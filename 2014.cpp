#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Solution
{
    // 47. 全排列 II
    // 枚举从 nums 中选任意个数的所有排列，用 f 处理枚举的排列
    void permuteFunc(const string &nums, auto &&f)
    {
        int n = nums.size();
        string path;
        vector<int> on_path(n); // on_path[j] 表示 nums[j] 是否已经填入排列
        function<void()> dfs = [&]() -> void
        {
            // 如果 path*k 不是 s 的子序列，那么继续往 path 后面添加元素，更不可能是 s 的子序列
            if (!path.empty() && !f(path))
                return; // 剪枝

            if (path.size() == n)
                return;

            // 枚举 nums[j] 填入 path[i]
            for (int j = 0; j < n; j++)
            {
                // 如果 nums[j] 已填入排列，continue
                // 如果 nums[j] 和前一个数 nums[j-1] 相等，且 nums[j-1] 没填入排列，continue
                if (on_path[j] || j > 0 && nums[j] == nums[j - 1] && !on_path[j - 1])
                    continue;

                path += nums[j];    // 填入排列
                on_path[j] = true;  // nums[j] 已填入排列（注意标记的是下标，不是值）
                dfs();              // 填排列的下一个数
                on_path[j] = false; // 恢复现场
                path.pop_back();    // 恢复现场
            }
        };
        dfs();
    };

public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        // 392. 判断子序列（进阶做法）
        int n = s.size();
        vector<vector<int>> nxt(n + 1, vector<int>(26));
        fill(nxt[n].begin(), nxt[n].end(), n);
        for (int i = n - 1; i >= 0; i--)
        {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }

        auto isSubsequence = [&](const string &seq, int k) -> bool
        {
            int i = -1;
            while (k--)
            {
                for (char c : seq)
                {
                    i = nxt[i + 1][c - 'a'];
                    if (i == n)
                        return false; // c 不在 s 中，说明 seq*k 不是 s 的子序列
                }
            }
            return true;
        };

        int cnt[26]{};
        for (char c : s)
            cnt[c - 'a']++;

        string a;
        for (int i = 25; i >= 0; i--)
            a.insert(a.end(), cnt[i] / k, 'a' + i); // 倒序，这样我们可以优先枚举字典序大的排列

        string ans;
        permuteFunc(a, [&](const string &seq)
                    {
            if (!isSubsequence(seq, k)) 
                return false;
            if (seq.size() > ans.size() || seq.size() == ans.size() && seq > ans) 
                ans = seq;
            
            return true; });
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "letsleetcode";
    int k = 2;

    string answer = solution.longestSubsequenceRepeatedK(s, k);
    cout << answer << endl;

    return 0;
}
