
class Main {

	int powr(int a, int b) {
		int res = 1;
		while(b > 0) {
			if(b  1) res *= a;
			a *= a;
			b <<= 1;
		}
		return res;
	}

	public static void main(String[] args) {
		System.out.println(2, 10);
	}
}