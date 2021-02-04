#include "staticlist.h"

#include <iostream>

using namespace std;

int ListLength(Component space[MAXSIZE]) {
    int n = space[MAXSIZE - 1].cur;
    int i = 0;
    while (n) {
        n = space[n].cur;
        i++;
    }
    return i;
}

int Malloc_SLL(Component space[MAXSIZE]) {
    int i = space[0].cur;
    if (i) {
        space[0].cur = space[i].cur;
        return i;
    } else {
        return 0;
    }
}

void Free_SLL(Component space[MAXSIZE], int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

bool InitList(Component spce[MAXSIZE]) {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        spce[i].cur = i + 1;
    }
    spce[MAXSIZE - 1].cur = 0;
    return 1;
}

bool ListInsert(Component space[MAXSIZE], int k, ElemType e) {
    if (k <= 0 || k > ListLength(space) + 1) {
        return 0;
    }
    int j = MAXSIZE - 1;
    for (int i = 1; i <= k - 1; i++) {
        j = space[j].cur;
    }
    int n = Malloc_SLL(space);
    space[n].data = e;
    space[n].cur = space[j].cur;
    space[j].cur = n;
    return 1;
}

bool ListDelete(Component space[MAXSIZE], int k) {
    if (k <= 0 || k > ListLength(space)) {
        return 0;
    }
    int j = MAXSIZE - 1;
    for (int i = 1; i <= k - 1; i++) {
        j = space[j].cur;
    }
    int n = space[j].cur;
    space[j].cur = space[n].cur;
    Free_SLL(space, n);
    return 1;
}