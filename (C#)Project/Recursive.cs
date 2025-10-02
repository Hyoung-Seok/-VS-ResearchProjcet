using System;

public class RecursiveTest
{
    public int Factorial(int n)
    {
        if(n <= 0)
        {
            return 1;
        }

        return n * Factorial(n - 1);
    }

    public int Fibonacci(int n) 
    {
        if(n <= 1)
        {
            return 0;
        }
        else if(n <= 2)
        {
            return 1;
        }

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
