/*
 * @Description: 
 * @Author: 天涯过客
 * @Date: 2025-01-20 23:46:49
 */

import java.util.Scanner;


public class _58 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] nums = new int[n];
        int[] p = new int[n+1];
        p[0] = 0;
        
        for(int i = 0;i<n;i++) {
            nums[i] = scan.nextInt();
            p[i+1] = p[i] + nums[i];
        }
        
        
        while(scan.hasNext()) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            
            System.out.println(p[b+1] - p[a]);
        }
        scan.close();
    }
}
