#include<iostream>

using namespace std;
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

//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}