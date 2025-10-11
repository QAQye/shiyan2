#include "chassis.h"
#include <ctime>
#include <fstream>
using std::ofstream;
using std::endl;
using std::rand;
using std::ios;
 Chassis::Chassis(string id,string model,int wheelbase_mm,int track_mm,int min_clearance_mm,int min_turn_radius,
        string drive,string max_range):
            id(id),model(model),wheelbase_mm(wheelbase_mm),track_mm(track_mm),min_clearance_mm(min_clearance_mm),min_turn_radius(min_turn_radius),drive(drive),max_range(max_range)
            {
                // 在初始化后为其分配一个id号
                setId(allocateid());
                // 并且一个底盘含有四个车轮，因此要将四个车轮也放入底盘中
                for(int i=0;i<4;i++){
                    Tire *t=new Tire();
                    tires.push_back(t);
                }
            }
string Chassis::allocateid(){
    // 这个是随机生成的池子在这里面选取随机数进生成
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    // 因为底盘的编号是以dp开头的8位数字和字母组成
    string id="dp";
    // 按照当前的时间戳来生成随机数
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i=0;i<6;i++){
        id+=chars[rand()%chars.size()];
    }
    return id;
}
void Chassis::setId(string id){
    this->id=id;
}
void Chassis::setModel(string model){
    this->model=model;
}
void Chassis::setWheelbase_mm(int wheelbase_mm){
    this->wheelbase_mm=wheelbase_mm;
}
void Chassis::setTrack_mm(int track_mm){
    this->track_mm=track_mm;
}
void Chassis::setMin_clearance_mm(int min_clearance_mm){
    this->min_clearance_mm=min_clearance_mm;
}
void Chassis::setMin_turn_radius(int min_turn_radius){
    this->min_turn_radius=min_turn_radius;
}
void Chassis::setDrive(string drive){
    this->drive=drive;
}
void Chassis::setMax_range(string max_range){
    this->max_range=max_range;
}

void Chassis::print(){
    cout<<"底盘信息："<<endl;
    cout<<"  编号: "<<id<<endl;
    cout<<"  型号: "<<model<<endl;
    cout<<"  轴距: "<<wheelbase_mm<<endl;
    cout<<"  轮距: "<<track_mm<<endl;
    cout<<"  最小离地间隙: "<<min_clearance_mm<<endl;
    cout<<"  最小转弯半径: "<<min_turn_radius<<endl;
    cout<<"  驱动形式: "<<wheelbase_mm<<endl;
    cout<<"  最大行程: "<<drive<<endl;
    cout<<"  轮胎（4个）: "<<endl;
    tires[0]->print();
}
void Chassis::save(string url,bool add){
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
    ofs<<"底盘信息："<<endl;
    ofs<<"  编号: "<<id<<endl;
    ofs<<"  型号: "<<model<<endl;
    ofs<<"  轴距: "<<wheelbase_mm<<endl;
    ofs<<"  轮距: "<<track_mm<<endl;
    ofs<<"  最小离地间隙: "<<min_clearance_mm<<endl;
    ofs<<"  最小转弯半径: "<<min_turn_radius<<endl;
    ofs<<"  驱动形式: "<<wheelbase_mm<<endl;
    ofs<<"  最大行程: "<<drive<<endl;
    ofs<<"  轮胎（4个）: "<<endl;
    tires[0]->save(url,true);
}
