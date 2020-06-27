#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<Windows.h>
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
    vector<Symptom*>* getSymptom()
    {
        return &symptom;
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

vector<Symptom> symptomInput()
{
    vector<Symptom> vTemp;      //temp for vector of Symptom
    Symptom cTemp;              //temp for Symptom
    string nTemp;               //temp for name
    string chTemp;              //temp for chance
    string qTemp;               //temp for question
    ifstream inf("symptom.txt");
    while(!inf.eof())
    {
        getline(inf, nTemp, ',');
        getline(inf, chTemp, ',');
        getline(inf, qTemp, '\n');
        cTemp.setName(nTemp);
        cTemp.setChance(stoi(chTemp));
        cTemp.setQuestion(qTemp);
        vTemp.push_back(cTemp);
    }
    inf.close();
    return vTemp;
}

vector<State> stateInput()
{
    vector<State> vTemp;        //temp for vector of State
    State cTemp;                //temp for State
    string nTemp;               //temp for name
    string sTemp;               //temp for status
    ifstream inf("state.txt");
    while(!inf.eof())
    {
        getline(inf, nTemp, ',');
        getline(inf, sTemp, '\n');
        cTemp.setName(nTemp);
        cTemp.setStatus(sTemp);
        vTemp.push_back(cTemp);
    }
    inf.close();
    return vTemp;
}

vector<DiseaseHistory> dhInput()
{
    vector<DiseaseHistory> vTemp;   //temp for vector of DiseaseHistory
    DiseaseHistory cTemp;           //temp for DiseaseHistory
    string nTemp;                   //temp for name
    string chTemp;                  // temp for chance
    ifstream inf("diseasehistory.txt");
    while(!inf.eof())
    {
        getline(inf, nTemp, ',');
        getline(inf, chTemp, '\n');
        cTemp.setName(nTemp);
        cTemp.setChance(stoi(chTemp));
        vTemp.push_back(cTemp);
    }
    inf.close();
    return vTemp;
}

void intro()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Hi, I'm LiSA. I'm going to ask you some questions.                 !\n"
         << "   !       I will use your answers to give you advice about the right level   !\n"
         << "   !       of medical care you should seek.                                   !\n"
         << "   !                                                                          !\n"
         << "   !       Let's get started.                                                 !\n"
         << "   \\__________________________________________________________________________/\n";
}

void gender()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       What is your gender?                                               !\n"
         << "   !                                                                          !\n"
         << "   !       1    Male                                                          !\n"
         << "   !       2    Female                                                        !\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void age()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       What is your age?                                                  !\n";
    cout << "   \\__________________________________________________________________________/\n";
}
void location(vector<State>& state)
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Where in the Malaysia are you located?                             !\n"
         << "   !                                                                          !\n";
    for(int i = 0; i < state.size(); ++i)
        cout << "   !       " << left << setw(4) << i+1 << setw(63) << state[i].getName() << "!\n";     //kalau pakai setw -> char[82] (+1)
    cout << "   \\__________________________________________________________________________/\n";
}

void diseaseHistory(vector<DiseaseHistory>& dh)
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Do you have any of these disease previously?                       !\n"
         << "   !                                                                          !\n";
    for(int i = 0; i < dh.size(); ++i)
        cout << "   !       " << left << setw(4) << i+1 << setw(63) << dh[i].getName() << "!\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void symptom(vector<Symptom>& symptom)
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Do you have any of the following symptoms?                         !\n"
         << "   !                                                                          !\n";
    for(int i = 0; i < symptom.size(); ++i)
        cout << "   !       " << left << setw(4) << i+1 << setw(63) << symptom[i].getName() << "!\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void symptomQuestion(Symptom* sq)
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       " << left << setw(67) << sq->getQuestion() << "!\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void last()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       I'm analyzing your answers...                                      !\n";
    cout << "   \\__________________________________________________________________________/\n";
}

//main kosongin, diisi terakhir
int main()
{
    vector<DiseaseHistory> dh = dhInput();
    vector<Symptom> s = symptomInput();
    vector<Local> l;
    // Local l;
    int temp;

    intro();
    Sleep(3000);
    gender();
    cout << "\n   Your input: ";
    cin >> temp;
    Sleep(3000);
    age();
    cout << "\n   Your input: ";
    cin >> temp;
    Sleep(3000);
    diseaseHistory(dh);
    cout << "\n   Your input: ";
    cin >> temp;
    Sleep(3000);
    symptom(s);
    cout << "\n   Your input: ";
    cin >> temp;
    Sleep(3000);
    l[0].addSymptom(&s[0]);
    symptomQuestion((*l[0].getSymptom())[0]);
    cout << "\n   Your input: ";
    cin >> temp;
    Sleep(3000);
    last();
    

    cout << "\n";
    system("pause");
    return 0;
}