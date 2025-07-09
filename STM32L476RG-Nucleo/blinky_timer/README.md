# 💡 Blinky Timer – STM32L476RG

Ce projet illustre l'utilisation du **Timer2** du STM32L476RG pour générer :

- ✅ un **clignotement précis** de deux LEDs (PA5 et PB5)
- ✅ des **fonctions de délai bloquant** en microsecondes et millisecondes
- ✅ une **interruption toutes les 65ms** pour exécuter une action périodique

---

## 🎯 Objectifs

- Configurer **Timer2** pour générer des ticks à 1 MHz
- Implémenter :
  - `Timer2_Delay_us(us)` : délai en microsecondes
  - `Timer2_Delay_ms(ms)` : délai en millisecondes
- Générer une **interruption toutes les 65ms**
- Clignoter deux LEDs :
  - **PA5** (LED verte intégrée)
  - **PB5** (LED externe ou GPIO libre)

---

## 📁 Fichiers principaux

| Fichier              | Rôle |
|----------------------|------|
| `main.c`             | Boucle principale et logique de clignotement |
| `timer.c/.h`         | Configuration du Timer2 et gestion des délais |
| `gpio.c/.h`          | Initialisation et toggling des GPIO PA5, PB5 |
| `config.h`           | Définition des constantes et autres paramètres si nécessaire |

---

## ⚙️ Configuration Timer2

- **Prescaler** : 79 → fréquence timer = 1 MHz
- **ARR** : 65535 → compte jusqu'à ~65 ms
- **Interruption** activée toutes (65ms)
- **Compteur 16 bits** utilisé pour mesures de temps précises

---

## 🧪 Comportement attendu

- Chaque **100ms**, la LED sur **PA5** est inversée
- Chaque **1ms**, la LED sur **PB5** est inversée (via compteur dans ISR)
- Aucun `HAL_Delay`, tout est basé sur des timers CMSIS

---

## 🚀 Compilation & Flash

Assure-toi d’être dans le dossier racine du projet (`blinky_timer/`), puis :

```bash
pio run --target upload
pio device monitor

