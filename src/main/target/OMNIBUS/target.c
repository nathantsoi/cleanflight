
#include <stdbool.h>
#include <stdint.h>

#include <platform.h>
#include "drivers/pwm_mapping.h"

const uint16_t multiPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT    << 8), // PPM input

    PWM2  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM3  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM4  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM5  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM6  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM7  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM8  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM9  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM10 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM11 | (MAP_TO_MOTOR_OUTPUT << 8),
    0xFFFF
};

const uint16_t multiPWM[] = {
    PWM2  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM3  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM4  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM5  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM6  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM7  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM8  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM9  | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM10 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM11 | (MAP_TO_MOTOR_OUTPUT << 8),
    0xFFFF
};

const uint16_t airPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT << 8),     // PPM input
    PWM2  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM3  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM4  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM5  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM6  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM7  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM8  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM9  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM10 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #8
    0xFFFF
};

const uint16_t airPWM[] = {
    PWM2  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM3  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM4  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM5  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM6  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM7  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM8  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM9  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM10 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #8
    0xFFFF
};

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    // PPM Pad
    { TIM3,  GPIOB, Pin_4,  TIM_Channel_1, TIM3_IRQn,               0, Mode_AF_PP, GPIO_PinSource4,  GPIO_AF_2, 0}, // PPM - PB4
    // PB5 / TIM3 CH2 is connected to USBPresent

    //{ TIM16, GPIOA, Pin_6,  TIM_Channel_1, TIM1_UP_TIM16_IRQn,      1, Mode_AF_PP, GPIO_PinSource6,  GPIO_AF_1, 0},  // PWM1 - PA6
    //{ TIM17, GPIOA, Pin_7,  TIM_Channel_1, TIM1_TRG_COM_TIM17_IRQn, 1, Mode_AF_PP, GPIO_PinSource7,  GPIO_AF_1, 0},  // PWM2 - PA7
    { TIM4,  GPIOB, Pin_8,  TIM_Channel_3, TIM4_IRQn,               1, Mode_AF_PP, GPIO_PinSource8,  GPIO_AF_2, 0},  // PWM3 - PB8
    { TIM4,  GPIOB, Pin_9,  TIM_Channel_4, TIM4_IRQn,               1, Mode_AF_PP, GPIO_PinSource9,  GPIO_AF_2, 0},  // PWM4 - PB9
    { TIM15, GPIOA, Pin_2,  TIM_Channel_1, TIM1_BRK_TIM15_IRQn,     1, Mode_AF_PP, GPIO_PinSource2,  GPIO_AF_9, 0},  // PWM5 - PA2
    { TIM15, GPIOA, Pin_3,  TIM_Channel_2, TIM1_BRK_TIM15_IRQn,     1, Mode_AF_PP, GPIO_PinSource3,  GPIO_AF_9, 0},  // PWM6 - PA3
    { TIM2,  GPIOA, Pin_0,  TIM_Channel_1, TIM2_IRQn,               1, Mode_AF_PP, GPIO_PinSource0,  GPIO_AF_1, 0},  // PWM7 - PA0
    { TIM2,  GPIOA, Pin_1,  TIM_Channel_2, TIM2_IRQn,               1, Mode_AF_PP, GPIO_PinSource1,  GPIO_AF_1, 0},  // PWM8 - PA1

    // UART3 RX/TX
    { TIM2,  GPIOB, Pin_10, TIM_Channel_3, TIM2_IRQn,               1, Mode_AF_PP, GPIO_PinSource10, GPIO_AF_1, 0}, // PWM9  - PB10 - TIM2_CH3 / USART3_TX (AF7)
    { TIM2,  GPIOB, Pin_11, TIM_Channel_4, TIM2_IRQn,               1, Mode_AF_PP, GPIO_PinSource11, GPIO_AF_1, 0}, // PWM10 - PB11 - TIM2_CH4 / USART3_RX (AF7)

    // LED Strip Pad
    { TIM1,  GPIOA, Pin_8,  TIM_Channel_1, TIM1_CC_IRQn,            1, Mode_AF_PP, GPIO_PinSource8,  GPIO_AF_6, 0},  // GPIO_TIMER / LED_STRIP
};

