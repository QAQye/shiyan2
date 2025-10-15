#include "battery.h"
#include <fstream>
using std::ofstream;
using std::ios;
using std::endl;
Battery::Battery(string parameter,string output,string charge_time):parameter(parameter),output(output),charge_time(charge_time){}
void Battery::setParameter(string parameter){
    this->parameter=parameter;
}
void Battery::setOutput(string output){
    this->output=output;
}
void Battery::setCarge_time(string charge_time){
    this->charge_time=charge_time;
}
void Battery::print(){
    cout << "电池模块: " <<  endl;
    cout << "  参数: " << parameter<< endl;
    cout << "  对外供电: " << output<< endl;
    cout << "  充电时长: " << charge_time<< endl;

}
void Battery::save(string url,bool add){
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
    ofs << "电池模块: " <<  endl;
    ofs << "  参数: " << parameter<< endl;
    ofs << "  对外供电: " << output<< endl;
    ofs << "  充电时长: " << charge_time<< endl;
}