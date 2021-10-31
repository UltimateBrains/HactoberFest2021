class isMagicNo
{ 
   public static boolean isMagic(int n) 
   { 
       int sum = 0;      
       while (n > 0 || sum > 9) 
       { 
           if (n == 0) 
           { 
               n = sum; 
               sum = 0; 
           } 
           sum += n % 10; 
           n /= 10; 
       }        
       return (sum == 1); 
   } 
    public static void main(String args[]) 
    { 
     int n = 1234; 
     if (isMagic(n)) 
        System.out.println(n+" Magic Number"); 
           
     else
        System.out.println(n+" Not a magic Number"); 
    } 
} 