#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    string answer = "";

    int lens = s.length();
    int lent = t.length();
    unordered_map<char, pair<int, bool>> tar;
    unordered_map<char, int> mem;
    for (int i = 0; i < lent; i++)
    {
      tar[t[i]].first++;
    }

    int left = 0;
    int righ = 0;
    int count = tar.size();
    bool found = false;
    string temp = "";
    for (; righ < lens; righ++)
    {
      char r = s[righ];
      if (tar.find(r) == tar.end())
      {
        continue;
      }

      mem[r]++;
      if (mem[r] == tar[r].first)
      {
        tar[r].second = true;
        count--;
      }

      if (count == 0)
      {
        // 找最短子串
        while (count == 0)
        {
          char l = s[left++];
          if (mem.find(l) == mem.end())
          {
            continue;
          }

          mem[l]--;
          if (tar[l].second && mem[l] < tar[l].first)
          {
            int len = righ - left + 2;
            if (!found || len < temp.length())
            {
              temp = s.substr(left - 1, len);
              found = true;
            }
            tar[l].second = false;
            count++;
          }
        }
      }
    }

    if (count == 0 || temp != "")
    {
      answer = temp;
    }
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  string s = "ADOBECODEBANC";
  string t = "ABC";

  string answer = solution.minWindow(s, t);
  cout << answer << endl;

  return 0;
}
