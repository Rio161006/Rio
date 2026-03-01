# Implement wifi dan OTA di program SOS blinking led

## 1. Ringkasan

### 1.1 Tujuan 
Jadi tujuannya adalah membuat program pada ESP32 C3 yang dapat membuat LED d4 berkedip dengan pola sos yaitu (3 titik, 3 garis, 3 titik) lalu juga dapat diprogram dari jrak jauh over the air (OTA)

### 1.2 Goal

1. mengedipkan LED D4 sesuai "SOS" morse code
2. Memberikan output ke serial monitor untuk tiap huruf saat LED blink morse per huruf
3. Memberikan akses WiFi untuk memungkinkan implementasi fitur OTA
4. Update code dilakukan secara wireless melalui VSCode

## 2. Data Hardware

|komponen |Spesifikasi|
|---------|------------|
|MCU      |ESP32C3 LuatOS Core|
|LED	  |Onboard LED D4 (GPIO 12)|
|Koneksi  |WiFi 2.4GHz|

## 3. Arsitektur Softwar

### 3.1 Framework and Libraries

Framework: VSCode PlatformIO Arduino (C++)
Libraries: 
1. WiFi.h
2. ArduinoOTA.h

### 3.2 Alur koding

1. Setup
- serial begin 9600
- konfigurasi GPIO 13 OUTPUT
- connect ke WiFi SSID & Password (placeholder)
- mengaktifkan ArduinoOTA.begin()

2. Loop
- menjalankan ArduinoOTA.handle() di tiap siklus
- Menjalankan urutan kedipan kode morse "SOS" dengan delay code "S" itu 200ms dan delay code "O" 600ms
- print huruf ke serial monitor saat lampu tiap hruuf kedip
- beri delay setelah telah melakukan 1 morse code "SOS"

### 4. Network & OTA
- Mode: WiFi Station (STA)
- OTA Port: Default (port 3232)
