
import java.util.*;

class Grading{

    static int[] solve(int[] grades){
        // Complete this function
        for(int i=0;i<grades.length;i++)
        {
          if(grades[i]>=38)
          {
               if(grades[i]+(5-grades[i]%5)-grades[i]<3)
               grades[i]=(grades[i]+(5-grades[i]%5));
          } 
        }
        return grades;
    }
    public static void main(String[] args) {
      
         Scanner scan = new Scanner(System.in);
         
        int n = Integer.parseInt(scan.nextLine().trim());

        int[] grades = new int[n];

        for (int gradesItr = 0; gradesItr < n; gradesItr++) {
            int gradesItem = Integer.parseInt(scan.nextLine().trim());
            grades[gradesItr] = gradesItem;
        }
        int[] result= Grading.solve(grades);
         for(int i=0;i<grades.length;i++)
         {
          System.out.println(result[i]);
         }
    }


}






