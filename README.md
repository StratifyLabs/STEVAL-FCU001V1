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

The board is not designed to be power with the USB cable alone. You must connect a Li-ion battery (or a 4V supply) to the battery connector. If you don't, you will notice a lot of spurious resets.

These instructions use default public (non-secure) keys to sign the firmware. Use `sl --help=keys` for details on creating new keys.

**Install the Bootloader**

```sh
<use SWD/JTAG or other bootloader to flash the bootloader>
```

**Install the OS**

The first line will install with debugging enabled. You can connect a UART receiver to `P7.4` to see the output at 115200,8,1,N.

```sh
sl os.install:build=debug
sl os.install
```

**Running Hello World**

```sh
sl app.install:path=apps/HelloWorld,run,terminal
```

