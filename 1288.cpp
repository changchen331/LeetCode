#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            if (a[0] != b[0])
            {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        }
    };

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int size = intervals.size();
        int answer = size;

        // 方法一（穷举）
        // vector<bool> covered(size, false);
        // for (int i = 0; i + 1 < size; i++)
        // {
        //     int x1 = intervals[i][0];
        //     int y1 = intervals[i][1];
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         int x2 = intervals[j][0];
        //         int y2 = intervals[j][1];

        //         if ((x1 >= x2) && (y1 <= y2))
        //         {
        //             covered[i] = true;
        //         }
        //         else if ((x2 >= x1) && (y2 <= y1))
        //         {
        //             covered[j] = true;
        //         }
        //     }
        // }

        // for (auto &&cov : covered)
        // {
        //     answer -= cov;
        // }

        // 方法二（排序）
        // sort(intervals.begin(), intervals.end(), Comparator());
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int maximum = intervals[0][1];
        for (int i = 1; i < size; i++)
        {
            if (maximum < intervals[i][1])
            {
                maximum = intervals[i][1];
            }
            else
            {
                answer--;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> intervals = {{34335, 39239}, {15875, 91969}, {29673, 66453}, {53548, 69161}, {40618, 93111}};

    int answer = solution.removeCoveredIntervals(intervals);
    cout << answer << endl;

    return 0;
}
