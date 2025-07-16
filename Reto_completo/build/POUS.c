void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void RETO_2_init__(RETO_2 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX1_0,data__->LINTERNA,retain)
  __INIT_LOCATED_VALUE(data__->LINTERNA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR,__BOOL_LITERAL(FALSE))
  __INIT_EXTERNAL(BOOL,SERVO1_ON,data__->SERVO1_ON,retain)
  __INIT_EXTERNAL(BOOL,SERVO2_ON,data__->SERVO2_ON,retain)
  __INIT_EXTERNAL(BOOL,SERVO3_ON,data__->SERVO3_ON,retain)
  TP_init__(&data__->TP0,retain);
  __INIT_EXTERNAL(BOOL,SERVO4_ON,data__->SERVO4_ON,retain)
  __INIT_LOCATED(BOOL,__IX0_1,data__->SENSOR2V,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR2V,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_2,data__->SENSOR3V,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR3V,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->LED_VERDE,retain)
  __INIT_LOCATED_VALUE(data__->LED_VERDE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_6,data__->LED_VERDE2,retain)
  __INIT_LOCATED_VALUE(data__->LED_VERDE2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_7,data__->LED_VERDE3,retain)
  __INIT_LOCATED_VALUE(data__->LED_VERDE3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_6,data__->SENSOR1AM,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR1AM,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_7,data__->SENSOR2AM,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR2AM,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX1_2,data__->SENSOR3AM,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR3AM,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX1_3,data__->LED_AMARILLO,retain)
  __INIT_LOCATED_VALUE(data__->LED_AMARILLO,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX1_4,data__->LED_AMARILLO2,retain)
  __INIT_LOCATED_VALUE(data__->LED_AMARILLO2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_5,data__->LED_AMARILLO3,retain)
  __INIT_LOCATED_VALUE(data__->LED_AMARILLO3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX1_0,data__->LED_AZUL,retain)
  __INIT_LOCATED_VALUE(data__->LED_AZUL,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->LED_AZUL2,retain)
  __INIT_LOCATED_VALUE(data__->LED_AZUL2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX1_2,data__->LED_AZUL3,retain)
  __INIT_LOCATED_VALUE(data__->LED_AZUL3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_3,data__->SENSOR1AZ,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR1AZ,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_4,data__->SENSOR2AZ,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR2AZ,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_5,data__->SENSOR3AZ,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR3AZ,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0,data__->PARO,retain)
  __INIT_LOCATED_VALUE(data__->PARO,__BOOL_LITERAL(FALSE))
}

// Code part
void RETO_2_body__(RETO_2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TP0.,IN,,(__GET_LOCATED(data__->MOTOR,) && !(__GET_LOCATED(data__->PARO,))));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_EXTERNAL(data__->,SERVO1_ON,,__GET_VAR(data__->TP0.Q,));
  __SET_LOCATED(data__->,MOTOR,,(!(__GET_LOCATED(data__->LINTERNA,)) && !(__GET_LOCATED(data__->PARO,))));

  goto __end;

__end:
  return;
} // RETO_2_body__() 





