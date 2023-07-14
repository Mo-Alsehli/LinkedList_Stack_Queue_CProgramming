#include "linkedList.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

// Initializing First Node1
struct SLinkedList *gpFirstStudent = NULL;

void AddStudent()
{
    char temp[40];
    struct SLinkedList *pNewStudent;
    struct SLinkedList *pLastStudent;
    if (gpFirstStudent == NULL)
    {
        pNewStudent = (struct SLinkedList *)malloc(sizeof(struct SLinkedList));
        gpFirstStudent = pNewStudent;
    }
    else
    {
        pLastStudent = gpFirstStudent;
        while (pLastStudent->PNextStudent)
        {
            pLastStudent = pLastStudent->PNextStudent;
        }
        pNewStudent = (struct SlinkedList *)malloc(sizeof(struct SLinkedList));
        pLastStudent->PNextStudent = pNewStudent;
    }

    printf("Enter The ID: ");
    gets(temp);
    pNewStudent->student.ID = atoi(temp);

    printf("Enter The Name: ");
    gets(pNewStudent->student.name);

    printf("Enter The Height: ");
    gets(temp);
    pNewStudent->student.height = atof(temp);

    pNewStudent->PNextStudent = NULL;
}

int DeleteStudent()
{
    char temp[40];
    unsigned int selected_id;
    printf("\n Please Enter An ID To Be Deleted: ");
    gets(temp);
    selected_id = atoi(temp);

    struct SLinkedList *pPrevStudent = NULL;
    struct SLinkedList *pSelectedStudent = gpFirstStudent;

    while (pSelectedStudent)
    {
        if (pSelectedStudent->student.ID == selected_id)
        {
            if (pPrevStudent)
            {
                pPrevStudent->PNextStudent = pSelectedStudent->PNextStudent;
            }
            else
            {
                gpFirstStudent = gpFirstStudent->PNextStudent;
            }
            free(pSelectedStudent);
            return 1;
        }
        pPrevStudent = pSelectedStudent;
        pSelectedStudent = pSelectedStudent->PNextStudent;
    }
    printf("\n Cannot Find Student ID.\n");
    return 0;
}

void PrintStudents()
{
    struct SLinkedList *pCurrStudent = gpFirstStudent;
    unsigned int count = 0;

    if (!pCurrStudent)
    {
        printf("\nEmpty List....:(!!!");
    }
    else
    {
        while (pCurrStudent)
        {
            printf("\n Record Number: %d\n", count + 1);
            printf("\n\t ID: %d", pCurrStudent->student.ID);
            printf("\n\t Name: %s", pCurrStudent->student.name);
            printf("\n\t height: %.2f", pCurrStudent->student.height);
            printf("\n=======================\n");

            pCurrStudent = pCurrStudent->PNextStudent;
            count++;
        }
    }
}
void DeleteAll()
{
    struct SLinkedList *pCurrStudent = gpFirstStudent;

    if (!pCurrStudent)
    {
        printf("\nEmpty List....:(!!!");
    }
    else
    {
        while (pCurrStudent)
        {
            struct SLinkedList *pTempStudent = pCurrStudent;
            pCurrStudent = pCurrStudent->PNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }
}
