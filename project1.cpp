#include<iostream>

using namespace std;

//tambahin kodemu mulai dibawah ini
class DiseaseHistory
{
    private:
        string name;
        float chance;
    public:
        DiseaseHistory(string n = "")
        {
            name = n;
        }
        void setName (string disease)
        {
            name = disease;
        }
        void setChance (float ch)
        {
            chance = ch;
        }
        string getName()
        {
            return name;
        }
        float getChance()
        {
            return chance;
        }
        void printQuestion()
        {
			string ans;
			cout << "(Answer Yes/No)";
			cout << " Do you have any comorbid COVID-19 condition such as ";
			cout << getName() << "\n";
			cout << "Your Answer: ";
			cin >> ans;			
        }
        
};

//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}