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

void backTree(Node* root) {
    if (root) {
        backTree(root->l);
        backTree(root->r);
        if (root->par == NULL) {
            printf("%d", root->val);
        }
        else {
            printf("%d ", root->val);
        }
    }
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
    backTree(t->root);
    printf("\n");
}