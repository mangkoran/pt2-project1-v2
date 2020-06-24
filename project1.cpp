#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Symptom
{
	private:
		string name;
		float chance;
		string question;
	public:
		Symptom()
		{
			name = "";
			chance = 0.0;
			question = "";
			
		}
		void setName(string _name)
		{
			name = _name;
		}
		void setChance(float _chance)
		{
			chance = _chance;
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
	        cout << "\nIn the last 14 days, do you:\n";
            cout << "(please answer with 'yes' or 'no' only)\n\n";
		}	
};

class State
{
	private:
		string name;
		string status;
		float chance;
	public:
		State()
		{
			name = "";
			status = "";
			chance = 0.0;
		}
		void setName(string n)
		{
			name = n;
		}
		void setStatus(string _status)
		{
			status = _status;
		}
		void setChance(float c)
		{
			chance = c;
		}
		string getName()
        {
            return name;
        }
		string getStatus()
        {
            return status;
        }
		float getChance()
        {
            return chance;
        }
        void readFile()
        {
            ifstream fin ("statezone.txt");
			int count = 0;
			while ( getline(fin,name,',') )
			{
				getline(fin,status);
				count++;
			}
			fin.close();
        }
};

//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}