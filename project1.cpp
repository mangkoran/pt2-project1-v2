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
private:
    string name;
    int age;
    int count;
    Symptom** symptom;
    State** currLoc;
    int chance;
public:
    Person(/* args */);
    void setName()
    {

    }
    void setAge()
    {

    }
    void addSymptom(Symptom* s)
    {
        Symptom** temp = new Symptom*;

    }
};



//main kosongin, diisi terakhir
int main()
{
    cout << "\n";
    system("pause");
    return 0;
}