class Solution {
public:
    int count_digits(int num){
        int count =0;
        
        if(num == 0)
            return 1;
        
        while(num != 0){
            ++count;
            num = num /10;
        }
        return count;
    }
    
    bool isPalindrome_helper(int x){
        int temp = x;
        int rev=0;
        
        
        while(temp!= 0 && temp > rev){
            int dig = temp %10;
            temp = temp /10;
            
            rev = (rev*10) + dig;
        }
        
        // temp is left half
        // rev is right half
        
        int left_digits = count_digits(temp);
        int right_digits = count_digits(rev);
        int total = left_digits +right_digits;
        
        // if number is odd length then we have to ignore middle digit
        if(total %2 != 0){
            int unit_dig = rev % 10;
            rev = rev/10;            
        }
        
        //FYI: if even length number no worries; both temp and rev will have same number of digits
        
        return temp == rev;
    
    }
   
    
    bool isPalindrome(int x) {
        if(x == 0)
            return true;
        
        // negative number
        if(x < 0 || (x%10) ==0 )
            return false;
        
        // positive number with explicit positive sign 
        // NO need to worry about this case as it is an integer 
        // in otherwords you need to worry about this only when you have a string 
        
        // single digit is a palindrome
        if( x>=0 && x <10)
            return true;
        
        return isPalindrome_helper(x);
        
    }
};
