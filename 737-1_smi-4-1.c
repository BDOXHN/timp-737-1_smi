#include <stdio.h>
#include <stdlib.h>
// узел дерева
typedef struct n {
    int val;
    struct n *l;
    struct n *r;
    struct n *par;
} Node;

// дерево
typedef struct tree {
    int count;
    struct n *root;
} Tree;

// узел для очереди
typedef struct queNode {
    Node* treeNode;
    struct queNode *next;
} QueNode;

// односвязный список для очереди
typedef struct que {
    QueNode *head;
    QueNode *tail;
}Que;

void init(Tree *t) {
    t->root = NULL;
}

//инициализация очереди
void initQue(Que *q) {
    q->head = NULL;
    q->tail = NULL;
}

//вставка в конец очереди
int pushBack(Que *q, Node *n) {
    QueNode *newQueNode = (QueNode*)malloc(sizeof(QueNode));
    newQueNode->treeNode = n;
    newQueNode->next = NULL;

    if (q->head){
        q->tail->next = newQueNode;
    }
    else {
        q->head = newQueNode;
    }
    q->tail = newQueNode;

    return 0;
}

//вставка в древо великое дай жить дай дышать
int insert(Tree* t, int v) {
    Node* tempFirst = (Node*)malloc(sizeof(Node));
    Node* tempSecond;
    Node* tempThird = NULL;

    tempFirst->val = v;

    if (t->root == NULL) {
        tempFirst->l = NULL;
        tempFirst->r = NULL;
        tempFirst->par = NULL;
        t->root = tempFirst;
        t->count = 1;
        return 0;
    }

    if (t->root->val == tempFirst->val) {
        return 1;
    }

    tempSecond = t->root;

    while (tempSecond != NULL) {
        tempThird = tempSecond;

        if (v < tempSecond->val) {
            tempSecond = tempSecond->l;
        }
        else {
            tempSecond = tempSecond->r;
        }

    }

    if (tempThird->val == tempFirst->val) {
        return 1;
    }

    tempFirst->r = NULL;
    tempFirst->l = NULL;
    tempFirst->par = tempThird;
    if (v < tempThird->val) {
        tempThird->l = tempFirst;
    }
    else {
        tempThird->r = tempFirst;
    }
    t->count++;
    return 0;
}

//очистка очереди
void cleanQue(Que* q) {
    QueNode* tempFirst;
    QueNode* tempSecond;

    tempFirst = q->head;

    do
    {
        tempSecond = tempFirst;
        tempFirst = tempFirst->next;
        free(tempSecond);
    } while (tempFirst);

    q->head = NULL;
    q->tail = NULL;
}


void printTree1(Node *n) {
    if (n)
    {
        Que que1;
        Que que2;
        Que* pointerQue1;
        Que* pointerQue2;
        QueNode* q;
        Node* tempFirst;
        Node* left;
        Node* right;
        int bool;
        int breaker;
        int v;

        pointerQue1 = &que1;
        pointerQue2 = &que2;
        initQue(pointerQue1);
        initQue(pointerQue2);
        left = n->l;
        right = n->r;
        bool = 0;
        breaker = 0;
        v = n->val;

        pushBack(pointerQue1, n);

        while (1337) {
            while (pointerQue1->head) {
                if (pointerQue1->head) {
                    QueNode* getFromQueAndDel;

                    tempFirst = pointerQue1->head->treeNode;
                    getFromQueAndDel = pointerQue1->head;
                    pointerQue1->head = pointerQue1->head->next;

                    if (pointerQue1->head == NULL) {
                        pointerQue1->tail = NULL;
                    }
                    free(getFromQueAndDel);
                }
                else {
                    tempFirst = NULL;
                }

                if (pointerQue1->head == NULL) {
                    if (tempFirst->val == v && bool == 1)
                        printf("_\n");
                    else
                        printf("%d\n", tempFirst->val);
                }
                else if (tempFirst->val == v && bool == 1)
                    printf("_ ");
                else
                    printf("%d ", tempFirst->val);

                if (tempFirst->l)
                    pushBack(pointerQue2, tempFirst->l);
                else
                    pushBack(pointerQue2, n);

                if (tempFirst->r)
                    pushBack(pointerQue2, tempFirst->r);
                else
                    pushBack(pointerQue2, n);
            }
            n->l = NULL;
            n->r = NULL;
            bool = 1;
            q = pointerQue2->head;

            while (pointerQue2->head->treeNode->val == v) {
                pointerQue2->head = pointerQue2->head->next;

                if (pointerQue2->head->next == NULL)
                    if (pointerQue2->head->treeNode->val == v) {
                        breaker = 1;
                        n->l = left;
                        n->r = right;
                        cleanQue(pointerQue2);
                        break;
                    }
            }
            pointerQue2->head = q;

            if (breaker == 1)
                break;
            pointerQue1->head = pointerQue2->head;
            pointerQue1->tail = pointerQue2->tail;
            pointerQue2->head = NULL;
            pointerQue2->tail = NULL;
        }
    }
    else
        printf("-\n");
}

