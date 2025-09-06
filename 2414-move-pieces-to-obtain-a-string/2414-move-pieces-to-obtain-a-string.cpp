class Solution {
public:
    bool canChange(string start, string target) {
       int n = start.size();
    int i = 0, j = 0;

    while(i < n || j < n) {
        // skip blanks
        while(i < n && start[i] == '_') i++;
        while(j < n && target[j] == '_') j++;

        if(i == n || j == n) break; // end reached

        if(start[i] != target[j]) return false;

        if(start[i] == 'L' && i < j) return false; // L can't move right
        if(start[i] == 'R' && i > j) return false; // R can't move left

        i++; j++;
    }

    // both must reach end together
    while(i < n && start[i] == '_') i++;
    while(j < n && target[j] == '_') j++;

    return i == n && j == n;
    }
};