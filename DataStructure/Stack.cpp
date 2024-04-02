#include<bits/stdc++.h>
using namespace std;
struct StackNode {
    int data;
    StackNode *next;
};
class Stack {
private:
    StackNode *top;
    int size;
public:
    Stack() {
        top = NULL;
        size = 0;
    }
    void push(int new_data) {
        StackNode *new_node = new StackNode();
        new_node->data = new_data;
        new_node->next = top;
        top = new_node;
    }
    bool isEmpty() {
        return top==NULL;
    }
    void pop() {
        if(!isEmpty) {
            StackNode *temp = top;
            top = top->next;
            free(temp);
        }
    }
    int peek() {
        if(!isEmpty)
        return top->data;
    }
}