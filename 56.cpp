#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> answer;

    size_t s = intervals.size();
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int left = intervals[0][0];
    int righ = intervals[0][1];
    for (size_t i = 1; i < s; i++)
    {
      int l = intervals[i][0];
      int r = intervals[i][1];

      if (righ < l)
      {
        answer.push_back({left, righ});
        left = l;
        righ = r;
      }
      else
      {
        righ = max(righ, r);
      }
    }

    answer.push_back({left, righ});
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  vector<vector<int>> answer = solution.merge(intervals);
  for (size_t i = 0; i < answer.size(); i++)
  {
    cout << answer[i][0] << " " << answer[i][1] << endl;
  }

  return 0;
}
