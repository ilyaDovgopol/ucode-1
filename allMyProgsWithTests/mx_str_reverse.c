int mx_strlen(char *c);
void mx_swap_char(char *s1, char *s2);

void mx_str_reverse(char *s) {
    if (!s)
        return;
    
    int len = mx_strlen(s);

    for (int i = 0; i < len / 2; i++) {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
