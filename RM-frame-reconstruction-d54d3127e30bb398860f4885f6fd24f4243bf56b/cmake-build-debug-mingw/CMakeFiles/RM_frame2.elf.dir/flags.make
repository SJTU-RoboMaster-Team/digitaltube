# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# compile ASM with C:/Users/92304/Documents/Study/gcc-arm-none-eabi-9-2020-q2-update-win32/bin/arm-none-eabi-gcc.exe
# compile C with C:/Users/92304/Documents/Study/gcc-arm-none-eabi-9-2020-q2-update-win32/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/Users/92304/Documents/Study/gcc-arm-none-eabi-9-2020-q2-update-win32/bin/arm-none-eabi-g++.exe
ASM_FLAGS = -g  

ASM_DEFINES = -DSTM32F427xx -DUSE_HAL_DRIVER -D__packed=__attribute__((__packed__)) -D__weak=__attribute__((weak))

ASM_INCLUDES = -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BoardConfiguration -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\UpperTasks\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BasicComponents\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\AdditionalFunctions\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BSP\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Additional\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Middleware\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Multimedia\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Lib 

C_FLAGS = -mcpu=cortex-m4  -mthumb -mthumb-interwork -ffunction-sections -fdata-sections     -g -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs -std=gnu99 -g  

C_DEFINES = -DSTM32F427xx -DUSE_HAL_DRIVER -D__packed=__attribute__((__packed__)) -D__weak=__attribute__((weak))

C_INCLUDES = -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BoardConfiguration -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\UpperTasks\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BasicComponents\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\AdditionalFunctions\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BSP\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Additional\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Middleware\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Multimedia\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Lib 

CXX_FLAGS = -mcpu=cortex-m4  -mthumb -mthumb-interwork -ffunction-sections -fdata-sections     -g -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs -std=c++11 -g   -std=gnu++11

CXX_DEFINES = -DSTM32F427xx -DUSE_HAL_DRIVER -D__packed=__attribute__((__packed__)) -D__weak=__attribute__((weak))

CXX_INCLUDES = -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Drivers\CMSIS\Include -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BoardConfiguration -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\UpperTasks\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BasicComponents\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\AdditionalFunctions\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\BSP\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Additional\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Middleware\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Multimedia\Inc -IC:\Users\92304\Documents\Study\SCHOOL_FRAME\RM-frame-reconstruction-d54d3127e30bb398860f4885f6fd24f4243bf56b\Lib 

