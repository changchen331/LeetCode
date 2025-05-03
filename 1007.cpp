#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int answer = 0, size = tops.size();

        vector<int> counts(7, 0);
        for (int i = 0; i < size; i++)
        {
            counts[tops[i]]++;
            counts[bottoms[i]] += (tops[i] != bottoms[i]);
        }

        int target = 0;
        for (int i = 1; i < 7; i++)
        {
            if (counts[i] == size)
            {
                target = i;
                break;
            }
        }
        if (target == 0)
            return -1;

        int temp = size;
        for (int i = 0; i < size; i++)
        {
            if (tops[i] == target)
                temp -= (tops[i] == bottoms[i]);
            else
                answer++;
        }

        return min(answer, temp - answer);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> tops{1, 2, 1, 1, 1, 2, 2, 2};
    vector<int> bottoms{2, 1, 2, 2, 2, 2, 2, 2};

    int answer = solution.minDominoRotations(tops, bottoms);
    cout << answer << endl;

    return 0;
}
