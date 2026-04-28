#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size(), n = grid[0].size();
        int answer = 0;

        // 扁平化数组（并排序）
        vector<int> nums;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = grid[i][j];
                if (nums.size() > 0 && num % x != nums.back() % x)
                {
                    return -1;
                }
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());

        // 计算中位数
        int size = m * n;
        int mid = nums[size / 2];

        // 计算步数
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            if ((num - mid) % x != 0)
            {
                return -1;
            }
            answer += abs(num - mid) / x;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;

    int answer = solution.minOperations(grid, x);
    cout << answer << endl;

    return 0;
}
