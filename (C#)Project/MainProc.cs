using System;

public static class MainProc
{
    public static void Main(string[] args)
    {
        var test = new RecursiveTest();

        Console.WriteLine($"5! = {test.Factorial(5)}");
        Console.WriteLine($"4! = {test.Factorial(4)}");
        Console.WriteLine($"3! = {test.Factorial(3)}");
        Console.WriteLine($"2! = {test.Factorial(2)}");
        Console.WriteLine($"1! = {test.Factorial(1)}");
    }
}
