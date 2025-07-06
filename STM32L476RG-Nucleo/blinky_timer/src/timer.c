#include "timer.h"
#include "config.h"
#include "gpio.h"
#include "stm32l4xx.h"

/**
 * @brief Initializes TIM2 for microsecond-precision timing.
 *
 * This function configures TIM2 to run at 1 MHz (1 us per tick) by setting the prescaler
 * and auto-reload register. It also enables the update interrupt and NVIC configuration.
 *
 * @note TIM2 is configured in up-counting mode with the maximum auto-reload value.
 *       The timer interrupt is enabled but the handler must be implemented separately.
 */
void Timer2_Init(void) {

    // Enable clock for Timer 2
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

    // Set Timer 2 prescaler to 80 (for 1 MHz timer clock)
    TIM2->PSC = TIMER2_PRESCALER;           // (80 MHz / 80) = 1 MHz (1 us tick)
    // Set Timer 2 auto-reload value for 1 ms
    TIM2->ARR = TIMER2_ARR;                     // Set the auto-reload value to maximum (65535) (max 65.535 ms at 1 MHz)

    // Configure Timer 2 in up-counting mode
    TIM2->CR1 &= ~TIM_CR1_DIR;              // Set the direction to up
    // Enable Timer 2 update interrupt
    TIM2->DIER |= TIM_DIER_UIE;             // Enable update interrupt

    //Enable the Timer 2 interrupt in NVIC
    NVIC_SetPriority(TIM2_IRQn, 1);         // Set Timer 2 interrupt priority to 1 (lower priority)
    NVIC_EnableIRQ(TIM2_IRQn);              // Enable Timer 2 interrupt in the NVIC
    
    // Enable Timer 2
    TIM2->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief Delays execution for a specified number of milliseconds using TIM2.
 *
 * This function creates a blocking delay by repeatedly waiting for the TIM2 counter
 * to increment by the required number of ticks corresponding to the requested delay.
 * The delay is processed in chunks of up to 65 milliseconds to avoid counter overflow.
 *
 * @param ms Number of milliseconds to delay.
 *
 * @note Assumes TIM2 is configured such that 1 tick equals 1 microsecond (1 MHz timer clock).
 *       The function is blocking and will halt execution until the delay has elapsed.
 */
void Timer2_Delay_ms(uint32_t ms) {

    while (ms > 0) {
        uint32_t chunk = (ms > MAX_MS) ? MAX_MS : ms; // 65 ms max per chunk
        volatile uint16_t start = TIM2->CNT;
        uint16_t wait_ticks = chunk * 1000;           // Convert ms to ticks (1 ms = 1000 us)    
        while ((uint16_t)(TIM2->CNT - start) < wait_ticks);
        ms -= chunk;
    }
}

/**
 * @brief Delays execution for a specified number of microseconds using TIM2.
 *
 * This function creates a blocking delay by waiting for the TIM2 counter
 * to increment by the required number of ticks corresponding to the requested delay.
 * The delay is processed in chunks of up to 65,000 microseconds to avoid counter overflow.
 *
 * @param us Number of microseconds to delay.
 *
 * @note Assumes TIM2 is configured such that 1 tick equals 1 microsecond (1 MHz timer clock).
 *       The function is blocking and will halt execution until the delay has elapsed.
 */
void Timer2_Delay_us(uint32_t us) {
    while (us > 0) {
        uint32_t chunk = (us > MAX_US) ? MAX_US : us; // 65000 us max per chunk
        volatile uint16_t start = TIM2->CNT;
        uint16_t wait_ticks = chunk; // 1 us tick
        while ((uint16_t)(TIM2->CNT - start) < wait_ticks);
        us -= chunk;
    }
}
/**
 * @brief TIM2 interrupt handler.
 *
 * This function handles the TIM2 update interrupt. It checks if the update interrupt flag (UIF)
 * is set, clears the flag, and provides a placeholder for user interrupt handling code.
 * Typical uses include toggling an LED or incrementing a counter.
 */
void TIM2_IRQHandler(void){
    //I don't have a specific action here, but you can implement it as needed.
    //You can toggle an LED periodically or perform other actions.
    //It's a good place to handle periodic tasks.
    //This is not a blocking function, so it should be quick to execute.
    // Check if the update interrupt flag is set
    if (TIM2->SR & TIM_SR_UIF) {
        // Clear the update interrupt flag
        TIM2->SR &= ~TIM_SR_UIF;
        // Add your interrupt handling code here
    }
}

