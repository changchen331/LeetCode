#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int answer = nums[0];
    size_t size = nums.size();

    int cur = nums[0];
    for (size_t i = 1; i < size; i++)
    {

      int c = nums[i];
      if (c > cur + c)
      {
        cur = c;
      }
      else
      {
        cur += c;
      }
      answer = max(answer, cur);
    }

    answer = max(answer, cur);
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> nums = {-1, -2};

  int answer = solution.maxSubArray(nums);
  cout << answer << endl;

  return 0;
}
