package main;

public class Main {

    private static String type = "A";
    private static String question = "1002";

    public static void main(String[] args)
    {
        try {
            String className = type + "." + type + question;
            Class<?> c = Class.forName(className);
            Answer answer = (Answer) c.newInstance();
            answer.Run();
        } catch (ClassNotFoundException | IllegalAccessException | InstantiationException e) {
            e.printStackTrace();
        }
    }
}
