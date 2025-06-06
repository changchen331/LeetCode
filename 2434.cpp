#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string robotWithString(string s)
    {
        string answer = "";
        int length = s.length();

        vector<char> minimum(length + 1);
        minimum[length] = 'z';
        for (int i = length - 1; i >= 0; i--)
            minimum[i] = min(s[i], minimum[i + 1]);

        stack<char> chars;
        for (int i = 0; i < length; i++)
        {
            chars.push(s[i]);
            while (!chars.empty() && chars.top() <= minimum[i + 1])
            {
                answer.push_back(chars.top());
                chars.pop();
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "zza";

    string answer = solution.robotWithString(s);
    cout << answer << endl;

    return 0;
}
