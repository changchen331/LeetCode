#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int answer = 0, size = points.size();
        unordered_map<double, map<double, int>> count1; // 斜率 -> 截距 -> 个数
        unordered_map<int, map<double, int>> count2;    // 中点 -> 截距 -> 个数

        for (int i = 1; i < size; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < i; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y1 - y2;
                int dx = x1 - x2;
                double k = dx ? 1.0 * dy / dx : INT_MAX;
                double b = dx ? 1.0 * (y1 * dx - x1 * dy) / dx : x1;
                int mid = (x1 + x2 + 2000) << 16 | (y1 + y2 + 2000); // 把二维坐标压缩成一个 int
                count1[k][b]++;                                      // 按照斜率和截距分组
                count2[mid][k]++;                                    // 按照中点和截距分组
            }
        }

        for (auto &&[_, m] : count1)
        {
            int s = 0;
            for (auto &&[_, c] : m)
            {
                answer += s * c;
                s += c;
            }
        }

        for (auto &&[_, m] : count2)
        {
            int s = 0;
            for (auto &&[_, c] : m)
            {
                answer -= s * c; // 平行四边形会统计两次，减去多统计的一次
                s += c;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> points = {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}};

    int answer = solution.countTrapezoids(points);
    cout << answer << endl;

    return 0;
}
