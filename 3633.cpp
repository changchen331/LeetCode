#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                           vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int answer = INT_MAX;

        int sizel = landStartTime.size();
        int sizew = waterStartTime.size();

        for (int i = 0; i < sizel; i++)
        {
            for (int j = 0; j < sizew; j++)
            {
                int at = landStartTime[i];
                int ad = landDuration[i];
                int bt = waterStartTime[j];
                int bd = waterDuration[j];

                int ab = (at + ad) + max(0, bt - (at + ad)) + bd;
                answer = min(answer, ab);
                int ba = (bt + bd) + max(0, at - (bt + bd)) + ad;
                answer = min(answer, ba);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};

    int answer = solution.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    cout << answer << endl;

    return 0;
}
