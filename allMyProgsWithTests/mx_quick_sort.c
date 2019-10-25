int mx_strlen(const char *s);
int compare(char *s1, char *s2);

int mx_quick_sort(char **arr, int left, int right) {
    int pivot;
    int i, j;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (compare(arr[pivot], arr[i])
                    && j <= right)
                i++;
            while (compare(arr[j], arr[pivot])
                    && j >= left)
                j--;
        }
        if (i < j) {
            char *t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    char *t = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = t;
    mx_quick_sort(arr, left, j - 1);
    mx_quick_sort(arr, j + 1, right);
    return WHAT????
}

int compare(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}
