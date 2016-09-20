class Solution {
public:
    bool isValid(string s) {
        enum Bra {S, M, L};
        stack<int> bras;
        for (auto c : s){
            switch(c){
                case '(':
                    bras.push(S);
                    break;
                case '[':
                    bras.push(M);
                    break;
                case '{':
                    bras.push(L);
                    break;
                case ')':
                    if (bras.empty() || bras.top() != S)
                        return false;
                    bras.pop();
                    break;
                case ']':
                    if (bras.empty() || bras.top() != M)
                        return false;
                    bras.pop();
                    break;
                case '}':
                    if (bras.empty() || bras.top() != L)
                        return false;
                    bras.pop();
                    break;
                default: break;
            }
        }
        return bras.empty();
    }
};