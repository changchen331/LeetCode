#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        bool answer = false;
        int length = s.length();

        int total = 1 << k;
        unordered_set<string> strs;
        for (int i = 0; (i <= length - k) && strs.size() < total; i++)
        {
            strs.insert(s.substr(i, k));
        }

        answer = (strs.size() == total);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "00110";
    int k = 2;

    bool answer = solution.hasAllCodes(s, k);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
