import java.util.Scanner;

public class Unde3 {
    public static void main(String[] args) {
        int num = 0;
        Scanner scanner = new Scanner(System.in);
        num = scanner.nextInt();
        Solution solution = new Solution();
        System.out.println(solution.solution(num));
    }
    static class Solution {
        public String solution(int num) {
            String answer = "";
            if(num % 2 == 0) answer = "Even";
            else answer = "Odd";
            return answer;
        }
    }
}
