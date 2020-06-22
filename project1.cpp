#include<iostream>

class Symptom
{
	private:
		std::string name;
		float chance;
		std::string question;
	public:
		Symptom()
		{
			name = "";
			chance = 0.0;
			question = "";
			
		}
		void setName(std::string _name)
		{
			name = _name;
		}
		void setChance(float _chance)
		{
			chance = _chance;
		}
		std::string getName()
		{
			return name;
		}
		float getChance()
		{
			return chance;
		}
		void printQuestion()
		{			  
	        std::cout << "\nIn the last 14 days, do you:\n";
            std::cout << "(please answer with 'yes' or 'no' only)\n\n";
		}	
};

class State
{
	private:
		std::string name;
		std::string status;
		float chance;
	public:
		State()
		{
			name = "";
			status = "";
			chance = 0.0;
		}
		void setName(std::string n)
		{
			name = n;
		}
		void setStatus(std::string _status)
		{
			status = _status;
		}
		void setChance(float c)
		{
			chance = c;
		}
		std::string getName()
        {
            return name;
        }
		std::string getStatus()
        {
            return status;
        }
		float getChance()
        {
            return chance;
        }
};

//main kosongin, diisi terakhir
int main()
{
    std::cout << "\n";
    system("pause");
    return 0;
}