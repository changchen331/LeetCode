#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int answer = -1;
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }

        int l = nums[0], r = nums.back();
        if (l == r)
        {
            if (1 < k && k < size)
            {
                return -1;
            }
        }

        int maxi = max(l, r);
        vector<int> count(51, 0);
        count[l]++;
        count[r]++;
        for (int i = 1; i < size - 1; i++)
        {
            int cur = nums[i];
            maxi = max(maxi, cur);
            count[cur]++;

            if (cur == l)
            {
                l = -1;
            }
            else if (cur == r)
            {
                r = -1;
            }
        }

        if (k == 1)
        {
            for (int i = 50; i > -1; i--)
            {
                int c = count[i];
                if (c == 0)
                {
                    continue;
                }

                if (c == 1)
                {
                    answer = i;
                    break;
                }
            }
        }
        else if (k == size)
        {
            answer = maxi;
        }
        else
        {
            answer = max(l, r);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1, 6, 1, 8, 4, 2};
    int k = 1;

    int answer = solution.largestInteger(nums, k);
    cout << answer << endl;

    return 0;
}
