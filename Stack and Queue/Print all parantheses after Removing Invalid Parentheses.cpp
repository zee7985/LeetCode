// Steps 
//1. Find the min no bracket to make it valid parantheses (getMinRemoval)
//2 . For printing all the valid paranthees ,use recursion and at each step remove a bracket and decrement getMinremoval count by 1
//3. When getMin Removal count become 0 print the string if it is valid by again finding minGetRemoval function(it should return 0) and only when it is not present in set 

class Solution {
    List<String> result = new ArrayList<>();
    Set<String> set1 = new HashSet<>();
   
    private void removeInvalidParenthesesRecursion(String s, int min, Set<String> set){
        
        if(min == 0){
            
            int minRemovalAllowed = getMinRemoval(s);
            if(minRemovalAllowed == 0){
                if(!set.contains(s)){
                    set.add(s);
                    result.add(s);
                }
            }
            return;
        }
        
        for(int i = 0; i < s.length(); i++){
            String left = s.substring(0, i);      // Remove current character from string 
            String right = s.substring(i+1);
           
            if(!set1.contains(left+right)){
                
                set1.add(left+right);
                removeInvalidParenthesesRecursion(left+right , min - 1, set);
            } 
            
        }
    }
    
   private int getMinRemoval(String str){
       Stack<Character> stack = new Stack<>();
        
        for(int i = 0; i < str.length(); i++ ){
            char currentChar = str.charAt(i);
            if(currentChar == '('){
                stack.push(currentChar);
            }
            if(currentChar == ')'){
                if(!stack.isEmpty() && stack.peek() == '('){
                    stack.pop();   
                } else {
                stack.push(')');
               }
            } 
        }
       return stack.size();
   }
   public List<String> removeInvalidParentheses(String s) {
        
        int minRemovals = getMinRemoval(s);
         System.out.println(minRemovals);
        Set<String> set = new HashSet<>();
        removeInvalidParenthesesRecursion(s, minRemovals, set);
        return result;
        
    }
}
