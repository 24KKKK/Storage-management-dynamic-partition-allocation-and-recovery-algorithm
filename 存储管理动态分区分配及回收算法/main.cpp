#include<iostream>
#include<string>
using namespace std;
typedef struct node
{
	int adr = 0;//�����׵�ַ
	int size = 0;//������С
	node *next = NULL;//ָ����һ��������ָ��
}node;
void  initlist(node* &L)//��һ���ڵ�Ϊ��
{
	L = new node;
	L->next = NULL;
}
void listadd(node* &head, node* Point)//����Ŀ�������ӵ�������
{
	Point->next = head->next;
	head->next = Point;
}
void freedel(node* &headl, int wz)
{
	node* s;//�������������е�ָ��
	s = headl;
	for (int i = 0; i < wz; i++)//�ҵ�����λ�õ�ǰһ��������
	{
		s = s->next;
	}

	s->next = s->next->next;//ɾ��s����һ���ڵ�
}
void outlist(node* &head)//�������
{
	node* s;
	s = head->next;
	int i = 0;
	while (s != NULL)
	{
		cout << "��ţ�" << i << "      �׵�ַ��" << s->adr << "      ��ַ��" << s->adr + s->size - 1 << "      ��С" << s->size << endl;
		s = s->next;
		i++;
	}
}
void fenqv(node* &s, node nod)//����
{
	node* ns = new node;//�½�����
	ns->adr = s->adr + nod.size;//�·����ĵ�ַ��ֵ
	ns->size = s->size - nod.size;//�·����Ĵ�С��ֵ
	ns->next = s->next;//�·�����next��ֵ
	s->size = nod.size;
	s->next = ns;//s����nextΪ�·���
}
bool findfree(node* &headl, node* &assign, node nod) //backl�ҵ����ʵĿ�����������ȥ������
{
	int length = 0, wz = 0;//��¼�����ȣ����ʿ�������λ��
	bool b = false;
	node* s;//�������������е�ָ��
	node* assignPoint;//����Ŀ�����

	//��ʼ��
	s = headl->next;
	assignPoint = NULL;
	//�ж��Ƿ���ں��ʵĿ�����
	while (s != NULL)
	{

		if (s->size >= nod.size)
		{
			wz = length;
			assignPoint = s;//��ȡ���������
			b = true;
			break;
		}
		s = s->next;
		length++;//headl����һ��Ϊ0��
	}
	if (b == false)
	{
		return b;
	}
	//�жϿ������Ƿ��и���
	if (assignPoint->size > nod.size)
	{
		//���з���
		fenqv(assignPoint, nod);
	}
	//���ֺõĿ�����ǰ���֣���û�з�����ѡ�õĿ�������ָ�������� ���ӿ��ж���ɾ��

	freedel(headl, wz);
	listadd(assign, assignPoint);
	return b;
}
void adrmin(node* &head)//Ѱ��head�ڵ� ֮�� �ĵ�ַ��Сֵ������head��next(������head�ڵ�)
{
	node* min;//��Сֵ��ָ��
	node* s;//����ָ��
	min = head->next;
	s = head->next;
	int wz = 0, length = 0;//λ�ã�����
	//
	while (s != NULL)
	{
		if (s->adr < min->adr)//����������ĵ�ַС��min�ĵ�ַ��min��ֵ
		{
			min = s;
			wz = length;//head->next��λ��Ϊ0��
		}
		length++;
		s = s->next;
	}
	s = head;
	//�Ӷ�����ɾ����Сֵ,�ҵ���Сֵ��ǰһ��
	for (int i = 0; i < wz; i++)
	{
		s = s->next;
	}
	s->next = s->next->next;

	//����Сֵ�����ͷ
	min->next = head->next;
	head->next = min;

}
void sizemin(node* &head)//Ѱ��head�ڵ� ֮�� �ĵ�ַ��Сֵ������head��next(������head�ڵ�)
{
	node* min;//��Сֵ��ָ��
	node* s;//����ָ��
	min = head->next;
	s = head->next;
	int wz = 0, length = 0;//λ�ã�����
	//
	while (s != NULL)
	{
		if (s->size < min->size)//����������ĵ�ַС��min�ĵ�ַ��min��ֵ
		{
			min = s;
			wz = length;//head->next��λ��Ϊ0��
		}
		length++;
		s = s->next;
	}
	s = head;
	//�Ӷ�����ɾ����Сֵ,�ҵ���Сֵ��ǰһ��
	for (int i = 0; i < wz; i++)
	{
		s = s->next;
	}
	s->next = s->next->next;

	//����Сֵ�����ͷ
	min->next = head->next;
	head->next = min;


}
void adrPaiXu(node* &headl)//��������ַ����
{
	node* s;//�������������е�ָ��,��������
	s = headl;
	while (s->next)
	{
		adrmin(s);
		s = s->next;//s�ƶ����ҵ��Ľڵ���
	}
}
void sizePaiXu(node* &headl)//��������С����
{
	node* s;//�������������е�ָ��,��������
	s = headl;
	while (s->next)
	{
		sizemin(s);
		s = s->next;//s�ƶ����ҵ��Ľڵ���
	}
}

