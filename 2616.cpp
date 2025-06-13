#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool possible(vector<int> &diffs, int p, int maximum)
    {
        int count = 0;

        for (int i = 0; i < diffs.size(); i++)
        {
            if (diffs[i] <= maximum)
            {
                count++;
                i++;
            }
        }

        return count >= p;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        int answer = 0, size = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> diffs(size - 1, 0);
        for (int i = 0; i < size - 1; i++)
            diffs[i] = nums[i + 1] - nums[i];

        int left = 0, right = nums.back() - nums.front();
        answer = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (possible(diffs, p, mid))
            {
                answer = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{10, 1, 2, 7, 1, 3};
    int p = 2;

    int answer = solution.minimizeMax(nums, p);
    cout << answer << endl;

    return 0;
}
