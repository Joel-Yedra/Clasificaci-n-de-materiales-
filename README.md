# 🛠️ Clasificador de Materiales por Color con OpenPLC y Arduino

Este proyecto consiste en un sistema de clasificación automática de materiales basado en su **color**, integrando la plataforma **OpenPLC** con una placa **Arduino UNO**. El objetivo principal fue crear una línea de clasificación donde un sensor de proximidad activa un motor reductor, este a su vez enciende la banda trsmportada cuando recibe material, identifica el color del material transportado por medio de un sensor de color, y dos servomotores lo redirigen al compartimento correspondiente según ese color.

## 🧰 Tecnologías utilizadas

El sistema está compuesto por los siguientes elementos:

- 🎛️ **Motor Reductor:** Impulsa una banda transportadora que lleva los objetos a lo largo del sistema.
- 📦 **Banda Transportadora:** Mueve el material hacia el punto de inspección y despues los transporta a un compartimiento especifico.
- 🎨 **Sensor de Color TCS34725:** Detecta el color RGB del material al pasar por el sensor.
- 🔄 **Arduino UNO:** Recibe los datos del sensor y los comunica a OpenPLC.
- 🧠 **OpenPLC:** Se encarga de procesar los datos y en base a la programacion en PLC y un codigo de Arduino; activa los actuadores, que en este caso son los servomotores.
- 🤖 **Servomotor:** Gira a un ángulo específico según el color detectado, redirigiendo el material al compartimiento correspondiente.
-  🔦 Sensor de proximidad E18-D80NK:** Tiene la funcion de activar la banda transportadora cuando recibe el material 

## 🔁 Lógica del sistema

1. Un AGV (Automatic Guided Vehicle) envia el material y el sistema lo recibe para cliasificarlo segun sus caracteriticas.
2. Al recibir el material el sensor de proximidad se activa al igual que el motor reductor, ocasionando que el material llegue hacia el sensor de color
3. El material pasa por el sensor TCS34725 y analiza el color que posee. Entre las opciones que se encuentran es azul, verde o amarillo
4. En base al color, se define un ángulo de giro para los servomotores para clasificar el material 
5. Gracias al movimiento constante generado por la banda trsnportadora y el angulo generado por los servomotores, se redirige el material al compartimiento asignado.


## 📹 Video del proyecto

[Clasificacion de materiales](https://youtube.com/shorts/kHZi7zJUA0E?feature=share)


