#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string answer = "";
        int len = s.length();

        stack<char> sk;
        for (int i = 0; i < len; i++)
        {
            char cur = s[i];
            if (cur != ']')
            {
                sk.push(cur);
            }
            else
            {
                string numb = "";
                string word = "";
                bool isNum = false;
                while (!sk.empty())
                {
                    char top = sk.top();
                    if (isNum && (top < '0' || '9' < top))
                    {
                        break;
                    }
                    sk.pop();

                    if (top == '[')
                    {
                        isNum = true;
                        continue;
                    }

                    if (!isNum)
                    {
                        word.push_back(top);
                    }
                    else
                    {
                        numb.insert(numb.begin(), top);
                    }
                }
                int num = stoi(numb);
                for (int i = 0; i < num; i++)
                {
                    for (int j = word.length() - 1; j > -1; j--)
                    {
                        sk.push(word[j]);
                    }
                }
            }
        }

        while (!sk.empty())
        {
            answer.insert(answer.begin(), sk.top());
            sk.pop();
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "10[leetcode]";

    string answer = solution.decodeString(s);
    cout << answer << endl;

    return 0;
}
