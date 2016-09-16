public class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern == null || pattern.length() == 0 || str == null || str.length() == 0) {
            return false;
        }

        String[] tokens = str.split(" ");
        
        if (pattern.length() != tokens.length) {
            return false;
        }

        Map<String, Character> inverseMap = new HashMap<>();
        Map<Character, String> map = new HashMap();
        
        int i = 0;
        for (i = 0; i < pattern.length(); i++) {
            char digit = pattern.charAt(i);
            
            String token = tokens[i];
            
            // Check the one-one mapping
            if (!map.containsKey(digit) && !inverseMap.containsKey(token)) {
                map.put(digit, token);
                inverseMap.put(token, digit);
            } else if (map.containsKey(digit) && inverseMap.containsKey(token)) {
                String token1 = map.get(digit);
                char digit1 = inverseMap.get(token);
                
                if (!token1.equals(token) || digit != digit1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
}