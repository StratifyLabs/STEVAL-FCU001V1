
//Copyright 2021 Stratify Labs, See LICENSE.md for details

#include "debug_config.h"


void debug_initialize() {
  //initialize the serial debug output
  //initialize the debug LED
  #error "debug_initialize() not implemented"
}

void debug_write(const void *buf, int nbyte) {
  //write the serial debut output
  #error "debug_write() not implemented"
}

void debug_enable_led() {
  //turn the debug LED on
  #warning "debug_enable_led() not implemented"
}

void debug_disable_led() {
  //turn the debug LED off
  #warning "debug_disable_led() not implemented"
}

void debug_trace_event(void * event){
  //write the event to the trace ffifo
  #warning "debug_trace_event() not implemented"
}