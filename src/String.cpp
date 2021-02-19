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