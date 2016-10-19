public class Solution {
    public int maxProduct(String[] words_) {
        int gmax = 0, size = words_.length;
        int words[] = new int[size];
        for (int i = 0; i < size; i++){
            int sb = 0;
            for (Character c : words_[i].toCharArray()) sb |= 1 << (c-'a');
            words[i] = sb;
        }
        for (int i = 0; i < size-1; i++)
            for (int j = i+1; j < size; j++)
                if ((words[i] & words[j]) == 0)
                    gmax = Math.max(words_[i].length() * words_[j].length(), gmax);
        return gmax;
    }
}