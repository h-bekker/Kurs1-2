using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
	public static void sign(int[] arr)
	{
		for (int i=0; i<5; i++)
		{
			if (arr[i]>0)
				arr[i]=-arr[i];
		}
	}
	static void Main(string[] args)
	{
		int[] arr=new int[5];
		for (int i=0; i<5; i++)
			arr[i]=Convert.ToInt32(Console.ReadLine());
		sign(arr);
		for (int i=0; i<5; i++)
			Console.WriteLine(arr[i]);
	}
}
