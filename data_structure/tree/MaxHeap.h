//
// Created by Vigo Wong on 22/4/20.
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct HeapStruct *MaxHeap;


MaxHeap Init_MaxHeap(int MaxHeap);

int IsFull(MaxHeap H);

int IsEmpty(MaxHeap H);

void Insert(MaxHeap H, int data);

void PrintValue(MaxHeap H);

int HeapSize(MaxHeap H);

int DeleteMax(MaxHeap H);
