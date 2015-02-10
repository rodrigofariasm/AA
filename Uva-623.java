import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
/* Name of the class has to be "Main" only if the class is public. */
public class Main{	
	 public static BigInteger fat(int n) {
		if (n <= 1) {
		return(new BigInteger("1"));
		} else {
			BigInteger bigN = new BigInteger(String.valueOf(n));
			return(bigN.multiply(fat(n - 1)));
		}
		}
		
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNextBigInteger()) {
			int input = scan.nextInt();
			BigInteger fact = fat(input);
			System.out.format("%d!\n%d\n",input,fact);
		}
	}
}
