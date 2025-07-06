
#include "gpio.h"

void GPIO_Init(void){
    // This function can be expanded to configure specific GPIO pins  
    //Enable clock for GPIOA
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // Enable clock for GPIOB if needed

    // Set PA5 as output (for example, for an LED)
    GPIOA->MODER &= ~(0x3 << (5 * 2)); // Clear mode bits for PA5
    GPIOA->MODER |= (0x1 << (5 * 2));  // Set PA5 to output mode
    GPIOA->OTYPER &= ~(0x1 << 5);       // Set PA5 to push-pull output
    GPIOA->OSPEEDR &= ~(0x3 << (5 * 2)); // Clear speed bits for PA5
    GPIOA->OSPEEDR |= (0x1 << (5 * 2)); // Set PA5 to medium speed

    //Set PB5 as output (for example, for another LED)
    GPIOB->MODER &= ~(0x3 << (5 * 2)); // Clear mode bits for PB5
    GPIOB->MODER |= (0x1 << (5 * 2));  // Set PB5 to output mode
    GPIOB->OTYPER &= ~(0x1 << 5);       // Set PB5 to push-pull output
    GPIOB->OSPEEDR &= ~(0x3 << (5 * 2)); // Clear speed bits for PB5
    GPIOB->OSPEEDR |= (0x1 << (5 * 2)); // Set PB5 to medium speed  
}

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    // Set the specified pin high
    GPIOx->ODR |= (1U << GPIO_Pin);
}
void GPIO_ResetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    // Set the specified pin low
    GPIOx->ODR &= ~(1U << GPIO_Pin);
}
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    // Toggle the specified pin
    GPIOx->ODR ^= (1U << GPIO_Pin);
}