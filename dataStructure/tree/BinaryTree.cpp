#include<bits/stdc++.h>
using namespace std;

typedef struct TNode {
    int val;
    TNode *left;
    TNode *right;
    int ltag, rtag; // 0表示指向真实孩子，1表示指向线索（前驱/后继）
} TNode, *Btree;

// 静态前驱指针，用于线索化过程
TNode *pre = nullptr;

/**
 * @brief 创建新节点
 * @param val 节点值
 * @return 新节点指针
 */
TNode* createNode(int val) {
    TNode *node = new TNode();
    node->val = val;
    node->left = node->right = nullptr;
    node->ltag = node->rtag = 0;
    return node;
}

/**
 * @brief 中序遍历（用于验证）
 * @param root 根节点
 */
void inOrder(Btree root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

/**
 * @brief 中序线索化递归函数
 * @param root 当前节点
 */
void inThread(Btree root) {
    if (root == nullptr) return;
    
    // 处理左子树
    inThread(root->left);
    
    // 处理当前节点的前驱线索
    if (root->left == nullptr) {
        root->left = pre; // 左指针指向前驱
        root->ltag = 1;
    }
    // 处理前驱节点的后继线索（当前节点是前驱的后继）
    if (pre != nullptr && pre->right == nullptr) {
        pre->right = root;
        pre->rtag = 1;
    }
    // 更新前驱为当前节点
    pre = root;
    
    // 处理右子树
    inThread(root->right);
}

/**
 * @brief 线索化后中序遍历（利用线索）
 * @param root 根节点
 */
void threadInOrder(Btree root) {
    TNode *p = root;
    // 找到中序遍历的第一个节点（最左叶子）
    while (p != nullptr && p->ltag == 0) {
        p = p->left;
    }
    
    while (p != nullptr) {
        cout << p->val << " ";
        // 如果右指针是线索，直接到后继；否则到右子树的最左节点
        if (p->rtag == 1) {
            p = p->right;
        } else {
            p = p->right;
            while (p != nullptr && p->ltag == 0) {
                p = p->left;
            }
        }
    }
    cout << endl;
}

int main() {
    // 构建测试二叉树
    //       1
    //    /    \
    //   2      3
    //  / \    / \
    // 4  5   6  7
    TNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "原始中序遍历: ";
    inOrder(root); // 输出: 4 2 5 1 6 3 7
    cout << endl;

    // 中序线索化
    inThread(root);

    cout << "线索化后中序遍历（利用线索）: ";
    threadInOrder(root); // 输出: 4 2 5 1 6 3 7

    // 验证线索：检查节点5的后继是否为1
    TNode *node5 = root->left->right;
    if (node5->rtag == 1) {
        cout << "节点5的后继是: " << node5->right->val << endl; // 应输出1
    }

    // 验证线索：检查节点1的前驱是否为5
    if (root->ltag == 1) {
        cout << "节点1的前驱是: " << root->left->val << endl; // 应输出5
    }

    return 0;
}