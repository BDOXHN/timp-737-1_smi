#include <stdio.h>
#include <stdlib.h>

int sorting_function1(int* arr, int left, int right) {

    int elem;       //разрешающий элемент
    int leftBack;   //левая граница
    int rightBack;  //правая граница

    leftBack = left;
    rightBack = right;

    elem = arr[left];

    while (left < right) {
        while ( arr[right] >= elem && left < right) {
            right--;
        }
        if (left != right) {
            arr[left] = arr[right];
            left++;
        }

        while ( arr[left] <= elem && left < right) {
            left++;
        }
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = elem;
    elem = left;
    left = leftBack;
    right = rightBack;

    if (left < elem) {
        sorting_function1(arr, left, elem - 1);
    }
    if (right > elem) {
        sorting_function1(arr, elem + 1, right);
    }
    return 0;
}

int sorting_function(int* arr, int arr_len) {
    sorting_function1(arr, 0, arr_len - 1);
}

int main() {
    int n;
    int i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    //считываем элементы
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sorting_function(a,n);

    //выводим массив
    i = 0;
    while (i < n) {
        if (i == n - 1) {
            printf("%d\n", a[i]);
            i++;
        }
        else {
            printf("%d ", a[i]);
            i++;
        }
    }
    free(a);
}