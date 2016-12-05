class Solution {
public:
    int calculate(string s) {
        int cursign = 1, res = 0, sum;
        stack<int> signs;
        signs.emplace(1);
        for (size_t i = 0; i < s.size(); i++){
            auto c = s[i];
            switch(c) {
                case ' ': continue;
                case '+':
                    cursign = 1;
                    break;
                case '-':
                    cursign = -1;
                    break;
                case '(':
                    signs.emplace(cursign * signs.top());
                    cursign = 1;
                    break;
                case ')':
                    signs.pop();
                    break;
                default:
                    sum = c - '0';
                    for (i++; i < s.size() && isdigit(s[i]); i++)
                        sum = sum*10 + (s[i]-'0');
                    i--;
                    res += sum * cursign * signs.top();
            }
        }
        return res;
    }
};