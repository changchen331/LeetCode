#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int answer = 0;
        int len = s.length();

        unordered_set<char> mem;
        int l = 0, r = 0;
        for (; r < len; r++)
        {
            char cur = s[r];

            if (mem.find(cur) != mem.end())
            {
                answer = max(answer, r - l);
                while (mem.find(cur) != mem.end())
                {
                    char t = s[l++];
                    mem.erase(t);
                }
            }
            mem.insert(cur);
        }
        answer = max(answer, r - l);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abcabcbb";

    int answer = solution.lengthOfLongestSubstring(s);
    cout << answer << endl;

    return 0;
}
