class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        for(int i=0;i<s.size();i+=k){
            int len = min(k,(int)s.size()- i);
            string tmp = s.substr(i, len);

            // this is for last string only            
            while(tmp.size() < k){
                tmp += fill;
            }            

            ans.push_back(tmp);
        }

        return ans;
    }
};