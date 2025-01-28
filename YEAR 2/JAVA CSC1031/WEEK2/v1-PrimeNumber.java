
//too slow, toke more than 3 seconds from number grater than 1milion

import java.util.Scanner;
import java.lang.Math;

public class PrimeNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long limit = scanner.nextInt();
        long cnt = 0;

        for (double i = 2; i < limit + 1; ++i)
        {
            if(i == 2)
                ++cnt;
            else if (isPrime(i) == true)
                ++cnt;  
        }
        System.out.println(cnt);

    }


    private static boolean isPrime(double num) {
        double square = 0;
        square = Math.sqrt(num);
        double s = Math.ceil(square);
        int c = 0;

            for(double i = 2; i <= s; ++i)
            {
                
                if( num % i == 0)
                    ++c;

            }
        return c == 0;


}
}