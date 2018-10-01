#include<iostream>
#include<algorithm>

class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node(int value) {
        data = value;
        left;
        right;
    }
    ~Node() {
        std::cout << "deleting node with value " << data << std::endl;
    }

    destroyNode(Node* node) {
        if(node) {
            destroyNode(node->left);
            destroyNode(node->right);

            delete node;
        }
    }

    void insert(int value) {
        if(value < data) {
            if(not left) {
                left = new Node(value);
            } else {
                left->insert(value);
            }
        }
        else {
            if(not right) {
                right = new Node(value);
            } else {
                right->insert(value);
            }
        }
    }

    void displayNodes() {
        if(left) {
            std::cout << data << "->" << " left: " << left->data << std::endl;
            left->displayNodes();
        }
        if(right) {
            std::cout << data << "->" << " right: " << right->data << std::endl;
            right->displayNodes();
        }
    }

    int branch(Node* node){
        return not node ? 0 : std::max(branch(node->left), branch(node->right))+1;
    }
};

class BinaryTree {
    Node* root;
public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    ~BinaryTree() {
        std::cout << "destroying Tree" << std::endl;
        destroyTree();
    }

    void destroyTree() {
        root->destroyNode(root);
    }

    void insertNode(int value) {
        root->insert(value);
    }

    void displayTree() {
        root->displayNodes();
    }

    int depth() {
        root->branch(root);
    }
};

int main() {
    BinaryTree tree(5);

    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(9);
    tree.insertNode(14);

    tree.displayTree();

    std::cout << "\nTree depth: " << tree.depth() << std::endl;
}