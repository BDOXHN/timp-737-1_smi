#include <stdio.h>
#include <stdlib.h>

int sorting_function(int* arr, int arr_len) {
    if (arr_len == 0) {
        return 0;
    }

    double factor;
    int i;
    int step;
    int temp;
    int shift; //кол-во перестановок
    int compare; //сравнения
    int bool = 0; //для логики в пузырьке
    factor = 1.2473309;
    shift = 0;
    compare = 0;

    //расчёсываем массив
    step = arr_len - 1;
    while (step >= 1) {
        for (i = 0; i + step < arr_len; ++i) {
            if (arr[i] > arr[i + step]) {
                temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                shift++;
                compare++;
            }
            else {
                compare++;
            }
            step = (int) (step / factor);
        }
    }

    //пузырёк напоследок
    i = 0;
    while (i < arr_len) {
        if (i + 1 != arr_len && arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            bool = 1;
        }
        i++;
        if (i == arr_len && bool == 1) {
            i = 0;
            bool = 0;
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
}