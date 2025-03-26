#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;
            int count = 0;

            for (auto &&num : nums)
            {
                if (num <= middle)
                    continue;
                // 类型转换之后再进行向上取整的操作巨慢，千万别用
                // count += ceil((double)num / (double)middle) - 1;
                // 建议使用这种方式：ceil(a/b) = (a-1/b)+1，仅针对 int 类型
                count += (num - 1) / middle;
                if (count > maxOperations)
                    break;
            }

            if (count > maxOperations)
                left = middle;
            else
                right = middle;
        }
        return right;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{9};
    int maxOperations = 2;

    int answer = solution.minimumSize(nums, maxOperations);
    cout << answer << endl;

    return 0;
}
