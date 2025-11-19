#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        int answer = original;

        unordered_set<int> numbers;
        for (auto &&num : nums)
            numbers.insert(num);

        while (numbers.find(answer) != numbers.end())
            answer *= 2;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int answer = solution.findFinalValue(nums, original);
    cout << answer << endl;

    return 0;
}
