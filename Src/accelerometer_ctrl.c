/**
  ******************************************************************************
  * File Name          : accelerometer_ctrl.c
  * Description        : Plik ten zawiera funkcje i zmienne potrzebne do obs�ugi
  * 					 odczytu/zapsu danych z akcelerometr�w i komputerea oraz
  * 					 odpowiada za zarz�dzanie przep�ywem danych w programie
  * Created on		   : 15.01.2019
  * Author			   : Gracjan Fedoryniec
  ******************************************************************************
  *
  * COPYRIGHT(c) FEDOR
  *
  ******************************************************************************
  */

#include "accelerometer_ctrl.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"


// zmienne globalne
volatile uint8_t RxFromTerminal = 1;						// bufor przechowuj�cy dane odebrane z terminala
uint8_t sprinf_buf[100]; 						// bufor przechowujacy wysylana wiadomosc do terminala
uint16_t size = 0;								// zmienna zawieraj�ca obliczon� przez funkcj� sprintf() dlugosc slowa



/**
* accelerometer_ctrl - jest to g�owna funkcja, kt�ra zarz�dza przep�ywem wszystkim danych w programie
* oraz umo�liwia u�ytkownikowi wyb�r akcelerometru z jakiego maj� zostac odczytane dane
* i zmian� paramter�w odczytywanych danych
*/
void accelerometer_ctrl(void){
	// Ustawienie parametr�w pomiarowych akcelerometr�w

	static uint8_t SetResolution = 0;		// SetResolution = 0 -> 16 bit without 8-LSB (small precision) or SetResolution = 1 -> 16bit high_percision


	if(RxFromTerminal == 1)
	{
		SetResolution = 0;
		// Wywo�anie funkcji realizuj�cej odczyt danych z akcelerometr�w + wys�anie do terminala
		read_data_acc(SetResolution);
	}
	else if(RxFromTerminal == 2)
	{
		SetResolution = 1;
		// Wywo�anie funkcji realizuj�cej odczyt danych z akcelerometr�w + wys�anie do terminala
		read_data_acc(SetResolution);
	}
	else{ // Komunikat o bledzie
		// Wyslanie do terminala
		size = sprintf((char*)sprinf_buf, "\r\n, %i, Error command. Range or command not exist!!!", RxFromTerminal);
		HAL_UART_Transmit_IT(&huart2, sprinf_buf, size);
	}

}
/**
* read_data_acc - function read data from accelerometer and send data to the terminal on computer
* inline - funkcja nie bedzie marnowa�a czasu na skok do wywo�ania funkcji(zostanie rozwini�ta jako makro)
*/
inline void read_data_acc(uint8_t SetResolution){
	int16_t x = 0;				// zmienna przechowuj�ca poprawnie przekonwertowan� dan� z akcelerometru z osi x - znak +/-
	int16_t y = 0;				// zmienna przechowuj�ca poprawnie przekonwertowan� dan� z akcelerometru z osi y - znak +/-
	int16_t z = 0;				// zmienna przechowuj�ca poprawnie przekonwertowan� dan� z akcelerometru z osi z - znak +/-


	static uint8_t out_h = 0;	// zmienna przechowuj�ca dane 8bit MSB z akcelerometru
	static uint8_t out_l = 0;	// zmienna przechowuj�ca dane 8bit LSB z akcelerometru

	if(SetResolution == 0){
		// Odczyt danych z akcelerometr�w
		HAL_I2C_Mem_Read(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_OUT_X_H, 1, &out_h, 1, 100); //get value for x_axis
		x |= out_h << 8; // przekszta�cenie 8 bitowej danej na 16 bitow� zgodnie z rozdzelczo�ci� akcelerometru
		HAL_I2C_Mem_Read(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_OUT_Y_H, 1, &out_h, 1, 100); //get value for y_axis
		y |= out_h << 8; // przekszta�cenie 8 bitowej danej na 16 bitow� zgodnie z rozdzelczo�ci� akcelerometru
		HAL_I2C_Mem_Read(&hi2c1, LIS3DH_ADDRESS << 1, LIS3DH_OUT_Z_H, 1, &out_h, 1, 100); //get value for z_axis
		z |= out_h << 8; // przekszta�cenie 8 bitowej danej na 16 bitow� zgodnie z rozdzelczo�ci� akcelerometru

	}
	else if(SetResolution == 1){
		// Odczyt danych z akcelerometr�w
		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_X_H, 1, &out_h, 1, 100); //get value for x_axis
		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_X_L, 1, &out_l, 1, 100); //get value for x_axis
		x = out_h << 8; // shift 8 bit to the MSB in x [-][-][-][-][-][-][-][-] | [][][][][][][][]
		x |= out_l; // write 8 bit to the LSB in x [][][][][][][][] | [-][-][-][-][-][-][-][-]

		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_Y_H, 1, &out_h, 1, 100); //get value for y_axis
		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_Y_L, 1, &out_l, 1, 100); //get value for y_axis
		y = out_h << 8; // shift 8 bit to the MSB in x [-][-][-][-][-][-][-][-] | [][][][][][][][]
		y |= out_l; // write 8 bit to the LSB in x [][][][][][][][] | [-][-][-][-][-][-][-][-]

		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_Z_H, 1, &out_h, 1, 100); //get value for z_axis
		HAL_I2C_Mem_Read(&hi2c1,LIS3DH_ADDRESS << 1, LIS3DH_OUT_Z_L, 1, &out_l, 1, 100); //get value for z_axis
		z = out_h << 8; // shift 8 bit to the MSB in x [-][-][-][-][-][-][-][-] | [][][][][][][][]
		z |= out_l; // write 8 bit to the LSB in x [][][][][][][][] | [-][-][-][-][-][-][-][-]


	}
	// Wyslanie do terminala
	size = sprintf((char*)sprinf_buf, "%i %i %i\r\n", x, y, z);
	HAL_UART_Transmit_IT(&huart2, sprinf_buf, size);
}


/* Obs�uga przerwania - odbi�r danych -------------------*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// wykonane dopiero gdy bedzie przerwanie, gdy recive odbierze ca�y bajt

	// UART2 - odbi�r danych z TERMINAL
	if(huart -> Instance == USART2)
	{
		HAL_UART_Receive_IT(&huart2, &RxFromTerminal, 1); // ponowne w��czenie przerwania na odbi�r danych - nas�uchiwanie na odbi�r danych z terminala
	}

}
