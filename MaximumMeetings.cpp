#include <bits/stdc++.h>

bool static compareMeetings(const vector<int>& a, vector<int>& b) {
    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else if (a[2] < b[2]) {
        return true;
    }
    return false;
}

vector<int> maximumMeetings(vector<int>& start, vector<int>& end) {
    vector<int> result;
    int n = start.size();
    vector<vector<int>> meetings(n);

    for (int i = 0; i < n; i++) {
        meetings[i] = { end[i], start[i], i + 1 };
    }

    sort(meetings.begin(), meetings.end(), compareMeetings);

    int currentEnd = meetings[0][0];
    result.push_back(meetings[0][2]);

    for (int i = 1; i < n; i++) {
        if (meetings[i][1] > currentEnd) {
            currentEnd = meetings[i][0];
            result.push_back(meetings[i][2]);
        }
    }

    return result;
}
