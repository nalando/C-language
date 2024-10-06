#include <iostream>

using namespace std;

// 定義二叉樹的節點結構
struct Node {
    int data;         // 節點的數據
    Node* left;      // 指向左子樹的指針
    Node* right;     // 指向右子樹的指針

    Node(int val) : data(val), left(nullptr), right(nullptr) {} // 節點構造函數
};

// 定義二叉樹的類
class BinaryTree {
private:
    Node* root;      // 樹的根節點

    // 幫助函數：插入節點
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val); // 如果當前節點為空，創建並返回新節點
        }
        if (val < node->data) {
            node->left = insert(node->left, val); // 在左子樹中插入
        } else {
            node->right = insert(node->right, val); // 在右子樹中插入
        }
        return node;
    }

    // 前序遍歷
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " "; // 訪問根節點
            preOrder(node->left);       // 遍歷左子樹
            preOrder(node->right);      // 遍歷右子樹
        }
    }

    // 中序遍歷
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);       // 遍歷左子樹
            cout << node->data << " "; // 訪問根節點
            inOrder(node->right);      // 遍歷右子樹
        }
    }

    // 後序遍歷
    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);     // 遍歷左子樹
            postOrder(node->right);    // 遍歷右子樹
            cout << node->data << " ";  // 訪問根節點
        }
    }

    // 幫助函數：釋放節點的記憶體
    void freeTree(Node* node) {
        if (node != nullptr) {
            freeTree(node->left);      // 釋放左子樹
            freeTree(node->right);     // 釋放右子樹
            delete node;               // 釋放當前節點
        }
    }

public:
    BinaryTree() : root(nullptr) {} // 初始化空樹

    // 插入節點的接口
    void insert(int val) {
        root = insert(root, val);
    }

    // 前序遍歷的接口
    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    // 中序遍歷的接口
    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    // 後序遍歷的接口
    void postOrder() {
        postOrder(root);
        cout << endl;
    }

    // 釋放記憶體
    ~BinaryTree() {
        freeTree(root);
    }
};

// 主函數
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    return 0;
}
