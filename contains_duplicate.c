#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for qsort to sort integers in ascending order.
int compare_integers(const void *a, const void *b) 
{
    int val1 = *(const int *)a;
    int val2 = *(const int *)b;
    return val1 - val2;
}

bool containsDuplicate(int *nums, int numsize) {
    // Sort the array using qsort
    qsort(nums, numsize, sizeof(int), compare_integers);

    // After sorting, check for duplicates by comparing adjacent elements
    for (int i = 0; i < numsize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

