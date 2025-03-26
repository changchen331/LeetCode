#include <iostream>
using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        int answer = 0;

        string str_num = to_string(num);
        int length = str_num.length();
        for (int i = 0; i <= length - k; i++)
        {
            int temp = stoi(str_num.substr(i, k));
            if (temp > 0 && num % temp == 0)
                answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int num = 430043;
    int k = 2;

    int answer = solution.divisorSubstrings(num, k);
    cout << answer << endl;

    return 0;
}
