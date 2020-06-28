#include<iostream>
#include<exception>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;

//tambahin kodemu mulai dibawah ini

//thrown if user enter invalid input
class InvalidInput: public exception
{
    const char* what() const throw()
    {
        return "\nInvalid input. Program is exiting...";
    }
} invinput;

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
        else if(status == "Yellow") chance = 5;
        else if(status == "Red") chance = 10;
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
};

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

class Person
{
protected:
    string name;
    int age;
    vector<Symptom*> symptom;
    State* currLoc;
    int dh;                         //diseaseHistory indicator, 1 if person have had the disease
    int chance;
public:
    Person()
    {
        name = "";
        age = 0;
        currLoc = NULL;
        dh = 0;
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
    void setDh(int i)
    {
        dh = i;
    }
    virtual void setChance()
    {
        
    }
    void addChance(int i)
    {
        chance += i;
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
        // chance += prevLoc->getChance();
        if(dh == 1) chance += 10;
    }
};

class Foreign: public Person
{
private:
    /* data */
public:
    Foreign() {};
    void setChance()
    {
        for(auto i : symptom)
            chance += i->getChance();

        chance += currLoc->getChance();
        if(dh == 1) chance += 10;
        chance += 10;
        
    }
};

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

void intro()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Hi, I'm Albert Bot. I'm going to ask you some questions.           !\n"
         << "   !       I will use your answers to give you advice about the right level   !\n"
         << "   !       of medical care you should seek.                                   !\n"
         << "   !                                                                          !\n"
         << "   !       Let's get started.                                                 !\n"
         << "   !                                                                          !\n"
         << "   !       Note: To exit the application, please close the window             !\n"
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
        cout << "   !       " << left << setw(4) << i+1 << setw(63) << state[i].getName() << "!\n";     //kalau pakai setw -> char[82] (81+1)
    cout << "   \\__________________________________________________________________________/\n";
}

void overseas()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Did you travel overseas in the last two weeks?                     !\n"
         << "   !                                                                          !\n"
         << "   !       1    Yes                                                           !\n"
         << "   !       2    No                                                            !\n";
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

void analysisLoading()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       I'm analyzing your answers...                                      !\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void analysis(Local& l)
{
    int chance = l.getChance();
    if(chance < 33)
    {
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       RECOMMENDATION                                                     !\n"
             << "   !                                                                          !\n"
             << "   !       Follow preventive measures.                                        !\n";
        cout << "   \\__________________________________________________________________________/\n";
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       It looks like your symptoms do not suggest that you have           !\n"
             << "   !       COVID-19. Continue following the common measures                   !\n"
             << "   !       and government directives to avoid contracting COVID-19.           !\n";
        cout << "   \\__________________________________________________________________________/\n";
    }
    else if(chance < 66)
    {
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       RECOMMENDATION                                                     !\n"
             << "   !                                                                          !\n"
             << "   !       Quarantine.                                                        !\n";
        cout << "   \\__________________________________________________________________________/\n";
        cout << "______________________________________________________________________________ \n"
            << "   \\                                                                          \\\n"
            << "   !       Your symptoms currently do not suggest that you have COVID-19.     !\n"
            << "   !       However, according to the WHO and CDC guidelines,                  !\n"
            << "   !       it is strongly recommended that you keep yourself separated        !\n"
            << "   !       from others for the next 14 days.                                  !\n";
        cout << "   \\__________________________________________________________________________/\n";
    }
    else
    {
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       RECOMMENDATION                                                     !\n"
             << "   !                                                                          !\n"
             << "   !       Call the emergency number. Avoid all contact.                      !\n";
        cout << "   \\__________________________________________________________________________/\n";
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       Your symptoms are very serious and you may have COVID-19.          !\n";
        cout << "   \\__________________________________________________________________________/\n";
    }
}

void analysis(Foreign& f)
{
    int chance = f.getChance();
    if(chance < 50)
    {
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       RECOMMENDATION                                                     !\n"
             << "   !                                                                          !\n"
             << "   !       Quarantine.                                                        !\n";
        cout << "   \\__________________________________________________________________________/\n";
        cout << "______________________________________________________________________________ \n"
            << "   \\                                                                          \\\n"
            << "   !       Your symptoms currently do not suggest that you have COVID-19.     !\n"
            << "   !       However, according to the WHO and CDC guidelines,                  !\n"
            << "   !       it is strongly recommended that you keep yourself separated        !\n"
            << "   !       from others for the next 14 days.                                  !\n";
        cout << "   \\__________________________________________________________________________/\n";
    }
    else
    {
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       RECOMMENDATION                                                     !\n"
             << "   !                                                                          !\n"
             << "   !       Call the emergency number. Avoid all contact.                      !\n";
        cout << "   \\__________________________________________________________________________/\n";
        cout << "______________________________________________________________________________ \n"
             << "   \\                                                                          \\\n"
             << "   !       Your symptoms are very serious and you may have COVID-19.          !\n";
        cout << "   \\__________________________________________________________________________/\n";
    }
}

