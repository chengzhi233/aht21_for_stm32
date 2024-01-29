# aht21_for_stm32  
基于奥松AHT21温湿度传感器开发的STM32（HAL）控制代码  
## 使用方法  
将aht21头文件及函数文件加入工程  
### 硬件读取  
修改宏定义AHT21_MODE为HARD  
并在主函数引用头文件
#### 读取温湿度  
```C
void GetAHT21Data(I2C_HandleTypeDef *hi2c,float *humidity, float *temperature);
//hi2c        I2C通道
//humidity    湿度
//temperature 温度
```    
#### 软复位
```C
void ResetAHT21(I2C_HandleTypeDef *hi2c);
//hi2c        I2C通道
```  
#### 初始化
```C
void StartAHT21(I2C_HandleTypeDef *hi2c);
//hi2c        I2C通道
```  
### 软件读取
修改宏定义AHT21_MODE为SOFT  
按照使用引脚修改SCL和SDA引脚
```c
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOE
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOE
```  
并在主函数引用头文件
#### 读取温湿度  
```C
void GetAHT21Data(float *humidity, float *temperature);
//humidity    湿度
//temperature 温度
```  
#### 软复位
```C
void ResetAHT21(void);
```  
#### 初始化
```C
void StartAHT21(void);
```  
## 未来计划 
- [x] HAL库硬件I2C支持  
- [x] 传感器软复位/初始化    