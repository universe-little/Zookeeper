#include<iostream>
#include<vector>
#include<string>
#include "s1093346_zoo_stu.h"
using namespace std;

int Animal::feed(int amount) 
{
    hungry -= amount;
    if (hungry < 0)
    {
        hungry = 0;
    }
    cout << "[LOG] " << Name << " eat " << amount << " food" << endl;
    return hungry;
}

int horse::feed(int amount) 
{
    Animal::feed(amount);
    energy += amount * 2;
    if (energy > 100)
    {
        energy = 100;
    }
    return hungry;
}

int pig::feed(int amount)
{
    if (hungry < amount)
    {
        int food = amount - hungry;
        energy += 2*food;
    }
    Animal::feed(amount);
    if (hungry == 0)
    {
        energy += 2 * amount;
    }
    return hungry;
}

int human::feed(int amount)
{
    energy -= 10;
    Animal::feed(amount);
    energy += amount;
    if (energy > 100)
    {
        energy = 100;
    }
    return hungry;
}

int Animal::exercise(int times)
{
    int money = 0;
    return money;
}

int horse::exercise(int times)
{
    if (energy > 0)
    {
        for (int i = 0; i < times; i++)
        {
            if (hungry < 100 && energy >0)
            {
                energy -= 35;
                hungry += 35;
                money += 50;
                if (hungry >= 100)
                {
                    hungry = 100;
                }
                if (energy < 0)
                {
                    energy = 0;
                }
            }
            else if( energy > 0)
            {
                energy -= 50;
                money += 25;
                if (energy < 0)
                {
                    energy = 0;
                }
            }
        }
        cout << "[LOG] " << Name << " do exercise and earn " << money << "$" << endl;
    }
    else if (energy <= 0)
    {
        energy = 0;
        cout << "[LOG] " << Name << " is Exhausted!!! " << endl;
    }
    return money;
}

int pig::exercise(int times)
{
    if (energy > 0 && hungry < 50)
    {
        for (int i = 0; i < times; i++)
        {
            if (energy > 0 && hungry < 50)
            {
                energy -= 35;
                hungry += 20;
                money += 100;
                if (energy < 0)
                {
                    energy = 0;
                }
                if (hungry > 50)
                {
                    hungry = 50;
                }
            }
        }
        cout << "[LOG] " << Name << " do exercise and earn " << money << "$" << endl;
    }
    else if (hungry >= 50 && energy <= 0)
    {
        energy = 0;
        hungry = 50;
        cout << "[LOG] " << Name << " is Exhausted & Hungry!!!" << endl;
    }
    else if (hungry >= 50)
    {
        hungry = 50;
        cout << "[LOG] " << Name << " is Hungry!!! " << endl;
    }
    else if (energy <= 0)
    {
        energy = 0;
        cout << "[LOG] " << Name << " is Exhausted!!! " << endl;
    }
    return money;
}

int human::exercise(int times)
{
    if (energy > 0 && hungry <= 150)
    {
        energy -= 10;
        for (int i = 0; i < times; i++)
        {
            if (energy > 0 && hungry <= 150)
            {
                energy -= 35;
                hungry += 35;
                money += 100;
                if (energy <= 0)
                {
                    energy = 0;
                }
                if (hungry >= 150)
                {
                    hungry = 150;
                }
            }
        }
        cout << "[LOG] " << Name << " do exercise and earn " << money << "$" << endl;
    }
    else if (hungry >= 150 && energy <= 0)
    {
        hungry = 150;
        energy = 0;
        cout << "[LOG] " << Name << " is Exhausted & Hungry!!!" << endl;
    }
    else if (hungry >= 150)
    {
        hungry = 150;
        cout << "[LOG] " << Name << " is Hungry!!! " << endl;
    }
    else if (energy <= 0)
    {
        energy = 0;
        cout << "[LOG] " << Name << " is Exhausted!!! " << endl;
    }
    return money;
}

int Animal::rest(int& food, int& water)
{
    return energy;
}

int horse::rest(int& food, int& water)
{
    int energyCount = 0;
    int foodCount = 0;
    int waterCount = 0;
    if (water >= 10)
    {
        water -= 10;
        waterCount += 10;
        energy += 10;
        energyCount += 10;
        if (energy > 100)
        {
            energy = 100;
        }
    }
    cout << "[LOG] " << Name << " take a rest, eat " << foodCount << " food & drink " << waterCount << " water, gain " << energyCount << " energy" << endl;
    return energy;
}

int pig::rest(int& food, int& water)
{
    int energyCount = 0;
    int foodCount = 0;
    int waterCount = 0;
    if (food >= 10)
    {
        foodCount += 10;
        food -= 10;
    }
    cout << "[LOG] " << Name << " take a rest, eat " << foodCount << " food & drink " << waterCount << " water, gain " << energyCount << " energy" << endl;
    return energy;
}

int human::rest(int& food, int& water)
{
    int energyCount = 0;
    int foodCount = 0;
    int waterCount = 0;
    if (water >= 20 && food >= 10)
    {
        water -= 20;
        waterCount += 20;
        food -= 10;
        foodCount += 10;
        energy += 10;
        energyCount += 20;
        if(energy > 100)
        {
            energy = 100;
        }
    }
    cout << "[LOG] " << Name << " take a rest, eat " << foodCount << " food & drink " << waterCount << " water, gain " << energyCount << " energy" << endl;
    return energy;
}

int Animal::drink(int amount)
{
    energy += amount;
    if (energy > 100)
    {
        energy = 100;
    }
    cout << "[LOG] " << Name << " drink " << amount << " water" << endl;
    return energy;
}

int horse::drink(int amount)
{
    Animal::drink(amount);
    return energy;
}

int pig::drink(int amount)
{
    Animal::drink(amount);
    return energy;
}

int human::drink(int amount)
{
    energy -= 10;
    energy += 2*amount;
    if (energy > 100)
    {
        energy = 100;
    }
    cout << "[LOG] " << Name << " drink " << amount << " water" << endl;
    return energy;
}