using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class GenAbilities  //общий для всех классов
	{
	private int StrongShot;
	private int WeakShot;
	}

class knight: GenAbilities
	{
	private bool Block; //блок
	private bool Persist; //уменьшение силы удара по игроку
	private int OutCry; //командный выкрик
	}

class archer: GenAbilities 
	{
	private bool Trefoil;
	private bool MassStrike;
	}

	

