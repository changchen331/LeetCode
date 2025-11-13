#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int answer = 0, length = s.length();

        int position = -1;
        bool meet0 = false;
        for (int i = length - 1; i >= 0; i--)
        {
            char c = s[i];
            if (!meet0 && c == '0')
                meet0 = true;
            else if (meet0 && c == '1')
            {
                position = i;
                break;
            }
        }

        int count = 0;
        for (; position > -1; position--)
        {
            char c = s[position];
            if (c == '0')
            {
                if (!meet0)
                    meet0 = true;
                continue;
            }
            else if (c == '1')
            {
                if (meet0)
                {
                    meet0 = false;
                    count++;
                }
                answer += count;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "1001101";

    int answer = solution.maxOperations(s);
    cout << answer << endl;

    return 0;
}
