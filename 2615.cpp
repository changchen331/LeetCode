#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int size = nums.size();
        vector<long long> answer(size, 0LL);

        unordered_map<int, vector<int>> memories;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            memories[num].push_back(i);
        }

        vector<long long> s(size + 1, 0);
        for (auto &&[_, memory] : memories)
        {
            int sizeM = memory.size();
            // 计算前缀和
            for (int i = 0; i < sizeM; i++)
            {
                s[i + 1] = s[i] + memory[i];
            }

            for (int i = 0; i < sizeM; i++)
            {
                long long target = memory[i];
                long long left = target * i - s[i];
                long long rght = (s[sizeM] - s[i]) - target * (sizeM - i);
                answer[target] = left + rght;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 3, 1, 1, 2};

    vector<long long> answer = solution.distance(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
