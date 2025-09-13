#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        sort(s.begin(), s.end());
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int answer = 0, length = s.length(), max_v = 0, max_c = 0;

        char last = s[0];
        int count = 1;
        for (int i = 1; i <= length; i++)
        {
            char current = i < length ? s[i] : ' ';
            if (current != last || i == length)
            {
                if (vowels.find(last) != vowels.end())
                    max_v = max(max_v, count);
                else
                    max_c = max(max_c, count);

                last = current;
                count = 1;
            }
            else
                count++;
        }

        answer = max_v + max_c;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "eg";

    int answer = solution.maxFreqSum(s);
    cout << answer << endl;

    return 0;
}
