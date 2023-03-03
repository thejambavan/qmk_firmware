# MCU name

# Pro Micro
MCU = atmega32u4

#	MCU = MKL26Z64
#	MCU = MK20DX256
# This MCU is not in the main CHIBIOS repo but in the CHIBIOS_CONTRIB repo.
USE_CHIBIOS_CONTRIB = yes

# Pro Micro build
 BOOTLOADER = caterina

# Teensy/Teensy LC
#BOOTLOADER = halfkay

# TODO: C3 Mini+IO extender
#BOOTLOADER = halfkay

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.

SPLIT_KEYBOARD = yes

#DEFAULT_FOLDER = redox/rev1/base
DEFAULT_FOLDER = redox/jambo3/base
#DEFAULT_FOLDER = redox/teensy32/base

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
