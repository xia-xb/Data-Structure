#include <iostream>

#include "staticlist.h"

using namespace std;

int main() {
    Component space[MAXSIZE];
    if (InitList(space)) {
        cout << "初始化成功" << endl;
    }
    cout << "链表的长度：" << ListLength(space) << endl;

    int length = 10;
    cout << "按顺序插入" << length << "个元素" << endl;
    for (int i = 1; i <= length; i++) {
        if (!ListInsert(space, i, i)) {
            cout << "插入第" << i << "个元素时出错" << endl;
        }
    }
    cout << "链表的长度：" << ListLength(space) << endl;
    cout << "打印静态链表中元素" << endl;
    int n = MAXSIZE - 1;
    for (int j = 1; j <= length; j++) {
        n = space[n].cur;
        cout << "第" << j << "个元素：" << space[n].data << endl;
    }

    cout << endl;
    cout << "在第5个元素位置插入20" << endl;
    if (!ListInsert(space, 5, 20)) {
        cout << "在第5个元素位置插入20失败" << endl;
    }
    length++;
    cout << "链表的长度：" << ListLength(space) << endl;
    cout << "打印静态链表中元素" << endl;
    n = MAXSIZE - 1;
    for (int j = 1; j <= length; j++) {
        n = space[n].cur;
        cout << "第" << j << "个元素：" << space[n].data << endl;
    }

    cout << endl;
    cout << "在第15个元素位置插入40" << endl;
    if (!ListInsert(space, 15, 40)) {
        cout << "在第15个元素位置插入40失败" << endl;
    } else {
        length++;
    }
    cout << "链表的长度：" << ListLength(space) << endl;
    cout << "打印静态链表中元素" << endl;
    n = MAXSIZE - 1;
    for (int j = 1; j <= length; j++) {
        n = space[n].cur;
        cout << "第" << j << "个元素：" << space[n].data << endl;
    }

    cout << endl;
    cout << "删除链表中第5个元素" << endl;
    if (!ListDelete(space, 5)) {
        cout << "删除链表中第5个元素失败" << endl;
    } else {
        length--;
    }
    cout << "链表的长度：" << ListLength(space) << endl;
    cout << "打印静态链表中元素" << endl;
    n = MAXSIZE - 1;
    for (int j = 1; j <= length; j++) {
        n = space[n].cur;
        cout << "第" << j << "个元素：" << space[n].data << endl;
    }

    cout << endl;
    cout << "删除链表中第15个元素" << endl;
    if (!ListDelete(space, 15)) {
        cout << "删除链表中第15个元素失败" << endl;
    } else {
        length--;
    }
    cout << "链表的长度：" << ListLength(space) << endl;
    cout << "打印静态链表中元素" << endl;
    n = MAXSIZE - 1;
    for (int j = 1; j <= length; j++) {
        n = space[n].cur;
        cout << "第" << j << "个元素：" << space[n].data << endl;
    }

    return 0;
}