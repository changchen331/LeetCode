#include <vector>
#include <iostream>
using namespace std;

vector<int> POWER_OF_TWO;

int init = []
{
    for (int i = 0; i < 31; i++)
        POWER_OF_TWO.emplace_back(1 << i);
    return 0;
}();

int main(int argc, char const *argv[])
{
    return 0;
}
