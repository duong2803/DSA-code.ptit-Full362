
// created: 2023-05-26 18:15:19
// author: Nguyen Tung Duong

package main;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Main {
    
    static BigInteger catalanNumber(int n){
        if(n <= 1) return new BigInteger("0");
        BigInteger[] res = new BigInteger[n + 1];
        res[0] = new BigInteger("1");
        res[1] = new BigInteger("1");
        for(int i = 1; i <= n; ++i){
            res[i] = new BigInteger("0");
            for(int j = 0; j < i; ++j){
                res[i] = res[i].add(res[j].multiply(res[i - j - 1]));
            }
        }
        return res[n];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
            int n = sc.nextInt();
            System.out.println(catalanNumber(n));
            t--;
        }
    }
}

