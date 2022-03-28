//
// Created by Tyler Gilbert on 3/28/22.
//



#include <sos/arch.h>
#include <stm32f4xx_hal.h>
#include <stm32_config.h>


#include "config.h"

static char stm32_usb_rx_buffer[CONFIG_USB_RX_BUFFER_SIZE] MCU_SYS_MEM;

const stm32_config_t stm32_config = {
  .flash_program_millivolts = 3300,
  .usb = {
    .rx_buffer = stm32_usb_rx_buffer,
    .rx_buffer_size = CONFIG_USB_RX_BUFFER_SIZE,
    .rx_fifo_word_size = 128, // RX fifo for all endpoints
    .tx_fifo_word_size[0] = 32, // TX endpoint 0
    .tx_fifo_word_size[1] = 0, // TX endpoint 1
    .tx_fifo_word_size[2] = 128, // TX endpoint 2
    .tx_fifo_word_size[3] = 0, // TX endpoint 3
    .tx_fifo_word_size[4] = 0, // TX endpoint 4
    .tx_fifo_word_size[5] = 0  // TX endpoint 5
  }};


void SystemClock_Config(){
    RCC_OscInitTypeDef RCC_OscInitStruct = {};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {};

    /** Configure the main internal regulator output voltage
        */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
    /** Initializes the CPU, AHB and APB busses clocks
        */
    RCC_OscInitStruct.OscillatorType =
            RCC_OSCILLATORTYPE_LSI
            | RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 96;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    /** Initializes the CPU, AHB and APB busses clocks
        */
    RCC_ClkInitStruct.ClockType =
            RCC_CLOCKTYPE_HCLK
            | RCC_CLOCKTYPE_SYSCLK
            | RCC_CLOCKTYPE_PCLK1
            | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

}
