#ifndef TIMMER_HAL_H
#define TIMMER_HAL_H


#include "stm32f1xx_hal.h"

typedef struct
{
    /**
     * @brief Pointer to STM32 HAL timer handle.
     */
    TIM_HandleTypeDef *TimerHandle;

    /**
     * @brief Software timer tick counter.
     *
     * @details This variable is modified inside the timer interrupt
     *          callback and therefore declared volatile.
     */
    volatile uint32_t Tick;

} TIMER_HAL;

/**
 * @brief Initialize the timer HAL object.
 *
 * @param[in,out] timer Pointer to the timer HAL object.
 */
void TIMER_Init(TIMER_HAL * const timer);

/**
 * @brief Start the timer in interrupt mode.
 *
 * @param[in,out] timer Pointer to the timer HAL object.
 */
void TIMER_Start(TIMER_HAL * const timer);

/**
 * @brief Stop the timer interrupt.
 *
 * @param[in,out] timer Pointer to the timer HAL object.
 */
void TIMER_Stop(TIMER_HAL * const timer);

/**
 * @brief Get the current timer tick.
 *
 * @param[in] timer Pointer to the timer HAL object.
 *
 * @return Current timer tick value.
 */
uint32_t TIMER_GetTick(TIMER_HAL * const timer);

/**
 * @brief Check whether the requested delay has elapsed.
 *
 * @param[in] timer     Pointer to the timer HAL object.
 * @param[in] startTick Tick value at the start of the delay.
 * @param[in] delayMs   Required delay in milliseconds.
 *
 * @return 1U if the delay has elapsed; otherwise 0U.
 */
uint8_t TIMER_IsElapsed(TIMER_HAL * const timer,
                        uint32_t startTick,
                        uint32_t delayMs);

#endif /* TIMMER_HAL_H */
