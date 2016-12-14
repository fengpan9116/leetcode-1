class Solution {
public:
    enum {ADD, SUB, MUL, DIV, NOP};
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int n1, n2, rest, op;
        for (auto s : tokens) {
            if (s == "+") op = ADD;
            else if (s == "-") op = SUB;
            else if (s == "*") op = MUL;
            else if (s == "/") op = DIV;
            else op = NOP;
            if (op != NOP) {
                n2 = numbers.top();
                numbers.pop();
                n1 = numbers.top();
                numbers.pop();
                if (op == ADD) rest = n1 + n2;
                else if (op == SUB) rest = n1 - n2;
                else if (op == MUL) rest = n1 * n2;
                else if (op == DIV) rest = n1 / n2;
                numbers.emplace(rest);
            }
            else numbers.emplace(stoi(s));
        }
        return numbers.top();
    }
};