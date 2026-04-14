#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<long long>> memories;

    struct Comparator
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        }
    };

    long long dfs(vector<int> &robot, vector<vector<int>> &factory, int i, int j)
    {
        if (j < 0)
        {
            return 0; // 机器人修完了
        }
        if (i < 0)
        {
            return LLONG_MAX / 2; // 工厂没了，机器人还有
        }

        long long &response = memories[i][j];
        if (response != -1)
        {
            return response;
        }

        // 工厂 i 不修机器人
        response = dfs(robot, factory, i - 1, j);

        // 枚举 limit 个机器人
        int position = factory[i][0], limit = factory[i][1];
        long long dis_sum = 0LL;
        for (int k = 1; k <= min(j + 1, limit); k++)
        {
            dis_sum += abs(robot[j - k + 1] - position);
            response = min(response, dfs(robot, factory, i - 1, j - k) + dis_sum);
        }

        return response;
    }

public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        long long answer = 0;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), Comparator());

        int sizeR = robot.size(), sizeF = factory.size();
        memories.resize(sizeF, vector<long long>(sizeR, -1));

        answer = dfs(robot, factory, sizeF - 1, sizeR - 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> robot = {0, 4, 6};
    vector<vector<int>> factory = {{2, 2}, {6, 2}};

    long long answer = solution.minimumTotalDistance(robot, factory);
    cout << answer << endl;

    return 0;
}
