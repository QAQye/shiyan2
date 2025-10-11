#include "tire.h"
#include <fstream>
using std::ios;
using std::ifstream;
using std::ofstream;
using std::endl;
Tire::Tire(string model,string size):
    model(model),size(size){}
void Tire::setModel(string model){
    this->model=model;
}
void Tire::setSize(string size){
    this->size=size;
}
void Tire::print(){
    cout<<"轮胎信息："<<endl;
    cout<<"  型号: "<<model<<endl;
    cout<<"  尺寸: "<<size<<endl;
}
void Tire::save(string url,bool add){
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
    ofs<<"轮胎信息："<<endl;
    ofs<<"  型号: "<<model<<endl;
    ofs<<"  尺寸: "<<size<<endl;   
}