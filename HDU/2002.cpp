import java.util.Scanner;
import java.math.*;
import java.text.DecimalFormat;

public class Main {
    public static void main(String args[]) {
        Scanner io = new Scanner(System.in);
        while (io.hasNext()) {
            double r=io.nextDouble();
            double ans = (4.0/3.0)*3.1415927*r*r*r;
          //  io.nextLine();
            DecimalFormat g=new DecimalFormat("0.000");
            System.out.println(g.format(ans));

        }

    }
}
