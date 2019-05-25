#include <stdio.h>
#include <stdlib.h>
// узел дерева
typedef struct node {
    int val;
    struct node *l;
    struct node *r;
    struct node *par;
} Node;

// дерево
typedef struct tree {
    int count;
    struct node *root;
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

void print(Node *n) {
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
                        printf(" ");
                    else
                        printf("%d ", tempFirst->val);
                }
                else if (tempFirst->val == v && bool == 1)
                    printf(" ");
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
        printf(" ");
}

int main()
{
    //1 вводим в дерево
    Tree *t = (Tree*)malloc(sizeof(Node));
    init(t);
    int putIt;

    for (int i = 1; i <= 7; i++) {
        scanf("%d", &putIt);
        insert(t, putIt);
    }

    //2 выводим дерево
    print(t->root);
    printf("\n");
}