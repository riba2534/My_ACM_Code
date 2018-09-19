
import java.util.*;

import java.math.*;

class Main {
    public static BigInteger getSqrt(String s) {

        BigInteger remain = BigInteger.ZERO;
        BigInteger odd = BigInteger.ZERO;
        BigInteger ans = BigInteger.ZERO;
        int group = 0, k = 0;
        if (s.length() % 2 == 1) {
            group = s.charAt(0) - '0';
            k = -1;
        } else {
            group = (s.charAt(0) - '0') * 10 + s.charAt(1) - '0';
            k = 0;
        }
        for (int j = 0; j < (s.length() + 1) / 2; j++) {
            if (j != 0)
                group = (s.charAt(j * 2 + k) - '0') * 10 + s.charAt(j * 2 + k + 1) - '0';
            odd = BigInteger.valueOf(20).multiply(ans).add(BigInteger.ONE);
            remain = BigInteger.valueOf(100).multiply(remain).add(BigInteger.valueOf(group));
            int count = 0;
            while (remain.compareTo(odd) >= 0) {
                count++;
                remain = remain.subtract(odd);
                odd = odd.add(BigInteger.valueOf(2));
            }
            ans = ans.multiply(BigInteger.TEN).add(BigInteger.valueOf(count));
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner io = new Scanner(System.in);
        int t = io.nextInt();
        while (t-- > 0) {
            BigInteger n = io.nextBigInteger();
            BigInteger x = n.multiply(n.subtract(new BigInteger(String.valueOf(1))));
            BigInteger xx = x.divide(new BigInteger(String.valueOf(2)));
            boolean flag0 = false, flag1 = false;
            BigInteger h1 = getSqrt(n.toString());
            BigInteger h2 = getSqrt(xx.toString());
            h1 = h1.multiply(h1);
            h2 = h2.multiply(h2);
            if (h1.compareTo(n) == 0)
                flag0 = true;
            if (h2.compareTo(xx) == 0)
                flag1 = true;
            if (flag0 == true && flag1 == true)
                System.out.println("Arena of Valor");
            else if (flag0 == true && flag1 == false)
                System.out.println("Hearth Stone");
            else if (flag0 == false && flag1 == true)
                System.out.println("Clash Royale");
            else {
                System.out.println("League of Legends");
            }

        }
    }
}
