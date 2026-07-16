#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        long long answer = 0;

        int size = nums.size();
        vector<int> pre(size, 1);
        int maxi = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            int &num = nums[i];
            maxi = max(maxi, num);
            pre[i] = gcd(num, maxi);
        }
        sort(pre.begin(), pre.end());

        for (int l = 0, r = size - 1; l < r; l++, r--)
        {
            int left = pre[l];
            int righ = pre[r];

            answer += gcd(left, righ);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {9, 13, 11, 10};

    long long answer = solution.gcdSum(nums);
    cout << answer << endl;

    return 0;
}
