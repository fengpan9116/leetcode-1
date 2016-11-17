class Solution {
public:
    string toHex(int num) {
        stringstream sstream;
        sstream << hex << num;
        return sstream.str();
    }
};