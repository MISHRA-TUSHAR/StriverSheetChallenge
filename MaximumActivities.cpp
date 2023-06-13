#include<bits/stdc++.h>

static bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int maximumActivities(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
        ans.push_back({ start[i], finish[i] });

    sort(ans.begin(), ans.end(), compare);

    int count = 1;
    int last = ans[0].second;

    for (int i = 1; i < n; i++) {
        if (ans[i].first < last)
            continue;
        else {
            count++;
            last = ans[i].second;
        }
    }

    return count;
}
