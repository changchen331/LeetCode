#include <vector>
#include <iostream>
using namespace std;

string word = "a";

int init = []()
{
    for (int i = 0; i < 9; i++)
    {
        string temp = word;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == 'z')
                temp[i] = 'a';
            else
                temp[i] += 1;
        }
        word += temp;
    }

    return 0;
}();

class Solution
{
public:
    char kthCharacter(int k)
    {
        return word[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int k = 5;

    char answer = solution.kthCharacter(k);
    cout << answer << endl;

    return 0;
}
