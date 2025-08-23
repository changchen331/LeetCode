#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int length = 0;
    string str_n = "";
    vector<vector<int>> memories;

    int dfs(int i, int mask, bool is_limit, bool is_num)
    {
        if (i == length)
            return is_num;
        if (!is_limit && is_num && memories[i][mask] != -1)
            return memories[i][mask]; // 记忆化

        int response = 0;

        if (!is_num)
            response = dfs(i + 1, mask, false, false);

        int limit = is_limit ? (str_n[i] - '0') : 9;
        for (int j = 1 - is_num; j <= limit; j++)
            if ((mask & (1 << j)) == 0)
                response += dfs(i + 1, mask | (1 << j), is_limit && j == limit, true);

        if (!is_limit && is_num)
            memories[i][mask] = response;

        return response;
    }

public:
    int countSpecialNumbers(int n)
    {
        str_n = to_string(n);
        length = str_n.length();
        vector<vector<int>> temp(length, vector<int>(1 << 10, -1));
        memories = temp;

        int answer = 0;
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
