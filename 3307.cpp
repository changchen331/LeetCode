#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        int size = operations.size();
        string str = "a";

        // 超内存
        // for (int i = 0; i < size - 1; i++)
        // {
        //     if (operations[i] == 0)
        //         str += str;
        //     else
        //     {
        //         string temp = str;
        //         for (int j = 0; j < str.length(); j++)
        //         {
        //             if (str[j] == 'z')
        //                 temp[j] = 'a';
        //             else
        //                 temp[j] += 1;
        //         }
        //         str += temp;
        //     }
        // }

        // int length = str.length();
        // int position = k - 1;
        // if (position < length)
        //     return str[position];
        // else
        // {
        //     if (operations.back() == 0)
        //         return str[position % length];
        //     else
        //         return str[position % length] == 'z' ? 'a' : str[position % length] + 1;
        // }

        // 法二
        long long m = 0;
        while ((1LL << m) < k)
            m++;

        long long position = k;
        int count = 0;

        for (int i = m; i > 0; i--)
        {
            long long half = 1LL << (i - 1);
            if (position > half)
            {
                position -= half;
                count += operations[i - 1];
            }
        }

        return char(count % 26 + 'a');
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long k = 4;
    vector<int> operations{1, 0};

    char answer = solution.kthCharacter(k, operations);
    cout << answer << endl;

    return 0;
}
