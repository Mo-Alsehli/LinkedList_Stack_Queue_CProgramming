/*
lifo.c
Mohamed Magdi
8 JUL 2023
*/

#ifndef _LIFO_H_
#define _LIFO_H_

// Type Definitions

typedef struct
{
    unsigned int length;
    unsigned int count;
    unsigned int *base;
    unsigned int *head;
} LIFO_BUF_t;

typedef enum
{
    LIFO_NO_ERROR,
    LIFO_FULL,
    LIFO_EMPTY,
    LIFO_NULL
} LIFO_STATUS;

// APIs
LIFO_STATUS Lifo_Add_Item(LIFO_BUF_t *lifo_buf, unsigned int item);
LIFO_STATUS Lifo_Pop_Item(LIFO_BUF_t *lifo_buf, unsigned int *item);
LIFO_STATUS Lifo_Init(LIFO_BUF_t *lifo_buf, unsigned int *buf, unsigned int length);
unsigned int Lifo_Top_Item(LIFO_BUF_t *lifo_buf);
void Lifo_IsEmpty(LIFO_BUF_t *lifo_buf);

#endif
