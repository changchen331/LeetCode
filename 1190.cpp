#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        string answer = "";

        int len = s.length();
        stack<char> master;
        for (int i = 0; i < len; i++)
        {
            char cur = s[i];
            if (cur != ')')
            {
                master.push(cur);
            }
            else
            {
                queue<char> temp;
                while (master.top() != '(')
                {
                    temp.push(master.top());
                    master.pop();
                }
                master.pop();

                while (!temp.empty())
                {
                    master.push(temp.front());
                    temp.pop();
                }
            }
        }

        int size = master.size();
        answer.resize(size, ' ');
        for (int i = size - 1; i > -1; i--)
        {
            answer[i] = master.top();
            master.pop();
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "(sugqlinrwj)gasmtbk";

    string answer = solution.reverseParentheses(s);
    cout << answer << endl;

    return 0;
}
