#include "libmx.h"

static int comparator(char *s1, char *s2);
static void swap(char **s1, char **s2, int *count);
//static int partition(char **arr, int lo, int hi, int *count);

static void prt_arr(char **arr, int n) {
    printf("arr={\'%s\'", arr[0]);
    for (int i = 1; i < n; i++) {
        printf(", \'%s\'", arr[i]);
    }
    printf("}\n---\n");
}

int mx_quicksort(char **arr, int low, int high) {
    //implimantaion https://www.programcreek.com/2012/11/quicksort-array-in-java/
    // Этот вариант почему-то работает!!!
    if (arr == NULL || *arr == NULL) return -1;
    if (low >= high)
        return 0;
    int count = 0;
    // pick the pivot
    int middle = low + (high - low) / 2;
    char *pivot = arr[middle];

    // make left < pivot and right > pivot
    int i = low;
    int j = high;
    while (i <= j) {
        while (comparator(arr[i], pivot) < 0) {
            i++;
        }

        while (comparator(arr[j], pivot) > 0) {
            j--;
        }

        if (i <= j) {
            swap(&arr[i], &arr[j], &count);
            i++;
            j--;
        }
    }

    // recursively sort two sub parts
    if (low < j)
        count += mx_quicksort(arr, low, j);

    if (high > i)
        count += mx_quicksort(arr, i, high);
    
    return count;
}

// int mx_quicksort(char **arr, int left, int right) {
//     if (arr == NULL || *arr == NULL) return -1;
//     if (left >= right)
//         return 0;                             // for counting shifts
//     int count = 0;                            // for counting shifts
//     int j = partition(arr, left, right, &count);
//     count += mx_quicksort(arr, left, j - 1);  // for counting shifts
//     count += mx_quicksort(arr, j + 1, right); // for counting shifts
//     return count;
// }

// static int partition(char **arr, int lo, int hi, int *count) {
//     int i = lo;
//     int j = hi;
//     //Pick middle element of the array as pivot. 
//     char *pivot = arr[lo + (hi - lo) / 2];
//     //printf("i=%d j=%d arr[pivot]=%s\n", i, j, pivot);
//     //int pivot = lo;
//     while (i <= j) {
//         // find item on lo to swap
//         while (comparator(arr[i], pivot) < 0) {
//             //if (i == hi) break;
//             i++;
//         }
//         //printf("found i=%d\n", i);
//         // find item on hi to swap
//         while (comparator(arr[j], pivot) > 0) {
//             //if (j == lo) break;
//             j--;
//         }
//         //printf("found j=%d\n", j);
//         // check if pointers cross
//         //if (i >= j) break;
//         if (i <= j) {
//             //printf("swap %s<->%s\n", arr[i], arr[j]);
//             swap(&arr[i], &arr[j], count);
//             //prt_arr(arr, 7);
//             i++;
//             j--;
//         }
//     }
//     // put partitioning item arr[pivot] at arr[j]
//     // prt_arr(arr, 7);
//     // printf("i=%d j=%d swap %s<->%s\n", i, j, pivot, arr[j]);
//     // swap(&pivot, &arr[j], count);
//     // // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
//     // printf("now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]\n");
//     // prt_arr(arr, 7);
//     return i;
// }

static int comparator(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}

static void swap(char **s1, char **s2, int *count) {
    if (comparator(*s1, *s2) == 0) return; // added this
    char *t = *s1; 
    *s1 = *s2;
    *s2 = t;
    (*count)++;                              // for counting shifts
}

