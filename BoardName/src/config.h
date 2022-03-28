
#ifndef CONFIG_H_
#define CONFIG_H_

#include <sos/arch.h>
#include <sos/debug.h>

#include "config/os_config.h"
#include "sl_config.h"

#define CONFIG_SYSTEM_MEMORY_SIZE (32 * 1024)
#define CONFIG_STDIO_BUFFER_SIZE 512

#error "This value must match the system clock in Hz"
#define CONFIG_SYSTEM_CLOCK 100000000

#define CONFIG_DEBUG_FLAGS                                                     \
  (SOS_DEBUG_MESSAGE | SOS_DEBUG_SYS | SOS_DEBUG_DEVICE)



#endif /* CONFIG_H_ */
