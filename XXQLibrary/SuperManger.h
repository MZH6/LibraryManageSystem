#pragma once
#include<iostream>
#include<string>
#include"Book.h"
#include"Content.h"
#include"Users.h"
#include"Book.h"
#include"Content.h"
#include"Users.h"
//////////////////////////////////////////////////////////////////////////////////// �� �� �� �� Ա //////////////////////////////
//��¼
void SuperMangerLogin()
{
    cout << "======��������Ա����======" << endl;
    cout << "      1.�޸�����      " << endl;
    cout << "      2.�����û�      " << endl;
    cout << "      3.ͼ������   " << endl;
    cout << "      4.���Ÿ��û�   " << endl;
    cout << "     �����������ֽ���ǳ�����" << endl;
    cout << "============================" << endl;
}
//
void DeleteUser(UserList& userlist, string name1, int& number1)
{
    UserNode* p = userlist.head;
    UserNode* temp = NULL;
    while (p != NULL)
    {
        if (p->user->Name == name1)
        {
            if (p == userlist.head)
            {
                userlist.head = p->next;
                delete p->user;
                delete p;
                number1--;
                p = userlist.head;//����pΪͷ
            }
            else if (p->next == NULL)//����ĩβʱ
            {
                temp->next = NULL;
                delete p->user;
                delete p;
                number1--;
                p = NULL;

            }
            else
            {
                temp->next = p->next;
                delete p->user;
                delete p;
                number1--;
                p = temp->next;//����p
            }
        }
        else
        {
            temp = p;
            p = p->next;
        }

    }
}
