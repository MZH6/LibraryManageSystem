#pragma once
#include<string>
#include<iostream>
using namespace std;
/// //////////////////////////////////////////////// ͼ �� �� �� �� //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ͼ����
class Book
{
public:
    int IBSN;
    string name;
    string state = "�ɽ���";
    int number;//ͼ������
    int hot = 0;//ͼ����ĵĻ𱬳̶ȣ��ñ����ļ�������ʾ
    void display();
    void set_bookname(string n) { name = n; }
    void set_number(int n) { number = n; }
    void set_IBSN(int i) { IBSN = i; }
};
//
struct BookNode
{
    Book* book;
    BookNode* next;
};
///
class BookList
{
public:
    BookNode* head;
    BookList()
    {
        head = NULL;
    }
    //����鱾����
    void AddBook(Book* book1);
    //չʾ�鱾��
    void show();
    
};



