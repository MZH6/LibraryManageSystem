#pragma once
#include<string>
#include<iostream>
#include<string>
using namespace std;
/// ///////////////////////////////////////// �� �� �� �� �� ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�û���
class User//�û���
{
public:
    string ID;//���
    string Name;//��ʾ�û�����
    string Password;//����
    string Type;//��ʾ�û�������
    string person_state;//��Ա�Ľ���״̬
    string Identification;//���֤��
    int bad_return_book;//�쳣�������
    int BookNumber;
    string LentBook[10][2];
    string hua;
    User() {
        Type = "��ͨ�û�";
        person_state = "����";
        bad_return_book = 0;//�쳣�������
    }
    void set_name(string n);
    void set_Password(string P);
    void set_ID(string id);
    void set_Ident(string i);
    void set_Type(string T);
    void set_BookNumber(int n);
    
};
//�ڵ��࣬��user��
struct UserNode
{
    User* user;
    UserNode* next;
};
//��ͷ�͹��ܺ�����,ͷ��struct���͵Ľڵ���
class UserList
{

public:
    UserNode* head;
    UserList() { head = NULL; }
    //����û�
    void AddUser(User* user1);
    //��¼����
    int login(const string Id, const string password);
    //��ʾ�û�
    void show();
};


///

