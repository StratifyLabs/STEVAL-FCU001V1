
#ifndef CONFIG_H_
#define CONFIG_H_

#include <sos/arch.h>
#include <sos/debug.h>

#include "config/os_config.h"
#include "sl_config.h"

#define CONFIG_SYSTEM_MEMORY_SIZE (16 * 1024)
#define CONFIG_STDIO_BUFFER_SIZE 512

#define CONFIG_SYSTEM_CLOCK 84000000UL

#define CONFIG_DEBUG_FLAGS                                                     \
  (SOS_DEBUG_MESSAGE | SOS_DEBUG_SYS | SOS_DEBUG_DEVICE)

#define CONFIG_USB_RX_BUFFER_SIZE 512



#endif /* CONFIG_H_ */
