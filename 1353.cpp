#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int answer = 0;

        // 找出最大天数
        int maximum = 0;
        for (auto &&event : events)
            maximum = max(maximum, event[1]);

        // 按照开始时间分组
        vector<vector<int>> groups(maximum + 1);
        for (auto &&event : events)
            groups[event[0]].push_back(event[1]);

        // 计算最大参与会议
        priority_queue<int, vector<int>, greater<>> pq;
        for (int day = 1; day <= maximum; day++)
        {
            // 删除过期会议
            while (!pq.empty() && pq.top() < day)
                pq.pop();

            // 新增会议
            for (auto &&group : groups[day])
                pq.push(group);

            // 参加会议
            if (!pq.empty())
            {
                answer++;
                pq.pop();
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> events{{1, 2}, {2, 3}, {3, 4}, {1, 2}};

    int answer = solution.maxEvents(events);
    cout << answer << endl;

    return 0;
}
