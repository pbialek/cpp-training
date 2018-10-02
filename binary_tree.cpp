#include<iostream>
#include<algorithm>
#include<iomanip>

template <typename T>
class Node {
    T data;
    Node* left;
    Node* right;
public:
    Node(T value) {
        data = value;
        left;
        right;
    }
    destroyNode(Node* node) {
        if(node) {
            destroyNode(node->left);
            destroyNode(node->right);

            delete node;
        }
    }

    void insert(T value) {
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

    void displayNode(Node* leaf, int indent)
    {
        if(leaf) {
            if(leaf->right) {
                displayNode(leaf->right, indent + 4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (leaf->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< leaf->data << "\n ";
            if(leaf->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                displayNode(leaf->left, indent + 4);
            }
        }
    }

    int depth(Node* node){
        return not node ? 0 : std::max(depth(node->left), depth(node->right))+1;
    }
};

template <typename T>
class BinaryTree {
    Node<T>* root;
public:
    BinaryTree(T value) {
        root = new Node<T>(value);
    }
    ~BinaryTree() {
        destroyTree();
    }

    void destroyTree() {
        root->destroyNode(root);
    }

    void insertNode(T value) {
        root->insert(value);
    }

    void displayTree() {
        root->displayNode(root, 0);
    }

    int depth() {
        root->depth(root);
    }
};

int main() {
    BinaryTree<int> tree(5);

    tree.insertNode(7);
    tree.insertNode(6);
    tree.insertNode(2);
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(9);
    tree.insertNode(14);

    tree.displayTree();

    std::cout << "\nTree depth: " << tree.depth() << std::endl;
}