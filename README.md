[![Consultar a DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/MauricioCastro16/control-automatizado-openplc)

# Sistema de Control Automatizado OpenPLC

[![OpenPLC](https://img.shields.io/badge/OpenPLC-IEC%2061131--3-orange.svg)](https://www.openplcproject.com/)

Sistema de control crítico para vehículos estratosféricos implementado con estándares industriales IEC 61131-3. Proporciona monitoreo en tiempo real de condiciones de seguridad y control automatizado de propulsión mediante lógica determinista.

## Características Principales

- Monitoreo continuo de temperatura y turbulencia mediante sensores KY-026/KY-027
- Máquina de estados con tres modos: SEGURO, PRECAUCIÓN y PELIGRO
- Control dinámico de propulsión con motor paso a paso 28BYJ-48
- Sistema de seguridad con paracaídas automatizado y LEDs indicadores RGB
- Telemetría en tiempo real vía MQTT para monitoreo remoto

- ## Detalles de la solución:
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


## 🔌 Diagrama de Conexión
![WhatsApp Image 2025-10-25 at 16 32 42](https://github.com/user-attachments/assets/72c7e78c-1959-4303-b8e2-f1c121a6097c)


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

## Stack Tecnológico

| Categoría | Tecnologías |
|-----------|-------------|
| **Frontend** | LEDs RGB, Indicadores visuales |
| **Backend** | OpenPLC, CircuitPython, Ladder Diagram (LD) |
| **Herramientas** | Raspberry Pi Pico W, IEC 61131-3, MQTT |

## Arquitectura / Flujo

El sistema implementa una arquitectura híbrida donde OpenPLC ejecuta la lógica de seguridad crítica mediante diagramas de escalera IEC 61131-3, mientras que CircuitPython gestiona periféricos avanzados y comunicaciones. Los sensores alimentan una máquina de estados determinista que controla actuadores y publica telemetría mediante MQTT.

## Instalación y Uso

```bash
# Clonar el repositorio
git clone https://github.com/MauricioCastro16/control-automatizado-openplc.git
cd control-automatizado-openplc

# Instalar dependencias de CircuitPython
pip install circuitpython-adafruit-motor circuitpython-adafruit-mqtt

# Cargar firmware en Raspberry Pi Pico W
# Conectar el hardware según diagrama de pines
# Ejecutar el programa principal
python3 code.py
```

```bash
# Configurar OpenPLC
# Importar archivo plc.xml en OpenPLC Editor
# Compilar y cargar en Raspberry Pi Pico W
# Monitorear mediante cliente MQTT en broker 10.13.100.84
```
