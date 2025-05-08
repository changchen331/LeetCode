#include <queue>
#include <vector>
#include <iostream>
using namespace std;

static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int size_x = moveTime.size(), size_y = moveTime[0].size();
        vector<vector<int>> dis(size_x, vector<int>(size_y, INT_MAX));
        dis[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        while (true)
        {
            auto [d, i, j] = pq.top();
            pq.pop();

            if ((i == size_x - 1) && (j == size_y - 1))
                return d;
            if (d > dis[i][j])
                continue;

            int time = 1;
            for (auto &&q : dirs)
            {
                int x = i + q[0], y = j + q[1];
                if (0 <= x && x < size_x && 0 <= y && y < size_y)
                {
                    int new_dis = max(d, moveTime[x][y]) + time;
                    if (new_dis < dis[x][y])
                        pq.emplace(dis[x][y] = new_dis, x, y);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> moveTime{{0, 4}, {4, 4}};

    int answer = solution.minTimeToReach(moveTime);
    cout << answer << endl;

    return 0;
}
