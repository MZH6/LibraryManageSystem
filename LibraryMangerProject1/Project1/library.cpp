#include "UserAll.h"//�ṹ��Ⱥ
#include<cstring>//ʹ��strcmp
#include<iostream>
#include<fstream>//
#include<string>
#include <cstdio>
using namespace std;
void OutputFile(User user[], Books book[], Contents news[], int user_number, int book_number, int news_number);
void Interface()//��ʼ����
{
    cout << "**********************************" << endl;
    cout << "***��ӭ������������ͼ�����ϵͳ***" << endl;
    cout << "**********************************" << endl;
}
bool login(User user[], int& n, int user_number)//��¼����
{
    int id;
    char Password[50];
    cout << "����������ID�ţ�";
    cin >> id;
    cout << "�������������룺 ";
    cin >> Password;
    //���û������в����û�
    for (int i = 0; i <= user_number - 1; i++)
    {
        if (user[i].ID == id && !strcmp(user[i].password, Password))
        {
            cout << "������ȷ!" << endl;
            n = i + 1;//i�������±꣬��rank��1
            return true;
        }
    }
    cout << "��Ŷ����������ˣ������³���" << endl;
    return false;

}
string CM = "��ͨ";
string LM = "ͼ��";
string SM = "����";
string Yes = "����";
string No = "�쳣";
void logined(User user[], int rank)//��¼����ʾ����
{


    
    if(strcmp(user[rank-1].type,"��ͨ�û�"))
    {
          cout << "Hi!"<<user[rank-1].type << user[rank - 1].name << "�������˶����~" << endl;
    } 
    if(strcmp(user[rank-1].type,"ͼ��"))
    {
        cout << "Hi!" << user[rank - 1].type<< user[rank - 1].name << "�������ң�����Ϊ��" << endl;
    }
    if(strcmp(user[rank-1].type,"����"))
    {
         cout << "Hi!" << user[rank - 1].type<< user[rank - 1].name << "������Խ������Խ��" << endl;
        
    }

    /*
    switch (rank) {
    case 1:
        cout << "Hi!"<<user[rank-1].type << user[rank - 1].name << "�������˶����~" << endl;
        break;
    case 2:
        cout << "Hi!" << user[rank - 1].type<< user[rank - 1].name << "�������ң�����Ϊ��" << endl;
        break;
    case 3:
        cout << "Hi!" << user[rank - 1].type<< user[rank - 1].name << "������Խ������Խ��" << endl;
        break;
    }*/
}
//��ͨ�û�ʵ�ֹ��ܺ���1.ԤԼ
bool Reverse(Books book[], User user[], int& rank, int& book_number)//ԤԼ�麯��
{
    while (1)
    {
        if (user[rank].person_state == No)
        {
            cout << "���Ľ���״̬�쳣����ͼ�����Ա�ѱ�ǣ���ϵ�绰��17719577839" << endl;
            cout << "��ѡ��΢��ת��50Ԫ���ָ����ķ���" << endl;
            break;
        }
        if (user[rank].number != 0)
        {
            cout << "������δ��ͼ�飬���Ƚ��л���������ٽ��н���" << endl;
            break;
        }
        char book_name[100];
        cout << "��������ԤԼ�����鼮������:" << endl;
        cin >> book_name;
        for (int i = 0; i < book_number; i++)
        {

            if (strcmp(book[i].name, book_name) == 0)
            {
                cout << "�ɹ�����" << book[i].name << ",��Ҫ����30�����Ҫ����Ŷ~" << endl;
                strcpy_s(book[i].state, "�ѽ���");//������״̬��Ϊ�ѽ���
                user[rank].day = 30;//���ڻ���ĳͷ�
                user[rank].number++;
                strcpy_s(user[rank].Lent_name, book_name);//�Ǽ���������
                return false;//����false�˳�ѭ��
            }
        }
        cout << "�ܱ�Ǹ�����������������û����¼~(ע���������������뷨����Ŷ)" << endl;
        break;//����
    }
}
//��ͨ�û�ʵ�ֻ��麯��
void return_books(Books* book, User user[], int& rank, int& book_number)
{
    char a[50] = "ȷ��";
    char b[50];
    if (user[rank].number > 0)
    {
        cout << "�����鼮:" << user[rank].Lent_name << endl;
        cout << "ʣ��ʱ��:" << user[rank].day << endl;
        cout << "���롱ȷ�������л���:";
        cin >> b;
        cout << b << endl;
        if (strcmp(a, b) == 0)//����ȷ���󣬽��л������
        {

            if (user[rank].day > 0)//�ж��Ƿ����ڻ���
            {
                cout << "����δ���ڣ���ӭ�´ν���" << endl;
                
            }
            else
            {
                cout << "�������ڣ���ע�ⰴʱ����" << endl;
                user[rank].bad_return_book++;//�����ڣ����¼�������ڴ���
            }
            for (int i = 0; i < book_number; i++)//�����鱾״̬
            {
                if (strcmp(book[i].name, user[rank].Lent_name) == 0)
                {
                    memset(user[rank].Lent_name, 0, sizeof(user[rank].Lent_name));//user�н�������
                    strcpy_s(book[i].state,"δ����");
                }
            }
            strcpy_s(user[rank].Lent_name, "��");
            user[rank].number = 0;//�������Ŀ����
        }
    }
    else
    {
        cout << "�������㻹û�н����أ���ȥ����һ����~" << endl;
    }

}
void commonUser(Books book[], int rank, User user[], Contents news[], int& book_number, int news_number,int user_number)//��ͨ�û�ʵ�ֹ��ܺ���
{
    cout << "======��ͨ�û�����======" << endl;
    cout << "     1.ԤԼ����      " << endl;
    cout << "     2.����         " << endl;
    cout << "     3.��ѯ������Ϣ   " << endl;
    cout << "     4.��ѯͼ����Ϣ   " << endl;
    cout << "     5.�鿴����      " << endl;
    cout << "   �����������ֽ���ǳ�����" << endl;
    cout << "=========================" << endl;
    while (1)
    {
        int n;
        cin >> n;
        if (n < 1 || n>5)
        {
            break;
        }
        switch (n) {
        case 0:
            break;
        case 1://����
            
                Reverse(book, user, rank, book_number);
            
            break;
        case 2://����
            return_books(book, user, rank, book_number);

            break;
        case 3://��ѯ������Ϣ
            cout << "ID:" << user[rank].ID;
            cout << "�� ����:" << user[rank].name << endl;
            cout << "�û�����״̬��";
            if (user[rank].person_state)
            {
                cout << "����" << endl;
            }
            else {
                cout << "�쳣��������δ����¼��" << endl;
            }
            if (user[rank].number > 0)
            {
                cout << "�����鼮:" << user[rank].Lent_name << endl;
                cout << "ʣ��ʱ��:" << user[rank].day << endl;
            }
            else
            {
                cout << "���޽���ͼ��" << endl;
            }
            cout << "�û�����:��ͨ�û�" << endl;

            break;
        case 4://��ѯͼ����Ϣ
            for (int i = 0; i < book_number; i++) {

                cout << "IBSN��:" << book[i].IBSN << endl;
                cout << "ͼ������:" << book[i].name << endl;
                cout << "����״̬:";
                if(strcmp(book[i].state,"δ����")==0)
                {
                    cout << "δ����" << endl;
                }
                else
                {
                    cout << "������" << endl;
                }
                cout << endl;

            }
            break;
        case 5:
            for (int i = 0; i < news_number; i++)
            {
                cout << news[i].notice << endl;
            }

            break;
        }
        OutputFile(user, book, news, user_number, book_number, news_number);
        cout << endl;
        cout << "����ʹ�û��������������˳���¼" << endl;

    }
}
//ͼ�����Ա����
//1.���ͼ��
void AddBook(int& book_number, Books book[])
{
    cout << "������������鱾��������";
    cin >> book[book_number].name;
    cout << "������������鱾�����кţ�";
    cin >> book[book_number].IBSN;
    strcpy_s(book[book_number].state, "δ����");
    book_number++;
}
void DeleteBook(int& book_number, Books book[])
{
    char a[50];
    cout << "����������ɾ��ͼ������ƣ�";
    cin >> a;
    int i = 0;
    for (; i < book_number; i++)
    {
        if (strcmp(a, book[i].name) == 0)
        {
            if (i == book_number - 1)
            {
                memset(book[i].name, 0, sizeof(book[i].name));
                memset(book[i].IBSN, 0, sizeof(book[i].IBSN));
            }
            else
            {
                Books temp;//ɾ��ͼ�����strcpy��ע���û����ýṹ����ַȻ�󽻻�ɾ���һ��
                strcpy_s(temp.state,book[i].state);
                strcpy_s(temp.name, book[i].name);
                strcpy_s(temp.IBSN, book[i].IBSN);
                strcpy_s(book[i].state,book[book_number].state);
                strcpy_s(book[i].name, book[book_number - 1].name);
                strcpy_s(book[i].IBSN, book[book_number - 1].IBSN);
                memset(book[book_number - 1].name, 0, sizeof(book[book_number - 1].name));
                memset(book[book_number - 1].IBSN, 0, sizeof(book[book_number - 1].IBSN));
            }
            book_number--;
            cout << "ɾ���ɹ�!" << endl;
        }
    }

}//�쳣����
void BadBeheavior(User user[], int& user_number)
{

    char a[5] = "��";
    char b[5];
    for (int i = 0; i < user_number; i++)
    {
        if (user[i].bad_return_book != 0)
        {
            cout << "�����쳣�����û�:" << user[i].name << endl;
            cout << "�Ƿ������д��������ظ����ǡ��򡰷񡱣�";
            cin >> b;
            if (strcmp(a, b) == 0)
            {
                cout << user[i].name << "�����쳣�����ܵ�ͼ�����Ա��������ͣ���ķ�������ϵͼ�����Ա����ϵ�绰��17719577839" << endl;
                cout << "��ѡ��΢��ת��50Ԫ�ָ����ģ�΢�źţ�ma23462471311" << endl;
            }
            strcpy_s(user[i].person_state, "�쳣");
        }
        else
        {
            cout << "�û�" << user[i].name << "�������ã��������쳣��¼Ŷ~" << endl;
        }
    }
}
void Announce(Contents news[], int& new_number)
{
    cout << "�뷢���µĹ���:";
    cin >> news[new_number].notice;
    new_number++;
}
void LibraryManger(User user[], Books book[], Contents news[], int& book_number, int& news_number, int& user_number) {
    cout << "======ͼ�����Ա����======" << endl;
    cout << "      1.���ͼ��      " << endl;
    cout << "      2.ɾ��ͼ��      " << endl;
    cout << "      3.�쳣���鴦��   " << endl;
    cout << "      4.��������      " << endl;
    cout << "     �����������ֽ���ǳ�����" << endl;
    cout << "=========================" << endl;
    while (1) {
        int n;
        cin >> n;
        if (n > 4 || n < 1)
        {
            break;
        }
        switch (n) {
        case 1:
            AddBook(book_number, book);//���ͼ��
            break;
        case 2:
            DeleteBook(book_number, book);//ɾ��ͼ��
            break;
        case 3:
            BadBeheavior(user, user_number);//�쳣��Ϊ����
            break;
        case 4:
            Announce(news, news_number);//��������
            break;
        }
        OutputFile(user, book, news, user_number, book_number, news_number);
        cout << endl;
        cout << "����ʹ�û��������������˳�ͼ�ܵ�¼" << endl;
    }
}

