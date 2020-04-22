
#include "MaxHeap.h"

#define MinData 100//哨兵元素的值
struct HeapStruct {
    int *p;
    int size;
    int capacity;
};


MaxHeap Init_MaxHeap(int MaxSize) {
    MaxHeap h = malloc(sizeof(struct HeapStruct));
    assert(h != NULL);
    h->capacity = MaxSize;
    h->size = 0;
    h->p = calloc(MaxSize, sizeof(int));
    return h;
}

int IsFull(MaxHeap H) {
    return (H->size == H->capacity);
}

int IsEmpty(MaxHeap H) {
    return (H->size == 0);
}

void Insert(MaxHeap H, int data) {
    if (IsFull(H)) return;
    int i;
    for (i = H->size++; H->p[(i - 1) / 2] < data && i != 0; i = (i - 1) / 2) {
        H->p[i] = H->p[(i - 1) / 2];
    }
    H->p[i] = data;
}

int DeleteMax(MaxHeap H) {
    if (H == NULL)return -1;
    int max = H->p[0];
    H->p[0] = H->p[H->size - 1];
    int i = 0;
    int temp;
    while (1) {
        int lc = H->p[i * 2 + 1];
        int rc = H->p[(i + 1) * 2];
        if (i >= H->size / 2 || (H->p[i] > lc && H->p[i] > rc))break;
        if (lc > rc) {
            temp = H->p[i];
            H->p[i] = H->p[i * 2 + 1];
            H->p[i * 2 + 1] = temp;
            i = i * 2 + 1;
        } else if (rc >= lc) {
            temp = H->p[i];
            H->p[i] = H->p[(i + 1) * 2];
            H->p[(i + 1) * 2] = temp;
            i = (i + 1) * 2;
        }
    }
    H->p[H->size - 1] = 0;
    H->size--;
    return max;
}

void PrintValue(MaxHeap H) {
    assert(H != NULL);
    for (int i = 0; i < H->size; i++) {
        printf("%d ", H->p[i]);
    }
}

int HeapSize(MaxHeap H) {
    assert(H != NULL);
    return H->size;
}
//
//int main(int argc, char const *argv[]) {
//    MaxHeap p = Init_MaxHeap(20);
//    int arr[] = {150, 80, 40, 30, 10, 70, 110, 100, 20, 90, 60, 50, 120, 140, 130};
//    for (int i = 0; i < 15; i++) {
//        Insert(p, arr[i]);
//    }
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    printf("\n");
//    printf("%d\n", DeleteMax(p));
//    printf("%d\n", DeleteMax(p));
//    PrintValue(p);
//    return 0;
//}
