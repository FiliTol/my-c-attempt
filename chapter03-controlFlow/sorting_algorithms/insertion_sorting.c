#include <stdio.h>

void insertionSort(int array[], int array_size);

int main(void) {
    int array[] = {1, 2, 5, 12, 11, 10, 4, 3};
    int array_size = sizeof(array)/sizeof(array[0]);

    int i;
    printf("Initial array is: ");
    for (i = 0; i < array_size; ++i) {
        printf(" %d", array[i]);
    }

    insertionSort(array, array_size);

    printf("\nSorted array is: ");
    for (i = 0; i < array_size; ++i) {
        printf(" %d", array[i]);
    }

    printf("\n");
    return 0;
}


void insertionSort(int array[], int array_size) {
    int index;
    for (index = 0; index < array_size ; ++index) {
        int j = index - 1; // This index loops through the sorted group
        int k = index;
        while (j >= 0){
            if (array[k] < array[j]) {
                int temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
            --j;
            --k;
        }
    }
}

