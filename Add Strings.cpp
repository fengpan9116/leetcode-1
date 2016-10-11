class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        char carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (unsigned long i = 0; ; i++){
            char ssum = 0;
            if (i < num1.size() && i < num2.size())
                ssum = (num1[i]-'0') + (num2[i]-'0');
            else if (i < num1.size())
                ssum = (num1[i]-'0');
            else if (i < num2.size())
                ssum = (num2[i]-'0');
            else {
                if (carry) sum += '1';
                break;
            }
            ssum += carry;
            if (ssum > 9){
                carry = 1;
                ssum -= 10;
            }
            else carry = 0;
            sum += to_string(ssum);
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};