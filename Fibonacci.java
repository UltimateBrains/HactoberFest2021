import java.util.Scanner;

public class Fibonacci{
    public static int Fibo(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return (Fibo(n-1)+Fibo(n-2));
    }
    public static void main(String[] args) {
        Scanner obj=new Scanner(System.in);
        System.out.print("Enter number of terms in the fibonacci series: ");
        int n = obj.nextInt();
        System.out.print("The fibonacci series upto "+n+" terms is: ");
        for(int i=0;i<n;i++) System.out.print(Fibo(i)+" ");
        obj.close();
    }
}