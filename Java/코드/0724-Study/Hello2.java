import java.util.Scanner;

public class Hello2 {
    static class Solution {
        public static String solution(int a, int b) {
            String answer[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
            int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
            int sum = 0;
            for(int i = 0; i < a - 1; i++) {
                sum += month[i];
            }
            sum += b;
            return answer[sum % 7];
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        Solution solution = new Solution();
        System.out.println(Solution.solution(a, b));
    }
}
