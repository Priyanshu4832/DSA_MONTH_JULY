class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> meet_going;
        priority_queue<int, vector<int>, greater<int>> rooms;
        vector<int> count(n, 0);

        for (int i = 0; i < n; ++i) {
            rooms.push(i);
        }

        for (auto meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms that have finished by the current meeting's start time
            while (!meet_going.empty() && meet_going.top().first <= start) {
                int room = meet_going.top().second;
                meet_going.pop();
                rooms.push(room);
            }

            if (!rooms.empty()) {
                // Assign the smallest available room
                int room = rooms.top();
                rooms.pop();
                count[room]++;
                meet_going.push({end, room});
            } else {
                // Delay the meeting until the earliest available room
                auto [earliest_end, room] = meet_going.top();
                meet_going.pop();
                count[room]++;
                long long new_end = earliest_end + (end - start);
                meet_going.push({new_end, room});
            }
        }

        int max_count = 0;
        int result_room = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > max_count) {
                max_count = count[i];
                result_room = i;
            }
        }
        return result_room;
    }
};