#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM LAZOEYECCIONSEGURA
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,TEMPERATURAALTA)
  __DECLARE_VAR(BOOL,TURBULENCIA)
  __DECLARE_VAR(BOOL,LED_ROJO)
  __DECLARE_VAR(BOOL,LED_VERDE)
  __DECLARE_VAR(BOOL,LED_AZUL)
  __DECLARE_VAR(BOOL,PARACAIDAS_LED)

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,ESTADO_ROJO)
  __DECLARE_VAR(BOOL,ESTADO_AZUL)
  __DECLARE_VAR(BOOL,ESTADO_VERDE)

} LAZOEYECCIONSEGURA;

void LAZOEYECCIONSEGURA_init__(LAZOEYECCIONSEGURA *data__, BOOL retain);
// Code part
void LAZOEYECCIONSEGURA_body__(LAZOEYECCIONSEGURA *data__);
#endif //__POUS_H
