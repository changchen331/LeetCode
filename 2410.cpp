#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        int answer = 0, sizeP = players.size(), sizeT = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int indexP = 0, indexT = 0;
        while (indexP < sizeP && indexT < sizeT)
        {
            if (players[indexP] <= trainers[indexT])
            {
                answer++;
                indexP++;
            }
            indexT++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> players{4, 7, 9};
    vector<int> trainers{8, 2, 5, 8};

    int answer = solution.matchPlayersAndTrainers(players, trainers);
    cout << answer << endl;

    return 0;
}
