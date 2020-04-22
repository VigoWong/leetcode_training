//
// Created by Vigo Wong on 22/4/20.
//
#include "../data_structure/tree/MaxHeap.h"

int lastStoneWeight(int* stones, int stonesSize) {
    MaxHeap h = Init_MaxHeap(stonesSize+1);
    for (int i = 0; i < stonesSize; i++) {
        Insert(h, stones[i]);
    }
    while (!IsEmpty(h)) {
        if (HeapSize(h) != 1) {
            int fir = DeleteMax(h);
            int sed = DeleteMax(h);
            int diff = (fir >= sed) ? (fir - sed) : (sed - fir);
            if (diff) Insert(h, diff);
        } else {
            return DeleteMax(h);
        }
    }
    return 0;

}

int main(int argc, char const *argv[]){
    int arr[] = {2,7,4,1,8,1, 9};
    printf("%d", lastStoneWeight(arr, 7));
    return 0;
}

