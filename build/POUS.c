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





void LAZOEYECCIONSEGURA_init__(LAZOEYECCIONSEGURA *data__, BOOL retain) {
  __INIT_VAR(data__->TEMPERATURAALTA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TURBULENCIA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED_ROJO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED_VERDE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED_AZUL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PARACAIDAS_LED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTADO_ROJO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTADO_AZUL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTADO_VERDE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LAZOEYECCIONSEGURA_body__(LAZOEYECCIONSEGURA *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,ESTADO_ROJO,,__GET_VAR(data__->TEMPERATURAALTA,));
  __SET_VAR(data__->,ESTADO_AZUL,,(__GET_VAR(data__->TURBULENCIA,) && !(__GET_VAR(data__->TEMPERATURAALTA,))));
  __SET_VAR(data__->,ESTADO_VERDE,,(!(__GET_VAR(data__->TURBULENCIA,)) && !(__GET_VAR(data__->TEMPERATURAALTA,))));
  __SET_VAR(data__->,LED_ROJO,,__GET_VAR(data__->ESTADO_ROJO,));
  __SET_VAR(data__->,LED_AZUL,,__GET_VAR(data__->ESTADO_AZUL,));
  __SET_VAR(data__->,LED_VERDE,,__GET_VAR(data__->ESTADO_VERDE,));
  __SET_VAR(data__->,PARACAIDAS_LED,,__GET_VAR(data__->ESTADO_VERDE,));

  goto __end;

__end:
  return;
} // LAZOEYECCIONSEGURA_body__() 





