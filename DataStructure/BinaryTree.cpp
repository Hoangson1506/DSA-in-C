#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    Node* newNode(int new_data) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    void insert(Node*& node, int new_data) {
        if(node==NULL) {
            node = newNode(new_data);
            return;
        }
        if(node->data >= new_data) {
            insert(node->left, new_data);
        }
        else if(node->data < new_data) {
            insert(node->right, new_data);
        }
    }
    void printNode(Node* node) {
        if(node==NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void deleteNode(Node*& node, int dlt_data) {
        if(node==NULL) {
            return;
        }
        if(node->data>dlt_data) {
            deleteNode(node->left, dlt_data);
        }
        else if(node->data<dlt_data) {
            deleteNode(node->right, dlt_data);
        }
        else {
            if(node->left==NULL) {
                Node *temp = node->right;
                delete node;
                node = temp;
            }
            else if(node->right==NULL) {
                Node *temp = node->left;
                delete node;
                node = temp;
            }
            else {
                Node *parent = node;
                Node *succesor = parent->right;
                while(succesor->left!=NULL) {
                    parent = succesor;
                    succesor = succesor->left;
                }
                node->data = succesor->data;
                deleteNode(node->right, succesor->data);
            }
        }
    }
} 