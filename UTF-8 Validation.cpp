class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bitset<8> byte;
        int left = 0;
        for (auto i : data){
            byte = i;
            if (left < 0) return false;
            if (left == 0) {
                if (byte[7] == 1 && byte[6] == 0) return false;
                for (size_t j = 7; j > 0; j--){
                    if (byte[j] == 0) break;
                    if (j <= 3) return false;
                    left += byte[j];
                }
                left = max(left-1, 0);
            }
            else {
                if (byte[7] == 1 && byte[6] == 0) left--;
                else return false;
            }
        }
        return left == 0;
    }
};