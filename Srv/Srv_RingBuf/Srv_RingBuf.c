#include "stm32f0xx_hal.h"
#include "Srv_RingBuf.h"
#include <string.h>

void Srv_RingBuf_Ini(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t size){
	pRingBuf->head = 0;	// Get from HEAD
	pRingBuf->tail = 0;	// Insert to TAIL
	pRingBuf->count = 0;
	pRingBuf->size = size;
	pRingBuf->pdata = pdata_u8;
}

/*
 *
 *
 * */

uint8_t Srv_RingBuf_Peek(RingBuffer_t* pRingBuf,uint8_t* data_u8,uint16_t data_length)
{
	uint16_t counter;
	if(pRingBuf->count == 0)
	{
		return RINGBUFFER_ERROR;
	}
	else if (data_length >= pRingBuf->size){
		return RINGBUFFER_ERROR;
	}
	else 
	{
		for(counter = 0 ;counter<data_length; counter++)
		{
			data_u8[counter] = pRingBuf->pdata[(pRingBuf->head + counter) % pRingBuf->size];
		}
		return RINGBUFFER_OK;
	}
}

uint8_t Srv_RingBuf_Push(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t data_length)
{
	uint16_t counter;
	if (data_length == 0)
	{
		return RINGBUFFER_ERROR;
	}	

	/* Check data input have too much */
	else if((pRingBuf->count + data_length) >= pRingBuf->size)	// count from zero, if ringbuf->count == ringbuf->size => FULL
	{
		return RINGBUFFER_ERROR;
	}
	/* Push data into the buffer */
	else
	{
		for(counter = 0 ;counter<data_length; counter++)
		{
			pRingBuf->pdata[pRingBuf->tail+counter] = pdata_u8[counter];
			pRingBuf->tail++;
			if(pRingBuf->tail >= pRingBuf->size)
			{
				pRingBuf->tail = 0;
			}
		}		
		pRingBuf->count = pRingBuf->count + data_length;
		return RINGBUFFER_OK;
	}	
}

		
uint8_t Srv_RingBuf_Pop(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t data_length)
{
	uint16_t counter;
	if (data_length == 0)
	{
		return RINGBUFFER_ERROR;
	}
	/* Check data output have too less */
	else if(pRingBuf->count < data_length)
	{
		return RINGBUFFER_ERROR;
	}
	else 
	{
		for(counter = 0 ;counter<data_length; counter++)
		{
			pdata_u8[counter] = pRingBuf->pdata[pRingBuf->head + counter];
			pRingBuf->head ++;
			if(pRingBuf->head >= pRingBuf->size)
			{
				pRingBuf->head = 0;
			}			
		}
		pRingBuf->count = pRingBuf->count - data_length;
		return RINGBUFFER_OK;
	}
}

// Clear Ring buffer data
void Srv_RingBuf_Reset(RingBuffer_t* pRingBuf)
{
	uint16_t counter;
	pRingBuf->head = 0;
	pRingBuf->tail = 0;
	pRingBuf->count = 0;
	for (counter = 0; counter<pRingBuf->size; counter++)
	{
		pRingBuf->pdata[counter] = 0;
	}
}

uint8_t Srv_RingBuf_Full(RingBuffer_t* pRingBuf)
{
	if (pRingBuf->tail + 1 == pRingBuf->head)
	{
		pRingBuf->count = pRingBuf->size;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

uint8_t Srv_RingBuf_Empty(RingBuffer_t* pRingBuf)
{
	if (pRingBuf->head == pRingBuf->tail)
	{
		pRingBuf->count = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
