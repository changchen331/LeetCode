#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        int answer = 0;

        unordered_map<int, vector<int>> mem;
        for (int i = 0; i < reservedSeats.size(); i++)
        {
            vector<int> cur = reservedSeats[i];
            mem[cur[0]].push_back(cur[1]);
        }

        for (auto &&m : mem)
        {
            vector<int> &cur = m.second;
            int size = cur.size();
            bool seat1 = true, seat2 = true, seat3 = true;
            for (int j = 0; j < size; j++)
            {
                int c = cur[j];
                if (c == 2 || c == 3)
                {
                    seat1 = false;
                }
                else if (c == 4 || c == 5)
                {
                    seat1 = false;
                    seat2 = false;
                }
                else if (c == 6 || c == 7)
                {
                    seat2 = false;
                    seat3 = false;
                }
                else if (c == 8 || c == 9)
                {
                    seat3 = false;
                }
            }

            if (seat1 && seat2 && seat3)
            {
                answer += 2;
            }
            else if (seat1 || seat3 || seat2)
            {
                answer += 1;
            }
        }

        answer += (n - mem.size()) * 2;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    vector<vector<int>> reserveSeat = {{2, 10},
                                       {3, 1},
                                       {1, 2},
                                       {2, 2},
                                       {3, 5},
                                       {4, 1},
                                       {4, 9},
                                       {2, 7}};

    int answer = solution.maxNumberOfFamilies(n, reserveSeat);
    cout << answer << endl;

    return 0;
}
