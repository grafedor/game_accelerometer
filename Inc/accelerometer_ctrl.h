/**
  ******************************************************************************
  * File Name          : accelerometer_ctrl.h
  * Description        : Plik ten zawiera deklaracje funkcji i zmiennych porzebnych
  * 					 do obs³ugi akcelerometrów LIS3DH
   * Created on		   : 15.01.2019
  * Author			   : Gracjan Fedoryniec
  ******************************************************************************
  *
  * COPYRIGHT(c) FEDOR
  *
  ******************************************************************************
  */

#ifndef ACCELEROMETER_CTRL_H_
#define ACCELEROMETER_CTRL_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "main.h"
#include "lis3dh.h"

/* Variable ----------------------------------------------------------------- */
extern volatile uint8_t RxFromTerminal;			// bufor przechowuj¹cy dane odebrane z terminala

/* Declaration Function ----------------------------------------------------- */
void accelerometer_ctrl(void);
static inline void read_data_acc(uint8_t);


/* Define ------------------------------------------------------------------- */

#endif /* ACCELEROMETER_CTRL_H_ */
