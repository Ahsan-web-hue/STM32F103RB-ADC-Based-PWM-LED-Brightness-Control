#include "main.h"
#include "tim.h"
#include "PWM_HAL.h"
#include "ADC_HAL.h"

PWM_HAL PWM1;
PWM_HAL PWM2;
PWM_HAL PWM3;

ADC_HAL ADC;

void SystemClock_Config(void);

int main(void)
{
    /*--------------------------------------------------
     * Initialize HAL FIRST
     *--------------------------------------------------*/
    HAL_Init();

    /*--------------------------------------------------
     * Configure System Clock
     *--------------------------------------------------*/
    SystemClock_Config();

    /*--------------------------------------------------
     * Initialize GPIO
     *--------------------------------------------------*/


    /*--------------------------------------------------
     * Initialize TIM3
     *--------------------------------------------------*/
    MX_TIM3_Init();

    /*--------------------------------------------------
     * Initialize ADC
     *--------------------------------------------------*/
    ADC_Init(&ADC);

    /*--------------------------------------------------
     * Initialize PWM objects
     *--------------------------------------------------*/
    PWM_Init(&PWM1);
    PWM_Init(&PWM2);
    PWM_Init(&PWM3);

    /*--------------------------------------------------
     * Configure PWM objects
     *--------------------------------------------------*/
    PWM_ObjectConfig(
        &PWM1,
        &htim3,
        TIM_CHANNEL_1,
        999U
    );

    PWM_ObjectConfig(
        &PWM2,
        &htim3,
        TIM_CHANNEL_2,
        999U
    );

    PWM_ObjectConfig(
        &PWM3,
        &htim3,
        TIM_CHANNEL_3,
        999U
    );

    /*--------------------------------------------------
     * Start PWM
     *--------------------------------------------------*/
    PWM_Start(&PWM1);
    PWM_Start(&PWM2);
    PWM_Start(&PWM3);

    /*--------------------------------------------------
     * Set fixed brightness for testing
     *--------------------------------------------------*/
    PWM_SetDutyCycle(&PWM1, 100U);
    PWM_SetDutyCycle(&PWM2, 100U);
    PWM_SetDutyCycle(&PWM3, 100U);

    /*--------------------------------------------------
     * Main Loop
     *--------------------------------------------------*/
    while (1)
    {
    	 uint16_t adcValue;
    	    uint8_t duty;

    	    adcValue = ADC_Read(&ADC);

    	    duty = (uint8_t)(
    	        ((uint32_t)adcValue * 100U) / 4095U
    	    );

    	    PWM_SetDutyCycle(&PWM1, duty);
    	    PWM_SetDutyCycle(&PWM2, duty);
    	    PWM_SetDutyCycle(&PWM3, duty);

    	    HAL_Delay(10U);
    }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
