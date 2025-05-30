#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> dfs(vector<int> &edges, int node)
    {
        int size = edges.size();
        vector<int> dis(size, size);

        for (int d = 0; node >= 0 && dis[node] == size; node = edges[node])
            dis[node] = d++;

        return dis;
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int answer = -1, size = edges.size();

        vector<int> dis1 = dfs(edges, node1);
        vector<int> dis2 = dfs(edges, node2);

        for (int i = 0, min_dis = size; i < size; i++)
        {
            int dis = max(dis1[i], dis2[i]);
            if (dis < min_dis)
            {
                min_dis = dis;
                answer = i;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> edges{2, 2, 3, -1};
    int node1 = 0;
    int node2 = 1;

    int answer = solution.closestMeetingNode(edges, node1, node2);
    cout << answer << endl;

    return 0;
}
