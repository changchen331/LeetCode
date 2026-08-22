#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int answer = 0;
        int size = isConnected.size();

        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (visited[i])
            {
                continue;
            }

            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < size; j++)
                {
                    int c = isConnected[cur][j];
                    if (c == 1 && !visited[j])
                    {
                        q.push(j);
                        visited[cur] = true;
                    }
                }
            }
            answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> isConnected = {{1, 0, 0},
                                       {0, 1, 0},
                                       {0, 0, 1}};

    int answer = solution.findCircleNum(isConnected);
    cout << answer << endl;

    return 0;
}
