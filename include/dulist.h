#ifndef DULIST_H
#define DULIST_H

typedef int ElemType;

/* struct DulNode {
    ElemType data;
    DulNode *pre;
    DulNode *next;
};

bool InitDuList(DulNode &Dulist);
int DuListLength(DulNode &Dulist);
bool DuListInsert(DulNode &Dulist, int i, ElemType &e);
bool DuListDelte(DulNode &Dulist, int i, ElemType &e);
bool GetElem(DulNode &DulNode, int i, ElemType &e); */

class Dulist {
private:
    /* data */
    Dulist *pre;
    Dulist *next;
    ElemType data;

public:
    int length;
    Dulist(/* args */);
    ~Dulist();
    bool Insert(int, ElemType &);
    bool Delete(int, ElemType &);
    bool getElem(int, ElemType &);
};

/* Dulist::Dulist()
{
}

Dulist::~Dulist()
{
} */

#endif