#include "Contact.h"  // �������ͷ�ļ���Ϊ Contact.h

int main() {


    // ����ͨѶ¼����
    contact myContact;
    int choice;
    do {
        // ��ʾ�˵�
        menu();
        cout << "���������ѡ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // �����ϵ��
            myContact.AddContact();
            break;
        case 2:
            // ɾ����ϵ��
            myContact.DelContact();
            break;
        case 3:
            // ������ϵ��
            myContact.FindContact();
            break;
        case 4:
            // �޸���ϵ����Ϣ
            myContact.ModifyContact();
            break;
        case 5:
            // չʾͨѶ¼
            myContact.ShowContact();
            break;
        case 6:
            // �˳�����
            // myContact.DestroyContact(); // �����ֶ����ã���Ȼ�����ֻ����
            cout << "�˳�ͨѶ¼���򣬲���������" << endl;
            return 0;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    } while (choice != 0);

    // �������ʱ�������Զ�����������������ͨѶ¼
    return 0;
}