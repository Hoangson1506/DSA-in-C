#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next, *prev;
};
class LinkedList {
private:
    Node *head, *tail;
    int size;
    Node* getNode(int position) {
        Node *current = head;
        while(position--) {
            current = current->next;
        }
        return current;
    }
public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
    void push(int new_data) {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = head;
        if(head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        if(tail==NULL) {
            tail = new_node;
        }
        size++;
    }
    void pushEnd(int new_data) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = NULL;
        new_node->prev = tail;
        if(tail!=NULL) {
            tail->next = new_node;
        }
        tail = new_node;
        if(head==NULL) {
            head = new_node;
        }
        size++;
    }
    void pop() {
        if(tail!=NULL) {
            Node *temp = tail;
            tail = temp->prev;
            if(tail!=NULL) {
                tail->next = NULL;
            }
            delete temp;
        }
        size--;
    }
    void popStart() {
        if(head!=NULL) {
            Node *temp = head;
            head = temp->next;
            if(head!=NULL) {
                head->prev = NULL;
            }
            delete temp;
        }
        size--;
    }
    void insert(int new_data, int position) {
        if(position==0) {
            push(new_data);
        }
        else {
            if(position==size-1) {
                pushEnd(new_data);
            }
            else {
                Node *new_node = new Node();
                new_node->data = new_data;
                Node *previous = getNode(position-1);
                new_node->next = previous->next;
                new_node->prev = previous;
                previous->next->prev = new_node;
                previous->next = new_node;
            }
        }
    }
    void remove(int position) {
        if(position==size-1) {
            pop();
        }
        else {
            if(position==0) {
                popStart();
            }
            else {
                Node *temp = getNode(position);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
};