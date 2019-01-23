/**
  ******************************************************************************
  * File Name          : lis3dh.h
  * Description        : Plik ten zawiera makra adresów i rejestrów zdefiniowanych
  * 					 dla akcelerometrów LIS3DH
   * Created on		   : 15.01.2019
  * Author			   : Gracjan Fedoryniec
  ******************************************************************************
  *
  * COPYRIGHT(c) FEDOR
  *
  ******************************************************************************
  */

#ifndef LIS3DH_H_
#define LIS3DH_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "main.h"

/* Declaration Function ----------------------------------------------------- */
void init_lis3dh(void);
void setup_lis3dh(uint8_t SetCtrl_Reg1, uint8_t SetCtrl_Reg4);

// Device Address
#define LIS3DH_ADDRESS 				  0x18 // 0x19 jumper open  or 3V3 on SDO/SAO | 0x18 jumper close or GND on SDO/SAO

// Device Registers
#define LIS3DH_STATUS_REG_AUX         0x07
#define LIS3DH_OUT_ADC1_L             0x08
#define LIS3DH_OUT_ADC1_H             0x09
#define LIS3DH_OUT_ADC2_L             0x0A
#define LIS3DH_OUT_ADC2_H             0x0B
#define LIS3DH_OUT_ADC3_L             0x0C
#define LIS3DH_OUT_ADC3_H             0x0D
#define LIS3DH_INT_COUNTER_REG        0x0E
#define LIS3DH_WHO_AM_I               0x0F

#define LIS3DH_TEMP_CFG_REG           0x1F
#define LIS3DH_CTRL_REG1              0x20
#define LIS3DH_CTRL_REG2              0x21
#define LIS3DH_CTRL_REG3              0x22
#define LIS3DH_CTRL_REG4              0x23
#define LIS3DH_CTRL_REG5              0x24
#define LIS3DH_CTRL_REG6              0x25
#define LIS3DH_REFERENCE              0x26
#define LIS3DH_STATUS_REG2            0x27
#define LIS3DH_OUT_X_L                0x28
#define LIS3DH_OUT_X_H                0x29
#define LIS3DH_OUT_Y_L                0x2A
#define LIS3DH_OUT_Y_H                0x2B
#define LIS3DH_OUT_Z_L                0x2C
#define LIS3DH_OUT_Z_H                0x2D
#define LIS3DH_FIFO_CTRL_REG          0x2E
#define LIS3DH_FIFO_SRC_REG           0x2F
#define LIS3DH_INT1_CFG               0x30
#define LIS3DH_INT1_SRC               0x31
#define LIS3DH_INT1_THS               0x32
#define LIS3DH_INT1_DURATION          0x33

#define LIS3DH_CLICK_CFG              0x38
#define LIS3DH_CLICK_SRC              0x39
#define LIS3DH_CLICK_THS              0x3A
#define LIS3DH_TIME_LIMIT             0x3B
#define LIS3DH_TIME_LATENCY           0x3C
#define LIS3DH_TIME_WINDOW 			  0x3D

// Device setup CTRL_REG1
#define SET_NORMAL_10BIT_100HZ		  0X57
#define SET_2G		  				  0X00

#define SET_NORMAL_10BIT_50HZ		  0X47
//#define SET_2G		  				  0X00

#define SET_LPOWER_8BIT_100HZ		  0X5F
//#define SET_2G		  				  0X00

#define SET_LPOWER_8BIT_50HZ		  0X4F
//#define SET_2G		  				  0X00

#define SET_HRES_12BIT_100HZ		  0X57
#define SET_HRES_2G		  			  0X08

#define SET_HRES_12BIT_50HZ		  	  0X47
//#define SET_HRES_2G		  			  0X08

// ---------------------------------- //
//#define SET_NORMAL_10BIT_100HZ		  0X57
#define SET_4G		  				  0X10

#define SET_NORMAL_10BIT_50HZ		  0X47
//#define SET_4G		  				  0X10

#define SET_LPOWER_8BIT_100HZ		  0X5F
//#define SET_4G		  				  0X10

#define SET_LPOWER_8BIT_50HZ		  0X4F
//#define SET_4G		  				  0X10

#define SET_HRES_12BIT_100HZ		  0X57
#define SET_HRES_4G		  			  0X18

#define SET_HRES_12BIT_50HZ		  	  0X47
//#define SET_HRES_4G	  				  0X18


#endif /* LIS3DH_H_ */
