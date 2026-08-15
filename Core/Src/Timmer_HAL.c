#include "Timmer_HAL.h"

/* Active timer object */
static TIMER_HAL *timerObject = NULL;


/*------------------------------------------------------------
 * Function : TIMER_Init()
 * Purpose  : Initialize timer object
 *-----------------------------------------------------------*/
void TIMER_Init(TIMER_HAL * const timer)
{
    if (timer != NULL)
    {
        timer->Tick = 0U;

        timerObject = timer;
    }
}


/*------------------------------------------------------------
 * Function : TIMER_Start()
 * Purpose  : Start timer in interrupt mode
 *-----------------------------------------------------------*/
void TIMER_Start(TIMER_HAL * const timer)
{
    if (timer != NULL)
    {
        if (timer->TimerHandle != NULL)
        {
            (void)HAL_TIM_Base_Start_IT(timer->TimerHandle);
        }
    }
}


/*------------------------------------------------------------
 * Function : TIMER_Stop()
 * Purpose  : Stop timer
 *-----------------------------------------------------------*/
void TIMER_Stop(TIMER_HAL * const timer)
{
    if (timer != NULL)
    {
        if (timer->TimerHandle != NULL)
        {
            (void)HAL_TIM_Base_Stop_IT(timer->TimerHandle);
        }
    }
}


/*------------------------------------------------------------
 * Function : TIMER_GetTick()
 * Purpose  : Get current timer tick
 *-----------------------------------------------------------*/
uint32_t TIMER_GetTick(TIMER_HAL * const timer)
{
    uint32_t tick;

    tick = 0U;

    if (timer != NULL)
    {
        tick = timer->Tick;
    }

    return tick;
}


/*------------------------------------------------------------
 * Function : TIMER_IsElapsed()
 * Purpose  : Check whether delay has elapsed
 *-----------------------------------------------------------*/
uint8_t TIMER_IsElapsed(TIMER_HAL * const timer,
                        uint32_t startTick,
                        uint32_t delayMs)
{
    uint32_t currentTick;
    uint32_t elapsedTime;
    uint8_t result;

    currentTick = 0U;
    elapsedTime = 0U;
    result = 0U;

    if (timer != NULL)
    {
        currentTick = timer->Tick;

        elapsedTime = currentTick - startTick;

        if (elapsedTime >= delayMs)
        {
            result = 1U;
        }
        else
        {
            result = 0U;
        }
    }

    return result;
}


/*------------------------------------------------------------
 * Function : HAL_TIM_PeriodElapsedCallback()
 * Purpose  : Timer interrupt callback
 *-----------------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if ((htim != NULL) && (timerObject != NULL))
    {
        if (htim == timerObject->TimerHandle)
        {
            timerObject->Tick++;
        }
        else
        {
            /* Different timer interrupt */
        }
    }
    else
    {
        /* Invalid pointer */
    }
}
