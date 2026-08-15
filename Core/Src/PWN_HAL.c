#include "PWM_HAL.h"

/* Initialize PWM */
void PWM_Init(PWM_HAL * const pwm)
{
    if (pwm != NULL)
    {
        pwm->TimerHandle = NULL;
        pwm->Channel = 0U;
        pwm->Period = 0U;
    }
}
void PWM_ObjectConfig(PWM_HAL * const pwm,
                      TIM_HandleTypeDef *timer,
                      uint32_t channel,
                      uint32_t period)
{
    if ((pwm != NULL) && (timer != NULL))
    {
        pwm->TimerHandle = timer;
        pwm->Channel = channel;
        pwm->Period = period;
    }
}
/* Start PWM */
HAL_StatusTypeDef PWM_Start(PWM_HAL * const pwm)
{
    HAL_StatusTypeDef status = HAL_ERROR;

    if ((pwm != NULL) && (pwm->TimerHandle != NULL))
    {
        status = HAL_TIM_PWM_Start(
                    pwm->TimerHandle,
                    pwm->Channel);
    }

    return status;
}

/* Stop PWM */
HAL_StatusTypeDef PWM_Stop(PWM_HAL * const pwm)
{
    HAL_StatusTypeDef status = HAL_ERROR;

    if ((pwm != NULL) && (pwm->TimerHandle != NULL))
    {
        status = HAL_TIM_PWM_Stop(
                    pwm->TimerHandle,
                    pwm->Channel);
    }

    return status;
}

/* Set PWM Duty Cycle */
void PWM_SetDutyCycle(PWM_HAL * const pwm, uint8_t duty)
{
    uint32_t compareValue;

    if ((pwm != NULL) && (pwm->TimerHandle != NULL))
    {
        if (duty > 100U)
        {
            duty = 100U;
        }

        compareValue =
            ((uint32_t)duty * (pwm->Period + 1U)) / 100U;

        __HAL_TIM_SET_COMPARE(
            pwm->TimerHandle,
            pwm->Channel,
            compareValue);
    }
}

/* Get PWM Duty Cycle */
uint8_t PWM_GetDutyCycle(const PWM_HAL * const pwm)
{
    uint32_t compareValue;
    uint8_t duty = 0U;

    if ((pwm != NULL) && (pwm->TimerHandle != NULL))
    {
        compareValue =
            __HAL_TIM_GET_COMPARE(
                pwm->TimerHandle,
                pwm->Channel);

        if (pwm->Period != 0U)
        {
            duty = (uint8_t)
                ((compareValue * 100U) /
                 (pwm->Period + 1U));
        }
    }

    return duty;
}

