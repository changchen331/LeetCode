#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int reverse(int num)
    {
        string str = to_string(num);

        string temp = "";
        for (int i = str.size() - 1; i >= 0; i--)
        {
            temp.push_back(str[i]);
        }

        return stoi(temp);
    }

public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        int answer = INT_MAX;
        int size = nums.size();

        unordered_map<int, vector<int>> memories;
        for (int i = 0; i < size; i++)
        {
            memories[nums[i]].push_back(i);
        }

        for (int i = 0; i < size - 1; i++)
        {
            int num = nums[i];
            int rever = reverse(num);

            if (memories.find(rever) != memories.end())
            {
                auto &memory = memories[rever];
                auto position = upper_bound(memory.begin(), memory.end(), i);
                if (position != memory.end())
                {
                    answer = min(answer, abs(i - *position));
                }
            }
        }

        return answer != INT_MAX ? answer : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {12, 21, 45, 33, 54};

    int answer = solution.minMirrorPairDistance(nums);
    cout << answer << endl;

    return 0;
}
