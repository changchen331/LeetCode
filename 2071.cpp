#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int m = workers.size();

        auto check = [&](int k) -> bool
        {
            // 贪心：用最强的 k 名工人，完成最简单的 k 个任务
            int i = 0, p = pills;
            deque<int> valid_tasks;
            for (int j = m - k; j < m; j++)
            { // 枚举工人
                int w = workers[j];
                // 在吃药的情况下，把能完成的任务记录到 valid_tasks 中
                while (i < k && tasks[i] <= w + strength)
                {
                    valid_tasks.push_back(tasks[i]);
                    i++;
                }
                // 即使吃药也无法完成任务
                if (valid_tasks.empty())
                {
                    return false;
                }
                // 无需吃药就能完成（最简单的）任务
                if (w >= valid_tasks.front())
                {
                    valid_tasks.pop_front();
                    continue;
                }
                // 必须吃药
                if (p == 0)
                { // 没药了
                    return false;
                }
                p--;
                // 完成（能完成的）最难的任务
                valid_tasks.pop_back();
            }
            return true;
        };

        int left = 0, right = min((int)tasks.size(), m) + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> task{3, 2, 1};
    vector<int> workers{0, 3, 3};
    int pills = 1;
    int strength = 1;

    int answer = solution.maxTaskAssign(task, workers, pills, strength);
    cout << answer << endl;

    return 0;
}
