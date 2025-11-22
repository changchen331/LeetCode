#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (auto &&num : nums)
            answer += (num % 3) != 0;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};

    int answer = solution.minimumOperations(nums);
    cout << answer << endl;

    return 0;
}