//��������Ա����
void ChangePassword(User user[], int& user_number)
{
    int id1;
    cout << "�����޸�IDΪ���ٵ��û����룿";
    cin >> id1;
    char new_password[50];
    for (int i = 0; i < user_number; i++)
    {
        if (id1 == user[i].ID)
        {
            cout << "��������ĺ��������:";
            cin >> new_password;
            strcpy_s(user[i].password, new_password);
            break;
        }
    }

    cout << "�԰���Ҫ������Ϊ�û���������!" << endl;
}
void DeleteLast(User user[], int i)
{
    user[i].ID = NULL;
    memset(user[i].name, 0, sizeof(user[i].name));
    memset(user[i].password, 0, sizeof(user[i].password));
    memset(user[i].Lent_name, 0, sizeof(user[i]).Lent_name);
    memset(user[i].type, 0, sizeof(user[i].type));//ע�����
    user[i].number = 0;//��������Ŀ
    user[i].day = NULL;
    user[i].bad_return_book = NULL;
    memset(user[i].person_state, 0, sizeof(user[i].person_state));
}
void DeleteUser(User user[], int& user_number, int i)
{
    strcpy_s(user[i].name, user[user_number - 1].name);
    strcpy_s(user[i].password, user[user_number - 1].password);
    strcpy_s(user[i].Lent_name, user[user_number - 1].Lent_name);
    strcpy_s(user[i].person_state, user[user_number - 1].person_state);
    user[i].ID = user[user_number - 1].ID;
    strcpy_s(user[i].type, user[user_number - 1].type);
    user[i].day = user[user_number - 1].day;
    user[i].number = user[user_number - 1].number;
    user[i].bad_return_book = user[user_number - 1].bad_return_book;
    //���
    user[user_number - 1].ID = NULL;
    memset(user[user_number - 1].name, 0, sizeof(user[user_number - 1].name));
    memset(user[user_number - 1].password, 0, sizeof(user[user_number - 1].password));
    memset(user[user_number - 1].Lent_name, 0, sizeof(user[user_number - 1]).Lent_name);
    memset(user[user_number - 1].type, 0, sizeof(user[user_number - 1]).type);
    user[user_number - 1].number = NULL;
    user[user_number - 1].bad_return_book = NULL;
    memset(user[user_number - 1].person_state, 0, sizeof(user[user_number - 1]).person_state);
    user[user_number - 1].number = NULL;//��������Ŀ
}
void MangeCommonUser(User user[], int& user_number)
{
    int id1;
    cout << "�������IDΪ���ٵ���ͨ�û���" << endl;
    cin >> id1;
    for (int i = 0; i < user_number; i++)
    {
        if (id1 == user[i].ID)
        {
            if (strcmp(user[i].type,"��ͨ")!=0)
            {
                cout << "��Ǹ����ID���û�������ͨ�û�";
            }
            else
            {
                while (1)
                {
                    cout << "====������ͨ�û�====" << endl;
                    cout << "1.�鿴�û�����״̬" << endl;
                    cout << "2.�鿴�û�����ͼ��" << endl;
                    cout << "3.�鿴�û��쳣�������" << endl;
                    cout << "4.�鿴�û�����ʣ��ʱ��" << endl;
                    cout << "5.��ʾ�û���Ϣ" << endl;
                    cout << "6.ע���û�" << endl;
                    cout << "�������������˳�������ͨ�û�" << endl;
                    cout << "===================" << endl;

                    int n;
                    cin >> n;
                    if (n > 6 || n < 1)
                    {
                        break;
                    }
                    switch (n) {
                    case 1:
                        cout << user[i].name << "�Ľ���״̬��";
                        if (user[i].person_state) {
                            cout << "��������" << endl;
                        }
                        else {
                            cout << "��ͣ���ķ���" << endl;
                        }
                        break;
                    case 2:
                        if (user[i].number) { cout << user[i].name << "������ͼ�飺" << user[i].Lent_name << endl; }
                        else {
                            cout << user[i].name << "��δ����ͼ��" << endl;
                        }
                        break;
                    case 3:
                        cout << user[i].name << "���쳣�������:" << user[i].bad_return_book << endl;
                        break;
                    case 4:
                        cout << user[i].name << "��ʣ�໹��ʱ��:" << user[i].day << endl;
                        break;
                    case 5:
                        cout << user[i].name << "���û�������Ϣ��" << endl;
                        cout << "����:" << user[i].name << endl << "ID:" << user[i].ID << endl << "����:"
                            << user[i].password << endl;
                        break;
                    case 6:
                        if (i == user_number - 1) {
                            DeleteLast(user, i);
                        }
                        else {//��λ
                            
                            DeleteUser(user, user_number, i);
                        }
                        cout << "��ע��" << endl;
                        user_number--;
                        break;
                    }
                }
                
            }
        }
    }

}
void MangerLibrary(User user[], int &user_number,int & book_number,int& news_number,Books book[],Contents news[])
{
    int id1;
    cout << "�������IDΪ���ٵ�ͼ�����Ա��";
    cin >> id1;
    for (int i = 0; i < user_number; i++)
    {
        if (id1 == i + 1)
        {
            if (strcmp(user[i].type,"ͼ��")!=0)
            {
                cout << "��Ǹ����ID���û�����ͼ�����Ա";
            }
            else
            {
                while (1)
                {
                    cout << "====����ͼ�����Ա====" << endl;
                    cout << "1.�鿴�û�����״̬" << endl;
                    cout << "2.�鿴�û�����ͼ��" << endl;
                    cout << "3.�鿴�û��쳣�������" << endl;
                    cout << "4.�鿴�û�����ʣ��ʱ��" << endl;
                    cout << "5.��ʾ�û���Ϣ" << endl;
                    cout << "6.ע���û�" << endl;
                    cout << "�������������˳�����ͼ�����Ա" << endl;
                    cout << "===================" << endl;
                    int n;
                    cin >> n;
                    if (n > 7 || n < 1)
                    {
                        break;
                    }
                    switch (n) {
                    case 1:
                        cout << user[i].name << "�Ľ���״̬��";
                        if (user[i].person_state) {
                            cout << "��������" << endl << endl;
                        }
                        else {
                            cout << "��ͣ���ķ���" << endl;
                        }
                        break;
                    case 2:
                        if (user[i].number) { cout << user[i].name << "������ͼ�飺" << user[i].Lent_name << endl; }
                        else {
                            cout << user[i].name << "��δ����ͼ��" << endl;
                        }
                        break;
                    case 3:
                        cout << user[i].name << "���쳣�������:" << user[i].bad_return_book << endl;
                        break;
                    case 4:
                        cout << user[i].name << "��ʣ�໹��ʱ��:" << user[i].day << endl;
                        break;
                    case 5:
                        cout << user[i].name << "���û�������Ϣ��" << endl;
                        cout << "����:" << user[i].name << endl << "ID:" << user[i].ID << endl << "����:"
                            << user[i].password << endl;
                        break;
                    case 6:
                        if (i == user_number - 1) {
                            DeleteLast(user, i);
                        }
                        else {
                            DeleteUser(user, user_number, i);
                        }
                        cout << "��ע��" << endl;
                        user_number--;
                        break;
                    }
                }
                OutputFile(user, book, news, user_number,book_number,news_number);
            }
        }
    }

}

