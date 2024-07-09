using System;

public class Solution {
    public int[] solution(int[] num_list) {
        int len = num_list.Length;
        int new_num = num_list[len-1] > num_list[len-2] ? num_list[len-1] - num_list[len-2] : num_list[len-1]*2;
        int[] answer = new int[len+1];
        Array.Copy(num_list, answer, len);
        answer[len] = new_num;
        return answer;
    }
}