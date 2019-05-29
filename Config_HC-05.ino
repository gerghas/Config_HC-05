// Monitor serial en NL & CR a 9600
// Enviar la palabra AT para comprobar que la cominicación sea correcta
// Para cambiar el nombre al dispositivo usar el comando: AT+NAME="Nombre"
// Para consultar la contraseña usar el comando: AT+PSWD?
// Cambiar la contraseña usar el comando: AT+PSWD="Nueva contraseña de 4 caracteres"

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
