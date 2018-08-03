
PROGRAM _CYCLIC

  (* -------------------------------------------------------------------
	state machine 
   ------------------------------------------------------------------- *)
	CASE step OF
		0:
		IF start = TRUE THEN
			step := 1;
		END_IF

		1: (* set step = 1 to start tuning, done after about 1300 seconds *)
		IF TempGroup.Active AND allTempControllerActive THEN

			fubGetTime(enable := TRUE);
			IF fubGetTime.status = 0 THEN
				startTime := fubGetTime.DT1;
				step := 10;
			END_IF
		END_IF

		10:
		(* TempController[0].Tune := TRUE ;*)
		TempGroup.Tune := TRUE;
		step := 20;

		20:
		fubGetTime(enable := TRUE);
		IF fubGetTime.status = 0 THEN
			endTime := fubGetTime.DT1;
			diffTime := DiffDT( endTime, startTime );  (* measure time used for tuning *)
		END_IF
		IF allTempControllerTuningDone THEN
			step := 30;		
		END_IF

		30:
		IF allTempControllerInSetpoint THEN
			enableDisturbance := TRUE;
			tonWait( IN:= FALSE, PT:= T#100s ); 
			step := 40;
		END_IF

		40:
		tonWait( IN:= TRUE ); (* wait and test the quality of control with 'disturbances' *)
		IF tonWait.Q THEN 
			enableDisturbance := FALSE; 
			start := 0;
			step := 0;
		END_IF
		
	

	END_CASE


  (* -------------------------------------------------------------------
	temperature controller
   ------------------------------------------------------------------- *)

	(* collective signals  *)
	allTempControllerActive := TRUE;
	allTempControllerInSetpoint := TRUE;
	allTempControllerTuningDone := TRUE;
	tuningError := FALSE;

	(* run temperature controller *)
	FOR n:= 0 TO 9 DO
		TC ACCESS ADR(TempController[n]);

		CASE n OF
		0: TC.MpLink := ADR(gTempController01);
		1: TC.MpLink := ADR(gTempController02);
		2: TC.MpLink := ADR(gTempController03);
		3: TC.MpLink := ADR(gTempController04);
		4: TC.MpLink := ADR(gTempController05);
		5: TC.MpLink := ADR(gTempController06);
		6: TC.MpLink := ADR(gTempController07);
		7: TC.MpLink := ADR(gTempController08);
		8: TC.MpLink := ADR(gTempController09);
		9: TC.MpLink := ADR(gTempController10);
		END_CASE
	
		(* for profiler *)
		LogEvent_0(enable := 1, objIdent := 123 , userEvent := profUSER_EVENT_START , pAddData :=0 , addDataLen := 0);

		TC (
			Enable := TRUE,
			Parameters := ADR(Parameter),
			SetTemperature := SetTemperature,
			ActualTemperature := _MTBasicsPT2[n].Out + ambientTemperature
		);

		(* for profiler *)
		LogEvent_0(enable := 1, objIdent := 123 , userEvent := profUSER_EVENT_STOP , pAddData :=0 , addDataLen := 0);

		(* collective signals *)
		IF NOT(TC.Active) THEN
			allTempControllerActive := FALSE;
		END_IF
		IF TC.Info.Tuning.State <> mpTEMP_TUNING_STATE_IN_SETPOINT THEN
			allTempControllerInSetpoint := FALSE;
		END_IF
		IF TC.Info.Tuning.State = mpTEMP_TUNING_STATE_ERROR THEN
			tuningError := TRUE;
		END_IF
		IF TC.TuningDone = FALSE THEN
			allTempControllerTuningDone := FALSE;
		END_IF
	END_FOR
	 
	(* run group *)
	TempGroup(
		MpLink := ADR(gTempGroup),
		Enable := TRUE,

		Parameters := ADR(GroupParameter),
	);


  (* -------------------------------------------------------------------
	run simulation model
   ------------------------------------------------------------------- *)
	FOR n:= 0 TO 9 DO
		_MTBasicsTimeDelay[n](
			Enable := TRUE,
			(* In := 80* TempController[n].HeatValue / 100.0 *)  (* analogue actuator *)
			In := 80 * BOOL_TO_REAL(TempController[n].Heat)	 (* digital actuator *)
		);

		_MTBasicsPT2[n](
			Enable := TRUE, 
			In := _MTBasicsTimeDelay[n].Out + disturbance
		 );
	END_FOR
	

  (* -------------------------------------------------------------------
	simulate disturbance
   ------------------------------------------------------------------- *)
   	IF enableDisturbance THEN
		disturbanceCounter := disturbanceCounter + 1;
		IF disturbanceCounter > 50 AND disturbanceCounter <= 60 THEN
			disturbance := 20;
		ELSIF disturbanceCounter > 60 THEN
			disturbance := 0;
			disturbanceCounter := 0;
		END_IF
	END_IF

END_PROGRAM
