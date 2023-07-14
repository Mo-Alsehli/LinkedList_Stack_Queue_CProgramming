/*
LinkedList.h
Mohamed Magdi
12 JUL 2023
*/

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct SData
{
    int ID;
    char name[40];
    float height;
};

// OUR NODE
struct SLinkedList
{
    struct SData student;
    struct SLinkedList *PNextStudent;
};

void AddStudent();
int DeleteStudent();
void PrintStudents();
void DeleteAll();

#endif
