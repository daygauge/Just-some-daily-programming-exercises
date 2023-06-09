#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (!s2.size() && !s1.size())return -1;
        if (s2.size())
        {
            int i = s2.top();
            s2.pop();
            return i;
        }
        else
        {
            while (s1.size())
            {
                int i1 = s1.top();
                s1.pop();
                s2.push(i1);
            }
            int i = s2.top();
            s2.pop();
            return i;
        }
    }
};

//class Solution {
//public:
//    bool isNumber(string s) 
//    {
//        int i = 0;
//        int lsd = 1;
//        int lse = 1;
//        while (s[i] == ' ')i++;//�����ո�
//
//        if ((s[i] == '+' || s[i] == '-'))i++;//�жϿ�ͷ�ַ�
//        else if (s[i] >= 0 + 48 && s[i] < 10 + 48);
//        else if (s[i] == '.' && (s[i + 1] >= 0 + 48 && s[++i] < 10 + 48)) lsd=0;
//        else return false;
//
//        if ((s[i] >= 0 + 48 && s[i] < 10 + 48)||s[i]=='.')
//        {
//            while (i < s.size())
//            {
//                if (s[i] >= 0 + 48 && s[i] < 10 + 48)
//                {
//
//                }
//                else if (s[i] == 'e' || s[i] == 'E')
//                {
//                    if (lse) lse = 0;
//                    else return false;
//
//                    if (i == s.size() - 1)return false;
//                    if ( (s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48) )
//                    {
//
//                        if (s[i + 1] >= 0 + 48 && s[i + 1] < 10 + 48)
//                        {
//
//                        }
//                        else if (s[i + 1] == '-')
//                        {
//                            if (s[i + 2] >= 0 + 48 && s[i + 2] < 10 + 48)
//                                i++;
//                        }
//                        else
//                        {
//                            return false;
//                        }
//                    }
//                    else
//                    {
//                        return false;
//                    }
//                }
//                else if (s[i] == '.')
//                {
//                    if (!lse) return false;
//                    if(lsd) lsd = 0;
//                    else return false;
//
//                    if (i + 1 == s.size())
//                    {
//                        if ((s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48)) return true;
//                        else return false;
//                    }
//                    else if ((s[i - 1] >= 0 + 48 && s[i - 1] < 10 + 48));
//                    else if (s[i + 1] >= 0 + 48 && s[i + 1] < 10 + 48);
//                    else if (s[i + 1] == ' ');
//                    else return false;
//                }
//                else if (s[i] == ' ')
//                {
//                    while (s[i] == ' ' && i < s.size())i++;
//                    if (i == s.size()) return true;
//                    else return false;
//                }
//                else
//                {
//                    return false;
//                }
//                i++;
//            }
//        }
//        else
//        {
//            return false;
//        }
//        return true;
//    }
//};
// 
// 
class Solution01 {
public:
    bool isNumber(string s)
    {
        if (!s.size())return false;//�п�
        int i = 0;
        while (s[i] == ' ')++i;//�����ո�
        bool sbf = fjjc(s, i);//�жϿ�ͷ���ź����ַ���

        if (s[i] == '.')//�жϵ�
        {
            ++i;

            sbf = prints(s, i) || sbf;//����������ַ�
        }

        if (s[i] == 'e' || s[i] == 'E')//�ж�e
        {
            ++i;
            sbf = fjjc(s, i) && sbf;//������e���ַ�
        }

        while (s[i] == ' ')++i;//�����ո�
        return sbf && i == s.size();
    }
    bool fjjc(string& s, int& i)//��ͷ�����ж�
    {
        if (s[i] == '+' || s[i] == '-')++i;
        return prints(s, i);
    }
    bool prints(string& s, int& i)//���ַ����ж�
    {
        int pos = i;
        while (i != s.size() && s[i] >= '0' && s[i] <= '9')++i;
        return pos < i;
    }
};


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution121 {
public:
    ListNode* dls(ListNode* head, ListNode* headls)
    {
        if (head->next == NULL) return head;

        headls->val = (dls(head->next, headls)->val);
        headls = headls->next;

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* headls = new ListNode(0);
        while (head != NULL)
        {
            head = head->next;
            headls->next = new ListNode(0);
        }
        dls(head, headls);
        return headls;
    }
};

