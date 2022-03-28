
//Copyright 2021 Stratify Labs, See LICENSE.md for details

#include <sos/arch.h>
#include "config.h"

void mcu_reset_watchdog_timer() {
  #error "mcu_reset_watchdog_timer() not implemented"
}

void mcu_set_interrupt_priority(int number, int priority) {
  NVIC_SetPriority((IRQn_Type)number, priority);
}

int mcu_set_pin_function(const mcu_pin_t *pin, int function, int periph_port) {
  //configure the pin function
  //only needed if application needs to change pin function values
  #error "mcu_set_pin_function() not implemented"
  return 0;
}

