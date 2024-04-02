#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right, *parent;
    int height;
};
class AvlTree {
private:
    Node *root;
    Node* newNode(int new_data) {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->left = new_node->right = NULL;
        new_node->height = 1;
        return new_node;
    }
    int height(Node *node) {
        if(node!=NULL) {
            return node->height;
        }
        else {
            return 0;
        }
    }
    int getBalanceStats(Node *node) {
        return height(node->right) - height(node->left);
    }
    Node* rotateLeft(Node *node) {
        Node *temp = node->right;
        if(temp!=NULL) {
            node->right = temp->left;
            temp->left = node;
            node->height = height(node);
            temp->height = height(temp);
        }
        return temp;
    }
    Node* rotateRight(Node *node) {
        Node *temp = node->left;
        if(temp!=NULL) {
            node->left = temp->right;
            temp->right = node;
            node->height = height(node);
            temp->height = height(temp);
        }
        return temp;
    }
public:
    AvlTree() {
        root = NULL;
    }
    Node* insert(Node* node, int new_data) {
        if(node==NULL) {
            return newNode(new_data);
        }
        if(new_data < node->data) {
            node->left = insert(node->left, new_data);
        }
        else if(new_data > node->data) {
            node->right = insert(node->right, new_data);
        }
        node->height = 1 + max(height(node->left), height(node->right)) ;
        int balance = getBalanceStats(node);
        if(balance>1 && new_data > node->right->data) {
            return rotateLeft(node);
        }
        if(balance<-1 && new_data < node->left->data) {
            return rotateRight(node);
        }
        if(balance>1 && new_data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if(balance<-1 && new_data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }
}