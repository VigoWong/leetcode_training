//
// Created by Vigo Wong on 22/4/20.
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct HeapStruct *MinHeap;


MinHeap Init_MinHeap(int MaxSize);

int IsFull(MinHeap H);

int IsEmpty(MinHeap H);

void Insert(MinHeap H, int data);

void Delete(MinHeap H);

void BuildMinHeap(MinHeap H, int N);

void PrintValue(MinHeap H);