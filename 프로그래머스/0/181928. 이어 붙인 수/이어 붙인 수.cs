using System;

public class Solution {
    public int solution(int[] num_list) {
        int odd = 0, even = 0, next_num = 10;
        foreach(int num in num_list)
        {
            if (num%2==0){
                even = even*next_num + num;
            }
            else {
                odd = odd*next_num + num;
            }
        }
        return even+odd;
    }
}