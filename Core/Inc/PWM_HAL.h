#ifndef PWM_HAL_H
#define PWM_HAL_H

#include "stm32f1xx_hal.h"

/* PWM HAL Object */
typedef struct
{
    TIM_HandleTypeDef *TimerHandle;
    uint32_t Channel;
    uint32_t Period;

} PWM_HAL;

/* PWM Initialization */
void PWM_Init(PWM_HAL * const pwm);

/* Start PWM */
HAL_StatusTypeDef PWM_Start(PWM_HAL * const pwm);

/* Stop PWM */
HAL_StatusTypeDef PWM_Stop(PWM_HAL * const pwm);

/* Set PWM Duty Cycle */
void PWM_SetDutyCycle(PWM_HAL * const pwm, uint8_t duty);

/* Get PWM Duty Cycle */
uint8_t PWM_GetDutyCycle(const PWM_HAL * const pwm);
void PWM_ObjectConfig(PWM_HAL * const pwm,
                      TIM_HandleTypeDef *timer,
                      uint32_t channel,
                      uint32_t period);

#endif
