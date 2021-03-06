
#include <cortexm/task.h>
#include <sos/debug.h>
#include <sos/sos.h>
#include <stm32_config.h>
#include <stm32_types.h>

#include <sos/debug.h>

#include "debug_config.h"

#if ___debug
static UART_HandleTypeDef m_huart;
#endif

#define DEBUG_LED_PORT GPIOB
#define DEBUG_LED_PINMASK (1 << 4)

void debug_initialize() {

  GPIO_InitTypeDef gpio_init = {
    .Mode = GPIO_MODE_OUTPUT_PP,
    .Pin = DEBUG_LED_PINMASK,
    .Speed = GPIO_SPEED_FREQ_LOW};
  HAL_GPIO_Init(DEBUG_LED_PORT, &gpio_init);
  debug_disable_led();

#if ___debug
  __HAL_RCC_USART1_CLK_ENABLE();

  /**USART3 GPIO Configuration
    PA9    ------> USART1_TX
    PA10     ------> USART1_RX
    */
  gpio_init.Pin = (1 << 9) | (1 << 10);
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Pull = GPIO_PULLUP;
  gpio_init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  gpio_init.Alternate = GPIO_AF7_USART1;
  HAL_GPIO_Init(GPIOA, &gpio_init);

  m_huart.Instance = USART1;
  m_huart.Init.BaudRate = 115200;
  m_huart.Init.WordLength = UART_WORDLENGTH_8B;
  m_huart.Init.StopBits = UART_STOPBITS_1;
  m_huart.Init.Parity = UART_PARITY_NONE;
  m_huart.Init.Mode = UART_MODE_TX_RX;
  m_huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  m_huart.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&m_huart);
#endif
}

void debug_write(const void *buf, int nbyte) {
#if ___debug
  const char *cbuf = buf;
  for (int i = 0; i < nbyte; i++) {
    u8 c = cbuf[i];
    HAL_UART_Transmit(&m_huart, &c, 1, HAL_MAX_DELAY);
  }
#endif
}

void debug_enable_led() {
  HAL_GPIO_WritePin(DEBUG_LED_PORT, DEBUG_LED_PINMASK, GPIO_PIN_RESET);
}

void debug_disable_led() {
  HAL_GPIO_WritePin(DEBUG_LED_PORT, DEBUG_LED_PINMASK, GPIO_PIN_SET);
}

#if !_IS_BOOT
#define TRACE_COUNT 16
#define TRACE_FRAME_SIZE sizeof(link_trace_event_t)
#define TRACE_BUFFER_SIZE (sizeof(link_trace_event_t) * TRACE_COUNT)
static char trace_buffer[TRACE_FRAME_SIZE * TRACE_COUNT];
const ffifo_config_t debug_trace_config = {
  .frame_count = TRACE_COUNT,
  .frame_size = sizeof(link_trace_event_t),
  .buffer = trace_buffer};
ffifo_state_t debug_trace_state;

void debug_trace_event(void *event) {
  link_trace_event_header_t *header = event;
  devfs_async_t async;
  const devfs_device_t *trace_dev = &(sos_config.fs.devfs_list[0]);

  // write the event to the fifo
  memset(&async, 0, sizeof(devfs_async_t));
  async.tid = task_get_current();
  async.buf = event;
  async.nbyte = header->size;
  async.flags = O_RDWR;
  trace_dev->driver.write(&(trace_dev->handle), &async);
}
#endif
