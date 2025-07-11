#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int answer = 0, size = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const std::vector<int> &a, const std::vector<int> &b)
             {
        if (a[0] != b[0]) {
            return a[0] < b[0]; // 优先按第 0 个元素升序
        } else {
            return a[1] < b[1]; // 如果第 0 个元素相同，按第 1 个元素升序
        } });

        int current = 0;
        for (int i = 0; i < size; i++)
        {
            if (current < meetings[i][0])
                answer += meetings[i][0] - current - 1;
            current = max(current, meetings[i][1]);
        }

        return answer + days - current;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int days = 10;
    vector<vector<int>> meetings{{5, 7}, {1, 3}, {9, 10}};

    int answer = solution.countDays(days, meetings);
    cout << answer << endl;

    return 0;
}
