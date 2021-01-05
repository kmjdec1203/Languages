import java.util.Scanner;

public class Hello {
    public static class Solution {
        public static String solution(int n) {
            String answer = "";
            for(int i = 1; i <= n; i++) {
                if(i % 2 != 0) answer += "수";
                else answer += "박";
            }
            return answer;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Solution solution = new Solution();
        System.out.println(Solution.solution(n));
    }
}
