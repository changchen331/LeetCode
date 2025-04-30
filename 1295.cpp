#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int answer = 0;

        for (auto &&num : nums)
        {
            int count = 0;
            while (num > 0)
            {
                count++;
                num /= 10;
            }
            answer += count % 2 == 0;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{12, 345, 2, 6, 7896};

    int answer = solution.findNumbers(nums);
    cout << answer << endl;

    return 0;
}
