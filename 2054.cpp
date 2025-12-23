#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[1] < b[1];
        }
    };

    struct Comparator2
    {
        bool operator()(const pair<int, int> &a, const int &b)
        {
            return a.first < b;
        }
    };

public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int answer = 0, m = events.size(), n = events[0].size();
        sort(events.begin(), events.end(), Comparator());

        vector<pair<int, int>> st = {{0, 0}};
        for (auto &&event : events)
        {
            int start_time = event[0], value = event[2];

            auto it = --lower_bound(st.begin(), st.end(), start_time, Comparator2());
            answer = max(answer, it->second + value);

            if (value > st.back().second)
                st.emplace_back(event[1], value);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};

    int answer = solution.maxTwoEvents(events);
    cout << answer << endl;

    return 0;
}
