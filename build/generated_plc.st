PROGRAM LazoEyeccionSegura
  VAR_INPUT
    TemperaturaAlta : BOOL;
    Turbulencia : BOOL;
  END_VAR
  VAR_OUTPUT
    LED_Rojo : BOOL;
    LED_Verde : BOOL;
    LED_Azul : BOOL;
    Paracaidas_LED : BOOL;
  END_VAR
  VAR
    Estado_Rojo : BOOL;
    Estado_Azul : BOOL;
    Estado_Verde : BOOL;
  END_VAR

  Estado_Rojo := TemperaturaAlta;
  Estado_Azul := Turbulencia AND NOT(TemperaturaAlta);
  Estado_Verde := NOT(Turbulencia) AND NOT(TemperaturaAlta);
  LED_Rojo := Estado_Rojo;
  LED_Azul := Estado_Azul;
  LED_Verde := Estado_Verde;
  Paracaidas_LED := Estado_Verde;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : LazoEyeccionSegura;
  END_RESOURCE
END_CONFIGURATION
