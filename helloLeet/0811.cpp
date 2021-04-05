// subdomainVisits (hash)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        vector<string> res;
        for (string& domain : cpdomains) {
            int idx = domain.find(' ');
            int cnt = stoi(domain.substr(0, idx));
            string name = domain.substr(idx + 1);
            while (idx > 0) {
                mp[name] += cnt;
                idx = name.find('.');
                name = name.substr(idx + 1);
            }
        }
        for (auto& pr : mp) {
            res.push_back(to_string(pr.second) + " " + pr.first);
        }
        return res;
    }
};
