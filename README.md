# STEVAL-FCU001V1

Board Support package for Stratify OS v4 on the STEVAL-FCU001V1 evaluation board.

## Building

```sh
git clone https://github.com/StratifyLabs/STEVAL-FCU001V1
cd <NewProjectName>
cmake -P bootstrap.cmake
source profile.sh
cd cmake_arm
cmake .. -GNinja
ninja SDK/StratifyOS-newlib/install && ninja
```

## Programming the Board

These instructions use default public (non-secure) keys to sign the firmware. Use `sl --help=keys` for details on creating new keys.

**Install the Bootloader**

```sh
sl --prepareBootloader
<use SWD/JTAG or other bootloader to flash the bootloader>
```

**Install the OS**

The first line will install with debugging enabled. You can connect a UART receiver to `D1` to see the output at 115200,8,1,N.

```sh
sl --installDebugOs
sl --installOs
```

