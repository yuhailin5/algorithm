#include<bits/stdc++.h>
using namespace std;

typedef struct heap {
    int arr[100001];
    int len;
} Heap, *HeapPtr;

// 异或交换
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

/**
 * @brief 下沉交换元素
 * 
 * @param n 堆长度
 * @param i 
 */
void down(int n, int i, HeapPtr h) {
    while (i < n) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && h->arr[left] < h->arr[smallest]) {
            smallest = left;
        }
        if (right < n && h->arr[right] < h->arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(h->arr[i], h->arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

/**
 * @brief 建堆
 * 
 * @param n 堆容量
 */
void heapify(int n, HeapPtr h) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        down(n, i, h);
    }
}

/**
 * @brief 新增一个元素往上调整
 * 
 * @param i 调整位置
 */
void up(int i, HeapPtr h) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[i] < h->arr[parent]) {
            swap(h->arr[i], h->arr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

/**
 * @brief 新增元素
 * 
 * @param v 
 * @param h 
 */
void add(int v, HeapPtr h) {
    h->arr[h->len++] = v;
    up(h->len - 1, h);
}

/**
 * @brief 删除最小元素 与最后一个位置交换然后下沉
 * 
 * @param h 
 */
void deleteMin(HeapPtr h) {
    if (h->len > 0) {
        h->arr[0] = h->arr[--h->len];
        down(h->len, 0, h);
    }
}

int main() {
    Heap h;
    h.len = 0;
    int n;
    cin >> n;
    while (n--) {
        int op, a;
        cin >> op;
        switch (op) {
        case 1:
            cin >> a;
            add(a, &h);
            break;
        case 2:
            if (h.len > 0) {
                cout << h.arr[0] << endl;
            }
            break;
        case 3:
            deleteMin(&h);
            break;
        }
    }
    return 0;
}
    