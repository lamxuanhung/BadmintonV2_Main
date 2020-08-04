/*
 * Uart.c
 *
 *  Created on: Jul 22, 2019
 *      Author: XuanHung
 */

#include "Uart.h"
#include "Srv_RingBuf.h"

static uint8_t uart_rx_byte_temp = 0;
uint8_t Uart_Buffer_Rx[UART_BUFFER_SIZE];
uint8_t Uart_Buffer_Tx[UART_BUFFER_SIZE];

RingBuffer_t RingBuffer_Uart_Rx;
uint8_t Uart1_Trans_Complete = 0;
void Uart_Proc_Ini()
{
	if (HAL_UART_Receive_DMA(&huart1, &uart_rx_byte_temp, 1) != HAL_OK)
	{

	}
	Srv_RingBuf_Ini(&RingBuffer_Uart_Rx,Uart_Buffer_Rx,UART_BUFFER_SIZE);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		Srv_RingBuf_Push(&RingBuffer_Uart_Rx,&uart_rx_byte_temp,1);
	}
}

/* Retrieve data in Ring Buffer */
uint8_t Uart_ReceiveData(RingBuffer_t* pRingBuf,uint8_t* pData,uint16_t dataLength)
{
	uint8_t ret_val;
	ret_val = Srv_RingBuf_Peek(pRingBuf,pData,dataLength);
	return ret_val;
}

uint8_t Uart_SendData(RingBuffer_t* pRingBuf,uint8_t* pData,uint16_t dataLength)
{
	uint8_t ret_val = 0;
	Uart1_Trans_Complete = 0;
	if (HAL_UART_Transmit(&huart1,pData,dataLength,0xFFFF) == HAL_OK)
	{
		ret_val = 1;
	}
	return ret_val;
}

void Uart_SendString(uint8_t* pData,uint16_t dataLength)
{
	HAL_UART_Transmit(&huart1,pData,dataLength,0xFFFF);

}
