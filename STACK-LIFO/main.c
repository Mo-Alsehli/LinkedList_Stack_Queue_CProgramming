#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

int buffer[5];

int main(void)
{
    int i, temp = 0;
    unsigned int length = 5;
    LIFO_BUF_t uart_lifo, I2C_lifo;
    // static allocation
    Lifo_Init(&uart_lifo, buffer, length);
    // Dynamic allocation.
    unsigned int *buffer2 = (unsigned int *)malloc(5 * sizeof(unsigned int));
    Lifo_Init(&I2C_lifo, buffer2, length);

    for (i = 0; i < 5; i++)
    {
        if (Lifo_Add_Item(&uart_lifo, i) == LIFO_NO_ERROR)
        {
            printf("UART Lifo Add: %d \n", i);
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (Lifo_Pop_Item(&uart_lifo, &temp) == LIFO_NO_ERROR)
        {
            printf("UART Lifo Pop: %d \n", temp);
        }
    }

    // getting the lifo top
    printf("The UART Lifo Top: %d\n", Lifo_Top_Item(&uart_lifo));
    // checking if lifo empty
    Lifo_IsEmpty(&uart_lifo);

    for (i = 0; i < 3; i++)
    {
        if (Lifo_Pop_Item(&uart_lifo, &temp) == LIFO_NO_ERROR)
        {
            printf("UART Lifo Pop: %d \n", temp);
        }
    }
    Lifo_IsEmpty(&uart_lifo);
}