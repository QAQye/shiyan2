#include "tire.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
Tire::Tire(){}
Tire::Tire(string model,string size):
    model(model),size(size){}
void Tire::setModel(string model){
    this->model=model;
}
void Tire::setSize(string size){
    this->size=size;
}
void Tire::printinfo(){
    cout<<"----------现在开始输出轮胎信息----------"<<endl;
    cout<<"轮胎信息："<<endl;
    cout<<"  型号: "<<model<<endl;
    cout<<"  尺寸: "<<size<<endl;
}
void Tire::saveToDocument(){
    ofstream ofs;
    ofs.open("./tire.txt");
    if(!(ofs.is_open())){
        cout<<"文件打开文件失败，无法保存数据"<<endl;
    }
    ofs<<"轮胎信息："<<endl;
    ofs<<"  型号: "<<model<<endl;
    ofs<<"  尺寸: "<<size<<endl;   
}