class Solution {
public:
    string say ( string prevSequence){
        int counter = 1;
        string output;
        for ( int i = 0; i < prevSequence.length(); i++){
            if ( i + 1 < prevSequence.length() && prevSequence[i] == prevSequence[i+1]){
                counter++;
            } else {
                output += to_string(counter) + prevSequence[i];
                counter = 1;
            }
        }
        return output;
    }
    string countAndSay(int n) {
      string sequence = "1";
      for ( int i = 1; i < n; i++){
        sequence = say(sequence);
      }
      return sequence;
    }
};