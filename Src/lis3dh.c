/**
  ******************************************************************************
  * File Name          : lis3dh.c
  * Description        : Plik ten zawiera deklaracje funkcji i zmiennych
  * 					 potrzebnych do zmiany konfiguracji akcelerometr�w LIS3DH
  * Created on		   : 15.01.2019
  * Author			   : Gracjan Fedoryniec
  ******************************************************************************
  *
  * COPYRIGHT(c) FEDOR
  *
  ******************************************************************************
  */


#include "lis3dh.h"
#include "i2c.h"
#include "gpio.h"



/**
* init_lis3dh - funkcja inicjuj�ca podstawowe parametry pomiarowe akcelerometr�w LIS3DH
*/
void init_lis3dh(void)
{
	// Setup configuration register for accelerometer

	uint8_t SetCtrl_Reg1 = SET_NORMAL_10BIT_100HZ; // setup Normal / low power mode (100 Hz) and Z, Y, X axis enable
	uint8_t SetCtrl_Reg4 = SET_2G; // +-2g
	HAL_I2C_Mem_Write(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_CTRL_REG1, 1, &SetCtrl_Reg1, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_CTRL_REG4, 1, &SetCtrl_Reg4, 1, 100);


}

/**
* init_lis3dh - funkcja umo�liwia zmian� prametr�w pomiarowych akcelerometr�w LIS3DH
*/
void setup_lis3dh(uint8_t SetCtrl_Reg1, uint8_t SetCtrl_Reg4)
{
	// Setup configuration register for accelerometer

	HAL_I2C_Mem_Write(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_CTRL_REG1, 1, &SetCtrl_Reg1, 1, 100); // setup Normal / low power mode (100 Hz) and Z, Y, X axis anable
	HAL_I2C_Mem_Write(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_CTRL_REG4, 1, &SetCtrl_Reg4, 1, 100); // setup Normal / low power mode (100 Hz) and Z, Y, X axis anable

}
