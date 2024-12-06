
Sensor de Humedad con Arduino y Pantalla OLED

Este proyecto utiliza un Arduino Uno, una pantalla OLED SSD1306 y un sensor de humedad de suelo para medir la humedad de la tierra y mostrar los valores en la pantalla OLED. Es ideal para proyectos de riego automatizado o monitoreo de plantas.

Materiales
Arduino Uno
Pantalla OLED (SSD1306, 0.96")
Sensor de humedad de suelo
Caja de pilas (4xAA, 6V) o fuente de alimentación
Cables Dupont (macho-macho/macho-hembra)
Protoboard (opcional)
Esquema de Conexión
OLED (I2C)
Pin OLED	Pin Arduino
VCC	5V
GND	GND
SCL	A5
SDA	A4
Sensor de Humedad
Pin Sensor	Pin Arduino
VCC	5V
GND	GND
AO	A0
Fuente de Alimentación
Conectar el positivo de la caja de pilas al pin VIN del Arduino.
Conectar el negativo de la caja de pilas al pin GND del Arduino.


Proceso
Montaje del circuito:
Conecta los componentes siguiendo el esquema proporcionado.
Asegúrate de que todas las conexiones estén firmes.
Carga del código:

Copia y pega el código anterior en el Arduino IDE.
Selecciona la placa Arduino Uno y el puerto correcto.
Carga el programa al Arduino.
Prueba del circuito:

Alimenta el Arduino con la caja de pilas.
Inserta el sensor en tierra seca y húmeda y observa los cambios en la pantalla OLED.

![Imagen de WhatsApp 2024-12-06 a las 10 36 04_092824b7](https://github.com/user-attachments/assets/c356541e-669a-447b-869a-c486ba48de29)
![Imagen de WhatsApp 2024-12-06 a las 10 36 23_dabd9152](https://github.com/user-attachments/assets/d33a4405-bc94-4796-9867-1fb9198a13e7)

![ezgif-6-cd01e7142a](https://github.com/user-attachments/assets/fb172b1d-ab24-42a7-9a6f-3b7de4a85994)



Notas Finales
Este circuito puede servir como base para un sistema de riego automatizado.
Si los valores no se muestran correctamente, verifica las conexiones de I2C (SDA, SCL) o los pines del sensor de humedad.
