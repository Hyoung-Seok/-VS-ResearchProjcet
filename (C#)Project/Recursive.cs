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

    public int BinarySearch(int[] arr, int first, int last, int target)
    {
        if (first > last) return -1;

        var mid = (first + last) / 2;

        // 찾아야 할 값이 중간값보다 작다면
        if (arr[mid] > target)
        {
            return BinarySearch(arr, first, mid - 1, target);
        }
        // 찾아야 할 값이 중간값보다 크다면
        else if (arr[mid] < target)
        {
            return BinarySearch(arr, mid + 1, last, target);
        }

        return mid;
    }

    public void HanoiTowerMove(int num, char from, char by, char to)
    {
        if(num <= 1)
        {
            Console.WriteLine($"원반 {num}을 {from}에서 {to}로 이동");
        }
        else
        {
            // 원반 n개를 A->C로 옮기기 위해 n-1개를 먼저 b로 옮김
            HanoiTowerMove(num - 1, from, to, by);

            // 큰 원반을 A에서 C로 이동
            Console.WriteLine($"원반 {num}을 {from}에서 {to}로 이동");

            // 작은 원반 n-1개를 B->C로 이동
            HanoiTowerMove(num - 1, by, from, to);
        }
    }
}
