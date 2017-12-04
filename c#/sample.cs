using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Hello {
	static void Main(string[] args) {
		Random rand=new Random();
		int a=rand.Next(100);
		Console.WriteLine("Вероятность крита :");
		Console.WriteLine(a);
	}
}
