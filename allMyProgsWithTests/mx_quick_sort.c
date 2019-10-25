int mx_strlen(const char *s);
int compare(char *s1, char *s2);

int mx_quick_sort(char **arr, int size, const char *s, int *count) {
    *count = 0; // dont forget
    if (!s) return -1;
    if (size <= 0) return -1;
    if (size == 1) return 0;

    int left = 0;
    int right = size - 1;
    while (left <= right) {
        (*count)++; // dont forget
        int mid = left + (right - left) / 2;
        if (compare((char *)s, arr[mid]) < 0)
            right = mid - 1;
        else if (compare((char *)s, arr[mid]) > 0)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int compare(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}
