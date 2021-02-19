#include "String.h"

#include <iostream>

struct String;

int BF(String s, String t, int pos) {
    int i = pos;
    int j = 1;
    while (i <= s[0] && j <= t[0]) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t[0]) {
        return i - t[0];
    } else {
        return 0;
    }
}

void get_next(String t, int *next) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < t[0]) {
        if (j == 0 || t[i] == t[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void get_nextval(Stirng t, int *nextval) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < t[0]) {
        if (j == 0 || t[i] == t[j]) {
            i++;
            j++;
            if (t[i] != t[i]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }
}

int Index_KMP(String s, String t, int pos) {
    int i = pos;
    int j = 1;
    int next[255];
    get_next(t, next);
    while (i < s[0] && j < t[0]) {
        if (j == 0 || s[i] == t[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > t[0]) {
        return i - t[0];
    } else {
        return 0;
    }
}