//***************************************************************************************
//�ͷ�
//�ҵ�s��ǰһ���ڵ㣬��ֵ��s
int findbef(node* &head, node* &point)
{
	int length = 0, wz = 0;//��¼�����ȣ����ʿ�������λ��
	node* s = head->next;//�������������е�ָ��
	while (s != NULL)
	{

		if (s->adr == point->adr)
		{
			wz = length;
		}
		s = s->next;
		length++;//headl����һ��Ϊ0��
	}
	s = head;
	for (int i = 0; i < wz; i++)//�ҵ�����λ�õ�ǰһ��������
	{
		s = s->next;
	}
	point = s;
	return wz;
}
bool check(node* assign, node nod)//���ָ���ͷſ�ĺϷ��� 
{
	node *s = assign->next;//s��ʼ��Ϊ�������Ķ�ͷ��һ��

	while (s != NULL)
	{
		if (s->adr == nod.adr)
		{
			if (s->size >= nod.size)
			{
				return true;
			}
		}
		s = s->next;
	}
	return false;
}

//�ж�ǰһ�����Ƿ�Ϊ��
bool befnull(node* &headl, node* &backl)
{
	node* s = headl->next;
	bool panbef = true;
	while (s != NULL)
	{
		if (s->adr + s->size == backl->adr)
		{
			panbef = false;//ǰһ��Ϊ����״̬
			break;
		}
		s = s->next;
	}
	if (panbef == false)//ǰһ�����У����кϲ�
	{
		backl->adr = s->adr;
		backl->size += s->size;
		freedel(headl, findbef(headl, s));
	}
	return panbef;
}

