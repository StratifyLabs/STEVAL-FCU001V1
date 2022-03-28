// Copyright 2021 Stratify Labs, See LICENSE.md for details

#include <sdk/types.h>
#include <sos/arch.h>
#include <sos/fs/devfs.h>

#include <mcu/flash.h>
#include <sos/config.h>
#include <stm32_config.h>

#include "boot_link_config.h"

const struct __sFILE_fake __sf_fake_stdin;
const struct __sFILE_fake __sf_fake_stdout;
const struct __sFILE_fake __sf_fake_stderr;

#include "../src/config.h"

void boot_event_handler(int event, void *args) {}

// Use PA4 -- right to GND
#define HW_REQUEST_PORT 0
#define HW_REQUEST_MASK (1 << 10)
int boot_is_bootloader_requested() {
  // check HW pin for bootloader request
  stm32_initialize(); // start GPIO clocks
  pio_attr_t attr;
  attr.o_pinmask = HW_REQUEST_MASK;
  attr.o_flags = PIO_FLAG_IS_PULLUP;
  sos_config.sys.pio_set_attributes(HW_REQUEST_PORT, &attr);
  cortexm_delay_ms(5);
  return sos_config.sys.pio_read(HW_REQUEST_PORT, HW_REQUEST_MASK) == 0;
}

int boot_flash_erase_page(const devfs_handle_t *handle, void *ctl) {
  return mcu_flash_erasepage(handle, ctl);
}

int boot_flash_write_page(const devfs_handle_t *handle, void *ctl) {
  return mcu_flash_writepage(handle, ctl);
}

const void *boot_kernel_request_api(u32 request) {
  MCU_UNUSED_ARGUMENT(request);
  return 0;
}
