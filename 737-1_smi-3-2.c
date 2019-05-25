#include <stdio.h>
#include <stdlib.h>

struct node {
	int value; 
	struct node* next;
	struct node* prev;
};

struct list {
	struct node* head; 
	struct node* tail;
};

/* 11111
инициализирует узел newHead
выделяет под него память
делает пустым
назначает списку *l в качестве головы этот узел
*/
void init(struct list* l, int value) {
	struct node* newHead;
	newHead = (struct node*)malloc(sizeof(struct node));
	l->head = newHead;
	l->tail = newHead;
	newHead->next = NULL;
	newHead->prev = NULL;
	newHead->value = value;
}

/* 11111
проверяет пустой ли список
принимает указатель на спиок
возвращает 1 если список пустой
возвращает 0 если список не пустой
*/
int isEmpty(struct list* l) {
	return (l->head == NULL) && (l->tail == NULL);
}


/* 11111
удаляет последовательно с головы по узлу
пока не обнаружится, что узел = NULL
(последний узел указывает на NULL)
*/
void clear(struct list* l) {
	if (isEmpty(l) == 1) {
		struct node* tempFirst;
		tempFirst = l->tail;
		struct node* tempSecond;
		tempSecond = NULL;
		while (tempFirst != NULL) {
			tempSecond = tempFirst->prev;
			free(tempFirst);
			tempFirst = tempSecond;
		}
		l->head = NULL;
		l->tail = NULL;
	}
}

/* 11111
ищет элемент с конца по значению value
принимает указатель на список
принимает переменную для поиска
возвращает значение указателя (арес) на найденный узел
*/
struct node* find(struct list* l, int value) {
	struct node* letFind;
	letFind = l->head;
	while (letFind->value != value) {
		if (letFind->next != NULL) {
			letFind = letFind->next;
		}
		else {
			return NULL;
		}
	}
	return letFind;
}

/* 11111
ищет элемент с конца по значению value
принимает указатель на список
принимает переменную для поиска
возвращает значение указателя (арес) на найденный узел
*/
struct node* findInvers(struct list* l, int value) {
	struct node* letFind;
	letFind = l->tail;
	while (letFind->value != value) {
		if (letFind->prev != NULL) {
			letFind = letFind->prev;
		}
		else {
			return NULL;
		}
	}
	return letFind;
}

/* 11111
вставляет значение в конец списка
принимает указатель на список
принимает переменную для вставки
возвращает 0 если вставка успешна
*/
int pushBack(struct list* l, int value) {
	if (isEmpty(l) == 1) {
		init(l, value);
	}
	else {
		struct node* tempFirst;
		tempFirst = (struct node*)malloc(sizeof(struct node));
		tempFirst->value = value;
		tempFirst->prev = l->tail;
		tempFirst->next = NULL;
		l->tail = tempFirst;
		tempFirst->prev->next = tempFirst;
	}
	return 0;
}

/* 11111
вставляет значение в начало списка
принимает указатель на список
принимает переменную для вставки
возвращает 0 если вставка успешна
*/
int pushFront(struct list* l, int value) {
	if (isEmpty(l) == 1) {
		init(l, value);
	}
	else {
		struct node* tempFirst;
		tempFirst = (struct node*)malloc(sizeof(struct node));
		tempFirst->value = value;
		tempFirst->prev = NULL;
		tempFirst->next = l->head;
		l->head = tempFirst;
		tempFirst->next->prev = tempFirst;
	}
	return 0;
}

/* 11111
вставляет значение после указанного узла
принимает указатель на узел
принимает переменную для вставки
возвращает 0 если вставка успешна
*/
int insertAfter(struct list* l, int value, int num) {
	struct node* tempFirst;
	tempFirst = (struct node*)malloc(sizeof(struct node));
	tempFirst->value = value;
	struct node* tempSecond;
	struct node* tempThird;
	tempSecond = l->head;
	tempThird = l->head;
	for (int i = 1; i <= num; i++) {
		tempThird = tempSecond;
		tempSecond = tempSecond->next;
		if (tempSecond == NULL) {
			return 1;
		}
	}
	tempThird->next = tempFirst;
	tempFirst->prev = tempThird;
	tempFirst->next = tempSecond;
	tempSecond->prev = tempFirst;
}

/* 11111
вставляет значение перед указанным узлом
принимает указатель на узел
принимает переменную для вставки
возвращает 0 если вставка успешна
*/
int insertBefore(struct list* l, int value, int num) {
	struct node* tempFirst;
	tempFirst = (struct node*)malloc(sizeof(struct node));
	tempFirst->value = value;
	struct node* tempSecond;
	struct node* tempThird;
	tempSecond = l->head;
	tempThird = l->head;
	for (int i = 1; i < num; i++) {
		tempThird = tempSecond;
		tempSecond = tempSecond->next;
		if (tempSecond == NULL) {
			return 1;
		}
	}
	tempThird->next = tempFirst;
	tempFirst->prev = tempThird;
	tempFirst->next = tempSecond;
	tempSecond->prev = tempFirst;
}

