#include <iostream>
using namespace std;

struct Elem
{
   int data; 
   Elem * next, * prev;
};

class List
{
   Elem * Head, * Tail;
    int Count;

public:

     List();
     List(const List&);
      ~List();
 
     int GetCount();
   Elem* GetElem(int);
	
      void DelAll();
   void Del(int pos = 0);
      void Insert(int pos = 0);
	
     void AddTail(int n);
	
      void AddHead(int n);
		
      void Print();	
   void Print(int pos);
	      
   List operator - ();
};

List::List()
{

   Head = Tail = NULL;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;

   
   Elem * temp = L.Head;
     while(temp != 0)
   {
       AddTail(temp->data);
      temp = temp->next;
   }
}

List::~List()
{
  
   DelAll();
}

void List::AddHead(int n)
{
   
   Elem * temp = new Elem;

   temp->prev = 0;
   temp->data = n;
   temp->next = Head;

   if(Head != 0)
      Head->prev = temp;

   if(Count == 0)
      Head = Tail = temp;
   else
      Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   
   Elem * temp = new Elem;
     temp->next = 0;
     temp->data = n;
     temp->prev = Tail;
	
   if(Tail != 0)
      Tail->next = temp;
	
   if(Count == 0)
      Head = Tail = temp;
   else
      Tail = temp;			

   Count++;
}

void List::Insert(int pos)
{
   
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }

   if(pos < 1 || pos > Count + 1)
   {
      
      cout << "Incorrect position !!!\n";
      return;
   }

   if(pos == Count + 1)
   {
     
      int data;
      cout << "Input new number: ";
      cin >> data;
      AddTail(data);
      return;
   }
   else if(pos == 1)
   {
      
      int data;
      cout << "Input new number: ";
      cin >> data;
      AddHead(data);
      return;
   }

  
   int i = 1;

   Elem * Ins = Head;

   while(i < pos)
   {
      
      Ins = Ins->next;
      i++;
   }

   Elem * PrevIns = Ins->prev;
   Elem * temp = new Elem;

   cout << "Input new number: ";
   cin >> temp->data; 
   if(PrevIns != 0 && Count != 1)
      PrevIns->next = temp;
   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;
	
   Count++;
}

void List::Del(int pos)
{
   
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
  
   if(pos < 1 || pos > Count)
   {
      
      cout << "Incorrect position !!!\n";
      return;
   }

   
   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
      Del = Del->next;
      i++;
   }

 
   Elem * PrevDel = Del->prev;
   Elem * AfterDel = Del->next;
   if(PrevDel != 0 && Count != 1)
      PrevDel->next = AfterDel;
   if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;
   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;
   delete Del;

   Count--;
}

void List::Print(int pos)
{
   
   if(pos < 1 || pos > Count)
   {
     
      cout << "Incorrect position !!!\n";
      return;
   }

   Elem * temp;
  
   if(pos <= Count / 2)
   {
     
      temp = Head;
      int i = 1;

      while(i < pos)
      {
         
         temp = temp->next;
         i++;
      }
   }
   else
   {
       
      temp = Tail;
      int i = 1;

      while(i <= Count - pos)
      {
         
         temp = temp->prev;
         i++;
      }
   }
  
   cout << pos << " element: ";
   cout << temp->data << endl;
}

void List::Print()
{
   if(Count != 0)
   {
      Elem * temp = Head;
      cout << "( ";
      while(temp->next != 0)
      {
          cout << temp->data << ", ";
          temp = temp->next;
      }

      cout << temp->data << " )\n";
   }
}

void List::DelAll()
{
   
   while(Count != 0)
      Del(1);
}

int List::GetCount()
{
    return Count;
}

Elem * List::GetElem(int pos)
{
   Elem *temp = Head;

   
   if(pos < 1 || pos > Count)
   {
      
      cout << "Incorrect position !!!\n";
      return 0;
   }

   int i = 1;
   
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }

   if(temp == 0)
      return 0;
   else
      return temp;
}
// Тестовый пример
void main()
{
   List L;

   const int n = 10;
   int a[n] = {0,1,2,3,4,5,6,7,8,9};

   // Добавляем элементы, стоящие на четных индексах, в голову,
   // на нечетных - в хвост
   for(int i = 0; i < n; i++)
      if(i % 2 == 0)
         L.AddHead(a[i]);
      else
         L.AddTail(a[i]);

   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   cout << endl;

   // Вставка элемента в список
   L.Insert();
   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   // Распечатка 2-го и 8-го элементов списка
   L.Print(2);
   L.Print(8);

   List T;

   // Копируем список
   T = L;
   // Распечатка копии
   cout << "List T:\n";
   T.Print();

   
}


