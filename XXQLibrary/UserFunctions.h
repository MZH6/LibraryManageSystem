#pragma once
#include"Users.h"
#include"Book.h"
#include"Content.h"
#include<iostream>
#include"SuperManger.h"
#include<fstream>//���ļ�����ͷ�ļ�
using namespace std;
#include<string>
//�ܽ���
void Interface()//��ʼ����
{
    cout << "**********************************" << endl;
    cout << "***��ӭ������������ͼ�����ϵͳ***" << endl;
    cout << "**********************************" << endl;
}
//д�ļ�
void OutputFile(UserList userlist, BookList booklist, ContentList newlist, int user_number, int book_number, int news_number)
{
    //д�ļ�������
    ofstream ofs;
    ofs.open("D:\\P2\\XXQLibrary\\BaseData\\User.txt", ios::trunc);
    UserNode* p = userlist.head;
    //д�û�
     while(p)
    {
         ofs << p->user->ID << " " << p->user->Name << " " << p->user->Password << " " << p->user->Type << " " <<p->user->hua<<" " << p->user->person_state << " " << p->user->Identification << " " << p->user->bad_return_book << " " << p->user->BookNumber << " ";
         for (int i = 0;i< p->user->BookNumber; i++)
         {
             ofs << p->user->LentBook[i][0] << " " << p->user->LentBook[i][1] ;
             if (i != p->user->BookNumber-1)
             {
                 ofs<< " ";
             }
         }
         ofs<< endl;
         p = p->next;
    }
    ofs.close();
    //д��
    ofstream ofs1;
    ofs1.open("D:\\P2\\XXQLibrary\\BaseData\\Book.txt", ios::trunc);
    BookNode* p1 = booklist.head;
    while (p1)
    {
        ofs1 << p1->book->IBSN << " " << p1->book->name << " " << p1->book->state << " " << p1->book->number << " " << p1->book->hot << endl;

        p1 = p1->next;
    }
    ofs1.close();
    //�ļ�д����
    ofstream ofs2;
    ofs2.open("D:\\P2\\XXQLibrary\\BaseData\\Contents.txt", ios::trunc);
    ContentNode* p2 = newlist.head;
     while(p2)
    {
        ofs2 << p2->news->notice << endl;
        p2 = p2->next;
    }
    ofs2.close();
}

