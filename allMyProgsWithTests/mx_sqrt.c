int mx_sqrt(int x) {
    int i = 1;
    while (i * i < x) {
        i++;
    }
    if (i * i == x) {
        return i;
    }
    return 0;
}

