

PROGRAM _INIT
	
	Parameter.ToleranceBand.Lower := 20;
	Parameter.ToleranceBand.Upper := 20;

	SetTemperature := 122;
	ambientTemperature := 25.0;
	disturbance := 0;
	enableDisturbance := FALSE;

	(* simulation model *)
	FOR n:= 0 TO 9 DO
		_MTBasicsTimeDelay[n](
			Enable := FALSE,
			DelayTime := 2.0 + n,
		);

		_MTBasicsPT2[n](
			Enable := FALSE, 
			Gain := 15, 
			TimeConstant1 := 200 + 20 * n,
			TimeConstant2 := 150 - 10 * n,
		 );

	END_FOR

END_PROGRAM