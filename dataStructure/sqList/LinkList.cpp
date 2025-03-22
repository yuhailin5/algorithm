/*
 * @Description: 不带头节点的单链表
 * @Author: 天涯过客
 * @Date: 2025-03-18 18:24:21
 */
#include<bits/stdc++.h>
using namespace std;


typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;


LNode* CreateNode() {
    LNode* L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        return NULL;
    }
    L->next = NULL;
    return L;
}

/**
 * @brief 获取链表长度
 * 
 * @param L 链表
 * @return int 链表长度
 */
int Length(LinkList L) {
    int cnt = 0;
    LNode* p = L;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/**
 * @brief 获取链表第i个元素
 * 
 * @param L 链表
 * @param i 第i个元素
 * @param e 第i个元素的值
 */
LNode* getElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode* p = L;
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
 * @brief 按值查找
 * 
 * @param L 
 * @param e 
 * @return LNode* 
 */
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

/**
 * @brief 尾插
 * 
 * @param L 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListInsert(LinkList &L,int e) {
    LNode* added = CreateNode();
    if (added == NULL) {
        return false;
    }
    added->data = e;
    LNode* last = getElem(L, Length(L) - 1);
    last->next = added;
    return true;
}

/**
 * @brief 删除第i个元素
 * 
 * @param L 
 * @param i 
 * @return true 
 * @return false 
 */
bool deleteElem(LinkList &L,int i,int &e) {
    if (i<0) {
        return false;
    }
    LNode* p = getElem(L, i-1);
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);    
    return true;
}

/**
 * @brief 头插法
 * 
 * @param L 
 * @param e 
 * @return true 
 * @return false 
 */
bool listInsertHead(LinkList &L, int e) {
    LNode* added = CreateNode();
    if (added == NULL) {
        return false;
    }
    added->data = e;
    added->next = L;
    L = added;
    return true;
}

/**
 * @brief 打印链表
 * 
 * @param L 
 */
void printList(LinkList L) {
    LNode* p = L;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


/**
 * @brief 判空
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool empty(LinkList L) {
    return L->next == NULL;
}

/**
 * @brief 测试创建插入删除
 * 
 */
void test1() {
    LinkList L = CreateNode();
    L->data = -1;
    for (int i = 0; i < 10; i++) {
        ListInsert(L, i);
    }
    int len = Length(L);
    cout << "Length: " << len << endl;
    LNode* p = getElem(L, 5);
    cout << "The 5th element is: " << p->data << endl;
    LNode* q = LocateElem(L, 4);
    cout << "The element 5 is: " << q->data << endl;
    int e;
    deleteElem(L, 5, e);
    printList(L);
}

/**
 * @brief 测试2 测试头插法
 * 
 */
void test2() {
    LinkList L = CreateNode();
    L->data = -1;
    for (int i = 0; i < 10; i++) {
        listInsertHead(L, i);
    }
    printList(L);
}


int main() {
    test2();


    return 0;
}