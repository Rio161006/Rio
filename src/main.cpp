#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// Konfigurasi WiFi
const char* ssid = "NAMA_WIFI_KAMU";
const char* password = "PASSWORD_WIFI_KAMU";

// Pin LED (ESP32 biasanya di GPIO 2)
const int LED_PIN = 2;

// Fungsi untuk kedip Morse
void blink(int duration) {
  digitalWrite(LED_PIN, HIGH);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
  delay(200); // Jeda antar ketukan
}

void playSOS() {
  // S: Tiga titik (pendek)
  for(int i=0; i<3; i++) blink(200);
  delay(400); 

  // O: Tiga garis (panjang)
  for(int i=0; i<3; i++) blink(600);
  delay(400);

  // S: Tiga titik (pendek)
  for(int i=0; i<3; i++) blink(200);
  
  delay(2000); // Jeda sebelum mengulang SOS
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // Inisialisasi WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Koneksi Gagal! Salah PW kaliii");
    delay(5000);
    ESP.restart();
  }

  // Setup ArduinoOTA
  ArduinoOTA.setHostname("esp32-sos-device"); // Nama perangkat di jaringan

  ArduinoOTA.onStart([]() {
    Serial.println("Memulai Updet...");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nSelesai");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
  });

  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle(); // Wajib ada supaya fungsi update tetap standby
  playSOS();           // Jalankan fungsi SOS
}