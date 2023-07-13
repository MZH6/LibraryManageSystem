#pragma once
#include<iostream>
#include<string>
#include"Book.h"
#include"Content.h"
#include"Users.h"
////////////////////////////////////////////////////////////////////////////// ͼ �� �� �� Ա �� �� �� �� //////////
//��¼���չʾ����
void LibraryMangerLogin()
{
    cout << "======ͼ�����Ա����======" << endl;
    cout << "      1.���ͼ��      " << endl;
    cout << "      2.ɾ��ͼ��      " << endl;
    cout << "      3.�쳣���鴦��   " << endl;
    cout << "      4.��������      " << endl;
    cout << "      5.�޸�����      " << endl;
    cout << "     �����������ֽ���ǳ�����" << endl;
    cout << "=========================" << endl;
}
//��������ͼ�麯��
bool AddNowBook(BookList& booklist, int booknumber, string bookname)
{
    BookNode* p = booklist.head;
    while (p)
    {
        if (p->book->name == bookname)
        {
            p->book->number += booknumber;
            return true;
        }
        p = p->next;
    }
    return false;
}
//ɾ��ͼ�麯��
void DeleteBook(BookList& booklist, string bookname, int& book_number)
{
    BookNode* p = booklist.head;
    BookNode* temp = NULL;
    while (p != NULL)
    {
        if (p->book->name == bookname)
        {
            if (p == booklist.head)
            {
                booklist.head = p->next;
                delete p->book;
                delete p;
                book_number--;
                p = booklist.head;//����pΪͷ
            }
            else if (p->next == NULL)//����ĩβʱ
            {
                temp->next = NULL;
                delete p->book;
                delete p;
                book_number--;
                p = NULL;

            }
            else
            {
                temp->next = p->next;
                delete p->book;
                delete p;
                book_number--;
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
//�쳣��������
void Punish(UserList& userlist)
{
    string No = "�쳣";
    UserNode* p = userlist.head;
    while (p)
    {
        if (p->user->bad_return_book > 0)
        {
            cout << p->user->Type << p->user->Name << "���쳣�����¼���Ƿ������б�ǣ�" << endl;
            cout << "1.��� || 2.�Ź� " << endl;
            int n;
            cin >> n;
            if (n == 1)
            {
                p->user->person_state = No;
                cout << "�ѽ������״̬��Ϊ���쳣����" << endl;
            }
            else if (n == 2)
            {
                cout << "�Ǿͷ�taһ��" << endl;
            }
            else
            {
                cout << "�����������Ժ����ԡ�" << endl;
            }

        }
        else
        {
            cout << p->user->Type << p->user->Name << "���쳣��¼" << endl;
        }
        p = p->next;
    }
}
//��������
void PostContent(ContentList& contentlist)
{
    cout << "��������Ҫ��ӵ��¹��棺";
    string news1;
    cin >> news1;
    Contents* a = new Contents;
    a->set_news(news1);
    contentlist.AddNews(a);
}
