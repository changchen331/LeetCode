#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        int size = nums.size();

        unordered_map<int, int> count;
        for (auto &&num : nums)
        {
            int temp = num % value;
            temp < 0 ? count[temp + value]++ : count[temp]++;
        }

        for (int i = 0; i < size; i++)
        {
            if (count.find(i % value) == count.end() || count[i % value] == 0)
                return i;
            count[i % value]--;
        }

        return size;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, -3};
    int value = 4;

    // int answer = (-3) % 4; // -3
    int answer = solution.findSmallestInteger(nums, value);
    cout << answer << endl;

    return 0;
}
