#pragma once
#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#define ZDX 1000
typedef struct mailList
{
	string mane;
	string surname;
	int age;
	string telephone;
	string HomeAddress;
}mail;
typedef struct NumberofAddressBooks
{
	mail txr[ZDX];
	int dqgs;
}Books;

void AddContacts(Books* lx);//�����ϵ��

void ShowContacts(Books* lx);//��ʾ��ϵ��

void DeleteContacts(Books* lx);//ɾ����ϵ��

void SeekContacts(Books* lx);//������ϵ��

void ReviseContacts(Books* lx);//�޸�����ϵ��

void EmptyContacts(Books* lx);//������ϵ���б