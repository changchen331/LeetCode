#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        long long sum1 = 0, sum2 = 0;
        bool flag1 = false, flag2 = false;

        for (int i = 0; i < size1; i++)
        {
            if (!flag1 && nums1[i] == 0)
                flag1 = true;
            sum1 += max(nums1[i], 1);
        }
        for (int i = 0; i < size2; i++)
        {
            if (!flag2 && nums2[i] == 0)
                flag2 = true;
            sum2 += max(nums2[i], 1);
        }

        if ((sum1 < sum2 && !flag1) || (sum1 > sum2 && !flag2))
            return -1;
        return max(sum1, sum2);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1{25, 29, 10, 12, 25, 26, 19, 6, 19, 10, 18};
    vector<int> nums2{0, 0, 22, 2, 17, 0, 7, 23, 22, 18, 20, 0, 13, 22, 0, 0, 0, 13, 6, 8};

    long long answer = solution.minSum(nums1, nums2);
    cout << answer << endl;

    return 0;
}
