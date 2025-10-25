# Laboratorio Nº 2 - OpenPLC.
## Integrantes del grupo Transferitos:
  - Beneyto, Mateo.
  - Castro, Mauricio Nicolás.
  - Kalchichen, Lucas Gernán.
  - Lopez Soto, Martin.
  - Peralta Ruiz, Nadine Andrea.


## Detalles de la solución:
La solución propuesta se implementará en un microcontrolador que coordina la lectura de sensores y el accionamiento de actuadores para cumplir los objetivos definidos. A continuación, se detalla cómo se materializa cada uno:

### Monitoreo de Control de Propulsión
#### Sensores utilizados:
    - Sensor de temperatura → permite detectar variaciones térmicas que condicionan la propulsión.
    - Sensor de turbulencia → mide la estabilidad del vuelo, indicando si existen perturbaciones que obligan a correcciones.
     
### Monitoreo de Condición de Eyección/Aterrizaje
  #### Sensores utilizados:
    - Sensor de temperatura → indica sobrecalentamiento cuando se superan los límites de seguridad.
    - Sensor de turbulencia → detecta inestabilidad que impide la eyección.
  #### Actuadores involucrados:
    - Luces LED RGB → representan el estado de seguridad del vuelo:
    - Verde: condiciones seguras para aterrizaje/eyección.
    - Azul parpadeante: turbulencia detectada (no seguro).
    - Rojo parpadeante: sobrecalentamiento (no seguro).
    - LED adicional: simboliza el despliegue del paracaídas cuando se cumplen las condiciones seguras en el ascenso y   simboliza el aterrizaje de la cápsula cuando se cumplen las condiciones seguras en el descenso.
    
## 🔧 Hardware Requerido
- **Raspberry Pi Pico W**
- **Sensor KY-026** (Detector de fuego/temperatura)
- **Sensor KY-027** (Detector de inclinación/vibración)
- **LED RGB** (indicadores de estado)
- **LED adicional** (luz de seguridad/paracaídas)
- **Resistencias 220Ω** (para LEDs)
- **Cables de conexión**
![WhatsApp Image 2025-10-25 at 16 32 42](https://github.com/user-attachments/assets/72c7e78c-1959-4303-b8e2-f1c121a6097c)


## 🔌 Diagrama de Conexión

### Mapeo de Pines Raspberry Pi Pico W

| Función | Variable | Dirección | GPIO | Pin Físico | Dispositivo |
|---------|----------|-----------|------|------------|-------------|
| **ENTRADAS** |
| Fuego | `TemperaturaAlta` | `%IX0.0` | GP6 | 9 | KY-026 (DO) |
| Turbulencia | `Turbulencia` | `%IX0.7` | GP13 | 17 | KY-027 (S) |
| **SALIDAS** |
| LED Rojo | `LED_Rojo` | `%QX0.4` | GP18 | 24 | LED RGB (R) |
| LED Verde | `LED_Verde` | `%QX0.5` | GP19 | 25 | LED RGB (G) |
| LED Azul | `LED_Azul` | `%QX0.6` | GP20 | 26 | LED RGB (B) |
| Paracaídas | `Paracaidas_LED` | `%QX0.7` | GP21 | 27 | LED Seguridad |

## 🎨 Estados del Sistema

| Estado | LED Activo | Condición | Paracaídas |
|--------|------------|-----------|------------|
| 🔴 **PELIGRO** | Rojo | Fuego detectado | ❌ Deshabilitado |
| 🔵 **PRECAUCIÓN** | Azul | Turbulencia (sin fuego) | ❌ Deshabilitado |
| 🟢 **SEGURO** | Verde | Sin fuego ni turbulencia | ✅ **Habilitado** |
