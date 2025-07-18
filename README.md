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


##  Logica del codigo (La parte de Arduino)

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

- Aqui se declaran las variables que vamos a utilizar para obtener las lecturas del sensor. Estas lecturas tiene las letras RGB porque dependiendo el color que detecte el sensor; son los valores de RGB que se obtienen

  ```
   float red, green, blue;
    tcs.getRGB(&red, &green, &blue);
    int R = int(red);
    int G = int(green);
    int B = int(blue);
    String color = "Neutral";

-Se realizan calculos con las lecturas que obtenemos del sensor y de acuerdo a esas lecturas creamos las condiciones para mostrar en la pantalla y en el codigo que color tiene el material que fue entregado. Estas operaciones se calculan con la ayuda del video que dejo hasta el final

```
  // Detecci\xf3n del color y asignaci\xf3n de flags

    if ((R - G > 10) && (G - B > 60)) { // Amarillo
        color = "Amarillo";
        F1 = 1; F2 = 0; F3 = 0; F4 = 0;
    } else if ((G - R > 20) && (G - B > 50)) { // Verde
        color = "Verde";
        F1 = 0; F2 = 1; F3 = 0; F4 = 0;
    } else if ((G - R > 10) && (B - G > 20)) { // Azul
        color = "Azul";
        F1 = 0; F2 = 0; F3 = 1; F4 = 0;
    } else { // Neutral
        F1 = 0; F2 = 0; F3 = 0; F4 = 1;
    }

    // Imprimir valores para depuraci\xf3n

    Serial.print("R: "); Serial.print(R);
    Serial.print(" G: "); Serial.print(G);
    Serial.print(" B: "); Serial.print(B);
    Serial.print(" Color: "); Serial.println(color);
```
- De acuerdo al color que se detecto y al codigo que se encuentra en PLC, entra a la condicion correspondiente y se van calasificacion los materiales. Dejamos un delay al final para que el programa no se activara tan rapido

 ```
// Control de los servos seg\xfan el flag activo
    if (F1 && Servo1_ON) { // Amarillo
        myservo1.write(Angulo1);
        myservo2.write(Angulo1-10);
    } else if (F2 && Servo1_ON) { // Verde
        myservo1.write(Angulo2);
        myservo2.write(Angulo2);
    } else if (F3 && Servo1_ON) { // Azul
        myservo1.write(Angulo3);
        myservo2.write(Angulo3);
    } else if (F4 && !Servo1_ON) { // Neutral
        myservo1.write(90); // Posici\xf3n central
        myservo2.write(90);
    }

    // Peque\xf1a pausa para estabilidad
    delay(100);

```
##   Logica del codigo (La parte de PLC)

- La configuracion de las entradas y las salidas en Open PLC se buscan en la pagina de internet de la misma ya que cada pin de la tarjeta Arduino tiene su propio valor
  
- [Da clic aqui para conocer las entradas y salidas en Open PLC](https://autonomylogic.com/docs/2-4-physical-addressing/). Las tarjetas Arduino son las que estan en el apartado que tiene el titulo Uno, Nano, Leonardo, Micro y Zero

  1. Declaramos las variables que van a ser de salida y de entrada con sus respectivos pines. El nombre de la variable "Linterna" reprseenta el sensor de proximidad, "Paro" representa un boton de paro de emergencia en caso de que se necesite detener todo el sistema y es normalmente cerrado. Por ultimo, "Motor" representa el motor reductor que ocasiona el movimiento en la banda transportadora
  2. 
![Imagen de WhatsApp 2025-07-17 a las 19 12 23_eecce24e](https://github.com/user-attachments/assets/0e2fdfed-3444-4bae-87ff-3cb1ee5e3fb5)



2.  Cuando el AGV aparece enfernte de la banda transportadora, el switch que corresponde al sensor de proximidad se transforma de normalmente abierto a normalmente cerrado, activando la bobina que representa el motor reductor. Esto ocasione que el motor se active al igual que la banda transportadora
   
3. Al ser activada la bobina que representa al motor, pasamos a la siguiente etapa en la cual se insertaba un timer de tipo TPO. Este timer tiene la funcion de detener la corriente electrica por 2 segundos para que el sensor de color tuviera el tiempo suficiente para correr el codigo de Arduino y reconocer el color del material
   
4. Despues de que se cumplan los 2 segundos, se le da energia a la bobina que representa la variable "Sensor1_ON". Esta bobina al ser activada obtiene el valor de 1, provocando que pueda entrar a los condicionales que activan los servomotores dependiendo del color

   


  





