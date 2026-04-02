#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int answer = 0, size = grid.size();

        vector<int> num_of_zero(size, 0);
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > -1 && grid[i][j] == 0; j--)
            {
                num_of_zero[i]++;
            }
        }

        for (int i = 1; i < size; i++)
        {
            bool flag = false;
            for (int j = i - 1; j < size; j++)
            {
                if (num_of_zero[j] >= (size - i))
                {
                    flag = true;
                    while (j > i - 1)
                    {
                        swap(num_of_zero[j], num_of_zero[j - 1]);
                        answer++;
                        j--;
                    }
                    break;
                }
            }
            if (!flag)
            {
                return -1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{0, 0}, {0, 1}};

    int answer = solution.minSwaps(grid);
    cout << answer << endl;

    return 0;
}
