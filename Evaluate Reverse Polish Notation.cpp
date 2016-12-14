class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int n1, n2, rest;
        for (auto s : tokens) {
            try {numbers.emplace(stoi(s));}
            catch (const invalid_argument& what) {
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                if (s == "+") rest = n1 + n2;
                else if (s == "-") rest = n1 - n2;
                else if (s == "*") rest = n1 * n2;
                else if (s == "/") rest = n1 / n2;
                numbers.emplace(rest);
            }
        }
        return numbers.top();
    }
};