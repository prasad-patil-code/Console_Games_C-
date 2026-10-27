#include <iostream>
#include <string>
#include <string_view>

class Battle
{
private:
	std::string m_name{};
	int m_health{};
	int m_power{};

public:
	Battle(std::string_view name, int health, int power)
		: m_name{name}, m_health{health}, m_power{power}
	{
	}

	void attack(Battle &b)
	{
		if (b.m_health > 0 && b.m_health <= 100)
		{
			b.m_health -= this->m_power;

			std::cout << this->m_name << " attacks " << b.m_name << "\n";

			if (b.m_health > 0)
				std::cout << b.m_name << " reduces health to " << b.m_health << "\n \n";

		}

		if (b.m_health <= 0)
		{
			std::cout << b.m_name << " reduces health to " << 0 << "\n \n";
			std::cout << b.m_name << " Looses Battle \n \n";

			std::cout << "END";

			exit(0);


		}

	}

	void heal(int a)
	{
		m_health += a;

		if (this->m_health > 0 && this->m_health < 100)
		{


			std::cout << this->m_name << " health updated to " << this->m_health << "\n \n";
		}

		if(this->m_health >= 100)
		{
			m_health = 100;

			std::cout << m_name << " health is " << 100 << "\n \n";
		}
	}

	void status() const
	{
		std::cout << "Name : " << this->m_name << "\n"
		          << "Health : " << this->m_health << "\n"
		          << "Power : " << this->m_power << "\n \n";
	}
};

int main()
{
	Battle p1{"Kremlin", 100, 25};
	Battle p2{"Goblin", 80, 15};

	p1.status();
	p2.status();

	std::cout << "-------------Mini Battle------------------------------- \n";
	int n{};

	for (int i{1}; i >= 1; ++i)
	{
		std::cout << "1. Attack \n"
		          << "2. Heal \n"
		          << "3. Status \n"
		          << "4. Quit \n \n";
		std::cout << "Choose : ";
		std::cin >> n;
		std::cout << "\n";

		Battle &P1{(i % 2 != 0) ? p1 : p2};
		Battle &P2{(i % 2 != 0) ? p2 : p1};

		if (n == 1)
			P1.attack(P2);

		if (n == 2)
			P1.heal(10);

		if (n == 3)
		{
			P1.status();
			std::cout << "\n";
			P2.status();
		}

		if (n == 4)
			break;
	}

	std::cout << "\n \n"
	          << "GAME END";

	return 0;
}
