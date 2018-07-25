import java.util.Scanner;
import java.math.*;
import java.text.DecimalFormat;

public class Main {
    public static void main(String args[]) {
        Scanner io = new Scanner(System.in);
        while (io.hasNextLine()) {
            double x1 = io.nextDouble();
            double y1 = io.nextDouble();
            double x2 = io.nextDouble();
            double y2 = io.nextDouble();
            double ans = Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            io.nextLine();
            DecimalFormat g=new DecimalFormat("0.00");
            System.out.println(g.format(ans));

        }

    }
}
