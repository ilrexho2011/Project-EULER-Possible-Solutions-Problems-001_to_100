// Java Program using Dynamic Programming.
public class EulerProblemTwo {
	
	public static void main(String[] args) {
		System.out.println(sumofFibonaccinumbers(4000000));
	}
	// Less than n 
	public static long sumofFibonaccinumbers (long n) {
		int i    = 2;
		long sum = 0;
		long value = 0;
		do {
			value = fib(i);
			sum = sum + value;
			i = i+3;
		} while (value < n);
		return sum-value;
	}
	static long []fib = new long[2000000];
	public static long fib(int n) {
		if (n == 1) {
			fib[n] = 1;
			return 1;
		}
		if (n == 2) {
			fib[n] = 2;
			return 2;
		}
		if (fib[n] == 0) {
			fib[n] = fib(n-1)+fib(n-2);
		}
		return fib[n];
	}

}
