#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int answer = 0, size = startTime.size();
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        vector<int> freeTimes(size + 1, 0);
        int current = 0, length = 0, temp = 0;
        for (int i = 0; i < size + 1; i++)
        {
            freeTimes[i] = startTime[i] - current;

            if (length < k + 1)
            {
                temp += freeTimes[i];
                length++;
            }
            else
                temp += freeTimes[i] - freeTimes[i - (k + 1)];

            current = endTime[i];
            answer = max(answer, temp);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int eventTime = 64;
    int k = 2;
    vector<int> startTime = {29, 49};
    vector<int> endTime = {37, 54};

    int answer = solution.maxFreeTime(eventTime, k, startTime, endTime);
    cout << answer << endl;

    return 0;
}
