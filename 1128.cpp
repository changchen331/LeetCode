#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int answer = 0, size = dominoes.size();

        // 解法一
        // for (auto &&dominoe : dominoes)
        // {
        //     if (dominoe[0] > dominoe[1])
        //     {
        //         int temp = dominoe[0];
        //         dominoe[0] = dominoe[1];
        //         dominoe[1] = temp;
        //     }
        // }

        // for (int i = 0; i < size - 1; i++)
        // {
        //     vector<int> &dominoe_left = dominoes[i];
        //     if (!dominoe_left[0])
        //         continue;

        //     int count = 1;
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         vector<int> &dominoe_right = dominoes[j];
        //         if ((dominoe_left[0] == dominoe_right[0]) &&
        //             (dominoe_left[1] == dominoe_right[1]))
        //         {
        //             dominoe_right[0] = 0;
        //             count++;
        //         };
        //     }
        //     answer += count * (count - 1) / 2;
        // }

        // 解法二
        int storage[10][10]{};

        for (auto &&dominoe : dominoes)
        {
            auto [a, b] = minmax(dominoe[0], dominoe[1]);
            answer += storage[a][b]++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> dominoes{{1, 2}, {2, 1}, {3, 4}, {5, 6}};

    int answer = solution.numEquivDominoPairs(dominoes);
    cout << answer << endl;

    return 0;
}
