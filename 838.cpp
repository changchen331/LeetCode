#include <iostream>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int length = dominoes.length();
        string answer(length, '.');

        int last = -1;
        for (int i = 0; i < length; i++)
        {
            char domino = dominoes[i];

            if (last < 0)
            {
                // 目前没有出现 L 或者 R
                if (domino == 'L')
                    for (int j = last = i; j > -1; j--)
                        answer[j] = 'L';
                else if (domino == 'R')
                    answer[last = i] = domino;
            }
            else
            {
                if (domino == 'L')
                {
                    if (dominoes[last] == 'L')
                    {
                        for (int j = i; j > last; j--)
                            answer[j] = domino;
                        last = i;
                    }
                    else if (dominoes[last] == 'R')
                    {
                        for (int left = last, right = i; left < right; left++, right--)
                        {
                            answer[left] = 'R';
                            answer[right] = 'L';
                        }
                        last = i;
                    }
                }
                else if (domino == 'R')
                {
                    if (dominoes[last] == 'R')
                    {
                        for (int j = i; j > last; j--)
                            answer[j] = domino;
                        last = i;
                    }
                    else if (dominoes[last] == 'L')
                        answer[last = i] = domino;
                }
            }

            if (i == length - 1 && last >= 0 && dominoes[last] == 'R')
                for (int j = i; j > last; j--)
                    answer[j] = 'R';
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string dominoes = "LL";

    string answer = solution.pushDominoes(dominoes);
    cout << answer << endl;

    return 0;
}
