#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> min_ans;
    vector<int> max_ans;
    // 使用双端队列来维护窗口内最小值和最大值的索引 单调队列
    deque<int> q_min;
    deque<int> q_max;

    for (int i = 0; i < n; i++) {
        // 移除窗口外的元素
        if (!q_min.empty() && q_min.front() == i - k) {
            q_min.pop_front();
        }
        if (!q_max.empty() && q_max.front() == i - k) {
            q_max.pop_front();
        }

        // 维持队列内最小值递增、最大值递减且下标顺序
        while (!q_min.empty() && nums[i] < nums[q_min.back()]) {
            q_min.pop_back();
        }
        while (!q_max.empty() && nums[i] > nums[q_max.back()]) {
            q_max.pop_back();
        }

        q_min.push_back(i);
        q_max.push_back(i);

        // 当窗口大小达到 k 时，记录最小值和最大值
        if (i >= k - 1) {
            min_ans.push_back(nums[q_min.front()]);
            max_ans.push_back(nums[q_max.front()]);
        }
    }

    // 输出最小值
    for_each(min_ans.begin(), min_ans.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    // 输出最大值
    for_each(max_ans.begin(), max_ans.end(), [](int x) {
        cout << x << " ";
    });
}

int main() {
    // 输入输出加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}