#include "stereocamera.h"
#include <windows.h>
using std::cout;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    StereoCamera *stereo=new StereoCamera();
    stereo->save();
}