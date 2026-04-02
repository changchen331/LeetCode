#include <iostream>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int answer = 0, length = s.length();

        int end = length - 1;
        while (end != 0)
        {
            if (s[end] == '1')
            {
                int temp = end;
                while (temp >= 0 && s[temp] == '1')
                {
                    s[temp--] = '0';
                }
                if (temp < 0)
                {
                    s = "1" + s;
                    end++;
                }
                else
                {
                    s[temp] = '1';
                }

                answer += 2;
                end--;
            }
            else
            {
                answer += 1;
                end--;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "1111011110000011100000110001011011110010111001010111110001";

    int answer = solution.numSteps(s);
    cout << answer << endl;

    return 0;
}
