public class Solution {
    public int firstUniqChar(String s) {
        HashSet<Character> cset = new HashSet<Character>();
        LinkedHashMap<Character, Integer> char_to_idx = new LinkedHashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++){
            if (cset.contains(s.charAt(i)))
                char_to_idx.remove(s.charAt(i));
            else{
                cset.add(s.charAt(i));
                char_to_idx.put(s.charAt(i), i);
            }
        }
        Iterator<Map.Entry<Character, Integer>> it = char_to_idx.entrySet().iterator();
        return it.hasNext() ? it.next().getValue() : -1;
    }
}