#include<bits/stdc++.h>
using namespace std;

#define InitSize 10

template <typename T>
struct SqList {
    T* data;
    int length;
    int maxSize;
};

/**
 * @brief 初始化线性表
 * 
 * @tparam T 元素类型
 * @param l 线性表
 */
template <typename T>
void InitList(SqList<T>& l) {
    l.data = (T*)malloc(InitSize * sizeof(T));
    // l.data = new T[InitSize];使用new关键字也可以
    l.length = 0;
    l.maxSize = InitSize;
}

/**
 * @brief Get the Length object 获取线性表的长度
 * 
 * @param l 线性表
 * @return int 长度
 */
int getLength(SqList<int> l) {
    return l.length;
}

/**
 * @brief 获取元素的位置
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @param key 元素
 * @return int 位置
 */
template <typename T>
int LocateElem(SqList<T> l, T key) {
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] == key) {
            return i + 1;
        }
    }
    return -1;
}

/**
 * @brief Get the Elem object 获取指定位置的元素
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @param i 位置
 * @return T 元素
 */
template <typename T>
T getElem(SqList<T> l, int i) {
    if (i < 1 || i > l.length) {
        return T();
    }
    return l.data[i - 1];
}

/**
 * @brief 重新分配内存
 * 
 * @tparam T 
 * @param data 
 * @param oldSize 
 * @param newSize 
 */
template <typename T>
void resize(T* &data,int oldSize,int newSize){
    T* temp = (T*)malloc(newSize * sizeof(T));
    for(int i=0;i<oldSize;i++){
        temp[i] = data[i];
    }
    free(data);
    data = temp;
}

/**
 * @brief 在指定位置插入元素
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @param i 位置
 * @param e 元素
 * @return true 插入成功
 * @return false 插入失败
 */
template <typename T>
bool ListInsert(SqList<T>& l, int i, T e) {
    if (i < 1 || i > l.length + 1) {
        return false;
    }
    if (l.length >= l.maxSize) {
        //扩容0.75
        resize(l.data,l.maxSize,l.maxSize*1.75);
        l.maxSize = l.maxSize*1.75;
    }
    for (int j = l.length; j >= i; j--) {
        l.data[j] = l.data[j - 1];
    }
    l.data[i - 1] = e;
    l.length++;
    return true;
}

/**
 * @brief 删除指定位置的元素
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @param i 位置
 * @param e 删除的元素
 * @return true 删除成功
 * @return false 删除失败
 */
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


/**
 * @brief 打印线性表中的元素
 * 
 * @tparam T 元素类型
 * @param l 线性表
 */
template <typename T>
void printList(SqList<T> l) {
    for (int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

/**
 * @brief 判断线性表是否为空
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @return true 为空
 * @return false 不为空
 */
template <typename T>
bool empty(SqList<T> l) {
    return l.length == 0;
}

/**
 * @brief 销毁线性表
 * 
 * @tparam T 元素类型
 * @param l 线性表
 * @return true 销毁成功
 * @return false 销毁失败
 */
template <typename T>
bool DestroyList(SqList<T>& l) {
    free(l.data);
    l.length = 0;
    return true;
}

int main() {
    SqList<int> l;
    InitList(l);
    for (int i = 1; i <= 10; i++) {
        ListInsert(l, i, i);
    }
    printList(l);
    cout << "length: " << getLength(l) << endl;
    cout << "locate 5: " << LocateElem(l, 5) << endl;
    cout << "get 5: " << getElem(l, 5) << endl;
    ListDelete(l, 5, l.data[5]);
    printList(l);
    cout << "length: " << getLength(l) << endl;
    cout << "empty: " << empty(l) << endl;
    DestroyList(l);
    cout << "empty: " << empty(l) << endl;
    return 0;
}