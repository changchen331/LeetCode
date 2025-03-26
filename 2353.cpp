#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class FoodRatings
{
private:
    unordered_map<string, set<pair<int, string>>> countries; // 国家, <评分的负数, 菜品>
    unordered_map<string, pair<int, string>> find_country;   // 菜品, <评分的负数, 国家>

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            string &food = foods[i], &cuisine = cuisines[i];
            countries[cuisine].emplace(-ratings[i], food);
            find_country[food] = {-ratings[i], cuisine};
        }
    }

    void changeRating(string food, int newRating)
    {
        auto &[rating, country] = find_country[food];
        set<pair<int, string>> &current = countries[country];
        current.erase({rating, food});
        rating = -newRating;
        current.emplace(rating, food);
    }

    string highestRated(string cuisine)
    {
        return countries[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(int argc, char const *argv[])
{
    FoodRatings *food_ratings;
    vector<string> commands{"FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"};
    vector<vector<vector<string>>> values{
        {{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"}, {"korean", "japanese", "japanese", "greek", "japanese", "korean"}, {"9", "12", "8", "15", "14", "7"}},
        {{"korean"}},
        {{"japanese"}},
        {{"sushi", "16"}},
        {{"japanese"}},
        {{"ramen", "16"}},
        {{"japanese"}}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        vector<vector<string>> value = values[i];
        if (command == "highestRated")
            cout << "\"" << food_ratings->highestRated(value[0][0]) << "\"";
        else if (command == "changeRating")
        {
            food_ratings->changeRating(value[0][0], stoi(value[0][1]));
            cout << "null";
        }
        else
        {
            vector<int> ratings;
            for (auto &&rating : value[2])
                ratings.emplace_back(stoi(rating));
            food_ratings = new FoodRatings(value[0], value[1], ratings);
            cout << "null";
        }
        cout << (i < commands.size() - 1 ? ", " : "");
    }

    return 0;
}
