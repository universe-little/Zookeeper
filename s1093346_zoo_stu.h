#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Animal {
public:
    Animal(string inName, int inEnergy = 100) //�W�ٸ��l��O
        : Name(inName), hungry(0), energy(inEnergy) {

    }
    ~Animal() {}
    virtual int feed(int amount); //�ǤJ���Ӷq�A�^�ǰ��j��
    virtual int exercise(int times); //�ǤJ���ơA�^�ǩ��Ȫ���
    virtual int rest(int& food, int& water); //�ݭn�ǤJ�@�Ǹ�T��K�A�վ�ʪ��魹���q ���q...
    virtual int drink(int amount);
    virtual void print() {
        cout << Name << " (hungry: " << hungry << ", energy : " << energy << ")" << endl;
    }
protected:
    string Name;
    int hungry; //hungry index (initial = 0, upper bound is varying)
    int energy; //energy index (initial = 100)
};

class Zoo {
public:
    Zoo(size_t size = 5) 
        : foodCount(500), waterCount(100), deposit(100), sizeLimit(size) 
    {
        house.reserve(size);
    }
    ~Zoo() {}
    int Run(int quantity = 1) {
        for (int i = 0; i < quantity; i++)
        {
            int earnings = 0;
            cout << "The begin of the day" << endl;
            Listing();
            for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) 
            {
                earnings += (*iter)->exercise(2);
            }
            FeedFood(2);
            FeedWater(1);
            for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter)
            {
                earnings += (*iter)->exercise(1);
            }
            AskRest();
            getMoreFood(100);
            FeedFood(4);
            FeedWater(3);
            for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter)
            {
                earnings += (*iter)->exercise(2);
            }
            AskRest();
            FeedFood(1);
            FeedWater(1);
            AskRest();
            for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter)
            {
                earnings += (*iter)->exercise(1);
            }
            FeedFood(4);
            FeedWater(2);
            for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter)
            {
                earnings += (*iter)->exercise(2);
            }
            AskRest();
            deposit += earnings;
            getMoreFood(300);
            waterCount += 200;
            FeedFood(4);
            FeedWater(2);
            AskRest();
            AskRest();
            cout << "The end of the day" << endl;
            cout << "total money: $" << deposit << endl;
        }
        return deposit; //�^���`���q
    }
    bool FeedFood(int quantity = 1) {
        cout << "[LOG] Feeding food...\n";
        int feeds = 0;
        int a = 0;
        for (int j = 0; j < quantity; j++)
        {
            for (int i = 0; i < house.size(); i++)
            {
                if (foodCount >= 50)
                {
                    feeds += 50;
                    house[i]->feed(50);
                    foodCount -= 50;
                }
                else if(foodCount < 50)
                {
                    a++;
                    break;
                }
            }
            if (a == 1)
            {
                break;
            }
        }
        if (foodCount < 50)
        {
            cout << "[WARNING] Insufficient food !!!\n";
            cout << "[LOG] total consume " << feeds << " food.\n";
            return false;
        }
        else
        {
            cout << "[LOG] total consume " << feeds << " food.\n";
            return true;
        }
    }
    bool FeedWater(int quantity = 1) {
        cout << "[LOG] Feeding water...\n";
        int feeds = 0;
        int a = 0;
        for (int j = 0; j < quantity; j++)
        {
            for (int i = 0; i < house.size(); i++)
            {
                if (waterCount >= 10)
                {
                    feeds += 10;
                    house[i]->drink(10);
                    waterCount -= 10;
                }
                else if(waterCount <= 10)
                {
                    a++;
                    break;
                }
            }
            if (a == 1)
            {
                break;
            }
        }
        if (waterCount <= 10)
        {
            cout << "[WARNING] Insufficient water !!!\n";
            cout << "[LOG] total consume " << feeds << " water.\n";
            return false;
        }
        else
        {
            cout << "[LOG] total consume " << feeds << " water.\n";
            return true;
        }
    }
    bool AskRest() {
        cout << "[LOG] ask all animals to rest.\n";
        for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
            (*iter)->rest(foodCount, waterCount);
        }
        return true;
    }
    void Listing() { //�L�X�Ҧ��ʪ���T
        for (vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
            (*iter)->print();
        }
    }
    bool AddAnimal(Animal* inPtr) {
        house.push_back(inPtr);
        if (house.size() > 5)
        {
            cout << "[WARNING] Too many animals !!!" << endl;
            return false;
        }
        return true;
    }
    int getCount() { return house.size(); }
    bool isBankrupt() {
        if (foodCount == 0 && deposit == 0)
            return true;
        //you may update this function
        return false;
    }
    int getMoreFood(int amount) { //try to buy food
        int gain = 0;
        if (deposit >= amount)
        {
            gain = amount * 2;
            deposit -= amount;
            cout << "[LOG] Transfer $ " << amount << " to " << gain << " food" << endl;
        }
        else
        {
            gain = deposit * 2;
            deposit = 0;
            cout << "[LOG] Transfer $ " << amount << "to" << gain << "food" << endl;
            cout << "[WARNING] Insufficient funds !!!" << endl;
        }
        foodCount += gain;
        return gain;
    }
    void operator+=(Animal* animal)
    {
        house.push_back(animal);
    }
   Animal* operator[](int i)
    {
        return house[i];
    }
    friend ostream& operator<<(ostream& output,Zoo& zoo) //[INFO] Food: ###, Water: ###, Foud$: ###$
    {
        cout << "Food: " << zoo.foodCount << ", Water: " << zoo.waterCount << ", Fond$: " << zoo.deposit << "$" << endl;
        return output;
    }

private:
    vector<Animal*> house;
    int foodCount; //�ʪ��魹�� �S�����i�H�Φs���ഫ
    int waterCount; //�ʪ���� �CRUN�|�W�[100;
    int deposit; //�ʪ���s�� �ʪ��B�ʥi�W�[
    const int sizeLimit; //�ʪ���]�p�W��(�즸�Ыخɳ]�w)�i�W�L���l�[�ʪ��|ĵ�i
};

class horse :public Animal
{
    public:
        horse(string inName, int Energy )
            :Animal(inName, Energy)
        {

        }
        ~horse(){}
        int feed(int amount);
        int exercise(int times);
        int rest(int& food, int& water);
        int drink(int amount);
        void print() {
            cout << Name << " (hungry: " << hungry << ", energy : " << energy << ")" << endl;
        }
    private:
        int money = 0;
};

class pig :public Animal
{
    public:
        pig(string inName, int Energy )
            :Animal(inName, Energy)
        {
            
        }
        ~pig(){}
        int feed(int amount);
        int exercise(int times);
        int rest(int& food, int& water);
        int drink(int amount);
        void print() {
            cout << Name << " (hungry: " << hungry << ", energy : " << energy << ")" << endl;
        }
    private:
        int money = 0;
};

class human :public Animal
{
    public:
        human(string inName, int Energy )
            :Animal(inName, Energy)
        {
            
        }
        ~human(){}
        int feed(int amount);
        int exercise(int times);
        int rest(int& food, int& water);
        int drink(int amount);
        void print() {
            cout << Name << " (hungry: " << hungry << ", energy : " << energy << ")" << endl;
        }
    private:
        int money = 0;
};