
#include <stdio.h>

void insert_sort(int *array, int len) {
    int i = 0;
    int j = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
            else {
                break;
            }
        }
    }
}

int main() {
    int i = 0;
    int array[] = {77,23,46,0,17,29,20,28};
    int num = 0;
    num = sizeof(array) / sizeof(int);
    insert_sort(array, num);
    printf("insert_sort <");
    for (i = 0; i < num; i++) {
        printf ("%d ", array[i]);
    }
    printf(">\n");
}