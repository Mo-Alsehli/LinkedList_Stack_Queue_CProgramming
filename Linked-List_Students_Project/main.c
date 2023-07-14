#include "linkedList.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char temp_text[40];
    while (1)
    {
        printf("\n===============================\n");
        printf("Choose One Of The Following Options: \n");
        printf("\t 1. Add Student\n");
        printf("\t 2. Delete Student\n");
        printf("\t 3. View Students\n");
        printf("\t 4.Delete All\n");
        printf("Enter Option Number: ");
        gets(temp_text);
        printf("\n===============================\n");
        switch (atoi(temp_text))
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            PrintStudents();
            break;
        case 4:
            DeleteAll();
            break;
        default:
            printf("Wrong Option!!!\n");
            break;
        }
    }
    return 0;
}