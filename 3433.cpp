#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(const vector<string> &a, const vector<string> &b)
        {
            if (a[1] != b[1])
                return stoi(a[1]) < stoi(b[1]);
            else
                return a[0] > b[0];
        }
    };

public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        int size = events.size();
        vector<int> answer(numberOfUsers, 0);
        vector<int> status(numberOfUsers, 0);
        sort(events.begin(), events.end(), Comparator());

        for (int i = 0; i < size; i++)
        {
            string &type = events[i][0];
            int time = stoi(events[i][1]);
            string &members = events[i][2];

            if (type == "MESSAGE")
            {
                if (members == "ALL")
                    for (auto &&ans : answer)
                        ans++;
                else if (members == "HERE")
                    for (int j = 0; j < numberOfUsers; j++)
                    {
                        int &sta = status[j];
                        if (sta > 0 && sta <= time)
                            sta = 0;
                        answer[j] += (sta == 0);
                    }
                else
                {
                    vector<int> ids;
                    members += " ";
                    string temp = "";
                    for (auto &&c : members)
                    {
                        if (isdigit(c))
                            temp += c;
                        else if (!temp.empty())
                        {
                            ids.emplace_back(stoi(temp));
                            temp = "";
                        }
                    }
                    for (auto &&id : ids)
                        answer[id]++;
                }
            }
            else
                status[stoi(members)] = time + 60;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numberOfUsers = 3;
    vector<vector<string>> events = {{"MESSAGE", "5", "HERE"}, {"OFFLINE", "10", "0"}, {"MESSAGE", "15", "HERE"}, {"OFFLINE", "18", "2"}, {"MESSAGE", "20", "HERE"}};

    vector<int> answer = solution.countMentions(numberOfUsers, events);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
