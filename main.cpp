#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void UpdateAnyIntVariable(int* VariableToUpdate){
    *VariableToUpdate = 1;

}




int main(){
    int a = 6;

    UpdateAnyIntVariable(&a);

    cout << a;


}