void SuperManger(User user[], Books book[], Contents news[], int& book_number, int& news_number, int& user_number) {
    cout << "======��������Ա����======" << endl;
    cout << "      1.�޸�����      " << endl;
    cout << "      2.������ͨ�û�      " << endl;
    cout << "      3.����ͼ�����Ա   " << endl;
    cout << "     �����������ֽ���ǳ�����" << endl;
    cout << "============================" << endl;
    while (1) {
        int n;
        cin >> n;
        if (n > 3 || n < 1)
        {
            break;
        }
        switch (n) {
        case 1:
            ChangePassword(user, user_number);
            break;
        case 2:
            MangeCommonUser(user, user_number);
            break;
        case 3:
            //User user[], int user_number,int & book_number,int& news_number,Book book[],Contents news[]
            MangerLibrary(user, user_number,book_number,news_number,book,news);
            break;
        }
        cout << endl;
        OutputFile(user, book, news, user_number, book_number, news_number);
        cout << "����ʹ�û��������������˳����ܵ�¼" << endl;
    }
}
void OutputFile(User user[], Books book[], Contents news[], int user_number, int book_number, int news_number)
{
    //д�ļ�������
    ofstream ofs;
    ofs.open("User.txt", ios::trunc);
    //д�û�
    for (int i = 0; i < user_number; i++)
    {//            1                  ������                 1                          ��ͨ                  0                      ����                             ��                               0                         0
        ofs << user[i].ID << " " << user[i].name << " " << user[i].password << " " << user[i].type << " " << user[i].day << " "<< user[i].person_state << " " << user[i].Lent_name << " " << user[i].bad_return_book<<" "<<user[i].number << endl;
        
    }
    ofs.close();
    //д����
    ofstream ofs1;
    ofs1.open("news.txt", ios::trunc);
    for (int i = 0; i < news_number;i++)
    {
        ofs1 << news[i].notice << endl;
    }
    ofs1.close();
    //�ļ�д��
    ofstream ofs2;
    ofs2.open("Book.txt", ios::trunc);
    for (int i = 0; i < book_number; i++)
    {
        ofs2 << book[i].name << " " << book[i].IBSN <<" "<<book[i].state << endl;
    }
    ofs2.close();
}

