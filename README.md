# 🧠 Embedded-Portfolio

Bienvenue dans ce dépôt contenant mes projets embarqués sur différentes plateformes :

- 🔷 **STM32L476RG Nucleo-64**
- 🔷 **ESP32S3 (WifiKit32)**
- 🔷 **Arduino Mega 2560**
- 🔷 **STM32L475RG Discovery IoT (B-L475E-IOT01A)**

Ces projets visent à illustrer la programmation **bas-niveau (CMSIS)**, l’usage de **protocoles de communication**, la **gestion du temps réel**, et l’interfaçage avec des **capteurs** et **périphériques IoT**.  
Tous les projets sont développés avec **PlatformIO sous VS Code**, et organisés par carte.

---

## 🧰 Environnement de développement

- 🖥️ **IDE** : Visual Studio Code + PlatformIO  
- 🛠️ **Langages** : C / C++, Python(scripting) (CMSIS, ESP-IDF, Arduino Core selon carte)  
- 📦 **Build system** : PlatformIO  
- 📚 **Librairies utilisées** : CMSIS, Arduino, ESP-IDF, FreeRTOS

---

## 📘 STM32L476RG (Nucleo-64)

| Projet               | Description |
|----------------------|-------------|
| `blinky_timer`       | Clignotement LED avec timer (CMSIS) |
| `pwm_dma`            | Génération de PWM avec transfert DMA |
| `adc_temp`           | Lecture température interne via ADC |
| `rtc_alarm`          | Réveil avec RTC + gestion d’alarmes |
| `uart_logger`        | Envoi de données série via UART (CMSIS) |
| `freertos_scheduler` | Tâches FreeRTOS basiques avec priorités |
| `modbus_slave`       | Esclave Modbus RTU sur UART |
| `lora_sensor_node`   | Envoi de données simulées via LoRa |

📁 Dossier : `STM32L476RG-NUCLEO/`
```text
STM32L476RG-NUCLEO/
├── .pio/                    # Fichiers générés par PlatformIO
├── .vscode/                 # Configuration VS Code
├── platformio.ini           # Config PIO pour tous les projets
├── blinky_timer/            # Clignotement LED via Timer
├── pwm_dma/                 # PWM avec DMA
├── adc_temp/                # Lecture température interne
├── rtc_alarm/               # Alarme RTC
├── uart_logger/             # Logger UART
├── freertos_scheduler/      # Scheduler FreeRTOS
├── modbus_slave/            # Esclave Modbus RTU
└── lora_sensor_node/        # Noeud capteur LoRa simulé


## 📘 ESP32S3 (WifiKit32)

| Projet              | Description |
|---------------------|-------------|
| `wifi_scan`         | Scan des réseaux Wi-Fi disponibles |
| `web_dashboard`     | Interface Web embarquée (ESPAsyncWebServer) |
| `mqtt_temp_client`  | Client MQTT avec capteur simulé |
| `ota_update`        | Mise à jour du firmware via Wi-Fi |
| `esp_cam_stream`    | Stream caméra (si module caméra branché) |
| `ble_uart`          | Communication BLE ↔ téléphone |
| `lowpower_logger`   | Envoi périodique de données avec deep sleep |

📁 Dossier : `ESP32S3-WifiKit32/`
ESP32S3-WifiKit32/
├── platformio.ini           # Config ESP32S3
├── wifi_scan/               # Scan des réseaux Wi-Fi
├── web_dashboard/           # Dashboard Web embarqué
├── mqtt_temp_client/        # Client MQTT simulant un capteur
├── ota_update/              # Mise à jour OTA
├── esp_cam_stream/          # Stream caméra
├── ble_uart/                # UART via BLE
└── lowpower_logger/         # Logger basse consommation


## 📘 Arduino Mega 2560

| Projet           | Description |
|------------------|-------------|
| `lcd_menu`       | Menu interactif via écran LCD 16x2 |
| `servo_control`  | Contrôle de plusieurs servos avec potentiomètre |
| `rfid_access`    | Lecture RFID + ouverture de porte |
| `i2c_scanner`    | Scanner de bus I2C |
| `uart_bridge`    | Pont série entre deux ports UART |
| `data_logger`    | Log de données sur carte SD |

📁 Dossier : `Arduino-Mega2560/`

Arduino-Mega2560/
├── platformio.ini           # Config Arduino Mega
├── lcd_menu/                # Menu interactif LCD
├── servo_control/           # Contrôle de servos
├── rfid_access/             # Lecture de badge RFID
├── i2c_scanner/             # Scanner I2C
├── uart_bridge/             # Pont UART↔UART
└── data_logger/             # Log sur carte SD


## 📘 B-L475E-IOT01A (STM32L475RG Discovery IoT)

| Projet                | Description |
|------------------------|-------------|
| `wifi_mqtt_station`    | Envoi de données capteur via MQTT |
| `gesture_control`      | Reconnaissance de mouvement via accéléro |
| `tls_https_client`     | Connexion sécurisée à un serveur (TLS) |
| `iot_dashboard`        | Dashboard distant avec Grafana + Node-RED |
| `lps22hb_logger`       | Acquisition pression avec LPS22HB |
| `ambient_sound_react`  | LED qui réagit au son (micro intégré) |

📁 Dossier : `STM32L475RG-Discovery/`

STM32L475RG-Discovery/
├── platformio.ini           # Config carte IoT STM32
├── wifi_mqtt_station/       # MQTT + Wi-Fi
├── gesture_control/         # Reconnaissance de mouvements
├── tls_https_client/        # Connexion sécurisée TLS
├── iot_dashboard/           # Dashboard distant (Grafana)
├── lps22hb_logger/          # Acquisition capteur pression
└── ambient_sound_react/     # Réaction à l’environnement sonore

## 🔧 Compilation & Flash

Tous les projets sont compatibles avec PlatformIO.

```bash
# Compilation
pio run

# Flash
pio run --target upload

# Monitor série
pio device monitor
