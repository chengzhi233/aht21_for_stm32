# aht21_for_stm32  
基于奥松AHT21温湿度传感器开发的STM32（HAL）控制代码  
## 使用方法  
将aht21及模拟i2c的头文件及函数文件加入工程  
配置i2cs.h文件
```c
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOE
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOE
```  
并在主函数引用头文件
### 读取温湿度  
```C
GetAHT21Data(float *humidity, float *temperature);
```  
## 未来计划 
- [ ] HAL库硬件I2C支持  
- [ ] 传感器软复位/初始化    