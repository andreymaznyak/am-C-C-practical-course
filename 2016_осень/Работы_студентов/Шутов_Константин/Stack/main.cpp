/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: КОНСТАНТИН
 *
 * Created on 25 ноября 2016 г., 20:20
 */

#include <iostream>

using namespace std;

template <class T>
class Stack
{
	struct List
	{
		T data;
		List *next;
	};
	List *head = NULL;
	public:
	void push (T p)
	{
		List *tmp = head;
		if(head != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp=tmp->next;
			}
			List *new_list = new List;
			new_list->data=p;
			new_list->next=NULL;
			tmp->next=new_list;
		}
		else
		{
			List *new_list = new List;
			new_list->data=p;
			new_list->next=NULL;
			head=new_list;
		}
	}

	void print()
	{
		List *tmp = head;
		while (tmp != NULL)
		{
			cout<<tmp->data<<endl;
			tmp=tmp->next;
		}
	}
	
	T pop()
	{
		T p;
		List *tmp = head;
		int i=0;
		while (tmp->next != NULL)
		{
			i++;
			if(tmp->next->next==NULL) 
			{
				p = tmp->next->data;
				tmp->next=NULL;
				break;
			}			
			tmp=tmp->next;
		}
		if(i==0) 
		{
			p = head->data;
			head = NULL;
		}
		return p;
	}
};

int main()
{
	Stack<int> tmp;
	tmp.push(8);
	tmp.push(1);
	tmp.push(2);
	tmp.push(7);
	tmp.push(3);
	tmp.print();
	cout<<endl;
	tmp.pop();
	tmp.pop();
	tmp.pop();
	tmp.pop();
	tmp.pop();
	cout<<endl;
        return 0;
}