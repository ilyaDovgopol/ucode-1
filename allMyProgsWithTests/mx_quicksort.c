#include "libmx.h"

static int compare(char *s1, char *s2);

#include <stdio.h>
static void prt_arr(char **arr, int n) {
    printf("\narr={\'%s\'", arr[0]);
    for (int i = 1; i < n; i++) {
        printf(", \'%s\'", arr[i]);
    }
    printf("}\n");
}

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL || *arr == NULL || left > right) return -1;
    int shifts = 0;
    int pivot;
    int i, j;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (compare(arr[pivot], arr[i]) >= 0
                    && i <= right) {
                i++;
            }
            while (compare(arr[j], arr[pivot]) > 0
                    && j >= left) {
                j--;
            }
            if (i < j) {
                shifts++;
                char *t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        shifts++;
        char *t = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = t;
        shifts += mx_quick_sort(arr, left, j - 1);
        shifts += mx_quick_sort(arr, j + 1, right);
    }
    return shifts;
}

static int compare(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}

