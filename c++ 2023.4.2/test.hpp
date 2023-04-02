#define _CRT_SECURE_NO_WARNINGS 1

class my_string
{
	friend ostream& operator<< (ostream& couts, const my_string& str);
private:
	char* str;
	int kj;
public:

	my_string()//����һ���յ��ַ���
	{
		str = NULL;
		kj = 0;
	}
	my_string(const char* a)//ʹ���ַ�����ʼ��
	{
		int i = 0;
		while (a[i] != '\0')
		{
			i++;
		}
		this->kj = i;
		this->str = new char[i];
		for (int j = 0; j < i; j++)
		{
			str[j] = a[j];
		}
	}
	my_string(const my_string &a)//ʹ��my_string��ʼ��my_string����������
	{
		if (a.str != NULL)
		{
			this->kj = a.kj;
			this->str = new char[a.kj];
			for (int i = 0; i < a.kj; i++)
			{
				this->str[i] = a.str[i];
			}
		}
		else
		{
			str = NULL;
			kj = 0;
		}
	}
	void operator=(const char* a)//����= char*�ַ�����ֵ�ַ���
	{
		if (a != NULL)
		{
			delete[] str;
			int i = 0;
			while (a[i] != '\0')
			{
				i++;
			}
			this->kj = i;
			this->str = new char[i];
		}
	}
	void operator=(const char a)//����= char�ַ���ֵ���ַ�
	{
		if (a != NULL)
		{
			delete[] str;
			this->kj = 1;
			this->str = new char[1];
			this->str[0] = a;
		}
	}
	void operator+=(const char* a)//����+= char*�ַ���������
	{
		int i = 0;
		int j = 0;
		char* s = new char[this->kj + i];
		if (this->kj != 0)//��������s
		{
			for (j = 0; j < this->kj; j++)
			{
				s[j] = this->str[j];
			}
		}
		while (a[i] != '\0')//β������ַ���
		{
			s[j + i] = a[i];
			i++;
		}
		//�ͷ�ԭ�ڴ沢����ָ��ָ��
		delete[] this->str;
		this->str = s;
		this->kj += i;
	}
	void operator+=(const char a)//����+= char�ַ�������
	{
		int j = 0;
		char* s = new char[this->kj + 1];
		if (this->kj != 0)//��������s
		{
			for (j = 0; j < this->kj; j++)
			{
				s[j] = this->str[j];
			}
		}
		s[j] = a;
		//�ͷ�ԭ�ڴ沢����ָ��ָ��
		delete[] this->str;
		this->str = s;
		this->kj++;
	}
	my_string& operator+=(const my_string &a)//����+= my_string�ַ�������
	{
		int i = 0;
		char* s = new char[this->kj + a.kj];
		for (i = 0; i < this->kj; i++)//��������s
		{
			s[i] = this->str[i];
		}
		for (int j = 0; j < a.kj; j++)//β�������ݽ�s
		{
			s[i++] = a.str[j];
		}
		//�ͷ�ԭ�ڴ沢����ָ��ָ��
		delete[] this->str;
		this->str = s;
		this->kj += a.kj;
		return *this;//��������
	}

	my_string& append(const my_string& s, int pos, int n)//β��s�ӵ�pos�ַ�����n��������
	{
		if ((s.kj-(pos-1)) < n)//�ж�n�Ƿ����pos��s�����ܸ���
		{
			n = (s.kj - pos);
		}

		char* ts = new char[this->kj + n];
		int cs = this->kj;
		int i = n;
		if (this->kj != 0)//��������ts
		{
			for (int j = 0; j < this->kj; j++)
			{
				ts[j] = this->str[j];
			}
		}
		while (n--)//����̶�����
		{
			ts[cs++] = s.str[pos++];
		}
		//�ͷ�ԭ�ڴ沢����ָ��ָ��
		delete[] this->str;
		this->str = ts;
		this->kj += i;
		return *this;;//��������
	}
};
ostream& operator<< (ostream& couts, const my_string& str)
{
	for (int i = 0; i < str.kj; i++)
	{
		couts << str.str[i];
	}
	return couts;
}