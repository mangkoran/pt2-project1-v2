#include<iostream>

using namespace std;

//tambahin kodemu mulai dibawah ini
class DiseaseHistory
{
    private:
        std::string name;
        float chance;
    public:
        DiseaseHistory(std::string n = "")
        {
            name = n;
        }
        void setName (std::string disease)
        {
            name = disease;
        }
        void setChance (float ch)
        {
            chance = ch;
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
			std::string ans;
			std::cout << "(Answer Yes/No)";
			std::cout << " Do you have any comorbid COVID-19 condition such as ";
			std::cout << getName() << "\n";
			std::cout << "Your Answer: ";
			std::cin >> ans;			
        }
        
};

//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}