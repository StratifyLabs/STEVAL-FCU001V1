//Copyright 2021 Stratify Labs, See LICENSE.md for details

#include <sos/arch.h>

#include <sos/fs/appfs.h>
#include <sos/dev/appfs.h>
#include <device/appfs.h>
#include <device/mem.h>
#include <mcu/flash.h>

#include "fs_config.h"
#include "config.h"


//configure the application filesystem to use the extra flash and RAM
//available in the system
#define APPFS_RAM_PAGES 32
u32 ram_usage_table[APPFS_RAM_USAGE_WORDS(APPFS_RAM_PAGES)] MCU_SYS_MEM;

const devfs_device_t flash0
  = DEVFS_DEVICE("flash0", mcu_flash, 0, 0, 0, 0666, SYSFS_ROOT, S_IFBLK);

#define FLASH0_PAGE_SIZE (16*1024)
//first 2 pages are for the bootloader
#define FLASH0_ADDRESS (0x08000000 + 2*FLASH0_PAGE_SIZE)
#define FLASH0_PAGE_COUNT 2
#define FLASH0_SIZE (FLASH0_PAGE_SIZE * FLASH0_PAGE_COUNT)

#define FLASH1_PAGE_SIZE (64*1024)
#define FLASH1_ADDRESS (FLASH0_ADDRESS + FLASH0_SIZE)
#define FLASH1_PAGE_COUNT 1
#define FLASH1_SIZE (FLASH1_PAGE_SIZE * FLASH1_PAGE_COUNT)

const appfs_mem_config_t appfs_mem_config = {
  .usage_size = sizeof(ram_usage_table),
  .usage = ram_usage_table,
  .flash_driver = &flash0,
  .section_count = 3,
  .sections = {
    {.o_flags = MEM_FLAG_IS_FLASH,
     .page_count = FLASH0_PAGE_COUNT,
     .page_size = FLASH0_PAGE_SIZE,
     .address = FLASH0_ADDRESS},
    {.o_flags = MEM_FLAG_IS_FLASH,
     .page_count = FLASH1_PAGE_COUNT,
     .page_size = FLASH1_PAGE_SIZE,
     .address = FLASH1_ADDRESS},
    {.o_flags = MEM_FLAG_IS_RAM,
     .page_count = APPFS_RAM_PAGES,
     .page_size = MCU_RAM_PAGE_SIZE,
     .address = 0x20000000 + CONFIG_SYSTEM_MEMORY_SIZE}}};

const devfs_device_t mem0 = DEVFS_DEVICE(
  "mem0",
  appfs_mem,
  0,
  &appfs_mem_config,
  0,
  0666,
  SYSFS_ROOT,
  S_IFBLK);

const sysfs_t sysfs_list[] = {
  APPFS_MOUNT(
    "/app",
    &mem0,
    0777,
    SYSFS_ROOT), // the folder for ram/flash applications
  DEVFS_MOUNT("/dev", devfs_list, 0777, SYSFS_ROOT), // the list of devices
  SYSFS_MOUNT(
    "/",
    sysfs_list,
    0777,
    SYSFS_ROOT), // the root filesystem (must be last)
  SYSFS_TERMINATOR};
