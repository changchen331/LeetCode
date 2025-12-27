#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        }
    };

public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        int answer = 0, size = meetings.size();
        sort(meetings.begin(), meetings.end(), Comparator());

        priority_queue<int, vector<int>, greater<>> idle; // 会议室编号
        for (int i = 0; i < n; i++)
            idle.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> using_; // (结束时间，会议室编号)
        vector<int> cnt(n);                                                                   // 会议室的开会次数
        for (auto &&meeting : meetings)
        {
            long long start = meeting[0], end = meeting[1];

            // 在 strat 时间就空出来的会议室
            while (!using_.empty() && using_.top().first <= start)
            {
                idle.push(using_.top().second);
                using_.pop();
            }

            int temp;
            if (!idle.empty()) // 有空闲的会议室
            {
                temp = idle.top();
                idle.pop();
            }
            else // 没有空闲的会议室
            {
                auto [e, room] = using_.top();
                temp = room;
                using_.pop();
                end += e - start;
            }

            using_.emplace(end, temp); // 使用一个会议室
            cnt[temp]++;
        }

        answer = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};

    int answer = solution.mostBooked(n, meetings);
    cout << answer << endl;

    return 0;
}
