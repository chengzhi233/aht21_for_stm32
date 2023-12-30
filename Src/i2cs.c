#include "i2cs.h"
#include "main.h"
void I2c_Start(void)
{
    SDA_SET;
    SDA_D_OUT;
    SCL_SET;
    SCL_D_OUT;
    DELAY_0_1US;
    SDA_CLR;
    DELAY_0_1US;
    SCL_CLR;
}

void I2c_Stop(void)
{
    SDA_CLR;
    DELAY_0_1US;
    SCL_SET;
    DELAY_0_1US;
    SDA_SET;
    DELAY_0_1US;
}

void I2c_WrByte(uint8_t dat)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        if (dat & 0x80)
        {
            SDA_SET;
        }
        else
        {
            SDA_CLR;
        }
        DELAY_0_1US;
        SCL_SET;
        dat <<= 1;
        DELAY_0_1US;
        SCL_CLR;
    }
    SDA_SET;
    DELAY_0_1US;
    SCL_SET;
    DELAY_0_1US;
    SCL_CLR;
}

uint8_t I2c_RdByte(void)
{
    uint8_t dat, i;
    SDA_SET;
    SDA_D_IN;
    dat = 0;
    for (i = 0; i < 8; i++)
    {
        DELAY_0_1US;
        SCL_SET;
        DELAY_0_1US;
        dat <<= 1;
        if (SDA_IN)
            dat++;
        SCL_CLR;
    }
		SDA_D_OUT;
    SDA_CLR;
    DELAY_0_1US;
    SCL_SET;
    DELAY_0_1US;
    SCL_CLR;
    return (dat);
}
