#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int answer = 0, size = points.size();

        for (int i = 0; i < size - 1; i++)
        {
            vector<int> &point1 = points[i];
            vector<int> &point2 = points[i + 1];
            int x_diff = abs(point1[0] - point2[0]);
            int y_diff = abs(point1[1] - point2[1]);
            answer += max(x_diff, y_diff);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};

    int answer = solution.minTimeToVisitAllPoints(points);
    cout << answer << endl;

    return 0;
}
