#include "Book.h"
using namespace std;
//չʾ�鱾��
void BookList::show()
{
    BookNode* p = head;
    while (p != NULL)
    {
        cout << p->book->IBSN << " " << p->book->name << " " << p->book->state << " " << p->book->number << endl;
        p = p->next;
    }
}
//����������鱾����
void BookList::AddBook(Book* book1)//������³�Ա
{
    BookNode* newNode = new BookNode;
    newNode->book = book1;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        BookNode* p = head;
        while (p->next != NULL)//p����һ�����ǿս���ѭ��
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

/* ~BookList()
    {
        BookNode* temp = NULL;
        BookNode* p = head;
        while (p != NULL)
        {
            temp = p;
            p = p->next;
            delete temp->book;
            delete temp;
        }
    }*/