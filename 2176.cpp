#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int answer = 0, size = nums.size();

        for (int i = 0; i < size - 1; i++)
        {
            int &num = nums[i];
            for (int j = i + 1; j < size; j++)
                if (num == nums[j] && i * j % k == 0)
                    answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    int answer = solution.countPairs(nums, k);
    cout << answer << endl;

    return 0;
}
