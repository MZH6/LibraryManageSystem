#include"Book.h"
#include"Users.h"
#include"Content.h"
#include"UserFunctions.h"
#include<conio.h>
#include<iostream>
#include"LM.h"
#include"SuperManger.h"
//�������ǲ���
string Unshow()
{
    char pass;
    string unshowpass;
    for (int i = 0; i < 6; i++)
    {
        pass = _getch();//���벻����ʾ����Ļ��
        if (pass >= 33 && pass <= 126)
        {
            if (i == 0) unshowpass = pass;
            else
                unshowpass = unshowpass + pass;
            cout << "*";// �����Ǻ�
        }
        else
        {
            cout << "���ڷǷ��ַ������������룺" << endl;
            i = -1;
        }
    }
    cout << endl;
    return unshowpass;
}
string C;
string L;
string c,l;
int main()
{
    int user_number = 4; int book_number = 5; int news_number = 1;
    UserList userlist;      //�û�����
    BookList booklist;      //ͼ������
    ContentList contentlist;   //��������
    int change = 0;//��Ҫ�޸����������
    //�����ļ�����
    Read(user_number, userlist, book_number, booklist, news_number, contentlist);
    string NAME;
    //���ĳ���ʼ
    string id;
    while (1)
    {
        int lentnumber = 0;
        Interface();//�ܽ���
        cout << "-----------------��¼����-----------------" << endl;
        cout << "1.��¼" << endl;
        cout << "2.ע��" << endl;
        cout << "3.��������" << endl;
        cout << "�������������˳�����" << endl;
        //  userlist.show();//�����û����
        //  booklist.show();//�����鱾���
        //  contentlist.show();//���Թ������
        int n; cin >> n;
        //��¼����
        if (n == 1)
        {
            cout << "����������ID:" << endl; cin >> id;//IDʶ��
            cout << "��ѡ����������ģʽ:" << endl;
            cout << "  1.��ʾ����  ||  2.��������" << endl;
            cout << "������ѡ��:";
            int mod; cin >> mod;
            cout << "�������������루��λ���룩:";
            //�������Ϊ* ���ж������Ƿ���ȷ
            if (mod == 2)//�������Ǻ�
            {
                string pass1;
                cout << "����(��λ����)��";
                pass1 = Unshow();
                cout << endl;
                while (  true)
                {
                    if (Correct(userlist, pass1,id))
                    {
                        cout << "��������������������������:";
                        cout << "����(��λ����)��";
                        pass1 = Unshow();
                        cout << endl;
                    }
                    else
                    {
                        break;
                    }

                }
                cout << "������ȷ��" << endl;
            }
            else
            {
                string pass1;
                cin >> pass1;
                while (true)
                {
                    if(Correct(userlist, pass1,id))
                    {
                        
                        cout << "��������������������������:";
                        cin >> pass1;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "�ɹ���¼��" << endl;
            }
            UserList new_userlist = FaceUser(userlist, id);//�ҵ�ID����Ӧ���û�����  new_userlist��
            //��ͨ�û�
            if (new_userlist.head->user->Type == "��ͨ�û�")
            {
                while (1)
                {
                    if (new_userlist.head->user->hua !="")
                    {
                        cout << "�г�������Ա֪ͨ��" << L;
                    }
                    cout << "Hi!��ͨ�û�" << new_userlist.head->user->Name << "�������˶����~" << endl;
                    //��ͨ�û����ܺ����ͽ����
                    CommonUserLogin(booklist);
                    if (new_userlist.head->user->ID == c)
                    {
                        cout << "�г�������Ա֪ͨ��" << C;
                    }
                    int n;
                    cin >> n;
                    if (n < 1 || n>6)
                    {
                        break;
                    }
                    switch (n)
                    {
                    case 1://ԤԼ���鹦��
                        Lent(new_userlist, booklist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    case 2://���鹦��
                        Give(new_userlist, booklist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    case 3://�鿴������Ϣ����
                        FindMessage(new_userlist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    case 4://��ѯͼ����Ϣ
                        FindBook(booklist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    case 5://��ѯ����
                        FindContent(contentlist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    case 6://�޸�����
                        ChangeMiMa(new_userlist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        break;
                    }
                    if (n == 6)
                    {
                        break;
                    }

                }
            }
            //ͼ�����Ա
            else if (new_userlist.head->user->Type == "ͼ�����Ա")
            {
                while (1)
                {
                    cout << "Hi!����Ա" << new_userlist.head->user->Name << "�������ң�����Ϊ��" << endl;
                    LibraryMangerLogin();//��¼��չʾ�Ľ���
                    int num; cin >> num;
                    if (num > 5 || num < 1)
                    {
                        break;
                    }
                    if (new_userlist.head->user->hua =="��")
                    {
                        
                    }
                    else
                    {
                        cout << "�г�������Ա֪ͨ��" << L;
                    }
                    switch (num)
                    {
                    case 1://���ͼ�鹦��
                    {
                        while (1)
                        {
                            string bookname; int addnumber, bookibsn;
                            cout << "��Ҫ��������ͼ���棬���������ͼ�飿" << endl << "1.��������ͼ�� || 2.�����ͼ�� || �������������˳�����" << endl;
                            int n; cin >> n;
                            if (n == 1)
                            {
                                cout << "����������Ҫ����ͼ������ƣ�";
                                cin >> bookname;
                                cout << "����������Ҫ����ͼ��ı�����";
                                cin >> addnumber;
                                if (AddNowBook(booklist, addnumber, bookname))
                                {
                                    cout << "�����鱾�ɹ���" << endl;
                                }
                                else
                                {
                                    cout << "�����鱾�������Ժ�����" << endl;
                                    break;
                                }


                            }
                            else if (n == 2)
                            {

                                cout << "��������Ҫ���ͼ������ƣ�";
                                cin >> bookname;
                                while (1)
                                {
                                    int panduan = 0;
                                    cout << "��������Ҫ���ͼ���IBSN�ţ�";/////////////////�ⲽ�����ǿ�IBSN���ظ���
                                    cin >> bookibsn;
                                    BookNode* p = booklist.head;
                                    while (p)
                                    {
                                        if (p->book->IBSN == bookibsn)
                                        {
                                            cout << "�������IBSN���ظ�������������" << endl;
                                            panduan = 1;
                                        }
                                        p = p->next;
                                    }
                                    if (panduan)
                                    {
                                        continue;
                                    }
                                    break;

                                }

                                cout << "����������Ҫ����ͼ��ı�����";
                                cin >> addnumber;
                                Book* a = new Book;
                                a->set_bookname(bookname); a->set_number(addnumber); a->set_IBSN(bookibsn);
                                booklist.AddBook(a);
                            }
                            else
                            {
                                break;
                            }
                        }
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    case 2: //ɾ��ͼ�鹦��
                        //  while (1)
                        //  {
                            //  string n1;
                             // cout << "����ȷ��������ɾ�������������������˳�����";cout << endl;
                             // cin >> n1;
                             // if (n1 == "ȷ��")
                            //  {
                    {string bookname1;
                    cout << "����������ɾ��ͼ������ƣ�";
                    cin >> bookname1;
                    DeleteBook(booklist, bookname1, book_number);
                    cout << "�Ѱ�Ҫ��ɾ��ͼ��" << endl;
                    OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number); 
                    }
                    //  }
                     // else
                    //  {
                   //       break;
                     // }
                //  }
                    break;
                    case 3://�쳣����
                    {
                        Punish(userlist);
                        cout << "*�쳣��ѯ����*" << endl; 
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    case 4://��������
                    {  
                        string bookname;
                        PostContent(contentlist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    case 5://�޸�����
                    {
                        ChangeMiMa(new_userlist);
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    if (n == 5)
                    {
                        break;
                    }
                    }
                }
            }
            //��������Ա
            else
            {
                cout << "Hi!����" << new_userlist.head->user->Name << "������Խ������Խ��" << endl;

                while (1)
                {
                    SuperMangerLogin();
                    int n;
                    cin >> n;
                    if (n < 1 || n>5)
                    {
                        break;
                    }
                    switch (n)
                    {
                        //�޸�����
                    case 1:
                    {
                        string id;
                        cout << "�����޸�IDΪ���ٵ��û����룿";
                        cin >> id;
                        while (1)//�ж�id�Ƿ�Ϸ�
                        {
                            if (IDCorrect(userlist, id))
                            {
                                break;
                            }
                            cout << "ID���벻�Ϸ������������룺";
                        }
                        string new_pass1;
                        UserNode* p = userlist.head;
                        while (p)
                        {
                            if (p->user->ID == id)
                            {
                                cout << "���뽫�������޸�Ϊ���٣�(��λ����)" << endl;
                                cin >> new_pass1;
                                //�жϳ���
                                while (1)
                                {
                                    if (new_pass1.length() == 6)
                                    {
                                        break;
                                    }
                                    cout << "������������������" << endl;
                                    cin >> new_pass1;
                                }
                                p->user->Password = new_pass1;
                                cout << "�޸ĳɹ���" << endl;
                                break;
                            }
                            p = p->next;
                        }
                        OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    //�����û�
                    case 2:
                    {
                        cout << "====�����û�====" << endl;
                        cout << "1.��ʾ�û���Ϣ" << endl;
                        cout << "2.ע���û�" << endl;
                        cout << "�������������˳������û�" << endl;
                        cout << "===================" << endl;
                        int n;
                        cin >> n;
                        switch (n)
                        {
                        case 1:
                        {
                            cout << "����������鿴���û�ID��";
                            string id;
                            cin >> id;
                            FindUser(userlist,id);
                            OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        }
                        break;
                        case 2:
                        {
                            DeleteLoop(userlist,user_number);
                            cout << "��ע��" << endl;
                            OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                        }
                        }
                    }
                    break;;
                    case  3:
                    {
                         SortByHot(booklist);
                         OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    }
                    break;
                    case 4:
                    {
                        cout << "����������֪ͨ���û�ID��";
                        cin >> l;
                        cout << "����������Ҫ�������Ϣ��";
                            cin >> L;
                            UserNode* p = userlist.head;
                            while (p)
                            {
                                if (p->user->ID == l)
                                {
                                    p->user->hua = L;
                                    break;
                                }
                                p = p->next;
                            }
                            
                    }
                    OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
                    break;
                    }
                   
                }
            }
        }

        //ע�����
        else if (n == 2)/////////////////////// ע �� �� �� ////
        {
            cout << "=====��ӭ����ע�����====" << endl;
            string aID;
            cout << "����������������";
            cin >> NAME;
            cout << "����ID��";
            cin >> aID;
            while (IDCorrect(userlist, aID))
            {
                cout << "���������ID�Ѿ����û�ʹ���ˣ�������һ���µ�ID��";
                cin >> aID;
            }

            string pass1, pass2;
            cout << "��ѡ����������ģʽ:" << endl;
            cout << "  1.��ʾ����  ||  2.��������" << endl;

            int n; cin >> n;
            //�ж������ѡ��ģ���Ƿ�Ϸ�
            while (1)
            {
                if (n == 1 || n == 2)
                {
                    break;
                }
                else
                {
                    cout << "��Ч���֣����������룺";
                    cin >> n;
                }
            }
            cout << "��������������(��λ���룩��";
            if (n == 1)
            {
                cin >> pass1;
                cout << endl << "���ٴ�����";
                cin >> pass2;
                while (1)
                {
                    if (pass1 == pass2 && size(pass1) == 6)
                    {
                        break;
                    }
                    else
                    {
                        cout << "��Ǹ�����������������β�ͬ�򳤶���������������" << endl;
                        cout << "��������������(��λ���룩��";
                        cin >> pass1;
                        cout << endl << "���ٴ�����";
                        cin >> pass2;
                    }
                }
            }
            else
            {
                pass1 = Unshow();
                cout << endl << "���ٴ�����:";
                pass2 = Unshow();
                //�˶�����
                while (pass1 != pass2)
                {
                    cout << "��������������벻ͬ�����ٴγ��ԡ�" << endl;
                    cout << "�������������루��λ���룩:";
                    pass1 = Unshow();
                    cout << "����ȷ��һ�����룺";
                    pass2 = Unshow();
                    cout << endl;

                }
            }
            string Idten1, Idten2;//�˶����֤
            while (1)
            {
                cout << "�������������֤��(��ؼ�飩��"; cin >> Idten1;
                cout << "���ٴ�����һ�Σ�"; cin >> Idten2;
                if (Idten1 != Idten2)
                {
                    cout << "������������֤��Ϣ��ͳһ�����ٴγ��ԣ�" << endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
            User* a = new User;
            string putong = "��ͨ�û�";
            a->set_ID(aID); a->set_name(NAME); a->set_Password(pass1); a->set_Ident(Idten1); a->set_Type(putong), a->set_BookNumber(0);
            userlist.AddUser(a);
            cout << "�ɹ�ע�ᣡ"; cout << endl;

            OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);
        }
        //�����������
        else if (n == 3)
        {
            string aID, NAME; string shenfenzhenghao;
            cout << "����������ID��"; cin >> aID;
            cout << endl << "����������������"; cin >> NAME;
            cout << endl << "�������������֤�ţ�"; cin >> shenfenzhenghao;
            if (ChangeCorrect(userlist, aID, NAME, shenfenzhenghao))
            {
                ChangePassword(userlist, aID);
                cout << "�ѽ����������޸�Ϊ666666��6��6)" << endl;

            }
            else
            {
                cout << "�����������Ժ���" << endl;

            }
            OutputFile(userlist, booklist, contentlist, user_number, book_number, news_number);

        }
        //�˳�����
        else
        {
            break;
        }
    }
}