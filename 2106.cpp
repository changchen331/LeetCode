#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        // 向左最远能到 fruits[left][0]
        int left = std::lower_bound(fruits.begin(), fruits.end(), startPos - k, [](const auto &f, int value)
                                    { return f[0] < value; }) -
                   fruits.begin();
        int right = left, s = 0, n = fruits.size();

        // 从 fruits[left][0] 到 startPos 的水果数
        for (; right < n && fruits[right][0] <= startPos; right++)
            s += fruits[right][1];

        int ans = s;
        // 枚举最右走到 fruits[right][0]
        for (; right < n && fruits[right][0] <= startPos + k; right++)
        {
            s += fruits[right][1];
            while (fruits[right][0] * 2 - fruits[left][0] - startPos > k && fruits[right][0] - fruits[left][0] * 2 + startPos > k)
                s -= fruits[left++][1]; // fruits[left][0] 太远了
            ans = max(ans, s);          // 更新答案最大值
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> fruits{{2, 8}, {6, 3}, {8, 6}};
    int startPos = 5;
    int k = 4;

    int answer = solution.maxTotalFruits(fruits, startPos, k);
    cout << answer << endl;

    return 0;
}
