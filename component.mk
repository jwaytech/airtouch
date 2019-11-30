##
# Component Makefile
#

COMPONENT_ADD_INCLUDEDIRS := port/include airtouch-iot-device-sdk-embedded-C/include

COMPONENT_SRCDIRS := airtouch-iot-device-sdk-embedded-C/src port

# Check the submodule is initialised
COMPONENT_SUBMODULES := airtouch-iot-device-sdk-embedded-C