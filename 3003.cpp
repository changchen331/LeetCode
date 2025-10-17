#include <cstdint>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    string str;
    int kk;
    unordered_map<long long, int> memo;

    int popcount(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n &= n - 1; // 清除最低位的1
            count++;
        }
        return count;
    }

    int dfs(int i, int mask, bool changed)
    {
        if (i == str.length())
            return 1;

        // 把参数压缩到一个 long long 中，方便作为哈希表的 key
        long long args = (long long)i << 32 | mask << 1 | changed;
        auto it = memo.find(args);
        if (it != memo.end())
            return it->second; // 之前计算过

        int res;
        // 不改 s[i]
        int bit = 1 << (str[i] - 'a');
        int new_mask = mask | bit;
        // 分割出一个子串，这个子串的最后一个字母在 i-1
        // s[i] 作为下一段的第一个字母，也就是 bit 作为下一段的 mask 的初始值
        if (popcount((uint32_t)new_mask) > kk)
            res = dfs(i + 1, bit, changed) + 1;
        else
            res = dfs(i + 1, new_mask, changed); // 不分割

        if (!changed)
        {
            // 枚举把 s[i] 改成 a,b,c,...,z
            for (int j = 0; j < 26; j++)
            {
                new_mask = mask | (1 << j);
                // 分割出一个子串，这个子串的最后一个字母在 i-1
                // j 作为下一段的第一个字母，也就是 1<<j 作为下一段的 mask 的初始值
                if (popcount((uint32_t)new_mask) > kk)
                    res = max(res, dfs(i + 1, 1 << j, true) + 1);
                else
                    res = max(res, dfs(i + 1, new_mask, true)); // 不分割
            }
        }

        return memo[args] = res; // 记忆化
    }

public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        str = s;
        kk = k;

        return dfs(0, 0, false);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "baacccb";
    int k = 1;

    int answer = solution.maxPartitionsAfterOperations(s, k);
    cout << answer << endl;

    return 0;
}
