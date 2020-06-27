#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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
    vector<Symptom*> symptom;
    State* currLoc;
    int chance;
public:
    Person()
    {
        name = "";
        age = 0;
        count = 0;
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
        symptom.push_back(s);
    }
    void setCurrLoc(State* s)
    {
        currLoc = s;
    }
    virtual void setChance()
    {
        if(count != 0)                          //count == 0 -> no symptom
        {
            for(auto i : symptom) chance += i->getChance();
        }
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
            for(auto i : symptom) chance += i->getChance();
        }
        chance += currLoc->getChance();
        chance += prevLoc->getChance();
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
            for(auto i : symptom)  chance += i->getChance();
        }
        chance += currLoc->getChance();
        chance += 5;
    }
};

class DiseaseHistory
{
private:
    string name;
    int chance;
public:
    DiseaseHistory()
    {
        name = "";
    }
    void setName (string disease)
    {
        name = disease;
    }
    void setChance (int c)
    {
        chance = c;
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
    vector<Symptom> vec;
    intro0();
    cout << "\n";
    system("pause");
    return 0;
}