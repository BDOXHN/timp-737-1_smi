#include <stdio.h>
#include <stdlib.h>

int sorting_function(int* arr, int arr_len) {
    int i;
    int j;
    int k;
    int t;

    for (k = arr_len / 2; k > 0; k = k / 2 ) {
        for (i = k; i < arr_len; i++) {
            t = arr[i];
            for (j = i; j >= k; j = j - k) {
                if (t < arr[j - k]) {
                    arr[j] = arr[j - k];
                }
                else
                    break;
            }
            arr[j] = t;
        }
    }

    //выводим массив
    i = 0;
    while (i < arr_len) {
        if (i == arr_len-1) {
            printf("%d\n", arr[i]);
            i++;
        }
        else {
            printf("%d ", arr[i]);
            i++;
        }
    }
    return 0;
}

int main() {
    int n;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    //считываем элементы
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sorting_function(a,n);
    free(a);
    return 0;
}

