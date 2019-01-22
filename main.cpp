#include "basis.h"
#include "uis/all_uis.h"

int main(int argc, char **argv) {
    if (initDatabase()) { // ��ʼ�����ݿ�
        std::cerr << "���ݿ��ʼ��ʧ��" << std::endl; // �˳�
        return 0;
    }
    launch(); // ����������
    globalType = checkLogin(); // ����½��Ϣ
    switch (globalType) {
        case StudentType:
            student_main::student_mainmenu(); // ѧ������
            break;
        case TeacherType:
            teacher_main::teacher_mainmenu(); // ��ʦ����
            break;
        case AdministratorType:
            system_management_main::system_management_mainmenu(); // ����Ա����
        default:
            std::cerr << "�˺Ż��������" << std::endl; // �˳�
            system("pause");
    }
    return 0;
}
