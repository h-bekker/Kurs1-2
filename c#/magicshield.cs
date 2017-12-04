class MagicShield : Ability 
{
	public int HP;
	public int Energy;
	public MagicShield() //инициализация всех тех полей, что есть в ability, в частности ниже
	{
		... 
		CanUse=false;
		Energy-=6;
		Cooldown=5;
		StepsPassed=0;
	}
	public void shot(int damage) 
	{
		if (Energy<0.6*damage) //случай, если полученный урон больше энергии
		{
			HP-=0.6*damage-Energy;
			Energy=0;
		}
		else
		{
			HP-=0.4*damage;
			Energy-=0.6*damage;
		}
		if (HP<0)
			HP=0;
		Cooldown--;
		StepsPassed++;
		if (StepsPassed==3)
			~MagicShield();
	}
}

	