void printTree(Tree* t) {
    printTree1(t->root);
}

// поиск элемента по значению. вернуть 0 если элемент найден и ссылку на найденнйы
// элемент в переменную n если n != NULL. в случае если элемент не найден вернуть 1
int find(Tree* t, int value, Node* n) {
    Node* tempFirst;
    tempFirst = t->root;

    if (t->root == NULL) {
        printf("-\n");
        return 1;
    }

    while (1337) {

        if (tempFirst == NULL) {
            printf("-\n");
            return 1;
        }
        else {
            if (tempFirst->val == value) {
                n->val = tempFirst->val;
                n->l = tempFirst->l;
                n->r = tempFirst->r;
                n->par = tempFirst->par;
                return 0;
            }
            else {
                if (value < tempFirst->val) {
                    tempFirst = tempFirst->l;
                }
                else {
                    tempFirst = tempFirst->r;
                }
            }
        }
    }
}

void printFind(Node* n) {

    if (n->par != NULL) {
        printf("%d ", n->par->val);
    }
    else {
        printf("_ ");
    }

    if (n->l != NULL) {
        printf("%d ", n->l->val);
    }
    else {
        printf("_ ");
    }

    if (n->r != NULL) {
        printf("%d\n", n->r->val);
    }
    else {
        printf("_\n");
    }
}

int removeNode(Tree* t, int value) {

    Node* tempFirst;
    Node* tempSecond;
    Node * search;
    int minValue;

    tempFirst = malloc(sizeof(Node));
    tempFirst = t->root;

    if (t->root == NULL) {
        return 1;
    }

    while (1337) {
        if (tempFirst == NULL) {
            return 1;
        }
        else if (tempFirst->val == value) {
            break;
        }
        else if (value > tempFirst->val) {
            tempFirst = tempFirst->r;
        }
        else {
            tempFirst = tempFirst->l;
        }
    }

    if ((tempFirst->l == NULL) && (tempFirst->r == NULL)) {
        if (tempFirst->par->r->val == tempFirst->val) {
            tempFirst->par->r = NULL;
        }
        else {
            tempFirst->par->l = NULL;
        }
    }
    else if (tempFirst->r == NULL) {
        *tempFirst = *(tempFirst->l);
    }
    else if (tempFirst->l == NULL) {
        *tempFirst = *(tempFirst->r);
    }
    else {
        search = tempFirst->r;

        while (1337) {
            if (search == NULL) {
                break;
            } else {
                tempSecond = search;
                minValue = search->val;
                search = search->l;
            }
        }

        tempFirst->val = tempSecond->val;
        tempFirst = tempSecond;

        if ((tempFirst->l == NULL) && (tempFirst->r == NULL)) {
            if (tempFirst->par->r->val == tempFirst->val) {
                tempFirst->par->r = NULL;
            } else {
                tempFirst->par->l = NULL;
            }
        } else if (tempFirst->r == NULL) {
            *tempFirst = *(tempFirst->l);
        } else {
            *tempFirst = *(tempFirst->r);
        }
    }
    t->count--;
    return 0;
}

