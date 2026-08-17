#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';

        stack<char> sk;

        int len = s.length();

        // 写法一
        // for (int i = 0; i < len; i++)
        // {
        //     char cur = s[i];
        //     if (cur == '(' || cur == '[' || cur == '{')
        //     {
        //         sk.push(cur);
        //     }
        //     else
        //     {
        //         if (sk.empty())
        //         {
        //             return false;
        //         }

        //         char top = sk.top();
        //         sk.pop();
        //         if (cur == ')')
        //         {
        //             if (top != '(')
        //             {
        //                 return false;
        //             }
        //         }
        //         else if (cur == ']')
        //         {
        //             if (top != '[')
        //             {
        //                 return false;
        //             }
        //         }
        //         else
        //         {
        //             if (top != '{')
        //             {
        //                 return false;
        //             }
        //         }
        //     }
        // }

        // 写法二
        for (int i = 0; i < len; i++)
        {
            char cur = s[i];
            if (mp.find(cur) != mp.end())
            {
                sk.push(cur);
            }
            else
            {
                if (sk.empty())
                {
                    return false;
                }

                char top = sk.top();
                sk.pop();
                if (mp[top] != cur)
                {
                    return false;
                }
            }
        }

        return sk.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "(";

    bool answer = solution.isValid(s);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
