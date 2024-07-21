#include <stdio.h>
#include <stdlib.h>

void replaceSubstring(char *str, char *substr);
char toUpper(char ch);
int stringLength(char *str);
char* findSubstring(char *str, char *substr);
void removeNewline(char *str);

int main() {
    char *str;
    char *substr;

    while (1) {
        str = (char *)malloc(101 * sizeof(char));
        if (str == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter text: ");
        fgets(str, 101, stdin);
        removeNewline(str);

        if (stringLength(str) == 0) {
            free(str);
            break;
        }

        substr = (char *)malloc(101 * sizeof(char));
        if (substr == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return 1;
        }

        printf("Enter substring: ");
        fgets(substr, 101, stdin);
        removeNewline(substr);

        if (stringLength(substr) == 0) {
            free(str);
            free(substr);
            break;
        }

        replaceSubstring(str, substr);

        printf("%s\n", str);

        free(str);
        free(substr);
    }

    printf("Finish\n");
    return 0;
}

void replaceSubstring(char *str, char *substr) {
    char *pos = str;
    int substr_len = stringLength(substr);

    while ((pos = findSubstring(pos, substr)) != NULL) {
        for (int i = 0; i < substr_len; i++) {
            pos[i] = toUpper(pos[i]);
        }
        pos += substr_len;
    }
}

char toUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }
    return ch;
}

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char* findSubstring(char *str, char *substr) {
    int len_str = stringLength(str);
    int len_substr = stringLength(substr);

    for (int i = 0; i <= len_str - len_substr; i++) {
        int j;
        for (j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len_substr) {
            return &str[i];
        }
    }
    return NULL;
}

void removeNewline(char *str) {
    int len = stringLength(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
