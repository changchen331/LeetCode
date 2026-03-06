#include <iostream>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int answer = 0, length = n.length();

        for (int i = 0; i < length; i++)
            answer = max(answer, n[i] - '0');

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "27346209830709182346";

    int answer = solution.minPartitions(s);
    cout << answer << endl;

    return 0;
}
