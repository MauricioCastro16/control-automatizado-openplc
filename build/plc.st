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


PROGRAM program0
  VAR
    SensorInclinacion AT %IX0.1 : BOOL;
    SensorFuego AT %IW0 : INT;
    LedAzul AT %QX0.3 : BOOL := FALSE;
    LedParacaidas AT %QX0.4 : BOOL := FALSE;
    LedRojo AT %QX0.1 : BOOL := FALSE;
  END_VAR
  VAR
    EstadoTurbulento : BOOL := FALSE;
    EstadoSobrecalentamiento : BOOL := FALSE;
  END_VAR
  VAR
    LedVerde AT %QX0.2 : BOOL := TRUE;
  END_VAR
  VAR
    EstadoSeguro : BOOL := TRUE;
    UmbralFuego : INT := 1;
    RetardoParacaidas : TIME := T#5000ms;
    Titilo : TIME := T#10ms;
    TiempoSubidaBajada : TIME := T#30000ms;
    RetardoEyeccion : TON;
    AscensoDescenso : TOF;
    ParpadeoLuces : TP;
    Despliegue : TP;
    BiestableAscDesc : RS;
    _TMP_NOT25_OUT : BOOL;
    _TMP_NOT23_OUT : BOOL;
    _TMP_AND52_OUT : BOOL;
    _TMP_NOT41_OUT : BOOL;
    _TMP_NOT13_OUT : BOOL;
    _TMP_GT10_OUT : BOOL;
    _TMP_NOT1_OUT : BOOL;
    _TMP_AND14_OUT : BOOL;
    _TMP_AND42_OUT : BOOL;
    _TMP_NOT36_OUT : BOOL;
    _TMP_AND21_OUT : BOOL;
    _TMP_AND37_OUT : BOOL;
    _TMP_NOT3_OUT : BOOL;
    _TMP_AND5_OUT : BOOL;
  END_VAR

  _TMP_NOT25_OUT := NOT(AscensoDescenso.Q);
  _TMP_NOT23_OUT := NOT(BiestableAscDesc.Q1);
  _TMP_AND52_OUT := AND(_TMP_NOT25_OUT, _TMP_NOT23_OUT);
  AscensoDescenso(IN := _TMP_AND52_OUT, PT := TiempoSubidaBajada);
  _TMP_NOT41_OUT := NOT(AscensoDescenso.Q);
  BiestableAscDesc(S := _TMP_NOT41_OUT, R1 := _TMP_AND42_OUT);
  _TMP_NOT13_OUT := NOT(SensorInclinacion);
  _TMP_GT10_OUT := GT(SensorFuego, UmbralFuego);
  _TMP_NOT1_OUT := NOT(_TMP_GT10_OUT);
  _TMP_AND14_OUT := AND(_TMP_NOT13_OUT, _TMP_NOT1_OUT);
  RetardoEyeccion(IN := _TMP_AND14_OUT, PT := RetardoParacaidas);
  _TMP_AND42_OUT := AND(BiestableAscDesc.Q1, RetardoEyeccion.Q);
  Despliegue(IN := _TMP_AND42_OUT, PT := RetardoParacaidas);
  LedParacaidas := Despliegue.Q;
  LedVerde := EstadoSeguro;
  _TMP_NOT36_OUT := NOT(ParpadeoLuces.Q);
  ParpadeoLuces(IN := _TMP_NOT36_OUT, PT := Titilo);
  _TMP_AND21_OUT := AND(EstadoTurbulento, ParpadeoLuces.Q);
  LedAzul := _TMP_AND21_OUT;
  _TMP_AND37_OUT := AND(EstadoSobrecalentamiento, ParpadeoLuces.Q);
  LedRojo := _TMP_AND37_OUT;
  EstadoSeguro := _TMP_AND14_OUT;
  _TMP_NOT3_OUT := NOT(_TMP_GT10_OUT);
  _TMP_AND5_OUT := AND(_TMP_NOT3_OUT, SensorInclinacion);
  EstadoTurbulento := _TMP_AND5_OUT;
  EstadoSobrecalentamiento := _TMP_GT10_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
