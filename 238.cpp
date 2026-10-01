#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    size_t s = nums.size();
    vector<int> answer(s, INT_MIN);

    // 方法一（有溢出风险）
    // long long sum = 1;
    // int count = 0;
    // for (size_t i = 0; i < s; i++)
    // {
    //   int c = nums[i];
    //   if (c == 0)
    //   {
    //     count++;
    //     if (count > 1)
    //     {
    //       return vector<int>(s, 0);
    //     }
    //     continue;
    //   }
    //   sum *= c;
    // }

    // for (size_t i = 0; i < s; i++)
    // {
    //   if (count == 0)
    //   {
    //     answer[i] = sum / nums[i];
    //   }
    //   else
    //   {
    //     if (nums[i] == 0)
    //     {
    //       answer[i] = sum;
    //     }
    //     else
    //     {
    //       answer[i] = 0;
    //     }
    //   }
    // }

    // 方法二
    vector<int> pre(s + 1, 1);
    vector<int> suf(s + 1, 1);
    for (size_t p = 1, f = s - 1; p <= s; p++, f--)
    {
      pre[p] = pre[p - 1] * nums[p - 1];
      suf[f] = suf[f + 1] * nums[f];
    }

    for (size_t i = 0; i < s; i++)
    {
      answer[i] = pre[i] * suf[i + 1];
    }

    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> nums = {-1, 1, 0, -3, 3};

  vector<int> answer = solution.productExceptSelf(nums);
  for (size_t i = 0; i < answer.size(); i++)
  {
    cout << answer[i];
    if (i == answer.size() - 1)
    {
      cout << endl;
      break;
    }
    cout << " ";
  }

  return 0;
}
