#include <iostream>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int answer = 0, length = s.length();
        s.push_back('e');

        int count0 = 0, count1 = 0, count = 1;
        for (int i = 1; i <= length; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (s[i - 1] == '0')
                {
                    count0 = count;
                }
                else
                {
                    count1 = count;
                }
                count = 1;

                answer += min(count0, count1);
            }
            else
                count++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "10101";

    int answer = solution.countBinarySubstrings(s);
    cout << answer << endl;

    return 0;
}
