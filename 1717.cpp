#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int answer = 0;
        stack<char> stack1, stack2;
        stack1.push('E');
        stack2.push('E');

        if (x >= y)
        {
            // ab
            for (auto &&c : s)
            {
                if (stack1.top() != 'E' && stack1.top() == 'a' && c == 'b')
                {
                    answer += x;
                    stack1.pop();
                    continue;
                }
                stack1.push(c);
            }

            // ba
            while (stack1.top() != 'E')
            {
                char current = stack1.top();
                stack1.pop();

                if (current == 'b' && stack2.top() == 'a')
                {
                    stack2.pop();
                    answer += y;
                    continue;
                }
                stack2.push(current);
            }
        }
        else
        {
            // ba
            for (auto &&c : s)
            {
                if (stack1.top() != 'E' && stack1.top() == 'b' && c == 'a')
                {
                    answer += y;
                    stack1.pop();
                    continue;
                }
                stack1.push(c);
            }

            // ab
            while (stack1.top() != 'E')
            {
                char current = stack1.top();
                stack1.pop();

                if (current == 'a' && stack2.top() == 'b')
                {
                    stack2.pop();
                    answer += x;
                    continue;
                }
                stack2.push(current);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;

    int answer = solution.maximumGain(s, x, y);
    cout << answer << endl;

    return 0;
}
