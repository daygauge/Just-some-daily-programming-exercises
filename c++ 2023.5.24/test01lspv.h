#pragma once
#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <unordered_map>

//class pvls1
//{
//public:
//	int mutex = 0;
//	int apple = 0;
//	int orange = 0;
//	int plate = 0;
//};

/*
* int chopsticks[] = {1,1,1,1,1};
* int data = 4;
* int mutex = 1;//����
* p1()
* {   p(mutex);//--
*     p(chopsticks[n]);//�������--
*     p(chopsticks[(n+1)%5]);//���ҿ���--
*     v(mutex);//++
*     �Է�
*     v(chopsticks[n]);//�������++
*     v(chopsticks[(n+1)%5]);//���ҿ���++

* 
*     ˼��
* }
* 
* p2()
* {
*     p(data);//��������++;
*     if(data%2)
*     p(chopsticks[n]);//�������--
*     p(chopsticks[(n+1)%5]);//���ҿ���--
*     else
*     p(chopsticks[(n+1)%5]);//���ҿ���--
*     p(chopsticks[n]);//�������--
*     �Է�
*     p(chopsticks[n]);//�������
*     p(chopsticks[(n+1)%5]);//���ҿ���
*     v(data);//��������--;
* 
*     ˼��
* }
* p3()
* {
* 
* }
* p4()
* {
* 
* }
* p5()
* {
* 
* }
* p6()
* {
* 
* }
*/
