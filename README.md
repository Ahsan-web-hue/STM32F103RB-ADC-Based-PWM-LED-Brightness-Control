# STM32F103RB-ADC-Based-PWM-LED-Brightness-Control
📌 Project Overview

This project demonstrates ADC-based PWM control using the STM32 Nucleo-F103RB. A 10kΩ potentiometer is connected to the ADC input, and its analog value is converted into a PWM duty cycle. The PWM signal is then used to control the brightness of three LEDs.

The project is developed using STM32CubeIDE, STM32 HAL Library, and C language, with a custom PWM Hardware Abstraction Layer (HAL).


⚙️ Working Principle
10kΩ Potentiometer
        ↓
    PA0 / ADC1
        ↓
   ADC Value 0–4095
        ↓
  Duty Cycle 0–100%
        ↓
      TIM3 PWM
    ↙     ↓     ↘
  PA6    PA7    PB0
   ↓      ↓      ↓
 LED1    LED2    LED3

 | Component     | STM32 Pin | Function |
| ------------- | --------- | -------- |
| Potentiometer | PA0       | ADC1_IN0 |
| LED1          | PA6       | TIM3_CH1 |
| LED2          | PA7       | TIM3_CH2 |
| LED3          | PB0       | TIM3_CH3 |

🛠️ Technologies Used
STM32 Nucleo-F103RB
STM32CubeIDE
STM32 HAL Library
C Programming
ADC
TIM3 PWM
GPIO
Custom PWM HAL
📊 PWM Configuration
Timer: TIM3
Prescaler: 71
Period (ARR): 999
PWM Frequency: Approximately 1 kHz
Duty Cycle: 0–100%
ADC Resolution: 12-bit (0–4095)
📁 Project Structure
Core/
├── Inc/
│   ├── ADC_HAL.h
│   ├── GPIO_HAL.h
│   └── PWM_HAL.h
│
└── Src/
    ├── ADC_HAL.c
    ├── GPIO_HAL.c
    ├── PWM_HAL.c
    └── main.c

🎯 Objectives
Interface a potentiometer with the STM32 ADC.
Convert ADC values into PWM duty cycles.
Generate PWM using the TIM3 timer.
Control LED brightness using PWM.
Implement a reusable PWM HAL.
👨‍💻 Author

Ahsan Basharat


    If you have any queries, please contact:

ahsanbasharatali38@gmail.com
