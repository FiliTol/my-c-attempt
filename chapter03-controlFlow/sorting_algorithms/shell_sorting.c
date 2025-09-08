#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

void shellSort(int array[], int array_size);

int main(void) {
    int array[] = {1, 2, 5, 12, 11, 10, 4, 3, 100, 99, 36, 65, 83, 789, 22, 34, 55, 31, 13, 21, 91};
    int array_size = sizeof(array)/sizeof(array[0]);

    int i;
    printf("Initial array is: ");
    for (i = 0; i < array_size; ++i) {
        printf(" %d", array[i]);
    }
    start = clock();
    shellSort(array, array_size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array is: ");
    for (i = 0; i < array_size; ++i) {
        printf(" %d", array[i]);
    }

    printf("\nTook %f seconds to execute", cpu_time_used);
    return 0;
}


void shellSort(int array[], int array_size) {
    int gap;
    int index;
    int j;

    for (gap = array_size/2; gap > 0; gap /=2 ) {
        for (index = gap; index < array_size ; ++index) {
            for (j = index - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
            int temp = array[j];
            array[j] = array[j + gap];
            array[j + gap] = temp;
            }
        }
    }
}

