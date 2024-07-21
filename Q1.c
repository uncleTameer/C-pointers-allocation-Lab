#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    int *series;

    printf("Enter the series length: ");
    scanf("%d", &length);

    series = (int *)malloc(length * sizeof(int));
    if (series == NULL) {
        printf("Memory allocation failed\n");
    }

    printf("Now, enter the series:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &series[i]);
    }

    printf("The series is:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", series[i]);
    }
    printf("\n");

    free(series);

    return 0;
}
