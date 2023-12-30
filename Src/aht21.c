#include "aht21.h"
#include "main.h"
#include "i2cs.h"
void GetAHT21Data(float *humidity, float *temperature)
{
    I2c_Start();
    I2c_WrByte(AHT21_READ_CMD << 1);
    I2c_WrByte(0xAC);
    I2c_WrByte(0x33);
    I2c_WrByte(0x00);
    I2c_Stop();
		HAL_Delay(80);
    uint8_t data[6] = {0};	
    I2c_Start();
    I2c_WrByte((AHT21_READ_CMD << 1) | 1);
    for (int i = 0; i < 6; i++)
    {
			data[i] = I2c_RdByte();
    }
    I2c_Stop();
    *humidity = ((data[1] << 12) | (data[2] << 4) | (data[3] >> 4)) / 1048576.0;
    *temperature = ((((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5]) / 1048576.0 * 200) - 50;
}
