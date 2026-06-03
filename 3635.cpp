#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int find_min(vector<int> &as, vector<int> &ad,
                 vector<int> &bs, vector<int> &bt)
    {
        int ff = INT_MAX;
        for (int i = 0; i < as.size(); i++)
        {
            ff = min(ff, as[i] + ad[i]);
        }

        int res = INT_MAX;
        for (int i = 0; i < bs.size(); i++)
        {
            res = min(res, (max(ff, bs[i]) + bt[i]));
        }

        return res;
    }

public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                           vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int sizel = landStartTime.size();
        int sizew = waterStartTime.size();

        int answer;
        int temp1 = find_min(landStartTime, landDuration,
                             waterStartTime, waterDuration);
        int temp2 = find_min(waterStartTime, waterDuration,
                             landStartTime, landDuration);
        answer = min(temp1, temp2);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> landStartTime = {2, 2};
    vector<int> landDuration = {4, 1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};

    int answer = solution.earliestFinishTime(landStartTime, landDuration,
                                             waterStartTime, waterDuration);
    cout << answer << endl;

    return 0;
}
