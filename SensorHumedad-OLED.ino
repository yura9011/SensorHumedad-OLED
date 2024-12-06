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
