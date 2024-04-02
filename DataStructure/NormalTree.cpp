#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    int height;
};
class BinaryTree {
private:
    Node *root;
    Node* find(Node *node, int key) {
        if(node == NULL) return NULL;
        if(node->data == key) return node;
        Node *temp1 = find(node->left, key);
        Node *temp2 = find(node->right, key);
        if(temp1 == NULL) {
            if(temp2 == NULL) return NULL;
            else return temp2;
        }
        else if(temp2 == NULL) {
            if(temp1 == NULL) return NULL;
            else return temp1;
        }
        return temp1;
    }
    Node* newNode(int new_data) {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->left = new_node->right = NULL;
        new_node->height = 1;
        return new_node;
    }
public:
    int getHeight(Node *node) {
        if(node == NULL) {
            return 0;
        }
        int height = 1 + max(getHeight(node->left), getHeight(node->right));
        return height;
    }
    bool isBalanced(Node *node) {
        if(node == NULL) return true;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return abs(leftHeight - rightHeight) <= 1
                && isBalanced(node->left) && isBalanced(node->right);
    }
    Node *insertNode(unordered_map<int, Node*> &tree, int data) {
        if(tree.find(data) == tree.end()) {
            tree[data] = newNode(data);
        }
        return tree[data];
    }
    void addEdges(unordered_map<int, Node*> &tree, int key, int new_data) {
        Node *parent = insertNode(tree, key);
        Node *child = insertNode(tree, new_data);
        if(parent->left == NULL) parent->left = child;
        else {
            parent->right = child;
        }
    }
};
int main() {
    int n; cin >> n;
    BinaryTree tree;
    unordered_map<int, Node*> m;
    Node *root = NULL;
    for(int i=1; i<n; i++) {
        int key, data;
        cin >> key >> data;
        tree.addEdges(m, key, data);
        if(i == 1) {
            root = m[key];
        }
    }
    if(tree.isBalanced(root)) {
        cout << "yes";
    }
    else cout << "no";
}