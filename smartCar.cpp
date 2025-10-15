#include "smartcar.h"
#include <ctime>
#include <fstream>
using std::ofstream;
using std::endl;
using std::ios;
Smartcar::Smartcar(){
    string id=alloctId();
    setId(id);
}
Smartcar::Smartcar(string id,Chassis chassis,Agx agx,StereoCamera camera,Lidar lidar,IMU9 imu,
        Display display,Battery battery):id(id),chassis(chassis),agx(agx),camera(camera),lidar(lidar),imu(imu),display(display),battery(battery){}

string Smartcar::alloctId(){
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string id = "cqusn"; 
    // 按照当前时间戳来生成随机数,从而保证每一次不同
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i=0;i<11;i++){
        id+=chars[rand()%chars.size()];
    }    
    return id;
}
void Smartcar::setId(string id){
    this->id=id;
}
void Smartcar::print(){
    cout << "编号: " << id << endl;
    chassis.print();
    agx.print();
    camera.print();
    lidar.print();
    imu.print();
    display.print();
    battery.print();

}
void Smartcar::save(string url,bool add){
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
    ofs << "Car: " <<  endl;
    ofs << "编号: " << id << endl;
    chassis.save(url,true);
    agx.save(url,true);
    camera.save(url,true);
    lidar.save(url,true);
    imu.save(url,true);
    display.save(url,true);
    battery.save(url,true);

}