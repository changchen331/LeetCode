#include <iostream>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    { 
        int answer = 0, length = s.length();
        for (int i = 1; i < length; i++)
            answer += abs(s[i] - s[i - 1]);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "zaz";

    int answer = solution.scoreOfString(s);
    cout << answer << endl;

    return 0;
}
