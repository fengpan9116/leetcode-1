class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        //vector<int> vowdex;
        for (int i = 0; i < s.length(); i++){
            switch(s[i]){
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    vowels.push_back(s[i]);
                    //vowdex.push_back(i);
                default:
                    break;
            }
        }
        for (int i = 0; i < s.length(); i++){
            switch(s[i]){
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    s[i] = vowels.back();
                    vowels.pop_back();
                default:
                    break;
            }
        }
        return s;
    }
};