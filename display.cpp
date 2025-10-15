#include "display.h"
#include <fstream>
using std::endl;
using std::ios;
using std::ofstream;
Display::Display(string size,string model):
size(size),model(model){}
void Display::setSize(string size){
    this->size=size;
}
void Display::setModel(string model){
    this->model=model;
}
void Display::print(){
        cout << "液晶显示屏: " <<  endl;
        cout << "  尺寸: " << size<< endl;
        cout << "  型号: " << model<< endl;
}
void Display::save(string url,bool add){
    ofstream ofs;
    if(add){
        ofs.open(url,ios::app);
    }
    else{
        ofs.open(url);
    }
    if(!(ofs.is_open())){
        cout<<"文件打开文件失败，无法保存数据"<<endl;
    }
    ofs << "液晶显示屏: " <<  endl;
    ofs << "  尺寸: " << size<< endl;
    ofs << "  型号: " << model<< endl;
}