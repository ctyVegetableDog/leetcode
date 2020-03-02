//Reconstruct Itinerary

/*
	bfs in a graph (how to build a graph T T)
*/

class Solution {
private:
    vector<string> res;
    unordered_map<string, priority_queue<string, vector<string>, greater<string> >> mp;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto v : tickets) mp[v[0]].push(v[1]);
        helper("JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
    void helper(string from) {
        while (!mp[from].empty()) {
            string to_airport = mp[from].top();
            mp[from].pop();
            helper(to_airport);
        }
        res.push_back(from);
        return;
    }
};
