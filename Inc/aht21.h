#ifndef __AHT21_H__
#define __AHT21_H__
#include "main.h"
#include "i2cs.h"

#define AHT21_READ_CMD 0x38

void GetAHT21Data(float *humidity,float *temperature);

#endif 
