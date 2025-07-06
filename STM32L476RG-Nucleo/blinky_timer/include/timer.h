#ifndef TIMER_H
#define TIMER_H 

#include "stm32l4xx.h"          // Include the STM32L4xx header file


#define MAX_MS 65               // Maximum milliseconds for a single delay chunk (65.535 ms at 1 MHz timer clock)
#define MAX_US 65000            // Maximum microseconds for a single delay chunk (65535 us at 1 MHz timer clock)
#define TIMER2_PRESCALER 79     // Prescaler value for 1 MHz timer clock (assuming 80 MHz system clock)
#define TIMER2_ARR 0xFFFF       // Auto-reload value for maximum delay (65535 ticks)

void Timer2_Init(void);
void Timer2_Delay_ms(uint32_t ms);
void Timer2_Delay_us(uint32_t us);
void Timer2_millis(uint32_t ms);

#endif // TIMER_H