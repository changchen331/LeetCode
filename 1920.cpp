#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 0);

        for (int i = 0; i < size; i++)
            answer[i] = nums[nums[i]];

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{0, 2, 1, 5, 3, 4};

    vector<int> answer = solution.buildArray(nums);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
