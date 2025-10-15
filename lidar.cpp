#include "lidar.h"
#include <fstream>
#include <algorithm>
using std::ofstream; 
using std::ios;
using std::endl;
Lidar::Lidar(string model,int channels ,string range_m ,string power):model(model),channels(channels),
range_m(range_m),power(power)
{

}
void Lidar::setModel(string model){
    this->model=model;
}
void Lidar::setChannels(int channels){
    this->channels=channels;
}
void Lidar::setRange_m(string range_m){
    this->range_m=range_m;
}
void Lidar::setPower(string power){
    this->power=power;
}
void Lidar::print(){
    cout << "多线激光雷达: " <<  endl;
    cout << "  型号: " << model<< endl;
    cout << "  通道数: " << channels<< endl;
    cout << "  测试范围: " << range_m<< endl;
    cout << "  功耗: " << power<< endl;
}
void Lidar::save(string url,bool add){
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
    ofs << "多线激光雷达: " <<  endl;
    ofs << "  型号: " << model<< endl;
    ofs << "  通道数: " << channels<< endl;
    ofs << "  测试范围: " << range_m<< endl;
    ofs << "  功耗: " << power<< endl;
}
//加入订阅者
void Lidar::addSubscriber(Subscriber * sub){
    // 防止重复加入订阅者
    if (std::find(subscribers.begin(), subscribers.end(), sub) == subscribers.end())
        subscribers.push_back(sub);
}
//移除订阅者
void Lidar::removeSubscriber(Subscriber * sub){
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
}
void Lidar::setState(int state){
    this->state=state;
    publish();
}
void Lidar::publish(){
    for(int i=0;i<subscribers.size();i++){
        // 向订阅者发送更新后的状态
        subscribers[i]->notify(state);
    }

}