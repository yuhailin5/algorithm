/*
 * @Description: 不带头节点双链表实现
 * @Author: 天涯过客
 * @Date: 2025-03-20 20:04:31
 */
#include<bits/stdc++.h>
using namespace std;


typedef struct DLNode {
    int data;
    struct DLNode *prior, *next;
}DLNode, *DLinkList;


DLNode* CreateNode(int e) {
    DLNode* L = (DLNode*)malloc(sizeof(DLNode));
    if (L == NULL) {
        return NULL;
    }
    L->data = e;
    L->prior = NULL;
    L->next = NULL;
    return L;
}

/**
 * @brief 判空
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool empty(DLinkList L) {
    return L->next == NULL && L->prior == NULL;
}

/**
 * @brief Get the Elem object获取指定位置元素
 * 
 * @param l 
 * @param i 
 * @return DLNode* 
 */
DLNode* getElem(DLinkList l, int i) {
    if (i<0) {
        return NULL;
    }
    DLNode* p = l;
    int j = 0;
    while (p != NULL && j<i) {
        p = p->next;
        j++;
    }
    if (j==i&&p!=NULL) {
        return p;
    }
    return NULL;
}

int locateElem(DLinkList l,int e) {
    
}


/**
 * @brief 指定位置插入节点
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool listInsert(DLinkList &L, int i, int e) {
}


int main() {
    return 0;
}