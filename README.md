# 🛠️ Clasificador de Materiales por Color con OpenPLC y Arduino

Este proyecto consiste en un sistema de clasificación automática de materiales basado en su **color**, integrando la plataforma **OpenPLC** con una placa **Arduino UNO**. El objetivo principal fue crear una línea de clasificación donde un sensor identifica el color del material transportado, y un servomotor lo redirige al compartimento correspondiente según ese color.

## ⚙️ ¿Cómo funciona?

El sistema está compuesto por los siguientes elementos:

- 🎛️ **Motor Reductor:** impulsa una banda transportadora que lleva los objetos a lo largo del sistema.
- 📦 **Banda Transportadora:** mueve el material hacia el punto de inspección.
- 🎨 **Sensor de Color TCS34725:** detecta el color RGB del material al pasar por el sensor.
- 🔄 **Arduino UNO:** recibe los datos del sensor y los comunica a OpenPLC.
- 🧠 **OpenPLC:** se encarga de procesar la lógica de control del sistema.
- 🤖 **Servomotor:** gira a un ángulo específico según el color detectado, redirigiendo el material al compartimiento correspondiente.

## 🔁 Lógica del sistema

1. El motor pone en marcha la banda transportadora.
2. El material pasa por el sensor TCS34725.
3. El sensor identifica el color (por ejemplo: rojo, verde, azul).
4. Arduino transmite los datos a OpenPLC.
5. Según el color recibido, se define un ángulo de giro para el servomotor.
6. El servomotor redirige el material al compartimiento asignado.

## 🧰 Tecnologías utilizadas

- OpenPLC Runtime (en PC o Raspberry Pi)
- Arduino UNO
- Sensor TCS34725 (sensor de color RGB)
- Motor reductor DC
- Banda transportadora
- Servomotor (SG90 o similar)

## 📹 Video del proyecto

[![Ver en YouTube](https://img.shields.io/badge/Video%20del%20Proyecto-YouTube-red?logo=youtube)](https://www.youtube.com/watch?v=ID_DEL_VIDEO)

> ⚠️ Reemplaza `ID_DEL_VIDEO` con el ID real de tu video de YouTube.

---

¿Te gustaría que también te ayude con una sección de **código**, **esquema de conexiones**, o una **licencia** para tu proyecto? Puedo completarlo.
