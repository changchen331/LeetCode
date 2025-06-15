#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {
        string numStr = to_string(num);
        int size = numStr.size();

        string maximum = numStr, minimum = numStr;
        int map = -1, mip = -1;
        for (int i = 0; i < size; i++)
        {
            // 最大值
            if (map == -1 && numStr[i] < '9')
                map = i;
            if (map > -1 && numStr[i] == numStr[map])
                maximum[i] = '9';

            // 最小值
            if (mip == -1 &&
                ((i == 0 && numStr[i] > '1') ||
                 (i > 0 && (numStr[i] > '0' && !(numStr[i] == numStr[0] && numStr[0] == '1')))))
                mip = i;
            if (mip > -1 && numStr[i] == numStr[mip])
            {
                if (mip == 0 || (mip > 0 && numStr[mip] == numStr[0]))
                    minimum[i] = '1';
                else
                    minimum[i] = '0';
            }
        }

        int mini = stoi(minimum);
        return stoi(maximum) - (mini > 0 ? mini : 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int num = 1101057;

    int answer = solution.maxDiff(num);
    cout << answer << endl;

    return 0;
}
