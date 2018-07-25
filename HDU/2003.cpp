import java.util.Scanner;


public class Main {
    public static void main(String args[]) {
        Scanner io = new Scanner(System.in);
        while (io.hasNext()) {
            double n=io.nextDouble();
            System.out.printf("%.2f",Math.abs(n));
            System.out.println();


        }

    }
}
