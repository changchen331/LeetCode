#include <vector>
#include <iostream>
using namespace std;

const double EPS = 1e-9;
class Solution
{
private:
    bool dfs(vector<double> &cards)
    {
        int size = cards.size();
        if (size == 1)
            return abs(cards[0] - 24) < EPS;

        for (int i = 0; i < size; i++)
        {
            double x = cards[i];
            for (int j = i + 1; j < size; j++)
            {
                double y = cards[j];

                vector<double> situations = {x + y, x - y, y - x, x * y};
                if (abs(y) > EPS)
                    situations.push_back(x / y);
                if (abs(x) > EPS)
                    situations.push_back(y / x);

                vector<double> new_cards = cards;
                new_cards.erase(new_cards.begin() + j);
                for (auto &&situation : situations)
                {
                    new_cards[i] = situation;
                    if (dfs(new_cards))
                        return true;
                }
            }
        }

        return false;
    }

public:
    bool judgePoint24(vector<int> &cards)
    {
        bool answer = false;

        vector<double> new_cards(cards.begin(), cards.end());
        answer = dfs(new_cards);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> cards = {3, 3, 8, 8};

    bool answer = solution.judgePoint24(cards);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
