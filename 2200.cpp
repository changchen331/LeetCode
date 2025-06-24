#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> answer, key_positions;
        int size = nums.size();

        for (int i = 0; i < size; i++)
            if (nums[i] == key)
                key_positions.push_back(i);
        int key_size = key_positions.size();

        for (int i = 0; i < size; i++)
        {
            int num = nums[i];

            for (int j = 0; j < key_size; j++)
            {
                if (abs(i - key_positions[j]) <= k)
                {
                    answer.push_back(i);
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    vector<int> answer = solution.findKDistantIndices(nums, key, k);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
