class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.size = 1
        # 找到大于等于n的最小2的幂次（也可以直接使用4*n的空间，这里采用递归构建方式）
        while self.size < self.n:
            self.size <<= 1
        self.tree = [0] * (2 * self.size)  # 线段树数组（这里使用递归构建方式，实际空间可优化）
        self.original_arr = arr  # 保存原始数组用于构建
        self.build(1, 0, self.n - 1, arr)  # 从根节点1开始，初始区间是[0, n-1]

    def build(self, o, l, r, arr):
        """
        递归构建线段树
        o: 当前节点编号（从1开始）
        l: 当前区间左端点（原始数组下标）
        r: 当前区间右端点（原始数组下标）
        arr: 原始数组
        """
        if l == r:
            if l < len(arr):
                self.tree[o] = arr[l]  # 叶子节点赋值
            return
        mid = (l + r) // 2
        self.build(2 * o, l, mid, arr)       # 左子节点
        self.build(2 * o + 1, mid + 1, r, arr) # 右子节点
        self.tree[o] = self.tree[2 * o] + self.tree[2 * o + 1]  # 合并子节点值

    def update(self, idx, val):
        """
        单点更新：将原始数组下标idx的值修改为val（注意：这里是直接赋值，非增量更新）
        idx: 原始数组下标（从0开始）
        val: 新值
        """
        def update_helper(o, l, r):
            if l == r:
                self.tree[o] = val  # 直接赋值
                return
            mid = (l + r) // 2
            if idx <= mid:
                update_helper(2 * o, l, mid)
            else:
                update_helper(2 * o + 1, mid + 1, r)
            self.tree[o] = self.tree[2 * o] + self.tree[2 * o + 1]
        update_helper(1, 0, self.n - 1)

    def query(self, L, R):
        """
        区间查询：查询原始数组区间[L, R]的和（左闭右闭，从0开始）
        L: 区间左端点
        R: 区间右端点
        """
        def query_helper(o, l, r):
            if R < l or L > r:
                return 0
            if L <= l and r <= R:
                return self.tree[o]
            mid = (l + r) // 2
            return query_helper(2 * o, l, mid) + query_helper(2 * o + 1, mid + 1, r)
        return query_helper(1, 0, self.n - 1)


if __name__ == "__main__":
    # 测试数组：[1, 3, 5, 7, 9, 11]
    arr = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(arr)
    
    # 初始区间和查询：[0,5]的和应为36
    print("初始区间和[0,5]:", st.query(0, 5))  # 输出36
    
    # 单点更新：将下标2（值5）改为10
    st.update(2, 10)
    print("更新后区间和[0,5]:", st.query(0, 5))  # 输出1+3+10+7+9+11=41
    
    # 单点查询：下标3的值应为7
    print("单点查询[3,3]:", st.query(3, 3))  # 输出7
    
    # 区间查询：[1,4]的和应为3+10+7+9=29
    print("区间查询[1,4]:", st.query(1, 4))  # 输出29