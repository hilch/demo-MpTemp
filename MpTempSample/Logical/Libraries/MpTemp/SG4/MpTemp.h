/* Automation Studio generated header file */
/* Do not edit ! */
/* MpTemp 5.02.0 */

#ifndef _MPTEMP_
#define _MPTEMP_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _MpTemp_VERSION
#define _MpTemp_VERSION 5.02.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "MpBase.h"
		#include "MTTypes.h"
		#include "MTBasics.h"
#endif

#ifdef _SG3
		#include "MpBase.h"
		#include "MTTypes.h"
		#include "MTBasics.h"
#endif

#ifdef _SGC
		#include "MpBase.h"
		#include "MTTypes.h"
		#include "MTBasics.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef enum MpTempProfileModeEnum
{	mpTEMP_PROFILE_MODE_OFF = 0,
	mpTEMP_PROFILE_MODE_TIME_OPT = 1,
	mpTEMP_PROFILE_MODE_RATE_LIMITED = 2
} MpTempProfileModeEnum;

typedef enum MpTempProfileStateEnum
{	mpTEMP_PROFILE_STATE_DISABLED = 0,
	mpTEMP_PROFILE_STATE_READY = 1,
	mpTEMP_PROFILE_STATE_ACTIVE = 2
} MpTempProfileStateEnum;

typedef enum MpTempProfileSyncModeEnum
{	mpTEMP_PROFILE_SYNC_OFF = 0,
	mpTEMP_PROFILE_SYNC_AUTO = 1,
	mpTEMP_PROFILE_SYNC_USER = 2
} MpTempProfileSyncModeEnum;

typedef enum MpTempPWMScheduleModeEnum
{	mpTEMP_PWM_MODE_SHIFT = 0,
	mpTEMP_PWM_MODE_SPLIT = 1
} MpTempPWMScheduleModeEnum;

typedef enum MpTempTuningModeEnum
{	mpTEMP_TUNING_MODE_OFF = 0,
	mpTEMP_TUNING_MODE_HEAT = 1,
	mpTEMP_TUNING_MODE_HEAT_COOL = 2
} MpTempTuningModeEnum;

typedef enum MpTempTuningStateEnum
{	mpTEMP_TUNING_STATE_IDLE = 0,
	mpTEMP_TUNING_STATE_INIT = 1,
	mpTEMP_TUNING_STATE_SYSTEM_CHECK = 2,
	mpTEMP_TUNING_STATE_DELAY_TIME = 3,
	mpTEMP_TUNING_STATE_IDENT = 4,
	mpTEMP_TUNING_STATE_PREDICTION = 5,
	mpTEMP_TUNING_STATE_IN_SETPOINT = 6,
	mpTEMP_TUNING_STATE_ERROR = 99,
	mpTEMP_TUNING_STATE_ABORTED = 100
} MpTempTuningStateEnum;

typedef enum MpTempTuningSystemCheckEnum
{	mpTEMP_TUNING_SYS_CHECK_SHORT = 0,
	mpTEMP_TUNING_SYS_CHECK_MEDIUM = 1,
	mpTEMP_TUNING_SYS_CHECK_LONG = 2
} MpTempTuningSystemCheckEnum;

typedef enum MpTempZoneTypeEnum
{	mpTEMP_ZONE_TYPE_HEAT = 0,
	mpTEMP_ZONE_TYPE_COOL = 1,
	mpTEMP_ZONE_TYPE_HEAT_COOL = 2
} MpTempZoneTypeEnum;

