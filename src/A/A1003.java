package A;

import main.Answer;

import java.util.Scanner;

public class A1003 implements Answer {

    static int citySum;
    static int roadSum;
    static int from;
    static int to;
    static int[] cities;
    static int[][] roads;
    static int[] teams;
    static int[] paths;

    @Override
    public void Run() {
        Scanner in = new Scanner(System.in);
        String[] nums1 = in.nextLine().split(" ");
        citySum = Integer.parseInt(nums1[0]);
        roadSum = Integer.parseInt(nums1[1]);
        from = Integer.parseInt(nums1[2]);
        to = Integer.parseInt(nums1[3]);
        cities = new int[citySum];
        roads = new int[citySum][citySum];
        for (int i = 0; i < citySum; i++)
            for (int j = 0; j < citySum; j++)
                roads[i][j] = -1;
        String[] nums2 = in.nextLine().split(" ");
        for (int i = 0; i < citySum; i++)
            cities[i] = Integer.parseInt(nums2[i]);
        for (int i = 0; i < roadSum; i++)
        {
            String[] nums3 = in.nextLine().split(" ");
            int rFrom = Integer.parseInt(nums3[0]), rTo = Integer.parseInt(nums3[1]);
            roads[rFrom][rTo] = Integer.parseInt(nums3[2]);
            roads[rTo][rFrom] = Integer.parseInt(nums3[2]);
        }
        teams = new int[citySum];
        paths = new int[citySum];
        for (int i = 0; i < citySum; i++) {
            teams[i] = 0;
            paths[i] = 0;
        }
        ShortestPath();
        System.out.println(paths[to] + " " + teams[to]);
    }

    int ShortestPath()
    {
        int[] lengths = new int[citySum];
        int[] tags = new int[citySum];
        for (int i = 0; i < citySum; i++) {
            lengths[i] = i == from ? 0 : -1;
            tags[i] = 0;
        }
        paths[from] = 1;
        teams[from] = cities[from];
        for (int count = 0; count < citySum; count++)
        {
            int vector = -1, minLength = -1;
            for (int j = 0; j < citySum; j++)
            {
                if (tags[j] == 0 && lengths[j] >= 0 && (minLength == -1 || minLength > lengths[j]))
                {
                    minLength = lengths[j];
                    vector = j;
                }
            }
            if (vector == -1) break;
            tags[vector] = 1;
            for (int i = 0; i < citySum; i++)
            {
                if (tags[i] == 0 && roads[vector][i] != -1)
                {
                    if (vector == from || lengths[vector] + roads[vector][i] < lengths[i]) {
                        lengths[i] = lengths[vector] + roads[vector][i];
                        paths[i] = paths[vector];
                        teams[i] = teams[vector] + cities[i];
                    }
                    else if (lengths[vector] + roads[vector][i] == lengths[i])
                    {
                        paths[i] += paths[vector];
                        teams[i] = Math.max(teams[i], teams[vector] + cities[i]);
                    }
                }
            }
        }
        return lengths[to];
    }
}
