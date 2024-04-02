#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
class LinkedList {
private:
    Node *head;
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
        head = NULL;
        size = 0;
    }
    void push(int new_data) {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = head;
        head = new_node;
        size++;
    }
    void insert(int position, int new_data) {
        Node *prev = getNode(position-1);
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = prev->next;
        prev->next = new_node;
        size++;
    }
    void remove(int position) {
        if(position == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node *prev = getNode(position-1);
            Node *dlt = prev->next;
            prev->next = dlt->next;
            delete dlt;
        }
        size--;
    }
};