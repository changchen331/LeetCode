#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        int answer = 0;
        vector<int> characters(26, 0);

        for (auto &&c : s)
            answer += characters[c - 'a']++ == 0;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "baadccab";

    int answer = solution.minimizedStringLength(s);
    cout << answer << endl;

    return 0;
}
