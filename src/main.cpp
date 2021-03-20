#include <iostream>

#include "search.h"

using namespace std;

int main() {
    HashTable1<int> h;
    h.InitializeTable(9);
    for (int i = 0; i < 9; i++) {
        h.Insert(i);
    }
    h.Output();
    h.Insert(12);
    h.Insert(13);
    h.Insert(23);
    h.Insert(21);
    h.Output();
    h.Delete(12);
    h.Delete(21);
    h.Output();
    return 0;
}