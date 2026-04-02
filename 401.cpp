#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>> times(11);
int init = []
{
    for (int h = 0; h < 12; h++)
    {
        int countH = 0, tempH = h;
        while (tempH > 0)
        {
            countH += (tempH & 1);
            tempH >>= 1;
        }

        string head = to_string(h);
        head.push_back(':');

        for (int m = 0; m < 60; m++)
        {
            int countM = 0, tempM = m;
            while (tempM > 0)
            {
                countM += (tempM & 1);
                tempM >>= 1;
            }

            string tail = "";
            if (m < 10)
            {
                tail.push_back('0');
            }
            tail += to_string(m);

            times[countH + countM].push_back(head + tail);
        }
    }

    return 0;
}();

class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        return times[turnedOn];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int turnedOn = 3;

    vector<string> answer = solution.readBinaryWatch(turnedOn);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
