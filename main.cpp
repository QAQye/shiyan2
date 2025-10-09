#include "tire.h"
#include <windows.h>
using std::cout;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Tire *tire =new Tire();
    tire->printinfo();
    tire->saveToDocument();

}