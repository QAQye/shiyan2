#include "smartcar.h"
#include "student.h"
#include <windows.h>
#include <vector>
#include <ctime>
#include <fstream>
using std::ios;
using std::ifstream;
using std::endl;
using std::vector;
using std::ofstream;
using std::cout;
void insrtcars(vector<Smartcar> &cars);
void insertstudents(vector<Student> &students);
void allocate(vector<Smartcar> cars,vector<Student> students);
void showPage(const string & filename);
void testPublishAndSubscriber();
int main(){
    // 用于设置终端显示的字符编码，否则是乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int cmd;
    cout<<"请输入你想要执行的操作"<<endl;
    cout<<"-----1.进行预览功能-----"<<endl;
    cout<<"-----2.进行雷达和底盘的订阅者模式测试-----"<<endl;
    std::cin>>cmd;
    if(cmd==1){
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        vector <Smartcar> cars;
        vector <Student> students;
        insrtcars(cars);
        insertstudents(students);
        allocate(cars,students);
        cout<<"相关小车信息、学生信息、分配信息已保存，请按下任意键进入浏览....."<<endl;
        system("pause");
        showPage("./document/allocation.txt");

    }
    else if(cmd==2){
        testPublishAndSubscriber();
    }
    else{
        cout<<"退出"<<endl;
    }

}
void insrtcars(vector<Smartcar> &cars){
    // 先保证写文件被清理
    std::ofstream ofs1("./document/smartcar.txt", std::ios::trunc);
    ofs1.close();
    for (int i=0;i<10;i++){
        Smartcar *car=new Smartcar();
        cars.push_back(*car);
    }
    for (int i=0;i<10;i++){
        ofstream ofs;
        ofs.open("./document/smartcar.txt",ios::app);
        ofs<<"Car "<<i+1<<endl;
        cars[i].save("./document/smartcar.txt",true);
        ofs<<"-----------------------------------------------"<<endl;
    }
}
void insertstudents(vector<Student> &students){
    // 先保证写文件被清理
    std::ofstream ofs1("./document/students.txt", std::ios::trunc);
    ofs1.close();
    students = {
    {"E2022001","张三"},
    {"E2022002","李四"},
    {"E2022003","王五"},
    {"E2022004","小明"},
    {"E2022005","小红"},
    {"E2022006","小芳"},
    {"E2022007","小何"},
    {"E2022008","小高"},
    {"E2022009","小艾"},
    {"E2022010","小康"}
};
    for (int i=0;i<10;i++){
        ofstream ofs;
        ofs.open("./document/students.txt",ios::app);
        ofs<<"Student "<<i+1<<endl;
        students[i].save("./document/students.txt");
        ofs<<"-----------------------------------------------"<<endl;
    }

}
void allocate(vector<Smartcar> cars,vector<Student> students){
    std::ofstream ofs1("./document/allocation.txt", std::ios::trunc);
    ofs1.close();
    ofstream ofs;
    ofs.open("./document/allocation.txt",ios::app);
    for (int i=0;i<cars.size();i++){
        ofs<<"Car "<<i+1<<endl;
        cars[i].save("./document/allocation.txt",true);
        ofs<<"所分配的学生信息: "<<endl;
        students[i].save("./document/allocation.txt");
        ofs<<"-----------------------------------------------"<<endl;
    }
    ofs.close();
}
void showPage(const string & filename){
    ifstream ifs(filename);
    if(!ifs.is_open()){
        std::cerr<<"无法打开文件"<<filename<<endl;
        return;
    }
    // 读取的行放入这个容器之中
    vector <string>lines;
    string line;
    // 每一次读取一行
    while(getline(ifs,line)){
        lines.push_back(line);
    }
    ifs.close();
    if (lines.empty()) {
        cout << "文件为空！" << endl;
        return;
    }
    //找到每一台汽车的起始行方便进行分页
    vector <int> carStart;
    for(int i=0;i<(int)lines.size();i++){
        // 检查是否以Car开头
        if(lines[i].rfind("Car",0)==0){
            carStart.push_back(i);
        }
    }
    int totalCars = carStart.size();
    int currentPage = 0;
    while (true){
        system("cls");
        cout << "===== 第 " << (currentPage + 1) << " 辆车 / 共 " << totalCars << " 辆 =====\n";
        int startline=carStart[currentPage];
        int endline;
        //判断是否为最后一辆车
        if(currentPage+1<totalCars){
            endline=carStart[currentPage + 1];
        }
        else{
            endline=lines.size();
        }
        // 输出当前车辆信息
        for (int i = startline; i < endline; ++i) {
            cout << lines[i] << "\n";
        }
        cout << "操作： n → 下一辆   p → 上一辆   q → 退出\n";
        cout << "请输入操作: ";
        // 读取输入的命令
        char cmd;
        std::cin >> cmd;
        if (cmd == 'n' || cmd == 'N') {
                if (currentPage < totalCars - 1)
                    currentPage++;
                else
                    cout << "已经是最后一页啦！\n"; 
                    cout << "按下任意键继续\n"; 
                    system("pause");
            } else if (cmd == 'p' || cmd == 'P') {
                if (currentPage > 0)
                    currentPage--;
                else
                    cout << "已经是第一页啦！\n"; 
                    cout << "按下任意键继续\n"; 
                    system("pause");
            } else if (cmd == 'q' || cmd == 'Q') {
                cout << "退出分页显示。\n"; 
                break;
            }
        }
    }
void testPublishAndSubscriber(){
    Chassis chassis;
    Lidar lidar;
    lidar.addSubscriber(&chassis);
    while(true){
        cout<<"请输入目前雷达检测到的障碍物状态(用数字表示)"<<endl;
        cout<<"-----1.障碍物在前方-----"<<endl;
        cout<<"-----2.障碍物在右前方-----"<<endl;
        cout<<"-----3.障碍物在左前方-----"<<endl;
        cout<<"-----0.退出-----"<<endl;
        int cmd;
        std::cin>>cmd;
        if (cmd == 0) break;
        lidar.setState(cmd);
    }
}