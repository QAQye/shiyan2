#include "smartcar.h"
#include <windows.h>
using std::cout;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Smartcar *car=new Smartcar();
    car->save();

}