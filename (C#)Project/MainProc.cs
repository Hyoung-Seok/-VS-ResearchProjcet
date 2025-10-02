using System;

public static class MainProc
{
    public static void Main(string[] args)
    {
        var test = new RecursiveTest();

        int n = int.Parse(Console.ReadLine());
        Console.WriteLine($"{n} 번째 피보나치 : {test.Fibonacci(n)}");
    }
}
