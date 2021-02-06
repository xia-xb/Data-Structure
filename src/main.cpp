#include <iostream>

#include "cirlist.h"

using namespace std;

int main() {
    Node list;
    if (InitList(list)) {
        cout << "初始化成功" << endl;
        cout << "循环链表的长度为：" << ListLength(list) << endl;
    }

    cout << endl << "依次插入10个数据元素" << endl;
    for (int i = 1; i <= 10; i++) {
        if (ListInsert(list, i, i) && i == 10) {
            cout << "插入成功" << endl;
        }
    }
    cout << "循环链表的长度为：" << ListLength(list) << endl;
    cout << "打印循环链表" << endl;
    for (int i = 1; i <= ListLength(list); i++) {
        int e = 0;
        if (GetElem(list, i, e)) {
            cout << "第" << i << "个元素为：" << e << endl;
        }
        cout << endl;
    }

    cout << "在循环链表中第5个元素位置插入20" << endl;
    ElemType e = 20;
    if (ListInsert(list, 5, e)) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }
    cout << "循环链表的长度为：" << ListLength(list) << endl;
    cout << "打印循环链表" << endl;
    for (int i = 1; i <= ListLength(list); i++) {
        int e = 0;
        if (GetElem(list, i, e)) {
            cout << "第" << i << "个元素为：" << e << endl;
        }
        cout << endl;
    }

    cout << "在循环链表中第15个元素位置插入40" << endl;
    e = 40;
    if (ListInsert(list, 15, e)) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }
    cout << "循环链表的长度为：" << ListLength(list) << endl;
    cout << "打印循环链表" << endl;
    for (int i = 1; i <= ListLength(list); i++) {
        int e = 0;
        if (GetElem(list, i, e)) {
            cout << "第" << i << "个元素为：" << e << endl;
        }
        cout << endl;
    }

    cout << "删除循环链表中第3个元素" << endl;
    if (ListDelte(list, 3, e)) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
    }
    cout << "循环链表的长度为：" << ListLength(list) << endl;
    cout << "打印循环链表" << endl;
    for (int i = 1; i <= ListLength(list); i++) {
        int e = 0;
        if (GetElem(list, i, e)) {
            cout << "第" << i << "个元素为：" << e << endl;
        }
        cout << endl;
    }

    cout << "删除循环链表中第13个元素" << endl;
    if (ListDelte(list, 13, e)) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
    }
    cout << "循环链表的长度为：" << ListLength(list) << endl;
    cout << "打印循环链表" << endl;
    for (int i = 1; i <= ListLength(list); i++) {
        int e = 0;
        if (GetElem(list, i, e)) {
            cout << "第" << i << "个元素为：" << e << endl;
        }
        cout << endl;
    }

    return 0;
}