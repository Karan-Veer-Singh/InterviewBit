bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, int>> v;

    for (int i = 0; i < arrive.size(); i++) {
        v.push_back({arrive[i], 1});
        v.push_back({depart[i], 0});
    }

    sort(v.begin(), v.end());
    int currRoom = 0, maxRoom = 0;

    for (int i = 0; i < v.size(); i++)
        if (v[i].second == 1) {currRoom++; maxRoom = max(maxRoom, currRoom);}
        else currRoom--;

    return (K >= maxRoom);
}

// https://www.interviewbit.com/problems/hotel-bookings-possible/