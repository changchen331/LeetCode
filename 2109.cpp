#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int length = s.length(), size = spaces.size(), total = length + size;
        string answer(length + size, ' ');

        // 方法一
        // for (int i = 0, count = 0; i < size; i++, count++)
        //     s.insert(spaces[i] + count, " ");
        // return s;

        // 方法二
        for (int longP = 0, shortP = 0, i = 0; longP < total; longP++, shortP++)
        {
            if (i < size && shortP == spaces[i])
            {
                longP++;
                i++;
            }
            answer[longP] = s[shortP];
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces{8, 13, 15};

    string answer = solution.addSpaces(s, spaces);
    cout << answer << endl;

    return 0;
}
