# 🧠 Embedded-Projects

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
| `blinky_timer`       | Clignotement LED avec timer 2|
| `adc_read`           | Lecture analogique       


## 📘 ESP32S3 (WifiKit32)

| Projet              | Description |
|---------------------|-------------|
| `wifi_scan`         | Scan des réseaux Wi-Fi disponibles |
| `web_dashboard`     | Interface Web embarquée (ESPAsyncWebServer) |


## 📘 Arduino Mega 2560

| Projet           | Description |
|------------------|-------------|
| `lcd_menu`       | Menu interactif via écran LCD 16x2 |
| `servo_control`  | Contrôle de plusieurs servos avec potentiomètre |



## 📘 B-L475E-IOT01A (STM32L475RG Discovery IoT)

| Projet                | Description |
|------------------------|-------------|
| `wifi_mqtt_station`    | Envoi de données capteur via MQTT |
| `gesture_control`      | Reconnaissance de mouvement via accéléro |


## 🔧 Compilation & Flash

Tous les projets sont compatibles avec PlatformIO.

```bash
# Compilation
pio run

# Flash
pio run --target upload

# Monitor série
pio device monitor

## Utilisation avec Docker 🐳

Ce dépôt contient plusieurs projets embarqués STM32. Pour faciliter la compilation, le flash et le debug, un environnement Docker est fourni. Cela permet de garantir un environnement de développement cohérent et portable, sans nécessiter d'installation locale complexe.

### Pré-requis 🔧

- [Docker](https://docs.docker.com/get-docker/) installé sur votre machine.
- Un clone du dépôt (via `git clone`).

### Construction de l'image Docker

Depuis la racine du dépôt (là où se trouve le `Dockerfile`), lancez :

```bash
docker build -t embedded_pio .

Compilation d’un projet
Pour compiler un projet spécifique, utilisez la commande suivante depuis la racine du dépôt :

docker run --rm -it \
  -v "$(pwd):/home/devuser/project" \
  -w /home/devuser/project/<chemin_vers_projet> \
  embedded_pio

Par exemple, pour compiler le projet blinky_timer :

docker run --rm -it \
  -v "$(pwd):/home/devuser/project" \
  -w /home/devuser/project/STM32L476RG-NUCLEO/blinky_timer \
  embedded_pio

Sous Linux, vous pouvez ajouter l’option --device pour accéder au port USB, par exemple :
--device /dev/ttyACM0
