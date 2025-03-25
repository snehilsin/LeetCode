class Solution {
public:
    int compress(vector<char>& chars) {
        // two pointers
        // one pointer --> i for traversing through the array
        // one will store the length of the compressed vector --> ans

        int ans = 0;
        for ( int i = 0; i < chars.size(); i++){
            char letter = chars[i];
            int count = 1;

            // count repeating chars freq
            while (i < chars.size()-1 && chars[i] == chars[i+1]){
                count++;
                i++;
            }
            chars[ans++] = letter;

            // if count > 1 , convert it to string
            if (count > 1){
                for (char c : to_string(count)){
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    }
};