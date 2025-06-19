#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int answer = 1, size = nums.size();
        sort(nums.begin(), nums.end());

        int minip = 0;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] - nums[minip] > k)
            {
                minip = i;
                answer++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 6, 1, 2, 5};
    int k = 2;

    int answer = solution.partitionArray(nums, k);
    cout << answer << endl;

    return 0;
}
