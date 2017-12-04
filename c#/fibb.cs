using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
	public static void fibb(int k)
	{
		int[] arr=new int[45];
		arr[0]=1;
		arr[1]=1;
		Console.WriteLine(1+"-ое число Фиббоначи: "+arr[0]);
		Console.WriteLine(2+"-ое число Фиббоначи: "+arr[1]);
		for (int i=2; i<k; i++)
		{
			arr[i]=arr[i-1]+arr[i-2];
			Console.WriteLine(i+1+"-ое число Фиббоначи: "+arr[i]);	
		}
	}
	static void Main(string[] args)
	{
		int n;
		Console.WriteLine("Введите число от 1 до 45");
		do
		{
			n=Convert.ToInt32(Console.ReadLine());
			if (n>45 || n<1)
				Console.WriteLine("Введеное вами число не соответсвует требованиям. Попробуйте еще раз");
		} while (n>45 || n<1);
		fibb(n);
	}
}
