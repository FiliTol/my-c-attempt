#include <stdio.h>

int binarySearch(int value, int array[], int array_size);

int main(void) {
    int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13};
    int value = 11;
	int array_size = sizeof(test_array) / sizeof(test_array[0]);

    int result = binarySearch(value, test_array, array_size);
    printf("%d\n", result);
    return 0;
}


int binarySearch(int value, int int_array[], int array_size)
{
	/*This finds the size of the array in bytes and divides by the number of bytes that each element in the array uses */
	int middle = array_size/2;
	int lb = 0;
    int ub = array_size - 1; // upper bound of search range

	while (ub >= lb) {
		if (value < int_array[middle]) {
            ub = middle - 1;
			middle = lb + ( (ub - lb) / 2);
		} else if (value > int_array[middle]) {
		    lb = middle + 1;
			middle = lb + ( (ub - lb) / 2);
		} else {
			return 1;
		}
	}
	return -1;
}
