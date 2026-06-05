#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    string low, high, str;
    int Limit, diff;
    vector<long long> memories;

    // 基础版（不支持前导零）
    long long dfs(int i, bool limit_low, bool limit_high)
    {
        if (i == high.length())
        {
            // 成功构造一个完整的数字（所有位都填完了）
            return 1;
        }
        if (!limit_low && !limit_high && (memories[i] != -1))
        {
            return memories[i];
        }

        // 第 i 个数位可以从 l 枚举到 h
        // 如果对数位还有其它约束，应当只在下面的 for 循环做限制，不应修改 l 或 h
        int l = limit_low ? low[i] - '0' : 0;
        int h = limit_high ? high[i] - '0' : 9;

        long long response = 0;
        if (i < diff)
        {
            for (int d = l; d <= min(Limit, h); d++)
            {
                response += dfs(i + 1, limit_low && (d == l), limit_high && (d == h));
            }
        }
        else
        {
            // 当前位置只能填指定数字
            int x = str[i - diff] - '0';
            if (l <= x && x <= h && x <= Limit)
            {
                response = dfs(i + 1, limit_low && (x == l), limit_high && (x == h));
            }
        }

        if (!limit_low && !limit_high)
        {
            memories[i] = response;
        }

        return response;
    }

    // 拓展版（支持前导零）
    // is_num: 前面是否填了非零的数字
    long long dfs_pro(int i, bool limit_low, bool limit_high, bool is_num)
    {
        if (i == high.length())
        {
            // 成功构造一个完整的数字（所有位都填完了）
            return 1;
        }
        if (!limit_low && !limit_high && (memories[i] != -1))
        {
            return memories[i];
        }

        // 第 i 个数位可以从 l 枚举到 h
        // 如果对数位还有其它约束，应当只在下面的 for 循环做限制，不应修改 l 或 h
        int l = limit_low ? low[i] - '0' : 0;
        int h = limit_high ? high[i] - '0' : 9;

        long long response = 0;
        if (!is_num && low[i] == '0')
        {
            response = dfs_pro(i + 1, false, false, true);
        }

        int d0 = is_num ? 0 : 1;
        if (i < diff)
        {
            for (int d = max(l, d0); d <= min(h, Limit); d++)
            {
                response += dfs_pro(i + 1, limit_low && (d == l), limit_high && (d == h), false);
            }
        }
        else
        {
            // 当前位置只能填指定数字
            int x = str[i - diff] - '0';
            if (max(l, d0) <= x && x <= min(h, Limit))
            {
                response = dfs_pro(i + 1, limit_low && (x == l), limit_high && (x == h), false);
            }
        }

        if (!limit_low && !limit_high)
        {
            memories[i] = response;
        }

        return response;
    }

public:
    pair<long long, long long> numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        high = to_string(finish);
        int sizeh = high.size();

        low = to_string(start);
        // 补前导零，和 high 对齐
        low = string(sizeh - low.size(), '0') + low;

        str = s;

        Limit = limit;
        // 前缀部分长度（可自由填充数字的长度）
        diff = sizeh - s.size();

        memories.resize(high.length(), -1);

        long long answer = dfs(0, true, true);
        long long answer_pro = dfs_pro(0, true, true, false);
        return {answer, answer_pro};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string s = "124";

    pair<long long, long long> answer = solution.numberOfPowerfulInt(start, finish, limit, s);
    cout << answer.first << " " << answer.second << endl;

    return 0;
}
