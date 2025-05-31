class Solution {
public:
    long helper( string s, int sign, int i, long result){
        if (sign * result >= INT_MAX){
            return INT_MAX;
        }
        if (sign * result <= INT_MIN){
            return INT_MIN;
        }
        if ( i >= s.size() || s[i] < '0' || s[i] > '9'){
            return sign  * result;
        }
        result = helper(s, sign, i+1, (result * 10  + (s[i] - '0')));
        return result;
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        while ( i < n && s[i] == ' '){
            i++;
        }
        if (s[i] == '-'){
            sign = -1;
            i++;
        } else if (s[i] == '+'){
            i++;
        }
        return helper(s, sign, i, 0);

    }
};