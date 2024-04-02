#include<bits/stdc++.h>
using namespace std;
struct QNode {
    int data;
    QNode *next;
};
class Queue {
private:
    QNode *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enQueue(int new_data) {
        QNode *new_node = new QNode();
        new_node->data = new_data;
        new_node->next = NULL;
        if(rear==NULL) {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }
    void deQueue() {
        if(front==NULL) {
            return;
        }
        QNode *temp = front;
        front = front->next;
        if(front==NULL) {
            rear = NULL;
            return;
        }
        delete temp;
    }
    int peek() {
        return front->data;
    }
}