//��ȡ�ĵ�������
void Read(int user_number, UserList& userlist, int book_number, BookList& booklist, int new_number, ContentList& contentlist)
{
    //���û��ļ��������û�������
    string filename = "D:\\P2\\XXQLibrary\\BaseData\\User.txt";
    ifstream fin(filename, ios::in);//�����ļ�
    for (int i = 0; i < user_number; i++)
    {
        User* user = new User;
        fin >> user->ID >> user->Name >> user->Password >> user->Type >>user->hua>> user->person_state >> user->Identification >> user->bad_return_book >> user->BookNumber;
        //�����������
        for (int i = 0; i < user->BookNumber; i++)
        {

            fin >> user->LentBook[i][0] >> user->LentBook[i][1];
        }

        userlist.AddUser(user);
    }
   // userlist.show();
     //cout << endl;
      //��ͼ���ļ�������ͼ��������
    string filename1 = "D:\\P2\\XXQLibrary\\BaseData\\Book.txt";
    ifstream fin1(filename1, ios::in);//�����ļ�
    for (int i = 0; i < book_number; i++)
    {
        Book* book = new Book;
        fin1 >> book->IBSN >> book->name >> book->state >> book->number >> book->hot;
        booklist.AddBook(book);
    }
    // booklist.show();
     //���빫��
    string filename2 = "D:\\P2\\XXQLibrary\\BaseData\\Contents.txt";
    ifstream fin2(filename2, ios::in);//�����ļ�
    for (int i = 0; i < new_number; i++)
    {
        Contents* news = new Contents;
        fin2 >> news->notice;
        contentlist.AddNews(news);
    }
    //  contentlist.show();
}
//��¼����
bool login(string id, string password, UserList user)//����user��
{
    if (user.login(id, password))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/////////////////////////////////////////////�ж�������ĶԲ��Բ���
bool Correct(UserList userlist, string password,string id)
{
    UserNode *p = userlist.head;
    while (p)
    {
        if (p->user->Password == password&&p->user->ID==id)
        {
            return false;//����˾ͷ���false���������
        }
        p = p->next;
    }
    return true;
}
/////////////////////////////////////////////�ж��û�ID�Ƿ�Ϸ�
bool IDCorrect(UserList userlist, string Id)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->ID == Id)
        {
            return true;
        }
        p.head = p.head->next;
    }
    return false;//����T��ѭ��
}
//�����޸����������ȷ��ֵ�Ƿ���ȷ
bool ChangeCorrect(UserList userlist, string Id, string name, string shenfen)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->ID == Id)
        {
            if (p.head->user->Name == name && p.head->user->Identification == shenfen)
            {
                return true;
            }
        }
        p.head = p.head->next;
    }
    return false;//����T��ѭ��
}
//�ж��û������Ƿ���ȷ
bool NameCorrect(UserList userlist, string n)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->Name == n)
        {
            return true;
        }
        p.head = p.head->next;
    }
    return false;
}
//�ж����֤���Ƿ���ȷ�Ĵ���
bool ShenFenZhengCorrect(UserList userlist, string shengfenzhenghao)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->Identification == shengfenzhenghao)
        {
            return true;
        }
        p.head = p.head->next;
    }
    return false;
}
//�л��û���
UserList FaceUser(UserList userlist, string aId)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->ID == aId)
        {
            return p;
        }
        p.head = p.head->next;
    }
}
//Ѱ��ָ���û�����////////////////////////////////////////////////////////////////////////////////////////////// �� ͨ �� �� ʵ �� �� �� ///////////////
int FindType(UserList userlist, string aID)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->ID == aID)
        {
            if (p.head->user->Type == "ͼ�����Ա")
            {
                return 2;
            }
            else if (p.head->user->Type == "��ͨ�û�")
            {
                return 1;
            }
            else
            {
                return 3;
            }
        }
        p.head = p.head->next;
    }
    return 0;
}
//��ͨ�û���½����ʾ�Ľ����
void CommonUserLogin(BookList booklist)
{
    BookNode* temp = booklist.head;
    string book1 = temp->book->name;
    int n = temp->book->hot;
    cout << "========���͹���========" << endl;
    while (temp)
    {
        if (temp->book->hot > n)
        {
            n = temp->book->hot;
            book1 = temp->book->name;
        }
        temp = temp->next;
    }
    cout << "Ŀǰ��ͼ�飺" << book1 << endl;
    cout << "========================" << endl<<endl;
    cout << "======��ͨ�û�����======" << endl;
    cout << "     1.ԤԼ����      " << endl;
    cout << "     2.����         " << endl;
    cout << "     3.��ѯ������Ϣ   " << endl;
    cout << "     4.��ѯͼ����Ϣ   " << endl;
    cout << "     5.�鿴����      " << endl;
    cout << "     6.�޸�����      " << endl;
    cout << "   �����������ֽ���ǳ�����" << endl;
    cout << "=========================" << endl;
}
//��ͨ�û���ѯ������Ϣ���ܺ���
void FindMessage(UserList new_userlist)
{
    cout << "������" << new_userlist.head->user->Name << endl;
    cout << "ID��" << new_userlist.head->user->ID << endl;
    cout << "�û����ͣ�" << new_userlist.head->user->Type << endl;
    cout << "����״̬��" << new_userlist.head->user->person_state << endl;
    if (new_userlist.head->user->BookNumber != 0)
    {
        for (int i = 0; i < new_userlist.head->user->BookNumber; i++)
        {
            cout << "���ڽ��ģ�" << new_userlist.head->user->LentBook[i][0];
            cout << ",ʣ��ʱ����" << new_userlist.head->user->LentBook[i][1] << "��" << endl;
        }
    }
    else
    {
        cout << "�û�δ����ͼ��";
    }
    cout << endl;
}
//���ܲ���
void FindUser(UserList userlist, string id)
{
    UserNode* p = userlist.head;
    while (p)
    {
        if (p->user->ID == id)
        {
            cout << "������" << p->user->Name<<endl;

            cout << "�û����ͣ�" << p->user->Type << endl;
            cout << "����״̬��" << p->user->person_state << endl;
            if (p->user->BookNumber != 0)
            {
                for (int i = 0; i < p->user->BookNumber; i++)
                {
                    cout << "���ڽ��ģ�" << p->user->LentBook[i][0];
                    cout << ",ʣ��ʱ����" << p->user->LentBook[i][1] << "��" << endl;
                }
            }
            else
            {
                cout << "�û�δ����ͼ��";
            }
            cout << endl;
            break;
        }
        p = p->next;
    }
}

