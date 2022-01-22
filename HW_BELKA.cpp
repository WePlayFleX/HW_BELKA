#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>

using namespace std;

const char* typTreeOne = "coniferous";
const char* typTreeTwo = "deciduous";

class Belka {
private:
    double height;
    double diameter;
    int age;
    char* type;

public:
    Belka() {}
    Belka(double, double, int, char*);
    Belka(const Belka&);
    ~Belka() {}

    void setHeight(double);
    double getHeight() const;

    void setDiameter(double);
    double getDiameter() const;

    void setAge(int);
    int getAge() const;

    void setTypeTree(char*);
    char* getTypeTree() const;

    void output();

};

Belka::Belka(double height, double diam, int age, char* typeTree)
{
    setHeight(height);
    setDiameter(diam);
    setAge(age);
    setTypeTree(typeTree);
}

Belka::Belka(const Belka& cpyP) 
{
    cout << "Belka(const Belka& copyP)" << endl;
    setHeight(cpyP.height);
    setDiameter(cpyP.diameter);
    setAge(cpyP.age);
    setTypeTree(cpyP.type);
}

void Belka::setHeight(double height)
{
    if (height >= 0)
    {
        this->height = height;
    }
    else
    {
        this->height = -height;
    }
}

double Belka::getHeight()const 
{
    return this->height;
}

void Belka::setDiameter(double diam) 
{
    if (diam >= 0)
    {
        this->diameter = diam;
    }
    else
    {
        this->diameter = -diam;
    }
}

double Belka::getDiameter()const
{
    return this->diameter;
}

void Belka::setAge(int age)
{
    if (age >= 0)
    {
        this->age = age;
    }
    else
    {
        this->age = -age;
    }
}

int Belka::getAge()const 
{
    return this->age;
}

void Belka::setTypeTree(char* typeTree) 
{
    int temp = 0;

    for (size_t i = 0; i < strlen(typeTree); i++)
    {
        if (typeTree[i] == typTreeOne[i])
        {
            temp++;
        }
    }

    if (temp == strlen(typTreeOne))
    {
        this->type = new char[strlen(typTreeOne) + 1];
        strcpy_s(this->type, strlen(typTreeOne) + 1, typTreeOne);
    }
    else if (strlen(typeTree) == strlen(typTreeTwo)) 
    {
        temp = 0;

        for (size_t i = 0; i < strlen(typeTree); i++)
        {
            if (typeTree[i] == typTreeTwo[i])
            {
                temp++;
            }
        }

        if (temp == strlen(typTreeTwo))
        {
            this->type = new char[strlen(typTreeTwo) + 1];
            strcpy_s(this->type, strlen(typTreeTwo) + 1, typTreeTwo);
        }
    }
    else
    {
        cerr << "Error! " << endl;
        this->type = new char[10];
        strcpy_s(this->type, strlen(typTreeTwo) + 1, "Not found.");
    }
}

char* Belka::getTypeTree()const 
{
    char* copyType = new char[strlen(this->type)];
    strcpy_s(copyType, strlen(this->type), this->type);

    return copyType;
}

void Belka::output()
{
    cout << "Height tree: " << this->height << endl;
    cout << "Diameter of tree: " << this->diameter << endl;
    cout << "Age of tree: " << this->age << endl;
    cout << "Type tree: " << type << endl;
}

class Park
{
private:
    Belka indefication;

public:
    Park(double H, double D, int A, char* T) : indefication(H, D, A, T) {}

};

int main()
{
    srand(time(nullptr));

    int random = rand() % 100 + 1;
    if (random % 2 == 0)
    {
        random = 1;
    }
    else
    {
        random = 2;
    }
    double H = 19.3;
    double D = 8.1;
    int A = 77;
    char* T = new char[11]{ " " };
    char* T1 = new char[11]{ "Conf" };
    char* T2 = new char[11]{ "Dec" };

    if (random == 1)
    {
        T = T1;
    }
    else if (random == 2)
    {
        T = T2;
    }
    Belka obj;
    obj.setHeight(H);
    obj.setDiameter(D);
    obj.setAge(A);
    obj.setTypeTree(T);

    cout << "Characters of tree: " << endl;
    obj.output();

    system("pause");
    return 0;
}


