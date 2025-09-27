#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double answer = 0.0;
        int size = points.size();

        for (int i = 0; i < size - 2; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < size - 1; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                for (int k = j + 1; k < size; k++)
                {
                    int x3 = points[k][0], y3 = points[k][1];

                    // 计算面积
                    double area = 0.5 * abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
                    answer = max(answer, area);
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> points = {{4, 6}, {6, 5}, {3, 1}};

    double answer = solution.largestTriangleArea(points);
    cout << fixed << setprecision(5);
    cout << answer << endl;

    return 0;
}
