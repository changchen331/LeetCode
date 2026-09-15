#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> answer;
        int lens = s.length();
        int lenp = p.length();

        unordered_map<char, int> mem;
        for (int i = 0; i < lenp; i++)
        {
            mem[p[i]]++;
        }

        int l = 0, r = 0;
        while (r < lens && mem.find(s[r]) == mem.end())
        {
            l++;
            r++;
        }

        int count = 0;
        for (; r < lens; r++)
        {
            char cur = s[r];
            if (mem.find(cur) == mem.end())
            {
                count = 0;
                while (l <= r)
                {
                    char left = s[l++];
                    if (mem.find(left) != mem.end())
                    {
                        mem[left]++;
                    }
                }
            }
            else
            {
                if (mem[cur] == 0)
                {
                    while (mem[cur] == 0)
                    {
                        char left = s[l++];
                        if (mem.find(left) != mem.end())
                        {
                            mem[left]++;
                            count--;
                        }
                    }
                }
                mem[cur]--;
                count++;
                if (count == lenp)
                {
                    answer.push_back(l);
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "acdcaeccde";
    string p = "c";

    vector<int> answer = solution.findAnagrams(s, p);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i != answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
