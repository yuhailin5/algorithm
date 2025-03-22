/*
 * @Description: 带头结点的单链表
 * @Author: 天涯过客
 * @Date: 2025-03-20 20:08:31
 */
#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

/**
 * @brief Create a List object创建一个链表
 * 
 * @return LinkList 
 */
LinkList createList() {
    LinkList L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        return NULL;
    }
    L->data = -9999;
    L->next = NULL;
    return L;
}

/**
 * @brief Create a Node object 创建一个结点
 * 
 * @param e 
 * @return LNode* 
 */
LNode* createNode(int e) {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        return NULL;
    }
    L->data = e;
    L->next = NULL;
    return L;
}

/**
 * @brief Get the Elem object 获取指定位置的元素
 * 
 * @param l 
 * @param i 
 * @return LNode* 
 */
LNode* getElem(LinkList l, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode* p = l->next;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (j == i) {
        return p;
    }
    return NULL;
}

/**
 * @brief 根据值获取结点
 * 
 * @param l 
 * @param e 
 * @return LNode* 
 */
LNode* LocateElem(LinkList l,int e) {
    LNode* p = l->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

/**
 * @brief 获取链表长度
 * 
 * @param l 
 * @return int 
 */
int length(LinkList l) {
    int cnt = 0;
    LNode* p = l->next;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/**
 * @brief 在指定位置插入元素
 * 
 * @param l 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool listInsert(LinkList &l, int i, int e) {
    if (i < 0) {
        return false;
    }
    LNode* p = getElem(l, i - 1);
    if (p == NULL) {
        return false;
    }
    LNode* added = createNode(e);
    if (added == NULL) {
        return false;
    }
    added->next = p->next;
    p->next = added;
    return true;
}


/**
 * @brief 尾插法创建链表
 * 
 * @return int 
 */
bool listInsertTail(LinkList &l, int e) {
    LNode* p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    if (p == NULL) {
        return false;
    }
    LNode* added = createNode(e);
    if (added == NULL) {
        return false;
    }
    p->next = added;
    return true;
}

/**
 * @brief 删除第i个元素
 * 
 * @param l 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool deleteElem(LinkList &l, int i, int &e) {
    if (i < 0) {
        return false;
    }
    LNode* p = getElem(l, i - 1);
    if (p == NULL||p->next == NULL) {
        return false;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}


/**
 * @brief 打印链表
 * 
 * @param l 
 */
void printList(LinkList l) {
    LNode* p = l->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/**
 * @brief 判空
 * 
 * @param l 
 * @return true 
 * @return false 
 */
bool empty(LinkList l) {
    return l->next == NULL;
}

/**
 * @brief 头插法
 * 
 * @param l 
 * @param e 
 * @return true 
 * @return false 
 */
bool listInsertHead(LinkList &l, int e) {
    LNode* added = createNode(e);
    if (added == NULL) {
        return false;
    }
    added->next = l->next;
    l->next = added;
    return true;
}

void test1() {
    LinkList L = createList();
    listInsertTail(L, 1);
    listInsertTail(L, 2);
    listInsertTail(L, 3);
    listInsertTail(L, 4);
    listInsertTail(L, 5);
    printList(L);
    cout << "length: " << length(L) << endl;
    int e;
    deleteElem(L, 3, e);
    printList(L);
    cout << "length: " << length(L) << endl;
    cout << "deleted element: " << e << endl;
}


int main() {
    test1();
    return 0;
}