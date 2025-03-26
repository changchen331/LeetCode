#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int min_x = 0, min_1 = arrays[0][0], min_2 = INT_MAX;
        int max_x = 0, max_1 = arrays[0].back(), max_2 = INT_MIN;

        for (int i = 1; i < arrays.size(); i++)
        {
            // 最小值
            if (arrays[i][0] < min_1)
            {
                min_x = i;
                min_2 = min_1;
                min_1 = arrays[i][0];
            }
            else if (arrays[i][0] < min_2)
                min_2 = arrays[i][0];

            // 最大值
            if (arrays[i].back() > max_1)
            {
                max_x = i;
                max_2 = max_1;
                max_1 = arrays[i].back();
            }
            else if (arrays[i].back() > max_2)
                max_2 = arrays[i].back();
        }

        if (min_x == max_x)
            return (min_2 - min_1) >= (max_1 - max_2) ? (max_2 - min_1) : (max_1 - min_2);
        return max_1 - min_1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> arrays{{1, 2, 3}, {4, 5}, {1, 2, 3}};

    int answer = solution.maxDistance(arrays);
    cout << answer << endl;

    return 0;
}
