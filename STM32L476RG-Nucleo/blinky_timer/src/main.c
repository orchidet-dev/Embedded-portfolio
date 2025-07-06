#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "stm32l4xx.h"
#include "gpio.h"
#include "timer.h"
#include "config.h"
#include "stm32l4xx_hal.h"

// Function prototypes
void SystemClock_config(void);

// Main function
int main(void) {

    /*Initialize the system clock*/
    SystemClock_config();

    /*Initialize the GPIO for LED*/
    GPIO_Init(); 

    /*Initialize Timer2 for blinking*/
    Timer2_Init();

    /*Main loop*/
    while (1) {
        //Uncomment the function delay you want to use
        //Timer2_Delay_ms(100); // Delay for 100 milliseconds
        Timer2_Delay_us(100000); // Delay for 100 milliseconds
        GPIO_TogglePin(GPIOA, LED_PIN_PA5); // Toggle the LED connected to PA5
        GPIO_TogglePin(GPIOB, LED_PIN_PB5); // Toggle the LED connected to PA5
    }

    return 0;
}


void SystemClock_config(void) {

    //This function configures the system clock to 80MHz using the HSI (High-Speed Internal) oscillator.
    //Enable HSI
    RCC->CR |= RCC_CR_HSION;                          // Set the HSI ON bit to enable the HSI clock (RCC_CR_HSION = (0x1UL << 8U))
    //Wait until HSI is ready
    while (!(RCC->CR & RCC_CR_HSIRDY));               // Wait until the HSI Ready bit is set (RCC_CR_HSIRDY = (0x1UL << 10U)) 

    //Disable the PLL
    RCC->CR &= ~RCC_CR_PLLON;                         // Clear the PLL ON bit
    while (RCC->CR & RCC_CR_PLLRDY);                  // Wait until the PLL Ready bit is cleared (RCC_CR_PLLRDY = (0x1UL << 25U))
    //Set the PLL source to HSI
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;              // Clear the PLL source bits (RCC_PLLCFGR_PLLSRC = (0x3UL << 0UL))
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI;           // Set the PLL source to HSI (RCC_PLLCFGR_PLLSRC_HSI = 0x0UL)
    //Set the PLL (for 80MHz)
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;                // Clear the PLLM bits (RCC_PLLCFGR_PLLM = (0x3FUL << 0U))
    RCC->PLLCFGR |= (0x2UL << RCC_PLLCFGR_PLLM_Pos);  // Set PLLM to 2 (RCC_PLLCFGR_PLLM_Pos = 4U)
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;                // Clear the PLLN bits (RCC_PLLCFGR_PLLN = (0x1FFUL << 6U))
    RCC->PLLCFGR |= (0x30UL << RCC_PLLCFGR_PLLN_Pos); // Set PLLN to 20 (RCC_PLLCFGR_PLLN_Pos = 8U)
    //Set the PLLR to 2 (for system clock)
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLR;                // Clear the PLLR bits (RCC_PLLCFGR_PLLR = (0x3UL << 25U))
    RCC->PLLCFGR |= (0x3UL << RCC_PLLCFGR_PLLR_Pos);  // Set PLLR to 3 (RCC_PLLCFGR_PLLR_Pos = 25U)
    //Set the PLLP to 7 (for PLLSAI3CLK (SAI1 and SAI2 clock))
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;                // Set PLLP to 7 (RCC_PLLCFGR_PLLP = (0x1UL << 17U))    //Set the PLLQ to 4 (for USB clock)
    //set the PLLQ for PLL48M1CLK. This output can be selected for USB, RNG, SDMMC (48MHz clock).
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ;                // Clear the PLLQ bits (RCC_PLLCFGR_PLLQ = (0xFUL << 24U))
    RCC->PLLCFGR |= (0x5UL << RCC_PLLCFGR_PLLQ_Pos);  // Set PLLQ to 4 (RCC_PLLCFGR_PLLQ_Pos = 24U)

    //Enable the PLLR (PLLQ and PLLP are not used in this project, no need to enable them)
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;               // Set the PLLREN bit to enable PLLR output (RCC_PLLCFGR_PLLREN = (0x1UL << 24U))
    while(!(RCC->PLLCFGR & RCC_PLLCFGR_PLLR));        // Wait until the PLL Ready bit is set (RCC_CR_PLLRDY = (0x1UL << 25U))
    //Enable the PLL
    RCC->CR |= RCC_CR_PLLON;                          // Set the PLL ON bit to enable
    while (!(RCC->CR & RCC_CR_PLLRDY));               // Wait until the PLL Ready bit is set (RCC_CR_PLLRDY = (0x1UL << 25U))
    //Set the system clock source to PLL
    RCC->CFGR &= ~RCC_CFGR_SW;                        // Clear the SW bits (RCC_CFGR_SW = (0x3UL << 0U))
    RCC->CFGR |= RCC_CFGR_SW_PLL;                     // Set the SW bits to select PLL as system clock source (RCC_CFGR_SW_PLL = (0x2UL << 0U))
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait until the SWS bits indicate PLL is the system clock source (RCC_CFGR_SWS_PLL = (0x3UL << 2U))
    //Set the AHB prescaler to 1 (no division)
    RCC->CFGR &= ~RCC_CFGR_HPRE;                      // Clear the HPRE bits (RCC_CFGR_HPRE = (0xFUL << 4U))
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;                  // Set the HPRE bits to divide by 1 (RCC_CFGR_HPRE_DIV1 = (0x0UL << 4U))
    //Set the APB1 prescaler to 1 (no division)
    RCC->CFGR &= ~RCC_CFGR_PPRE1;                     // Clear the PPRE1 bits (RCC_CFGR_PPRE1 = (0x7UL << 8U))
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;                 // Set the PPRE1 bits to divide by 1 (RCC_CFGR_PPRE1_DIV1 = (0x00000000UL))
    //Set the APB2 prescaler to 1 (no division)
    RCC->CFGR &= ~RCC_CFGR_PPRE2;                     // Clear the PPRE2 bits (RCC_CFGR_PPRE2 = (0x7UL << 11U))
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;                 // Set the PPRE2 bits to divide by 1 (RCC_CFGR_PPRE2_DIV1 = (0x00000000UL))
    //Set the flash latency to 4 wait states (for 80MHz)
    //This is necessary to ensure the flash memory can keep up with the faster clock speed.
    //The flash memory needs to be configured to have enough wait states for the higher clock frequency
    FLASH->ACR &= ~FLASH_ACR_LATENCY;                 // Clear the LATENCY bits (FLASH_ACR_LATENCY = (0x7UL << 0U))
    FLASH->ACR |= FLASH_ACR_LATENCY_4WS;              // Set the LATENCY bits to 4 wait states (FLASH_ACR_LATENCY_4WS = (0x4UL << 0U))

    //Update the SystemCoreClock variable
    SystemCoreClock = 80000000;                        // Set the SystemCoreClock variable to 80MHz

}