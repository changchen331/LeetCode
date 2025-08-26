#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int answer = 0, size = dimensions.size();

        int max_dimension = pow(dimensions[0][0], 2) + pow(dimensions[0][1], 2);
        int max_area = dimensions[0][0] * dimensions[0][1];
        int index = 0;
        for (int i = 1; i < size; i++)
        {
            int plus = pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2);
            int area = dimensions[i][0] * dimensions[i][1];

            if (max_dimension > plus)
                continue;
            if (max_dimension < plus)
            {
                max_dimension = plus;
                max_area = area;
                index = i;
            }
            else if (max_area < area)
            {
                max_area = area;
                index = i;
            }
        }

        answer = max_area;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> dimensions = {{10, 3}, {5, 9}};

    int answer = solution.areaOfMaxDiagonal(dimensions);
    cout << answer << endl;

    return 0;
}
