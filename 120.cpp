#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int size = triangle.size();

        for (int i = size - 2; i >= 0; i--)
        {
            vector<int> &temp = triangle[i];
            for (int j = 0; j < temp.size(); j++)
                temp[j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }

        return triangle[0][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int answer = solution.minimumTotal(triangle);
    cout << answer << endl;

    return 0;
}