typedef enum MpTempErrorEnum
{	mpTEMP_NO_ERROR = 0,
	mpTEMP_ERR_ACTIVATION = -1064239103,
	mpTEMP_ERR_MPLINK_NULL = -1064239102,
	mpTEMP_ERR_MPLINK_INVALID = -1064239101,
	mpTEMP_ERR_MPLINK_CHANGED = -1064239100,
	mpTEMP_ERR_MPLINK_CORRUPT = -1064239099,
	mpTEMP_ERR_MPLINK_IN_USE = -1064239098,
	mpTEMP_ERR_PAR_NULL = -1064239097,
	mpTEMP_ERR_CONFIG_NULL = -1064239096,
	mpTEMP_ERR_CONFIG_NO_PV = -1064239095,
	mpTEMP_ERR_CONFIG_LOAD = -1064239094,
	mpTEMP_WRN_CONFIG_LOAD = -2137980917,
	mpTEMP_ERR_CONFIG_SAVE = -1064239092,
	mpTEMP_ERR_CONFIG_INVALID = -1064239091,
	mpTEMP_ERR_PID_PAR_INVALID = -1063980032,
	mpTEMP_ERR_TUNING_PAR_INVALID = -1063980031,
	mpTEMP_ERR_PROFILE_PAR_INVALID = -1063980030,
	mpTEMP_ERR_TOLERANCE_BAND = -1063980029,
	mpTEMP_ERR_TUNING = -1063980028,
	mpTEMP_ERR_PROFILE = -1063980027,
	mpTEMP_WRN_TUNING = -2137721850,
	mpTEMP_WRN_PROFILE = -2137721849,
	mpTEMP_ERR_COMMAND_INVALID = -1063980024,
	mpTEMP_ERR_CONTROLLER = -1063980023,
	mpTEMP_ERR_CONFIG_PAR_INVALID = -1063980022,
	mpTEMP_ERR_NO_LINKED_COMPONENTS = -1063980021,
	mpTEMP_INF_PROFILE_NOT_SUITABLE = 1083503628,
	mpTEMP_ERR_TUNING_ABORTED = -1063980019,
	mpTEMP_INF_COMPONENT_DISABLED = 1083503630,
	mpTEMP_ERR_PWM = -1063980017,
	mpTEMP_ERR_SIMULATION = -1063980016
} MpTempErrorEnum;

typedef enum MpTempAlarmEnum
{	mpTEMP_ALM_PAR_INVALID = 0,
	mpTEMP_ALM_COMMAND_INVALID = 1,
	mpTEMP_ALM_TUNING_FAILED = 2,
	mpTEMP_ALM_TUNING_DONE = 3,
	mpTEMP_ALM_OUTSIDE_TOLERANCE = 4
} MpTempAlarmEnum;

typedef struct MpTempSystemParType
{	float Gain;
	float TimeConstant1;
	float TimeConstant2;
	float DelayTime;
} MpTempSystemParType;

typedef struct MpTempSystemType
{	struct MpTempSystemParType Heat;
	struct MpTempSystemParType Cool;
} MpTempSystemType;

typedef struct MpTempPWMParType
{	float Period;
	float MinPulseWidth;
	float MinPause;
} MpTempPWMParType;

typedef struct MpTempPWMType
{	struct MpTempPWMParType Heat;
	struct MpTempPWMParType Cool;
} MpTempPWMType;

typedef struct MpTempControllerConfigType
{	enum MpTempZoneTypeEnum Type;
	float AmbientTemperature;
	float MaxHeatPower;
	float MaxHeatOutput;
	float MaxCoolOutput;
	enum MpTempProfileModeEnum ProfileMode;
	enum MpTempTuningSystemCheckEnum SystemCheck;
	struct MpTempSystemType SystemParameters;
	struct MpTempPWMType PWMParameters;
} MpTempControllerConfigType;

typedef struct MpTempPWMScheduleParType
{	enum MpTempPWMScheduleModeEnum Mode;
	float Period;
	float MinPulseWidth;
	float MinPause;
} MpTempPWMScheduleParType;

typedef struct MpTempPWMScheduleType
{	struct MpTempPWMScheduleParType Heat;
	struct MpTempPWMScheduleParType Cool;
} MpTempPWMScheduleType;

typedef struct MpTempGroupConfigType
{	plcbit EnableLoadBalancing;
	float MaxHeatPower;
	struct MpTempPWMScheduleType PWMScheduleParameters;
} MpTempGroupConfigType;

typedef struct MpTempPIDParType
{	float ProportionalGain;
	float IntegrationTime;
	float DerivativeTime;
	float FilterTime;
} MpTempPIDParType;

typedef struct MpTempPIDType
{	struct MpTempPIDParType Heat;
	struct MpTempPIDParType Cool;
} MpTempPIDType;

typedef struct MpTempTuningType
{	enum MpTempTuningModeEnum Mode;
	float SetPointHeat;
	float SetPointCool;
} MpTempTuningType;

typedef struct MpTempProfileParType
{	float SlewRate;
	float FilterTime;
	float DelayTime;
} MpTempProfileParType;

typedef struct MpTempControllerProfileType
{	struct MpTempProfileParType Heat;
	struct MpTempProfileParType Cool;
	float AttenuationFactor;
} MpTempControllerProfileType;

typedef struct MpTempToleranceBandType
{	float Lower;
	float Upper;
} MpTempToleranceBandType;

