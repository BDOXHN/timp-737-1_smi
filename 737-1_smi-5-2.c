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

void init(Tree *t) {
    t->root = NULL;
}

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

void deeper(Tree* t) {
    Node* rightNodes[20];
    Node* allNodes[20];
    Node* tempFirst;
    int tempRight;
    int tempCounter;
    int i;

    tempRight = 0;
    tempCounter = 0;
    i = 1;
    tempFirst = t->root;

    //накидываем в массивы все узлы по прямому обходу
    while (tempCounter < t-> count) {
        while (tempFirst != NULL) {
            tempCounter += 1;

            if (tempFirst->r != NULL) {
                tempRight += 1;
                rightNodes[tempRight] = tempFirst->r;
            }
            allNodes[tempCounter] = tempFirst;
            tempFirst = tempFirst->l;
        }
        tempFirst = rightNodes[tempRight];
        tempRight -= 1;
    }

    while (i <= tempCounter) {
        if (i == tempCounter) {
            printf("%d", allNodes[i]->val);
        }
        else {
            printf("%d ", allNodes[i]->val);
        }
        i += 1;
    }

    printf("\n");
}

int main() {

    //1 вводим в дерево
    Tree *t = (Tree*)malloc(sizeof(Node));
    init(t);
    int putIt;

    for (int i = 1; i <= 7; i++) {
        scanf("%d", &putIt);
        insert(t, putIt);
    }

    //2 выводим дерево
    deeper(t);
}