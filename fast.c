
#include <stdio.h>

int get_index(int *array, int low, int high) {
    int *aa = array;
    int tmp = aa[low];
    printf("[%s:%d]==low:%d high:%d tmp:%d\n", __FUNCTION__, __LINE__, low, high, tmp);
    while (low < high) {
        while ((low < high) && (aa[high] >= tmp)) {
            high--;
        }
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
        aa[low] = aa[high];
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
        while ((low < high) && (aa[low] <= tmp)) {
            // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
            low++;
        }
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
        aa[high] = aa[low];
    }
    // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
    aa[low] = tmp;
    // printf("[%s:%d]==low:%d\n", __FUNCTION__, __LINE__, low);
    printf("quick_sort11 <");
    int i = 0;
    for (i = 0; i < 8; i++) {
        printf ("%d ", array[i]);
    }
    printf(">\n");
    return low;
}

void quick_sort(int *array, int low, int high) {
    int index = 0;
    if (low < high) {
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
        index = get_index(array, low, high);
        printf("[%s:%d]==index:%d low:%d\n", __FUNCTION__, __LINE__, index, low);
        quick_sort(array, low, index - 1);
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
        quick_sort(array, index + 1, high);
        // printf("[%s:%d]==\n", __FUNCTION__, __LINE__);
    }
}

int main(int argc, char *argv[]) {
    int i = 0;
    int array[] = {77,23,46,0,17,29,20,28};
    int num = 0;
    num = sizeof(array) / sizeof(int);
    printf("array size:%d\n", num);
    quick_sort(array, 0, num - 1);
    printf("quick_sort <");
    for (i = 0; i < num; i++) {
        printf ("%d ", array[i]);
    }
    printf(">\n");
    return 0;
}