#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size);

        for (int i = 0; i < size; i++)
        {
            int current = nums[i];
            answer[i] = 1;

            for (int j = i - 1; j >= 0 && ((nums[j] | current) != nums[j]); j--)
            {
                nums[j] |= current;
                answer[j] = i - j + 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 0, 2, 1, 3};

    vector<int> answer = solution.smallestSubarrays(nums);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
