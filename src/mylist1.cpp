#include <iostream>
#include "mylist1.h"

using namespace std;

void InitList(list &L){
    L.length=0;
}

bool ListEmpty(list &L){
    if((L.length)==0){
        return 0;
    }
    else{
        return 1;
    }
}

void ClearList(list &L){
    L.length=0;
}

bool GetElem(list &L, int i, elemType &e){
    if(L.length==0 || i>L.length || i<=0){
        return 0;
    }
    else{
        e=L.data[i-1];
        return 1;
    }
}


int LocateElem(list &L, elemType &e){
    if(L.length==0){
        return 0;
    }
    else{
        int i=1;
        for(;i<=L.length;i++){
            if(L.data[i-1]==e){              
                break;
            }
        }
        // 未查找到元素，返回0，表示失败
        if(i>L.length){
            i=0;
        }
        return i;
    }    
}

bool ListInsert(list &L, int i, elemType &e){
    if(L.length==MAXSIZE || i<=0){
        return 0;
    }
    else{
        for(int j=L.length;j>=i;j--){
            L.data[j]=L.data[j-1];
        }
        L.data[i-1]=e;
        L.length++;
        return 1;
    }
}

bool ListDelete(list &L, int i, elemType &e){
    if(L.length==0 || i<=0 || i>(L.length)){
        return 0;
    }
    else{
        e=L.data[i-1];
        for(int j=i;j<L.length;j++){
            L.data[j-1]=L.data[j];
        }
        L.length--;
        return 1;
    }
}

int ListLength(list &L){
    return L.length;
}

// ***********************************************************************
// ***********************************************************************


/* void InitList(list* L){
    L->length=0;
}

bool ListEmpty(list *L){
    return L->length;
}

void ClearList(list *L){
    (*L).length=0;
}

bool GetElem(list *L, int i, elemType &e){
    if((*L).length==0 || i>(*L).length || i<=0){
        return 0;
    }
    else{
        e=(*L).data[i-1];
        return 1;
    }
}


int LocateElem(list *L, elemType &e){
    if((*L).length==0){
        return 0;
    }
    else{
        int i=1;
        for(;i<=(*L).length;i++){
            if((*L).data[i-1]==e){              
                break;
            }
        }
        // 未查找到元素，返回0，表示失败
        if(i>(*L).length){
            i=0;
        }
        return i;
    }    
}

bool ListInsert(list *L, int i, elemType &e){
    if((*L).length==MAXSIZE || i<=0){
        return 0;
    }
    else{
        for(int j=(*L).length;j>=i;j--){
            (*L).data[j]=(*L).data[j-1];
        }
        (*L).data[i-1]=e;
        (*L).length++;
        return 1;
    }
}

bool ListDelete(list *L, int i, elemType &e){
    if((*L).length==0 || i<=0 || i>((*L).length)){
        return 0;
    }
    else{
        e=(*L).data[i-1];
        for(int j=i;j<(*L).length;j++){
            (*L).data[j-1]=(*L).data[j];
        }
        (*L).length--;
        return 1;
    }
}

int ListLength(list *L){
    return (*L).length;
} */