/* 11111
удаляет первый элемент из списка с указанным значением
принимает указатель на список
принимает переменную, по которой нужно найти узел
возвращает 0 если удаление успешно
*/
int removeFirst(struct list* l, int value) {
	struct  node* DeleteThis;
	DeleteThis = find(l, value);
	if (DeleteThis != NULL) {
		if (DeleteThis == l->head) {
			l->head = DeleteThis->next;
			l->head->prev = NULL;
		}
		else {
			struct node* tempFirst;
			tempFirst = (struct node*)malloc(sizeof(struct node));
			tempFirst = l->head;
			while (tempFirst->next != DeleteThis) {
				tempFirst = tempFirst->next;
			}
			tempFirst->next = DeleteThis->next;
			tempFirst->next->prev = tempFirst;
		}
		free(DeleteThis);
	}
	else {
		return 1;
	}
}

/* 11111
удаляет последний элемент из списка с указанным значением
принимает указатель на список
принимает переменную, по которой нужно найти узел
возвращает 0 если удаление успешно
*/
int removeLast(struct list* l, int value) {
	struct  node* DeleteThis;
	DeleteThis = findInvers(l, value);
	if (DeleteThis != NULL) {
		if (DeleteThis == l->tail) {
			l->tail = DeleteThis->prev;
			l->tail->next = NULL;
		}
		else {
			struct node* tempFirst;
			tempFirst = (struct node*)malloc(sizeof(struct node));
			tempFirst = l->tail;
			while (tempFirst->prev != DeleteThis) {
				tempFirst = tempFirst->prev;
			}
			tempFirst->prev = DeleteThis->prev;
			DeleteThis->prev->next = tempFirst;
		}
		free(DeleteThis);
	}
	else {
		return 1;
	}
}

/* 11111
печатает все элементы через пробел
в конце переходит на новую строку
*/
void print(struct list* l) {
	struct node* tempFirst;
	tempFirst = l->head;
	while (tempFirst->next != NULL) {
		printf("%d ", tempFirst->value);
		tempFirst = tempFirst->next;
	}
	printf("%d\n", tempFirst->value);
}


/* 11111
печатает все элементы через пробел
в конце переходит на новую строку
*/
void printInvers(struct list* l) {
	struct node* tempFirst;
	tempFirst = l->tail;
	while (tempFirst->prev != NULL) {
		printf("%d ", tempFirst->value);
		tempFirst = tempFirst->prev;
	}
	printf("%d\n", tempFirst->value);
}

int main(void) {
	//1 считываем количество элементов
	int n;
	scanf("%d", &n);

	//2 создаём пустой список, считываем элементы, заносим их в список
	struct list* p = (struct list*)malloc(sizeof(struct list));
	int putItBack;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &putItBack);
		pushBack(p, putItBack);
	}

	//3 выводим содержимое списка
	print(p);

	//4 считываем k1 k2 k3, выводим 1 если такой элемент есть, 0 если нет
	//переходим после этого на новую строку
	for (int i = 1; i <= 3; i++) {
		int k123;
		scanf("%d", &k123);
		if (find(p, k123) != NULL) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");

	//5 считать m и вставить его в конец списка
	int putItLast;
	scanf("%d", &putItLast);
	pushBack(p, putItLast);

	//6 выводим содержимое списка в обратном порядке
	printInvers(p);

	//7 считать m и вставить его в начало списка
	int putItFirst;
	scanf("%d", &putItFirst);
	pushFront(p, putItFirst);

	//8 выводим содержимое списка
	print(p);

	//9 считать j и x, вставить x после jго элемента
	int j;
	int x;
	scanf("%d%d", &j, &x);
	insertAfter(p, x, j);

	//10 выводим содержимое списка в обратном порядке
	printInvers(p);

	//11 считать j и x, вставить x перед jым элементом
	int j1;
	int x1;
	scanf("%d%d", &j1, &x1);
	insertBefore(p, x1, j1);

	//12 выводим содержимое списка
	print(p);

	//13 считать z и удалить первый элемент с таким значением
	int z;
	scanf("%d", &z);
	removeFirst(p, z);

	//14 выводим содержимое списка в обратном порядке
	printInvers(p);

	//15 считать z и удалить последний элемент с таким значением
	int z1;
	scanf("%d", &z1);
	removeLast(p, z1);

	//14 выводим содержимое списка
	print(p);

	//очищаем список
	clear(p);
}