//��ͨ�û���ѯͼ��Ĺ��ܺ���
void FindBook(BookList& booklist)
{
    BookNode* p = booklist.head;
    while (p)
    {
        cout << "ID�ţ�" << p->book->IBSN << "��ͼ�����ƣ�" << p->book->name << "��ͼ���棺" << p->book->number << "��ͼ����ȳ̶ȣ�";
        int index = 1;
        if (p->book->hot >= 0&& p->book->hot <= 5)
        {
            index = 1;
        }
        else if (p->book->hot > 5 && p->book->hot <= 10)
        {
            index = 2;
        }
        else if ((int)p->book->hot > 10 && (int)p->book->hot <= 15)
        {
            index = 3;
        }
        else if ((int)p->book->hot > 15 && (int)p->book->hot <= 20)
        {
            index = 4;
        }
        else
        {
            index = 5;
        }
        for (int i = 0; i < index; i++)
        {
            cout << "*";
        }
        cout << endl;
        p = p->next;
    }
}
//�޸�����
void ChangePassword(UserList userlist, string aID)
{
    UserList p = userlist;
    while (p.head != NULL)
    {
        if (p.head->user->ID == aID)
        {
            p.head->user->Password = "666666";
            break;
        }
        p.head = p.head->next;
    }
}
//��ͨ�û��鿴���溯��
void FindContent(ContentList contentlist)
{
    ContentNode* p = contentlist.head;
    while (p)
    {
        cout << "���棺" << p->news->notice << endl;
        p = p->next;
    }
}
//��ͨ�û�ԤԼ���鹦��
bool Lent(UserList userlist, BookList booklist)
{
    while (1)
    {
        if (userlist.head->user->person_state == "�쳣")
        {
            cout << "���Ľ���״̬�쳣����ͼ�����Ա�ѱ�ǣ���ϵ�绰��17719577839" << endl;
            cout << "��ѡ��΢��ת��50Ԫ���ָ����Ĺ��ܣ�΢�źţ�ma2362471311" << endl;
            break;
        }
        string ibsn, NAME;
        cout << "��ǰ�ɽ���ͼ�飺" << endl; BookNode* p = booklist.head;//��ʾ��ǰ�ɽ���ͼ��
        while (p)
        {
            if (p->book->number > 0)
            {
                cout << "IBSN�ţ�" << p->book->IBSN << "��������" << p->book->name << endl;
            }
            p = p->next;
        }   cout << "��������Ҫ����ͼ������ƣ�" << endl; cin >> NAME;
        p = booklist.head;
        while (p)
        {
            if (p->book->name == NAME)
            {
                if (p->book->number == 0)
                {
                    cout << "��Ǹ��治��,���Ժ�һ��ͼ����н���" << endl;
                    return false;
                }
                p->book->number--;
                cout << "�ɹ�����!��Ҫ������ʮ�����Ŷ" << endl;
                

                if (p->book->number == 0)
                {
                    p->book->state = "���ɽ���";
                }
                userlist.head->user->LentBook[userlist.head->user->BookNumber][0] = NAME;
                userlist.head->user->LentBook[userlist.head->user->BookNumber++][1] = "30";
                booklist.head->book->hot++;
                return true;
            }
            p = p->next;
        }
        cout << "�ܱ�Ǹ�������������������û����¼" << endl;
        return false;
    }
    return true;
}
//��ͨ�û�����ʵ�ֺ��ĳ���
void FunctionGive(UserList userlist, int n)
{
    if (n == userlist.head->user->BookNumber - 1)
    {
        userlist.head->user->LentBook[n][0] = "";
        userlist.head->user->LentBook[n][1] = "";
    }
    else
    {
        userlist.head->user->LentBook[n][0] = userlist.head->user->LentBook[userlist.head->user->BookNumber - 1][0];
        userlist.head->user->LentBook[n][1] = userlist.head->user->LentBook[userlist.head->user->BookNumber - 1][1];
        userlist.head->user->LentBook[userlist.head->user->BookNumber - 1][0] = "";
        userlist.head->user->LentBook[userlist.head->user->BookNumber - 1][1] = "";
    }
}
//��ͨ�û�ʵ�ֻ��鹦��
bool Give(UserList& userlist, BookList& booklist)
{
    string book1;//�黹��ͼ����
    while (true)
    {
        cout << "��������" << userlist.head->user->BookNumber << endl;
        if (userlist.head->user->BookNumber > 0)
        {
            cout << "����������黹��ͼ�飺" << endl;
            cin >> book1;
            int i;
            for (i = 0; i < userlist.head->user->BookNumber; i++)
            {
                if (userlist.head->user->LentBook[i][0] == book1)//�һ��������
                {
                    if (userlist.head->user->LentBook[i][1] > "0")//�һ���ı��
                    {

                        cout << "����δ���ڣ���ӭ�´ν���~" << endl;
                    }
                    else
                    {
                        cout << "�������ڣ���ע�ⰴʱ���飡����" << endl;
                        userlist.head->user->bad_return_book++;

                    }
                    FunctionGive(userlist, i);//��
                    BookNode* p = booklist.head;
                    while (p)//������м�һ
                    {
                        if (p->book->name == book1)
                        {
                            p->book->number++;
                            break;
                        }
                        p = p->next;
                    }
                    userlist.head->user->BookNumber--;
                    break;
                }
                if (i == userlist.head->user->BookNumber)
                {
                    cout << "����ʧ�ܣ�����δ��¼����" << endl;
                }
            }
        }
        else
        {
            cout << "��û���ڽ�ͼ�飬���軹��" << endl;
            break;
        }
        cout << "===ѡ���Ƿ��������===" << endl << "1.��  ||  2.��" << endl;
        int num; cin >> num;
        if (num == 2)
        {
            break;
        }
    }
    return true;
}
void SortByHot(BookList booklist)
{
    BookNode* first = booklist.head->next;
    BookNode* p, * q, * tail;
    tail = NULL; // tail��ʾ�Ѿ��ź���Ľ��
    while (booklist.head->next != tail)
    { // ���ѭ��
        p = booklist.head; // pָͷ
        q = booklist.head->next; // qָ��һ��
        while (q->next != tail) { // �Ƚ�
            if (q->book->hot < q->next->book->hot) {
                p->next = q->next; // p��nextָ��q����һ�����
                q->next = q->next->next; // q��nextָ��q������һ�����
                p->next->next = q; // p����һ������nextָ��q
                q = p->next; // qָ��p����һ����㣬���������λ��
            }
            p = p->next; // p��q������
            q = q->next;
        }
        tail = q; // tailָ�����һ���Ѿ��ź���Ľ��
    }
    BookNode* r = booklist.head->next;
    while (r)
    {
        cout << "ͼ�����ƣ�" << r->book->name << "��ͼ����ȳ̶ȣ�";
        int index = 1;
        if (r->book->hot >= 0 && r->book->hot <= 5)
        {
            index = 1;
        }
        else if (r->book->hot > 5 && r->book->hot <= 10)
        {
            index = 2;
        }
        else if ((int)r->book->hot > 10 && (int)r->book->hot <= 15)
        {
            index = 3;
        }
        else if ((int)r->book->hot > 15 && (int)r->book->hot <= 20)
        {
            index = 4;
        }
        else
        {
            index = 5;
        }
        for (int i = 0; i < index; i++)
        {
            cout << "*";
        }
        cout << endl << flush;
        r = r->next;
    }

}

