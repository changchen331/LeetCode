#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int tar;
    vector<string> answer;
    void dfs(int l, int r, string s)
    {
        if (l == tar && r == tar)
        {
            answer.push_back(s);
        }

        if (l < tar)
        {
            dfs(l + 1, r, s + '(');
        }
        if (r < tar && l > r)
        {
            dfs(l, r + 1, s + ')');
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        tar = n;
        dfs(0, 0, "");
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 8;

    vector<string> answer = solution.generateParenthesis(n);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
