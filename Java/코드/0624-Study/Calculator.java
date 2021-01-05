import java.util.Scanner;
import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        int num1, num2;
        String c;
        Scanner scanner = new Scanner(System.in);
        num1 = scanner.nextInt();
        c = scanner.next();
        num2 = scanner.nextInt();

        int result = 0;
        switch (c) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                result = num1 / num2;
                break;
        }
        System.out.printf("%d %s %d = %d", num1, c, num2, result);
    }
}
