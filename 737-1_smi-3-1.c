#include <stdio.h>
#include <stdlib.h>

struct node {
	int value; //�������� � ����
	struct node* next;
} node;

struct list {
	struct node* head; // ������ ������
} list;

/* 11111
	�������������� ���� newHead
	�������� ��� ���� ������
	������ ������
	��������� ������ *l � �������� ������ ���� ����
*/
void init(struct list* l, int value) {
	struct node* newHead;
	newHead = (struct node*)malloc(sizeof(struct node));
	newHead->next = NULL;
	newHead->value = value;
	l->head = newHead;
}

/* 11111
��������� ������ �� ������
��������� ��������� �� �����
���������� 1 ���� ������ ������
���������� 0 ���� ������ �� ������
*/
int isEmpty(struct list* l) {
	return l->head == NULL;
}
 
/* 11111
	������� ��������������� � ������ �� ����
	���� �� �����������, ��� ���� = NULL
	(��������� ���� ��������� �� NULL)
*/
void clear(struct list* l) {
	if (isEmpty(l) == 1) {
		struct node* tempFirst;
		tempFirst = l->head;
		struct node* tempSecond;
		tempSecond = NULL;
		while (tempFirst != NULL) {
			tempSecond = tempFirst->next;
			free(tempFirst);
			tempFirst = tempSecond;
		}
		l->head = NULL;
	}
}

/* 11111
	���� ������� �� �������� value
	��������� ��������� �� ������
	��������� ���������� ��� ������
	���������� �������� ��������� (����) �� ��������� ����
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
	��������� �������� � ����� ������
	��������� ��������� �� ������
	��������� ���������� ��� �������
	���������� 0 ���� ������� �������
*/
int pushBack(struct list* l, int value) {
	if (isEmpty(l) == 1) {
		init(l, value);
	}
	else {
		struct node* tempFirst;
		tempFirst = l->head;
		struct node* tempSecond;
		tempSecond = (struct node*)malloc(sizeof(struct node));
		tempSecond->value = value;
		tempSecond->next = NULL;
		while (tempFirst->next != NULL) {
			tempFirst = tempFirst->next;
		}
		tempFirst->next = tempSecond;
	}
	return 0;
}

/* 11111
	��������� �������� � ������ ������
	��������� ��������� �� ������
	��������� ���������� ��� �������
	���������� 0 ���� ������� �������
*/
int pushFront(struct list* l, int value) {
	if (isEmpty(l) == 1) {
		init(l, value);
	}
	else {
		struct node* tempFirst;
		tempFirst = (struct node*)malloc(sizeof(struct node));
		tempFirst->next = l->head;
		tempFirst->value = value;
		l->head = tempFirst;
	}
	return 0;
}

/* 11111
	��������� �������� ����� ���������� ����
	��������� ��������� �� ����
	��������� ���������� ��� �������
	���������� 0 ���� ������� �������
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
		tempFirst->next = tempSecond;
}

/* 11111
	������� ������ ������� �� ������ � ��������� ���������
	��������� ��������� �� ������
	��������� ����������, �� ������� ����� ����� ����
	���������� 0 ���� �������� �������
*/
int removeFirst(struct list* l, int value) {
	struct  node* DeleteThis;
	DeleteThis = find(l, value);
	if (DeleteThis != NULL) {
		if (DeleteThis == l->head) {
			l->head = DeleteThis->next;
		}
		else {
			struct node* tempFirst;
			tempFirst = (struct node*)malloc(sizeof(struct node));
			tempFirst = l->head;
			while (tempFirst->next != DeleteThis) {
				tempFirst = tempFirst->next;
			}
			tempFirst->next = DeleteThis->next;
		}
		free(DeleteThis);
	}
	else {
		return 1;
	}
}

/* 11111
	�������� ��� �������� ����� ������
	� ����� ��������� �� ����� ������
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

int main(void) {
	//1 ��������� ���������� ���������
	int n;
	scanf("%d", &n);

	//2 ������ ������ ������, ��������� ��������, ������� �� � ������
	struct list* p = (struct list*)malloc(sizeof(struct list));
	int putItBack;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &putItBack);
		pushBack(p, putItBack);
	}

	//3 ������� ���������� ������
	print(p);

	//4 ��������� k1 k2 k3, ������� 1 ���� ����� ������� ����, 0 ���� ���
	//��������� ����� ����� �� ����� ������
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

	//5 ������� m � �������� ��� � ����� ������
	int putItLast;
	scanf("%d", &putItLast);
	pushBack(p, putItLast);

	//6 ������� ���������� ������
	print(p);

	//7 ������� m � �������� ��� � ������ ������
	int putItFirst;
	scanf("%d", &putItFirst);
	pushFront(p, putItFirst);

	//8 ������� ���������� ������
	print(p);

	//9 ������� j � x, �������� x ����� j�� ��������
	int j;
	int x;
	scanf("%d%d", &j, &x);
	insertAfter(p, x, j);

	//10 ������� ���������� ������
	print(p);

	//11 ������� z � ������� ������ ������� � ����� ���������
	int z;
	scanf("%d", &z);
	removeFirst(p, z);

	//12 ������� ���������� ������
	print(p);

	//������� ������
	clear(p);
}