using System;

public class RecursiveTest
{
    public void Recursive()
    {
        Console.WriteLine("Recursive Call!");
        // 자기 자신 호출
        Recursive();
    }
}
