import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main {

	static void solve(BigInteger n, BigInteger k) {
		BigInteger x = n.subtract(k);
		x = x.divide(BigInteger.valueOf(2));
		BigInteger y = x.add(k);
		System.out.println(y);
		System.out.println(x);
		System.out.println("Hello World");
	}

	public static void main(String[] args) {
		BigInteger n, k;
		Scanner sc = new Scanner(System.in);
		int tc = 1;

		while(tc > 0) {
			n = sc.nextBigInteger();
			k = sc.nextBigInteger();
			solve(n, k);
			tc--;
		}
	}
}