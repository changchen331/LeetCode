#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int answer = 0, size_a = apple.size(), size_c = capacity.size();
        sort(capacity.begin(), capacity.end(), greater());

        int total = 0;
        for (auto &&a : apple)
            total += a;

        int count = 0;
        for (auto &&c : capacity)
        {
            count += c;
            answer++;
            if (count >= total)
                break;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};

    int answer = solution.minimumBoxes(apple, capacity);
    cout << answer << endl;

    return 0;
}
