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


##  Logica del codigo

- Se declaran las librerias para los servomotores y para el sensor de color

  ```
  #include <Servo.h> //Librria para el servomotor 
  #include <Adafruit_TCS34725.h> //Libreria para el sensor de color
   ```
- Se declaran el sensor de color, los servomotores, los angulos que seran constantes durante la ejecucuion del codigo y unas variables que usaremos como banderas mas adelante en el codigo 

  ```

  // Inicializaci\xf3n del sensor de color
    Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

  // Inicializacion de los servos
    Servo myservo1;
    Servo myservo2;

  // Definimos los angulos para los servos
  const int Angulo1 = 50; // Puedes trabajar con los angulos 38 y 47 pero es mejor 50 
  const int Angulo2 = 90;
  const int Angulo3 = 135; //138
  
  // Declaraci\xf3n de variables globales
  bool F1 = 0, F2 = 0, F3 = 0, F4 = 0;   // Flags para colores
  
- Insertamos una funcion para que comience la ejecucuion del sensor de color
  ```
   if (!tcs.begin()) {
        Serial.println("Sensor TCS34725 no detectado.");
        while (1); // Detener ejecuci\xf3n si no hay sensor
    }
-Se declara el pin en el que estaran los servomotores y el angulo en el que deberian de estar 
```
    // Configuraci\xf3n de los servos
    myservo1.attach(15);
    myservo1.write(90); // Posici\xf3n inicial
    myservo2.attach(16);
    myservo2.write(90); // Posici\xf3n inicial

```
-Con este comando "Serial.begin" se inicia la comunicacion serial entre el Arduino y la computaada para mostarr las lecturas del sensor

    Serial.begin(9600); // Comunicacion serial
  



