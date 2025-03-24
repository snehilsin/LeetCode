class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> mergedMeetings;
        for (const auto& meeting : meetings){
            if (mergedMeetings.empty() || meeting[0] > mergedMeetings.back()[1]){
                mergedMeetings.push_back(meeting);
            } else {
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
            }
        }
        int meetingDaysCnt = 0;
        for (const auto& m : mergedMeetings){
            meetingDaysCnt += (m[1] - m[0] + 1);
        }
        return days - meetingDaysCnt;
    }
};