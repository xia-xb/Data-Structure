
#include <iostream>

#include "queue2.h"

using namespace std;

int main() {
    LinkQueue que;
    if (que.IsEmpty()) {
        cout << "创建空队列成功" << endl;
        cout << "队列的长度为：" << que.length() << endl;
    }

    cout << "依次插入5个元素" << endl;
    for (int i = 1; i <= 5; i++) {
        if (que.QueueInsert(i) && i == 5) {
            cout << "插入元素成功" << endl;
            cout << "队列的长度为：" << que.length() << endl;
        }
    }
    cout << "队列头元素：" << que.GetHead() << endl;

    cout << "删除队列中一个元素" << endl;
    QElemType e;
    if (que.QueueDelete(e)) {
        cout << "删除成功" << endl;
        cout << "队列的长度为：" << que.length() << endl;
    }
    cout << "队列头元素：" << que.GetHead() << endl;

    cout<<"清空队列"<<endl;
    if(que.ClearQueue()&&que.IsEmpty()){
        cout<<"清空成功"<<endl;
        cout << "队列的长度为：" << que.length() << endl;
    }

    cout<<"销毁队列"<<endl;
    if(que.DestoryQueue()){
        cout<<"销毁队列成功"<<endl;
    }
    return 0;
}