int removeMin(Tree* t, Node* n) {
    Node* tempFirst;
    tempFirst = n;

    while (tempFirst->l != NULL) {
        tempFirst = tempFirst->l;
    }

    removeNode(t, tempFirst->val);
}

int rotateLeft(Tree* t) {
    Node *tempFirst;
    tempFirst = t->root->r;

    if (tempFirst == NULL)
        return 1;

    t->root->r = tempFirst->l;
    tempFirst->l = t->root;
    tempFirst->par = t->root->par;
    t->root->par = tempFirst;
    t->root = tempFirst;

    return 0;
}

int rotateRight(Tree *t) {
    Node *tempFirst;
    tempFirst = t->root->l;

    if (tempFirst == NULL)
        return 1;

    t->root->l = tempFirst->r;
    tempFirst->r = t->root;
    tempFirst->par = t->root->par;
    t->root->par = tempFirst;
    t->root = tempFirst;

    return 0;
}

void clear1(Node* node)
{
    if (node == NULL) return;
    clear1(node->l);
    clear1(node->r);
    free(node);
}

void clear(Node** node_ref)
{
    clear1(*node_ref);
    *node_ref = NULL;
}


int main(void) {
    //1 создаём пустое дерево, считываем в него 4 элемента ai и заносим их в дерево
    Tree* t;
    int putIt;
    int i;
    int bool;
    Node* n1;
    Node* n2;

    t = malloc(sizeof(Tree));

    init(t);
    for (i = 1; i <= 4; i++) {
        scanf("%d", &putIt);
        insert(t, putIt);
    }

    //2 выводим дерево с помощью printTree
    printTree(t);

    //3 считываем 3 элемента ai и заносим их в дерево
    for (i = 1; i <= 3; i++) {
        scanf("%d", &putIt);
        insert(t, putIt);
    }

    //4 выводим деревь с помозью printTree
    printTree(t);

    //5 считываем m1 и находим элемент с заданным начением в дереве
    // вывести через пробел значение ПРЕДКА и ПОТОМКОВ элемента
    // если элемент не найден, вывести "-"
    // если нет предка или потомков вывести "_" вместо них
    n1 = malloc(sizeof(Node));

    scanf("%d", &putIt);
    bool = find(t, putIt, n1);

    if (bool != 1) {
        printFind(n1);
    }
    free(n1);

    //6 считываем m2 и найти элемент с заданным значением в дереве
    // вывести через пробел значение предка и потомков найденного элемента
    // если элемент не найден, вывести "-"
    // если нет предка или потомков вывести "_" вместо них
    n2 = malloc(sizeof(Node));

    scanf("%d", &putIt);
    bool = find(t, putIt, n2);

    if (bool != 1) {
        printFind(n2);
    }
    free(n2);

    //7 считать m3 и удалить из дерева элемент с заданным значением
    scanf("%d", &putIt);
    removeNode(t, putIt);

    //8 выводим дерево используя printTree
    printTree(t);

    //9 выполняем левый поворот древа относительно корня пока это возможно
    while (rotateLeft(t) == 0);

    //10 выводим дерево с помощью printTree
    printTree(t);

    //11 выполняем правый поворот древа относительно корня пока это возможно
    while (rotateRight(t) == 0);

    //12 выводим дерево с помощью printTree
    printTree(t);

    //13 выводим на экран количество элементов в дереве
    printf("%d\n", t->count);

    //14 очищаем дерево
    clear(&t->root);

    //15 выводим дерево на жкран с помощью printTree
    printTree(t);
}