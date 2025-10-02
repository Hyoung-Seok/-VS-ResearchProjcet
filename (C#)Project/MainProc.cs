using System;

public static class MainProc
{
    public static void Main(string[] args)
    {
        var test = new RecursiveTest();

        test.HanoiTowerMove(3, 'A', 'B', 'C');
    }
}
