#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int answer = 0;
        unordered_map<int, int> numbers;

        // 我的解法
        // for (auto &&num : nums)
        //     numbers[num]++;
        // for (auto &&number : numbers)
        //     answer += (number.second - 1) * number.second / 2;
        // return answer;

        // 官解
        for (auto &&num : nums)
            answer += numbers[num]++;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 1, 1, 3};

    int answer = solution.numIdenticalPairs(nums);
    cout << answer << endl;

    return 0;
}
