#pragma once
#ifndef _LIBRARY_H
#define _LIBRARY_H
//����ṹ��Ⱥ
#include<iostream>
#include<cstring>
using namespace std;

//��Ľṹ��
struct Books
{
    char name[100];//����
    char IBSN[100];//IBSN��
    char state[20]= "δ����";//�鱾״̬:δ����\�ѽ���
    
};

struct User
{
    int ID;//ID                                                  
    char name[50];//����                                        
    char password[100];//����                                   
    char type[100];//��Ա����                                  
    int day = 0;//����ʣ��ʱ��                                 
    int number=0;//��������Ŀ                                  
    char person_state[10] = "����";//�Ƿ���Խ��ĵ�״̬        
    char Lent_name[100];//��������1                            
    int bad_return_book = 0;//�쳣�������                     

};
//����Ľṹ��
struct Contents
{
    char notice[500];
};



#endif //_LIBRARY_H