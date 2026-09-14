#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int xl1 = rec1[0], yb1 = rec1[1], xr1 = rec1[2], yt1 = rec1[3];
        int xl2 = rec2[0], yb2 = rec2[1], xr2 = rec2[2], yt2 = rec2[3];

        bool x = !(xl2 >= xr1 || xr2 <= xl1);
        bool y = !(yb2 >= yt1 || yb1 >= yt2);
        return x && y;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {1, 0, 2, 1};

    bool answer = solution.isRectangleOverlap(rec1, rec2);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
