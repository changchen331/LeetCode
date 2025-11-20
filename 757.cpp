#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void help(vector<vector<int>> &intervals, vector<vector<int>> &temp, int pos, int num)
    {
        for (int i = pos; i >= 0; i--)
        {
            if (intervals[i][1] < num)
                break;
            temp[i].push_back(num);
        }
    }

public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int res = 0;
        int n = intervals.size();
        int m = 2;
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
             { if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0]; });

        vector<vector<int>> temp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++)
            {
                res++;
                help(intervals, temp, i - 1, j);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {3, 7}, {8, 9}};

    int answer = solution.intersectionSizeTwo(intervals);
    cout << answer << endl;

    return 0;
}
