class Solution {
public:
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;
		vector<int> pattern = kmpArray(needle);
		for (int i = 0, j = -1; i < haystack.size(); i++) {
			while (j >= 0 && haystack[i] != needle[j+1]) j = pattern[j];
			if (haystack[i] == needle[j+1]) j++;
			if (j == needle.size()-1) return i-needle.size()+1;
		}
		return -1;
    }
	vector<int> kmpArray(string str) {
		vector<int> pattern(str.size(), -1);
		for (int i = 1, j = -1; i < str.size(); i++) {
			while (j >= 0 && str[i] != str[j+1]) j = pattern[j];
			if (str[i] == str[j+1]) j++;
			pattern[i] = j;
		}
		return pattern;
	}
};