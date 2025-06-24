#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int answer = 0, length = s.length();

        vector<int> count(4, 0);
        for (int i = 0; i < length; i++)
        {
            char c = s[i];
            switch (c)
            {
            case 'N':
                count[0]++;
                break;
            case 'S':
                count[1]++;
                break;
            case 'W':
                count[2]++;
                break;
            case 'E':
                count[3]++;
                break;
            }

            // 当前的距离
            int currentDis = abs(count[0] - count[1]) + abs(count[2] - count[3]);
            // 选择需要修改的路
            int possibleChange = min(count[0], count[1]) + min(count[2], count[3]);
            // 进行修改
            int changeCount = min(possibleChange, k) * 2;
            // 重新计算距离
            answer = max(answer, currentDis + changeCount);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "WEWE";
    int k = 1;

    int answer = solution.maxDistance(s, k);
    cout << answer << endl;

    return 0;
}
