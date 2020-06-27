#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

//tambahin kodemu mulai dibawah ini
class Symptom
{
private:
    string name;
    int chance;
    string question;
public:
    Symptom()
    {
        name = "";
        chance = 0;
        question = "";
    }
    void setName(string n)
    {
        name = n;
    }
    void setChance(int c)
    {
        chance = c;
    }
    void setQuestion(string q)
    {
        question = q;
    }
    string getName()
    {
        return name;
    }
    int getChance()
    {
        return chance;
    }
    string getQuestion()
    {
        return question;
    }
};

class State
{
private:
    string name;
    string status;
    int chance;
public:
    State()
    {
        name = "";
        status = "";
        chance = 0;
    }
    void setName(string n)
    {
        name = n;
    }
    void setStatus(string s)
    {
        status = s;
        setChance();
    }
    void setChance()
    {
        if(status == "Green") chance = 0;
        else if(status == "Yellow") chance = 10;
        else if(status == "Red") chance = 20;
    }
    string getName()
    {
        return name;
    }
    string getStatus()
    {
        return status;
    }
    int getChance()
    {
        return chance;
    }
    // void readFile()
    // {
    //     ifstream fin ("statezone.txt");
    //     int count = 0;
    //     while ( getline(fin,name,',') )
    //     {
    //         getline(fin,status);
    //         count++;
    //     }
    //     fin.close();
    // }
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
        // for(auto i : symptom)
        //     chance += i->getChance();
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
        for(auto i : symptom)
            chance += i->getChance();

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
        for(auto i : symptom)
            chance += i->getChance();

        chance += currLoc->getChance();
        chance += 10;
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
        chance = 0;
    }
    void setName (string s)
    {
        name = s;
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