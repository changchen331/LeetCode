#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long answer = 0, a, b;
        int size = nums.size();

        for (int i = 0; i < size - 2; i++)
        {
            a = (long long)nums[i];
            for (int j = i + 1; j < size - 1; j++)
            {
                b = a - (long long)nums[j];
                for (int k = j + 1; k < size; k++)
                {
                    answer = max(answer, b * (long long)nums[k]);
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{12, 6, 1, 2, 7};

    long long answer = solution.maximumTripletValue(nums);
    cout << answer << endl;

    return 0;
}