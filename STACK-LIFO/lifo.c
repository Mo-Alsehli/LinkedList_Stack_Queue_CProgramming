#include "lifo.h"
#include <stdio.h>

LIFO_STATUS Lifo_Init(LIFO_BUF_t *lifo_buf, unsigned int *buf, unsigned int length)
{
    if (buf == NULL)
        return LIFO_NULL;

    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;

    return LIFO_NO_ERROR;
}

LIFO_STATUS Lifo_Add_Item(LIFO_BUF_t *lifo_buf, unsigned int item)
{
    if (!lifo_buf->base || !lifo_buf->head)
    {
        return LIFO_NULL;
    }

    // if(lifo_buf -> head == (lifo_buf -> base) + (lifo_buf -> length * 4))
    if (lifo_buf->count == lifo_buf->length)
    {
        return LIFO_FULL;
    }

    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;

    printf("Item %d Pushed !!\n", item);

    return LIFO_NO_ERROR;
}

LIFO_STATUS Lifo_Pop_Item(LIFO_BUF_t *lifo_buf, unsigned int *item)
{
    if (!lifo_buf->base || !lifo_buf->head)
    {
        return LIFO_NULL;
    }

    if (lifo_buf->count == 0)
    {
        return LIFO_EMPTY;
    }

    lifo_buf->head--;
    *(item) = *(lifo_buf->head);
    lifo_buf->count--;

    return LIFO_NO_ERROR;
}

void Lifo_IsEmpty(LIFO_BUF_t *lifo_buf)
{
    if (lifo_buf->count == 0)
    {
        printf("Lifo Is Empty :)\n");
    }
    else
    {
        printf("Lifo Is Not Empty !!!\n");
    }
}

unsigned int Lifo_Top_Item(LIFO_BUF_t *lifo_buf)
{
    unsigned int *top = lifo_buf->base;
    int i = 0;

    while (i < lifo_buf->count - 1)
    {
        top++;
        i++;
    }

    return *top;
}