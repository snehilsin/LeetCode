class Solution {
public:
    int canBeTypedWords(string text, string broken){
        bool brokenKeys[26] = {0};
        int count = 0;
        const int offset = 'a';

        for (char c : broken){
            brokenKeys[c - offset] = true;
        }

        stringstream ss(text);
        string word;
        vector<string> words;

        while (ss >> word){
            words.push_back(word);
        }

        for (auto w : words){
            for (char c : w){
                if (brokenKeys[c - offset]){
                    count++;
                    break;
                }
            }
        }

        return words.size() - count;
    }
};