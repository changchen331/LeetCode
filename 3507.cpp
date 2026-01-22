#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &nums)
    {
        bool flag = true;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                flag = false;
                break;
            }
        }

        return flag;
    }

    int find(vector<int> &nums)
    {
        int position = 0;
        int minimum = nums[0] + nums[1];

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int current = nums[i] + nums[i + 1];
            if (current < minimum)
            {
                minimum = current;
                position = i;
            }
        }

        return position;
    }

public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int answer = 0;

        int size = nums.size();

        while (!check(nums))
        {
            int position = find(nums);
            nums[position] = nums[position] + nums[position + 1];
            nums.erase(nums.begin() + position + 1);
            answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 2, 3, 1};

    int answer = solution.minimumPairRemoval(nums);
    cout << answer << endl;

    return 0;
}
