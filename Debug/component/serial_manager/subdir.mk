################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c component/serial_manager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/board" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/source" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/drivers" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/utilities" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/component/serial_manager" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/component/uart" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/component/lists" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/CMSIS" -I"/home/wardo/Documents/Documentos/diplomado/Diseno_con_microcontroladores/MCUXIDE_proyectos/SERIAL/Tarea_DAC/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


