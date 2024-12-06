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

Código
A continuación, el código usado para el proyecto. Este código mide la humedad del suelo (de 0 a 1023) y la convierte en un porcentaje, que luego muestra en la pantalla OLED.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configuración de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin del sensor de humedad
const int soilSensorPin = A0;

void setup() {
  // Configuración del sensor
  pinMode(soilSensorPin, INPUT);

  // Iniciar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    // Si la pantalla no se inicializa, mostrar error
    Serial.println(F("No se encontró la pantalla OLED"));
    for (;;);
  }

  // Limpiar y configurar la pantalla
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Inicializando..."));
  display.display();
  delay(1000); // Esperar 1 segundo
}

void loop() {
  // Leer el valor del sensor de humedad
  int soilValue = analogRead(soilSensorPin);

  // Calcular porcentaje de humedad (0 - 1023)
  int soilPercent = map(soilValue, 0, 1023, 100, 0); // 100 = húmedo, 0 = seco

  // Mostrar valores en el OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Sensor de humedad"));
  display.setCursor(0, 20);
  display.print(F("Valor bruto: "));
  display.println(soilValue);
  display.setCursor(0, 40);
  display.print(F("Humedad: "));
  display.print(soilPercent);
  display.println(F("%"));
  display.display();

  // Esperar un momento antes de repetir
  delay(1000);
}


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
![Imagen de WhatsApp 2024-12-06 a las 10 36 04_d35a6329](https://github.com/user-attachments/assets/86d7d99f-1680-4ea4-a589-53d1da867307)


![image](https://github.com/user-attachments/assets/58d4fe89-247b-4965-9177-af3594c26da7)


Notas Finales
Este circuito puede servir como base para un sistema de riego automatizado.
Si los valores no se muestran correctamente, verifica las conexiones de I2C (SDA, SCL) o los pines del sensor de humedad.
