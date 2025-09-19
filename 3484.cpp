#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Spreadsheet
{
private:
    unordered_map<string, int> sheet;

public:
    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        sheet[cell] = value;
    }

    void resetCell(string cell)
    {
        sheet[cell] = 0;
    }

    int getValue(string formula)
    {

        int plus = formula.find('+');
        string x = formula.substr(1, plus - 1);
        string y = formula.substr(plus + 1);

        // 'A'=65，'Z'=90
        int X = (64 < x[0] && x[0] < 91) ? sheet[x] : stoi(x);
        int Y = (64 < y[0] && y[0] < 91) ? sheet[y] : stoi(y);
        return X + Y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

int main(int argc, char const *argv[])
{
    Spreadsheet *obj;
    vector<string> commands = {"Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"};
    vector<pair<string, int>> values = {{"", 3}, {"=5+7", -1}, {"A1", 10}, {"=A1+6", -1}, {"B2", 15}, {"=A1+B2", -1}, {"A1", -1}, {"=A1+B2", -1}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        auto value = values[i];

        if (command == "Spreadsheet")
        {
            obj = new Spreadsheet(value.second);
            cout << "null" << " ";
        }
        else if (command == "setCell")
        {
            obj->setCell(value.first, value.second);
            cout << "null" << " ";
        }
        else if (command == "resetCell")
        {
            obj->resetCell(value.first);
            cout << "null" << " ";
        }
        else if (command == "getValue")
            cout << obj->getValue(value.first) << " ";
    }
    cout << endl;

    return 0;
}