void DeleteLoop(UserList &userlist, int& user_number)
{
    cout << "�������ע���û�ID��";
    string id;
    cin >> id;
    UserNode* s = userlist.head;
    UserNode* temp = NULL;
    while (s)
    {
        if (s->user->ID == id)
        {
            if (s == userlist.head)
            {
                userlist.head = s->next;
                if (s->user != NULL) //�ж�s->user�Ƿ�Ϊ��
                {
                    delete s->user; //�����Ϊ�գ���ɾ����
                }
                if (s != NULL) //�ж�s�Ƿ�Ϊ��
                {
                    delete s; //�����Ϊ�գ���ɾ����
                }
                user_number--;
                s = userlist.head;//����sΪͷ
            }
            else if (s->next == NULL)//��ĩβʱ
            {
                temp->next = NULL;
                delete s->user;
                delete s;
                user_number--;
                s = NULL;

            }
            else
            {
                temp->next = s->next;
                delete s->user;
                delete s;
                user_number--;
                s = temp->next;//����s
            }
            break;
        }
        temp = s; //��¼ǰ�����
        s = s->next;
    }
}
//��������ͨ�û���ͼ�ܵ��޸����뺯��
void ChangeMiMa(UserList new_userlist)
{
    
        cout << "������������ĵ����룺";
        string n;
        cin >> n;
        new_userlist.head->user->Password = n;
        cout << "�����������޸ģ������µ�¼" << endl;
    
}