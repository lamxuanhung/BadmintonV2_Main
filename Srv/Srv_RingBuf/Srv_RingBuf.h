#ifndef RINGBUFFER_H
#define RINGBUFFER_H



typedef struct {	
	uint16_t head;	// Read Out Indexrea
	uint16_t tail;	// Write In Index
	uint16_t size;
	uint16_t count;	
	uint8_t* pdata;
}RingBuffer_t;

#define	RINGBUFFER_ERROR	0x00
#define	RINGBUFFER_OK	0x01

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

void Srv_RingBuf_Ini(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t size);
uint8_t Srv_RingBuf_Peek(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t data_length);
uint8_t Srv_RingBuf_Push(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t data_length);
uint8_t Srv_RingBuf_Pop(RingBuffer_t* pRingBuf,uint8_t* pdata_u8,uint16_t data_length);
void Srv_RingBuf_Reset(RingBuffer_t* pRingBuf);
uint8_t Srv_RingBuf_Full(RingBuffer_t* pRingBuf);
uint8_t Srv_RingBuf_Empty(RingBuffer_t* pRingBuf);

#endif
 
