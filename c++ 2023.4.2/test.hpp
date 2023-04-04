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
	~my_string()
	{
		delete[] this->str;
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

	int my_find(const my_string* str, int pos = 0)
	{
		char* n1 = this->str, * n2 = n1;
		char* m1 = str->str, * m2 = m1;
		int a = pos;
		int b = 0;
		if(pos < this->kj)
		while (a < this->kj)
		{
			if (n1[a] == m1[b])
			{
				int i = a;
				int j = 0;
				while (j < str->kj && i < this->kj)
				{
					if (n2[i] == m2[j])
					{
						i++;
						j++;
					}
					else
					{
						break;
					}
				}
				if (j == str->kj||i == this->kj)
				{
					return 0;
				}
				else
				{
					n2 = n1;
					m2 = m1;
				}
			}
			a++;
		}
		return -1;
	}

	int my_comare(const my_string& a)//�ַ����Ƚ�
	{
		int i = 0;
		int as = 0;
		int ac = 0;
		while (i < this->kj||i < a.kj)//�Ƚ�ASCllֵ
		{
			if(i<this->kj)
			as += this->str[i];
			if(i<a.kj)
			ac += a.str[i];
			i++;
		}
		return as - ac;
	}

	char& operator[](int n)//��ȡn�±���ַ�
	{
		return this->str[n];
	}

	my_string& my_insert(int pos, const char* s)//��posλ�ò���s�ַ���
	{
		int i = 0;
		while (s[i]!='\0')//��ȡs�ַ�����С
		{
			i++;
		}
		if (i == 0 || pos > this->kj)
		{
			return *this;
		}

		char* a = new char[this->kj + i];
		int n1 = 0;//���뵱ǰд����λ��

		int as = 0;//����str��ǰд����λ��
		while (n1 < pos)//д��posǰ����
		{
			a[n1++] = this->str[as++];
		}

		int k = 0;//ģ��s�ַ������±�λ��
		while (k < i)////д��pos������
		{
			a[n1++] = s[k++];
		}

		while (n1 < (this->kj+i))//д��ʣ������
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + i;
		return *this;
	}
	my_string& my_insert(int pos, const my_string& s)//��posλ�ò���s��str
	{
		int i = s.kj;//��ȡs�ַ�����С

		if (i == 0 || pos > this->kj)
		{
			return *this;
		}

		char* a = new char[this->kj + i];
		int n1 = 0;//���뵱ǰд����λ��

		int as = 0;//����str��ǰд����λ��
		while (n1 < pos)//д��posǰ����
		{
			a[n1++] = this->str[as++];
		}

		int k = 0;//ģ��s�ַ������±�λ��
		while (k < i)////д��pos������
		{
			a[n1++] = s.str[k++];
		}

		while (n1 < (this->kj + i))//д��ʣ������
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + i;
		return *this;
	}
	my_string& my_insert(int pos, int n, char c)
	{
		char* a = new char[this->kj + n];

		int n1 = 0;//���뵱ǰд����λ��
		int as = 0;//����str��ǰд����λ��
		while (n1 < pos)//д��posǰ����
		{
			a[n1++] = this->str[as++];
		}
		int ns = n;
		while (n--)
		{
			a[n1++] = c;
		}

		while (n1 < (this->kj + ns))//д��ʣ������
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + ns;
		return *this;
	}
	my_string& my_erase(int pos, int n = 0) //ɾ����Pos��ʼ��n���ַ�
	{
		char* a = new char[this->kj - n];
		int cs = this->kj - n;
		int poscs = 0;

		for (int i = 0; i < cs; i++)
		{
			if (i == pos)
			{
				poscs += n;
			}
			a[i] = this->str[poscs++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj -n;
		return *this;
	}
	my_string my_substr(int pos = 0, int n = 1)//������pos��ʼ��n���ַ���ɵ��ַ���
	{
		char* a = new char[n - pos+1];
		int i = pos;
		int j = 0;
		while (i < n)
		{
			a[j++] = this->str[i++];
		}
		a[j] = '\0';
		my_string cs(a);
		delete[] a;
		return cs;
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