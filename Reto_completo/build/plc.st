TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Reto_2
  VAR
    Linterna AT %IX1.0 : BOOL;
    Motor AT %QX0.0 : BOOL;
  END_VAR
  VAR_EXTERNAL
    Servo1_ON : BOOL;
    Servo2_ON : BOOL;
    Servo3_ON : BOOL;
  END_VAR
  VAR
    TP0 : TP;
  END_VAR
  VAR_EXTERNAL
    Servo4_ON : BOOL;
  END_VAR
  VAR
    Sensor2V AT %IX0.1 : BOOL;
    Sensor3V AT %IX0.2 : BOOL;
    Led_Verde AT %QX0.3 : BOOL;
    Led_Verde2 AT %QX0.6 : BOOL;
    Led_Verde3 AT %QX0.7 : BOOL;
    Sensor1Am AT %IX0.6 : BOOL;
    Sensor2Am AT %IX0.7 : BOOL;
    Sensor3Am AT %IX1.2 : BOOL;
    Led_Amarillo AT %QX1.3 : BOOL;
    Led_Amarillo2 AT %QX1.4 : BOOL;
    Led_Amarillo3 AT %QX0.5 : BOOL;
    Led_Azul AT %QX1.0 : BOOL;
    Led_Azul2 AT %QX0.4 : BOOL;
    Led_Azul3 AT %QX1.2 : BOOL;
    Sensor1Az AT %IX0.3 : BOOL;
    Sensor2Az AT %IX0.4 : BOOL;
    Sensor3Az AT %IX0.5 : BOOL;
    Paro AT %IX0.0 : BOOL;
  END_VAR

  TP0(IN := Motor AND NOT(Paro), PT := T#2s);
  Servo1_ON := TP0.Q;
  Motor := NOT(Linterna) AND NOT(Paro);
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    Servo1_ON : BOOL;
    Servo2_ON : BOOL;
    Servo3_ON : BOOL;
    Servo4_ON : BOOL;
  END_VAR

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Reto_2;
  END_RESOURCE
END_CONFIGURATION
