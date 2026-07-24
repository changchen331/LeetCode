#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int size = nums.size();
        int answer = 0;

        // 方法一
        // unordered_set<int> counts;
        // for (int i = 0; i < size; i++)
        // {
        //     int ii = nums[i];
        //     for (int j = i; j < size; j++)
        //     {
        //         int jj = nums[j] ^ ii;
        //         for (int k = j; k < size; k++)
        //         {
        //             int kk = nums[k] ^ jj;
        //             counts.insert(kk);
        //         }
        //     }
        // }
        // answer = counts.size();

        // 方法二
        unordered_set<int> ij;
        unordered_set<int> ijk;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                ij.insert(nums[i] ^ nums[j]);
            }
        }

        for (auto &&iijj : ij)
        {
            for (int k = 0; k < size; k++)
            {
                ijk.insert(iijj ^ nums[k]);
            }
        }
        answer = ijk.size();

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 1};

    int answer = solution.uniqueXorTriplets(nums);
    cout << answer << endl;

    return 0;
}