void checkPrev(vector<Local>& l, vector<Foreign>& f)
{
    int localN = l.size();
    int foreignN = f.size();
    if(localN + foreignN == 0) return;
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Please be safe!                                                    !\n"
         << "   !                                                                          !\n"
         << "   !       There are " << left << setw(2) << localN + foreignN << setw(55) << " person that may have COVID-19" << "!\n"
         << "   !       tracked with this application.                                     !\n";
    cout << "   \\__________________________________________________________________________/\n";
}

void end()
{
    cout << "______________________________________________________________________________ \n"
         << "   \\                                                                          \\\n"
         << "   !       Thank you for chatting with me.                                    !\n"
         << "   !       Stay safe and be healthy!                                          !\n";
    cout << "   \\__________________________________________________________________________/\n";
}
//main kosongin, diisi terakhir
int main()
{
    vector<DiseaseHistory> vecDh = dhInput();
    vector<State> vecSt = stateInput();
    vector<Symptom> vecS = symptomInput();
    vector<Local> vecL;
    vector<Foreign> vecF;

    while(1)
    {
        Local l;
        Foreign f;
        int temp;
        int a;                  //temp for age
        int cL;                 //temp for current location
        int o;                  //temp for overseas
        string dh;
        string s;

        system("cls");
        intro();
        Sleep(1000);
        
        try
        {
            gender();
            cout << "\n   Your input: ";
            cin >> temp;
            Sleep(1000);
            if(temp != 1 && temp != 2) throw invinput;
            
            age();
            cout << "\n   Your input: ";
            cin >> a;
            Sleep(1000);
            if(a < 1 || a > 100) throw invinput;
            
            location(vecSt);
            cout << "\n   Your input: ";
            cin >> cL;
            Sleep(1000);
            if(cL < 1 || cL > vecSt.size()) throw invinput;
            
            overseas();
            cout << "\n   Your input: ";
            cin >> o;
            Sleep(1000);
            if(o != 1 && o != 2) throw invinput;
            if(o == 1)
            {
                f.setAge(a);
                f.setCurrLoc(&vecSt[cL-1]);
            }
            else if(o == 2)
            {
                l.setAge(a);
                l.setCurrLoc(&vecSt[cL-1]);
            }

            diseaseHistory(vecDh);
            cout << "\n   Your input: ";
            cin >> temp;
            Sleep(1000);
            if(temp != 1 && temp != 2) throw invinput;
            if(temp == 1)
            {
                if(o == 1) f.setDh(1);
                else if(o == 2) l.setDh(1);
            }

            symptom(vecS);
            cout << "\n   Your input: ";
            cin.ignore();
            getline(cin, s);
            Sleep(1000);
            if(o == 1)
            {
                for(char i : s)
                {
                    if(i == ' ') continue;
                    int j = i - '0' - 1;
                    for(int k = 0; k < vecS.size(); ++k)
                    {
                        if(j == k)
                        {
                            f.addSymptom(&vecS[j]);
                        }
                    }
                }
            }
            else if(o == 2)
            {
                for(char i : s)
                {
                    if(i == ' ') continue;
                    int j = i - '0' - 1;
                    for(int k = 0; k < vecS.size(); ++k)
                    {
                        if(j == k)
                        {
                            l.addSymptom(&vecS[j]);
                        }
                    }
                }
            }

            if(o == 1)
            {
                for(auto i : *f.getSymptom())
                {
                    symptomQuestion(i);
                    cout << "\n   Your input: ";
                    cin >> temp;
                    if(temp != 1 && temp != 2) throw invinput;
                    if(temp == 1) f.addChance(10);
                    Sleep(1000);
                }
            }
            else if(o == 2)
            {
                for(auto i : *l.getSymptom())
                {
                    symptomQuestion(i);
                    cout << "\n   Your input: ";
                    cin >> temp;
                    if(temp != 1 && temp != 2) throw invinput;
                    if(temp == 1) l.addChance(10);
                    Sleep(1000);
                }
            }
        }
        catch(const exception& e)
        {
            cout << e.what() << '\n';
            cout << "\n";
            system("pause");
            return 0;
        }

        analysisLoading();
        Sleep(1000);
        if(o == 1) f.setChance();
        else if(o == 2) l.setChance();

        if(o == 1) analysis(f);
        else if(o == 2) analysis(l);
        Sleep(1000);

        checkPrev(vecL, vecF);
        Sleep(1000);

        end();
        if(o == 1)
        {
            vecF.push_back(f);
        }
        else if(o == 2)
        {
            if(l.getChance() >= 50)
                vecL.push_back(l);
        }

        cout << "Local chance: " << l.getChance() << "\n";
        cout << "Foreign chance: " << f.getChance() << "\n";
        system("pause");
    }


    cout << "\n";
    system("pause");
    return 0;
}