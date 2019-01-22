#include "basis.h"
#include "uis/all_uis.h"

int main(int argc, char **argv) {
    if (initDatabase()) { // 初始化数据库
        std::cerr << "数据库初始化失败" << std::endl; // 退出
        return 0;
    }
    launch(); // 启动主界面
    globalType = checkLogin(); // 检查登陆信息
    switch (globalType) {
        case StudentType:
            student_main::student_mainmenu(); // 学生界面
            break;
        case TeacherType:
            teacher_main::teacher_mainmenu(); // 教师界面
            break;
        case AdministratorType:
            system_management_main::system_management_mainmenu(); // 管理员界面
        default:
            std::cerr << "账号或密码错误" << std::endl; // 退出
            system("pause");
    }
    return 0;
}
