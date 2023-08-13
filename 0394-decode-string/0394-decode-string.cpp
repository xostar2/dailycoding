class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decode(s,idx);
    }
     string decode(string &s, int &idx) {
        int times = 0;
        string word = "";
        
        while(idx < s.length()) {
            if(s[idx] >= '0' && s[idx] <= '9')
                times = times * 10 + (s[idx] - '0');
            else if(s[idx] == '[') {
                idx++;
                string temp = decode(s, idx);
                while(times--) word += temp;
                times = 0;
            }
            else if(s[idx] == ']')
                return word;
            else
                word += s[idx];
            idx++;
        }
        return word;
    }
};