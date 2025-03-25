#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<string>> answer;

    string check(string &s, int start, int end)
    {
        int head = start, tail = end;
        while (head < tail)
            if (s[head++] != s[tail--])
                return "";
        return s.substr(start, end - start + 1);
    }

    void dfs(string &s, vector<string> &palindromes, int position, int count)
    {
        if (count == s.length())
        {
            answer.push_back(palindromes);
            return;
        }

        for (int i = position; i < s.length(); i++)
        {
            string substr = check(s, position, i);
            if (substr != "")
            {
                palindromes.push_back(substr);
                dfs(s, palindromes, i + 1, count + (i - position + 1));
                palindromes.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        for (int i = 1; i <= s.length(); i++)
        {
            vector<string> palindromes = {check(s, 0, i - 1)};
            if (palindromes[0] != "")
                dfs(s, palindromes, i, i);
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aab";

    vector<vector<string>> answer = solution.partition(s);
    for (auto &&ans : answer)
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? ", " : "\n");

    return 0;
}
