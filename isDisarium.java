/* 10. Given an integer N, find whether N is a Disarium or not.
Write a function solution that accepts an integer N. The function should returns 1 if N is Disarium number else 0.  
Input     135 
 Output     1  
For 135, sum of digits powered with their respective position = 11 + 32 + 53 = 135, which is equal to an original number. 

 */

import java.util.Scanner;

public class isDisarium {
    static boolean check(int n) 
    { 
       
        int count_digits = Integer.toString(n).length(); 
           
        int sum = 0; 
        int x = n; 
        while (x!=0) 
        { 
            int r = x%10;   
            sum = (int) (sum + Math.pow(r, count_digits--)); 
            x = x/10; 
        } 
     
        return (sum == n); 
    } 
 
    public static void main(String[] args)  
    { 
        int n = 89; 
          
        System.out.println(check(n) ? n+ " Disarium Number" : n+ " Not a Disarium Number"); 
    } 
} 
    