typedef struct MpTempControllerParType
{	struct MpTempPIDType PID;
	struct MpTempTuningType Tuning;
	struct MpTempControllerProfileType Profile;
	struct MpTempToleranceBandType ToleranceBand;
} MpTempControllerParType;

typedef struct MpTempGroupProfileType
{	enum MpTempProfileSyncModeEnum SynchronizationMode;
	struct MpTempProfileParType Heat;
	struct MpTempProfileParType Cool;
} MpTempGroupProfileType;

typedef struct MpTempGroupParType
{	plcbit SynchronizeTuning;
	struct MpTempGroupProfileType Profile;
} MpTempGroupParType;

typedef struct MpTempProfileType
{	struct MpTempProfileParType Heat;
	struct MpTempProfileParType Cool;
} MpTempProfileType;

typedef struct MpTempTuningInfoType
{	enum MpTempTuningStateEnum State;
	struct MpTempPIDType PIDParameters;
	struct MpTempSystemType SystemParameters;
	struct MpTempProfileType ProfileParameters;
} MpTempTuningInfoType;

typedef struct MpTempControllerProfileInfoType
{	plcbit Active;
	plcbit InSetPoint;
} MpTempControllerProfileInfoType;

typedef struct MpTempControlInfoType
{	float ControlError;
	float ProportionalPart;
	float IntegrationPart;
	float DerivativePart;
	float ActualTemperatureFiltered;
	float ActualTemperatureDerivative;
} MpTempControlInfoType;

typedef struct MpTempSimulationInfoType
{	float HeatValue;
	float CoolValue;
	float ActualTemperature;
} MpTempSimulationInfoType;

typedef struct MpTempStatusIDType
{	enum MpTempErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpTempStatusIDType;

typedef struct MpTempDiagType
{	struct MpTempStatusIDType StatusID;
} MpTempDiagType;

typedef struct MpTempControllerInfoType
{	float SetTemperature;
	float FeedForwardHeat;
	float FeedForwardCool;
	plcbit InTolerance;
	struct MpTempTuningInfoType Tuning;
	struct MpTempControllerProfileInfoType Profile;
	struct MpTempControlInfoType Control;
	struct MpTempSimulationInfoType Simulation;
	struct MpTempDiagType Diag;
} MpTempControllerInfoType;

typedef struct MpTempGroupProfileInfoType
{	plcbit Active;
	plcbit InSetPoint;
	struct MpTempProfileParType Heat;
	struct MpTempProfileParType Cool;
} MpTempGroupProfileInfoType;

typedef struct MpTempGroupPowerType
{	float Actual;
	float Required;
	plcbit InLimitation;
} MpTempGroupPowerType;

typedef struct MpTempGroupInfoType
{	struct MpTempGroupProfileInfoType Profile;
	struct MpTempGroupPowerType HeatPower;
	struct MpTempDiagType Diag;
} MpTempGroupInfoType;

typedef struct MpTempInfoType
{	struct MpTempDiagType Diag;
} MpTempInfoType;

typedef struct MpTempController
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpTempControllerParType* Parameters;
	float SetTemperature;
	float ActualTemperature;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	float HeatValue;
	float CoolValue;
	struct MpTempControllerInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Control;
	plcbit Tune;
	plcbit Simulate;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit Heat;
	plcbit Cool;
	plcbit ControlActive;
	plcbit TuningActive;
	plcbit TuningDone;
	plcbit Simulation;
} MpTempController_typ;

typedef struct MpTempControllerConfig
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpTempControllerConfigType* Configuration;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpTempInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Load;
	plcbit Save;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit CommandDone;
} MpTempControllerConfig_typ;

typedef struct MpTempGroup
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpTempGroupParType* Parameters;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpTempGroupInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Control;
	plcbit Tune;
	plcbit LimitPower;
	plcbit Simulate;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit ControlActive;
	plcbit TuningActive;
	plcbit TuningDone;
	plcbit PowerLimitationActive;
	plcbit Simulation;
} MpTempGroup_typ;

typedef struct MpTempGroupConfig
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpTempGroupConfigType* Configuration;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpTempInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Load;
	plcbit Save;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit CommandDone;
} MpTempGroupConfig_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MpTempController(struct MpTempController* inst);
_BUR_PUBLIC void MpTempControllerConfig(struct MpTempControllerConfig* inst);
_BUR_PUBLIC void MpTempGroup(struct MpTempGroup* inst);
_BUR_PUBLIC void MpTempGroupConfig(struct MpTempGroupConfig* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MPTEMP_ */

