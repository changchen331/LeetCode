#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<int> answer;
        int size = invocations.size();

        vector<bool> vis(n, false);
        vector<vector<int>> sufs(n);
        for (int i = 0; i < size; i++)
        {
            int a = invocations[i][0];
            int b = invocations[i][1];
            sufs[a].emplace_back(b);
        }

        queue<int> q;
        q.push(k);
        vis[k] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            vector<int> &suf = sufs[cur];
            for (int i = 0; i < suf.size(); i++)
            {
                if (vis[suf[i]])
                {
                    continue;
                }
                vis[suf[i]] = true;
                q.push(suf[i]);
            }
        }

        bool del = true;
        for (int i = 0; i < size; i++)
        {
            int a = invocations[i][0];
            int b = invocations[i][1];
            if (!vis[a] && vis[b])
            {
                del = false;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (del && vis[i])
            {
                continue;
            }
            answer.emplace_back(i);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    int k = 1;
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};

    vector<int> answer = solution.remainingMethods(n, k, invocations);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i < answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
