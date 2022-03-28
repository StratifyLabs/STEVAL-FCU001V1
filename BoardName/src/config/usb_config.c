//Copyright 2021 Stratify Labs, See LICENSE.md for details

#include "usb_config.h"

int usb_set_attributes(const devfs_handle_t *handle, void *ctl) {
  #error "usb_set_attributes() not implemented"
  return 0;
}

int usb_set_action(const devfs_handle_t *handle, mcu_action_t *action) {
  #error "usb_set_action() not implemented"
  return 0;
}

void usb_write_endpoint(const devfs_handle_t *handle, u32 endpoint_num,
                        const void *src, u32 size) {
  #error "usb_write_endpoint() not implemented"
}

int usb_read_endpoint(const devfs_handle_t *handle, u32 endpoint_num,
                      void *dest) {
  #error "usb_read_endpoint() not implemented"
  return 0;
}
