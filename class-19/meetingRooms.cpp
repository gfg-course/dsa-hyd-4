#include<bits/stdc++.h>
using namespace std;

// return true if `a` should come before `b`. (return -1 in java)
// return false if `a` should come after `b`. (retunr +1 in java)
bool timelineComp(pair<int, char> &a, pair<int, char> &b) {
    if (a.first == b.first) {
        // if (a.second == 'e') {
        //     return true;
        // } else {
        //     return false;
        // }
        return a.second == 'e';
    }

    // if (a.first < b.first) {
    //     return true;
    // } else {
    //     return false;
    // }
    return a.first < b.first;
}

// TC: O(n*log(n))
// AS: O(n)
int getMinMeetingRooms(vector<vector<int>> meetings) {
    int n = meetings.size();

    vector<pair<int, char>> timeline; // {timestamp, 's'/'e'}.

    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], 's'});
        timeline.push_back({meetings[i][1], 'e'});
    }

    sort(timeline.begin(), timeline.end(), timelineComp);

    int concurrentMeetings = 0, maxConcurrentMeetings = 0;
    for (int i = 0; i < timeline.size(); i++) {
        if (timeline[i].second == 's') {
            concurrentMeetings++;
        } else {
            concurrentMeetings--;
        }

        maxConcurrentMeetings = max(maxConcurrentMeetings, concurrentMeetings);
    }

    return maxConcurrentMeetings;
}

int main() {
    cout << getMinMeetingRooms({{0, 30},
                                {5, 10},
                                {15, 20}}) << endl;
    cout << getMinMeetingRooms({{1, 18},
                                {18, 23},
                                {15, 29},
                                {4, 15},
                                {2, 11},
                                {5, 13}}) << endl;
}