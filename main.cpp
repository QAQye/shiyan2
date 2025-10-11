#include "chassis.h"
#include "tire.h"
#include <windows.h>
using std::cout;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Chassis *c=new Chassis();
    c->print();
    c->save();

}