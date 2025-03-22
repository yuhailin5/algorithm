package luogu.java.test;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            b[i] = i;
        }
        sort(a,b);
        int[] c = new int[n];
        int countLess = 0;
        int countMore = 0;
        for (int i = 0; i < n; i++) {
          countLess = i-0;
          countMore = n-i-1;
          int res = 0;
          //6 10 12 15 20
          if (countMore > countLess) {
              int targetIndex = (n-i) / 2;
              int target = a[targetIndex];
              res = target - a[i] + 1;
          } else {
              res = 0;
          }
          c[b[i]] = res;
        }

        for(int i = 0;i<n;i++) {
          if(i==n-1) {
            System.out.print(c[i]);
            break;
          }
          System.out.print(c[i]+" ");
        }
        scanner.close();
    }
    public static void sort(int[] records, int[] words) {
        int n = records.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (records[j] > records[j + 1]) {
                    int tmp = records[j];
                    records[j] = records[j + 1];
                    records[j + 1] = tmp;

                    tmp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = tmp;
                }
            }
        }
    }
}