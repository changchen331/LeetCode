#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        sort(nums.begin(), nums.end());

        nums.push_back(-1);
        int maximum = 0, record = nums[0], count = 1;
        for (int i = 1; i <= size; i++)
        {
            int current = nums[i];
            if (current != record)
            {
                if (count > maximum)
                {
                    maximum = count;
                    answer = count;
                }
                else if (count == maximum)
                    answer += count;

                record = current;
                count = 1;
            }
            else
                count++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 1, 4};

    int answer = solution.maxFrequencyElements(nums);
    cout << answer << endl;

    return 0;
}
