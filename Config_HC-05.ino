// Para poder configurar el HC-05 mediante el monitor serial, requerimos cargar este código
// en nuestro Arduino y despues seguir los siguientes pasos:
// *En caso de tener error durante la carga, desconecta el HC-05 y al terminar la carga vuelve a conectar*
//
// 1.- Poner nuestro monitor serial en NL & CR a 9600
// 2.- Enviar la palabra AT para comprobar que la cominicación sea correcta, reciniremos un "OK"
// 3.- Para cambiar el nombre al dispositivo usar el comando: AT+NAME="Nombre"
// 4.- Para consultar la contraseña usar el comando: AT+PSWD?
// 5.- Cambiar la contraseña usar el comando: AT+PSWD="Nueva contraseña de 4 caracteres"

#include <SoftwareSerial.h> //Se Inclute la librería.
SoftwareSerial BT(11,10); // Aquí se definen los pines para RX y TX del módulo al Arduino.

void setup()
{
  BT.begin(9600); //Iniciamos el puerto serial para el BT (En AT2 la velocidad debe ser 38400).
  Serial.begin(9600); // Iniciamos el puerto serial.
}

void loop()
{
  if(BT.available()) // Cuando un dato sea recibido por BT se mandará al monitor serial.
  {
    Serial.write(BT.read());
  }
}
