
//Copyright 2021 Stratify Labs, See LICENSE.md for details

#include "clock_config.h"

void clock_initialize(
    int (*handle_match_channel0)(void *context, const mcu_event_t *data),
    int (*handle_match_channel1)(void *context, const mcu_event_t *data),
    int (*handle_overflow)(void *context, const mcu_event_t *data)) {
      //initialize the clock
}

void clock_enable() {
  #error "clock_enable() not implemented"
}

u32 clock_disable() {
  //stop the clock and return its present value
    #error "clock_disable() not implemented"

  u32 result = 0;
  return result;
}

void clock_set_channel(const mcu_channel_t *channel) {
  //set the value of the specified channel
    #error "clock_set_channel() not implemented"

}

void clock_get_channel(mcu_channel_t *channel) {
  //update channel with the channel value
    #error "clock_get_channel() not implemented"
}

u32 clock_microseconds() { 
  //return the value of the clock in microseconds
  #error "clock_microseconds() not implemented"
 return 0; 
}

u32 clock_nanoseconds() { 
  //return the number of nanseconds from 0 to 1000 (as a sub unit of clock_microseconds())
  //this can just return zero if nanosecond precision is not needed
  #warning "clock_nanoseconds() not implemented"
  return 0; 
}
