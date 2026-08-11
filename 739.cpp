#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int size = temperatures.size();
        vector<int> answer(size, 0);

        vector<int> tp(101, -1);
        tp[temperatures.back()] = size - 1;
        for (int i = size - 2; i > -1; i--)
        {
            int cur = temperatures[i];
            tp[cur] = i;
            int temp = INT_MAX;
            for (int j = cur + 1; j < 101; j++)
            {
                if (tp[j] != -1)
                {
                    temp = min(temp, tp[j]);
                }
            }
            answer[i] = temp < INT_MAX ? temp - i : 0;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> answer = solution.dailyTemperatures(temperatures);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i + 1 < answer.size())
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
