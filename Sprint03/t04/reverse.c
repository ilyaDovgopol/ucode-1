#include <stdio.h>

void reverce(char *s);
int strlen(char *s);
void swap(char *a, char *b);

int main(void) {
  char s[] = "Helo";
  reverce(s);
  printf("%s", s);
}

int strlen(char *s) {
    int count = 0;
    while(s[count] != '\0') {
        count++;
    }
    return count;
}

void reverce(char *s) {
  int lenght = strlen(s);
  for (int i = 0; i < lenght / 2; i++) {
    int j = lenght - i - 1;
    swap(&s[i], &s[j]);
  }
}

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
