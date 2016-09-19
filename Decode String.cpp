class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> code;
        string rest, temp;
        int repeat = 0;
        for (auto c : s){
            if (isdigit(c)){
                repeat *= 10;
                // WARNING: DO NOT USE ATOI!!
                repeat += c - '0';
            }
            else if (c == '['){
                count.push(repeat);
                repeat = 0;
                code.push(rest);
                rest.clear();
            }
            else if (c == ']'){
                temp = rest;
                rest = code.top();
                for (repeat = count.top(); repeat > 0; --repeat)                            
                    rest += temp;
                code.pop();
                count.pop();
            }
            else rest += c;
        }
        //if(!temp.empty()) rest += temp;
        return rest;
    }
};