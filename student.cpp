 #include "student.h"
 #include <fstream>
 using std::ofstream;
 using std::endl;
 using std::cout;
 using std::ios;
Student::Student(string id,string name):
    id(id),name(name){}
void Student::setId(string id){
    this->id=id;
}
void Student::setName(string name){
    this->name=name;
}
void Student::print(){
    cout << "学生学号: " << id << endl;
    cout << "学生姓名: " << name << endl;
}
void Student::save(string url){
    ofstream ofs;
    ofs.open(url,ios::app);
    if(!(ofs.is_open())){
        cout<<"文件打开文件失败，无法保存数据"<<endl;
    }
    ofs << "学号: " << id << endl;
    ofs << "姓名: " << name << endl;
}