import java.util.*;

public class LoopsII {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            for (int j = 0 ; j < n ; ++j) {
                long num = a;
                for (int k = 0 ; k <= j ; ++k) {
                    num += Math.pow(2,k)*b;
                }
                System.out.print (num);
                if (j != n-1)
                    System.out.print(" ");
            }
            if (i != n-1)
                System.out.println("");
        }
        in.close();
    }
}
