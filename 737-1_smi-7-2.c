#include <stdio.h>
#include <stdlib.h>

void sorting_function1(int *arr, int node, int last) {

    int tempNodeMin; // сюда запоминаем минимальный элемент
    int boolEnd = 0; // если пирамида построена, задаём единицей

    while ((node * 2 <= last) && (!boolEnd)){ //шагаем до последнего "уровня"
        if (node * 2 == last) {
            tempNodeMin = node * 2;    // запоминаем левый потомок, если мы в последнем уровне
        } // иначе запоминаем меньший потомок из двух
        else {
            if (arr[node * 2] < arr[node * 2 + 1]) {
                tempNodeMin = node * 2;
            }
            else {
                tempNodeMin = node * 2 + 1;
            }
        }

        if (arr[node] > arr[tempNodeMin]) {//сравнение узла вершины с наименьшим узлом
          //меняем местами
            int temp;

            temp = arr[node];
            arr[node] = arr[tempNodeMin];
            arr[tempNodeMin] = temp;
            node = tempNodeMin;
        }
        else { // в противном случае пирамида сформирована
            boolEnd = 1;
        }
    }
}


void sorting_function(int *arr, int arr_len)
{
    // строим пирамиду
    int i; //номер первоначального узла
    for (i = (arr_len / 2) - 1; i > -1; i--) {
        sorting_function1(arr, i, arr_len - 1);
    }

    // сито правды, сито доброты, сито необходимости закрыть практику 7 (с) конфуций
    for (int i = arr_len - 1; i >= 1; i--) {
        int temp;

        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        sorting_function1(arr, 0, i - 1);
    }
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