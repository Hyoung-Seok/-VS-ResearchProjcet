using System;

public static class MainProc
{
    public static void Main(string[] args)
    {
        var test = new RecursiveTest();

        var arr = new int[] { 1, 3, 5, 7, 9, 12, 13, 14, 16, 19, 20 };
        Console.WriteLine(test.BinarySearch(arr, 0, arr.Length - 1, 14));
    }
}
