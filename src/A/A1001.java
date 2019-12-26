package A;

import main.Answer;

import java.util.Scanner;

public class A1001 implements Answer {

    public void Run()
    {
        Scanner in = new Scanner(System.in);
        String[] input = in.nextLine().split(" ");
        long reL = Long.parseLong(input[0]) + Long.parseLong(input[1]);
        boolean isNeg = reL < 0;
        String reS = String.valueOf(reL).replace("-", "");
        String result = "";
        for(int i = reS.length(); i > 0; i -= 3)
        {
            int start = Math.max(i - 3, 0);
            result = (i - 3 > 0 ? "," : "") + reS.substring(start, i) + result;
        }
        System.out.println((isNeg ? "-" : "") + result);
    }
}
