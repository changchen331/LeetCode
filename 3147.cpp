#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int answer = INT_MIN, size = energy.size();

        for (int i = 1; i <= k; i++)
        {
            answer = max(answer, energy[size - i]);
            int position = size - i - k;
            while (position >= 0)
            {
                energy[position] += energy[position + k];
                answer = max(answer, energy[position]);
                position -= k;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    int answer = solution.maximumEnergy(energy, k);
    cout << answer << endl;

    return 0;
}
