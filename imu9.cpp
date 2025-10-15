#include "imu9.h"
#include <fstream>
using std::ofstream;
using std::ios;
using std::endl;
IMU9::IMU9(string model,string vendor):
model(model),vendor(vendor)
{

}
void IMU9::setModel(string model){
    this->model=model;
}
void IMU9::setVendor(string vendor){
    this->vendor=vendor;
    
}
void IMU9::print(){
    cout << "9轴陀螺仪（1个）: " <<  endl;
    cout << "  型号: " << model<< endl;
    cout << "  厂家: " << vendor<< endl;
}
void IMU9::save(string url,bool add){
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
    ofs << "9轴陀螺仪（1个）: " <<  endl;
    ofs << "  型号: " << model<< endl;
    ofs << "  厂家: " << vendor<< endl;
}