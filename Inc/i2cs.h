#ifndef __I2CS_H__
#define __I2CS_H__
#include "main.h"

#define DELAY_0_1US HAL_Delay(1);

#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOE
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOE

#define SCL_SET HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET);
#define SCL_CLR HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_RESET);
#define SCL_D_OUT                                  \
	GPIO_InitTypeDef GPIO_InitStruct_SCL_OUT = {0};      \
	GPIO_InitStruct_SCL_OUT.Pin = SCL_Pin;             \
	GPIO_InitStruct_SCL_OUT.Mode = GPIO_MODE_OUTPUT_PP;  \
	GPIO_InitStruct_SCL_OUT.Pull = GPIO_NOPULL;          \
	GPIO_InitStruct_SCL_OUT.Speed = GPIO_SPEED_FREQ_LOW; \
	HAL_GPIO_Init(SCL_GPIO_Port, &GPIO_InitStruct_SCL_OUT);
#define SDA_SET HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET);
#define SDA_CLR HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_RESET);
#define SDA_IN HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin)
#define SDA_D_OUT                                  \
	GPIO_InitTypeDef GPIO_InitStruct_SDA_OUT = {0};      \
	GPIO_InitStruct_SDA_OUT.Pin = SDA_Pin;             \
	GPIO_InitStruct_SDA_OUT.Mode = GPIO_MODE_OUTPUT_PP;  \
	GPIO_InitStruct_SDA_OUT.Pull = GPIO_NOPULL;          \
	GPIO_InitStruct_SDA_OUT.Speed = GPIO_SPEED_FREQ_LOW; \
	HAL_GPIO_Init(SDA_GPIO_Port, &GPIO_InitStruct_SDA_OUT);
#define SDA_D_IN                             \
	GPIO_InitTypeDef GPIO_InitStruct_SDA_IN = {0}; \
	GPIO_InitStruct_SDA_IN.Pin = SDA_Pin;        \
	GPIO_InitStruct_SDA_IN.Mode = GPIO_MODE_INPUT; \
	GPIO_InitStruct_SDA_IN.Pull = GPIO_NOPULL;     \
	HAL_GPIO_Init(SDA_GPIO_Port, &GPIO_InitStruct_SDA_IN);
	
void I2c_Start(void);
void I2c_Stop(void);
void I2c_WrByte(uint8_t dat);
uint8_t I2c_RdByte(void);
#endif
