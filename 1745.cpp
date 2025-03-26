#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int length = 0;
    vector<vector<int>> memory_dfs;
    vector<vector<int>> memory_check;

    bool check(string &s, int left, int right)
    {
        if (left >= right)
            return true;
        if (memory_check[left][right] != -1)
            return memory_check[left][right];
        if (s[left] != s[right])
            return memory_check[left][right] = 0;
        return memory_check[left][right] = check(s, left + 1, right - 1);
    }

    bool dfs(string &s, int remain, int left)
    {
        if (remain == 0)
            return check(s, left, length - 1);
        if (memory_dfs[remain - 1][left] != -1)
            return memory_dfs[remain - 1][left];

        bool temp;
        for (int right = length - 1 - remain; right >= left; right--)
        {
            if (!check(s, left, right))
                continue;
            if (temp = dfs(s, remain - 1, right + 1))
                break;
        }
        return memory_dfs[remain - 1][left] = temp;
    }

public:
    bool checkPartitioning(string s)
    {
        length = s.length();
        memory_dfs.resize(2, vector<int>(length, -1));
        memory_check.resize(length, vector<int>(length, -1));
        return dfs(s, 2, 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abcbdd";

    bool answer = solution.checkPartitioning(s);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