int main()
{
    //��ʼ������
    User user[50];
    string a;
    int user_number = 3;
    string filename = "E:\\ͼ��VS\\LibraryManger\\Project1\\User.txt";
    ifstream fin(filename,ios::in);//�������

    int i = 0,index=3;
    while(fin >> user[i].ID >> user[i].name >> user[i].password >> user[i].type >> user[i].day >>user[i].person_state >> user[i].Lent_name >> user[i].bad_return_book>>user[i].number)
    {
        
         
         i++;
    }
    fin.close();//�� 
    Contents news[100];
    int news_number = 1;
    string filename1 = "E:\\ͼ��VS\\LibraryManger\\Project1\\news.txt";
    ifstream fin1(filename1, ios::in); i = 0;
    while(fin1 >> news[i].notice)
    {
        i++;
    }
    fin1.close();
    Books book[50];
    string filename3 = "E:\\ͼ��VS\\LibraryManger\\Project1\\Book.txt";
    int book_number = 3;
    ifstream fin3(filename3, ios::in); i = 0;
    while (fin3 >> book[i].name >> book[i].IBSN >> book[i].state)
    {
        i++;
    }
    //���ĳ���ʼ��
    while (1)
    {
        int rank = 0;//��Ա���ͣ�1����ͨ��2��ͼ�ܣ�3�ǳ���
        Interface();//��������
        cout << "             ��¼����" << endl;
        while (1)
        {
            if (login(user, rank, user_number))//������������棬����ȷ������һ��
            {
                break;
            }
        }
        logined(user, rank);//��½���֪��Ϣ
        switch (rank)//�ֲ�ʵ��ÿһ�û��ع���
        {
        case 1://ʵ����ͨ�û��ĸ��ֹ���
            //Books book[], int rank, User user[], Contents news[], int& book_number, int news_number,int user_number
            commonUser(book, rank - 1, user, news, book_number, news_number,user_number);//rank�����һ��Ϊ������0��
            break;
        case 2:
            LibraryManger(user, book, news, book_number, news_number, user_number);
            break;
        case 3:
            SuperManger(user, book, news, book_number, news_number, user_number);
            break;
        }
        cout << "*�˳����������롱0��*" << endl;
        cout << "�����������ͼ�����ϵͳ����������������ּ���" << endl;
        int num;
        cin >> num;
        if (num)
        {
            continue;
        }
        else
        {
            break;
        }
    }

}
