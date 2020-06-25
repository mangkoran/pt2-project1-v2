#include<iostream>

using namespace std;

//tambahin kodemu mulai dibawah ini
class Symptom
{
private:
    /* data */
public:
    Symptom(/* args */);
};

class State
{
private:
    /* data */
public:
    State(/* args */);
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
        // if(count != 0)                          //if no symmptom, chance = 0
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



//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}