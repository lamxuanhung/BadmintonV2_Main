#ifndef UART_PUB_H
#define UART_PUB_H

#include "MCU.h"
#include <stdio.h>
#include <string.h>
#include "Srv_RingBuf.h"


#define UART_BUFFER_SIZE	128

typedef enum 
{
	UART_FREE 			= 0,
	UART_TRANSMIT 	= 1,
	UART_RECEIVE 		= 2
}UART_Status_e;

void UART_Tx_Proc_Ini(void);
void UART_Rx_Proc_Ini(void);
void MX_UART_DMA_Init(void);

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart2_rx;

extern RingBuffer_t Uart_RingBuffer;

typedef struct
{
	UART_HandleTypeDef* p_huart;
	uint8_t* p_TxBuffer;
	uint8_t* p_RxBuffer;
	RingBuffer_t* p_RingBuffer;
	uint8_t flg_TxComplete;
}Uart_Control_Block_t;

/* Private function prototypes -----------------------------------------------*/
void Uart_Proc_Ini();
uint8_t Uart_ReceiveData(RingBuffer_t* pRingBuf,uint8_t* pData,uint16_t DataLength);
uint8_t Uart_SendData(RingBuffer_t* pRingBuf,uint8_t* pData,uint16_t dataLength);
void Uart_SendString(uint8_t* pData,uint16_t dataLength);
#endif

