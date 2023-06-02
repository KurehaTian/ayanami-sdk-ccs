/**
 * main.c
 */
#include <ayanami_common/aya_common_base_head.h>
#include <ayanami_common/aya_common_driver_head.h>


void delay()
{
    volatile uint32_t ui32Loop;
    for (ui32Loop = 0; ui32Loop < 800000; ui32Loop++)
    {
    }
}
void ConfigureUART(void)
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable UART0
    //
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Configure GPIO Pins for UART mode.
    //
    MAP_GPIOPinConfigure(GPIO_PA0_U0RX);
    MAP_GPIOPinConfigure(GPIO_PA1_U0TX);
    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 115200, 16000000);
}

int main(void)
{
    MAP_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);
    ConfigureUART();
    MAP_FPULazyStackingEnable();
    timer_loop_init(timer_0,900000);
    timer_loop_init(timer_1,900000);
    timer_loop_init(timer_2,900000);
    timer_loop_init(timer_3,900000);
    timer_loop_init(timer_4,900000);
    timer_loop_init(timer_5,900000);

    UARTprintf("Init Done.\n");
    while (1)
    {
        //UARTprintf("In loop.\n");
        delay();
    }
    return 0;
}
