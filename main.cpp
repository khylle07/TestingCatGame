#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cat{
public:
   // attributes or components
    int health;
    int armor;
    int ScratchPower;

    // constructor
    Cat(int CatHealth, int CatScratchPower, int CatArmor) {
        health = CatHealth;
        ScratchPower = CatScratchPower;
        armor = CatArmor;
    }

    void CatStatus(){
        cout << "Health: " << health << endl;
        cout << "Armor: " << armor << endl << endl;
    }

    void DamageOtherCat(Cat& EnemyCat) {
        EnemyCat.TakeDamage(ScratchPower);
    }

    void TakeDamage(int ScratchPower) {
        int TotalScratchPower = ScratchPower - armor;
        cout << "Attacked " << ScratchPower << "damage." << endl << endl;
        if (TotalScratchPower < 0) {
            health -= TotalScratchPower;
        }
    }

    void Dodge(Cat& EnemyCat){
        int dodge = rand() % 2;

        if(dodge == 0){
            cout << "You Dodge an Attack... +10 Armor";
            armor += 10;
        } else{
            cout << "Failed to Dodge" << endl;
            EnemyCat.TakeDamage(ScratchPower);
        }
    }
};

int main(){
    srand(time(0));

    Cat MingMing = Cat(100, 0, 50);
    Cat Meowy = Cat(100, 0, 50);



    while(MingMing.health > 0 && Meowy.health > 0){

        cout << "MingMing Status...." << endl;
        MingMing.CatStatus();
        cout << "Meowy Status" << endl;
        Meowy.CatStatus();

        int choice;

        //player
        cout << "What Do You Want to do?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Dodge" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        MingMing.ScratchPower = rand() % 25 + 1;
        Meowy.ScratchPower = rand() % 25 + 1;

        switch(choice){
        case 1:
            MingMing.DamageOtherCat(Meowy);
            cout << "Meowy Status" << endl;
            Meowy.CatStatus();
            break;
        case 2:
            MingMing.Dodge(Meowy);
            cout << "MingMing Status...." << endl;
            MingMing.CatStatus();
            break;
        default:
            cout << "Invalid Action! Skipping";
            break;
        }

        if(Meowy.health <= 0){
            cout << "Meowy Has Been Defeated! MingMing Wins..." << endl;
            break;
        }

        cout << "Enemy Turn" << endl;
        int EnemyChoice = rand() % 2;
        switch(choice){
        case 0:
            Meowy.DamageOtherCat(MingMing);
            cout << "MingMing Status...." << endl;
            MingMing.CatStatus();
            break;
        case 1:
            Meowy.Dodge(MingMing);
            cout << "Meowy Status" << endl;
            Meowy.CatStatus();
            break;

        }


        if(MingMing.health <= 0){
            cout << "MingMing Has Been Defeated! Meowy Wins..." << endl;
            break;
        }
        cout << "======================================\n";
}

    return 0;
}

