#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();

        // 方法一（超时）
        // unordered_set<int> count;
        // for (int i = 0; i < size; i++)
        // {
        //     int ni = nums[i];
        //     for (int j = i; j < size; j++)
        //     {
        //         int nj = ni ^ nums[j];
        //         for (int k = j; k < size; k++)
        //         {
        //             int nk = nj ^ nums[k];
        //             count.insert(nk);
        //         }
        //     }
        // }
        // answer = count.size();

        // 方法二
        int temp = size;
        int count = 0;
        while (temp > 0)
        {
            temp >>= 1;
            count++;
        }

        if (size == 1)
        {
            answer = 1;
        }
        else if (size == 2)
        {
            answer = 2;
        }
        else
        {
            answer = 1 << count;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 1, 2};

    int answer = solution.uniqueXorTriplets(nums);
    cout << answer << endl;

    return 0;
}
