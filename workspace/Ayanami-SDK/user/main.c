/**
 * main.c
 */
#include "ayanami_common/aya_common_headfile.h"

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
    ConfigureUART();
    int t_raw,h_raw;
    i2c_init(I2C_3);
    uint8_t tbuff[10],rbuff[10];

    tbuff[0]=0xac;
    tbuff[1]=0x33;
    tbuff[2]=0x00;
    i2c_write(I2C_3,0x38,tbuff,3);
    delay();


    delay();

    while (1)
    {
        delay();
        tbuff[0]=0xac;
        tbuff[1]=0x33;
        tbuff[2]=0x00;
        i2c_write(I2C_3,0x38,tbuff,3);
        delay();
        i2c_read(I2C_3,0x38,rbuff,6);
        h_raw=(rbuff[1] << 12) | (rbuff[2] << 4) | (rbuff[3] >> 4);
        t_raw=((rbuff[3] & 0x0F) << 16) | (rbuff[4] << 8) | rbuff[5];
        int temperature = (t_raw / 1048576.0) * 200.0 - 50.0;
        int humidity = h_raw / 1048576.0 * 100.0;

        UARTprintf("\nTemp=%d,Humi=%d",temperature,humidity);
        //UARTprintf("\n\n\n");
    }

    return 0;
}
