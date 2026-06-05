#include <vector>
#include <iostream>
using namespace std;

// LeetCode 2376
class Solution
{
private:
    // 返回从 i 开始填数字, i 前面填的数字的集合是 mask, 此时能构造的特殊整数的数目
    // is_limit 表示前面填的数字是否都是 n 对应位置上的, 如果为 true,则当前位置至多为 stoi(s[i]), 反之为 '0'~'9'
    // is_num 表示前面是否填了数字(是否跳过), 如果为 true, 那么当前位可以从 0 开始, 反之可以选择跳过或从 1 开始填数字
    string s;
    vector<vector<int>> memories;

    int dfs(int i, int mask, bool is_limit, bool is_num)
    {
        if (i == s.length())
        {
            // 已经达到指定长度，如果 is_num=true 表示已经构建出了一个特殊整数
            return is_num;
        }
        if (!is_limit && is_num && memories[i][mask] != -1)
        {
            return memories[i][mask]; // 之前计算过
        }

        int response = 0;
        if (!is_num)
        {
            // 选择跳过, 不填数字
            response = dfs(i + 1, mask, false, false);
        }

        // 枚举要填入的数字 j
        // 如果前面没有填数字，则必须从 1 开始（因为不能有前导零）
        // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n）
        int limit = is_limit ? (s[i] - '0') : 9;
        for (int j = 1 - is_num; j <= limit; j++)
        {
            if ((mask & (1 << j)) == 0)
            {
                // j 不在 mask 中，说明之前没有填过 j
                response += dfs(i + 1, mask | (1 << j), is_limit && j == limit, true);
            }
        }

        // 只有 !is_limit && is_num 的状态才存入 memories
        // 因为这种状态是不受 n 上限约束且已经开始了数字的“自由态”，它的后续结果是固定的，可以被后续其他分支复用
        if (!is_limit && is_num)
        {
            memories[i][mask] = response;
        }

        return response;
    }

public:
    int countSpecialNumbers(int n)
    {
        // 数位 DP
        s = to_string(n);
        int answer = 0, length = s.length();
        memories.resize(length, vector<int>(1 << 10, -1));

        answer = dfs(0, 0, true, false);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.countSpecialNumbers(n);
    cout << answer << endl;

    return 0;
}
