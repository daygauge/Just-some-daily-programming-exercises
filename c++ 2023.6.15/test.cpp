#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>

class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0 || k == 0) return res;
        deque<int> d;
        for (int j = 0, i = 1 - k; j < nums.size(); i++, j++) {
            if (i > 0 && d.front() == nums[i - 1]) d.pop_front();
            while (!d.empty() && d.back() < nums[j]) d.pop_back();
            d.push_back(nums[j]);
            if (i >= 0) res.push_back(d.front());
        }
        return res;
    }
};
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> vls;
        for (int j = 0, i = 0 - (k - 1); j < nums.size(); i++, j++)//ѭ����������-(k+1)��,jΪ����β,iΪ����ͷ
        {
            if (i > 0 && vls.front() == nums[i - 1]) vls.pop_front();//����ͷi����0���ҵ����ڵ�ֵ����k��ʱ����ͷֵ
            if (i >= 0 && vls.front() > nums[j])//��ͷ������ӣ���ͷС����պ����
            {
                vls.push_back(nums[j]);
            }
            else
            {
                vls.clear();
                vls.push_back(nums[j]);
            }
            if (i >= 0)v.push_back(vls.front());
        }
        return v;
    }
};
class testls
{
public:
    void operator()(int a)
    {
        cout << a << " ";
    }
};
void test()
{
    Solution1 s1;
    vector<int> v = { 1,3,1,2,0,5 };
    int a = 3;
    vector<int> v1 = s1.maxSlidingWindow(v, a);;
    for_each(v1.begin(), v1.end(), testls());
}


void test01()
{
    vector<int> v = { 4,8,3,60,26,83,32,12 };
    //make_heap(v.begin(), v.end(), greater<int>());
    make_heap(v.begin(), v.end(), less<int>());
    for_each(v.begin(), v.end(), testls());
    cout << endl;

    v.push_back(110);
    for_each(v.begin(), v.end(), testls());
    push_heap(v.begin(), v.end(), less<int>());
    cout << endl;
    for_each(v.begin(), v.end(), testls());
    cout << endl;


    pop_heap(v.begin(), v.end(), less<int>());
    for_each(v.begin(), v.end(), testls());
    v.pop_back();
    cout << endl;
    for_each(v.begin(), v.end(), testls());
    cout << endl;

    sort_heap(v.begin(), v.end(), less<int>());
    for_each(v.begin(), v.end(), testls());
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), testls());
    cout << endl;

}
class Solution002 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();//ȡnums�����ֵ

        priority_queue<pair<int, int>> q;//�󶥶�

        for (int i = 0; i < k; i++)//���󶥶��еĶ������k��ֵ������¼nums��Ԫ�غ���ԭ�����±�
        {
            q.emplace(nums[i], i);
        }

        vector<int> ans;//�������ڷ��ص�vector����
        ans.push_back(q.top().first);//ȡ�Ѷ�����������������
        for (int i = k; i < n; i++)//�ӵ�k��Ԫ�ؿ�ʼ�������ڱ���
        {
            q.emplace(nums[i], i);//д���µ�nums����
            while (i - q.top().second + 1 > k)//ͨ���Ѷ����±���i�ĶԱȣ��жϵ��Ѷ�Ԫ�ص���Ԫ�س���kʱ���Ѷ��䵯����
            {
                q.pop();
            }
            ans.push_back(q.top().first);//ÿ��������һ�λ��������� ���ڷ��ص�vector���� ��д��Ѷ����Ԫ��
        }
        return ans;
    }
};

class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {

    }

    int max_value() {
        if (!q.size()) return -1;
        return d.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
    }

    int pop_front() {
        if (!q.size()) return -1;
        int i = q.front();
        q.pop();
        if (d.front() == i) d.pop_front();
        return i;
    }
};

void test02()
{
    MaxQueue m;
    m.push_back(1);
    m.push_back(2);
    cout << m.max_value() << endl;
    cout << m.pop_front() << endl;
    cout << m.max_value() << endl;

    //queue<int> q;
    //q.push(1);
    //q.push(2);

}
int main()
{
    //test();
    //test01();
    test02();
	return 0;
}