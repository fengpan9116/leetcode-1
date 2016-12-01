class Solution {
public:
    int myAtoi(string str) {
        int res;
        try {res = stoi(str);}
        catch (const out_of_range& oex) {
            if (str.find('-') != string::npos) res = INT_MIN;
            else res = INT_MAX;
        }
        catch (...) {res = 0;}
        return res;
    }
};