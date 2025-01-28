//much faster
//algorithm used https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

import java.util.Scanner;
import java.lang.Math;

public class PrimeNumber {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int limit = scanner.nextInt();
        long primes = 0;

        boolean[] number = new boolean[limit + 1];
        number[0]=false;
        number[1]=false;
        for (int i = 2; i <= limit  ; ++ i) {
                number[i] = true;         
        }

        for (int i = 0; i < limit + 1; ++i) {
            if(number[i] == true)
            {
                for(int j = i + i; j < limit + 1; j=j+i)
                {
                        number[j] = false;
                }
             
            }

            
        }
        for (int i = 0; i < limit + 1 ; ++i ) {
            if(number[i])
            {
                ++primes;
                
            }
            
        }
        System.out.println(primes);

    }


}

