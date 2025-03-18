#include <iostream>
using namespace std;

/*
 * @Description: 线性表 静态数组实现
 * @Author: 天涯过客
 * @Date: 2025-03-17 22:01:18
 */
#define MAX_SIZE 10

// 定义泛型结构体 SqList
template <typename T>
struct SqList {
    T data[MAX_SIZE];
    int length;
};

// 初始化线性表
template <typename T>
void InitList(SqList<T>& l) {
    l.length = 0;
}

// 获取线性表的长度
template <typename T>
int Length(SqList<T> l) {
    return l.length;
}

// 按值查找元素，返回元素位置
template <typename T>
int LocateElem(SqList<T> l, T key) {
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == key) {
            return i + 1;
        }
    }
    return -1;
}

// 获取指定位置的元素
template <typename T>
T getElem(SqList<T> l, int i) {
    if (i < 1 || i > l.length) {
        // 这里可以考虑抛出异常或者使用更合适的错误处理方式
        return T(); 
    }
    return l.data[i - 1];
}

// 在指定位置插入元素
template <typename T>
bool ListInsert(SqList<T>& l, int i, T e) {
    if (i < 1 || i > l.length + 1) {
        return false;
    }
    if (l.length >= MAX_SIZE) {
        return false;
    }
    for (int j = l.length; j >= i; j--) {
        l.data[j] = l.data[j - 1];
    }
    l.data[i - 1] = e;
    l.length++;
    return true;
}

// 删除指定位置的元素，并返回删除的元素
template <typename T>
bool ListDelete(SqList<T>& l, int i, T& e) {
    if (i < 1 || i > l.length) {
        return false;
    }
    e = l.data[i - 1];
    for (int j = i - 1; j < l.length - 1; j++) {
        l.data[j] = l.data[j + 1];
    }
    l.length--;
    return true;
}

// 打印线性表中的元素
template <typename T>
void printList(SqList<T> l) {
    for (int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

// 判断线性表是否为空
template <typename T>
bool empty(SqList<T> l) {
    return l.length == 0;
}

// 销毁线性表
template <typename T>
bool DestroyList(SqList<T>& l) {
    l.length = 0;
    return true;
}

// 测试单元函数
void testSqList() {
    SqList<int> list;
    InitList(list);

    // 测试插入元素
    std::cout << "Testing ListInsert:" << std::endl;
    ListInsert(list, 1, 10);
    ListInsert(list, 2, 20);
    ListInsert(list, 1, 30);
    std::cout << "List after insertions: ";
    printList(list);

    // 测试获取长度
    std::cout << "Testing Length:" << std::endl;
    std::cout << "Length of the list: " << Length(list) << std::endl;

    // 测试按值查找
    std::cout << "Testing LocateElem:" << std::endl;
    int pos = LocateElem(list, 20);
    std::cout << "Position of 20 in the list: " << pos << std::endl;

    // 测试获取指定元素
    std::cout << "Testing getElem:" << std::endl;
    int elem = getElem(list, 2);
    std::cout << "Element at position 2: " << elem << std::endl;

    // 测试删除元素
    std::cout << "Testing ListDelete:" << std::endl;
    int deletedElem;
    ListDelete(list, 2, deletedElem);
    std::cout << "Element deleted: " << deletedElem << std::endl;
    std::cout << "List after deletion: ";
    printList(list);

    // 测试判断是否为空
    std::cout << "Testing empty:" << std::endl;
    std::cout << "Is the list empty? " << (empty(list) ? "Yes" : "No") << std::endl;

    // 测试销毁列表
    std::cout << "Testing DestroyList:" << std::endl;
    DestroyList(list);
    std::cout << "List after destruction: ";
    printList(list);
    std::cout << "Is the list empty after destruction? " << (empty(list) ? "Yes" : "No") << std::endl;
}

int main() {
    testSqList();
    return 0;
}