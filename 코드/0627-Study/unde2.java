import java.util.*;
class Solution {
        public int[] solution(int[] arr) {
            int i = 0;
            // int[] arr = new int[0];
            ArrayList<Integer> list = new ArrayList<Integer>();
            int a = 10;
            for (i = 0; i < arr.length; i++) {
                if (arr[i] != a) {
                    list.add(arr[i]);
                    a = arr[i];
                }
            }
            int[] answer = new int[list.size()];
            for (i = 0; i < list.size(); i++)
                answer[i] = list.get(i);
            return answer;
        }
    }



