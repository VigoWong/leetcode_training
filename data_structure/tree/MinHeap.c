
#include "MinHeap.h"

#define MinData 100//哨兵元素的值
struct HeapStruct {
    int *p;
    int size;
    int capacity;
};


MinHeap Init_MinHeap(int MaxSize) {
    MinHeap h = malloc(sizeof(struct HeapStruct));
    assert(h != NULL);
    h->capacity = MaxSize;
    h->size = 0;
    h->p = calloc(MaxSize, sizeof(int)  );
    return h;
}

int IsFull(MinHeap H) {
    return (H->size == H->capacity);
}

int IsEmpty(MinHeap H) {
    return (H->size == 0);
}

void Insert(MinHeap H, int data) {
    if (IsFull(H)) return;
    int i;
    for (i = ++H->size; H->p[i] < data || i == 0; i /= 2) {
        H->p[i] = H->p[i / 2];
    }
    H->p[i] = data;
}

void Delete(MinHeap H) {
    if (H == NULL)return;
    else {
        free(H->p);
        free(H);
    }
}

void BuildMinHeap(MinHeap H, int N) {

}

void PrintValue(MinHeap H) {
    assert(H != NULL);
    for (int i = 0; i < H->size; H++) {
        printf("%d ", H->p[i]);
    }
}

