import java.util.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner io = new Scanner(System.in);
        int t = io.nextInt();
        while (t-- > 0) {
            int n = io.nextInt();
            BigInteger x = new BigInteger(String.valueOf(2));
            System.out.println(x.pow(n));
        }
    }
}
