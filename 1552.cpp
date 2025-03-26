#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &position, int m, int distance)
    {
        int last = position[0], count = 1;
        for (int i = 1; i < position.size(); i++)
            if (position[i] - last >= distance)
            {
                last = position[i];
                if (++count == m)
                    break;
            }
        return count == m;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());

        int left = 0;
        int right = (position.back() - position[0]) / (m - 1) + 1;
        if (m == 2)
            return right - 1;

        while (left + 1 < right)
        {
            int middle = left + (right - left) / 2;

            if (check(position, m, middle))
                left = middle;
            else
                right = middle;
        }

        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> position{1, 2, 3, 4, 7};
    int m = 3;

    int answer = solution.maxDistance(position, m);
    cout << answer << endl;

    return 0;
}
