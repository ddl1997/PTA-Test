package A;

import main.Answer;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A1002 implements Answer {
    @Override
    public void Run() {
        Scanner in = new Scanner(System.in);
        String[] first = in.nextLine().split(" ");
        String[] second = in.nextLine().split(" ");
        int fsum = Integer.parseInt(first[0]);
        int ssum = Integer.parseInt(second[0]);
        List<Item> fPoly = new ArrayList<>();
        List<Item> sPoly = new ArrayList<>();

        for (int i = 0; i < fsum; i++)
        {
            fPoly.add(new Item(Integer.parseInt(first[2 * i + 1]), Float.parseFloat(first[2 * i + 2])));
        }
        for (int i = 0; i < ssum; i++)
        {
            sPoly.add(new Item(Integer.parseInt(second[2 * i + 1]), Float.parseFloat(second[2 * i + 2])));
        }

        List<Item> result = new ArrayList<>();
        int fi = 0, si = 0;
        fsum = fPoly.size();
        ssum = sPoly.size();
        while (fi < fsum || si < ssum)
        {
            if (fi < fsum && si < ssum)
            {
                Item f = fPoly.get(fi);
                Item s = sPoly.get(si);
                if (f.exp == s.exp)
                {
                    if (f.coff + s.coff != 0)
                        result.add(new Item(f.exp, f.coff + s.coff));
                    fi++;
                    si++;
                }
                else if (f.exp > s.exp)
                {
                    result.add(f);
                    fi++;
                }
                else
                {
                    result.add(s);
                    si++;
                }
            }
            else if (fi >= fsum)
            {
                for (; si < ssum; si++)
                {
                    result.add(sPoly.get(si));
                }
            }
            else
            {
                for (; fi < fsum; fi++)
                {
                    result.add(fPoly.get(fi));
                }
            }
        }

        String sResult = String.valueOf(result.size());
        for (Item item : result) {
            sResult = sResult + " " + item.exp + " " + String.format("%.1f", item.coff);
        }
        System.out.println(sResult);
    }

    static class Item
    {
        int exp;
        float coff;
        Item(int e, float c)
        {
            exp = e;
            coff = c;
        }
    }
}
