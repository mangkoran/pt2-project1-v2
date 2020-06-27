#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//tambahin kodemu mulai dibawah ini
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

class Person
{
protected:
    string name;
    int age;
    int count;
    Symptom** symptom;
    State* currLoc;
    int chance;
public:
    Person()
    {
        name = "";
        age = 0;
        count = 0;
        symptom = NULL;
        currLoc = NULL;
        chance = 0;

    };
    void setName(string n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void addSymptom(Symptom* s)
    {
        ++count;
        Symptom** temp = new Symptom*[count];   //pointer to pointer to class
        for(int i = 0; i < count-1; ++i)        //if count == 1 this loop is ignored
        {
            temp[i] = symptom[i];               //assign symptom element into temp element
        }
        temp[count-1] = s;                      //assign s into last temp element
        symptom = temp;                         //assign temp into symptom
        if(count == 1) delete temp;             //delete temp memory
        else delete[] temp;


    }
    void setCurrLoc(State* s)
    {
        currLoc = s;
    }
    virtual void setChance()
    {
        // if(count != 0)                          //count == 0 -> no symptom
        // {
        //     for(int i = 0; i < count; ++i)
        //     {
        //         // chance += symptom[i]->getChance();
        //     }
        // }
    }
    string getName()
    {
        return name;
    }
    int getChance()
    {
        return chance;
    }
};

class Local: public Person
{
private:
    State* prevLoc;
public:
    Local()
    {
        prevLoc = NULL;
    };
    void setPrevLoc(State* s)
    {
        prevLoc = s;
    }
    void setChance()
    {
        if(count != 0)
        {
            for(int i = 0; i < count; ++i)
            {
                // chance += symptom[i]->getChance();
            }
        }
        // chance += currLoc->getChance();
        // chance += prevLoc->getChance();
    }
};

class Foreign: public Person
{
private:
    /* data */
public:
    Foreign();
    void setChance()
    {
        if(count != 0)                          //count == 0 -> no symptom
        {
            for(int i = 0; i < count; ++i)
            {
                // chance += symptom[i]->getChance();
            }
        }
        // chance += currLoc->getChance();
        // chance += prevLoc->getChance();
        chance += 5;
    }
};

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

void intro0()
{
    cout << "_______________________________________________________________________________ \n"
         << "    \\                                                                          \\\n"
         << "    !      Hi, I'm LiSA. I'm goint to ask you some questions                   !\n"
         << "    !      I will use your answers to give you advice about the right level    !\n"
         << "    !      of medical care you should seek.                                    !\n"
         << "    !                                                                          !\n"
         << "    !      Let's get started.                                                  !\n"
         << "    \\__________________________________________________________________________/\n";
}

//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}