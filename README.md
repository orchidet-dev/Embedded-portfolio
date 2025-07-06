# Embedded-portfolio
Bienvenue dans ce dépôt contenant mes projets autour de la carte **STM32L476RG Nucleo-64**.  
Ces projets visent à illustrer la programmation bas-niveau en C (CMSIS), la gestion des périphériques, les interruptions, les timers, ainsi que des systèmes embarqués plus avancés.

# 🚀 STM32L476RG-Nucleo Projects (PlatformIO)

Ce dépôt regroupe plusieurs projets développés sur la carte **STM32L476RG Nucleo-64**, programmés en **C bas-niveau avec CMSIS**, et gérés avec **PlatformIO sous VS Code**.

L’objectif est de démontrer ma compréhension des systèmes embarqués en manipulant directement les registres STM32, sans utiliser HAL, et en construisant des modules propres : gpio, timer, uart, etc.

---

## 🧰 Environnement de développement

- 💻 **Carte** : STM32 Nucleo-L476RG  
- 🧠 **Microcontrôleur** : ARM Cortex-M4 (80 MHz, FPU, DSP)  
- 💡 **IDE** : [Visual Studio Code](https://code.visualstudio.com/)  
- ⚙️ **PlatformIO** : pour la compilation, le flash, l'organisation multi-projets  
- 📚 **Librairies** : CMSIS uniquement (pas de HAL)

---

## 📁 Structure du dépôt

```text
STM32L476RG-NUCLEO/
├── .pio/                    # Dossier PlatformIO (généré automatiquement)
├── .vscode/                 # Fichiers de configuration pour VS Code
├── platformio.ini           # Configuration globale PIO (board, build flags…)
├── blinky_timer/            # Clignotement LED via Timer
├── pwm_dma/                 # PWM avec DMA
├── adc_temp/                # Lecture température interne
├── rtc_alarm/               # Alarme RTC
├── uart_logger/             # Logger UART
├── freertos_scheduler/      # Scheduler FreeRTOS
├── modbus_slave/            # Esclave Modbus RTU
└── lora_sensor_node/        # Noeud capteur LoRa simulé