//��ָ Offer 24 2023 6 10
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (!head) return NULL;
//        vector<int> v;
//        while (head)
//        {
//            v.push_back(head->val);
//            head = head->next;
//        }
//        ListNode* lsgead = new ListNode(0);
//        ListNode* lsc = lsgead;
//        for (int i = v.size() - 1; i >= 0; i--)
//        {
//            lsgead->val = v[i];
//            if (i) lsgead->next = new ListNode(0);
//            lsgead = lsgead->next;
//        }
//        return lsc;
//    }
//};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* he1 = head, * he2 = head->next;
        he1->next = NULL;
        while (he2 == NULL)
        {
            ListNode* he3 = he2->next;
            he2->next = he1;
            he1 = he2;
            he2 = he3;
        }
        return he1;
    }
};
void ListNodepush(int i, ListNode * a)
{
    while (a->next != NULL)
    {
        a = a->next;
    }
    ListNode* ls = new ListNode(i);
    a->next = ls;
}

//��ָ Offer 30 2023 6 10
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() {

    }

    void push(int x) {
        s1.push(x);
        if (s2.empty())
        {
            s2.push(x);
        }
        else
        {
            if (x <= s2.top()) s2.push(x);
        }
    }

    void pop() {
        if (s2.top() == s1.top()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution111 {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> v;
        Node* headls0 = head;
        while (headls0 != NULL)
        {
            v.push_back(headls0);
            headls0 = headls0->next;
        }

        Node* headls = new Node(head->val);
        Node* headlsbs = headls;
        Node* hls = headls, * hels = head;
        while (hels->next != NULL)//������ͬ��С������
        {
            hels = hels->next;
            hls->next = new Node(head->val);
            hls = hls->next;
        }

        Node* ls3 = head;
        hls = headls;
        hels = head;
        while (hels != NULL)//�޸����������ָ��
        {
            hls->random = hels;
            ls3 = hels->next;
            hels->next = hls;

            hels = ls3;
            hls = hls->next;
        }

        ls3 = head;
        while (headls != NULL)//�޸����������random
        {
            if (headls->random->random == NULL) headls->random = NULL;
            else headls->random = headls->random->random->next;
            headls = headls->next;
        }
        int i = 0;
        while (i < v.size() - 1)
        {
            v[i]->next = v[i + 1];
            i++;
        }
        return headlsbs;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* node = head;
        while (node != NULL)//���������������ԭ��������һ��
        {
            Node* head01 = new Node(node->val);
            head01->next = node->next;
            node->next = head01;
            node = head01->next;
        }

        node = head;
        while (node != NULL)//��ֵ�������random
        {
            if (node->random != NULL) node->next->random = node->random->next;
            node = node->next->next;
        }

        node = head->next;
        Node* node1 = head, * node2 = head->next;
        while (node2->next != NULL)
        {
            node1->next = node1->next->next;
            node2->next = node2->next->next;

            node1 = node1->next;
            node2 = node2->next;
        }
        node1->next = NULL;
        return node;
    }
};

void test01()
{
    MinStack m;
    m.push(10);
    m.push(6);
    m.push(8);
    m.push(12);
    m.push(11);

    cout << m.min() << endl;
    m.pop();
    m.pop();
    cout << m.min() << endl;
    m.pop();
    m.pop();
    cout << m.min() << endl;


    //ListNode* ls = new ListNode(1);
    //ListNodepush(2, ls);
    //ListNodepush(3, ls);
    //ListNodepush(4, ls);
    //ListNodepush(5, ls);

    //Solution sls;
    //ListNode* ls01 = sls.reverseList(ls);

    //while (ls01 != NULL)
    //{
    //    cout << ls01->val << " ";
    //    ls01 = ls01->next;
    //}



    //Solution01 sols;
    //cout << sols.isNumber("-1E-16") << endl;
    //vector<int> bv;
    //bv.push_back(1);
    //Solution s;
    //cout << s.isNumber("7.e-.") << endl;
    //CQueue c;
    //c.appendTail(3);
    //c.deleteHead();
    //c.deleteHead();
    //c.deleteHead();



	//vector<int> bv;
	//bv.push_back(1);


	return;
}
void testcs()
{
    int i = 0;
    if (i >= 0&&i<10)
    {
        cout << "true" << endl;
    }
}
int main()
{
	test01();
    //testcs();
	return 0;
}