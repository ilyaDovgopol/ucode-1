#include "libmx.h"

static int comparator(char *s1, char *s2);
static void swap(char **arr, int i, int j, int *count);
static int partition(char **arr, int lo, int hi, int *count);

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL || *arr == NULL) return -1;
    if (left >= right)
        return 0;                             // for counting shifts
    int count = 0;                            // for counting shifts
    int j = partition(arr, left, right, &count);
    count += mx_quicksort(arr, left, j - 1);  // for counting shifts
    count += mx_quicksort(arr, j + 1, right); // for counting shifts
    return count;
}

static int partition(char **arr, int lo, int hi, int *count) {
    int i = lo;
    int j = hi;
    //Pick middle element of the array as pivot. 
    int pivot = lo + (hi - lo) / 2;
    //int pivot = lo;
    while (true) {
        // find item on lo to swap
        while (comparator(arr[i], arr[pivot]) <= 0) {
            if (i == hi) break;
            i++;
        }
        // find item on hi to swap
        while (comparator(arr[j], arr[pivot]) > 0) {
            if (j == lo) break;
            j--;
        }
        // check if pointers cross
        if (i >= j) break;
        swap(arr, i, j, count);
    }
    // put partitioning item arr[pivot] at arr[j]
    swap(arr, pivot, j, count);
    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
    return j;
}

static int comparator(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}

static void swap(char **arr, int i, int j, int *count) {
    if (i == j) return;
    char *t = arr[j]; 
    arr[j] = arr[i];
    arr[i] = t;
    (*count)++;                              // for counting shifts
}

