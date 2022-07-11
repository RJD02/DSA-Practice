

public class hello {
    int a;
    int b;
    hello(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public static void main(String args[]) {
        // System.out.println("Hello World");
        System.out.println(sayHello(2, 3));
    }

    public static int sayHello(int a, int b) {
        return a + b;
    }
}