#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int event;
    vector<int> start, end;

    int getFree(int index)
    {
        int response = start[0];

        if (index == start.size())
            response = event - end.back();
        else if (index > 0)
            response = start[index] - end[index - 1];

        return response;
    }

public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int answer = 0, size = startTime.size();
        event = eventTime;
        start = startTime;
        end = endTime;

        // 前三大空位
        int a = 0, b = -1, c = -1;
        for (int i = 1; i <= size; i++)
        {
            int temp = getFree(i);
            if (temp > getFree(a))
            {
                c = b;
                b = a;
                a = i;
            }
            else if (b < 0 || temp > getFree(b))
            {
                c = b;
                b = i;
            }
            else if (c < 0 || temp > getFree(c))
                c = i;
        }

        // 枚举
        for (int i = 0; i < size; i++)
        {
            int time = endTime[i] - startTime[i];

            if (i != a && i + 1 != a && time <= getFree(a) ||
                i != b && i + 1 != b && time <= getFree(b) ||
                time <= getFree(c))
                answer = max(answer, getFree(i) + time + getFree(i + 1));
            else
                answer = max(answer, getFree(i) + getFree(i + 1));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int eventTime = 64;
    vector<int> startTime{29, 49};
    vector<int> endTime{37, 54};

    int answer = solution.maxFreeTime(eventTime, startTime, endTime);
    cout << answer << endl;

    return 0;
}
