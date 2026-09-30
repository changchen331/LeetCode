#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    size_t s = nums.size();

    vector<int> temp(s, -1);
    for (size_t i = 0; i < s; i++)
    {
      int c = nums[i];
      temp[(i + k) % s] = c;
    }

    nums = temp;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  solution.rotate(nums, k);
  for (size_t i = 0; i < nums.size(); i++)
  {
    cout << nums[i];
    if (i == nums.size() - 1)
    {
      cout << endl;
    }
    cout << " ";
  }

  return 0;
}
