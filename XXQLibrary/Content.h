#pragma once
#include<string>
#include<iostream>
using namespace std;
// ////////////////////////////////////////////// �� �� �� �� �� ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ������
class Contents
{
public:
    string notice;
    string display();//���ع���
    void set_news(string n);

};

struct ContentNode {
    Contents* news;
    ContentNode* next;

};

class ContentList
{
public:
    ContentNode* head;
    ContentList();
    void AddNews(Contents* notice1);
    void show();
    
};