//�жϺ�һ�������Ƿ�Ϊ��
bool aftnull(node* &headl, node* &backl)
{
	node* s = headl->next;
	bool panbef = true;
	while (s != NULL)
	{
		if (s->adr == backl->adr + backl->size)
		{
			panbef = false;//ǰһ��Ϊ����״̬
			break;
		}
		s = s->next;
	}
	if (panbef == false)//ǰһ�����У����кϲ�
	{
		backl->size += s->size;
		freedel(headl, findbef(headl, s));
	}
	return panbef;
}
//���������ҵ���Ӧ�����򣬲�����
bool findback(node* &backl, node* &assign, node nod)
{
	if (check(assign, nod) == false)
	{
		cout << "�����ͷ�����ַ���С����" << endl;
		return false;
	}
	node* s = assign->next;//s��ʼ��Ϊ�������Ķ�ͷ��һ��
	int length = 0, wz = 0;//�Ӷ�ͷ��һ��Ϊ0

	//�ҵ��ͷŵ�λ��
	while (s != NULL)
	{
		if (s->adr == nod.adr)
		{
			break;
		}
		s = s->next;
		wz++;
	}

	//������տռ�С��ʹ�ÿռ��򣬽��з�����
	//��ǰ�벿�ͷţ���������ɾ�����ж�ǰ�����Ƿ���У����кϲ���
	if (s->size > nod.size)
	{
		fenqv(s, nod);
		backl = s;//��ֵ���ͷ�ָ��
		freedel(assign, wz);
	}
	else if (s->size = nod.size)
	{
		backl = s;//��ֵ���ͷ�ָ��
		freedel(assign, wz);
	}
	else
	{
		return  false;
	}
	return true;
}
void assignment1(node* &headl, node* &assign, node nod)//ʵ��First Fit Algorithm 
{
	adrPaiXu(headl);
	if (findfree(headl, assign, nod) == false)
	{
		cout << "û���㹻�Ŀռ�" << endl;
	}
	else
	{
		adrPaiXu(headl);
		cout << "*************************************������********************************************" << endl;
		outlist(headl);

		adrPaiXu(assign);
		cout << "*************************************������********************************************" << endl;
		outlist(assign);
	}

}
void assignment2(node* &headl, node* &assign, node nod)//ʵ��Best Fit Algorithm  
{
	sizePaiXu(headl);
	if (findfree(headl, assign, nod) == false)
	{
		cout << "û���㹻�Ŀռ�";
	}
	else
	{
		sizePaiXu(headl);
		cout << "*************************************������********************************************" << endl;
		outlist(headl);

		sizePaiXu(assign);
		cout << "*************************************������********************************************" << endl;
		outlist(assign);
	}

}
void acceptment1(node* &headl, node* &backl, node* &assign, node nod)//ʵ��First Fit Algorithm �Ļ����㷨
{
	//adrPaiXu(headl);
	//��assign�ҵ���Ӧλ�ã�
	//��������������
	//�����ͷ���������������ɾ��
	if (findback(backl, assign, nod) == true)
	{
		//���ͷ���������ж���
		listadd(headl, backl);
		//�жϺ�����Ƿ���У�(��������Ŀռ�ӵ��ͷ����ϣ����Ѻ����ɾ��)
		//���кϲ�
		aftnull(headl, backl);
		//�ж�ǰ�����Ƿ���У�����
		//���кϲ���
		befnull(headl, backl);
		//��������
		adrPaiXu(headl);
		cout << "*************************************������********************************************" << endl;
		outlist(headl);

		adrPaiXu(assign);
		cout << "*************************************������********************************************" << endl;
		outlist(assign);
	};

}
void acceptment2(node* &headl, node* &backl, node* &assign, node nod)//ʵ��Best Fit Algorithm �Ļ����㷨
{
	//sizePaiXu(headl);
	//��assign�ҵ���Ӧλ�ã�
	//��������������
	//�����ͷ���������������ɾ��
	if (findback(backl, assign, nod) == true)
	{
		//���ͷ���������ж���
		listadd(headl, backl);


		//�жϺ�����Ƿ���У�(��������Ŀռ�ӵ��ͷ����ϣ����Ѻ����ɾ��)
		//���кϲ�
		aftnull(headl, backl);

		//�ж�ǰ�����Ƿ���У�����
		//���кϲ���
		befnull(headl, backl);

		//��������
		sizePaiXu(headl);
		cout << "*************************************������********************************************" << endl;
		outlist(headl);

		sizePaiXu(assign);
		cout << "*************************************������********************************************" << endl;
		outlist(assign);
	};

}
void main()
{
	node* headl;//������������ָ�� 
	node* backl; //ָ���ͷ���node�ṹ��ָ��
	node* assign;//ָ��������ڴ����node�ṹ��ָ��
	int free = 0;//�������Ĵ�С
	int acsize = 0;//�ͷ����Ĵ�С
	int acadr = 0;//�ͷ������׵�ַ
	//ָ���ʼ��
	initlist(headl);
	initlist(backl);
	initlist(assign);

	//���ж��и���ֵ
	node* n = new node;
	n->adr = 0;
	n->size = 32767;
	n->next = NULL;
	headl->next = n;
	node nod;
	//ѭ������
	int xz, xz2;
	while (true)
	{
		//������ֵ
		cout << "ѡ���㷨���������֣���1.������Ӧ�㷨  2.�����Ӧ�㷨  3.�˳�" << endl;
		cin >> xz;
		if (xz == 3)
		{
			break;
		}
		if (xz != 1 && xz != 2 && xz != 3)
		{
			cout << "�������" << endl;
			continue;
		}
		cout << "ѡ��������������֣���1.���� 2����" << endl;
		cin >> xz2;

		if (xz2 != 1 && xz2 != 2)
		{
			cout << "�������" << endl;
			continue;
		}

		if (xz2 == 1)
		{
			cout << "������������С" << endl;
			cin >> free;
			nod.adr = 0;
			nod.size = free;
		}
		else if (xz2 == 2)
		{
			cout << "�����ͷ����׵�ַ�ʹ�С" << endl;
			cin >> acadr >> acsize;
			nod.adr = acadr;
			nod.size = acsize;
		}
		else
		{
			cout << "�������" << endl;
			continue;
		}
		//��������
		if (xz == 1)
		{
			if (xz2 == 1)
			{
				assignment1(headl, assign, nod);
			}
			else
			{
				acceptment1(headl, backl, assign, nod);
			}
		}
		else if (xz == 2)
		{
			if (xz2 == 1)
			{
				assignment2(headl, assign, nod);
			}
			else
			{
				acceptment2(headl, backl, assign, nod);
			}
		}
		else if (xz == 3)
		{
			break;
		}
		else
		{
			cout << "�������" << endl;
		}

	}
}