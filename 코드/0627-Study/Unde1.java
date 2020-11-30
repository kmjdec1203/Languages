import java.util.Scanner;

class Unde1 {
    public static void main(String[] args) {
        int a, b;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        System.out.println(Solution(a, b));
    }

    public static long Solution(int a, int b) {
        int i;
        long answer = 0;
        if(a < b)
        {
            for(i = a; i <= b; i++) answer += i;
        }
        else if(a > b)
        {
            for(i = b; i <= a; i++) answer += i;
        }
        else answer = a;
        return answer;
    }
}

