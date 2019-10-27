#include <stdio.h>
int mx_quick_sort(char **arr, int left, int right);

static void prt_arr(char **arr, int n) {
    printf("\narr={\'%s\'", arr[0]);
    for (int i = 1; i < n; i++) {
        printf(", \'%s\'", arr[i]);
    }
    printf("}\n");
}

int main(void) {
    printf("\nTest quick sort\n");
    //char *arr[] = {"xyz", "abc", "ghi", "def"};
    char *arr[] = {"xxxx", "x",  "xxx", "xx"};
    int n = 4;
    prt_arr(arr, n);
    int d = mx_quick_sort(arr, 0, n - 1);
    //printf("%d\n", d);
    prt_arr(arr, n);
    return 0;
}

