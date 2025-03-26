#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int length = 0;
    vector<vector<int>> memory_dfs;
    vector<vector<int>> memory_change;

    int check(string &s, int left, int right)
    {
        if (left >= right)
            return 0;
        if (memory_change[left][right] > -1)
            return memory_change[left][right];
        return memory_change[left][right] = check(s, left + 1, right - 1) + (s[left] != s[right]);
    }

    int dfs(string &s, int remain, int left)
    {
        if (remain == 0)
            return check(s, left, length - 1);
        if (memory_dfs[remain][left] > -1)
            return memory_dfs[remain][left];

        int temp = INT_MAX;
        for (int right = length - 1 - remain; right >= left; right--)
            temp = min(temp, dfs(s, remain - 1, right + 1) + check(s, left, right));
        return memory_dfs[remain][left] = temp;
    }

public:
    int palindromePartition(string s, int k)
    {
        length = s.length();
        if (length == k)
            return 0;
        memory_dfs.resize(k, vector<int>(length, -1));
        memory_change.resize(length, vector<int>(length, -1));
        return dfs(s, k - 1, 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "fyhowoxzyrincxivwarjuwxrwealesxsimsepjdqsstfggjnjhilvrwwytbgsqbpnwjaojfnmiqiqnyzijfmvekgakefjaxryyml";
    int k = 32;

    int answer = solution.palindromePartition(s, k);
    cout << answer << endl;

    return 0;
}
