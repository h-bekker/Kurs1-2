using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
	static void Main(string[] args)
	{
		string s;
		do
		{
			s=Console.ReadLine();
			if (s=="root") 
				break;
			else
				Console.WriteLine("Пароль введен неправильно, попробуйте еще раз");
		}
		while(true);
		Console.WriteLine("Введен правильный пароль, доступ открыт");
	}
}
