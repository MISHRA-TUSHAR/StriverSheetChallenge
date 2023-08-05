#include <bits/stdc++.h> 

std::vector<int> KMostFrequent(int n, int k, std::vector<int>& arr)
{
    vector<int> ans;
    priority_queue<pair<int, int>, vector<std::pair<int, int>>, greater<pair<int, int>>> mini;

    std::unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] += 1;
    }

    for (auto pair : mp) {
        if (mini.size() < k) {
            mini.push({ pair.second, pair.first });
        }
        else {
            if (mini.top().first < pair.second) {
                mini.pop();
                mini.push({ pair.second, pair.first });
            }
        }
    }

    while (!mini.empty()) {
        ans.push_back(mini.top().second);
        mini.pop();
    }

    std::sort(ans.begin(), ans.end());
    return ans;
}
