#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> Hou;
    vector<int> Hea;
    int m, n;

    bool check(int r)
    {
        int houp = 0, heap = 0;
        for (; houp < m && heap < n;)
        {
            int houc = Hou[houp];

            for (; heap < n; heap++)
            {
                int heac = Hea[heap];
                if (houc < heac)
                {
                    if (heac - houc > r)
                    {
                        return false;
                    }
                    houp++;
                    break;
                }
                else if (houc > heac)
                {
                    if (houc - heac <= r)
                    {
                        houp++;
                        break;
                    }
                }
                else
                {
                    houp++;
                    break;
                }
            }
        }
        bool resp = (houp == m);

        return resp;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int answer = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        Hou = houses;
        Hea = heaters;
        m = houses.size();
        n = heaters.size();

        int houh = houses[0], hout = houses.back();
        int heah = heaters[0], heat = heaters.back();
        int tmax = max(abs(heat - houh), abs(heat - hout));
        int tmin = max(abs(heah - houh), abs(heah - hout));

        int l = 0, r = max(tmax, tmin);
        while (l <= r)
        {
            int mid = r + (l - r) / 2;
            if (check(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        answer = l;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> houses = {1, 5};
    vector<int> heaters = {2};

    int answer = solution.findRadius(houses, heaters);
    cout << answer << endl;

    return 0;
}
