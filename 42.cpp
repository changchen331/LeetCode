#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int answer = 0;
        int size = height.size();

        vector<int> lmax(size, 0);
        lmax[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            int cur = height[i];
            lmax[i] = max(lmax[i - 1], cur);
        }

        vector<int> rmax(size, 0);
        rmax.back() = height.back();
        for (int i = size - 2; i > -1; i--)
        {
            int cur = height[i];
            rmax[i] = max(rmax[i + 1], cur);
        }

        for (int i = 1; i < size - 1; i++)
        {
            int cur = height[i];
            int mini = min(lmax[i], rmax[i]);
            if (cur < mini)
            {
                answer += mini - cur;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int answer = solution.trap(height);
    cout << answer << endl;

    return 0;
}
