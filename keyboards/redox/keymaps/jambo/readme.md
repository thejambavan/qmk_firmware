# Jambo's redox UK keymap with lots of timed keys

Build process

## Import JSON

qmk json2c ~/jambo.json > keymap.c

## Flash Caterina bootloader

Pro Micro clones didn't have a usable DFU or Caterina bootloader, and I didn't want to use the arduino IDE to flash them. I had to do this for the uC in both halves of the keyboard.

```
~/git/Caterina-Bootloader/Built Firmwares master$ avrdude -c buspirate -P /dev/ttyUSB0 -p m32u4 -v

avrdude: Version 6.3-20171130
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/etc/avrdude.conf"
         User configuration file is "/home/sethp/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/ttyUSB0
         Using Programmer              : buspirate
         AVR Part                      : ATmega32U4
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PA0
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    20     4    0 no       1024    4      0  9000  9000 0x00 0x00
           flash         65     6   128    0 yes     32768  128    256  4500  4500 0x00 0x00
           lfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           lock           0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : BusPirate
         Description     : The Bus Pirate

Attempting to initiate BusPirate binary mode...
BusPirate binmode version: 1
BusPirate SPI version: 1
avrdude: Paged flash write enabled.
AVR Extended Commands not found.
avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.09s

avrdude: Device signature = 0x1e9587 (probably m32u4)
avrdude: safemode: lfuse reads as FF
avrdude: safemode: hfuse reads as D8
avrdude: safemode: efuse reads as FD

avrdude: safemode: lfuse reads as FF
avrdude: safemode: hfuse reads as D8
avrdude: safemode: efuse reads as FD
avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)
BusPirate is back in the text mode

avrdude done.  Thank you.
```

## Flash QMK using the built-in tools

Since I've used `EE_HANDS`, I can plug the USB into either half and the other half will be the i2c slave.

Left hand
```
sethp@graphene:~/git/qmk-redox-jambo master$ make redox:jambo:avrdude-split-left
Making redox/rev1/base with keymap jambo and target avrdude-split-left

avr-gcc (GCC) 5.4.0
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text	   data	    bss	    dec	    hex	filename
      0	  25240	      0	  25240	   6298	redox_rev1_base_jambo.hex

Compiling: quantum/command.c                                                                        [OK]
Linking: .build/redox_rev1_base_jambo.elf                                                           [OK]
Creating load file for flashing: .build/redox_rev1_base_jambo.hex                                   [OK]
Copying redox_rev1_base_jambo.hex to qmk_firmware folder                                            [OK]
Checking file size of redox_rev1_base_jambo.hex                                                     [OK]
 * The firmware size is fine - 25240/28672 (88%, 3432 bytes free)
Waiting for USB serial port - reset your controller now (Ctrl+C to cancel).........................................................................................................................................................................................
Device /dev/ttyACM0 has appeared; assuming it is the controller.
Waiting for /dev/ttyACM0 to become writable.

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9587 (probably m32u4)
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file ".build/redox_rev1_base_jambo.hex"
avrdude: input file .build/redox_rev1_base_jambo.hex auto detected as Intel Hex
avrdude: writing flash (25240 bytes):

Writing | ################################################## | 100% 1.95s

avrdude: 25240 bytes of flash written
avrdude: verifying flash memory against .build/redox_rev1_base_jambo.hex:
avrdude: load data flash data from input file .build/redox_rev1_base_jambo.hex:
avrdude: input file .build/redox_rev1_base_jambo.hex auto detected as Intel Hex
avrdude: input file .build/redox_rev1_base_jambo.hex contains 25240 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.19s

avrdude: verifying ...
avrdude: 25240 bytes of flash verified
avrdude: reading input file "quantum/split_common/eeprom-lefthand.eep"
avrdude: input file quantum/split_common/eeprom-lefthand.eep auto detected as Intel Hex
avrdude: writing eeprom (15 bytes):

Writing | ################################################## | 100% 0.05s

avrdude: 15 bytes of eeprom written
avrdude: verifying eeprom memory against quantum/split_common/eeprom-lefthand.eep:
avrdude: load data eeprom data from input file quantum/split_common/eeprom-lefthand.eep:
avrdude: input file quantum/split_common/eeprom-lefthand.eep auto detected as Intel Hex
avrdude: input file quantum/split_common/eeprom-lefthand.eep contains 15 bytes
avrdude: reading on-chip eeprom data:

Reading | ################################################## | 100% 0.00s

avrdude: verifying ...
avrdude: 15 bytes of eeprom verified

avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.
```

Right hand
```
$ make redox:jambo:avrdude-split-right
Making redox/rev1/base with keymap jambo and target avrdude-split-right

avr-gcc (GCC) 5.4.0
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text	   data	    bss	    dec	    hex	filename
      0	  25240	      0	  25240	   6298	redox_rev1_base_jambo.hex

Compiling: quantum/command.c                                                                        [OK]
Linking: .build/redox_rev1_base_jambo.elf                                                           [OK]
Creating load file for flashing: .build/redox_rev1_base_jambo.hex                                   [OK]
Copying redox_rev1_base_jambo.hex to qmk_firmware folder                                            [OK]
Checking file size of redox_rev1_base_jambo.hex                                                     [OK]
 * The firmware size is fine - 25240/28672 (88%, 3432 bytes free)
Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)....
Device /dev/ttyACM0 has appeared; assuming it is the controller.
Waiting for /dev/ttyACM0 to become writable.

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9587 (probably m32u4)
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file ".build/redox_rev1_base_jambo.hex"
avrdude: input file .build/redox_rev1_base_jambo.hex auto detected as Intel Hex
avrdude: writing flash (25240 bytes):

Writing | ################################################## | 100% 1.94s

avrdude: 25240 bytes of flash written
avrdude: verifying flash memory against .build/redox_rev1_base_jambo.hex:
avrdude: load data flash data from input file .build/redox_rev1_base_jambo.hex:
avrdude: input file .build/redox_rev1_base_jambo.hex auto detected as Intel Hex
avrdude: input file .build/redox_rev1_base_jambo.hex contains 25240 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.22s

avrdude: verifying ...
avrdude: 25240 bytes of flash verified
avrdude: reading input file "quantum/split_common/eeprom-righthand.eep"
avrdude: input file quantum/split_common/eeprom-righthand.eep auto detected as Intel Hex
avrdude: writing eeprom (15 bytes):

Writing | ################################################## | 100% 0.05s

avrdude: 15 bytes of eeprom written
avrdude: verifying eeprom memory against quantum/split_common/eeprom-righthand.eep:
avrdude: load data eeprom data from input file quantum/split_common/eeprom-righthand.eep:
avrdude: input file quantum/split_common/eeprom-righthand.eep auto detected as Intel Hex
avrdude: input file quantum/split_common/eeprom-righthand.eep contains 15 bytes
avrdude: reading on-chip eeprom data:

Reading | ################################################## | 100% 0.01s

avrdude: verifying ...
avrdude: 15 bytes of eeprom verified

avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.
```
