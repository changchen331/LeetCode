#include <iostream>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int answer = 0, length = s.length();

        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (s[i] == 91)
                count++;
            else if (count > 0)
                count--;
            else
            {
                answer++;
                count++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "[[[]]]][][]][[]]][[[";

    int answer = solution.minSwaps(s);
    cout << answer << endl;

    return 0;
}
