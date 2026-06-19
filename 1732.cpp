#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int answer = 0;

        int size = gain.size();
        for (int i = 0, current = answer; i < size; i++)
        {
            current += gain[i];
            answer = max(answer, current);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};

    int answer = solution.largestAltitude(gain);
    cout << answer << endl;

    return 0;
}
