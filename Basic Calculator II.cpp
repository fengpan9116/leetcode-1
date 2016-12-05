class Solution {
public:
    enum {ADD, MUL, DIV};
    int calculate(string s) {
        int prevOp = ADD, res = 0;
        stack<int> numbers;
        for (size_t i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (isdigit(c) || c == '+' || c == '-') {
                size_t next = i+1;
                for (; ; next++) {
                    if (next == s.size() || (!isdigit(s[next]) && s[next] != ' '))
                        break;
                }
                string numstr = s.substr(i, next-i);
                for (size_t j = 0; j < (volatile size_t)numstr.size(); ) {
                    if (numstr[j] == ' ') numstr.erase(j,1);
                    else j++;
                }
                int num = stoi(numstr);
                if (prevOp == MUL || prevOp == DIV) {
                    auto prev = numbers.top();
                    numbers.pop();
                    if (prevOp == MUL) numbers.emplace(prev * num);
                    else numbers.emplace(prev / num);
                }
                else {
                    numbers.emplace(num);
                }
                prevOp = ADD;
                i = next-1;
            }
            else if (c == '*') prevOp = MUL;
            else if (c == '/') prevOp = DIV;
        }
        while (!numbers.empty()) {
            res += numbers.top();
            numbers.pop();
        }
        return res;
    }
};