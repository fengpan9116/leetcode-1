class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        bitset<10> temp;
        vector<bitset<10>> rest;
        vector<string> res;
        for (unsigned i = 0; i < 1024; i++){
            temp = i;
            if (temp.count() == num) rest.push_back(temp);
        }
        bitset<4> hour;
        bitset<6> minute;
        string hs, ms;
        for (auto b : rest){
            for (int i = 0; i < 6; i++)
                minute[i] = b[i];
            for (int i = 0; i < 4; i++)
                hour[i] = b[i+6];
            if (hour.to_ulong() > 12 || minute.to_ulong() > 59)
                continue;
            hs = to_string(hour.to_ulong());
            ms = to_string(minute.to_ulong());
            if (minute.to_ulong() < 10) ms.insert(0, "0");
            res.push_back(hs + ":" + ms);
        }
        return res;
    }
};