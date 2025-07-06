#ifndef GPIO_H
#define GPIO_H

#include "stm32l4xx.h"

#define LED_PIN_PA5         5          // Pin number for the LED (PA5)
#define LED_PIN_PB5         5          // Pin number for the LED (PB5)

void GPIO_Init(void);
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif // GPIO_H
