#include "Users.h"
/// /////////// �� ֵ //////////////////////////////////////////////////
void User::set_name(string n)
{ Name = n; }
void User::set_Password(string P) 
{ Password = P; }
void User::set_ID(string id) 
{ ID = id; }
void User::set_Ident(string i) 
{ Identification = i; }
void User::set_Type(string T) 
{ Type = T; }
void User::set_BookNumber(int n) 
{ BookNumber = n; }
///////////////////////////////////////// չ ʾ �� �� �� Ϣ //////////////////////////
void UserList::show()
{
    UserNode* p = head;
    while (p != NULL)
    {
        cout << p->user->ID << " " << p->user->Name << " " << p->user->Password << " " << p->user->Type << " " << p->user->person_state << " " << p->user->Identification << " " << p->user->bad_return_book << " " << p->user->BookNumber;
        for (int i = 0; i < p->user->BookNumber; i++)
        {
            if (p->user->BookNumber == 0)
            {
                break;
            }
            cout << " ���ĵ��鱾��" << p->user->LentBook[i][0] << "," << "ʣ��ʱ����" << p->user->LentBook[i][1];
        }
        cout << endl;
        p = p->next;
    }
}
/////////////////////////////////////// �� ¼ /////////////////////
int UserList::login(const string Id, const string password)
{
    UserNode* temp = this->head;
    while (temp)
    {
        if (temp->user->ID == Id && temp->user->Password == password)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;

}
/////////////////////////////// �� չ �� �� �� �� �� �� ///////////////////////
void UserList::AddUser(User* user1)
{
    UserNode* newNode = new UserNode();
    newNode->user = user1;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        UserNode* p = head;
        while (p->next != NULL)//p����һ�����ǿս���ѭ��
        {
            p = p->next;
        }
        p->next = newNode;
    }
}