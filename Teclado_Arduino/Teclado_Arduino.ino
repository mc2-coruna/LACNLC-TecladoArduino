#include <Keyboard.h>

/* Teclado para las aplicaciones de la exposición 
La Astronomía Como Nos la Cuentan. */

// Tiempo minimo entre dos pulsaciones si se maniene el boton pulsado
boolean repeticion = false;
int tiempoRepeticion = 250;

// Definicion de los pines asociados a cada botón
// NOMBRE BOTON     PIN
#define botonPIN_0   2
#define botonPIN_1   3
#define botonPIN_2   4
#define botonPIN_3   5
#define botonPIN_4   6
#define botonPIN_5   7
#define botonPIN_6   8
#define botonPIN_7   9
#define botonPIN_8   10
#define botonPIN_9   11


// Definición de caracteres ASCII asociados a cada tecla
//               ASCII     SIMBOLO
#define boton_0    48       // 0
#define boton_1    49       // 1
#define boton_2    50       // 2
#define boton_3    51       // 3
#define boton_4    52       // 4
#define boton_5    53       // 5
#define boton_6    54       // 6
#define boton_7    55       // 7
#define boton_8    56       // 8
#define boton_9    65       // A  // Para la cámara termográfica

void setup() {
  // Configura las entradas y salidas
  pinMode (LED_BUILTIN, OUTPUT);
  
  pinMode (botonPIN_0, INPUT_PULLUP);
  pinMode (botonPIN_1, INPUT_PULLUP);
  pinMode (botonPIN_2, INPUT_PULLUP);
  pinMode (botonPIN_3, INPUT_PULLUP);
  pinMode (botonPIN_4, INPUT_PULLUP);
  pinMode (botonPIN_5, INPUT_PULLUP);
  pinMode (botonPIN_6, INPUT_PULLUP);
  pinMode (botonPIN_7, INPUT_PULLUP);
  pinMode (botonPIN_8, INPUT_PULLUP);
  pinMode (botonPIN_9, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  // Tecla en la que se almacena el caracter ASCII del botón pulsado
  static byte botonPulsado = 0;
  
  //Comprueba si hay alguna tecla pulsada
  botonPulsado = leeTeclas ();

  
  // Si detecta una pulsación la envía y espera antes de volver a leer el teclado
  if (botonPulsado >= 33)
  {
    digitalWrite (LED_BUILTIN, HIGH);
    Keyboard.press (botonPulsado);
    
    Serial.println(botonPulsado);
    delay (5);
    Keyboard.releaseAll ();
    delay (100);
    digitalWrite (LED_BUILTIN, LOW);
      
    delay (tiempoRepeticion);
      
    if (! repeticion)  
      // Si la repeticion de teclas no está activa espera a 
      //       que NINGUNA las teclas esté pulsada
    {
      while (leeTeclas () >= 33)
      {
        delay (25);
      }
    }      
  }
  delay (25);
}

byte leeTeclas ()
{
  byte botonPulsado = 0;
  
  // Detecta el primer botón pulsado
  if      (! digitalRead (botonPIN_0)) botonPulsado = boton_0;
  else if (! digitalRead (botonPIN_1)) botonPulsado = boton_1;
  else if (! digitalRead (botonPIN_2)) botonPulsado = boton_2;
  else if (! digitalRead (botonPIN_3)) botonPulsado = boton_3;
  else if (! digitalRead (botonPIN_4)) botonPulsado = boton_4;
  else if (! digitalRead (botonPIN_5)) botonPulsado = boton_5;
  else if (! digitalRead (botonPIN_6)) botonPulsado = boton_6;
  else if (! digitalRead (botonPIN_7)) botonPulsado = boton_7;
  else if (! digitalRead (botonPIN_8)) botonPulsado = boton_8;
  else if (! digitalRead (botonPIN_9)) botonPulsado = boton_9;
  
  return botonPulsado;
}
