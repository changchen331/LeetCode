#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int limit;
    void dfs(vector<int> &answer, int current)
    {
        if (current > limit)
            return;

        answer.push_back(current);
        for (int i = 0; i < 10; i++)
            dfs(answer, current * 10 + i);
    }

public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> answer;

        // 我的解法
        // vector<string> temp(n);
        // for (int i = 1; i <= n; i++)
        //     temp[i - 1] = to_string(i);
        // sort(temp.begin(), temp.end());
        // for (auto &&t : temp)
        //     answer.push_back(stoi(t));

        // 解法二
        limit = n;
        for (int i = 1; i < 10; i++)
            dfs(answer, i);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    vector<int> answer = solution.lexicalOrder(n);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
