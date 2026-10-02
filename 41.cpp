#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    long long answer;
    size_t s = nums.size();

    // 方法一（未达题目要求）
    // sort(nums.begin(), nums.end());
    // answer = max(1LL, 0LL + nums[s - 1] + 1);
    // bool posi = false;
    // for (size_t i = 0; i < s; i++)
    // {
    //   int c = nums[i];
    //   if (c <= 0)
    //   {
    //     continue;
    //   }

    //   if (!posi)
    //   {
    //     if (c != 1)
    //     {
    //       return 1;
    //     }
    //     posi = true;
    //     continue;
    //   }

    //   if (c == nums[i - 1])
    //   {
    //     continue;
    //   }
    //   else if (c - 1 != nums[i - 1])
    //   {
    //     return nums[i - 1] + 1;
    //   }
    // }

    // 方法二
    for (size_t i = 0; i < s;)
    {
      int &c = nums[i];
      if (c <= 0 || c > s || c == i + 1 || c == nums[c - 1])
      {
        i++;
        continue;
      }

      int temp = nums[c - 1];
      nums[c - 1] = c;
      c = temp;
    }

    for (size_t i = 0; i < s; i++)
    {
      int c = nums[i];
      if (c != i + 1)
      {
        return i + 1;
      }
    }

    answer = s + 1;
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> nums = {1};

  int answer = solution.firstMissingPositive(nums);
  cout << answer << endl;

  return 0;
}
