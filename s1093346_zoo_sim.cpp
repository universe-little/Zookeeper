#include <iostream>
#include "s1093346_zoo_stu.h"
using namespace std;
int main()
{
    cout << "Hello World!\n";
    Zoo ZooSim1(5);

    ZooSim1.AddAnimal(new horse("Pony", 100));
    ZooSim1.AddAnimal(new pig("Piggy", 100));
    ZooSim1.AddAnimal(new human("Pony", 100));
    ZooSim1 += new pig("Piggy", 100);
    ZooSim1.Listing();
    cout << "==================================\n";
    //...example...
    cout << ZooSim1 << endl;
    ZooSim1.Run(3);
    cout << "==================================\n";
    cout << "---Test getMorefood()--- \n";
    cout << "Before:  "<< ZooSim1 << endl;
    ZooSim1.getMoreFood(100);
    cout << "After:  " << ZooSim1 << endl;
    ZooSim1.getMoreFood(500);
    cout << "==================================\n";
    cout << "---Test food/water Insufficient--- \n";
    ZooSim1.Listing();
    while (ZooSim1.FeedFood(10)) {}
    while (ZooSim1.FeedWater(20)) {}
    ZooSim1.Listing();
    //...
    /*
    while (!ZooSim1.isBankrupt())
    {
        cout << ZooSim1 << endl;
        ZooSim1.Run();
    }*/
}