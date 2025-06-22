#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int length = s.length();
        vector<string> answer((length - 1) / k + 1);

        for (int i = 0; i < length; i++)
            answer[i / k].push_back(s[i]);

        int temp = answer.back().length();
        if (temp < k)
            for (; temp < k; temp++)
                answer.back().push_back(fill);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';

    vector<string> answer = solution.divideString(s, k, fill);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
