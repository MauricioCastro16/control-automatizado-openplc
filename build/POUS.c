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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_1,data__->SENSORINCLINACION,retain)
  __INIT_LOCATED_VALUE(data__->SENSORINCLINACION,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0,data__->SENSORFUEGO,retain)
  __INIT_LOCATED_VALUE(data__->SENSORFUEGO,0)
  __INIT_LOCATED(BOOL,__QX0_3,data__->LEDAZUL,retain)
  __INIT_LOCATED_VALUE(data__->LEDAZUL,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->LEDPARACAIDAS,retain)
  __INIT_LOCATED_VALUE(data__->LEDPARACAIDAS,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->LEDROJO,retain)
  __INIT_LOCATED_VALUE(data__->LEDROJO,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->ESTADOTURBULENTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTADOSOBRECALENTAMIENTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_2,data__->LEDVERDE,retain)
  __INIT_LOCATED_VALUE(data__->LEDVERDE,__BOOL_LITERAL(TRUE))
  __INIT_VAR(data__->ESTADOSEGURO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UMBRALFUEGO,1,retain)
  __INIT_VAR(data__->RETARDOPARACAIDAS,__time_to_timespec(1, 5000, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TITILO,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIEMPOSUBIDABAJADA,__time_to_timespec(1, 30000, 0, 0, 0, 0),retain)
  TON_init__(&data__->RETARDOEYECCION,retain);
  TOF_init__(&data__->ASCENSODESCENSO,retain);
  TP_init__(&data__->PARPADEOLUCES,retain);
  TP_init__(&data__->DESPLIEGUE,retain);
  RS_init__(&data__->BIESTABLEASCDESC,retain);
  __INIT_VAR(data__->_TMP_NOT25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND52_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT41_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND42_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT3_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND5_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_NOT25_OUT,,!(__GET_VAR(data__->ASCENSODESCENSO.Q,)));
  __SET_VAR(data__->,_TMP_NOT23_OUT,,!(__GET_VAR(data__->BIESTABLEASCDESC.Q1,)));
  __SET_VAR(data__->,_TMP_AND52_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT25_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT23_OUT,)));
  __SET_VAR(data__->ASCENSODESCENSO.,IN,,__GET_VAR(data__->_TMP_AND52_OUT,));
  __SET_VAR(data__->ASCENSODESCENSO.,PT,,__GET_VAR(data__->TIEMPOSUBIDABAJADA,));
  TOF_body__(&data__->ASCENSODESCENSO);
  __SET_VAR(data__->,_TMP_NOT41_OUT,,!(__GET_VAR(data__->ASCENSODESCENSO.Q,)));
  __SET_VAR(data__->BIESTABLEASCDESC.,S,,__GET_VAR(data__->_TMP_NOT41_OUT,));
  __SET_VAR(data__->BIESTABLEASCDESC.,R1,,__GET_VAR(data__->_TMP_AND42_OUT,));
  RS_body__(&data__->BIESTABLEASCDESC);
  __SET_VAR(data__->,_TMP_NOT13_OUT,,!(__GET_LOCATED(data__->SENSORINCLINACION,)));
  __SET_VAR(data__->,_TMP_GT10_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->SENSORFUEGO,),
    (INT)__GET_VAR(data__->UMBRALFUEGO,)));
  __SET_VAR(data__->,_TMP_NOT1_OUT,,!(__GET_VAR(data__->_TMP_GT10_OUT,)));
  __SET_VAR(data__->,_TMP_AND14_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT13_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT1_OUT,)));
  __SET_VAR(data__->RETARDOEYECCION.,IN,,__GET_VAR(data__->_TMP_AND14_OUT,));
  __SET_VAR(data__->RETARDOEYECCION.,PT,,__GET_VAR(data__->RETARDOPARACAIDAS,));
  TON_body__(&data__->RETARDOEYECCION);
  __SET_VAR(data__->,_TMP_AND42_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->BIESTABLEASCDESC.Q1,),
    (BOOL)__GET_VAR(data__->RETARDOEYECCION.Q,)));
  __SET_VAR(data__->DESPLIEGUE.,IN,,__GET_VAR(data__->_TMP_AND42_OUT,));
  __SET_VAR(data__->DESPLIEGUE.,PT,,__GET_VAR(data__->RETARDOPARACAIDAS,));
  TP_body__(&data__->DESPLIEGUE);
  __SET_LOCATED(data__->,LEDPARACAIDAS,,__GET_VAR(data__->DESPLIEGUE.Q,));
  __SET_LOCATED(data__->,LEDVERDE,,__GET_VAR(data__->ESTADOSEGURO,));
  __SET_VAR(data__->,_TMP_NOT36_OUT,,!(__GET_VAR(data__->PARPADEOLUCES.Q,)));
  __SET_VAR(data__->PARPADEOLUCES.,IN,,__GET_VAR(data__->_TMP_NOT36_OUT,));
  __SET_VAR(data__->PARPADEOLUCES.,PT,,__GET_VAR(data__->TITILO,));
  TP_body__(&data__->PARPADEOLUCES);
  __SET_VAR(data__->,_TMP_AND21_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ESTADOTURBULENTO,),
    (BOOL)__GET_VAR(data__->PARPADEOLUCES.Q,)));
  __SET_LOCATED(data__->,LEDAZUL,,__GET_VAR(data__->_TMP_AND21_OUT,));
  __SET_VAR(data__->,_TMP_AND37_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->ESTADOSOBRECALENTAMIENTO,),
    (BOOL)__GET_VAR(data__->PARPADEOLUCES.Q,)));
  __SET_LOCATED(data__->,LEDROJO,,__GET_VAR(data__->_TMP_AND37_OUT,));
  __SET_VAR(data__->,ESTADOSEGURO,,__GET_VAR(data__->_TMP_AND14_OUT,));
  __SET_VAR(data__->,_TMP_NOT3_OUT,,!(__GET_VAR(data__->_TMP_GT10_OUT,)));
  __SET_VAR(data__->,_TMP_AND5_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT3_OUT,),
    (BOOL)__GET_LOCATED(data__->SENSORINCLINACION,)));
  __SET_VAR(data__->,ESTADOTURBULENTO,,__GET_VAR(data__->_TMP_AND5_OUT,));
  __SET_VAR(data__->,ESTADOSOBRECALENTAMIENTO,,__GET_VAR(data__->_TMP_GT10_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





