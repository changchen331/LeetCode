#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int length;
    vector<int> memory;

    bool check(string &s, int start, int end)
    {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }

    void dfs(string &s, int position, int count)
    {
        if (position == length)
            return;

        for (int i = length - 1; i >= position; i--)
        {
            if (memory[i] <= count + 1)
                continue;
            if (check(s, position, i))
            {
                memory[i] = count + 1;
                dfs(s, i + 1, memory[i]);
            }
        }
    }

public:
    int minCut(string s)
    {
        length = s.length();
        memory.resize(length, INT_MAX);

        dfs(s, 0, -1);
        return memory[length - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aab";

    int answer = solution.minCut(s);
    cout << answer << endl;

    return 0;
}
