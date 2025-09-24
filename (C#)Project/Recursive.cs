using System;

public class RecursiveTest
{
    public void Recursive(int num)
    {
        // 재귀 함수의 탈출 조건
        if (num <= 0) return;

        Console.WriteLine($"Recursive Call : {num}");
        Recursive(num - 1);
    }
}
