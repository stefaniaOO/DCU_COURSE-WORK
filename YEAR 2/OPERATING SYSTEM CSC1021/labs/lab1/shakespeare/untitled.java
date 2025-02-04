import java.util.Scanner;
import java.lang.Math;


public class PrimeNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long limit = scanner.nextInt();

   
        double cnt = 0;
        double square = 0;
       // if(limit > 2)
        //	cnt = cnt + 1;

        for (double i = 2; i < limit + 1; ++i)
        {
        	if(i == 2)
        		++cnt;
            square = Math.sqrt(i);
        	double s = Math.ceil(square);
        	int counter = 0;

        	for(double y = 2; y <= s; ++y)
        	{
        		
        		if( i % y == 0)
        			++counter;

        	}
        	if(counter == 0)
        		++cnt;

        }
        System.out.println((int)cnt);
        
    }
