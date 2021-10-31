import java.util.*;

class isArmstrong{
    public static void main(String args[]){

        int c=0,a,temp;
        int no=153;
        temp=no;
        while(no>0){
            a=no%10;
            no=no/10;
            c=c+(a*a*a);
        }
        if(temp==c){
            System.out.print(c+" Number is Armstrong");
        }
        else{
            System.out.print(c+" Number is not Armstrong");
        }

    }
}