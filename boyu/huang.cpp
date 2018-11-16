/**
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm> 
using namespace std;*/

/********小于某数的自守数的个数****
#include<iostream>
using namespace std;
int getNumber(int n)
{
	int x = 10;
	while (n/x)
	{
		x *= 10;
	}
	return x;
}
int CalcAutomorphicNumbers(int n)
{
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if (i*(i - 1) % getNumber(i) == 0)
		{
			x++;
		}
	}
	return x;
}
void main()
{
	int i;
	cin>>i;
	cout << CalcAutomorphicNumbers(i) << endl;
}
*/
/*
void main()
{
	ofstream input("huang.txt");
	string str("huang");
	input << str;
	cout<<str;
}
*/
/***********求int数在内存中1的个数****************
int numberof1(int i)
{
	int sum = 0;
	while (i)
	{
		sum++;
		i &= (i - 1);
	}
	return sum;
}
void main()
{
	int i;
	cin >> i;
	cout << numberof1(i) << endl;
}
*/
/*************句子逆序*************
void rverseword(char *begin, char *end)
{
	while (begin < end - 1)
	{
		char temp = *begin;
		*begin = *(end - 1);
		*(end - 1) = temp;
		begin++;
		end--;
	}
}
void reverse(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		char c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
	}
	char *strbuf=s;
	while (*s != '\0')
	{
		s++;
		if (*s == ' ' || *s == '\0')
		{
			rverseword(strbuf, s);
			if (*s == ' ')
			{
				s++;
				strbuf = s;
			}
		}
	}
}
void main()
{
	char str[100] = "wo shi huang";
	reverse(str);
	cout << str << endl;
}
*/
/*****************字符串反转*****************************
void reverse(string &str)
{
	string::iterator iter1;
	string::iterator iter2;
	if (str.size() == 0)
		return;
	for (iter1 = str.begin(), iter2 = str.end()-1; iter1 < iter2; ++iter1, --iter2)
	{
		char temp = *iter1;
		*iter1 = *iter2;
		*iter2 = temp;
	}
}
void main()
{
	string str;
	getline(cin, str);
	reverse(str);
	cout << str << endl;
}
*/
/*数字颠倒***************************************
void reverse(int i, string &str)
{
	char c;
	str.clear();
	while (i)
	{
		c = i % 10+'0';
		str.push_back(c);
		i /= 10;
	}
}
void main()
{
	int i;
	string str;
	cin >> i;
	reverse(i, str);
	cout << str << endl;

}*/
/**********字符串中字符种类统计******************************
void main()
{
	int buf[128] = {0};
	string str;
	int sum = 0;
	getline(cin, str);
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		buf[*iter] = 1;
	}
	for (int i = 0; i < 128; i++)
	{
		if (buf[i])
		{
			sum++;
		}
	}
	cout << sum << endl;
}
*/
/************提取不重复整数*******************************
void main()
{
	int i,j;
	int flag[10] = { 0 };
	string str;
	char c;
	cin >> i;
	if (i == 0)
	{
		cout << i << endl;
		return;
	}
	while (i)
	{
		j = i % 10;
		if (flag[j] == 0&&(j!=0||str.size()!=0))
		{
			str.push_back(j + '0');
			
		}
		flag[j] = 1;
		i /= 10;
	}
	cout << str << endl;
}
*/
/*****合并表记录*************************
#include<algorithm>
struct Record
{
	int index;
	int value;
};
bool cmp(const struct Record a, const struct Record b)
{
	return a.index < b.index;
}
void main()
{
	struct Record array[100];
	int N;
	int m, n;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> n;
		array[i].index = m;
		array[i].value = n;
	}
	sort(array, array + N, cmp);
	for (int i = 0; i < N; i++)
	{
		if (array[i].index == array[i + 1].index)
		{
			array[i + 1].value += array[i].value;
		}
		else
		{
			cout << array[i].index << endl;
			cout << array[i].value << endl;
		}
	}
}
*/
/***********求近似值*******************
void main()
{
	double d;
	int i;
	cin >> d;
	if (d >= 0)
		i = (int)(d + 0.5);
	else
		i = (int)(d - 0.5);
	cout << i << endl;
}
*/
/*
bool iszhishu(long i)
{
	long j;
	for (j = 2; j <= i; j++)
	{
		if (i%j == 0)
		{
			break;
		}
	}
	if (j == i)
		return true;
}
long fun(long &l, long i)
{
	while (l%i != 0)
	{
		do
		{
			i++;
		} while (!iszhishu(i));
	}
	l /= i;
	return i;
}
void main()
{
	vector<int> ivec;
	long l;
	long i=2;
	cin >> l;
	while (l != 1)
	{
		i = fun(l, i);
		ivec.push_back(i);
	}
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
}
*/

/**************
void getResult(long input)
{
	for (int i = 2; i <= input; i++)
	{
		while ((0 == input%i) && input != 0)
		{
			cout << i << " ";
			input = input / i;
		}
	}

}
int main()
{
	long a;
	cin >> a;
	getResult(a);
	return 0;
}
*/
/****质数因子******************
void getresult(long l)
{
	for (long i = 2; i <= l; i++)
	{
		while (l%i == 0 && l != 1)
		{
			cout << i << ' ';
			l /= i;
		}
	}
	cout << endl;
}
void main()
{
	long l;
	cin >> l;
	cout << l << endl;
	getresult(l);
}
*/
/**********进制转换******************************
void main()
{
	string str;
	cin >> str;
	int i=0;
	int j = 1;
	if (str[0] != '0' || str[1] != 'x')
	{
		cout << "输入有误" << endl;
		return;
	}
	for (string::iterator iter = str.end() - 1; iter != str.begin() + 1; --iter)
	{
		if ((*iter > 'G' || *iter<'A') && (*iter>'9' || *iter < '0'))
		{
			cout << "输入有误" << endl;
			return;
		}
		if (*iter >= 'A')
		{
			i += (*iter - 'A' + 10)*j;
		}
		else
		{
			i += (*iter - '0')*j;
		}
		j *= 16;
	}
	cout << i << endl;
}
*/
/********字符串分割******************************
void main()
{
	string str,str1,strbuf;
	vector<string> strvec;
	cin >> str >> str1;
	int i=0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		i++;
		strbuf.push_back(*iter);
		if (i >= 8)
		{
			i = 0;
			strvec.push_back(strbuf);
			strbuf.clear();
		}
	}
	if (strbuf.size() < 8)
	{
		int k = strbuf.size();
		for (int j = 0; j < (8 - k); j++)
		{
			strbuf.push_back('0');
		}
		strvec.push_back(strbuf);
		strbuf.clear();
	}
	i = 0;
	for (string::iterator iter = str1.begin(); iter != str1.end(); ++iter)
	{
		i++;
		strbuf.push_back(*iter);
		if (i >= 8)
		{
			i = 0;
			strvec.push_back(strbuf);
			strbuf.clear();
		}
	}
	if (strbuf.size() < 8)
	{
		int k = strbuf.size();
		for (int j = 0; j < (8 - k); j++)
		{
			strbuf.push_back('0');
		}
		strvec.push_back(strbuf);
		strbuf.clear();
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
*/
/************小明的随机数****************************
void main()
{
	int i,k;
	vector<int> ivec;
	cin >> i;
	for (int j = 0; j < i; j++)
	{
		cin >> k;
		ivec.push_back(k);
	}
	sort(ivec.begin(), ivec.end());
	vector<int>::iterator iter = unique(ivec.begin(), ivec.end());
	ivec.erase(iter,ivec.end());
	for (vector<int>::iterator iter1 = ivec.begin(); iter1 != ivec.end(); ++iter1)
	{
		cout << *iter1 << endl;
	}
}
*/
/***********字符串中字符个数*****************************
void main()
{
	string str;
	char c;
	getline(cin, str);
	cin >> c;
	int i = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter == c)
		{
			i++;
		}
	}
	cout << i << endl;
}
*/
/***********最小公倍数**************************************
void fun(int &a, int &b)
{
	if (a > b)
	{
		int i = a;
		a = b;
		b = i;
	}
}
void main()
{
	int a, b,i;
	long long l;
	cin >> a >> b;
	fun(a, b);
	for (i = 1; i <= a; i++)
	{
		l = (long long)i*b;   //强制类型转换不能丢了
		if (l%a == 0)
		{
			break;
		}
	}
	cout << l << endl;;
}
*/
/*******最大公约数******************
int gys(int a, int b)
{
	return (!b) ? (a) : (gys(b, a%b));
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << gys(a, b) << endl;
}
*/

/*求解立方根************************************
#define E 0.0001
double getCubeRoot(double num)
{
	double x0 = num;
	double result;
	while (1)
	{
		result = x0 - (x0*x0*x0 - num) / (3 * x0*x0);
		if (result*result*result - num<E &&result*result*result - num>-E)
			return result;
		else
			x0 = result;
	}
}
void main()
{
	double d;
	cin >> d;
	cout << getCubeRoot(d) << endl;
}
*/
/**********************
void main()
{
	string str;
	getline(cin, str);
	if (str.size() == 0)
	{
		return;
	}
	string::iterator iter0 = str.begin();
	string::iterator iter1 = str.end() - 1;
	for (; iter0 < iter1; ++iter0, --iter1)
	{
		char c = *iter0;
		*iter0 = *iter1;
		*iter1 = c;
	}
	cout << str << endl;
}
*/
/********最大公约数与最小公倍数**********************************
int gys(int a, int b)
{
	return (!b) ? (a) : (gys(b, a%b));
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << gys(a, b) << endl;                        //最大公约数
	cout << (long long)a / gys(a, b)*b << endl;       //最小公倍数
}
*/
/*****非递归求最大公约数**********************
int gys(int a, int b)
{
	while (b > 0)
	{
		int temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << gys(a, b) << endl;
}
*/
/********求数组最大和**********
int max(int a, int b)
{
	return (a >= b) ? a : b;
}
int getMax_sum(int *a, int n)
{
	int maxSum = 0;
	int curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum += a[i];
		if (curSum < 0)
			curSum = 0;
		maxSum = max(curSum, maxSum);
	}
	return maxSum;
}
void main()
{
	int a[7] = {4,2,-4,2,3,-4,9};
	cout << getMax_sum(a, 7) << endl;
}
*/

/*********************求数组最大积**************
int min(int a, int b)
{
	return (a < b) ? (a) : (b);
}
int max(int a, int b)
{
	return (a>b) ? (a) : (b);
}
int getMax_produce(int *a, int n)
{
	int maxProduce = 1;
	int minProduce = 1;
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>0)
		{
			maxProduce *= a[i];
			minProduce = min(minProduce*a[i], 1);
		}
		else if (a[i] == 0)
		{
			maxProduce = 1;
			minProduce = 1;
		}
		else
		{
			int temp = maxProduce;
			maxProduce = max(minProduce*a[i], 1);
			minProduce = temp*a[i];
		}
		r = max(maxProduce, r);
	}
	return r;
}
void main()
{
	int a[7] = { 1, 2, -2, 4, 5, 2, -1 };
	cout << getMax_produce(a, 7) << endl;
}
*/
/*************************************
struct Node;
typedef struct Node *pNode;
struct Node
{
	int data;
	pNode link;
};
typedef struct Node *LinkList;
typedef LinkList *pLinkList;
void main()
{
	int m, s, n;
	cin >> m >> s >> n;
	LinkList plist = (pNode)malloc(sizeof(struct Node));
	plist->data = 1;
	plist->link = plist;
	pNode p, q;
	p = plist;
	for (int i = 2; i <= m; i++)
	{
		q = (pNode)malloc(sizeof(struct Node));
		q->data = i;
		q->link = p->link;
		p->link = q;
		p = q;
	}
	p = plist;
	for (int i = 0; i < s - 1; i++)
	{
		p = p->link;
	}
	pNode pre;
	pre = p;
	while (pre->link != p)
	{
		pre = pre->link;
	}
	while (plist->link != plist)
	{
		for (int i = 0; i < m; i++)
		{
			pre = pre->link;
			p = pre->link;
		}
		if (p == plist)
		{
			plist = plist->link;
		}
		cout << p->data << endl;
		pre->link = p->link;
		free(p);
		p = pre->link;	
	}
	cout << p->data;
	free(p);
}
*/
/********计负均正***********************************
void main()
{
	vector<int> ivec;
	int a;
	while (cin >> a)
	{
		ivec.push_back(a);
	}
	int num = 0;
	double sum = 0.0;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		if (*iter < 0)
		{
			num++;
		}
		else
		{
			sum += *iter;
		}
	}
	cout << num << endl;
	cout << sum / (ivec.size() - num) << endl;
}
*/
/****不使用+、-、*、/求两个数的和*************************
int add(int a, int b)
{
	int x, y;
	if (b == 0)
	{
		return a;
	}
	x = a^b;
	y = (a&b) << 1;
	return add(x, y);
}
void main()
{
	int x, y;
	cin >> x>>y;
	cout << add(x, y) << endl;
}
*/
/********上例的非递归算法********************************
int add(int a, int b)
{
	while (b != 0)
	{
		int temp = a;
		a = a^b;
		b = (temp&b) << 1;
	}
	return a;
}
void main()
{
	int x, y;
	cin >> x >> y;
	cout << add(x, y) << endl;
}
*/
/********数组中只出现1次的两个数*****************************
#include<iostream>
using namespace std;
int firstdif(int i)
{
	int x = 1;
	while ((i & 1) == 0)
	{
		i >>= 1;
		x<<=1;
	}
	return x;
}
void findTwoNums(int *a, int n, int &one, int &two)
{
	int buf = 0;
	one = 0;
	two = 0;
	for (int i = 0; i < n; i++)
	{
		buf ^= a[i];
	}
	int diffNum = firstdif(buf);
	for (int i = 0; i < n; i++)
	{
		if (a[i] & diffNum)
		{
			one ^= a[i];
		}
		else
		{
			two ^= a[i];
		}
	}
}
int main()
{
	int a[10] = { 123, 345, 567, 5, 123, 567, 345, 7, 5, 4567 };
	int x = 0;
	int y = 0;
	findTwoNums(a, 10, x, y);
	cout << x << ' ' << y << endl;

	return 0;
}
*/

/******n!后面0的个数******************
#include<iostream>
using namespace std;
int numof0(int s)
{
	int n = 0;
	for (int i = 5; i <= s; i += 5)
	{
		n++;
		int k = i / 5;
		while (k % 5 == 0)
		{
			n++;
			k /= 5;
		}
	}
	return n;
}
int main()
{
	int s;
	while (cin >> s)
	{
		cout << numof0(s) << endl;
	}
	return 0;
}
*/
/************************************************
int numof1(int i)
{
	int num = 0;
	while (i != 0)
	{
		num++;
		i = i&(i - 1);
	}
	return num;
}
bool is2num(int i)
{
	return (i&(i - 1)) == 0;     //注意运算符的优先级
}
void main()
{
	int i;
	cin >> i;
	cout << numof1(i) << endl;
	cout << is2num(1024) << endl;
}
*/
/******************************************
#include <iostream>
#include <string>
#include <stack>
#include "stdlib.h"
using namespace std;
int pri(char m)
{
	switch (m)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
	case ')':
		return 0;
	case '#':
		return -1;
	default:
		break;
	}
}
int getResult(string s)
{
	stack<int>value;
	stack<char>fuhao;
	s = s + "#$";
	if (s[0] == '-')
		s = "0" + s;
	int i = 0;
	string c = "";
	while (s[i] != '$')
	{
		if (s[i] <= '9'&&s[i] >= '0')
		{
			c = c + s[i];
			i++;
			while (s[i] <= '9'&&s[i] >= '0')
			{
				c = c + s[i];
				i++;
			}
			i--;
			int m = atoi(c.c_str());
			value.push(m);
			c = "";
		}

		else if (fuhao.size() == 0 || s[i] == '(' || pri(s[i])>pri(fuhao.top()))
			fuhao.push(s[i]);
		else if (s[i] == ')')
		{
			for (; fuhao.top() != '('; fuhao.pop())
			{
				char d = fuhao.top();
				int a = value.top();
				value.pop();
				int b = value.top();
				value.pop();
				switch (d)
				{
				case '+':
				{a = a + b;
				break; }
				case '-':
				{a = b - a;
				break; }
				case '*':
				{a = a*b;
				break; }
				case '/':
				{a = b / a;
				break; }
				default:
					break;
				}
				value.push(a);
			}
			fuhao.pop();
		}
		else
		{
			for (; fuhao.size() != 0 && pri(s[i]) <= pri(fuhao.top()); fuhao.pop())
			{
				char d = fuhao.top();
				int a = value.top();
				value.pop();
				int b = value.top();
				value.pop();
				switch (d)
				{
				case '+':
				{a = a + b;
				break; }
				case '-':
				{a = b - a;
				break; }
				case '*':
				{a = a*b;
				break; }
				case '/':
				{a = b / a;
				break; }
				}
				value.push(a);
			}
			fuhao.push(s[i]);
		}
		i++;
	}
	return value.top();
}

bool calculating(string str)
{

	cout << getResult(str) << endl;
	return true;
}

int main(void)
{
	string a;
	cin >> a;
	if (calculating(a))
	{
		cout << "true" << endl;
	}
	return 0;
}
*/
/*****************************************
void main()
{
	string str1, str2;
	stack<char> cstack;
	stack<double> dstack;
	cin >> str1;
	for (string::iterator iter = str1.begin(); iter != str1.end(); ++iter)
	{
		if ((*iter) >= '0'&&(*iter) <= '9')
		{
			str2.push_back(*iter);
			if (!cstack.empty()&&(cstack.top() == '*' || cstack.top() == '/'))
			{
				str2.push_back(cstack.top());
				cstack.pop();
			}
		}
		else
		{
			cstack.push(*iter);
		}
		if (!cstack.empty() && cstack.top() == ')')
		{
			cstack.pop();
			while (cstack.top() != '(')
			{
				str2.push_back(cstack.top());
				cstack.pop();
			}
			cstack.pop();
			if (!cstack.empty() && (cstack.top() == '*' || cstack.top() == '/'))
			{
				str2.push_back(cstack.top());
				cstack.pop();
			}
		}
	}
	while (!cstack.empty())
	{
		str2.push_back(cstack.top());
		cstack.pop();
	}

	for (string::iterator iter = str2.begin(); iter != str2.end(); ++iter)
	{
		if (*iter >= '0'&&*iter <= '9')
		{
			dstack.push(*iter-'0');
		}
		else
		{
			double a = dstack.top();
			dstack.pop();
			double b = dstack.top();
			dstack.pop();
			double d;
			switch (*iter)
			{
			case '+':
				d = a + b;
				break;
			case '-':
				d = a - b;
				break;
			case '*':
				d = a*b;
				break;
			case '/':
				d = a / b;
				break;
			}
			dstack.push(d);
		}
	}
	cout << dstack.top()<< endl;
}
*/
/**********************************************************************
//=====定义二叉树================================
struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode
{
	int info;
	PBinTreeNode llink, rlink;
};
typedef struct BinTreeNode *BinTree;
typedef BinTree *PBinTree;
//====定义栈=================
struct SeqStack
{
	int MAXNUM;
	int t;
	BinTree *c;
};
typedef struct SeqStack *Stack;
//======创建空栈======================
Stack createEmptyStack()
{
	Stack s = (Stack)malloc(sizeof(struct SeqStack));
	if (s)
	{
		s->c = (BinTree*)malloc(sizeof(BinTree)* 100);
		if (s->c)
		{
			s->MAXNUM = 100;
			s->t = -1;
			return s;
		}
		else
		{
			free(s);
		}
	}
	printf("out of space!\n");
	return NULL;
}
//=======销毁栈=============
void destroyStack(Stack s)
{
	if (s != NULL)
	{
		free(s->c);
		free(s);
	}
}
//====判断栈是否为空=======
int isEmptyStack(Stack s)
{
	return s->t == -1;
}
//============入栈==============
void push(Stack s, BinTree x)
{
	if ((s->t + 1) == s->MAXNUM)
	{
		printf("Full Stack!\n");
	}
	else
	{
		s->t++;
		s->c[s->t] = x;
	}
}
//=======出栈===========================
void pop(Stack s)
{
	if (isEmptyStack(s))
	{
		printf("Empty Stack!\n");
	}
	else
	{
		s->t--;
	}
}
//====取栈顶元素=============================
BinTree top(Stack s)
{
	if (isEmptyStack(s))
	{
		printf("Empty Stack!\n");
	}
	else
	{
		return s->c[s->t];
	}
}
//====定义队列==============
struct SeqQueue
{
	int MAXMUN;
	int f,r;
	BinTree *q;
};
typedef struct SeqQueue *Queue;
//====创建空队列==========================
Queue createEmptyQueue()
{
	Queue paqu = (Queue)malloc(sizeof(struct SeqQueue));
	if (paqu)
	{
		paqu->q = (BinTree*)malloc(sizeof(BinTree)* 100);
		if (paqu->q)
		{
			paqu->MAXMUN = 100;
			paqu->f = 0;
			paqu->r = 0;
			return paqu;
		}
		else
		{
			free(paqu);
		}
	}
	printf("out of space!\n");
	return NULL;
}
//====销毁队列======================
void destroyQueue(Queue paqu)
{
	if (paqu != NULL)
	{
		free(paqu->q);
		free(paqu);
	}
}
//======判断队列是否为空====================
int isEmptyQueue(Queue paqu)
{
	return paqu->f == paqu->r;
}
//============入队============================
void enQueue(Queue paqu, BinTree t)
{
	if ((paqu->r + 1) % (paqu->MAXMUN) == paqu->f)
	{
		printf("Full Queue!\n");
	}
	else
	{
		paqu->q[paqu->r] = t;
		paqu->r = (paqu->r + 1) % paqu->MAXMUN;
	}
}
//=======出队=====================================
void deQueue(Queue paqu)
{
	if (isEmptyQueue(paqu))
	{
		printf("Empty Queue!\n");
	}
	else
	{
		paqu->f = (paqu->f + 1) % paqu->MAXMUN;
	}
}
//=====取队首元素========================================
BinTree frontQueue(Queue paqu)
{
	if (isEmptyQueue(paqu))
	{
		printf("empty queue!\n");
	}
	else
	{
		return paqu->q[paqu->f];
	}
}
//==========创建二叉树======================
void createBinTree(PBinTree pt)
{
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		*pt = NULL;
	}
	else
	{
		*pt = (BinTree)malloc(sizeof(struct BinTreeNode));
		(*pt)->info = tmp;
		createBinTree(&(*pt)->llink);
		createBinTree(&(*pt)->rlink);
	}
}
//======销毁二叉树===========
void destroyBinTree(BinTree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		destroyBinTree(t->llink);
		destroyBinTree(t->rlink);
		free(t);
	}
}
//====先根次序周游的递归算法======================
void preOrder(BinTree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->info << endl;
		preOrder(t->llink);
		preOrder(t->rlink);
	}
}
//======先根次序周游的非递归算法===============
void nPreOrder(BinTree t)
{
	Stack s = NULL;
	BinTree c = t;
	if (t == NULL)
	{
		return;
	}
	s = createEmptyStack();
	push(s, c);
	while (!isEmptyStack(s))
	{
		c = top(s);
		pop(s);
		if (c != NULL)
		{
			cout << c->info << endl;
			push(s, c->rlink);
			push(s, c->llink);
		}
	}
	destroyStack(s);
}
//====对称序列周游递归算法===============================
void inOrder(BinTree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		inOrder(t->llink);
		cout << t->info << endl;
		inOrder(t->rlink);
	}
}
//====对称序列周游非递归算法===============
void nInOrder(BinTree t)
{
	Stack s = NULL;
	BinTree c = t;
	if (t == NULL)
	{
		return;
	}
	s = createEmptyStack();
	do
	{
		while (c != NULL)
		{
			push(s, c);
			c = c->llink;
		}
		c = top(s);
		pop(s);
		cout << c->info << endl;
		c = c->rlink;
	} while (!isEmptyStack(s)|| c != NULL);
	destroyStack(s);
}
//===后根次序周游递归算法===========================
void postOrder(BinTree t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		postOrder(t->llink);
		postOrder(t->rlink);
		cout << t->info << endl;
	}
}
//=====后跟次序周游非递归算法===========================
void nPostOrder(BinTree t)
{
	Stack s = NULL;
	BinTree p = t;
	BinTree pr;
	if (t == NULL)
	{
		return;
	}
	s = createEmptyStack();
	while (!isEmptyStack(s) || p != NULL)
	{
		while (p != NULL)
		{
			push(s, p);
			pr = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pr;
			}
		}
		p = top(s);
		pop(s);
		cout << p->info << endl;
		if (!isEmptyStack(s)&&top(s)->llink == p)
		{
			p = top(s)->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	destroyStack(s);
}
//===二叉树的广度优先周游==================================
void guangduOrder(BinTree t)
{
	Queue q = createEmptyQueue();
	BinTree c = t;
	BinTree cc;
	if (t == NULL)
	{
		return;
	}
	enQueue(q, c);
	while (!isEmptyQueue(q))
	{
		c = frontQueue(q);
		deQueue(q);
		printf("%d\n", c->info);
		cc = c->llink;
		if (cc != NULL)
		{
			enQueue(q, cc);
		}
		cc = c->rlink;
		if (cc != NULL)
		{
			enQueue(q, cc);
		}
	}
}
void main()
{
	BinTree bt;
	createBinTree(&bt);
	cout << "广度优先周游:" << endl;
	guangduOrder(bt);
	cout << "先根序列周游递归：" << endl;
	preOrder(bt);
	cout << "先根序列周游非递归：" << endl;
	nPreOrder(bt);
	cout << "对称序列周游递归：" << endl;
	inOrder(bt);
	cout << "对称序列周游非递归：" << endl;
	nInOrder(bt);
	cout << "后根序列周游递归：" << endl;
	postOrder(bt);
	cout << "后根序列周游非递归：" << endl;
	nPostOrder(bt);
	destroyBinTree(bt);
}
*/
/************函数指针的应用实例*******************************
typedef int(*Fun)(int, int);
int max(int a, int b)
{
	return (a > b) ? (a) : (b);
}
int min(int a, int b)
{
	return (a < b) ? (a) : (b);
}
int sum(int a, int b)
{
	return a + b;
}
int result(Fun f, int a, int b)
{
	return (*f)(a, b);
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << result(max, a, b) << endl;
	cout << result(min, a, b) << endl;
	cout << result(sum, a, b) << endl;
}
*/

/************按给定的参数从小到大或从大到小排序*******************************
void sortIntArray(int *a, int n, int flag)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if ((a[j]>a[j + 1]&&flag==0)||(a[j]<a[j+1]&&flag==1))
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void main()
{
	int a, flag;
	int array[100];
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> array[i];
	}
	cin >> flag;
	sortIntArray(array, a, flag);
	for (int i = 0; i < a; i++)
	{
		cout << array[i] <<' ';
	}
	cout << endl;
}
*/
/****************字符串中最长数字字符串********************************************************************
int isNUM(char c)
{
	return c >= '0'&&c <= '9';
}
void main()
{
	string str;
	cin >> str;
	string::iterator iterStart,iterx;
	int max=0, curMax;
	int flag = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (isNUM(*iter))
		{
			if (!flag)
			{
				flag = 1;
				iterStart = iter;
				curMax = 1;
			}
			else
			{
				curMax++;
				if (curMax > max)
				{
					max = curMax;
					iterx = iterStart;
				}
			}
		}
		else
		{
			curMax = 0;
			flag = 0;
		}
	}
	for (int i = 0; i < max; i++)
	{
		cout << *iterx;
		++iterx;
	}
	cout << ' ' << max << endl;
}
*/
/**
#include<iostream>
#include<string>
using namespace std;
void main()
{
	string str;
	cin >> str;
	int max=0,curMax=0;
	string::iterator start, curStart;
	int flag = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (!flag&&*iter >= '0'&&*iter <= '9')
		{
			flag = 1;
			curMax = 0;
			curStart = iter;
		}
		if (flag)
		{
			if (*iter >= '0'&&*iter <= '9')
			{
				curMax++;
				if (curMax > max)
				{
					max = curMax;
					start = curStart;
				}
			}
			else
			{
				flag = 0;
			}
		}
	}
	for (int i = 0; i < max; i++)
	{
		cout << *start;
		++start;
	}
	cout << endl;
}
*/
/**********************************************
int gys(int a, int b)
{
	return (!b) ? (a) : (gys(b, a%b));
}
int gys1(int a, int b)
{
	while (b != 0)
	{
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << gys(a, b) << endl;
	cout << gys1(a, b) << endl;
}
*/

/*****************排列组合*************************************
#include<iostream>
using namespace std;
void combine(int a[], int n, int m, int b[], const int M) 
{
	for (int i = n; i >= m; i--) 
	{  // 注意这里的循环范围  
		b[m - 1] = i - 1;
		if (m > 1) 
		{
			combine(a, i - 1, m - 1, b, M);
		}
		else  
		{                   // m == 1, 输出一个组合  
			for (int j = M - 1; j >= 0; j--)
				cout << a[b[j]] << " ";
			cout << endl;
		}
	}
}
int main(){
	int a[] = { 1, 2, 3, 4, 5 ,6};
	int b[3];
	combine(a, 6, 3, b, 2);
}
*/
/*******************判断是否是素数**********************
int isPrime(int n)
{
	int i = sqrt(n);
	int j;
	for (j = 2; j <= i; j++)
	{
		if (n%j == 0)
		{
			break;
		}
	}
	if (j <= i)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void main()
{
	int i;
	while (cin >> i)
	{
		cout << isPrime(i) << endl;
	}
}
*/
/****************质数因子*******************************************
void fun(long long n)
{
	long long i=2;
	long long buf=n;  //初始化别忘了
	while (i <= n)
	{
		if (n % i == 0)
		{
			cout << i << ' ';
			n = n / i;
			buf =sqrt(n);                   //加了这个速度快多了 4567893456784 时间复杂度由O(n)变为O(sqrt(n))
		}
		else
		{
			i++;
			if (i > buf)
			{
				cout << n << ' ';
				break;
			}
		}
	}
	cout << endl;
}
void main()
{
	long long l;
	while (cin >> l)
	{
		fun(l);
	}
}
*/
/***************************
void main()
{
	unsigned int i = 0x40000000;
	cout << (i << 2) << endl;       //溢出，为0
	i = 1;
	cout << (i << 33) << endl;      //33超过int的位数32，其实移位33%32=1
	i = -2;
	cout << (i >> 1) << endl;
	i = 5;
	cout << (i >> 1) << endl;
}
*/
/****************************************************
//=====求平均值===============================================================
int fun(int a, int b)
{
	//return (a + b) / 2;         //溢出
	return (a&b) + ((a^b) >> 1);
}
void main()
{
	int a, b;
	cin >> a;
	cin >> b;
	cout << fun(a, b) << endl;
}
*/
/**************************************
#include<iostream>
using namespace std;
int add(int a, int b)
{
	return (!b) ? (a) : (add(a^b, (a&b) << 1));
}
int add1(int a, int b)
{
	while (b)
	{
		int temp = a;
		a = (a^b);
		b = (temp&b) << 1;
	}
	return a;
}
int gys(int a, int b)
{
	return (!b) ? (a) : (gys(b, a%b));
}
int gys1(int a, int b)
{
	while (b)
	{
		int temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
	cout << add1(a, b) << endl;
	cout << gys(a, b) << endl;
	cout <<gys1(a, b) << endl;
}
*/
/******
#include<iostream>
using namespace std;
int abs(int x)
{
	int y = x >> 31;
	//return (x^y) - y;
	return (x + y) ^ y;
}
void main()
{
	int i;
	cin >> i;
	cout << abs(i) << endl;
	int x = 0x80000001;
	cout << x << endl;
}
*/
/******************************
#include<cstring>
#include<stdio.h>
void Reverse(char *a, int x, int y)
{
	for (; x < y; x++, y--)
	{
		a[x] = a[x] ^ a[y];
		a[y] = a[x] ^ a[y];
		a[x] = a[x] ^ a[y];
	}
}
void shiftRight(char *a, int n, int k)
{
	k %= n;
	Reverse(a, 0, n - k - 1);
	Reverse(a, n - k, n - 1);
	Reverse(a, 0, n - 1);
}
void main()
{
	char a[11];
	gets_s(a);
	shiftRight(a, 10, 3);
	printf("%s\n", a);
}
*/
/***********字符串循环右移k位********************
void shiftRight(string &str,int k)
{
	size_t size = str.size();
	k%size;
	reverse(str.begin(), str.begin() + size - k);
	reverse(str.end() - k, str.end());
	reverse(str.begin(), str.end());
}
void main()
{
	string str;
	cin >> str;
	shiftRight(str, 3);
	cout << str << endl;
}
*/
/************************************************************************
template<typename T>
class A;

template<typename T>
void input(A<T> &obj, T x);

template<typename T>
class A
{
public:
	void display()
	{
		cout << a << endl;
	}
	friend void input<T>(A<T> &obj, T x);
	
	friend istream &operator>><T>(istream &is, A<T> &x);               //<>别忘了
	friend ostream &operator<<<T>(ostream &os, const A<T> &x);
private:
	T a;
};

template<typename T>
void input(A<T> &obj, T x)
{
	obj.a = x;
}

template<typename T>
istream &operator>>(istream &is, A<T> &x)
{
	is >> x.a;
	return is;
}

template<typename T>
ostream &operator<<(ostream &os, const A<T> &x)
{
	os << x.a;
	return os;
}

void main()
{
	A<int> obj;
	A<string> strA;
	cin>>obj>>strA;
	input(obj, 5);
	cout << obj<<' '<<strA << endl;	
}
*/

//// 第一种方式，在模板类内部声明友元的函数模板 
/**
template <typename T>
class C 
{ 
	T m[5];
public:
     template <typename U>
     friend void foo(const C<U>& T);
};
 
template <typename T>
void foo(const C<T>& t)
{
	for (int i = 0; i < 5; ++i)
    {
		cout << t.m[i] << endl;
    }
}
*/
 // 第二种方式，在模板类内部声明对应版本的友元函数模板实例化
 // 需要前置声明
 // 这种方式是最为合理的方式

 //// 第三种方式，在模板类内部直接声明友元函数，不涉及函数模板
 //// 这种情况只能在模板类内部一起把函数的定义写出来，不能在外部实现，因为外部需要类型参数，而需要类型参数就是模板了
 //// 其实这种情况相当于一般的模板类的成员函数，也就是相当于一个函数模板
 //// 第二种方式也是一个函数模板，他们保持函数的参数类型和该模板类的实例一个类型
 //// 第一种方式更为灵活，他不会要求参数类型与模板类实例是一个类型，但是一般情况下我们也是按照一个类型使用的。

 
/***********01背包递归**************
#include <iostream>
using namespace std;
int Need[10000];
int value[500];
int max(int x, int y)
{
	return x > y ? x : y;
}
int GetMaxValue(int people, int mineNum)
{
	int retMaxGold;
	if (mineNum == 1)
	{
		if (people >= Need[mineNum])
		{
			retMaxGold = value[mineNum];
		}
		else
		{
			retMaxGold = 0;
		}
	}
	else if (people >= Need[mineNum])
	{
		retMaxGold = max(GetMaxValue(people - Need[mineNum], mineNum - 1) + value[mineNum],
			GetMaxValue(people, mineNum - 1));
	}
	else
	{
		retMaxGold = GetMaxValue(people, mineNum - 1);
	}
	return retMaxGold;
}

int main()
{
	int n;//奖品数
	int m;//奖券数
	cin >> n >> m;
	for (int i = 1; i<=n; i++)
		cin >> Need[i] >> value[i];
	cout << GetMaxValue(m, n) << endl;
	return 0;
}
*/
/**********01背包动态规划****************************************
//5 1000              //奖品数和奖券数      相当于物体个数和总体积  金矿个数和总人数
//144 990             //消耗的奖券数和价值  相当于单个体积和重量    单个金矿所需人数和价值
//487 436
//210 673
//567 58
//1056 897
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	int n;//奖品数
	int m;//奖券数
	int *need;
	int *value;
	int **maxValue;
	cin >> n >> m;
	need = new int[n + 1];
	value = new int[n + 1];
	maxValue = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		maxValue[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
		cin >> need[i] >> value[i];
	for (int j = 0; j <= m; j++)
	{
		maxValue[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j < need[i])
			{
				maxValue[i][j] = maxValue[i - 1][j];
			}
			
			else
			{
				maxValue[i][j] = max(maxValue[i-1][j], maxValue[i-1][j - need[i]] + value[i]);
			}
			
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cout << maxValue[i][j] << ' ';
		}
		cout << endl;
	}
	cout << maxValue[n][m] << endl;
	delete[]need;
	delete[]value;
	for (int j = 0; j <= n; j++)
	{
		delete[]maxValue[j];
	}
	delete[]maxValue;
	return 0;
}
*/
/**01背包动态规划优化存储空间***
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	int n;//奖品数
	int m;//奖券数
	int *need;
	int *value;
	int *maxValue;
	cin >> n >> m;
	need = new int[n+1];
	value = new int[n+1];
	maxValue = new int[m + 1];
	for (int i = 1; i<=n; i++)
		cin >> need[i] >> value[i];
	for (int j = 0; j <= m; j++)
	{
		maxValue[j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >=need[i]; j--)
		{
			maxValue[j] = max(maxValue[j], maxValue[j - need[i]] + value[i]);	
		}
		for (int j = 0; j <= m; j++)
		{
			cout << maxValue[j] << ' ';
		}
		cout << endl;
	}
	cout << maxValue[m] << endl;
	delete []need;
	delete []value;
	delete []maxValue;
	return 0;
}
*/
/******完全背包动态规划**************************
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	int n;//奖品数
	int m;//奖券数
	int *need;
	int *value;
	int **maxValue;
	cin >> n >> m;
	need = new int[n + 1];
	value = new int[n + 1];
	maxValue = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		maxValue[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
		cin >> need[i] >> value[i];
	for (int j = 0; j <= m; j++)
	{
		maxValue[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= j / need[i];k++)
			{
				maxValue[i][j] = max(maxValue[i][j], maxValue[i - 1][j - need[i]*k] + value[i]*k);
			}
		}
	}
	cout << maxValue[n][m] << endl;
	delete[]need;
	delete[]value;
	for (int j = 0; j <= n; j++)
	{
		delete[]maxValue[j];
	}
	delete[]maxValue;
	return 0;
}
*/
/**********完全背包动态规划时间优化**********************
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	int n;//奖品数
	int m;//奖券数
	int *need;
	int *value;
	int **maxValue;
	cin >> n >> m;
	need = new int[n + 1];
	value = new int[n + 1];
	maxValue = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		maxValue[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
		cin >> need[i] >> value[i];
	for (int j = 0; j <= m; j++)
	{
		maxValue[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (need[i] > j)
			{
				maxValue[i][j] = maxValue[i - 1][j];
			}
			else
			{
				maxValue[i][j] = max(maxValue[i - 1][j], maxValue[i][j - need[i]] + value[i]);
			}
		}
	}
	cout << maxValue[n][m] << endl;
	delete[]need;
	delete[]value;
	for (int j = 0; j <= n; j++)
	{
		delete[]maxValue[j];
	}
	delete[]maxValue;
	return 0;
}
*/
/****************************************************
#include<iostream>  
#include<string>  
#include<stack>  
#include<vector>  
using namespace std;
bool isF(string &str, int i)
{
	if (i == 0)
	{
		return true;
	}
	if (str[i - 1] >= '0'&&str[i - 1] <= '9'&&str[i + 1] >= '0'&&str[i + 1] <= '9')
	{
		return false;
	}
	return true;
}
int strtovector(string &str, vector<string> &strvec)
{
	string strbuf;
	stack<char> cstack;
	int flag = 0;
	int start = 0;
	int length;
	for (int i = 0; i < str.size(); i++)
	{
		if (!flag)
		{
			if ((str[i] >= '0'&&str[i] <= '9') || (str[i] == '-'&&isF(str, i)))//注意
			{
				flag = 1;
				start = i;
				length = 0;
			}
			else
			{
				cstack.push(str[i]);
			}
		}
		if (flag)
		{
			if ((str[i] >= '0'&&str[i] <= '9') || (str[i] == '-'&&isF(str, i)))
			{
				length++;
			}
			else if (str[i] != ')'&&str[i] != ']'&&str[i] != '}')
			{
				flag = 0;
				if (length)
				{
					strvec.push_back(str.substr(start, length));
					length = 0;
					if (!cstack.empty() && (cstack.top() == '/' || cstack.top() == '*'))
					{
						strbuf.clear();
						strbuf.push_back(cstack.top());
						cstack.pop();
						strvec.push_back(strbuf);
					}
				}
				cstack.push(str[i]);
			}
			else
			{
				//flag = 0;  
				if (length)
				{
					strvec.push_back(str.substr(start, length));
					length = 0;
				}
				while (!cstack.empty() && cstack.top() != '('&&cstack.top() != '['&&cstack.top() != '{')
				{
					strbuf.clear();
					strbuf.push_back(cstack.top());
					cstack.pop();
					strvec.push_back(strbuf);
				}
				if ((!cstack.empty() && cstack.top() != '('&&cstack.top() != '['&&cstack.top() != '{') || cstack.empty())
				{
					return -1;
				}
				cstack.pop();
				if (!cstack.empty() && (cstack.top() == '/' || cstack.top() == '*')) //注意
				{
					strbuf.clear();
					strbuf.push_back(cstack.top());
					cstack.pop();
					strvec.push_back(strbuf);
				}
			}
		}
	}
	if (length)
	{
		strvec.push_back(str.substr(start, length));
	}
	while (!cstack.empty())
	{
		if (cstack.top() == '(' || cstack.top() == '[' || cstack.top() == '{')
		{
			return -1;
		}
		strbuf.clear();
		strbuf.push_back(cstack.top());
		cstack.pop();
		strvec.push_back(strbuf);
	}
	return 0;
}
int strtod(string &str)
{
	int sum = 0;
	int flag = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter == '-')
		{
			flag = 1;
			continue;
		}
		sum *= 10;
		sum += *iter - '0';
	}
	if (flag)
		return sum - 2 * sum;
	else
		return sum;
}
int getResult(vector<string> &strvec)
{
	int d;
	stack<int> dstack;
	for (vector<string>::iterator strter = strvec.begin(); strter != strvec.end(); ++strter)
	{
		if (((*strter)[0] >= '0' && (*strter)[0] <= '9') || ((*strter).size()>1 && (*strter)[0] == '-'))    //注意,size大于1才可能是负数
		{
			dstack.push(strtod(*strter));
		}
		else
		{
			int y = dstack.top();
			dstack.pop();
			int x = dstack.top();
			dstack.pop();
			switch ((*strter)[0])
			{
			case '+':
				x += y;
				break;
			case '-':
				x -= y;
				break;
			case '*':
				x *= y;
				break;
			case '/':
				x /= y;
				break;
			default:
				break;
			}
			dstack.push(x);
		}
	}
	return dstack.top();
}
int main()
{
	string str;

	vector<string> strvec;
	cin >> str;
	if (strtovector(str, strvec) == -1)
	{
		return -1;
	}
	cout << getResult(strvec) << endl;
	return 0;
}
*/
/**
#include<iostream>    
using namespace std;
void main()
{
	int n = 11;
	int a[3] = {1,3,5};
	int Min[12] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		Min[i] = n;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i>=a[j] && Min[i - a[j]] + 1 < Min[i])
			{
				Min[i] = Min[i - a[j]] + 1;
			}
		}
		for (int k = 0; k <= n; k++)
		{
			cout << Min[k] << ' ';
		}
		cout << endl;
	}
	cout << Min[n] << endl;
}
*/
/*******************人民币转换********************************
#include<iostream>    
using namespace std;
void main()
{
	int n = 11;
	int a[3] = { 2, 3, 5 };
	int Min[12] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		Min[i] = n;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i >= a[j]&&i-a[j]!=1 && Min[i - a[j]] + 1 < Min[i])
			{
				Min[i] = Min[i - a[j]] + 1;
			}
		}
		for (int k = 0; k <= n; k++)
		{
			cout << Min[k] << ' ';
		}
		cout << endl;
	}
	cout << Min[n] << endl;
}
*/
/*******动态规划（最长不降序列的长度）******************************
#include <iostream>
using namespace std;
int list(int *a, int n)
{
	int *d = new int[n];
	int max = 1;

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] >= a[j] && d[j] + 1>d[i])
			{
				d[i] = d[j] + 1;
			}
			if (d[i]>max)
			{
				max = d[i];
			}
		}
	}
	delete[]d;
	return max;
}
int main()
{
	int a[6] = { 1, 2, 3, 1, 1, 2 };
	cout << list(a, 6) << endl;
	return 0;
}
*/
/********最大公共子串********
#include<iostream>
#include<string>
using namespace std;
void main()
{
	string X, Y;
	int i = 0;
	int j = 0;
	int **dp = NULL;
	cin >> X >> Y;
	int xlen = X.size();
	int ylen = Y.size();
	dp = new int*[xlen + 1];
	for (i = 0; i <= xlen; i++)
	{
		dp[i] = new int[ylen + 1];
	}
	for (i = 0; i <= xlen; i++)
	{
		dp[i][0] = 0;
	}
	for (j = 0; j <= ylen; j++)
	{
		dp[0][j] = 0;
	}
	for (i = 1; i <= xlen; ++i)
	{
		for (j = 1; j <= ylen; ++j)
		{
			if (X[i - 1] == Y[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (dp[i][j - 1] > dp[i - 1][j])
			{
				dp[i][j] = dp[i][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << "len of LCS is:" << dp[xlen][ylen] << endl;
	i = xlen;
	j = ylen;
	int k = dp[i][j];
	string buf;
	while (i && j)
	{
		if (X[i - 1] == Y[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1)
		{
			buf.insert(buf.begin(), X[i - 1]);
			--i; --j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
	}
	cout << buf << endl;
}
*/
/*******************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i)
	{
		if (size)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(NULL), size(obj.size)
	{
		if (size)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
		
	}
	const array& operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		if (data)
		{
			delete[]data;
			data = NULL;
		}
		size = obj.size;
		if (size)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
		
	}
	~array()
	{
		if (data)
		{
			delete []data;
		}
	}
	void setValue(int index,const T &x)
	{
		if (index < size)
		{
			data[index] = x;
		}
	}
	T getValue(int index) const
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			return T();
		}
	}
	int getsize() const
	{
		return size;
	}
private:
	
	T *data;
	int size;
};
int main()
{
	int n;
	cin >> n;
	string str;
	int a;
	array<int> intarray(n);
	for (int i = 0; i < intarray.getsize(); i++)
	{
		intarray.setValue(i, i);
	}
	array<int> intarray1=intarray;       //初始化，调用拷贝构造函数；
	for (int i = 0; i < intarray1.getsize(); i++)
	{
		cout << intarray1.getValue(i) << endl;
	}

	array<int> intarray2(2);
	intarray2 = intarray;
	for (int i = 0; i < intarray2.getsize(); i++)
	{
		cout << intarray2.getValue(i) << endl;
	}
	return 0;
}
*/
/*****************引用计数应用 有点意思**********************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i), count(new int)
	{
		*count = 1;
		if (size)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(obj.data), size(obj.size), count(obj.count)
	{
		++(*count);

	}
	const array& operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		Release();
		data = obj.data;
		size = obj.size;
		count = obj.count;
		++(*count);
		return *this;
	}
	~array()
	{
		Release();
	}
	void setValue(int index, const T &x)
	{
		if (index < size)
		{
			data[index] = x;
		}
	}
	T getValue(int index) const
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			return T();
		}
	}
	int getsize() const
	{
		return size;
	}
	int *getcount() const
	{
		return count;
	}
private:
	void Release()
	{
		--(*count);
		if (!(*count))
		{
			if (data)
			{
				delete[]data;
				data = NULL;
			}
			delete count;
			count = NULL;
			cout << "huang"<<endl;
		}
	}
	T *data;
	int size;
	int *count;
};
int main()
{
	int n;
	cin >> n;
	string str;
	int a;
	array<int> intarray(n);
	for (int i = 0; i < intarray.getsize(); i++)
	{
		intarray.setValue(i, i);
	}
	
	array<int> intarray2(2),intarray3(3);
	intarray3=intarray2 = intarray;
	cout << "=================" << endl;
	intarray2 = intarray;     //重新赋值count减1再加1 count的值还是不变，妙
	cout << "huang" <<*intarray2.getcount() << endl;
	for (int i = 0; i < intarray2.getsize(); i++)
	{
		cout << intarray2.getValue(i) << endl;
	}
	return 0;
}
*/
/****************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i)
	{}
	const A &operator=(const A &obj)
	{
		a = obj.a;
		return *this;
	}
	friend ostream &operator<<(ostream &os, const A &obj)
	{
		os << obj.a;
		return os;
	}
private:
	int a;
};
int main()
{
	A obj(0);
	A obj1(1);
	A obj2(2);
	obj2=obj1 = obj;
	cout <<obj2<< obj1 << obj << endl;
}
*/
/*************求链表的倒数第k个结点**************************************************
#include<iostream>
using namespace std;
struct Node;
typedef struct Node *PNode;
struct Node
{
	int info;
	PNode link;
};
typedef struct Node *Link;
//===创建链表=======================================
void createLink(Link *p, int n)
{
	PNode q,t;
	if (n <= 0)
	{
		return;
	}
	*p= new Node;
	q = *p;
	q->info = 1;
	q->link = NULL;
	for (int i = 2; i <= n; i++)
	{
		t = new Node;
		t->info = i;
		t->link = NULL;
		q->link = t;
		q = t;
	}
}
//=========销毁链表======================================
void destroy(Link plink)
{
	if (plink == NULL)
	{
		return;
	};
	PNode p;
	while (plink->link != NULL)
	{
		p = plink->link;
		delete plink;
		plink = p;
	}
	delete plink;
}
//=======寻找链表的倒数第k个结点==============================
PNode getnumk(Link a, int k)
{
	if (a == NULL||k<=0)
	{
		return NULL;
	}
	PNode first = a;
	PNode second = a;
	int i;
	for ( i= 1; i < k; i++)
	{
		if (second->link == NULL)
		{
			break;
		}
		second = second->link;
	}
	if (i != k)
	{
		return NULL;
	}
	while (second->link != NULL)
	{
		second = second->link;
		first = first->link;
	}
	return first;
}
int main()
{
	Link mylink=NULL;
	int n;
	cin >> n;
	createLink(&mylink, n);
	int k;
	while (cin >> k)
	{
		PNode buf = getnumk(mylink, k);
		if (buf)
		{
			cout << buf->info << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	destroy(mylink);
	mylink = NULL;
	return 0;
}
*/
/************************************************************************
#include<iostream>
using namespace std;
const char *fun()
{
	const char *p = "hua";
	return p;
}
int main()
{
	char a[] = "huang";
	char b[] = "huang";
	const char *c = "huang";    //c和d指向同一块内存区
	const char *d = "huang";
	if (a == b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	if (c == d)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	const char *h = fun();
	while ((*h) != '\0')
	{
		cout << *h++;
	}
	cout << endl;
	return 0;
}
*/
/*************链表的各种操作*********************************************************************************
#include<iostream>
using namespace std;
//定义链表结点
struct LinkNode
{
	int info;
	LinkNode *link;
};
//定义堆栈
struct SeqStack
{
	int MAXNUM;
	int t;
	int *c;
};
typedef struct SeqStack *Stack;
//创建一个堆栈
Stack createEmptyStack(int m)
{
	Stack s = new struct SeqStack;
	if (s)
	{
		s->c = new int[m];
		if (s->c)
		{
			s->MAXNUM = m;
			s->t = -1;
			return s;
		}
		else
		{
			delete s;
		}
	}
	printf("out of space\n");
	return NULL;
}
//销毁堆栈
void destroyStack(Stack *s)
{
	if (*s == NULL)
	{
		return;
	}
	delete[](*s)->c;
	delete *s;
	*s = NULL;
}
//判断堆栈是否为空
bool isEmptyStack(Stack s)
{
	return s->t == -1;
}
//判断堆栈是否满
bool isFullStack(Stack s)
{
	return s->t + 1 == s->MAXNUM;
}
//入栈
void push(Stack s, int x)
{
	if (isFullStack(s))
	{
		cout << "Full Stack" << endl;
	}
	else
	{
		s->t++;
		s->c[s->t] = x;
	}
}
//出栈
void pop(Stack s)
{
	if (isEmptyStack(s))
	{
		cout << "Empty Stack" << endl;
	}
	else
	{
		s->t--;
	}
}
//取栈顶元素
int top(Stack s)
{
	if (isEmptyStack(s))
	{
		cout << "Empty Stack" << endl;
	}
	else
	{
		return s->c[s->t];
	}
}
//链表尾部加值等于x的元素
void AddToTail(LinkNode **p, int x)
{
	if (p == NULL)
	{
		return;
	}
	LinkNode *pNew = new LinkNode();
	pNew->info = x;
	pNew->link = NULL;
	if (*p == NULL)
	{
		*p = pNew;                 //指针可能改变，传进来的参数要是指针的指针
	}
	else
	{
		LinkNode *pEnd = *p;
		while (pEnd->link != NULL)
		{
			pEnd = pEnd->link;
		}
		pEnd->link = pNew;
	}
}
//删除链表中第一个等于value的结点
void RemoveNode(LinkNode **p, int value)
{
	if (p == NULL || *p == NULL)
	{
		return;
	}
	LinkNode *pStart = *p;
	if ((*p)->info == value)
	{
		*p = (*p)->link;
		delete pStart;
	}
	else
	{
		while (pStart->link != NULL&&pStart->link->info != value)
		{
			pStart = pStart->link;
		}
		if (pStart->link != NULL&&pStart->link->info == value)
		{
			LinkNode *pbuf = pStart->link;
			pStart->link = pbuf->link;
			delete pbuf;
		}
	}
}
//链表翻转
void reverse(LinkNode **p)
{
	if (p == NULL || *p == NULL || (*p)->link == NULL)
	{
		return;
	}
	LinkNode *pnext=NULL;
	LinkNode *ppre = *p;
	*p = (*p)->link;
	pnext = (*p)->link;
	(*p)->link = ppre;
	ppre->link = NULL;
	while (pnext != NULL)
	{
		ppre = *p;
		*p =pnext;
		pnext = (*p)->link;
		(*p)->link = ppre;
	}
}
//从头至尾打印链表
void display(LinkNode *p)
{
	while (p != NULL)
	{
		cout << p->info << ' ';
		p = p->link;
	}
	cout << endl;
}
//从尾至头打印链表
void postDisplay(LinkNode *p)
{
	Stack s = createEmptyStack(20);
	while (p != NULL)
	{
		push(s, p->info);
		p = p->link;
	}
	while (!isEmptyStack(s))
	{
		cout << top(s) << ' ';
		pop(s);
	}
	cout << endl;
	destroyStack(&s);
}
//从尾至头打印链表的递归算法
void postDisplay_recursive(LinkNode *p)
{
	if (p != NULL)
	{
		if (p->link != NULL)
		{
			postDisplay_recursive(p->link);
		}
		cout << p->info <<' ';
	}
}
int main()
{
	LinkNode *myLink = NULL;
	for (int i = 0; i < 10; i++)
	{
		AddToTail(&myLink, i);
	}
	display(myLink);
	postDisplay(myLink);
	postDisplay_recursive(myLink);
	cout << endl;
	return 0;
}
*/
/*********最长递增子序列的长度（动态规划 时间复杂度为O(n2)）***********************************
#include<iostream>
using namespace std;
int LIS(int *a, int n)
{
	int *max = new int[n];
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		max[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i]>a[j] && max[j] + 1>max[i])
			{
				max[i] = max[j] + 1;
			}
		}
		if (max[i] > len)
		{
			len = max[i];
		}
	}
	delete[]max;
	return len;
}
int main()
{
	int a[] = { 8, 9, 3, 5, 7, 2, 6, 8, 1 };
	cout << LIS(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}
*/
/*********最长递增子序列的长度（DP+二分查找 时间复杂度为O(nlogn)）*********************
#include<iostream>
using namespace std;
int findpos(int *a, int begin, int end, int x)
{
	int mid = 0;
	while (begin < end)
	{
		mid = (begin + end) / 2;
		if (a[mid]>x)
		{
			end = mid;
		}
		else if (a[mid] < x)
		{
			begin = mid+1;
		}
		else
		{
			return mid;
		}
	}
}
int LIS(int *a, int n)
{
	int *max = new int[n + 1];
	max[0] = 0;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max[len])
		{
			max[++len] = a[i];
		}
		else
		{
			int pos = findpos(max, 0, len, a[i]);
			max[pos] = a[i];
		}
	}
	delete[]max;
	return len;
}
int main()
{
	int a[] = { 8, 9, 3, 5, 7, 2, 6, 8, 1 };
	cout << LIS(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}
*/
/************两个字符串的最大公共子序列（动态规划）**************************************
#include<iostream>
#include<string>
using namespace std;
int LCS(string &str1, string &str2, string &common)
{
	int i = 0;
	int j = 0;
	size_t size1 = str1.size();
	size_t size2 = str2.size();
	int **max = new int*[size1 + 1];
	for (i = 0; i <= size1; i++)
	{
		max[i] = new int[size2 + 1];
	}
	for (i = 0; i <= size1; i++)
	{
		max[i][0] = 0;
	}
	for (j = 0; j <= size2; j++)
	{
		max[0][j] = 0;
	}
	for (i = 1; i <= size1; i++)
	{
		for (j = 1; j <= size2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				max[i][j] = max[i - 1][j - 1] + 1;
			}
			else if (max[i-1][j]>max[i][j-1])
			{
				max[i][j] = max[i - 1][j];
			}
			else
			{
				max[i][j] = max[i][j - 1];
			}
		}
	}
	common.clear();
	i = size1;
	j = size2;
	while (i&&j)
	{
		if (str1[i - 1] == str2[j - 1] && max[i][j] == max[i - 1][j - 1] + 1)
		{
			common.insert(common.begin(), str1[i - 1]);
			i--;
			j--;
		}
		else if (max[i - 1][j] > max[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	int theMax=max[size1][size2];
	for (i = 0; i <= size1; i++)
	{
		delete[]max[i];
	}
	delete[]max;
	return theMax;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	string common;
	cout << LCS(str1, str2, common) << endl;
	cout << common << endl;
	return 0;
}
*/
/****************************************
#include<iostream>
using namespace std;
int Max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int n=0;
	int m=0;
	cin >> n >> m;
	int *need = new int[n + 1];
	int *value = new int[n + 1];
	int *maxValue = new int[m + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> need[i] >> value[i];
	}
	for (int j = 0; j <= m; j++)
	{
		maxValue[j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j>=need[i]; j--)
		{
			maxValue[j] = Max(maxValue[j], maxValue[j - need[i]] + value[i]);
		}
	}
	cout << maxValue[m] << endl;
	return 0;
}
*/
/**********根据先根次序和对称序列创建二叉树*******************************
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink;
	BinTreeNode *rlink;
};
typedef struct BinTreeNode *Tree;
Tree construct(int *preOrder, int *inOrder, int len)
{
	Tree root = new BinTreeNode;
	if (root)
	{
		root->info = preOrder[0];
		root->llink = root->rlink = NULL;
	}
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (inOrder[i] == preOrder[0])
		{
			break;
		}
	}
	if (i == len)
	{
		//throw exception("Invalid input!");
		return NULL;
	}
	int len1 = i;
	int len2 = len - i - 1;
	if (len1)
	{
		root->llink = construct(preOrder + 1, inOrder, len1);
	}
	if (len2)
	{
		root->rlink = construct(preOrder + len1 + 1, inOrder + len1 + 1, len2);
	}
	return root;
}
Tree constructTree(int *preOrder, int *inOrder, int len)
{
	if (preOrder == NULL || inOrder == NULL || len <= 0)
	{
		return NULL;
	}
	return construct(preOrder, inOrder, len);
}
void PreOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->info<<' ';
	PreOrder(t->llink);
	PreOrder(t->rlink);
}
int main()
{
	int a[] = { 1 };
	int b[] = { 4 };
	Tree mytree = constructTree(a, b,sizeof(a)/sizeof(int));
	PreOrder(mytree);
	cout << endl;
	return 0;
}
*/
/***********两个栈实现队列******************************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
template<typename T>
class CQueue
{
public:
	bool empty();
	void enQueue(const T &node);
	T deleteQueue(void);
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::enQueue(const T &node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteQueue()
{
	if (empty())
	{
		cout << "empty Queue" << endl;
		return T();
	}
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	T data = stack2.top();
	stack2.pop();
	return data;
}

template<typename T>
bool CQueue<T>::empty()
{
	return stack1.empty() && stack2.empty();
}
int main()
{
	CQueue<int> iQueue;
	for (int i = 0; i < 10; i++)
	{
		iQueue.enQueue(i);
	}
	while (!iQueue.empty())
	{
		cout << iQueue.deleteQueue() << endl;
	}

	string str;
	CQueue<string> strQueue;
	while (cin >> str)
	{
		strQueue.enQueue(str);
	}
	while (!strQueue.empty())
	{
		cout << strQueue.deleteQueue() << endl;
	}
	return 0;
}
*/
/*************两个队列实现栈*********************************************
#include<iostream>
#include<string>
#include<queue>
using namespace std;

template<typename T>
class CStack
{
public:
	bool empty(void);
	void push(const T &x);
	T pop(void);
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T>
bool CStack<T>::empty()
{
	return queue1.empty() && queue2.empty();
}

template<typename T>
void CStack<T>::push(const T &x)
{
	if (!queue1.empty())
	{
		queue1.push(x);
	}
	else
	{
		queue2.push(x);
	}
}

template<typename T>
T CStack<T>::pop()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return T();
	}
	T data = T();
	if (queue1.empty())
	{
		while (queue2.size() != 1)
		{
			queue1.push(queue2.front());
			queue2.pop();
		}
		data = queue2.front();
		queue2.pop();
	}
	else
	{
		while (queue1.size() != 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		data = queue1.front();
		queue1.pop();
	}
	return data;
}

int main()
{
	CStack<int> intstack;
	for (int i = 0; i < 10; i++)
	{
		intstack.push(i);
	}
	while (!intstack.empty())
	{
		cout << intstack.pop() << endl;
	}

	string str;
	CStack<string> strstack;
	while (cin >> str)
	{
		strstack.push(str);
	}
	while (!strstack.empty())
	{
		cout << strstack.pop() << endl;
	}
	return 0;
}
*/
/**********C++实现栈*************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T> 
class CStack
{
public:
	CStack(int m);
	~CStack();
	bool empty();
	bool full();
	void push(const T &x);
	void pop();
	T top();
private:
	CStack(const CStack &obj);
	CStack &operator=(const CStack &obj);
	int MAXNUM;
	int t;
	T *c;
};

template<typename T>
CStack<T>::CStack(int m)
{
	c = new T[m];
	if (c)
	{
		MAXNUM = m;
		t = -1;
	}
}

template<typename T>
CStack<T>::~CStack()
{
	delete []c;
}

template<typename T>
bool CStack<T>::empty()
{
	return t == -1;
}

template<typename T>
bool CStack<T>::full()
{
	return t + 1 == MAXNUM;
}

template<typename T>
void CStack<T>::push(const T &x)
{
	if (full())
	{
		cout << "full stack" << endl;
		return;
	}
	t++;
	c[t] = x;
}

template<typename T>
void CStack<T>::pop()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return;
	}
	t--;
}

template<typename T>
T CStack<T>::top()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return T();
	}
	return c[t];
}
int main()
{
	CStack<int> iStack(10);
	for (int i = 0; i < 10; i++)
	{
		iStack.push(i);
	}
	while (!iStack.empty())
	{
		cout << iStack.top() << endl;
		iStack.pop();
	}
	CStack<string> strStack(10);
	string str;
	while (cin >> str)
	{
		strStack.push(str);
	}
	while (!strStack.empty())
	{
		cout << strStack.top() << endl;
		strStack.pop();
	}
	return 0;
}
*/
/**********C++实现队列*********************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class CQueue
{
public:
	CQueue(int m);
	~CQueue();
	bool empty();
	bool full();
	void push(const T &x);
	void pop();
	T front();
private:
	CQueue(const CQueue &obj);
	CQueue &operator=(const CQueue &obj);
	int MAXNUM;
	int f, r;
	T *q;
};

template<typename T>
CQueue<T>::CQueue(int m)
{
	q = new T[m];
	if (q)
	{
		MAXNUM = m;
		f = 0;
		r = 0;
	}
}

template<typename T>
CQueue<T>::~CQueue()
{
	delete[]q;
}

template<typename T>
bool CQueue<T>::empty()
{
	return f == r;
}

template<typename T>
bool CQueue<T>::full()
{
	return (r + 1) % MAXNUM == f;
}

template<typename T>
void CQueue<T>::push(const T &x)
{
	if (full())
	{
		cout << "full Queue" << endl;
		return;
	}
	q[r++] = x;
}

template<typename T>
void CQueue<T>::pop()
{
	if (empty())
	{
		cout << "empty Queue" << endl;
		return;
	}
	f++;
}

template<typename T>
T CQueue<T>::front()
{
	if (empty())
	{
		cout << "empty Queue" << endl;
		return T();
	}
	return q[f];
}
int main()
{
	CQueue<int> iQueue(10);
	for (int i = 0; i < 10; i++)
	{
		iQueue.push(i);
	}
	while (!iQueue.empty())
	{
		cout << iQueue.front() << endl;
		iQueue.pop();
	}

	string str;
	CQueue<string> strQueue(10);
	while (cin >> str)
	{
		strQueue.push(str);
	}
	while (!strQueue.empty())
	{
		cout << strQueue.front() << endl;
		strQueue.pop();
	}
	return 0;
}
*/
/*********提高了代码的重用性，为功能扩展提供了便利****************************************************
#include<iostream>
using namespace std;
//是否是偶数
bool isEven(int i)
{
	return (i & 1)==0;
}
bool isThree(int i)
{
	return i % 3 == 0;
}
void Reorder(int *pData, int length,bool (*pf)(int))
{
	if (pData == NULL || length <= 0)
	{
		return;
	}
	int *begin = pData;
	int *end = pData + length-1;
	while (begin < end)
	{
		while (!(*pf)(*begin))
		{
			++begin;
		}
		while ((*pf)(*end))
		{
			--end;
		}
		if (begin < end)
		{
			*begin = *begin^*end;
			*end   = *begin^*end;
			*begin = *begin^*end;
		}
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(a) / sizeof(int);
	Reorder(a, size,isEven);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	Reorder(a, size, isThree);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/*****************************************************************
#include<iostream>
using namespace std;
struct LinkNode
{
	int info;
	LinkNode *next;
};
void createLink(LinkNode **pLinkHead, int m)
{
	if (m <= 0)
	{
		*pLinkHead = NULL;
		return;
	}
	LinkNode *pNode = new struct LinkNode;
	pNode->info = 0;
	pNode->next = NULL;
	*pLinkHead = pNode;
	for (int i = 1; i < m; i++)
	{
		pNode->next = new struct LinkNode;
		pNode = pNode->next;
		pNode->info = i;
		pNode->next = NULL;
	}
}
void destroy(LinkNode **pLinkHead)
{
	if (pLinkHead == NULL || *pLinkHead == NULL)
	{
		return;
	}
	LinkNode *pNode = *pLinkHead;
	while (pNode->next != NULL)
	{
		pNode = pNode->next;
		delete *pLinkHead;
		*pLinkHead = pNode;
	}
	delete *pLinkHead;
	*pLinkHead = NULL;
}
void display(LinkNode *pLink)
{
	if (pLink == NULL)
	{
		return;
	}
	while (pLink != NULL)
	{
		cout << pLink->info << endl;
		pLink=pLink->next;
	} 
}
void deleteNode(LinkNode **pLinkHead, LinkNode *pDeleteNode)
{
	if (pLinkHead == NULL || *pLinkHead == NULL || pDeleteNode == NULL)
	{
		return;
	}
	if (pDeleteNode->next == NULL)
	{
		if (*pLinkHead == pDeleteNode)
		{
			delete pDeleteNode;
			pDeleteNode = NULL;
			*pLinkHead == NULL;
		}
		else
		{
			LinkNode *pNode = *pLinkHead;
			while (pNode->next != pDeleteNode)
			{
				pNode = pNode->next;
			}
			pNode->next = NULL;
			delete pDeleteNode;
			pDeleteNode = NULL;
		}
	}
	else
	{
		LinkNode *pNode = pDeleteNode->next;
		pDeleteNode->info = pNode->info;
		pDeleteNode->next = pNode->next;
		delete pNode;
		pNode = NULL;
	}
}
int main()
{
	LinkNode *pMyLink;
	createLink(&pMyLink, 10);
	LinkNode *pNode = pMyLink->next->next->next->next;
	deleteNode(&pMyLink, pNode);
	display(pMyLink);
	destroy(&pMyLink);
	return 0;
}
*/
/**********二叉树镜像**********************************************
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
typedef struct BinTreeNode *Tree;
void createTree(Tree *pTree)
{
	int tmp = 0;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*pTree = new BinTreeNode;
	(*pTree)->info = tmp;
	(*pTree)->llink = (*pTree)->rlink = NULL;
	createTree(&(*pTree)->llink);
	createTree(&(*pTree)->rlink);
}
void destroyTree(Tree *pt)
{
	if (pt == NULL || *pt == NULL)
	{
		return;
	}
	destroyTree(&(*pt)->llink);
	destroyTree(&(*pt)->rlink);
	delete *pt;
	*pt = NULL;
}
void mirrorTree(Tree *pt)
{
	if (pt==NULL||*pt == NULL)
	{
		return;
	}
	if (!(*pt)->llink&&!(*pt)->rlink)
	{
		return;
	}
	Tree tmp = (*pt)->llink;
	(*pt)->llink = (*pt)->rlink;
	(*pt)->rlink = tmp;
	if ((*pt)->llink!=NULL)
	{
		mirrorTree(&(*pt)->llink);
	}
	if ((*pt)->rlink!=NULL)
	{
		mirrorTree(&(*pt)->rlink);
	}
}
void preOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->info << ' ';
	preOrder(t->llink);
	preOrder(t->rlink);
}
int main()
{
	Tree myTree = NULL;
	createTree(&myTree);
	preOrder(myTree);
	cout << endl;
	mirrorTree(&myTree);
	preOrder(myTree);
	cout << endl;
	destroyTree(&myTree);
	return 0;
}
*/
/************二维动态规划******************************************************
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int main()
{
	const int m = 7;
	const int n = 6;
	int a[m][n] = { 5, 8, 5, 7, 1, 8,
					1, 3, 2, 8, 7, 9,
					7, 8, 6, 6, 8, 7,
					9, 9, 8, 1, 6, 3,
					2, 4, 10, 2, 6, 2,
					5, 5, 2, 1, 8, 8,
					5, 9, 2, 6, 8, 4 };
	int **dp = new int*[m];
	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++)
	{
		dp[i] = new int[n];
	}
	dp[0][0] = a[0][0];
	for (i = 1; i < m; i++)
	{
		dp[i][0] = a[i][0]+dp[i - 1][0];
	}
	for (j = 1; j < n; j++)
	{
		dp[0][j] = a[0][j] + dp[0][j - 1];
	}
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[m - 1][n - 1] << endl;
//------------------求路径------------------------------------------
	vector<pair<int, int> > pairvec;
	pair<int, int> ipair;
	i = m - 1;
	j = n - 1;
	while (i&&j)
	{
		if (dp[i - 1][j] > dp[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
		ipair.first = i;
		ipair.second = j;
		pairvec.insert(pairvec.begin(),ipair);
	}
	if (i == 0)
	{
		ipair.first = 0;
		while (j)
		{
			ipair.second = --j;
			pairvec.insert(pairvec.begin(), ipair);
		}
	}
	else
	{
		ipair.second = 0;
		while (i)
		{
			ipair.first = --i;
			pairvec.insert(pairvec.begin(), ipair);
		}
	}
//-----------打印路径----------------------------------------
	for (vector<pair<int, int> >::iterator iter = pairvec.begin(); iter != pairvec.end(); ++iter)
	{
		cout << '(' << (*iter).first << ',' << (*iter).second << ')' << endl;
	}
	for (i = 0; i < m; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
}
*/
/*******
#include<iostream>
using namespace std;
int fun(int n)
{
	if (n < 1)
	{
		return -1;
	}
	else if (n==1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	int s1 = 1;
	int s2 = 2;
	for (int i = 3; i <= n; i++)
	{
		int temp = s1;
		s1 = s2;
		s2 = temp + s2;
		if (s1 > 19999997 && s2 > 19999997)
		{
			s1 %= 19999997;
			s2 %= 19999997;
		}
	}
	return s2 %= 19999997;
}
int main()
{
	int N=0;
	cin >> N;
	int result = fun(N);
	if (result > 0)
	{
		cout << result << endl;
		return 0;
	}
	return -1;
}
*/
/**************************************************************
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int reslut(string &str)
{
	size_t size = str.size();
	if (size == 0)
	{
		return 0;
	}
	int i;
	for (i = size; i >=1; i--)
	{
		string strbuf, strbuf1;
		for (int j = 0; j < size - i + 1; j++)
		{
			strbuf = str.substr(j, i);
			strbuf1 = strbuf;
			reverse(strbuf1.begin(), strbuf1.end());
			if (strbuf == strbuf1)
			{
				break;
			}
		}
		if (strbuf == strbuf1)
		{
			break;
		}
	}
	return i;
}
int main()
{
	vector<string> strvec;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		strvec.push_back(str);
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		cout << reslut(*iter) << endl;
	}
	return 0;
}
*/
/******************************************************************************
#include<iostream>
//#include<stack>
//#include<queue>
using namespace std;

template<typename T>
class stack
{
public:
	stack(int m=100);
	~stack();
	bool empty();
	bool full();
	void push(const T &tobj);
	T top();
	void pop();
private:
	stack(const stack &obj);
	stack &operator=(const stack &obj);
	int MAXNUM;
	int t;
	T *p;
};
template<typename T>
stack<T>::stack(int m=100)
{
	p = new T[m];
	if (p)
	{
		MAXNUM = m;
		t = -1;
	}
}
template<typename T>
stack<T>::~stack()
{
	delete[]p;
}
template<typename T>
bool stack<T>::empty()
{
	return t == -1;
}
template<typename T>
bool stack<T>::full()
{
	return (t + 1) == MAXNUM;
}
template<typename T>
void stack<T>::push(const T &tobj)
{
	if (full())
	{
		cout << "full stack" << endl;
	}
	else
	{
		p[++t] = tobj;
	}
}
template<typename T>
T stack<T>::top()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return T();
	}
	else
	{
		return p[t];
	}
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		cout << "empty stack" << endl;
	}
	else
	{
		t--;
	}
}

template<typename T>
class queue
{
public:
	queue(int m = 100);
	~queue();
	bool empty();
	bool full();
	void push(const T &tobj);
	T front();
	void pop();
private:
	queue(const queue &obj);
	queue &operator=(const queue &obj);
	int MAXNUM;
	int f, r;
	T *p;
};
template<typename T>
queue<T>::queue(int m = 100)
{
	p = new T[m];
	if (p)
	{
		MAXNUM = m;
		f = r = 0;
	}
}
template<typename T>
queue<T>::~queue()
{
	delete[]p;
}
template<typename T>
bool queue<T>::empty()
{
	return f == r;
}
template<typename T>
bool queue<T>::full()
{
	return (r + 1) % MAXNUM == f;
}
template<typename T>
void queue<T>::push(const T &tobj)
{
	if (full())
	{
		cout << "full queue" << endl;
	}
	else
	{
		p[r] = tobj;
		r = (r + 1) % MAXNUM;
	}
}
template<typename T>
T queue<T>::front()
{
	if (empty())
	{
		cout << "empty queue" << endl;
		return T();
	}
	else
	{
		return p[f];
	}
}
template<typename T>
void queue<T>::pop()
{
	if (empty())
	{
		cout << "empty queue" << endl;
	}
	else
	{
		f = (f + 1) % MAXNUM;
	}
}
struct BinTreeNode
{
	int info;
	BinTreeNode *llink;
	BinTreeNode *rlink;
};
typedef struct BinTreeNode *Tree;
void createTree(Tree *pTree)
{
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*pTree = new BinTreeNode;
	(*pTree)->info = tmp;
	(*pTree)->llink = (*pTree)->rlink = NULL;
	createTree(&(*pTree)->llink);
	createTree(&(*pTree)->rlink);
}
void destroy(Tree *pTree)
{
	if (pTree == NULL || *pTree == NULL)
	{
		return;
	}
	destroy(&(*pTree)->llink);
	destroy(&(*pTree)->rlink);
	delete *pTree;
	*pTree = NULL;
}
void preOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->info << ' ';
	preOrder(t->llink);
	preOrder(t->rlink);
}
void nPreOrder(Tree t)
{
	stack<Tree> tStack;
	if (t == NULL)
	{
		return;
	}
	Tree p = t;
	tStack.push(p);
	while (!tStack.empty())
	{
		p = tStack.top();
		tStack.pop();
		if (p != NULL)
		{
			cout << p->info << ' ';
			tStack.push(p->rlink);
			tStack.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	inOrder(t->llink);
	cout << t->info << ' ';
	inOrder(t->rlink);
}
void nInOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Tree> tStack;
	Tree p = t;
	while (p != NULL || !tStack.empty())
	{
		while (p != NULL)
		{
			tStack.push(p);
			p = p->llink;
		}
		p = tStack.top();
		tStack.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	postOrder(t->llink);
	postOrder(t->rlink);
	cout << t->info << ' ';
}
void nPostOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Tree> tStack;
	Tree p = t;
	Tree pp;
	while (p != NULL||!tStack.empty())
	{
		while (p != NULL)
		{
			tStack.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = tStack.top();
		tStack.pop();
		cout << p->info << ' ';
		if (!tStack.empty()&&tStack.top()->llink == p)
		{
			p = tStack.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
struct Flag
{
	int tag;
	Tree pt;
};
void nPostOrder1(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	Flag pnode;
	stack<Flag> fStack;
	Tree p = t;
	while (p != NULL || !fStack.empty())
	{
		while (p != NULL)
		{
			pnode.tag = 1;
			pnode.pt = p;
			fStack.push(pnode);
			p = p->llink;
		}
		pnode = fStack.top();
		fStack.pop();
		p = pnode.pt;
		if (pnode.tag == 1)
		{
			pnode.tag = 2;
			fStack.push(pnode);
			p = p->rlink;
		}
		else
		{
			cout << p->info << ' ';
			p = NULL;
		}
	}
	cout << endl;
}
void guangduOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	queue<Tree> tQueue;
	Tree q = t;
	Tree qq;
	tQueue.push(q);
	while (!tQueue.empty())
	{
		q = tQueue.front();
		tQueue.pop();
		cout << q->info << ' ';
		qq = q->llink;
		if (qq != NULL)
		{
			tQueue.push(qq);
		}
		qq = q->rlink;
		if (qq != NULL)
		{
			tQueue.push(qq);
		}
	}
	cout << endl;
}
int main()
{
	Tree myTree;
	createTree(&myTree);
	cout << "先根次序递归算法：" << endl;
	preOrder(myTree);
	cout << endl;
	cout << "先根次序非递归：" << endl;
	nPreOrder(myTree);
	cout << "对称次序递归算法：" << endl;
	inOrder(myTree);
	cout << endl;
	cout << "对称次序非递归算法：" << endl;
	nInOrder(myTree);
	cout << "后根次序递归算法：" << endl;
	postOrder(myTree);
	cout << endl;
	cout << "后根次序非递归算法：" << endl;
	nPostOrder(myTree);
	nPostOrder1(myTree);
	cout << "广度优先周游：" << endl;
	guangduOrder(myTree);
	destroy(&myTree);
	return 0;
}
*/
/***********************
#include<iostream>
using namespace std;
#define test 0
int main()
{
#if test
	cout << "huang" << endl;
#else
	cout << "hua" << endl;
#endif
	return 0;
}
*/
/************************************************
#include<iostream>
using namespace std;
union A
{
	unsigned char a[4];
	int aa;
	A()
	{
		for (int i = 0; i < 4; i++)
		{
			a[i] = 1;
		}
	}
	void display()
	{
		cout << aa << endl;
	}
};
int main()
{
	A obj;
	obj.display();
	return 0;
}
*/
/******************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i)
	{
		cout << "A" << endl;
	}
	virtual ~A()                         //必须定义为虚的
	{
		cout << "~A" << endl;
	}
private:
	int a;
};
class B :public A
{
public:
	B(int i, int j) :A(i), b(j)
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
private:
	int b;
};
int main()
{
	A *p = new B(1, 2);
	delete p;
	return 0;
}
*/
/*****************************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int &i) :a0(10), a1(i){}
	void display()
	{
		cout << a0 << ' ' << a1 << endl;
	}
private:
	const int a0;
	int &a1;
};
int main()
{
	int i = 1;
	A obj(i);
	obj.display();
	i++;
	obj.display();
	return 0;
}
*/
/***********************************
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << a++ << endl;
	}
	void display()
	{
		cout << a << endl;
	}
	
private:
	static int a;
	
};
int A::a;                 
int main()
{
	A obj,obj1;
	return 0;
}
*/
/**
#include<iostream>
using namespace std;

template<typename T>
class A;

template<typename T>
void display(A<T> &obj);

template<typename T>
class A
{
public:
	static void fun(T i, A &obj)
	{
		obj.a = i;
	}
	friend void display<T>(A<T> &obj);
	friend ostream &operator<<<T>(ostream &os, const A<T> &obj);
	friend istream &operator>>(istream &is, A &obj)
	{
		is >> obj.a;
		return is;
	}
private:
	T a;
};
template<typename T>
void display(A<T> &obj)
{
	cout << obj.a << endl;
}
template<typename T>
ostream &operator<<(ostream &os, const A<T> &obj)
{
	os << obj.a;
	return os;
}
int main()
{
	A<int> obj;
	A<int>::fun(5, obj);
	A<int> obj1;
	obj1.fun(6, obj1);
	cout << obj << ' ' << obj1 << endl;
	display(obj);
	return 0;
}
*/
/**********************
#include<iostream>
using namespace std;
class A
{
public:
	protected:
	int a;
};
class B:private A
{
public:
	void display()
	{
		cout << a << b << endl;
	}
private:
	int b;
};
int main()
{
	B obj;
	cout << sizeof(obj) << endl;
	return 0;
}
*/
/********************************************************
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		a++;
		cout << "A" << endl;
	}
	static void fun()
	{
		cout << a<<endl;
	}
protected:
	static int a;
};

class B :public A
{
public:
	B()
	{
		a++;
		cout << "B" << endl;
	}
private:
};
int A::a = 1;
int main()
{
	A obj;
	B obj0;
	A::fun();
	B::fun();
	return 0;
}
*/
/*******************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(double i, double j) :x(i), y(j){}
	virtual double fun() = 0;
protected:
	double x, y;
};
class B0 :public A
{
public:
	B0(double i, double j) :A(i, j){}
	double fun()
	{
		return x*y;
	}
private:
};
class B1 :public A
{
public:
	B1(double i, double j) :A(i, j){}
	double fun()
	{
		return 0.5*x*y;
	}
};
double result(A &obj)
{
	return obj.fun();
}
int main()
{
	B0 obj0(3, 4);
	B1 obj1(3, 4);
	cout << result(obj0) << endl;
	cout << result(obj1) << endl;
	return 0;
}
*/
/*************************************
#include<iostream>
using namespace std;
class A
{
public:
	void f(int i)
	{
		cout << "f in A" << endl;
	}
};
class B
{
public:
	void f(double i)            //只要函数名相同 就是隐藏
	{
		cout << "f in B" << endl;
	}
};
int main()
{
	B obj;
	obj.f(1);
	return 0;
}
*/
/********不能被继承的类*************************
#include<iostream>
using namespace std;
class FinalClass1
{
public:
	static FinalClass1* GetInstance(int i)
	{
		return new FinalClass1(i);
	}

	static void DeleteInstance(FinalClass1* pInstance)
	{
		delete pInstance;
		pInstance = NULL;
	}
	void dispaly()
	{
		cout << a << endl;
	}
private:
	FinalClass1(int i):a(i) {}
	~FinalClass1() {}
	int a;
};
int main()
{
	FinalClass1 *pobj = FinalClass1::GetInstance(6);
	pobj->dispaly();
	FinalClass1::DeleteInstance(pobj);
	return 0;
}
*/
/**
#include<iostream>
using namespace std;
class A
{
public:
	static A *GetInstance(int i)
	{
		return new A(i);
	}
	static void DeleteInstance(A **pA)
	{
		delete *pA;
		*pA = NULL;
	}
	friend ostream &operator<<(ostream &os, const A &obj)
	{
		os << obj.a;
		return os;
	}

private:
	A(int i) :a(i)
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	int a;
};
int main()
{
	A *pobj = A::GetInstance(6);
	cout << *pobj << endl;
	A::DeleteInstance(&pobj);
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
class MakeA
{
	friend class A;
private:
	MakeA()
	{
		cout << "MakeA" << endl;
	}
	~MakeA()
	{
		cout << "~MakeA" << endl;
	}
};
class A :virtual public MakeA
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
private:
};
int main()
{
	A obj;
	cout << sizeof(obj) << endl;
	return 0;
}
*/
/****
#include<iostream>
using namespace std;
int main()
{
	short i = 0;
	i = i + 1L;
	return 0;
}
*/
/**
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i)
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	virtual void display()
	{
		cout << a << endl;
	}
private:
	int a;
};
int main()
{
	A *p = new A(1);
	p->display();
	delete p;

	A *pp = (A*)malloc(sizeof(A));//没有调用构造函数
	//pp->display();              //虚函数表的建立是在构造函数中完成的，由于没有调用构造函数，这里运行出错
	cout << sizeof(*pp) << endl;
	free(pp);                     //没有调用析构函数
	return 0;
}
*/
/****
#include<iostream>
using namespace std;
#define max(a,b) (a)>(b)? (a):(b)
int main()
{
	int a = 4;
	int b = 3;
	int c = max(a++, b++);
	cout << c << ' ' << a << ' ' << b << endl;
	return 0;
}
*/
/*****************
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		test++;
		cout << "A" << endl;
	}
	inline void fun()
	{
		cout << "fun" << endl;
	}
	static int test;
private:
	int a;
};
int A::test = 0;
typedef void (*Fun)();
class B :public A
{
public:
	B()
	{
		test++;
		cout << "B" << endl;
	}
private:
	int b;
};
int main()
{
	A obj;
	cout << A::test << endl;
	B obj0;                     //先调用父类的构造函数，再调用子类的构造函数，test加了两次
	cout << A::test << endl;   //子类共享父类的static成员
	obj0.fun();
	return 0;
}
*/
/*********************
#include<iostream>
using namespace std;
class A
{
public:
	void fun()
	{
		cout << "A" << endl;
	}
private:
};
class B:public A
{
public:
	void fun()
	{
		cout << "B" << endl;
	}
};
int main()
{
	B obj;
	obj.fun();

	A *p = new B;
	p->fun();
	delete p;
	return 0;
}
*/
/******realloc*
#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
	int *a = (int*)malloc(sizeof(int)* 5);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
	}	

	int *b=(int*)realloc(a, sizeof(int)*10);
	for (int i = 5; i < 10; i++)
	{
		b[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;
	free(b);
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
class A
{
public:
	A() 
	{ 
		p = this; 
		cout << "构造函数" << endl;
	}
	~A() 
	{ 
		cout << "析构函数" << endl;
		if (p != NULL) 
		{ 
			delete p;                           //无限的在这调用析构函数
			p = NULL;                           //程序永远跑不到这里
			cout << "huang" << endl;
		} 
	}
	A* p;
};

int main()
{
	A obj;
	return 0;
}
*/
/***********************
#include <iostream>
using namespace std;

class A

{

public:

	virtual void print(void)

	{

		cout << "A::print()" << endl;

	}

};

class B :public A

{

public:

	virtual void print(void)

	{

		cout << "B::print()" << endl;

	};

};

class C :public B

{

public:

	virtual void print(void)

	{

		cout << "C::print()" << endl;

	}

};

void print(A a)                   //引用调用或指针调用才能覆盖

{

	a.print();

}

void main(void)

{

	A a, *pa, *pb, *pc;

	B b;

	C c;

	pa = &a;

	pb = &b;

	pc = &c;

	a.print();

	b.print();

	c.print();

	pa->print();

	pb->print();

	pc->print();

	print(a);

	print(b);

	print(c);

}
*/
/****************
#include<iostream>
using namespace std;
void fun(int i)
{
	cout << i % 10;
	i /= 10;
	if (i == 0)
	{
		return;
	}
	fun(i);
}
int main()
{
	int i;
	cin >> i;
	fun(i);
	return 0;
}
*/
/*********最长递增子序列*******************************
#include<iostream>
#include<stack>
using namespace std;
int LIS(int *a, int n)
{
	int *dp = new int[n];
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i]>len)
		{
			len = dp[i];
		}
	}
	int result = len;
	int index = n - 1;
	stack<int> st;
	while (len)
	{
		if (dp[index] == len)
		{
			st.push(a[index]);
			len--;
		}
		index--;
	}
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
	return result;
}
int main()
{
	int a[] = {2,5,3,7,22,6,8,4};
	cout << LIS(a, 8) << endl;
	return 0;
}
*/
/***最长公共子序列
#include<iostream>
#include<string>
using namespace std;
int LCS(string &str0, string &str1, string &str)
{
	int size0 = str0.size();
	int size1 = str1.size();
	int **dp = new int*[size0 + 1];
	for (int i = 0; i <= size0; i++)
	{
		dp[i] = new int[size1 + 1];
	}
	for (int i = 0; i <= size0; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j <= size1; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= size0; i++)
	{
		for (int j = 1; j <= size1; j++)
		{
			if (str0[i - 1] == str1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (dp[i-1][j]>dp[i][j-1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	int i = size0;
	int j = size1;
	str.clear();
	while (i&&j)
	{
		if (str0[i - 1] == str1[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1)
		{
			str.insert(str.begin(), str0[i - 1]);
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	int result = dp[size0][size1];
	for (int i = 0; i <= size0; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	return result;
}
int main()
{
	string str0, str1;
	cin >> str0 >> str1;
	string str;
	cout << LCS(str0, str1, str) << endl;
	cout << str << endl;
	return 0;
}
*/
/******************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i){}
private:
	int a;
};
class B1 :virtual public A
{
public:
	B1(int i, int j) :A(i), b1(j){}
private:
	int b1;
};
class B2 :virtual public A
{
public:
	B2(int i, int j) :A(i), b2(j){}
private:
	int b2;
};
class C :public B1, public B2
{
public:
	C(int i, int j, int m, int n) :A(i),B1(i, j), B2(i, m), c(n){}
private:
	int c;
};
int main()
{
	C obj(1, 2, 3, 4);
	cout << *((int*)&obj) << endl;
	cout << *((int*)&obj+1) << endl;
	cout << *((int*)&obj+2) << endl;
	cout << *((int*)&obj+3) << endl;
	cout << *((int*)&obj+4) << endl;
	cout << *((int*)&obj+5) << endl;
	return 0;
}
*/
/*******************
#include<iostream>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i)
	{
		if (size > 0)
			data = new T[size];
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
		}
	}
private:
	array(const array &obj);
	array &operator=(const array &obj);
	T *data;
	int size;
};
int main()
{
	array<int> obj(6);
	return 0;
}
*/
/*******************************
#include<iostream>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i)
	{
		if (size > 0)
			data = new T[size];
	}
	array(const array &obj) : data(NULL), size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
		}
	}
	array &operator=(const array &obj)
	{
		if (&obj == this)
		{
			return *this;
		}
		if (data != NULL)
		{
			delete[]data;
			data = NULL;
		}
		size = obj.size;
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	T &operator[](int i)
	{
		return data[i];
	}
private:
	
	
	T *data;
	int size;
};
int main()
{
	array<int> obj(6);
	for (int i = 0; i < 6; i++)
	{
		obj[i] = i;
	}
	array<int> obj1(3);
	obj1 = obj;
	for (int i = 0; i < 6; i++)
	{
		cout << obj1[i] << endl;;
	}
	array<int> obj2(obj);
	for (int i = 0; i < 6; i++)
	{
		cout << obj2[i] << endl;;
	}
	return 0;
}
*/
/****************************************
#include<iostream>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i)
	{
		if (size > 0)
			data = new T[size];
	}
	array(const array &obj) : data(NULL), size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
			data = NULL;
		}
	}
	array &operator=(const array &obj)
	{
		if (this != &obj)
		{
			array temparr = obj;     //复制一个右值
			T *temp = temparr.data;  //与左值交换成员变量
			temparr.data = data;
			data = temp;
			int tempsize = temparr.size;
			temparr.size = size;
			size = tempsize;
		}                           //原来的左值被析构
		return *this;
	}
	T &operator[](int i)
	{
		return data[i];
	}
private:


	T *data;
	int size;
};
int main()
{
	array<int> obj(6);
	for (int i = 0; i < 6; i++)
	{
		obj[i] = i;
	}
	array<int> obj1(3);
	obj1 = obj;
	for (int i = 0; i < 6; i++)
	{
		cout << obj1[i] << endl;;
	}
	array<int> obj2(obj);
	for (int i = 0; i < 6; i++)
	{
		cout << obj2[i] << endl;;
	}
	return 0;
}
*/
/*************************************
#include<iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int min(int x, int y)
{
	return (x < y) ? x : y;
}
int maxProduct(int *a, int n)
{
	int MAX = 1;
	int MIN = 1;
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>0)
		{
			MAX *= a[i];
			MIN = min(MIN*a[i], 1);
		}
		else if (a[i] == 0)
		{
			MAX = 1;
			MIN = 1;
		}
		else
		{
			int temp = MAX;
			MAX = max(MIN*a[i], 1);
			MIN = temp*a[i];
		}
		r = max(r, MAX);
	}
	return r;
}
int main()
{
	int a[] = { 1, 2, 3, -1, 8, -9,2,4,-9 };
	cout << maxProduct(a, 9) << endl;
	return 0;
}
*/
/**************************************************
#include<iostream>
using namespace std;
bool find(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != NULL&&rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row<rows&&column>=0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			else if ((matrix[row*columns + column] > number))
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}	
	return found;
}
int main()
{
	int max[16] = { 1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	cout << find(max, 4, 4, 7) << endl;
	cout << find(max, 4, 4, 5) << endl;
	return 0;
}
*/
/*******************************************
#include<iostream>
using namespace std;
void replaceBlank(char a[], int len)
{
	if (a == NULL || len <= 0)
	{
		return;
	}
	int originalLength = 0;
	int numofBlank = 0;
	int i = 0;
	while (a[i] != '\0')
	{
		originalLength++;
		if (a[i] == ' ')
		{
			numofBlank++;
		}
		i++;
	}
	int newlength = originalLength + numofBlank * 2;
	if (newlength > len)
	{
		return;
	}
	while (newlength != originalLength)
	{
		while (a[originalLength] != ' ')
		{
			a[newlength] = a[originalLength];
			newlength--;
			originalLength--;
		}
		a[newlength--] = '0';
		a[newlength--] = '2';
		a[newlength--] = '%';
		originalLength--;	
	}

//	while (newlength != originalLength)
//	{
//		if (a[originalLength] == ' ')
//		{
//			a[newlength--] = '0';
//			a[newlength--] = '2';
//			a[newlength--] = '%';
//		}
//		else
//		{
//			a[newlength--] = a[originalLength];
//		}
//		originalLength--;
//	}
}
int main()
{
	char a[100] = " hello world huang";
	replaceBlank(a, 100);
	cout << a << endl;
	return 0;
}
*/
/**************************************************************
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> strvec;
	string str;
	while (getline(cin, str))
	{
		strvec.push_back(str);
	}

	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		string::size_type size = iter->size();
		for (string::size_type i = 0; i < size - 8; i++)
		{
			if (((*iter)[i] == 'M' || (*iter)[i] == 'm') && ((*iter)[i + 1] == 'a' || (*iter)[i + 1] == 'A')
				&& ((*iter)[i + 2] == 'r' || (*iter)[i + 2] == 'R') && ((*iter)[i + 3] == 's' || (*iter)[i + 3] == 'S')
				&& ((*iter)[i+4] == 'h' || (*iter)[i+4] == 'H')&& ((*iter)[i+5] == 't' || (*iter)[i+5] == 'T')
				&& ((*iter)[i + 6] == 'o' || (*iter)[i + 6] == 'O') && ((*iter)[i + 7] == 'm' || (*iter)[i + 7] == 'M')
				&& ((*iter)[i + 8] == 'p' || (*iter)[i + 8] == 'P'))
				
			{
				iter->replace(i, 9, "fjxmlhx");
				i += 6;
			}
		}
		cout << *iter << endl;
	}
	return 0;
}
*/
/**************nim博弈*****************************
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> ivec;
	int m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		ivec.push_back(m);
	}
	int sum = 0;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		sum ^= (*iter);
	}
	if (sum == 0)
	{
		cout << "Bob" << endl;
	}
	else
	{
		cout << "Alice" << endl;
	}
	return 0;
}
*/
/**************************************
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<string> strvec;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		strvec.push_back(str);
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		while (1)
		{
			bool flag = false;
			string::iterator start = iter->begin();
			string::iterator it;
			for (it = start + 1; it != iter->end(); ++it)
			{
				if (*it != *start)
				{
					if (it - start > 1)
					{
						start = iter->erase(start, it);
						it = start;
						flag = true;
					}
					else
					{
						start = it;
					}
				}
			}
			if (it - start > 1)
			{
				iter->erase(start, it);
			}
			if (!flag)
			{
				break;
			}
		}
		cout << *iter << endl;
	}
	return 0;
}
*/
/******************************************
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isTrue(int *a)
{
	for (int i = 0; i < 7; i++)
	{
		if (a[i]<0)
		{
			return false;
		}
		while (a[i]>0)
		{
			if (a[i] >= 3)
			{
				a[i] -= 3;
			}
			else
			{
				int temp = a[i];
				a[i] = 0;
				a[i + 1] -= temp;
				a[i + 2] -= temp;
			}
		}
	}
	if ((a[7] != 0 && a[7] != 3) || (a[8] != 0 && a[8] != 3))
	{
		return false;
	}
	return true;
}
bool fun(vector<int> &ivec)
{
	int a[9] = { 0 };
	int b[9];
	if (ivec.size() == 0)
		return true;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		a[(*iter) - 1]++;
	}
	if (ivec.size() % 3 == 0)
	{
		if (!isTrue(a))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (a[i] >= 2)
			{
				for (int j = 0; j < 9; j++)
				{
					if (i == j)
					{
						b[j] = a[j]-2;
					}
					else
					{
						b[j] = a[j];
					}
				}
			}
			if (isTrue(b))
			{
				return true;
			}
		}
		return false;
	}
}
bool is7(vector<int> &vec)
{
	if (vec.size() % 2 == 1)
	{
		return false;
	}
	int a[9] = { 0 };
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		a[(*iter) - 1]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (a[i] % 2 == 1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	vector<int> Dvec;
	vector<int> Tvec;
	vector<int> Wvec;
	string str;
	vector<string> strvec;
	while (1)
	{
		cin >> str;
		if (str == "0")
		{
			break;
		}
		strvec.push_back(str);
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		Dvec.clear();
		Tvec.clear();
		Wvec.clear();
		string::size_type size = iter->size();
		for (int i = 1; i < size; i += 2)
		{
			if ((*iter)[i] == 'D')
			{
				Dvec.push_back((*iter)[i - 1] - '0');
			}
			else if ((*iter)[i] == 'T')
			{
				Tvec.push_back((*iter)[i - 1] - '0');
			}
			else if ((*iter)[i] == 'W')
			{
				Wvec.push_back((*iter)[i - 1] - '0');
			}
		}
		if (!Dvec.empty() && !Tvec.empty() && !Wvec.empty())  //三种牌都有
		{
			cout << "false" << endl;
			continue;
		}
		if (is7(Dvec) && is7(Tvec) && is7(Wvec))         //判断是否是7对
		{
			cout << "true" << endl;
			continue;
		}
		if (Dvec.size() % 3 == 1 || Tvec.size() % 3 == 1 || Wvec.size() % 3 == 1)//有一种牌的张数除以3的余数为1
		{
			cout << "false" << endl;
			continue;
		}
		if (!fun(Dvec) || !fun(Tvec) || !fun(Wvec))
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}
	}
	return 0;
}
*/
/**********迷宫问题**********************
#include<iostream>
#include<vector>
using namespace std;
const int direction[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
struct DataType
{
	int x, y, d;
};
void mazePath(int *maze[], int x0, int y0, int x1, int y1)
{
	int i, j, k;
	int g, h;
	vector<DataType> st;
	DataType element;
	maze[x0][y0] = 2;
	element.x = x0;
	element.y = y0;
	element.d = -1;
	st.push_back(element);
	while (!st.empty())
	{
		element = st.back();
		st.pop_back();
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k <= 3)
		{
			if (i + direction[k][0] > x1 || i + direction[k][0] <0 || j + direction[k][1] > y1 || j + direction[k][1] <0)
			{
				k++;
				if (k > 3)
				{
					break;
				}
			}
			g = i + direction[k][0];
			h = j + direction[k][1];
			if (maze[g][h] == 0)
			{
				maze[g][h] = 2;
				element.x = i;
				element.y = j;
				element.d = k;
				st.push_back(element);
				i = g;
				j = h;
				k = -1;
			}

			if (g == x1&&h == y1&&maze[g][h] == 2)
			{
				for (vector<DataType>::iterator iter = st.begin(); iter != st.end(); ++iter)
				{
					cout << iter->x << ',' << iter->y << endl;
					
				}
				cout << g << ',' << h << endl;
				return;
			}
			k++;
		}
	}
}
int main()
{
	int x, y;
	cin >> x >> y;
	int **maze = new int*[x];
	for (int i = 0; i < x; i++)
	{
		maze[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> maze[i][j];
		}
	}
	mazePath(maze, 0, 0, x - 1, y - 1);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout<< maze[i][j]<<' ';
		}
		cout << endl;
	}
	for (int i = 0; i < x; i++)
	{
		delete[]maze[i];
	}
	delete[]maze;
	return 0;
}
*/
/*************最大公约数**************
#include<iostream>
using namespace std;
int gys(int x, int y)
{
	return (!y) ? x : (gys(y,x%y));
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout << gys(x, y) << endl;
	}
	return 0;
}
*/
/*********不用加减乘除算两个数的和***************************
#include<iostream>
using namespace std;
int add(int x,int y)
{
	return (!y) ? x : (add(x^y, (x&y) << 1));
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout << add(x, y) << endl;
	}
	return 0;
}
*/
/**************************************************
#include<iostream>
#include<string>
using namespace std;
int result1(int x, int y)
{
	return (x - 1)*(y + 1);
}
int result2(int x, int y)
{
	return (2*x + 5)*(3*y + 60);
}
int result3(int x, int y)
{
	return (x + 1)*(2*x + 3)*(y - 1)*(2*y - 3);
}
int result4(int x, int y)
{
	return (x + y + 1)*(y - 9) + (x + 7) / (y - 8);
}
int(*f[4])(int, int) = { result1, result2, result3, result4 };
char fuhao[4] = { '@', '#', '$', '&' };
bool isFuhao(char c)
{
	return c == '@' || c == '#' || c == '$' || c == '&';
}
string inttostr(int x)
{
	string str;
	if (x == 0)
	{
		str.push_back('0');
		return str;
	}
	bool flag = false;
	if (x < 0)
	{
		flag = true;
		x = -x;
	}
	while (x)
	{
		str.insert(str.begin(), x % 10 + '0');
		x /= 10;
	}
	if (flag)
	{
		str.insert(str.begin(), '-');
	}
	return str;
}
int fun(string &str)
{
	for (int i = 0; i < 4; i++)
	{
		string::size_type start = 0;
		
		
		while (1)
		{
			string::size_type pos = str.find(fuhao[i], start);
			if (pos == string::npos)
			{
				break;
			}
			string::size_type m = pos - 1;
			int first = 0;
			int second = 0;
			int t = 1;
			while (!isFuhao(str[m]) && m > 0)
			{
				if (str[m] >= '0'&&str[m] <= '9')
				{
					first += ((str[m] - '0')*t);
				}
				if (str[m] == '-')
				{
					first = first - 2 * first;
				}
				m--;
			}
			if (str[m] >= '0'&&str[m] <= '9'&&m==0)
			{
				first += ((str[m] - '0')*t);
			}
			if (str[m] == '-'&&m == 0)
			{
				first = first - 2 * first;
			}
			if (m!=0)
			{
				m++;
			}
			string::size_type n = pos + 1;
			bool flag = false;
			while (!isFuhao(str[n]) && n < str.size() - 1)
			{
				if (str[n] >= '0'&&str[n] <= '9')
				{
					second *= 10;
					second+=(str[n] - '0');
				}
				if (str[n] == '-')
				{
					flag = true;
				}
				n++;
			}
			if (str[n] >= '0'&&str[n] <= '9'&&n == str.size() - 1)
			{
				second *= 10;
				second += (str[n] - '0');
			}
			if (flag)
			{
				second = second - 2 * second;
			}
			if (n == str.size() - 1)
			{
				n++;
			}
			str.erase(m, n - m);
			if (str.size() == 0)
				return f[i](first, second);
			str.insert(m, inttostr(f[i](first,second)));
			start = m;
		}
		
	}
	return -1;
}
int main()
{
	string str;
	getline(cin, str);
	cout << fun(str) << endl;
	return 0;
}
*/
/***********火星计算器堆栈实现**************************
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isFuhao(char c)
{
	return c == '@' || c == '#' || c == '$' || c == '&';
}
bool cmp(char first, char second)
{
	bool flag = false;
	switch (first)
	{
	case '@':
		flag = true;
		break;
	case '#':
		if (second != '@')
			flag = true;
		break;
	case '$':
		if (second == '$' || second == '&')
			flag = true;
		break;
	case '&':
		if (second == '&')
			flag = true;
		break;
	default:
		break;
	}
	return flag;
}
int jisuan(int x, int y, char fuhao)
{
	int result;
	switch (fuhao)
	{
	case '@':
		result = (x - 1)*(y + 1);
		break;
	case '#':
		result = (2 * x + 5)*(3 * y + 60);
		break;
	case '$':
		result = (x + 1)*(2 * x + 3)*(y - 1)*(2 * y - 3);
		break;
	case '&':
		result = (x + y + 1)*(y - 9) + (x + 7) / (y - 8);
		break;
	default:
		break;
	}
	return result;
}
int fun(string &str)
{
	stack<int> iStack;
	stack<char> cStack;
	string::size_type size = str.size();
	int sum = 0;
	for (string::size_type i = 0; i < size; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			sum *= 10;
			sum += str[i] - '0';
		}
		else if (isFuhao(str[i]))
		{
			iStack.push(sum);
			sum = 0;
			while (!cStack.empty() && cmp(cStack.top(), str[i]))
			{
				int y = iStack.top();
				iStack.pop();
				int x = iStack.top();
				iStack.pop();
				iStack.push(jisuan(x, y, cStack.top()));
				cStack.pop();
			}
			cStack.push(str[i]);
		}
	}
	iStack.push(sum);
	while (!cStack.empty())
	{
		int y = iStack.top();
		iStack.pop();
		int x = iStack.top();
		iStack.pop();
		iStack.push(jisuan(x, y, cStack.top()));
		cStack.pop();
	}
	return iStack.top();
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << fun(str) << endl;
	}
	return 0;
}
*/
/********火车售票系统*****************
#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main()
{
	map<pair<int, int>, int> ticketMap;
	typedef map<pair<int, int>, int>::iterator map_it_type;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sums;
	cin >> sums;
	ticketMap[make_pair(1, n)] = sums;
	string str;
	int start, end;
	while (cin >> str >> start >> end)
	{
		int i;
		for ( i= 0; i < n; i++)
		{
			if (start == a[i])
			{
				start = i + 1;
				break;
			}
		}
		if (i == n)
		{
			if (str == "FindLeftTickets")
				cout << 0 << endl;
			else if (str == "SellTicket")
				cout << -1 << endl;
			continue;
		}
		for (i = 0; i < n; i++)
		{
			if (end == a[i])
			{
				end = i + 1;
				break;
			}
		}
		if (i == n)
		{
			if (str == "FindLeftTickets")
				cout << 0 << endl;
			else if (str == "SellTicket")
				cout << -1 << endl;
			continue;
		}
		if (str == "FindLeftTickets")
		{
			int leftNum = 0;
			if (start >= end)
			{
				cout << 0 << endl;
				continue;
			}
			for (map_it_type iter = ticketMap.begin(); iter != ticketMap.end(); ++iter)
			{
				if (iter->first.first <= start&&iter->first.second >= end)
				{
					leftNum += iter->second;
				}
			}
			cout << leftNum << endl;
		}
		else if (str == "SellTicket")
		{
			if (start >= end)
			{
				cout << -1 << endl;
				continue;
			}
			map_it_type it;
			int startbuf = start;
			int endbuf;
			while (startbuf != 0)
			{
				endbuf = end;
				while (endbuf <= n)
				{
					it = ticketMap.find(make_pair(startbuf, endbuf));
					if (it != ticketMap.end())
					{
						break;
					}
					endbuf++;
				}
				if (it != ticketMap.end())
				{
					break;
				}
				startbuf--;
			}
			if (it != ticketMap.end())
			{
				if (it->second <= 1)
				{
					ticketMap.erase(it);
				}
				else
				{
					it->second--;
				}
				if (startbuf < start)
				{
					ticketMap[make_pair(startbuf, start)]++;
				}
				if (endbuf>end)
				{
					ticketMap[make_pair(end, endbuf)]++;
				}
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}
*/
/************最大递增子序列****************
#include<iostream>
using namespace std;
int LIS(int *a, int n)
{
	int *dp = new int[n];
	int max = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i]>a[j] && dp[j] + 1>dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	return max;
}
int main()
{
	int a[] = { 3, 5, 8, 2, 5, 6, 7, 8 };
	cout << LIS(a, sizeof(a) / sizeof(int)) << endl;
}
*/
/*************最大公共子序列**********************************
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str0, str1;
	cin >> str0 >> str1;
	string::size_type len0 = str0.size();
	string::size_type len1 = str1.size();
	int **dp = new int*[len0 + 1];
	int i, j;
	for (i = 0; i <= len0; i++)
	{
		dp[i] = new int[len1 + 1];
	}
	for (i = 0; i <= len0; i++)
	{
		dp[i][0] = 0;
	}
	for (j = 0; j <= len1; j++)
	{
		dp[0][j] = 0;
	}
	for (i = 1; i <= len0; i++)
	{
		for (j = 1; j <= len1; j++)
		{
			if (str0[i - 1] == str1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (dp[i - 1][j] >= dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	cout << dp[len0][len1] << endl;
	i = len0;
	j = len1;
	string strbuf;
	while (i&&j)
	{
		if (str0[i - 1] == str1[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1)
		{
			strbuf.insert(strbuf.begin(), str0[i - 1]);
			i--;
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	cout << strbuf << endl;
	for (i = 0; i <= len0; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	return 0;
}
*/
/************栈、队列的C++实现，以及二叉树的各种遍历**********************
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
typedef struct BinTreeNode *Tree;
template<typename T>
class stack
{
public:
	stack(int n=100);
	
	~stack();
	
	bool empty();
	bool full();
	void push(const T &x);
	void pop();
	T top();
private:
	stack(const stack &obj);
	stack &operator=(const stack &obj);
	int MAXNUM;
	int t;
	T *data;
};

template<typename T>
stack<T>::stack(int n = 100)
{
	data = new T[n];
	if (data)
	{
		MAXNUM = n;
		t = -1;
	}
}
template<typename T>
stack<T>::~stack()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
bool stack<T>::empty()
{
	return t == -1;
}
template<typename T>
bool stack<T>::full()
{
	return t + 1 == MAXNUM;
}
template<typename T>
void stack<T>::push(const T &x)
{
	if (full())
	{
		return;
	}
	data[++t] = x;
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	t--;
}
template<typename T>
T stack<T>::top()
{
	if (empty())
	{
		return T();
	}
	return data[t];
}

template<typename T>
class queue
{
public:
	queue(int n = 100);
	~queue();
	bool empty();
	bool full();
	void push(const T &x);
	void pop();
	T front();
private:
	queue(const queue &obj);
	queue &operator=(const queue &obj);
	int MAXNUM;
	int f, r;
	T *data;
};

template<typename T>
queue<T>::queue(int n = 100)
{
	data = new T[n];
	if (data)
	{
		MAXNUM = n;
		f = 0;
		r = 0;
	}
}
template<typename T>
queue<T>::~queue()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
bool queue<T>::empty()
{
	return f == r;
}
template<typename T>
bool queue<T>::full()
{
	return ((r + 1) % MAXNUM) == f;
}
template<typename T>
void queue<T>::push(const T &x)
{
	if (full())
	{
		return;
	}
	data[r] = x;
	r = ((r + 1) % MAXNUM);
}
template<typename T>
void queue<T>::pop()
{
	if (empty())
	{
		return;
	}
	f = (f + 1) % MAXNUM;
}
template<typename T>
T queue<T>::front()
{
	if (empty())
	{
		return T();
		cout << "huang" << endl;
	}
	return data[f];
}
void createTree(Tree *pt)
{
	if (pt == NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*pt = new BinTreeNode;
	(*pt)->info = tmp;
	(*pt)->llink = NULL;
	(*pt)->rlink = NULL;
	createTree(&(*pt)->llink);
	createTree(&(*pt)->rlink);
}
void destroyTree(Tree *pt)
{
	if (pt == NULL || *pt == NULL)
	{
		return;
	}
	destroyTree(&(*pt)->llink);
	destroyTree(&(*pt)->rlink);
	delete *pt;
	*pt = NULL;
}
void preOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->info << ' ';
	preOrder(t->llink);
	preOrder(t->rlink);
}
void nPreOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Tree> ts;
	Tree p = t;
	ts.push(p);
	while (!ts.empty())
	{
		p = ts.top();
		ts.pop();
		if (p != NULL)
		{
			cout << p->info << ' ';
			ts.push(p->rlink);
			ts.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	inOrder(t->llink);
	cout << t->info << ' ';
	inOrder(t->rlink);
}
void nInOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Tree> ts;
	Tree p = t;
	while (p != NULL || !ts.empty())
	{
		while (p != NULL)
		{
			ts.push(p);
			p = p->llink;
		}
		p = ts.top();
		ts.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	postOrder(t->llink);
	postOrder(t->rlink);
	cout << t->info << ' ';
}
void nPostOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Tree> st;
	Tree p = t;
	Tree pp;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
struct Node
{
	int tag;
	Tree t;
};
void nPostOrder1(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	stack<Node> ns;
	Node pnode;
	Tree p = t;
	while (p != NULL || !ns.empty())
	{
		while (p != NULL)
		{
			pnode.tag = 1;
			pnode.t = p;
			ns.push(pnode);
			p = p->llink;
		}
		pnode = ns.top();
		ns.pop();
		p = pnode.t;
		if (pnode.tag == 1)
		{
			pnode.tag = 2;
			ns.push(pnode);
			p = p->rlink;
		}
		else
		{
			cout << p->info << ' ';
			p = NULL;
		}
	}
	cout << endl;
}
void guangduOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	queue<Tree> tq;
	Tree q = t;
	Tree qq;
	tq.push(q);
	while (!tq.empty())
	{
		q = tq.front();
		tq.pop();
		cout << q->info << ' ';
		qq = q->llink;
		if (qq != NULL)
		{
			tq.push(qq);
		}
		qq = q->rlink;
		if (qq != NULL)
		{
			tq.push(qq);
		}
	}
	cout << endl;
}
int main()
{
	Tree myTree;
	createTree(&myTree);
	preOrder(myTree);
	cout << endl;
	nPreOrder(myTree);

	inOrder(myTree);
	cout << endl;
	nInOrder(myTree);

	postOrder(myTree);
	cout << endl;
	nPostOrder(myTree);
	nPostOrder1(myTree);

	guangduOrder(myTree);
	destroyTree(&myTree);
	return 0;
}
*/
/**********************************
#include<iostream>
using namespace std;
class A
{
public:
	int a;
};
class B :public A
{
public:
	int b;
};
int main()
{
	B obj;
	obj.a = 100;
	return 0;
}
*/
/********************************************
#include<iostream>
using namespace std;
template<typename T,int dim>
class point
{
public:
	point()
	{
	}
	point(T coord[dim])
	{
		for (int i = 0; i < dim; i++)
		{
			_coord[i] = coord[i];
		}
	}
	T &operator[](int index)
	{
		return _coord[index];
	}
	T operator[](int index) const
	{
		return _coord[index];
	}
private:
	T _coord[dim];
};
template<typename T,int dim>
ostream &operator<<(ostream &os, const point<T, dim> &obj)
{
	os << '(';
	for (int i = 0; i < dim - 1; i++)
		os << obj[i] << ',';                  //上面的const[]函数必须有 否则会出问题
	os << obj[dim - 1] << ')';
	return os;
}
int main()
{
	point<int,3> obj;
	obj[0] = 1; obj[1] = 2; obj[2] = 3;
	cout << obj << endl;
	return 0;
}
*/
/******************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0) :a(i)
	{}
	virtual void f()
	{
		cout << "f() in A" << endl;
	}
private:
	int a;
};
int main()
{
	typedef void(*pF)();
	A obj(1),obj1(2);
	cout << *((int*)&obj) << endl;
	cout << *((int*)&obj + 1) << endl;
	cout << *((int*)&obj1) << endl;
	cout << *((int*)&obj1 + 1) << endl;
	pF p = (pF)*((int*)*((int*)&obj));
	(*p)();
	p = (pF)*((int*)*((int*)&obj1));
	(*p)();
	return 0;
}
*/
/**********************************
#include<iostream>
using namespace std;
class A
{
public:
	virtual void f()
	{
		cout << "f() in A" << endl;
	}
};
class B :public A
{
public:
	void f()
	{
		cout << "f() in B" << endl;
	}
};
void fun(A obj0, A &obj1, A *p)
{
	obj1.f();
	p->f();
	obj0.f();
}
int main()
{
	B obj;
	fun(obj, obj, &obj);
	return 0;
}
*/
/******************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i){}
	
private:
	int a;
};
class B :public A
{
public:
	B(int i, int j) :A(i), b(j){}
	virtual void f()
	{
		cout << "f() in B" << endl;
	}
private:
	int b;
};
int main()
{
	B obj(1, 2);
	cout << *((int*)&obj) << endl;
	cout << *((int*)&obj+1) << endl;
	cout << *((int*)&obj+2) << endl;
	return 0;
}
*/
/***************************************
#include<iostream>
using namespace std;
class Base
{
public:
	Base(int i=0) :b(i){}
	void display()
	{
		cout << b << endl;
	}
private:
	int b;
};
class A
{
public:
	void display()
	{
		bobj.display();
	}
private:
	Base bobj;
};
int main()
{
	A obj;
	obj.display();
	return 0;
}
*/
/*******************************
#include<iostream>
using namespace std;
class A
{
};
class B1 :virtual public A
{
};
class B2 :virtual public A
{};
class C :public B1, public B2
{};
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B1) << endl;
	cout << sizeof(B2) << endl;
	cout << sizeof(C) << endl;
	return 0;
}
*/
/*******************************
#include<iostream>
using namespace std;
class A
{
public:
private:
	int a;
	char c;
};
class A1 :public A
{
public:
private:
	char c1;
};
class A2 :public A1
{
public:
private:
	char c2;
};
int main()
{
	cout << sizeof(A2) << endl;
	return 0;
}
*/
/********************************
#include<iostream>
using namespace std;
class A
{
public:
	virtual void f()
	{}

	int x, y, z;
};
int main()
{
	printf("%d\n",&A::x);
	printf("%d\n",&A::y);
	printf("%d\n",&A::z);
	return 0;
}
*/
/****************
#include<iostream>
using namespace std;
class A1
{
public:
	virtual ~A1()
	{
		cout << "~A1" << endl;
	}
private:
};
class A2
{
public:
	virtual ~A2()
	{
		cout << "~A2" << endl;
	}
private:
};
class B :public A1, public A2
{
public:
private:
	virtual ~B()
	{
		cout << "~B" << endl;
	}
};
int main()
{
	A1 *pA1 = new B;
	delete pA1;
	return 0;
}
*/
/****************************
#include<iostream>
using namespace std;
//==直接插入排序==============================
void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (a[j]>k&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

//=====希尔排序=================================
void shellInsert(int *a, int n, int k)
{
	for (int i = k; i < n; i++)
	{
		int x = a[i];
		int j = i - k;
		while (a[j]>x&&j >= 0)
		{
			a[j + k] = a[j];
			j -= k;
		}
		a[j + k] = x;
	}
}
void shellSort(int *a, int n)
{
	int k = n / 2;
	while (k)
	{
		shellInsert(a, n, k);
		k /= 2;
	}
}
//==========选择排序================================	
void SelectSort(int *a, int n)
{
	int k;
	for (int i = 0; i<n - 1; i++)
	{
		k = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}
//===========堆排序=====================================
void sift(int *a, int n, int i)
{
	int child;
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[i] < a[child])
		{
			int temp = a[i];
			a[i] = a[child];
			a[child] = temp;
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		sift(a, n, i);
	}
	for (i = n - 1; i > 0; i--)
	{
		a[0] = a[0] ^ a[i];
		a[i] = a[0] ^ a[i];
		a[0] = a[0] ^ a[i];
		sift(a, i, 0);
	}
}

//=======快速排序============================================================
void QSort(int *a, int n)
{
	int i = 0;
	int j = n - 1;
	int k = a[0];
	if (n > 1)     //这玩意不能丢啊
	{
		while (i < j)
		{
			for (; i < j; j--)
			{
				if (a[j] < k)
				{
					a[i++] = a[j];
					break;                  //这玩意不能忘了啊
				}
			}
			for (; i < j; i++)
			{
				if (a[i]>k)
				{
					a[j--] = a[i];
					break;               //这玩意不能忘了啊
				}
			}
		}
		a[i] = k;
		QSort(a, i);
		QSort(a + i + 1, n - i - 1);
	}
}

//========起泡排序==============================
void bubbleSort(int *a, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int i;
	int num[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//insertSort(num, sizeof(num) / sizeof(int));   //时间复杂度：O（n^2）.
	//shellSort(num, sizeof(num) / sizeof(int));

	//SelectSort(num, sizeof(num) / sizeof(int));
	//heapSort(num, sizeof(num) / sizeof(int));

	QSort(num, sizeof(num) / sizeof(int));
	//bubbleSort(num, sizeof(num) / sizeof(int));
	for (i = 0; i<sizeof(num) / sizeof(int); i++)
	{
		cout << num[i] << endl;
	}
	return 0;
}
*/
/*************栈实现火车进出站******************
#include <stdio.h>
#include <malloc.h>
#define STACK_SIZE 20
typedef struct{
	int stack[STACK_SIZE];
	int top;
}SqStack;
int count = 1;
bool InitStack(SqStack &S)
{
	S.top = -1;
	return true;
}
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return true;
	}
	else
		return false;
}

bool ClearStack(SqStack &S)
{
	S.top = -1;
	return true;
}

int StackLength(SqStack S)
{
	return S.top + 1;
}

bool GetTop(SqStack &S, int &e)
{
	if (S.top == 0)
	{
		return false;
	}
	e = S.stack[S.top];
	return true;
}

bool Push(SqStack &S, int e)
{
	if (S.top >= STACK_SIZE - 1)
	{
		return false;
	}
	S.top++;
	S.stack[S.top] = e;
	return true;
}
int Pop(SqStack &S)
{
	int e;
	if (S.top == -1)
	{
		return -1;
	}
	e = S.stack[S.top];
	S.top--;
	return e;
}

int e;
void InOutStack(SqStack &input, SqStack &S, SqStack &output)
{
	if (StackEmpty(S) && StackEmpty(input))
	{
		int i;
		printf("%4d     |     ", count++);
		for (i = 0; i <= output.top; i++)
		{
			printf("%d ", output.stack[i]);
		}
		printf("\n");
	}
	else
	{
		if (!StackEmpty(input))
		{
			Push(S, Pop(input));
			InOutStack(input, S, output);
			Push(input, Pop(S));
		}
		if (!StackEmpty(S))
		{
			Push(output, Pop(S));
			InOutStack(input, S, output);
			Push(S, Pop(output));
		}
	}
}

int main()
{
	SqStack S, input, output;
	InitStack(S);
	InitStack(input);
	InitStack(output);
	int n = 1;
	printf("请输入列车数(1-6)：");
	scanf_s("%d", &n);
	int i;
	for (i = n; i>0; i--)
	{
		Push(input, i);
	}
	printf("情况序号    出站次序情况\n");
	InOutStack(input, S, output);
	return 0;
}
*/
/*********************
#include<iostream>
#include<vector>
using namespace std;
int main()

try
{
	vector<int> ivec;
	cout << ivec[0] << endl;
	return 0;
}
	catch (out_of_range)
	{
		cout << "out of range" << endl;
	}
*/
/******************************
#include<iostream>
#include<string>

using namespace std;
int main()
{
	ostream_iterator<string> oo(cout);
	*oo = "huang";
	oo++;
	*oo = "hua";
}
*/
/**************
#include<iostream>
using namespace std;
int main()
{
	wchar_t c = L'a';
	cout << sizeof(wchar_t) << endl;
	cout << c << endl;
	return 0;
}
*/
/************************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
		}
	}
	T &operator[](int index)
	{
		return data[index];
	}
private:
	array(const array &obj);
	array &operator=(const array &obj);
	T *data;
	int size;
};
int main()
{
	array<string> strArray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> strArray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << strArray[i] << endl;
	}
	//array<string> strA = strArray;
	return 0;
}
*/
/**********************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i=0) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(NULL),size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	array &operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		delete []data;
		data = NULL;
		size = obj.size;
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
		return *this;
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
		}
	}
	T &operator[](int index)
	{
		return data[index];
	}
private:

	T *data;
	int size;
};
int main()
{
	array<string> strArray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> strArray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << strArray[i] << endl;
	}
	array<string> strA;
	strA= strArray;
	for (int i = 0; i < 5; i++)
	{
		cout << strA[i] << endl;
	}
	return 0;
}
*/
/****************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(NULL), size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	array &operator=(const array &obj)
	{
		if (this != &obj)
		{
			array arraytmp(obj);
		
			T *tmp = data;
			data = arraytmp.data;
			arraytmp.data = tmp;
			int t = size;
			size = arraytmp.size;
			arraytmp.size = t;
		}
		return *this;
	}
	~array()
	{
		if (data != NULL)
		{
			delete[]data;
		}
	}
	T &operator[](int index)
	{
		return data[index];
	}
private:

	T *data;
	int size;
};
int main()
{
	array<string> strArray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> strArray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << strArray[i] << endl;
	}
	array<string> strA;
	strA = strArray;
	for (int i = 0; i < 5; i++)
	{
		cout << strA[i] << endl;
	}
	return 0;
}
*/
/**************************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i=0) : data(NULL), size(i), count(new int)
	{
		++(*count);
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(obj.data), size(obj.size), count(data.count)
	{
		++(*count);
	}
	array &operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		Release();
		data = obj.data;
		size = obj.size;
		count = obj.count;
		++(*count);
	}
	T &operator[](int index)
	{
		return data[index];
	}
	~array()
	{
		Release();
	}
private:
	void Release()
	{
		--(*count);
		if (*count == 0)
		{
			if (data)
			{
				delete data;
			}
			delete count;
		}
	}
	int *count;
	int size;
	T *data;
};
int main()
{
	array<string> strarray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> strarray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << strarray[i] << endl;
	}
	array<string> strarray1;
	strarray1 = strarray;
	for (int i = 0; i < 5; i++)
	{
		cout << strarray1[i] << endl;
	}
	return 0;
}
*/
/**************************************
#include<iostream>
using namespace std;
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int fun(int a[][6], int m, int n)
{
	int **dp = new int*[m+1];
	for (int i = 0; i <= m; i++)
	{
		dp[i] = new int[n+1];
	}
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = a[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}
int main()
{
	int array[7][6] = { 5, 8, 5, 7, 1, 8,
						1, 3, 2, 8, 7, 9,
						7, 8, 6, 6, 8, 7,
						9, 9, 8, 1, 6, 3,
						2, 4, 10, 2, 6, 2,
						5, 5, 2, 1, 8, 8,
						5, 9, 2, 6, 8, 3 };
	cout << fun(array, 7, 6) << endl;
	return 0;
}
*/
/********************************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	T &operator[](int index)
	{
		return data[index];
	}
	~array()
	{
		if (data)
		{
			delete[]data;
		}
	}
private:
	array(const array &obj);
	array &operator=(const array &obj);
	int size;
	T *data;
};
int main()
{
	array<string> stray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> stray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << stray[i] << endl;
	}
	array<string> stray0;
	//stray0 = stray;
	return 0;
}
*/
/*****************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(obj.data), size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	array &operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		delete[]data;
		data = obj.data;
		size = obj.size;
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
		return *this;
	}
	T &operator[](int index)
	{
		return data[index];
	}
	~array()
	{
		if (data)
		{
			delete[]data;
		}
	}
private:
	int size;
	T *data;
};
int main()
{
	array<string> stray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> stray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << stray[i] << endl;
	}
	array<string> stray0;
	stray0 = stray;
	return 0;
}
*/
/********************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0) : data(NULL), size(i), count(new int)
	{
		*count = 1;
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(obj.data), size(obj.size), count(obj.count)
	{
		++(*count);
	}
	array &operator=(const array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		Release();
		data = obj.data;
		size = obj.size;
		count = obj.count;
		++(*count);
		return *this;
	}
	T &operator[](int index)
	{
		return data[index];
	}
	~array()
	{
		Release();
	}
private:
	void Release()
	{
		--(*count);
		if (*count == 0)
		{
			if (data)
			{
				delete[]data;
			}
			delete count;
		}
	}
	int *count;
	int size;
	T *data;
};
int main()
{
	array<string> stray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> stray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << stray[i] << endl;
	}
	array<string> stray0;
	stray0 = stray;
	return 0;
}
*/
/**************************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0) : data(NULL), size(i)
	{
		if (size > 0)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : data(obj.data), size(obj.size)
	{
		if (size > 0)
		{
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	array &operator=(const array &obj)
	{
		if (this != &obj)
		{
			array buf(obj);
			T *tmp = data;
			data = buf.data;
			buf.data = tmp;
			int sizetmp = size;
			size = buf.size;
			buf.size = sizetmp;
		}
		return *this;
	}
	T &operator[](int index)
	{
		return data[index];
	}
	~array()
	{
		if (data)
		{
			delete[]data;
		}
	}
private:
	int size;
	T *data;
};
int main()
{
	array<string> stray(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> stray[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << stray[i] << endl;
	}
	array<string> stray0;
	stray0 = stray;
	return 0;
}
*/
/************二叉排序树******************************
#include<iostream>
//#include<stack>
//#include<queue>
using namespace std;
struct BinSearchNode
{
	int key;
	BinSearchNode *llink,*rlink;
};
typedef BinSearchNode *BinSearchTree;
//C++实现栈
template<typename T>
class stack
{
public:
	stack(int i = 100);
	~stack();
	bool full();
	bool empty();
	void push(const T &obj);
	T top();
	void pop();
private:
	stack(const stack &obj);
	stack &operator=(const stack &obj);
	int MAXNUM;
	int t;
	T *data;
};
template<typename T>
stack<T>::stack(int i = 100)
{
	data = new T[i];
	if (data)
	{
		MAXNUM = i;
		t = -1;
	}
}
template<typename T>
stack<T>::~stack()
{
	if (data)
	{
		delete []data;
	}
}
template<typename T>
bool stack<T>::full()
{
	return t + 1 == MAXNUM;
}
template<typename T>
bool stack<T>::empty()
{
	return t == -1;
}
template<typename T>
void stack<T>::push(const T &obj)
{
	if (full())
	{
		cout << "full stack" << endl;
		return;
	}
	data[++t] = obj;
}
template<typename T>
T stack<T>::top()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return T();
	}
	return data[t];
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return;
	}
	t--;
}
//C++实现队列
template<typename T>
class queue
{
public:
	queue(int i = 100);
	~queue();
	bool full();
	bool empty();
	void push(const T &obj);
	T front();
	void pop();
private:
	queue(const queue &obj);
	queue &operator=(const queue &obj);
	int MAXNUM;
	int f, r;
	T *data;
};
template<typename T>
queue<T>::queue(int i = 100)
{
	data = new T[i];
	if (data)
	{
		MAXNUM = i;
		f = 0;
		r = 0;
	}
}
template<typename T>
queue<T>::~queue()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
bool queue<T>::full()
{
	return (r + 1) % MAXNUM == f;
}
template<typename T>
bool queue<T>::empty()
{
	return f == r;
}
template<typename T>
void queue<T>::push(const T &obj)
{
	if (full())
	{
		cout << "full queue" << endl;
		return;
	}
	data[r] = obj;
	r = (r + 1) % MAXNUM;
}
template<typename T>
T queue<T>::front()
{
	if (empty())
	{
		cout << "empty queue" << endl;
		return T();
	}
	return data[f];
}
template<typename T>
void queue<T>::pop()
{
	if (empty())
	{
		cout << "empty queue" << endl;
		return;
	}
	f = (f + 1) % MAXNUM;
}
//二叉排序树中寻找指定元素
int search(BinSearchTree *ptree, int key, BinSearchNode **position)
{
	if (ptree == NULL)            //传进来的是空指针
	{
		return -1;
	}
	BinSearchNode *p, *q;
	p = *ptree; q = p;
	while (p != NULL)
	{
		q = p;
		if (p->key == key)
		{
			*position = p;
			return 1;
		}
		else if (p->key > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	*position = q;
	return 0;
}
//二叉排序树中插入指定元素
int insert(BinSearchTree *ptree, int key)
{
	if (ptree == NULL)            //如果传入的指针是空
	{
		return -1;
	}
	BinSearchNode *position;
	if (search(ptree, key, &position) == 1)    //树中已有该元素
	{
		return 0;                            
	}
	BinSearchNode *p = new BinSearchNode;
	if (p == NULL)
	{
		return 0;
	}
	p->key = key;
	p->llink = p->rlink = NULL;
	if (position == NULL)           //表示树为空
	{
		*ptree = p;
	}
	else if (position->key>key)
	{
		position->llink = p;
	}
	else
	{
		position->rlink = p;
	}
}
//生成二叉排序树
int createBinSearch(BinSearchTree *ptree)
{
	int i;
	if (ptree == NULL)              //如果传入的是空指针
	{
		return 0;
	}
	while (cin >> i)
	{
		insert(ptree, i);          //插入元素
	}
	return 1;
}
//销毁二叉排序树
void destroyBinSearch(BinSearchTree *ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyBinSearch(&(*ptree)->llink);
	destroyBinSearch(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
//删除二叉排序树中指定元素
int deleteNode(BinSearchTree *ptree, int key)
{
	BinSearchNode *p, *parentp, *r;
	if (ptree == NULL)
	{
		return -1;
	}
	p = *ptree;
	parentp = NULL;
	while (p != NULL)
	{
		if (p->key == key)
		{
			break;
		}
		parentp = p;
		if (p->key > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	if (p == NULL)                     //未找到指定元素
	{
		return 0;
	}
	if (p->llink == NULL)
	{
		if (parentp == NULL)
		{
			*ptree = p->rlink;
		}
		else if (parentp->rlink == p)
		{
			parentp->rlink = p->rlink;
		}
		else
		{
			parentp->llink = p->rlink;
		}
	}
	else
	{
		r = p->llink;
		while (r->rlink != NULL)
		{
			r = r->rlink;
		}
		r->rlink = p->rlink;
		if (parentp == NULL)
		{
			*ptree = p->llink;
		}
		else if (parentp->rlink == p)
		{
			parentp->rlink = p->llink;
		}
		else
		{
			parentp->llink = p->llink;
		}
	}
	delete p;
	return 1;
}
//先根周游递归算法
void preOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->key << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
//先根周游非递归算法
void nPreOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchTree> st;
	BinSearchTree p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != NULL)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
//对称周游递归算法
void inOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->key << ' ';
	inOrder(tree->rlink);
}
//对称周游非递归算法
void nInOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchTree> st;
	BinSearchTree p = tree;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
//后根周游递归
void postOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->key << ' ';
}
//后根周游非递归
void nPostOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchTree> st;
	BinSearchTree p, pp;
	p = tree;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
//后根周游非递归1
struct Elem
{
	int tag;
	BinSearchTree tree;
};
void nPostOrder1(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<Elem> st;
	BinSearchTree p = tree;
	Elem pnode;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			pnode.tag = 1;
			pnode.tree = p;
			st.push(pnode);
			p = p->llink;
		}
		pnode = st.top();
		st.pop();
		p = pnode.tree;
		if (pnode.tag == 1)
		{
			pnode.tag = 2;
			st.push(pnode);
			p = p->rlink;
		}
		else
		{
			cout << p->key << ' ';
			p = NULL;
		}
	}
	cout << endl;
}
//广度优先周游
void guangduOrder(BinSearchTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	queue<BinSearchTree> qu;
	BinSearchNode *q = tree, *qq;
	qu.push(q);
	while (!qu.empty())
	{
		q = qu.front();
		qu.pop();
		cout << q->key << ' ';
		qq = q->llink;
		if (qq)
		{
			qu.push(qq);
		}
		qq = q->rlink;
		if (qq)
		{
			qu.push(qq);
		}
	}
	cout << endl;
}
int main()
{
	BinSearchTree tree = NULL;
	createBinSearch(&tree);

	preOrder(tree);
	cout << endl;
	nPreOrder(tree);

	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	nPostOrder1(tree);

	guangduOrder(tree);

	destroyBinSearch(&tree);
	return 0;
}
*/

/**********************************************
#include<iostream>
using namespace std;
struct LinkNode
{
	int info;
	LinkNode *next;
};
typedef LinkNode *Link;
//创建链表
void createLink(Link *pLink)
{
	int i;
	LinkNode *p,*q=NULL;
	if (pLink == NULL)
	{
		return;
	}
	if (*pLink != NULL)
	{
		return;
	}
	while (cin >> i)
	{
		p = new LinkNode;
		p->info = i;
		p->next = NULL;
		if (*pLink == NULL)
		{
			*pLink = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
}
//销毁链表
void destroyLink(Link *pLink)
{
	if (pLink == NULL || *pLink == NULL)
	{
		return;
	}
	LinkNode *p = *pLink;
	while (p->next != NULL)
	{
		p = p->next;
		delete *pLink;
		*pLink = p;
	}
	delete *pLink;
	*pLink = NULL;
}
//删除链表的倒数第k个结点
void deleteNodeK(Link *pLink, int k)
{
	if (pLink == NULL || *pLink == NULL)
	{
		return;
	}
	if (k <= 0)
	{
		return;
	}
	LinkNode *p = *pLink;
	LinkNode *q = p;
	LinkNode *r = NULL;
	for (int i = 0; i < k-1; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			break;
		}
	}
	if (p == NULL)
	{
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		r = q;
		q = q->next;
	}
	if (q == *pLink)
	{
		*pLink = q->next;
	}
	else
	{
		r->next = q->next;
	}
	delete q;
}
//依次打印链表
void displayLink(Link mlink)
{
	while (mlink != NULL)
	{
		cout << mlink->info << ' ';
		mlink = mlink->next;
	}
	cout << endl;
}

int main()
{
	Link myLink = NULL;
	deleteNodeK(&myLink, 5);
	createLink(&myLink);
	displayLink(myLink);

	deleteNodeK(&myLink, 5);
	displayLink(myLink);

	destroyLink(&myLink);
	return 0;
}
*/

/**************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0) :a(i){}
	A(A obj):a(obj.a)                          //编译出错
	{}
	void display()
	{
		cout << a << endl;
	}
private:
	int a;
};
int main()
{
	A obj;
	A obj1 = obj;
	obj.display();
	obj1.display();
	return 0;
}
*/
/***********************************************************
#include<iostream>
using namespace std;
bool find(int *matrix, int rows, int columns, int key)
{
	bool found = false;
	if (matrix != NULL&&rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows&&column >= 0)
		{
			if (matrix[row*columns + column] == key)
			{
				return true;
			}
			else if (matrix[row*columns + column]>key)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return found;
}
int main()
{
	int a[16] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	cout << find(a, 4, 4,9) << endl;
	return 0;
}
*/
/*************************************************
#include<iostream>
using namespace std;
void replaceSpace(char String[], int length)
{
	if (String == NULL || length <= 0)
	{
		return;
	}
	int q = 0, p = 0;
	while (String[q] != '\0')
	{
		if (String[q] == ' ')
		{
			p++;
		}
		q++;
	}
	p *= 2;
	p += q;
	p++;
	q++;
	if (p >= length)
	{
		return;
	}
	while (p!=q)
	{
		p--;
		q--;
		while (String[q] != ' ')
		{
			String[p] = String[q];
			p--;
			q--;
		}
		String[p--] = '0';
		String[p--] = '2';
		String[p] = '%';
	}
}
int main()
{
	char a[30] = "are you it";
	cout << a << endl;
	replaceSpace(a, 30);
	cout << a << endl;
	return 0;
}
*/
/*******************************
#include<iostream>
using namespace std;
void hecheng(int *a, int *b, int len1, int len2)
{
	int p = len1 + len2 - 1;
	while (len2)
	{
		if (b[len2-1] >= a[len1-1])
		{
			a[p] = b[--len2];
		}
		else
		{
			a[p] = a[--len1];
		}
		p--;
	}
}
int main()
{
	int a[11] = { 1, 3, 5, 7, 9 };
	int b[6] = { 4, 6, 7, 8, 10, 11 };
	hecheng(a, b, 5, 6);
	for (int i = 0; i < 11; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/************************************************
#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
//按输入的整数创建一个链表
void createList(ListNode **pList)
{
	int i;
	if (pList == NULL || *pList != NULL)
	{
		return;
	}
	ListNode *q = NULL;
	while (cin >> i)
	{
		ListNode *p = new ListNode;
		p->info = i;
		p->next = NULL;
		if (*pList == NULL)
		{
			*pList = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
}
//销毁链表
void destroyList(ListNode **pList)
{
	if (pList == NULL || *pList == NULL)
	{
		return;
	}
	while (*pList != NULL)
	{
		ListNode *p = *pList;
		*pList = (*pList)->next;
		delete p;
	}
}
//删除指定元素结点
void deleteNode(ListNode **pList, int value)
{
	if (pList == NULL || *pList == NULL)
	{
		return;
	}
	ListNode *pDelete = NULL;
	ListNode *pre = *pList;
	if ((*pList)->info == value)
	{
		pDelete = *pList;
		*pList = pDelete->next;
	}
	else
	{
		while (pre->next!=NULL)
		{
			if (pre->next->info == value)
			{
				pDelete = pre->next;
				break;
			}
			pre = pre->next;
		}
	}
	if (pDelete)
	{
		pre->next = pDelete->next;
		delete pDelete;
	}
}
//在链表尾部添加结点
void addToTail(ListNode **pList, int value)
{
	if (pList == NULL)
	{
		return;
	}
	ListNode *p = new ListNode;
	p->info = value;
	p->next = NULL;
	if (*pList == NULL)
	{
		*pList = p;
	}
	else
	{
		ListNode *q = *pList;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}
//从头到尾打印链表
void displayList(ListNode *list)
{
	if (list == NULL)
	{
		return;
	}
	while (list != NULL)
	{
		cout << list->info << ' ';
		list = list->next;
	}
	cout << endl;
}
//从尾到头打印链表
void rDisplayList(ListNode *list)
{
	if (list == NULL)
	{
		return;
	}
	stack<int> iStack;
	while (list != NULL)
	{
		iStack.push(list->info);
		list = list->next;
	}
	while (!iStack.empty())
	{
		cout << iStack.top()<<' ';
		iStack.pop();
	}
	cout << endl;
}
//从尾至头打印链表的递归算法
void rDisplayList1(ListNode *list)
{
	if (list == NULL)
	{
		return;
	}
	rDisplayList1(list->next);
	cout << ' ' << list->info;
}
int main()
{
	ListNode *list=NULL;
	createList(&list);            //创建一个链表
	displayList(list);            //打印链表
	cin.clear();
	int i;
	while (cin >> i)              //循环删除链表中的指定结点并打印
	{
		deleteNode(&list, i);
		displayList(list);
		rDisplayList(list);
	}
	cin.clear();
	while (cin >> i)             //循环在链表尾添加结点并打印
	{
		addToTail(&list, i);
		displayList(list);
		rDisplayList1(list);
		cout << endl;
	}
	destroyList(&list);
	return 0;
}
*/
/************前序与中序重建二叉树**********************************
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink;
	BinTreeNode *rlink;
};
//根据前序和中序重建二叉树
BinTreeNode *constructCore(int *preStart, int *preEnd, int *inStart, int *inEnd)
{
	int rootValue = preStart[0];
	BinTreeNode *root = new BinTreeNode;
	root->info = rootValue;
	root->llink = root->rlink = NULL;

	if (preStart == preEnd)
	{
		if (inStart == inEnd&&*preStart ==*inStart)
		{
			return root;
		}
		else                             //出错返回
		{
			return NULL;
		}
	}
	int *rootIn = inStart;
	while (rootIn <= inEnd&&*rootIn != rootValue)
	{
		++rootIn;
	}
	if (*rootIn != rootValue)   //出错
	{
		return NULL;
	}
	int leftlen = rootIn - inStart;
	if (leftlen)
	{
		root->llink = constructCore(preStart + 1, preStart + leftlen, inStart, rootIn-1);
	}
	if (leftlen < inEnd - inStart)
	{
		root->rlink = constructCore(preStart + leftlen + 1, preEnd, rootIn + 1, inEnd);
	}
	return root;
}
BinTreeNode *construct(int *pre, int *in, int len)
{
	if (pre == NULL || in == NULL || len <= 0)
	{
		return NULL;
	}
	return constructCore(pre, pre + len - 1, in, in + len - 1);
}
//销毁二叉树
void destroyTree(BinTreeNode **pTree)
{
	if (pTree == NULL || *pTree == NULL)
	{
		return;
	}
	destroyTree(&(*pTree)->llink);
	destroyTree(&(*pTree)->rlink);
	delete *pTree;
	*pTree = NULL;
}
//前序遍历的递归算法
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
//前序遍历的非递归算法
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != NULL)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
//中序遍历的递归算法
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
//中序遍历的非递归算法
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
//后序遍历的递归算法
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << ' ';
}
//后序遍历的递归算法
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinTreeNode *tree = construct(a, b, 8);
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);

	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);

	destroyTree(&tree);
	return 0;
}
*/
/********两个栈实现队列**************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
template<typename T>
class queue
{
public:
	bool empty();
	void push(const T &obj);
	void pop();
	T front();
private:
	stack<T> st1;
	stack<T> st2;
};
template<typename T>
bool queue<T>::empty()
{
	return st1.empty() && st2.empty();
}
template<typename T>
void queue<T>::push(const T &obj)
{
	st1.push(obj);
}
template<typename T>
void queue<T>::pop()
{
	if (empty())
	{
		return;
	}
	if (st1.empty())
	{
		st2.pop();
	}
	else
	{
		while (st1.size() != 1)
		{
			st2.push(st1.top());
			st1.pop();
		}
		st1.pop();
	}
}
template<typename T>
T queue<T>::front()
{
	if (empty())
	{
		return T();
	}
	while (!st1.empty())
	{
		st2.push(st1.top());
		st1.pop();
	}
	return st2.top();

}
int main()
{
	string str;
	queue<string> strq;
	while (cin >> str)
	{
		strq.push(str);
	}
	while (!strq.empty())
	{
		cout << strq.front() << ' ';
		strq.pop();
	}
	cout << endl;
	return 0;
}
*/
/***********两个队列实现栈******************************
#include<iostream>
#include<string>
#include<queue>
using namespace std;
template<typename T>
class stack
{
public:
	bool empty();
	void push(const T &obj);
	void pop();
	T top();
private:
	queue<T> qu1;
	queue<T> qu2;
};
template<typename T>
bool stack<T>::empty()
{
	return qu1.empty() && qu2.empty();
}
template<typename T>
void stack<T>::push(const T &obj)
{
	if (qu2.empty())
	{
		qu1.push(obj);
	}
	else
	{
		qu1.push(obj);
	}
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	if (qu2.empty())
	{
		while (qu1.size() != 1)
		{
			qu2.push(qu1.front());
			qu1.pop();
		}
		qu1.pop();
	}
	else
	{
		while (qu2.size() != 1)
		{
			qu1.push(qu2.front());
			qu2.pop();
		}
		qu2.pop();
	}
}
template<typename T>
T stack<T>::top()
{
	T result;
	if (empty())
	{
		return T();
	}
	if (qu2.empty())
	{
		while (qu1.size() != 1)
		{
			qu2.push(qu1.front());
			qu1.pop();
		}
		result = qu1.front();
		qu2.push(qu1.front());
		qu1.pop();
	}
	else
	{
		while (qu2.size() != 1)
		{
			qu1.push(qu2.front());
			qu2.pop();
		}
		result = qu2.front();
		qu1.push(qu2.front());
		qu2.pop();
	}
	return result;
}
int main()
{
	string str;
	stack<string> strq;
	while (cin >> str)
	{
		strq.push(str);
	}
	while (!strq.empty())
	{
		cout << strq.top() << ' ';
		strq.pop();
	}
	cout << endl;
	return 0;
}
*/
/**********************************************
#include<iostream>
using namespace std;
//二分查找法非递归
int binSearch(int *a, int len, int key)
{
	if (a == NULL || len <= 0)
	{
		return -1;
	}
	int start = 0;
	int end = len - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid]>key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}
//二分查找法的递归算法
int binSearchTCore(int *a, int start, int end, int key)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] > key)
		{
			return binSearchTCore(a, start, mid - 1, key);
		}
		else
		{
			return binSearchTCore(a, mid + 1, end, key);
		}
	}
	else
	{
		return -1;
	}
}
int binSearchT(int *a, int len, int key)
{
	if (a == NULL || len <= 0)
	{
		return -1;
	}
	return binSearchTCore(a, 0, len - 1, key);
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << binSearch(a, 7, 7) << endl;
	cout << binSearchT(a, 7, 2) << endl;
	return 0;
}
*/
/************************以时间复杂度为 O(n)实现排序，被排序的数组的元素小于一定值*****
#include<iostream>
using namespace std;
void sortAges(int ages[], int len)
{
	if (ages == NULL || len <= 0)
	{
		return;
	}
	const int oldAge = 99;
	int timesOfAge[oldAge+1] = { 0 };
	for (int i = 0; i < len; i++)
	{
		timesOfAge[ages[i]]++;
	}
	int index = 0;
	for (int i = 0; i <= oldAge; i++)
	{
		for (int j = 0; j < timesOfAge[i]; j++)
		{
			ages[index++] = i;
		}
	}
}
int main()
{
	int ages[] = { 9, 7, 6, 5, 4, 9, 10, 20, 9, 30, 68, 20, 1, 8, 9, 99 };
	int len = sizeof(ages) / sizeof(int);
	sortAges(ages, len);
	for (int i = 0; i < len; i++)
	{
		cout << ages[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/********查找旋转数组的最小值***********************************
#include<iostream>
using namespace std;
int mininorder(int *a, int start, int end)
{
	int index = a[start];
	for (int i = start + 1; i < end; i++)
	{
		if (index>a[i])
		{
			index = a[i];
		}
	}
	return index;
}
int min(int *a, int len)
{
	int start = 0;
	int end = len - 1;
	int mid = start;
	while (a[start] >= a[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if (a[start] == a[end] && a[start] == a[mid])    //特殊情况，必须做处理
		{
			return mininorder(a, start, end);
		}
		if (a[mid] >= a[start])
		{
			start = mid;
		}
		else if (a[mid]<=a[end])
		{
			end = mid;
		}
	}
	return a[mid];
}
int main()
{
	int a[] = { 1, 1, 0, 1, 1 };
	cout << min(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}
*/
/*********************************************
#include<iostream>
using namespace std;
int add(int n)
{
	return (n == 1) ? 1 : (add(n - 1) + n);
}
int add0(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n--);
	}
	return sum;
}
int main()
{
	cout << add(10) << endl;
	//cout << add(5000) << endl;           //递归调用栈溢出     
	cout << add0(10) << endl;
	cout << add0(5000) << endl;           
	return 1;
}
*/
/*********************************************
#include<iostream>
using namespace std;
//---一个数的二进制表示中1的个数
int numOf1(int n)
{
	int sum = 0;
	while (n)
	{
		n = n&(n - 1);
		sum++;
	}
	return sum;
}
//----判断一个数是否是2的幂
bool is2(int n)
{
	return !(n&(n - 1));
}
int main()
{
	cout << numOf1(3) << endl;
	cout << is2(7) << endl;
	return 0;
}
*/
/*----------以O(1)的时间复杂度删除链表中的结点
#include<iostream>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
void createList(ListNode **pList)
{
	if (pList == NULL||*pList!=NULL)
	{
		return;
	}
	int n;
	ListNode *q = NULL;
	while (cin >> n)
	{
		ListNode *p = new ListNode;
		p->info = n;
		p->next = NULL;
		if (*pList == NULL)
		{
			*pList = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
}
//--销毁链表的递归算法
void destroyList(ListNode **plist)
{
	if (plist == NULL || *plist == NULL)
	{
		return;
	}
	destroyList(&(*plist)->next);
	delete *plist;
	*plist = NULL;
}
//----销毁链表的非递归算法
void destroyList0(ListNode **plist)
{
	if (plist == NULL || *plist == NULL)
	{
		return;
	}
	ListNode *p = *plist;
	while (p != NULL)
	{
		p = p->next;
		delete *plist;
		*plist = p;
	}
}
void printList(ListNode *list)
{
	while (list != NULL)
	{
		cout << list->info << ' ';
		list = list->next;
	}
	cout << endl;
}
ListNode *find(ListNode *list, int key)
{
	while (list)
	{
		if (list->info == key)
		{
			return list;
		}
		list = list->next;
	}
	return NULL;
}
//时间复杂度O(n)删除链表结点
void deleteNode(ListNode **pList, ListNode *pDelete)
{
	if (pList == NULL || *pList == NULL || pDelete == NULL)
	{
		return;
	}
	ListNode *p = *pList;
	if (pDelete == p)
	{
		*pList = p->next;
	}
	else
	{
		while (p->next != NULL&&p->next != pDelete)
		{
			p = p->next;
		}
		if (p->next == NULL)
		{
			return;
		}
		p->next = pDelete->next;
	}
	delete pDelete;

}
void deleteNode0(ListNode **pList, ListNode *pDelete)
{
	if (pList == NULL || *pList == NULL||pDelete==NULL)
	{
		return;
	}

	ListNode *p = NULL;
	if (pDelete == *pList)
	{
		*pList = pDelete->next;
		delete pDelete;
	}
	else if (pDelete->next == NULL)
	{
		p = *pList;
		while (p->next != pDelete)
		{
			p = p->next;
		}
		p->next = NULL;
		delete pDelete;
	}
	else
	{
		p = pDelete->next;
		pDelete->info = p->info;
		pDelete->next = p->next;
		delete p;
	}
}
int main()
{
	ListNode *list=NULL;
	createList(&list);
	printList(list);

	ListNode *pDelete = find(list, 5);
	deleteNode0(&list, pDelete);
	printList(list);

	destroyList(&list);
	
	
	return 0;
}
*/
/************************基数在前偶数在后排序的可扩展性解法********************
#include<iostream>
using namespace std;
bool isOdd(int a)
{
	return (a & 0x01) == 1;
}
bool isPositive(int a)
{
	return a >= 0;
}
void reOrderOddEven(int *a, unsigned int len,bool (*fun)(int))
{
	if (a == NULL || len == 0)
	{
		return;
	}
	int *begin = a;
	int *end = a + len - 1;
	while (begin < end)
	{
		while (begin < end && (*fun)(*begin))
		{
			begin++;
		}
		while (begin < end && !(*fun)(*end))
		{
			end--;
		}
		if (begin < end)
		{
			int temp = *begin;
			*begin = *end;
			*end = temp;
		}
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(a) / sizeof(int);
	reOrderOddEven(a, len,isOdd);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	int b[] = { -1, 2, -3, 4, -5, 6, -7, 8, -9 };
	int lenb = sizeof(b) / sizeof(int);
	reOrderOddEven(b, lenb, isPositive);
	for (int i = 0; i < lenb; i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;

	return 0;
}
*/
/***********C++实现单链表*******************
#include<iostream>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
class List
{
public:
	List();											//普通构造函数
	List(const List &obj);                          //拷贝构造函数
	List &operator=(const List &obj);               //赋值运算符重载
	~List();
	void addtotail(int key);                        //链表尾添加元素
	void addtohead(int key);                        //链表头添加元素
	ListNode *findKFormTail(unsigned int k);        //寻找链表的倒数第k个结点
	void reverseList();								//链表反向
	void print();                                   //从头至尾打印链表
private:
	ListNode *head, *tail;
};
List::List() :head(NULL), tail(NULL)
{
}
List::List(const List &obj) : head(NULL), tail(NULL)
{
	ListNode *p = obj.head;
	while (p)
	{
		addtotail(p->info);
		p = p->next;
	}
}
List &List::operator=(const List &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	ListNode *p = NULL;
	while (head)
	{
		p = head->next;
		delete head;
		head = p;
	}
	tail = NULL;
	p = obj.head;
	while (p)
	{
		addtotail(p->info);
		p = p->next;
	}
	return *this;
}
List::~List()
{
	ListNode *p = NULL;
	while (head != NULL)
	{
		p = head->next;
		delete head;
		head = p;
	}
	tail = NULL;
}
void List::addtotail(int key)
{
	ListNode *p = new ListNode;
	p->info = key;
	p->next = NULL;
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}
void List::addtohead(int key)
{
	ListNode *p = new ListNode;
	p->info = key;
	p->next = NULL;
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}
ListNode *List::findKFormTail(unsigned int k)
{
	ListNode *p = head;
	ListNode *q = head;
	for (int i = 0; i < k; i++)
	{
		if (q == NULL)
		{
			return NULL;
		}
		q = q->next;
	}
	if (q == NULL)
	{
		return NULL;
	}
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}
void List::reverseList()
{
	if (head == tail)
	{
		return;
	}
	tail = head;
	ListNode *p = head->next;
	ListNode *q = p->next;
	p->next = head;
	while (q)
	{
		head = p;
		p = q;
		q = q->next;
		p->next = head;
	}
	head = p;
	tail->next = NULL;
}
void List::print()
{
	ListNode *p = head;
	while (p)
	{
		cout << p->info << ' ';
		p = p->next;
	}
	cout << endl;
}
int main()
{
	List listtest;
	for (int i = 0; i < 10; i++)
	{
		listtest.addtotail(i);
	}

	ListNode *kFromTail = listtest.findKFormTail(10);//删除倒数第K个结点测试
	if (kFromTail != NULL)
	{
		cout << kFromTail->info << endl;
	}
	listtest.print();

	listtest.reverseList();
	listtest.print();
	listtest.addtotail(10);
	listtest.print();

	List list0(listtest);
	list0.print();

	List list1;
	list1 = list0;
	list1.print();

	return 0;
}
*/
/*********欧拉路**************************
#include<iostream>
using namespace std;
int main()
{
	int vexNum, arcNum;
	cin >> vexNum >> arcNum;
	int *buf = new int[vexNum + 1];
	for (int i = 0; i <= vexNum; i++)
	{
		buf[i] = 0;
	}
	int v0, v1;
	for (int i = 0; i < arcNum; i++)
	{
		cin >> v0 >> v1;
		buf[v0]++;
		buf[v1]++;
	}
	int odd = 0;
	int even = 0;
	for (int i = 1; i <= vexNum; i++)
	{
		if (buf[i] % 2)
		{
			odd++;
		}
		else
		{
			even++;
		}
	}
	if (odd == 2 || (odd == 0 && even == vexNum))
	{
		cout << "Full" << endl;
	}
	else
	{
		cout << "Part" << endl;
	}
	delete[]buf;
	return 0;
}
*/
/**************************************************
#include<iostream>
#include<stack>
using namespace std;
struct edgeNode
{
	int vetex;
	edgeNode *nextNode;
};
struct GraphList
{
	int vexNum;
	int arcNum;
	edgeNode **vexs;
};
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cin >> G.vexNum >> G.arcNum;
	G.vexs = new edgeNode*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.vexs[i] = NULL;
	}
	int v0, v1;
	for (int i = 0; i < G.arcNum; i++)
	{
		cin >> v0 >> v1;
		edgeNode *p = new edgeNode;
		p->vetex = v1 - 1;
		p->nextNode = G.vexs[v0 - 1];
		G.vexs[v0 - 1] = p;
	}
}
void findIndegree(GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i];
		while (p)
		{
			++indegree[p->vetex];
			p = p->nextNode;
		}
	}
}
bool topTest(GraphList &G)
{
	int index = 0;
	stack<int> st;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		edgeNode *p = G.vexs[j];
		while (p)
		{

		}
	}
}
int main()
{
	return 0;
}
*/
/**************顺序链表的合并*****************************
#include<iostream>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
void createList(ListNode **plist)
{
	if (plist == NULL || *plist != NULL)
	{
		return;
	}
	cin.clear();
	int tmp;
	ListNode *q = *plist;
	while (cin >> tmp)
	{
		ListNode *p = new ListNode;
		p->info = tmp;
		p->next = NULL;
		if (*plist == NULL)
		{
			(*plist) = p;	
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
}
void destroyList(ListNode **plist)
{
	if (plist == NULL || *plist == NULL)
	{
		return;
	}
	ListNode *p = *plist;
	while (p)
	{
		p = p->next;
		delete *plist;
		*plist = p;
	}
}
ListNode *merge(ListNode *listA, ListNode *listB)
{
	if (listA == NULL)
	{
		return listB;
	}
	else if (listB == NULL)
	{
		return listA;
	}
	ListNode *mergeList = NULL;
	if (listA->info <= listB->info)
	{
		mergeList = listA;
		mergeList->next = merge(listB, listA->next);
	}
	else
	{
		mergeList = listB;
		mergeList->next = merge(listA, listB->next);
	}
	return mergeList;
}
void printList(ListNode *list)
{
	while (list)
	{
		cout << list->info << ' ';
		list = list->next;
	}
	cout << endl;
}
int main()
{
	ListNode *list0 = NULL;
	createList(&list0);
	ListNode *list1 = NULL;
	createList(&list1);
	ListNode *listMerge=merge(list0, list1);
	list0 = NULL;                          //合并后 被合并的清零
	list1 = NULL;						   //清零
	printList(listMerge);
	destroyList(&listMerge);
	return 0;
}
*/
/**********是否二叉树子树、二叉树的镜像*****************************************
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
//-----------生成二叉树
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
//----销毁二叉树
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
//----先根周游递归
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
//----先根周游非递归
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *p = tree;
	stack<BinTreeNode*> st;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != NULL)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
//-----对称周游递归
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
//-------对称周游非递归
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *p = tree;
	stack<BinTreeNode*> st;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
//----后根周游递归
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << ' ';
}
//--------后根周游非递归
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	stack<BinTreeNode*> st;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
//------广度优先周游
void guanduOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *p = tree;
	queue<BinTreeNode*> qu;
	qu.push(p);
	while (!qu.empty())
	{
		p = qu.front();
		qu.pop();
		cout << p->info << ' ';
		if (p->llink!=NULL)
		{
			qu.push(p->llink);
		}
		if (p->rlink!=NULL)
		{
			qu.push(p->rlink);
		}
	}
	cout << endl;
}
//---判断一棵二叉树是否包含另一棵二叉树
bool DoesTree1HaveTree2(BinTreeNode *tree1,BinTreeNode *tree2 )
{
	if (tree2 == NULL)               //这个一定要在前
	{
		return true;   
	}
	if (tree1 == NULL)
	{
		return false;
	}
	if (tree1->info != tree2->info)
	{
		return false;
	}
	return DoesTree1HaveTree2(tree1->llink, tree2->llink) &&
		DoesTree1HaveTree2(tree1->rlink, tree2->rlink);
}
bool HasSubtree(BinTreeNode *pRoot1, BinTreeNode *pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL&&pRoot2 != NULL)
	{
		if (pRoot1->info == pRoot2->info)
		{
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->llink, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->rlink, pRoot2);
		}
	}
	return result;
}
//----二叉树镜像的递归算法
void MirrorRecursively(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *temp = tree->llink;
	tree->llink = tree->rlink;
	tree->rlink = temp;
	MirrorRecursively(tree->llink);
	MirrorRecursively(tree->rlink);
}
//-----------二叉树镜像的非递归算法
void MirrorNoRecursively(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinTreeNode *p = tree;
	stack<BinTreeNode*> st;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			BinTreeNode *tmp = p->llink;
			p->llink = p->rlink;
			p->rlink = tmp;
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
}
int main()
{
	BinTreeNode *tree = NULL;
	//----生成树------
	createTree(&tree);
	//---树的各种遍历------------
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);
	inOrder(tree);
	cout << endl;
	nInOrder(tree);
	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	guanduOrder(tree);
	//---树2是否是树1的子树测试
	BinTreeNode *tree0 = NULL;
	createTree(&tree0);
	cout << HasSubtree(tree, tree0) << endl;

	//---树的镜像测试--------------
	MirrorRecursively(tree);
	preOrder(tree);
	cout << endl;
	MirrorNoRecursively(tree);
	preOrder(tree);
	cout << endl;
	//----释放树申请的资源--------------
	destroyTree(&tree0);
	destroyTree(&tree);
}
*/
/************顺时针打印二维数组*********************
#include<iostream>
using namespace std;
void printMatrixCircle(int **Matrix, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;
	for (int i = start; i <= endX; i++)
	{
		cout << Matrix[start][i] << ' ';
	}
	for (int j = start + 1; j <= endY; j++)
	{
		cout << Matrix[j][endX] << ' ';
	}
	if (endY > start)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			cout << Matrix[endY][i] << ' ';
		}
	}
	if (endX > start + 1)
	{
		for (int j = endY - 1; j > start; j--)
		{
			cout << Matrix[j][start] << ' ';
		}
	}
}
void printMatrixClockwisely(int **Matrix, int columns, int rows)
{
	if (Matrix == NULL || columns <= 0 || rows <= 0)
	{
		return;
	}
	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		printMatrixCircle(Matrix, columns, rows, start);
		start++;
	}
	cout << endl;
}
int main()
{
	int **Matrix = NULL;
	int rows, columns;
	cin >> rows >> columns;
	Matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		Matrix[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> Matrix[i][j];
		}
	}
	printMatrixClockwisely(Matrix, columns, rows);
	return 0;
}
*/
/********带求最小值的函数min的栈****************
#include<iostream>
#include<stack>
#include<string>
using namespace std;
template<typename T>
class stackWithMin
{
public:
	void push(const T &x);
	void pop();
	T min();
private:
	stack<T> m_data;
	stack<T> m_min;
};
template<typename T>
void stackWithMin<T>::push(const T&x)
{
	m_data.push(x);
	if (m_min.empty() || x < m_min.top())
	{
		m_min.push(x);
	}
	else
	{
		m_min.push(m_min.top());
	}
}
template<typename T>
void stackWithMin<T>::pop()
{
	if (!m_data.empty())
	{
		m_data.pop();
		m_min.pop();
	}
}
template<typename T>
T stackWithMin<T>::min()
{
	if (!m_min.empty())
	{
		return m_min.top();
	}
	return T();
}
int main()
{
	stackWithMin<int> st;
	string str;
	while (cin >> str)
	{
		if (str == "push")
		{
			int i;
			cin >> i;
			st.push(i);
		}
		else if (str == "pop")
		{
			st.pop();
		}
		else if (str == "min")
		{
			cout << st.min() << endl;
		}
	}
	return 0;
}
*/
/************C++实现栈*****************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class stack
{
public:
	stack(int i=100);
	~stack();
	bool empty();
	bool full();
	void push(const T &x);
	void pop();
	T top();
private:
	stack(const stack &obj);
	stack &operator=(const stack &obj);
	int MAX;
	int t;
	T *data;
};
template<typename T>
stack<T>::stack(int i = 100) :MAX(i), data(NULL)
{
	data = new T[MAX];
	if (data)
	{
		t = -1;
	}
}
template<typename T>
stack<T>::~stack()
{
	if (data)
	{
		delete[]data;
		data = NULL;
	}
}
template<typename T>
bool stack<T>::empty()
{
	return t == -1;
}
template<typename T>
bool stack<T>::full()
{
	return t + 1 == MAX;
}
template<typename T>
void stack<T>::push(const T &x)
{
	if (full())
	{
		return;
	}
	data[++t] = x;
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	t--;
}
template<typename T>
T stack<T>::top()
{
	if (empty())
	{
		return T();
	}
	return data[t];
}
int main()
{
	stack<string> strstack;
	string str;
	while (cin >> str)
	{
		if (str == "push")
		{
			string i;
			cin >> i;
			strstack.push(i);
		}
		else if (str == "pop")
		{
			strstack.pop();
		}
		else if (str == "top")
		{
			cout << strstack.top() << endl;
		}
	}
	return 0;
}
*/
/*********火车入站出站顺序************************
#include<iostream>
#include<stack>
using namespace std;
template<typename T>                                      //函数模板，有点意思
bool isPopOrder(const T *pPush, const T *pPop, int len)
{
	if (pPush == NULL || pPop == NULL || len <= 0)
	{
		return false;
	}
	
	int index = 0;
	stack<T> st;
	for (int i = 0; i < len; i++)
	{
		st.push(pPush[i]);
		while (!st.empty() && st.top() == pPop[index])
		{
			st.pop();
			index++;
		}
	}
	if (index != len)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 4, 5, 3, 1, 2 };
	cout << isPopOrder(a, b, 5) << endl;
	
	string str0[5] = { "1", "2", "3", "4", "5" };
	string str1[5] = { "4", "5", "3", "2", "1" };
	cout << isPopOrder(str0, str1, 5) << endl;
	return 0;
}
*/
/********判断数组序列是否是一个二叉排序树的后序遍历和前序遍历**************
#include<iostream>
using namespace std;
//判断是否后序遍历
bool verifyPostOrderofBST(int *a, int len)
{
	if (a == NULL || len <= 0)
	{
		return false;
	}
	int root = a[len - 1];
	
	int i = 0;
	for (; i < len - 1; i++)
	{
		if (a[i]>root)
		{
			break;
		}
	}
	for (int j = i; j < len - 1; j++)
	{
		if (a[j] < root)
		{
			return false;
		}
	}
	bool left = true;
	if (i>0)
	{
		left = verifyPostOrderofBST(a, i);
	}
	bool right = true;
	if (i < len - 1)
	{
		right = verifyPostOrderofBST(a + i, len - i - 1);
	}
	return left&&right;
}
//判断是否前序遍历
bool verifyPreOrderofBST(int *a, int len)
{
	if (a == NULL || len <= 0)
	{
		return false;
	}
	int root = a[0];
	int i = 1;
	for (; i < len; i++)
	{
		if (a[i]>root)
		{
			break;
		}
	}
	for (int j = i; j < len; j++)
	{
		if (a[j] < root)
		{
			return false;
		}
	}
	bool left = true;
	if (i>1)
	{
		left = verifyPreOrderofBST(a + 1, i - 1);
	}
	bool right = true;
	if (i < len)
	{
		right = verifyPreOrderofBST(a + i, len - i);
	}
	return left&&right;
}
int main()
{
	int a[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << verifyPostOrderofBST(a, 7) << endl;

	int b[] = { 8, 6, 5, 7, 10, 9, 11 };
	cout << verifyPreOrderofBST(b, 7) << endl;
	return 0;
}
*/
/****************二叉树中和为某一值的路径**********************************
#include<iostream>
#include<vector>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL | *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void findPath(BinTreeNode *tree, int expectedSum, vector<int> &path, int &currentSum)
{
	currentSum += tree->info;
	path.push_back(tree->info);
	if (tree->llink == NULL&&tree->rlink == NULL&&currentSum == expectedSum)
	{
		for (vector<int>::iterator iter = path.begin(); iter != path.end(); ++iter)
		{
			cout << *iter << ' ';
		}
		cout << endl;
	}
	if (tree->llink != NULL)
	{
		findPath(tree->llink, expectedSum, path, currentSum);
	}
	if (tree->rlink != NULL)
	{
		findPath(tree->rlink, expectedSum, path, currentSum);
	}
	currentSum -= tree->info;
	path.pop_back();
}
void findPath(BinTreeNode *tree, int expectedSum)
{
	if (tree == NULL)
	{
		return;
	}
	vector<int> path;
	int currentSum = 0;
	findPath(tree, expectedSum, path, currentSum);
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	findPath(tree, 22);
	destroyTree(&tree);
	return 0;
}
*/
/*****************二叉排序树转换为双向链表*******************
#include<iostream>
#include<stack>
using namespace std;
struct BinSearchNode
{
	int info;
	BinSearchNode *llink, *rlink;
};
//二叉排序树中寻找指定结点
//返回-1表示异常
//返回0表示未找到，*position 指向如果存在指定结点的父结点
//返回1表示找到，*position 指向找到的结点
int search(BinSearchNode *tree, int key, BinSearchNode **position)
{
	if (tree == NULL || position == NULL)
	{
		return -1;
	}
	BinSearchNode *p = tree;
	BinSearchNode *q = NULL;
	while (p)
	{
		q = p;
		if (p->info == key)
		{
			*position = p;
			return 1;
		}
		else if (p->info > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	*position = q;
	return 0;
}
//--在二叉排序树中插入指定值得结点-----
int insert(BinSearchNode **ptree, int key)
{
	if (ptree == NULL)
	{
		return -1;
	}
	BinSearchNode *position = NULL;
	if (search(*ptree, key, &position) == 1)    //树中已有指定元素
	{
		return 0;
	}
	BinSearchNode *p = new BinSearchNode;
	p->info = key;
	p->llink = p->rlink = NULL;
	if (*ptree == NULL)
	{
		*ptree = p;
	}
	else if (position->info>key)
	{
		position->llink = p;
	}
	else
	{
		position->rlink = p;
	}
	return 1;
}
//-------删除二叉排序树中指定的元素---------------------
int deleteNode(BinSearchNode **ptree, int key)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return -1;                            //输入错误
	}
	BinSearchNode *p = *ptree;
	BinSearchNode *parent = NULL;
	while (p)
	{
		if (p->info == key)
		{
			break;
		}
		parent = p;
		if (p->info > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	if (p == NULL)
	{
		return 0;                 //二叉树中没有指定元素
	}
	if (p->llink == NULL)
	{
		if (parent == NULL)
		{
			*ptree = p->rlink;
		}
		else if (parent->rlink==p)
		{
			parent->rlink = p->rlink;
		}
		else
		{
			parent->llink = p->rlink;
		}
	}
	else
	{
		BinSearchNode *r = p->llink;
		while (r->rlink)
		{
			r = r->rlink;
		}
		r->rlink = p->rlink;
		if (parent == NULL)
		{
			*ptree = p->llink;
		}
		else if (parent->rlink == p)
		{
			parent->rlink = p->llink;
		}
		else
		{
			parent->llink = p->llink;
		}
	}
	delete p;
	return 1;
}
//-----构造二叉排序树--------
void createSearchTree(BinSearchNode **ptree)
{
	if (ptree == NULL)
	{
		return;
	}
	int i;
	while (cin >> i)
	{
		insert(ptree, i);
	}
}
//----销毁二叉排序树-----------------------
void destroy(BinSearchNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroy(&(*ptree)->llink);
	destroy(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
//------ 先根遍历--------------------------------------
void preOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
//--------对称周游遍历--------------------------------------
void inOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
//-----递归算法----------------------------------------
void convertNode(BinSearchNode *tree, BinSearchNode **pLastNode)
{
	if (tree == NULL)
	{
		return;
	}
	BinSearchNode *pCurrent = tree;
	if (pCurrent->llink != NULL)
	{
		convertNode(pCurrent->llink, pLastNode);
	}

	pCurrent->llink = *pLastNode;
	if (*pLastNode != NULL)
	{
		(*pLastNode)->rlink = pCurrent;
	}

	*pLastNode = pCurrent;
	if (pCurrent->rlink != NULL)
	{
		convertNode(pCurrent->rlink, pLastNode);
	}
}
BinSearchNode *convert(BinSearchNode **ptree)
{
	BinSearchNode *pLastNode = NULL;
	convertNode(*ptree, &pLastNode);
	while (pLastNode!=NULL&&pLastNode->llink!=NULL)
	{
		pLastNode = pLastNode->llink;
	}
	*ptree = NULL;
	return pLastNode;
}
//---------非递归算法---------------------
BinSearchNode *convertNoRecu(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
}
//---销毁循环链表------
void destroyList(BinSearchNode **plist)
{
	if (plist == NULL || *plist == NULL)
	{
		return;
	}
	BinSearchNode *p = *plist;
	while (*plist)
	{
		p = (*plist)->rlink;
		delete *plist;
		*plist = p;
	}
}
//--打印循环链表
void print(BinSearchNode *list)
{
	while (list)
	{
		cout << list->info << ' ';
		list = list->rlink;
	}
	cout << endl;
}
int main()
{
	BinSearchNode *tree = NULL;
	createSearchTree(&tree);
	preOrder(tree);
	cout << endl;
	inOrder(tree);
	cout << endl;
//--删除二叉排序树中指定元素测试
	cin.clear();
	int deleteKey;
	while (cin >> deleteKey)
	{
		deleteNode(&tree, deleteKey);
		preOrder(tree);
		cout << endl;
		inOrder(tree);
		cout << endl;
	}
//---二叉排序树转换为双向链表测试
	BinSearchNode *list = convert(&tree);
	print(list);
	destroyList(&list);

	return 0;
}
*/
/******连续子数组的最大和*****************
#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int getMaxSum(int *a, int n)
{
	if (a == NULL || n <= 0)
	{
		return 0;
	}
	int maxSum = 0;
	int curSum = 0;
	for (int i = 0; i < n; i++)
	{
		if (curSum + a[i] <= 0)
		{
			curSum = 0;
		}
		else
		{
			curSum += a[i];
			maxSum = max(maxSum, curSum);
		}
	}
	return maxSum;
}
int main()
{
	int a[] = {1,-2,3,10,-4,7,2,-5};
	cout << getMaxSum(a, 8) << endl;
	return 0;
}
*/
/******连续子数组的最大积**********
#include<iostream>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a>b ? a : b;
}
int getMaxProduct(int *a, int n)
{
	if (a == NULL || n <= 0)
	{
		return 0;
	}
	if (a[0] < 0 && n == 1)
	{
		return a[0];
	}
	int minProduct = 1;
	int maxProduct = 1;
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			int temp = maxProduct;
			maxProduct = max(minProduct*a[i], 1);
			minProduct = temp*a[i];
			
		}
		else if (a[i] == 0)
		{
			maxProduct = 1;
			minProduct = 1;
		}
		else
		{
			maxProduct *= a[i];
			minProduct = min(minProduct*a[i], 1);
		}
		r = max(r, maxProduct);
	}
	return r;
}
int main()
{
	int a[] = {1,-2,3,4,-1};
	cout << getMaxProduct(a, 5) << endl;
	return 0;
}
*/
/********字符串中第一个只出现1次的第一个字符******************
#include<iostream>
using namespace std;
char firtCharNum1(char *pchar)
{
	if (pchar == NULL)
	{
		return 0;
	}
	int a[256] = { 0 };
	char *pc = pchar;
	while (*pc != '\0')
	{
		a[*pc]++;
		pc++;
	}
	while (*pchar != '\0')
	{
		if (a[*pchar] == 1)
		{
			return *pchar;
		}
		pchar++;
	}
	return 0;
}
int main()
{
	char a[] = "huanghu";
	cout << firtCharNum1(a) << endl;
	return 0;
}
*/
/********最大公共子序列****
#include<iostream>
#include<string>
using namespace std;
int LCS(string &str0, string &str1, string &common)
{
	int i = 0;
	int j = 0;
	int size0 = str0.size();
	int size1 = str1.size();
	int **dp = new int*[size0+1];
	for (i = 0; i <= size0; i++)
	{
		dp[i] = new int[size1 + 1];
	}
	for (i = 0; i <= size0; i++)
	{
		dp[i][0] = 0;
	}
	for (j = 0; j <= size1; j++)
	{
		dp[0][j] = 0;
	}
	for (i = 1; i <= size0; i++)
	{
		for (j = 1; j <= size1; j++)
		{
			if (str0[i-1] == str1[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1]+1;
			}
			else if (dp[i - 1][j] > dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	common.clear();
	i = size0;
	j = size1;
	while (i&&j)
	{
		if (dp[i][j] == dp[i - 1][j - 1] + 1 && str0[i - 1] == str1[j - 1])
		{
			common.insert(common.begin(),str0[i-1]);
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	int MAX = dp[size0][size1];
	for (int i = 0; i <= size0; i++)
	{
		delete []dp[i];
	}
	delete[]dp;
	return MAX;
}
int main()
{
	string str0, str1;
	string common;
	while (cin >> str0 >> str1)
	{
		cout << LCS(str0, str1, common) << ' ';
		cout << common << endl;
	}
	return 0;
}
*/
/*************************
#include<iostream>
using namespace std;
void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (a[j]>x&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void shell(int *a, int n, int k)
{
	for (int i = k; i < n; i += k)
	{
		int j = i - k;
		int x = a[i];
		while (a[j]>x&&j >= 0)
		{
			a[j + k] = a[j];
			j -= k;
		}
		a[j + k] = x;
	}
}
void shellSort(int *a, int n)
{
	int k = n / 2;
	while (k)
	{
		shell(a, n, k);
		k /= 2;
	}
}
void selectSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			a[i] = a[i] ^ a[k];
			a[k] = a[i] ^ a[k];
			a[i] = a[i] ^ a[k];
		}
	}
}
void sift(int *a, int n, int i)
{
	int child=0;
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[i] < a[child])
		{
			int tmp = a[i];
			a[i] = a[child];
			a[child] = tmp;
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		sift(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		sift(a, i, 0);
	}
}
void QiPao(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void QSort(int *a, int n)
{
	int i = 0;
	int j = n - 1;
	int k = a[0];
	if (n > 1)
	{
		while (i < j)
		{
			for (; i < j; j--)
			{
				if (a[j] < k)
				{
					a[i++] = a[j];
					break;
				}
			}
			for (; i < j; i++)
			{
				if (a[i]>k)
				{
					a[j--] = a[i];
					break;
				}
			}
		}
		a[i] = k;
		QSort(a, i);
		QSort(a + i + 1, n - i - 1);
	}
}
int main()
{
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	//insertSort(a, 10);
	//shellSort(a, 10);
	//selectSort(a, 10);
	//heapSort(a, 10);
	//QiPao(a, 10);
	QSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/

/**********AOV*****************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int endvex;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vetex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum, arcNum;
	vexNode *vexs;
};
int locateVex(const GraphList &G,string &str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vetex == str)
		{
			return i;
		}
	}
	return -1;
}
bool createGraphList(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return false;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.arcNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vetex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息（v0,v1,w）：" << endl;
	for (int i = 0; i < G.arcNum; i++)
	{
		string str0, str1;
		int w;
		cin >> str0 >> str1 >> w;
		int x = locateVex(G,str0);
		int y = locateVex(G,str1);
		if (x == -1 || y == -1)
		{
			return false;
		}
		edgeNode *p = new edgeNode;
		p->endvex = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraphList(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (G.vexs[i].firstNode)
		{
			p = G.vexs[i].firstNode->nextNode;
			delete G.vexs[i].firstNode;
			G.vexs[i].firstNode = p;
		}
	}
	delete[]G.vexs;
	G.vexs = NULL;
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			++indegree[p->endvex];
			p=p->nextNode;
		}
	}
}
bool topSort(GraphList &G, int *result)
{
	int index = 0;
	stack<int> st;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			--indegree[p->endvex];
			if (indegree[p->endvex] == 0)
			{
				st.push(p->endvex);
			}
			p = p->nextNode;
		}
	}
	if (index != G.vexNum)
	{
		return false;
	}
	return true;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	bool flag=createGraphList(G);
	if (!flag)
	{
		cout << "输入错误" << endl;
	}
	int *result = new int[G.vexNum];
	if (topSort(G, result)&&flag)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			cout << G.vexs[result[i]].vetex << ' ';
		}
		cout << endl;
	}
	destroyGraphList(G);
	return 0;
}
*/
/**********
#include<iostream>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct path
{
	int **len;
	int **endvex;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.arcNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.arcNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(GraphMatrix &G, path &result)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			result.len[i][j] = G.arcs[i][j];
			if (result.len[i][j] != MAX)
			{
				result.endvex[i][j] = j;
			}
			else
			{
				result.endvex[i][j] = -1;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (result.len[i][j]>result.len[i][k] + result.len[k][j])
				{
					result.len[i][j]=result.len[i][k] + result.len[k][j];
					result.endvex[i][j] = result.endvex[i][k];
				}
			}
		}
	}
}
void showPath(const path &result,int v0,int v1)
{
	if (result.len[v0][v1] == MAX)
	{
		cout << "无法到达：" << endl;
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << ' ';
		v0 = result.endvex[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path reslut;
	reslut.endvex = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		reslut.endvex[i] = new int[G.vexNum];
	}
	reslut.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		reslut.len[i] = new int[G.vexNum];
	}
	Floyd(G, reslut);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(reslut, v0, v1);
	}
	return 0;
}
*/
/**************************************
#include<iostream>
using namespace std;
void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (a[j]>x&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int fun(int n)
{
	int a[4];
	a[0] = n / 1000;
	a[1] = n / 100 % 10;
	a[2] = n / 10 % 10;
	a[3] = n % 10;
	insertSort(a, 4);
	int sub = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0] - (a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]);
	while (n!=sub)
	{
		n = sub;
		a[0] = n / 1000;
		a[1] = n / 100 % 10;
		a[2] = n / 10 % 10;
		a[3] = n % 10;
		insertSort(a, 4);
		sub = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0] - (a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]);
	}
	return n;
}
int main()
{
	int num = 0;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int h = 0; h < 10; h++)
				{
					if (i != j&&i!=k&&i!=h&&j != k&&j!=h&&k != h)
					{
						num = fun(i*1000+j*100+k*10+h);
						if (num != flag&&flag!= 0)
						{
							cout << "false" << endl;
							return 0;
						}
						flag = num;
					}
				}
			}
		}
	}
	cout << num << endl;
	return 0;
}
*/
/***********全排列火车进出站*****************
#include <iostream>  
#include<stack>
using namespace std;
int n = 0;
void swap(int *a, int *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}
bool isPop(const int *list0, const int *list, int n)
{
	stack<int> st;
	int index = 0;
	for (int i = 0; i<n; i++)
	{
		st.push(list0[i]);
		while (!st.empty()&&st.top() == list[index])
		{
			st.pop();
			index++;
		}
	}
	if (index==n)
	{
		return true;	
	}
	else
	{
		return false;
	}
}
void perm(const int *list0,int *list, int k, int m)
{
	int i;
	if (k > m)
	{
		if (isPop(list0, list, m+1))
		{
			for (i = 0; i <= m; i++)
			{
				cout << list[i];
			}
			cout << endl;
			n++;
		}
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			perm(list0,list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}
int main()
{
	int list[] = { 1, 2, 3, 4, 5,6 };
	int list0[] = { 1, 2, 3, 4, 5,6 };
	perm(list0,list, 0, 5);
	cout << n << endl;
	return 0;
}
*/
/************全排列火车进出栈************************
#include<iostream>
#include<stack>
using namespace std;
const int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int x[11];
bool isPop(int n)
{
	stack<int> st;
	int i = 0;
	int j = 1;
	while (i < n)
	{
		st.push(buf[i++]);
		while (!st.empty() && st.top() == x[j])
		{
			st.pop();
			j++;
		}
	}
	if (j>n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool place(int k)
{
	for (int i = 1; i < k; i++)
	{
		if (x[i] == x[k])
		{
			return false;
		}
	}
	return true;
}
void dfs(int n)
{
	int k = 1;
	while (k >= 1)
	{
		x[k]++;
		while (x[k] <= n&&!place(k))
		{
			x[k]++;
		}
		if (x[k] <= n)
		{
			if (k == n)
			{
				if (isPop(n))
				{
					for (int i = 1; i <= n; i++)
					{
						cout << x[i] << ' ';
					}
					cout << endl;
				}
			}
			else if (k<n)
			{
				k++;
			}
		}
		else
		{
			x[k] = 0;
			k--;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	dfs(n);
	return 0;
}
*/
/****************************************************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct path
{
	int len;
	int vexend;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.arcNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.arcNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GraphMatrix &G, path *dist)
{
	if (G.arcs == NULL)
	{
		return;
	}
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	dist[0].len = 0;
	dist[0].vexend = 0;
	flag[0] = 1;
	for (int i = 1; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vexend = -1;
		}
		else
		{
			dist[i].vexend = 0;
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len < minw)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		if (min == 0)
		{
			return;
		}
		flag[min] = 1;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[min].len + G.arcs[min][j] < dist[j].len)
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vexend = min;
			}

		}
	}
	delete[]flag;
}
void showpath(path *dist, int v)
{
	if (dist[v].len == MAX)
	{
		return;
	}
	stack<int> st;
	while (v != 0)
	{
		st.push(v);
		v = dist[v].vexend;
	}
	cout << 0 << ' ';
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path *dist = new path[G.vexNum];
	dijkstra(G, dist);
	int n;
	while (cin >> n)
	{
		if (n <= 5)
		{
			cout << "huang" << endl;
			showpath(dist, n);
		}
	}
	destroyGraph(G);
	return 0;
}
*/
/*******************************************
#include<iostream>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexend;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.arcNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.arcNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &result)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			result.len[i][j] = G.arcs[i][j];
			if (result.len[i][j] == MAX)
			{
				result.vexend[i][j] = -1;
			}
			else
			{
				result.vexend[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (result.len[i][j]>result.len[i][k] + result.len[k][j])
				{
					result.len[i][j] = result.len[i][k] + result.len[k][j];
					result.vexend[i][j] = result.vexend[i][k];
				}
			}
		}
	}
}
void showPath(const path &result, int v0, int v1)
{
	if (result.len[v0][v1] == MAX)
	{
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << ' ';
		v0 = result.vexend[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path result;

	result.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		result.len[i] = new int[G.vexNum];
	}
	result.vexend = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		result.vexend[i] = new int[G.vexNum];
	}

	Floyd(G, result);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(result, v0, v1);
	}
	destroyGraph(G);

	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]result.len[i];
	}
	delete[]result.len;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]result.vexend[i];
	}
	delete[]result.vexend;
	return 0;
}
*/
/**********************************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int vexend;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vetex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum;
	int arcNum;
	vexNode *vexs;
};
int locateVex(const GraphList &G, string &str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vetex == str)
		{
			return i;
		}
	}
	return -1;
}
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cout << "请输入结点数和边数：" << endl;
	cin >> G.vexNum >> G.arcNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vetex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息(v0,v1,w)：" << endl;
	string str0, str1;
	int w;
	for (int i = 0; i < G.arcNum; i++)
	{
		cin >> str0 >> str1 >> w;
		int x = locateVex(G, str0);
		int y = locateVex(G, str1);
		if (x == -1 || y == -1)
		{
			cout << "输入有误！" << endl;
			return;
		}
		edgeNode *p = new edgeNode;
		p->vexend = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraph(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (G.vexs[i].firstNode)
		{
			p = p->nextNode;
			delete G.vexs[i].firstNode;
			G.vexs[i].firstNode = p;
		}
	}
	delete[]G.vexs;
	G.vexs = NULL;
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			indegree[p->vexend]++;
			p = p->nextNode;
		}
	}
}
int AOV(GraphList &G, int *result)
{
	if (G.vexs == NULL || result == NULL)
	{
		return -1;
	}
	stack<int> st;
	int index = 0;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			indegree[p->vexend]--;
			if (indegree[p->vexend] == 0)
			{
				st.push(p->vexend);
			}
			p = p->nextNode;
		}
	}
	return 0;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	createGraph(G);
	int *result = new int[G.vexNum];
	if (AOV(G, result) == 0)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			cout << G.vexs[result[i]].vetex << ' ';
		}
		cout << endl;
	}
	delete[]result;
	destroyGraph(G);
	return 0;
}
*/
/*****************************************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int endVex;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vertex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum;
	int edgeNum;
	vexNode *vexs;
};
int locateVex(const GraphList &G,const string &str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vertex == str)
		{
			return i;
		}
	}
	return -1;
}
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vertex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	string v0, v1;
	int w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		int x = locateVex(G,v0);
		int y = locateVex(G,v1);
		edgeNode *p = new edgeNode;
		p->endVex = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraph(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = NULL;
		while (G.vexs[i].firstNode != NULL)
		{
			p = G.vexs[i].firstNode->nextNode;
			delete G.vexs[i].firstNode;
			G.vexs[i].firstNode = p;
		}
	}
	delete[]G.vexs;
	G.vexs = NULL;
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			++indegree[p->endVex];
			p = p->nextNode;
		}
	}
}
void topSort(const GraphList &G, int *result)
{
	int index = 0;
	stack<int> st;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			indegree[p->endVex]--;
			if (indegree[p->endVex] == 0)
			{
				st.push(p->endVex);
			}
			p = p->nextNode;
		}
	}
	if (index < G.vexNum)
	{
		cout << "存在回路" << endl;
	}
	delete[]indegree;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	createGraph(G);
	int *result = new int[G.vexNum];
	topSort(G, result);
	for (int i = 0; i < G.vexNum; i++)
	{
		cout << G.vexs[result[i]].vertex << ' ';
	}
	cout << endl;
	delete[]result;
	destroyGraph(G);
	return 0;
}
*/
/************************************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int len;
	int vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroy(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GraphMatrix &G, path *dist)
{
	if (G.arcs == NULL)
	{
		return;
	}
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	dist[0].len = 0;
	dist[0].vexEnd = 0;
	flag[0] = 1;
	for (int i = 1; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vexEnd = -1;
		}
		else
		{
			dist[i].vexEnd = 0;
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len < minw)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		if (min == 0)
		{
			return;
		}
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[min].len + G.arcs[min][j] < dist[j].len)
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vexEnd = min;
			}
		}
	}
	delete[]flag;
}
void showPath(path *dist, int v)
{
	if (dist[v].len == MAX)
	{
		return;
	}
	stack<int> st;
	while (v)
	{
		st.push(v);
		v = dist[v].vexEnd;
	}
	cout << 0 << ' ';
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path *dist = new path[G.vexNum];
	dijkstra(G, dist);
	showPath(dist, 4);
	destroy(G);
	return 0;
}
*/
/*****************************************
#include<iostream>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息(v0,v1,w)：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &result)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			result.len[i][j] = G.arcs[i][j];
			if (result.len[i][j] == MAX)
			{
				result.vexEnd[i][j] = -1;
			}
			else
			{
				result.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (result.len[i][j]>result.len[i][k] + result.len[k][j])
				{
					result.len[i][j]=result.len[i][k] + result.len[k][j];
					result.vexEnd[i][j] = result.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << ' ';
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;

	destroyGraph(G);
	return 0;
}
*/
/************dijkstra算法*************************************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int len;
	int vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数:" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GraphMatrix &G, path *dist)
{
	if (G.arcs == NULL)
	{
		return;
	}
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	dist[0].len = 0;
	dist[0].vexEnd = 0;
	flag[0] = 1;
	for (int i = 1; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vexEnd = -1;
		}
		else
		{
			dist[i].vexEnd = 0;
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len < minw)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		if (min == 0)
		{
			return;
		}
		flag[min] = 1;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len > dist[min].len + G.arcs[min][j])
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vexEnd = min;
			}
		}
	}
}
void showPath(path *dist, int v)
{
	if (dist[v].len == MAX)
	{
		return;
	}
	stack<int> st;
	while (v)
	{
		st.push(v);
		v = dist[v].vexEnd;
	}
	cout << 0 << ' ';
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path *dist = new path[G.vexNum];
	dijkstra(G, dist);
	int i;
	while (cin >> i)
	{
		showPath(dist, i);
	}
	delete[]dist;
	destroyGraph(G);
	return 0;
}
*/
/*******Floyd算法************************
#include<iostream>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vexEnd[i][j] = -1;
			}
			else
			{
				dist.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vexEnd[i][j] = dist.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << ' ';
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;
	destroyGraph(G);
	return 0;
}
*/
/******AOV拓扑排序**************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int vexEnd;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vertex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum;
	int edgeNum;
	vexNode *vexs;
};
int locateVex(const GraphList &G, string &str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vertex == str)
		{
			return i;
		}
	}
	return 0;
}
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vertex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	string v0, v1;
	int w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		int x = locateVex(G, v0);
		int y = locateVex(G, v1);
		edgeNode *p = new edgeNode;
		p->vexEnd = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraph(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	edgeNode *p = NULL;
	for (int i = 0; i < G.vexNum; i++)
	{
		while (G.vexs[i].firstNode)
		{
			p = G.vexs[i].firstNode->nextNode;
			delete G.vexs[i].firstNode;
			G.vexs[i].firstNode = p;
		}
	}
	delete[]G.vexs;
	G.vexs = NULL;
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			indegree[p->vexEnd]++;
			p = p->nextNode;
		}
	}
}
void AOV(const GraphList &G, int *result)
{
	if (G.vexs == NULL)
	{
		return;
	}
	int index = 0;
	stack<int> st;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			indegree[p->vexEnd]--;
			if (indegree[p->vexEnd] == 0)
			{
				st.push(p->vexEnd);
			}
			p = p->nextNode;
		}
	}
	delete[]indegree;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	createGraph(G);
	int *result = new int[G.vexNum];
	AOV(G, result);
	for (int i = 0; i < G.vexNum; i++)
	{
		cout << G.vexs[result[i]].vertex << ' ';
	}
	cout << endl;
	destroyGraph(G);
	return 0;
}
*/
/*****************************************************
#include<iostream>
using namespace std;
//插入排序
void insertSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//希尔排序
void shell(int *a, int n, int k)
{
	for (int i = k; i < n; i += k)
	{
		int j = i - k;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + k] = a[j];
			j -= k;
		}
		a[j + k] = x;
	}
}
void shellSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int k = n / 2;
	while (k)
	{
		shell(a, n, k);
		k /= 2;
	}
}
//选择排序
void selectSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int tmp = a[k];
			a[k] = a[i];
			a[i] = tmp;
		}
	}
}
//堆排序
void sift(int *a, int n, int i)
{
	int child;
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[i] < a[child])
		{
			a[i] = a[i] ^ a[child];
			a[child] = a[i] ^ a[child];
			a[i] = a[i] ^ a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		sift(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[0] = a[0] ^ a[i];
		a[i] = a[0] ^ a[i];
		a[0] = a[0] ^ a[i];
		sift(a, i, 0);
	}
}
//起泡排序
void QiPaoSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1;j++)
		{
			if (a[j]>a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void QSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int i = 0;
	int j = n - 1;
	int k = a[0];
	while (i < j)
	{
		for (; i < j; j--)
		{
			if (a[j] < k)
			{
				a[i++] = a[j];
				break;
			}
		}
		for (; i < j; i++)
		{
			if (a[i]>k)
			{
				a[j--] = a[i];
				break;
			}
		}
	}
	a[i] = k;
	QSort(a, i);
	QSort(a + i + 1, n - i - 1);
}
int main()
{
	int a[] = { 4, 6, 8, 7, 1, 3, 9, 5, 2 };
	insertSort(a, 9);
	shellSort(a, 9);
	selectSort(a, 9);
	heapSort(a, 9);
	QiPaoSort(a, 9);
	QSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 10);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	int size;
	T *data;
};
template<typename T>
array<T>::array(int i = 10) : size(i), data(NULL)
{
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(NULL)
{
	if (size)
	{
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (data)
	{
		delete[]data;
		data = NULL;
	}
	size = obj.size;
	if (size)
	{
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	return *this;
}
template<typename T>
array<T>::~array()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1;
	arr1 = arr;
	cout << "========================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "========================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << endl;
	}
	cout << "========================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	return 0;
}
*/
/**********************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 20);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	void release();
	int *count;
	int size;
	T *data;
};
template<typename T>
array<T>::array(int i = 20) : size(i), data(NULL), count(new int)
{
	(*count) = 1;
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(obj.data), count(obj.count)
{
	(*count)++;
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	release();
	size = obj.size;
	data = obj.data;
	count = obj.count;
	(*count)++;
	return *this;
}
template<typename T>
array<T>::~array()
{
	release();
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
	else
	{
		return T();
	}
}
template<typename T>
void array<T>::release()
{
	(*count)--;
	if (*count == 0)
	{
		if (data)
		{
			delete[]data;
		}
		delete count;
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1;
	arr1 = arr;
	cout << "++++++++++++++++++++" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "++++++++++++++++++++" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << endl;
	}
	cout << "++++++++++++++++++++" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	return 0;
}
*/
/********多线程********************
#include<iostream>
#include<string>
#include<windows.h>
#include<process.h>
using namespace std;
void delay(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10000; j++);
	}
}
void Thread1()
{
	for (;;)
	{
		system("title %time%");
	}
}

void main(int argc, char* argv[])
{
	HANDLE hThread;
	DWORD ThreadID;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
	string str;
	while (cin >> str)
	{
		if (str == "stop")
		{
			SuspendThread(hThread);                   //挂起线程  即暂停线程
		}
		else if (str=="start")
		{
			ResumeThread(hThread);
		}
	}
}
*/
/***********************
#include<iostream>
#define MAX_VERTEX_NUM 10
#include "conio.h"
#include "stdlib.h"
using namespace std;
struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int info;
};  //表结点类型
struct VNode
{
	char data;
	ArcNode *firstarc;
}; //头结点
struct ALGraph
{
	VNode vertices[MAX_VERTEX_NUM];  //邻接表
	int vexnum, arcnum;
};

int visited[MAX_VERTEX_NUM];

int LocateVex(ALGraph G, char u)
{
	int i;
	for (i = 0; i<G.vexnum; i++)
	{
		if (u == G.vertices[i].data) return i;
	}
	if (i == G.vexnum) 
	{ 
		cout << "Error u!" << endl; 
		exit(1);
	}
	return 0;
}
void CreateALGraph_adjlist(ALGraph &G)
{
	int i, j, k, w;
	char v1, v2, enter;
	ArcNode *p;
	cout << "Input vexnum & arcnum:" << endl;
	cin>>G.vexnum;
	cin>>G.arcnum;
	cout << "Input Vertices:" << endl;
	for (i = 0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}//for
	cout << "Input Arcs(v1,v2,w)以回车分开各个数据:" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin>>v1;
		cin>>v2;
		cin>>w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
	}//for     
	return;
}//CreateALGraph_adjlist
//图的深度优先周游
void DFS(ALGraph &G, int v)
{
	ArcNode *p;
	cout<<G.vertices[v].data;
	visited[v] = 1;
	p = G.vertices[v].firstarc;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}   //从第v个顶点出发DFS
void DFSTraverse(ALGraph &G)
{
	for (int v = 0; v < G.vexnum; ++v)
	{ 
		visited[v] = 0;
	}
	for (int v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			DFS(G, v);
		}
	}
}//DFSTraverse
int main()
{
	ALGraph G;
	CreateALGraph_adjlist(G);
	DFSTraverse(G);
}
*/

/**************最短路径dijkstra算法*****************************
#include<iostream>
#include<stack>
using namespace std;
struct GraphMatrix
{
	int n;
	char *vexs;
	int **arcs;
};
struct Edge
{
	int start_vex, stop_vex;
	int weight;
};
#define MAX 10000;
void createGraph(GraphMatrix *pgraph)
{
	int n, v;
	cin >> n >> v;
	pgraph->n = n;
	pgraph->vexs = new char[n];
	pgraph->arcs = new int*[n];
	for (int i = 0; i < n; i++)
	{
		pgraph->arcs[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				pgraph->arcs[i][j] = 0;
			}
			else
			{
				pgraph->arcs[i][j] = MAX;
			}
		}
	}
	int x, y, w;
	for (int i = 0; i < v; i++)
	{
		cin >> x >> y >> w;
		pgraph->arcs[x][y] = w;
	}
}
void destroyGraph(GraphMatrix *pgraph)
{
	if (pgraph == NULL)
	{
		return;
	}
	delete[]pgraph->vexs;
	for (int i = 0; i < pgraph->n; i++)
	{
		delete[]pgraph->arcs[i];
	}
	delete[]pgraph->arcs;
}
//最短路径
struct Path
{
	int length;
	int prevex;
};

void dijkstra(GraphMatrix graph, Path *dist)
{
	int i, j, min;
	int minw;
	dist[0].length = 0;
	dist[0].prevex = 0;
	graph.arcs[0][0] = 1;
	for (i = 1; i < graph.n; i++)
	{
		dist[i].length = graph.arcs[0][i];
		if (dist[i].length != 10000)
		{
			dist[i].prevex = 0;
		}
		else
		{
			dist[i].prevex = -1;
		}
	}
	for (i = 1; i < graph.n; i++)
	{
		minw = MAX;
		min = 0;
		for (j = 1; j < graph.n; j++)
		{
			if ((graph.arcs[j][j] == 0) && (dist[j].length < minw))
			{
				minw = dist[j].length;
				min = j;
			}
		}
		if (min == 0)
		{
			break;
		}
		graph.arcs[min][min] = 1;
		for (j = 1; j < graph.n; j++)
		{
			if (graph.arcs[j][j] == 1)
			{
				continue;
			}
			if (dist[j].length>dist[min].length + graph.arcs[min][j])
			{
				dist[j].length = dist[min].length + graph.arcs[min][j];
				dist[j].prevex = min;
			}
		}
	}
}
void showPath(Path *path, int v, int v0)   //打印最短路径上的各个顶点 
{
	stack<int> s;
	int u = v;
	while (v != v0)
	{
		s.push(v);
		v = path[v].prevex;
	}
	s.push(v);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	GraphMatrix graph;
	createGraph(&graph);
	Path *dist = new Path[graph.n];
	dijkstra(graph, dist);
	showPath(dist, 3, 0);
	delete[]dist;
	destroyGraph(&graph);
	return 0;
}
*/
/************最短路径Floyd算法****************************************
//17 25
//0 1 12
//0 4 18
//1 2 3
//1 3 3
//2 3 4
//2 6 19
//3 4 7
//3 7 11
//4 9 31
//5 9 12
//6 7 4 
//6 11 7
//7 8 13
//7 10 6
//8 13 9
//9 16 35
//10 11 5
//10 12 6
//11 15 14
//12 13 9
//12 14 6
//13 16 24
//14 15 6
//14 16 8
//15 16 7
#include<iostream>
#include<stack>
using namespace std;
struct GraphMatrix
{
	int n;
	int **arcs;
};
const int MAX = 10000;
void createGraph(GraphMatrix *pgraph)
{
	int n, v;
	cin >> n >> v;
	pgraph->n = n;
	pgraph->arcs = new int*[n];
	for (int i = 0; i < n; i++)
	{
		pgraph->arcs[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				pgraph->arcs[i][j] = 0;
			}
			else
			{
				pgraph->arcs[i][j] = MAX;
			}
		}
	}
	int x, y, w;
	for (int i = 0; i < v; i++)
	{
		cin >> x >> y >> w;
		pgraph->arcs[x][y] = w;
		pgraph->arcs[y][x] = w;    //无向图
	}
}
void destroyGraph(GraphMatrix *pgraph)
{
	if (pgraph == NULL)
	{
		return;
	}

	for (int i = 0; i < pgraph->n; i++)
	{
		delete[]pgraph->arcs[i];
	}
	delete[]pgraph->arcs;
}
//最短路径
struct Path
{
	int **length;
	int **prevex;
};

void Floyd(GraphMatrix *graph, Path dist)
{
	for (int i = 0; i < graph->n; i++)
	{
		for (int j = 0; j < graph->n; j++)
		{
			dist.length[i][j] = graph->arcs[i][j];
			if (graph->arcs[i][j] != MAX)
			{
				dist.prevex[i][j] = j;
			}
			else
			{
				dist.prevex[i][j] = -1;
			}
		}
	}

	for (int k = 0; k < graph->n; k++)
	{
		for (int i = 0; i < graph->n; i++)
		{
			for (int j = 0; j < graph->n; j++)
			{
				if (dist.length[i][j]>dist.length[i][k] + dist.length[k][j])
				{
					dist.length[i][j] = dist.length[i][k] + dist.length[k][j];
					dist.prevex[i][j] = dist.prevex[i][k];
				}
			}
		}
	}
}
void showPath(Path path, int v0, int v)   //打印最短路径上的各个顶点 
{
	if (path.length[v0][v] == MAX)
	{
		return;
	}
	while (v0 != v)
	{
		cout << v0 << ' ';
		v0 = path.prevex[v0][v];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix graph;
	createGraph(&graph);

	Path dist;

	dist.length = new int*[graph.n];
	for (int i = 0; i < graph.n; i++)
	{
		dist.length[i] = new int[graph.n];
	}
	dist.prevex = new int*[graph.n];
	for (int i = 0; i < graph.n; i++)
	{
		dist.prevex[i] = new int[graph.n];
	}

	Floyd(&graph, dist);
	int x, y;
	while (cin >> x >> y)
	{
		showPath(dist, x, y);
	}


	for (int i = 0; i < graph.n; i++)
	{
		delete[]dist.prevex[i];
	}
	delete[]dist.prevex;
	for (int i = 0; i < graph.n; i++)
	{
		delete[]dist.length[i];
	}
	delete[]dist.length;

	destroyGraph(&graph);
	return 0;
}
*/
/********AOV网络**********************
#include<iostream>
#include<stack>
using namespace std;
struct EdgeNode
{
	int endvex;
	int weight;
	EdgeNode *nextedge;
};
struct VexNode
{
	int vertex;
	EdgeNode *edgelist;
};
struct GraphList
{
	int n,arcnum;
	VexNode *vexs;
};
int LocateVex(GraphList G, char u)
{
	int i;
	for (i = 0; i<G.n; i++)
	{
		if (u == G.vexs[i].vertex) return i;
	}
	if (i == G.n)
	{
		cout << "Error u!" << endl;
		exit(1);
	}
	return 0;
}
//生成图（链接表表示法）
void CreateALGraph(GraphList &G)
{

	int i, j, k, w;
	char v1, v2, enter;
	EdgeNode *p;
	cout << "Input vexnum & arcnum:" << endl;;
	cin >> G.n;               //输入结点个数
	cin >> G.arcnum;               //输入边条数
	G.vexs = new VexNode[G.n];
	cout << "Input Vertices:" << endl;
	for (i = 0; i<G.n; i++)
	{
		cin >> G.vexs[i].vertex; //输入各结点的数据
		G.vexs[i].edgelist = NULL;
	}
	cout << "Input Arcs(v1,v2,w)以回车分开各个数据:" << endl;
	for (k = 0; k<G.arcnum; k++)
	{

		cin >> i >> j >> w;     //输入两结点和边的的权值
		//i = LocateVex(G, v1);
		//j = LocateVex(G, v2);

		p = new EdgeNode;
		p->endvex = j;
		p->weight = w;
		p->nextedge = G.vexs[i].edgelist;
		G.vexs[i].edgelist = p;
	}
	return;
}


void findInDegree(GraphList *g, int *indegree)
{
	EdgeNode *p;
	for (int i = 0; i < g->n; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < g->n; i++)
	{
		p = g->vexs[i].edgelist;
		while (p)
		{
			++indegree[p->endvex];
			p = p->nextedge;
		}
	}
}
int topoSort(GraphList *paov, int *ptopo)
{
	EdgeNode *p;
	int i, j, k, nodeno = 0, top = -1;
	int *indegree = new int[paov->n];
	findInDegree(paov, indegree);
	for (i = 0; i < paov->n; i++)
	{
		if (indegree[i] == 0)
		{
			indegree[i] = top;
			top = i;
		}
	}
	while (top != -1)
	{
		j = top;
		top = indegree[top];
		ptopo[nodeno++] = j;
		p = paov->vexs[j].edgelist;
		while (p)
		{
			k = p->endvex;
			indegree[k]--;
			if (indegree[k] == 0)
			{
				indegree[k] = top;
				top = k;
			}
			p = p->nextedge;
		}
	}
	delete[]indegree;
	if (nodeno < paov->n)
	{
		cout << "AOV网络中存在回路" << endl;
		return 0;
	}
	return 1;
}
int topoSort0(GraphList *paov, int *ptopo)
{
	EdgeNode *p;
	int i, j, k, nodeno = 0;
	stack<int> st;
	int *indegree = new int[paov->n];
	findInDegree(paov, indegree);
	for (i = 0; i < paov->n; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		j = st.top();
		st.pop();
		ptopo[nodeno++] = j;
		p = paov->vexs[j].edgelist;
		while (p)
		{
			k = p->endvex;
			indegree[k]--;
			if (indegree[k] == 0)
			{
				st.push(k);
			}
			p = p->nextedge;
		}
	}
	delete[]indegree;
	if (nodeno < paov->n)
	{
		cout << "AOV网络中存在回路" << endl;
		return 0;
	}
	return 1;
}

int main()
{
	GraphList G;
	CreateALGraph(G);
	int *ptopo = new int[G.n];
	topoSort(&G, ptopo);
	for (int i = 0; i < G.n; i++)
	{
		cout << ptopo[i] << ' ';
	}
	cout << endl;
	delete[]ptopo;
	return 0;
}
*/
/************************************************
#include<iostream>
using namespace std;
int gys(int x, int y)
{
	return (y == 0) ? x : (gys(y, x%y));
}
int gys0(int x, int y)
{
	while (y != 0)
	{
		int temp = x;
		x = y;
		y = temp%y;
	}
	return x;
}
int add(int x, int y)
{
	return (y == 0) ? x : (add(x^y,(x&y) << 1));
}
int add0(int x, int y)
{
	while (y != 0)
	{
		int temp = x;
		x = x^y;
		y = (temp&y)<<1;
	}
	return x;
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout << gys(x, y) << ' ' << gys0(x, y) << endl;
		cout << add(x, y) << ' ' << add0(x, y) << endl;
	}
	return 0;
}
*/
/**********************************
#include<iostream>
using namespace std;
int fun(int x)
{
	int y = x >> 31;
	return (x^y) - y;
}
int main()
{
	int i;
	while (cin >> i)
	{
		cout << fun(i) << endl;
	}
	return 0;
}
*/
/******************************************************************
#include<iostream>
using namespace std;
template<typename T>
class stack
{
public:
	stack(int i = 10);
	~stack();
	bool empty();
	bool full();
	void push(const T &x);
	T top();
	void pop();
private:
	stack(const stack &obj);
	stack &operator=(const stack &obj);
	int MAX;
	int t;
	T *data;
};
template<typename T>
stack<T>::stack(int i = 10) :MAX(i)
{
	data = new T[MAX];
	if (data)
	{
		t = -1;
	}
}
template<typename T>
stack<T>::~stack()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
bool stack<T>::empty()
{
	return t == -1;
}
template<typename T>
bool stack<T>::full()
{
	return t + 1 == MAX;
}
template<typename T>
void stack<T>::push(const T &x)
{
	if (full())
	{
		return;
	}
	data[++t] = x;
}
template<typename T>
T stack<T>::top()
{
	if (empty())
	{
		return T();
	}
	return data[t];
}
template<typename T>
void stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	t--;
}
template<typename T>
struct queue
{
public:
	queue(int i = 10);
	~queue();
	bool empty();
	bool full();
	void push(const T &x);
	T front();
	void pop();
private:
	queue(const queue &obj);
	queue &operator=(const queue &obj);
	int MAX;
	int f, r;
	T *data;
};
template<typename T>
queue<T>::queue(int i = 10) :MAX(i)
{
	data = new T[MAX];
	if (data)
	{
		f = r = 0;
	}
}
template<typename T>
queue<T>::~queue()
{
	if (data)
	{
		delete data;
	}
}
template<typename T>
bool queue<T>::empty()
{
	return (f == r);
}
template<typename T>
bool queue<T>::full()
{
	return (r + 1) % MAX == f;
}
template<typename T>
void queue<T>::push(const T &x)
{
	if (full())
	{
		return;
	}
	data[r] = x;
	r = (r + 1) % MAX;
	
}
template<typename T>
T queue<T>::front()
{
	if (empty())
	{
		return T();
	}
	return data[f];
}
template<typename T>
void queue<T>::pop()
{
	if (empty())
	{
		return;
	}
	f = (f + 1) % MAX;
}
struct BinSearchNode
{
	int info;
	BinSearchNode *llink, *rlink;
};
int search(BinSearchNode *tree, int key, BinSearchNode **pPosition)
{
	if (tree == NULL)
	{
		return -1;
	}
	BinSearchNode *p = tree;
	BinSearchNode *q = NULL;
	while (p)
	{
		q = p;
		if (p->info == key)
		{
			*pPosition = p;
			return 1;
		}
		else if (p->info > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	*pPosition = q;
	return 0;
}
int insert(BinSearchNode **ptree, int key)
{
	if (ptree == NULL)
	{
		return -1;
	}
	BinSearchNode *position = NULL;;
	if (search(*ptree, key, &position) == 1)
	{
		return 0;
	}
	BinSearchNode *p = new BinSearchNode;
	p->info = key;
	p->llink = p->rlink = NULL;
	if (position == NULL)
	{
		*ptree = p;
	}
	else if (position->info > key)
	{
		position->llink = p;
	}
	else
	{
		position->rlink = p;
	}
	return 1;
}
void createTree(BinSearchNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int i;
	while (cin >> i)
	{
		insert(ptree, i);
	}
}
void destroyTree(BinSearchNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void deleteNode(BinSearchNode **ptree, int key)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	BinSearchNode *p = *ptree;
	BinSearchNode *parent = NULL;
	while (p)
	{
		if (p->info == key)
		{
			break;
		}
		parent = p;
		if (p->info > key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	if (p == NULL)   //未找到要删除的元素
	{
		return;
	}
	if (p->llink == NULL)
	{
		if (parent == NULL)
		{
			*ptree = p->rlink;
		}
		else if (parent->llink == p)
		{
			parent->llink = p->rlink;
		}
		else
		{
			parent->rlink = p->rlink;
		}
	}
	else
	{
		BinSearchNode *r = p->llink;
		while (r->rlink != NULL)
		{
			r = r->rlink;
		}
		r->rlink = p->rlink;
		if (parent == NULL)
		{
			*ptree = p->llink;
		}
		else if (parent->llink == p)
		{
			parent->llink = p->llink;
		}
		else
		{
			parent->rlink = p->llink;
		}
	}
	delete p;
}
void preOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchNode*> st;
	BinSearchNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
void nInOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchNode*> st;
	BinSearchNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << ' ';
}
void nPostOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinSearchNode*> st;
	BinSearchNode *p = tree;
	BinSearchNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
void guangduOrder(BinSearchNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	queue<BinSearchNode*> st;
	BinSearchNode *q = tree;
	st.push(q);
	while (!st.empty())
	{
		q = st.front();
		st.pop();
		cout << q->info << ' ';
		if (q->llink != NULL)
		{
			st.push(q->llink);
		}
		if (q->rlink != NULL)
		{
			st.push(q->rlink);
		}
	}
	cout << endl;
}
int main()
{
	BinSearchNode *tree = NULL;
	createTree(&tree);
	cout << "前序遍历=========================" << endl;
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);
	cout << "中序遍历=========================" << endl;
	inOrder(tree);
	cout << endl;
	nInOrder(tree);
	cout << "后序遍历=========================" << endl;
	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	cout << "广度优先遍历=====================" << endl;
	guangduOrder(tree);

	int n;
	cin.clear();
	while (cin >> n)
	{
		deleteNode(&tree, n);
		inOrder(tree);
		cout << endl;
	}
	destroyTree(&tree);
	return 0;
}
*/
/**************************************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int vexEnd;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vertex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum;
	int edgeNum;
	vexNode *vexs;
};
int locateVex(const GraphList &G, string &str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vertex == str)
		{
			return i;
		}
	}
	return -1;
}
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vertex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息（v0,v1,w）:" << endl;
	string v0, v1;
	int w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		int x = locateVex(G, v0);
		int y = locateVex(G, v1);
		if (x == -1 || y == -1)
		{
			cout << "此边有误，请重新输入：" << endl;
			continue;
		}
		edgeNode *p = new edgeNode;
		p->vexEnd = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraph(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		edgeNode *q = NULL;
		while (p)
		{
			q = p->nextNode;
			delete p;
			p = q;
		}
		G.vexs[i].firstNode = NULL;
	}
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			indegree[p->vexEnd]++;
			p = p->nextNode;
		}
	}
}
int AOV(const GraphList &G, int *result)
{
	if (G.vexs == NULL)
	{
		return -1;
	}
	int index = 0;
	stack<int> st;
	int *indegree = new int[G.vexNum];
	
	findIndegree(G, indegree);
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			indegree[p->vexEnd]--;
			if (indegree[p->vexEnd] == 0)
			{
				st.push(p->vexEnd);
			}
			p = p->nextNode;
		}
	}
	if (index != G.vexNum)
	{
		return -1;
	}

	return 1;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	createGraph(G);
	int *result = new int[G.vexNum];
	if (AOV(G, result) == 1)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			cout << G.vexs[result[i]].vertex << ' ';
		}
		cout << endl;
	}
	return 0;
}
*/
/********************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 10);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	int size;
	T *data;
};
template<typename T>
array<T>::array(int i = 10) : size(i), data(NULL)
{
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size)
{
	if (data)
	{
		delete[]data;
	}
	if (size)
	{
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this != &obj)
	{
		array<T> tmp = obj;
		int tmp0 = size;
		size = tmp.size;
		tmp.size = tmp0;
		T *pTmp = data;
		data = tmp.data;
		tmp.data = pTmp;
	}
	return *this;
}
template<typename T>
array<T>::~array()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1,arr2;
	arr1 = arr2 = arr;
	cout << "============================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "============================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << endl;
	}
	cout << "============================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	cout << "============================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}
	return 0;
}
*/
/**************引用计数****************************************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 10);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	void release();
	int size;
	int *count;
	T *data;
};
template<typename T>
array<T>::array(int i = 10) : size(i), data(NULL), count(new int)
{
	(*count) = 1;
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(obj.data), count(obj.count)
{
	(*count)++;
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	release();
	size = obj.size;
	data = obj.data;
	count = obj.count;
	(*count)++;
	return *this;
}
template<typename T>
array<T>::~array()
{
	release();
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
template<typename T>
void array<T>::release()
{
	(*count)--;
	if (*count == 0)
	{
		if (data)
		{
			delete[]data;
		}
		delete count;
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1, arr2;
	arr1 = arr2 = arr;
	cout << "==================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "==================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << endl;
	}
	cout << "==================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;
	}
	cout << "==================" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}
	return 0;
}
*/
/************自己实现vector***********************
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>  
#include<string>
#include <algorithm>  
#include <memory>  
using namespace std;
template<typename T>
void destroy(T* pointer)
{
	pointer->~T();
}

template<typename ForwardIterator>
void destroy(ForwardIterator first, ForwardIterator last)
{
	for (ForwardIterator it = first; it != last; ++it)
	{
		destroy(&*it);
	}
}

template<typename T>
class MyVector
{
public:
	typedef T  value_type;                         //元素类型
	typedef T* iterator;                           //迭代器
	typedef const T*const_iterator;                //指向常量的迭代器
	typedef T* pointer;                            //指向元素的指针
	typedef const T* const_pointer;                //指向常量的指针
	typedef T& reference;                          //引用
	typedef const T& const_reference;              //不能修改的引用
	typedef size_t size_type;                      //大小类型

	MyVector();                                   //默认构造函数
	MyVector(size_type n, T value = T());         //默认参数
	MyVector(iterator begin, iterator end);       //迭代器范围构造函数
	~MyVector();                                  //析构函数

	//copy control  
	MyVector(const MyVector&);                    //拷贝构造函数
	MyVector& operator=(const MyVector&);         //赋值运算符重载

	bool empty() const 
	{ 
		return begin() == end(); 
	}
	size_type size() const 
	{ 
		return (size_type)(finish - start); 
	}
	size_type capacity() const 
	{ 
		return (size_type)(end_of_storage - start); 
	}

	iterator begin() 
	{ 
		return start; 
	}
	const_iterator begin() const
	{	
		return start; 
	}
	iterator end()   
	{ 
		return finish; 
	}
	const_iterator end() const
	{ 
		return finish; 
	}

	reference operator[](size_type i)
	{ 
		return *(start + i); 
	}
	const_reference operator[](size_type i)const 
	{ 
		return *(start + i); 
	}

	void insert(iterator position, size_type n, const T& value);
	void push_back(const T& value);
	void pop_back();

	void erase(iterator first, iterator last);
	void clear();

	void reserve(size_type n);
protected:
	iterator start;   //空间的头  
	iterator finish;  //空间的尾  
	iterator end_of_storage; //可用空间的尾巴  
private:
	static allocator<T> alloc; // object to get raw memory  
};

// static class member needed to be defined outside of class  
template<typename T>
allocator<T> MyVector<T>::alloc;

// default constructor  
template<typename T>
MyVector<T>::MyVector()
: start(NULL), finish(NULL), end_of_storage(NULL)
{
}

template<typename T>
MyVector<T>::MyVector(size_type n, T value)
{
	start = alloc.allocate(n);
	end_of_storage = finish = start + n;

	for (iterator i = start; i != finish; ++i)
	{
		alloc.construct(i, value);
	}
}

template<typename T>
MyVector<T>::MyVector(iterator begin, iterator end)
{
	const size_type n = end - begin;
	start = alloc.allocate(n);                //分配空间
	finish = end_of_storage = start + n;

	uninitialized_copy(begin, end, start);
}

template<typename T>
MyVector<T>::~MyVector()
{
	::destroy(start, finish);                             //依次调用元素的析构函数

	alloc.deallocate(start, end_of_storage - start);      //释放空间
}

template<typename T>
MyVector<T>::MyVector(const MyVector& rhs)
{
	start = alloc.allocate(rhs.capacity());
	uninitialized_copy(rhs.start, rhs.finish, start);
	finish = start + (rhs.finish - rhs.start);
	end_of_storage = start + (rhs.end_of_storage - rhs.start);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	::destroy(start, finish);                             //依次调用元素的析构函数，先释放原有元素占用的空间
	alloc.deallocate(start, end_of_storage - start);      //释放空间，释放原有空间

	start = alloc.allocate(rhs.capacity());
	uninitialized_copy(rhs.start, rhs.finish, start);
	finish = start + (rhs.finish - rhs.start);
	end_of_storage = start + (rhs.end_of_storage - rhs.start);
	return *this;
}

template<typename T>
void MyVector<T>::insert(iterator position, size_type n, const T& value)
{
	if (n <= end_of_storage - finish)
	{
		if (n <= finish - position)
		{
			uninitialized_copy(finish - n, finish, finish);
			copy(position, finish - n, position + n);
			fill_n(position, n, value);
		}
		else
		{
			uninitialized_fill_n(finish, n - (finish - position), value);
			uninitialized_copy(position, finish, position + n);
			fill(position, finish, value);
		}
		finish += n;
	}
	else
	{
		pointer new_start(NULL), new_finish(NULL);
		size_type old_type = end_of_storage - start;
		size_type new_size = old_type + max(old_type, n);
		new_start = alloc.allocate(new_size);

		// copy old vector to new vector  
		new_finish = uninitialized_copy(start, position, new_start);
		uninitialized_fill_n(new_finish, n, value);
		new_finish += n;
		new_finish = uninitialized_copy(position, finish, new_finish);

		alloc.deallocate(start, end_of_storage - start);

		start = new_start;
		finish = new_finish;
		end_of_storage = new_start + new_size;
	}
}

template<typename T>
void MyVector<T>::push_back(const T &value)
{
	insert(end(), 1, value);
}

template<typename T>
void MyVector<T>::pop_back()
{
	alloc.destroy(--finish);
}

template<typename T>
void MyVector<T>::erase(iterator first, iterator last)
{
	iterator old_finish = finish;
	finish = copy(last, finish, first);
	::destroy(finish, old_finish);
}

template<typename T>
void MyVector<T>::clear()
{
	erase(start, finish);
}

template<typename T>
void MyVector<T>::reserve(size_type n)
{
	if (capacity() < n)
	{
		iterator new_start = alloc.allocate(n);
		uninitialized_copy(start, finish, new_start);

		::destroy(start, finish);
		alloc.deallocate(start, size());

		const size_type old_size = finish - start;
		start = new_start;
		finish = new_start + old_size;
		end_of_storage = new_start + n;
	}
}

int main()
{
	MyVector<string> strvec;
	string str;
	while (cin >> str)
	{
		strvec.push_back(str);
	}
	cout << strvec.capacity() << ' ' << strvec.size() << endl;
	for (MyVector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	strvec = strvec;
	MyVector<string> strvec0;
	strvec0 = strvec;
	return 0;
}
*/
/*************带指针指向堆数据的运算符重载 （考虑异常安全性）********************
#include<iostream>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
template<typename T>
class array
{
public:
	array(int i = 10) : size(i), data(NULL)
	{
		if (size)
		{
			data = new T[size];
		}
	}
	array(const array &obj) : size(obj.size), data(NULL)
	{
		if (size)
		{
			data = new T[size];
		}
	}
	array &operator=(const array &obj)
	{
		if (this != &obj)
		{
			array tmp(obj);
			int sizetmp = size;
			size = tmp.size;
			tmp.size = sizetmp;

			T *ptmp = data;
			data = tmp.data;
			tmp.data = ptmp;
		}
		return *this;
	}
	~array()
	{
		if (data)
		{
			delete[]data;
		}
	}
	T &operator[](int i)
	{
		if (i >= 0 && i < size)
		{
			return data[i];
		}
	}
private:
	int size;
	T *data;
};
class mstring
{
public:
	mstring() :size(0), str(NULL)
	{

	}
	mstring(char *str0)
	{
		size = strlen(str0);
		if (size)
		{
			str = new char[size+1];
			strcpy(str, str0);
		}
	}
	mstring &operator=(const mstring &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		if (str)
		{
			delete[]str;
		}
		size = obj.size;
		str = new char[size+1];
		strcpy(str, obj.str);
	}
	~mstring()
	{
		cout << "~mstring" << endl;
		if (str)
		{
			delete[]str;
		}
	}
	void display()
	{
		cout << str << endl;
	}
private:
	int size;
	char *str;
};

int main()
{
	array<mstring> arr(5);
	for (int i = 0; i < 5; i++)
	{
		
		arr[i] = "huang";
	}
	return 0;
}
*/
/***********************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0) :a(i){}
	~A()
	{
		cout << "~A" << endl;
	}
	friend ostream &operator<<(ostream &os, const A &obj)
	{
		os << obj.a;
		return os;
	}
private:
	int a;
};
class B
{
public:
	B(int i, int j) :aobj(i), b(j){}
	~B()
	{
		cout << "~B" << endl;
	}
	friend ostream &operator<<(ostream &os, const B &obj)
	{
		os << obj.aobj << ' ' << obj.b;
		return os;
	}
private:
	A aobj;
	int b;
};
int main()
{
	B obj(1, 2);
	cout << obj << endl;
	return 0;
}
*/
/****************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0) :a(i)
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	friend ostream &operator<<(ostream &os, const A &obj)
	{
		os << obj.a;
		return os;
	}
protected:
	int a;
};
class B :public A
{
public:
	B(int i, int j) :A(i), b(j)
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
	friend ostream &operator<<(ostream &os, const B &obj)
	{
		cout << obj.a << ' ' << obj.b;
		return os;
	}
private:
	int b;
};
int main()
{
	B obj(1, 2);
	cout << obj << endl;
	return 0;
}
*/
/*************最大递增子序列******************
#include<iostream>
using namespace std;
int LIS(int *a, int n)
{
	int *dp = new int[n];
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j]<a[i] && dp[j] + 1>dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i]>len)
		{
			len = dp[i];
		}
	}
	delete[]dp;
	return len;
}
int main()
{
	int a[] = { 1, 2, 8, 5, 3, 9 };
	cout << LIS(a, 6) << endl;
	return 0;
}
*/
/***************最大公共子序列*******************************************
#include<iostream>
#include<string>
using namespace std;
int LCS(string &str0, string &str1,string &result)
{
	int i, j;
	size_t len0 = str0.size();
	size_t len1 = str1.size();
	int **dp = new int*[len0+1];
	for (i = 0; i <= len0; i++)
	{
		dp[i] = new int[len1 + 1];
	}
	for (i = 0; i <= len0; i++)
	{
		dp[i][0] = 0;
	}
	for (j = 0; j <= len1; j++)
	{
		dp[0][j] = 0;
	}
	for (i = 1; i <= len0; i++)
	{
		for (j = 1; j <= len1; j++)
		{
			if (str0[i - 1] == str1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (dp[i-1][j]>dp[i][j-1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	i = len0;
	j = len1;
	result.clear();
	while (i && j)
	{
		if (str0[i-1] == str1[j-1] && dp[i][j] == dp[i - 1][j - 1] + 1)
		{
			result.insert(result.begin(), str0[i - 1]);
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	int buf = dp[len0][len1];
	for (i = 0; i <= len0; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	
	return buf;
}
int main()
{
	string str0, str1;
	string str;
	while (cin >> str0 >> str1)
	{
		cout << LCS(str0, str1,str)<<' ';
		cout << str << endl;
	}
	return 0;
}
*/
/*************************************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0,int j = 0) :x(i), y(j){}
	void display()
	{
		cout << x << ' ' << y << endl;
	}
	void display() const
	{
		cout <<"const:"<< x << ' ' << y << endl;
	}
private:
	int x;
	int y;
};
int main()
{
	const A obj(1, 2);
	obj.display();
	A obj0(3, 4);
	obj0.display();
	return 0;
}
*/
/************前序遍历和中序遍历重建二叉树***************************
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
BinTreeNode *construct(int *preStart, int *preEnd, int *inStart, int *inEnd)
{
	int rootValue = *preStart;
	BinTreeNode *root = new BinTreeNode;
	root->info = rootValue;
	root->llink = root->rlink = NULL;
	if (preStart == preEnd)
	{
		if (inStart == inEnd&&*preStart == *inStart)
		{
			return root;
		}
		else
		{
			cout << "huang" << *preStart <<' '<< *inStart<< endl;
			return NULL;
		}
	}
	int *p = inStart;
	while (*p != rootValue&&p <= inEnd)
	{
		p++;
	}
	if (p > inEnd)
	{
		cout << "hua" << endl;
		return NULL;
	}
	int llen = p - inStart;
	int rlen = inEnd - p;
	if (llen)
	{
		root->llink = construct(preStart + 1, preStart + llen, inStart, p - 1);
	}
	if (rlen)
	{
		root->rlink = construct(preEnd - rlen+1, preEnd, p + 1, inEnd);
	}
	return root;

}

BinTreeNode *construct(int *pre, int *in, int len)
{
	if (pre == NULL || in == NULL || len <= 0)
	{
		return NULL;
	}
	return construct(pre, pre + len - 1, in, in + len - 1);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
int main()
{
	int pre[] = { 1, 2, 4, 5, 3, 6, 7 };// { 8, 2, 1, 5, 3, 4, 7, 32, 9, 25, 11, 13 };
	int in[] = { 4, 2, 5, 1, 6, 3, 7 };// { 1, 2, 3, 4, 5, 7, 8, 9, 11, 13, 25, 32 };
	BinTreeNode *tree = construct(pre, in, 7);
	preOrder(tree);
	cout << endl;
	inOrder(tree);
	cout << endl;
	destroyTree(&tree);
	return 0;
}
*/
/*********最长递增子序列****************************
#include<iostream>
#include<vector>
using namespace std;
int LIS(int *a, int n, vector<int> &ivec)
{
	int *dp = new int[n];
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (len < dp[i])
		{
			len = dp[i];
		}
	}
	int lenbuf = len;
	int index = n - 1;
	ivec.clear();
	while (index >= 0)
	{
		if (dp[index] == lenbuf)
		{
			ivec.insert(ivec.begin(), a[index]);
			lenbuf--;
		}
		index--;
	}
	delete[]dp;
	return len;
}
int main()
{
	int a[] = { 2, 8, 4, 3, 5, 12, 1 };
	vector<int> ivec;
	cout << LIS(a, 7, ivec) << endl;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
	return 0;
}
*/
/****************四川麻将*****************************************
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isTrue(int *a)
{
	for (int i = 0; i < 7; i++)
	{
		if (a[i] < 0)
		{
			return false;
		}
		while (a[i])
		{
			if (a[i] >= 3)
			{
				a[i] -= 3;
			}
			else
			{
				int tmp = a[i];
				a[i] = 0;
				a[i + 1] -= tmp;
				a[i + 2] -= tmp;
			}
		}
	}
	if ((a[7] != 0 && a[7] != 3) && (a[8] != 0 && a[8] != 3))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool fun(vector<int> &ivec)
{
	int a[9] = { 0 };
	int b[9] = { 0 };
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		a[(*iter) - 1]++;
	}
	if (ivec.size() % 3 == 0)
	{
		if (isTrue(a))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (a[i] >= 2)
			{
				for (int j = 0; j < 9; j++)
				{
					if (j == i)
					{
						b[j] = a[j] - 2;
					}
					else
					{
						b[j] = a[j];
					}
				}
				if (isTrue(b))
				{
					return true;
				}
			}
		}
		return false;
	}
}
bool is7(vector<int> &ivec)
{
	if (ivec.size() % 2 == 1)
	{
		return false;
	}
	int a[9] = { 0 };
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		a[(*iter) - 1]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (a[i] % 2 == 1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	vector<int> Dvec, Wvec, Tvec;
	vector<string> strvec;
	string str;
	while (1)
	{
		cin >> str;
		if (str == "0")
		{
			break;
		}
		strvec.push_back(str);
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		Dvec.clear();
		Wvec.clear();
		Tvec.clear();
		string::size_type size = iter->size();
		if (size != 28)
		{
			cout << "wrong input" << endl;
		}
		for (int i = 1; i < size; i += 2)
		{
			if ((*iter)[i] == 'D')
			{
				Dvec.push_back((*iter)[i - 1] - '0');
			}
			else if ((*iter)[i] == 'W')
			{
				Wvec.push_back((*iter)[i - 1] - '0');
			}
			else if ((*iter)[i] == 'T')
			{
				Tvec.push_back((*iter)[i - 1] - '0');
			}
		}
		if (!Dvec.empty() && !Wvec.empty() && !Tvec.empty())    //如果有3种牌
		{
			cout << "false" << endl;
			continue;
		}
		if (is7(Dvec) && is7(Wvec) && is7(Tvec))                //如果是7对
		{
			cout << "true" << endl;
			continue;
		}
		if (Dvec.size() % 3 == 1 || Wvec.size() % 3 == 1 || Tvec.size() % 3 == 1)//如果有一种牌的个数除以3的余数为1
		{
			cout << "false" << endl;
			continue;
		}
		if (!fun(Dvec) || !fun(Wvec) || !fun(Tvec))
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}
	}
	return 0;
}
*/
/***************dijkstra最短路径算法********************************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int len;
	int vecEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GraphMatrix &G, path *dist)
{
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	dist[0].len = 0;
	dist[0].vecEnd = 0;
	flag[0] = 1;
	for (int i = 1; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vecEnd = -1;
		}
		else
		{
			dist[i].vecEnd = 0;
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len < minw)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		if (min == 0)
		{
			return;
		}
		flag[min] = 1;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len>dist[min].len + G.arcs[min][j])
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vecEnd = min;
			}
		}
	}
}
void showPath(path *dist, int v)
{
	stack<int> st;
	while (v)
	{
		st.push(v);
		v = dist[v].vecEnd;
	}
	cout << 0 << ' ';
	while (!st.empty())
	{
		cout << st.top() << ' ';
	}
	cout << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path *dist = new path[G.vexNum];
	int i;
	while (cin >> i)
	{
		dijkstra(G, dist);
		showPath(dist, i);
	}
	destroyGraph(G);
	return 0;
}
*/
/*************Floyd最短路径算法**********************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vecEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vecEnd[i][j] = -1;
			}
			else
			{
				dist.vecEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vecEnd[i][j] = dist.vecEnd[i][k];
				}
			}
		}
	}
}
void showPath(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << ' ';
		v0 = dist.vecEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);

	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vecEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vecEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vecEnd[i];
	}
	delete[]dist.vecEnd;
	destroyGraph(G);
	return 0;
}
*/
/******m个苹果放到n个盘子里
#include<iostream>
#include<string>
using namespace std;
int fun(int m, int n)
{
	int **dp = new int*[m + 1];
	for (int i = 0; i <= m; i++)
	{
		dp[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 1; j <= n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
			}
			else
			{
				dp[i][j] = dp[i][i];
			}
		}
	}
	int result = dp[m][n];
	for (int i = 0; i <= m; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	return result;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << fun(m, n) << endl;
	}
	return 0;
}
*/
/***********最长递增子序列********************
#include<iostream>
#include<vector>
using namespace std;
int LIS(int *a, int n)
{
	int *dp = new int[n];
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (len < dp[i])
		{
			len = dp[i];
		}
	}
	int lenbuf = len;
	int index = n - 1;
	vector<int> ivec;
	while (index >= 0)
	{
		if (dp[index] == lenbuf)
		{
			ivec.insert(ivec.begin(), a[index]);
			lenbuf--;
		}
		index--;
	}
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
	delete[]dp;
	return len;
}
int main()
{
	int a[] = { 3, 5, 2, 7, 4, 8, 6 };
	cout << LIS(a, 7) << endl;
	return 0;
}
*/
/********迪杰斯特拉最短路径算法**********************
#include<iostream>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int **arcs;
};
void createGraph(GraphMatrix &G, int n,int edgenum)
{
	G.vexNum = n;
	G.arcs = new int*[n];
	for (int i = 0; i < n; i++)
	{
		G.arcs[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	int v0, v1, w;
	for (int i = 0; i < edgenum; i++)
	{
		cin >> v0 >> v1 >> w;
		if (G.arcs[v0 - 1][v1 - 1] > w)
		{
			G.arcs[v0 - 1][v1 - 1] = w;
			G.arcs[v1 - 1][v0 - 1] = w;
		}
		
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			delete[]G.arcs[i];
		}
		delete[]G.arcs;
		G.arcs = NULL;
	}
}
int dijkstra(const GraphMatrix &G, int v0, int v1)
{
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	int *len = new int[G.vexNum];
	flag[v0 - 1] = 1;
	len[v0 - 1] = 0;
	for (int i = 0; i < G.vexNum; i++)
	{
		if (flag[i] == 0)
		{
			len[i] = G.arcs[v0 - 1][i];
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = v0-1;
		for (int j = 0; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && len[j] < minw)
			{
				minw = len[j];
				min = j;
			}
		}
		flag[min] = 1;
		for (int j = 0; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && len[j]>len[min] + G.arcs[min][j])
			{
				len[j] = len[min] + G.arcs[min][j];
			}
		}
	}
	int result = len[v1 - 1];
	delete[]flag;
	delete[]len;
	return result;
}
int main()
{
	int vexNum, edgeNum;
	int v0, v1;
	GraphMatrix G;
	G.arcs = NULL;
	cin >> vexNum >> edgeNum >> v0 >> v1;
	createGraph(G, vexNum, edgeNum);
	cout << dijkstra(G, v0, v1) << endl;
	destroyGraph(G);
	return 0;
}
*/
/*************迪杰斯特拉最短路径算法**************************************
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int **arcs;
};
struct path
{
	int len;
	int vexEnd;
};
void createGraph(GraphMatrix &G, int n, int edgenum)
{
	G.vexNum = n;
	G.arcs = new int*[n];
	for (int i = 0; i < n; i++)
	{
		G.arcs[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	int v0, v1, w;
	ifstream input;
	input.open("huang.txt");
	for (int i = 0; i < edgenum; i++)
	{
		input >> v0 >> v1 >> w;
		if (G.arcs[v0 - 1][v1 - 1] > w)
		{
			G.arcs[v0 - 1][v1 - 1] = w;
			G.arcs[v1 - 1][v0 - 1] = w;
		}

	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			delete[]G.arcs[i];
		}
		delete[]G.arcs;
		G.arcs = NULL;
	}
}
void dijkstra(const GraphMatrix &G, int v0, int v1,path *dist)
{
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	flag[v0 - 1] = 1;
	dist[v0 - 1].len = 0;
	dist[v0 - 1].vexEnd = v0 - 1;
	for (int i = 0; i < G.vexNum; i++)
	{
		if (flag[i] == 0)
		{
			dist[i].len = G.arcs[v0 - 1][i];
			if (dist[i].len == MAX)
			{
				dist[i].vexEnd = -1;
			}
			else
			{
				dist[i].vexEnd = v0 - 1;
			}
		}
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = v0 - 1;
		for (int j = 0; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len < minw)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		flag[min] = 1;
		for (int j = 0; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len>dist[min].len + G.arcs[min][j])
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vexEnd = min;
			}
		}
	}
	delete[]flag;
}
void showPath(const path *dist, int v0, int v1)
{
	stack<int> st;
	while (v1 != v0)
	{
		st.push(v1);
		v1 = dist[v1-1].vexEnd+1;
	}
	cout << v0 << "->";
	while (!st.empty())
	{
		if (st.size() != 1)
		{
			cout << st.top() << "->";
		}
		else
		{
			cout << st.top() << endl;
		}
		st.pop();
	}
}
int main()
{
	int vexNum, edgeNum;
	int v0, v1;
	GraphMatrix G;
	G.arcs = NULL;
	cin >> vexNum >> edgeNum >> v0 >> v1;
	path *dist = new path[vexNum];
	createGraph(G, vexNum, edgeNum);
	dijkstra(G, v0, v1,dist);
	cout << dist[v1 - 1].len << endl;
	showPath(dist, v0, v1);
	destroyGraph(G);
	return 0;
}
*/
/************弗洛伊德最短路径算法************************************************
#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 10000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	ifstream input("hua.txt");
	input >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		input >> v0 >> v1>>w;
		if (G.arcs[v0 - 1][v1 - 1]>w)
		{
			G.arcs[v0 - 1][v1 - 1] = w;
			G.arcs[v1 - 1][v0 - 1] = w;
		}
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			delete[]G.arcs[i];
		}
		delete[]G.arcs;
		G.arcs = NULL;
	}
}
void Floyd(const GraphMatrix &G)
{
	int **len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		len[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			len[i][j] = G.arcs[i][j];
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (len[i][j]>len[i][k] + len[k][j])
				{
					len[i][j]=len[i][k] + len[k][j];
				}
			}
		}
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (j < G.vexNum - 1)
			{
				cout << len[i][j] << ' ';
			}
			else
			{
				cout << len[i][j] << endl;
			}
		}
	}
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	Floyd(G);
	destroyGraph(G);
	return 0;
}
*/
/***n取k的组合问题的递归算法****
#include<iostream>
using namespace std;
int buf[10];
void dfs(int cur, int cnt, int n, int k)
{
	if (cnt == k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << buf[i] + 1 << ' ';
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = cur; i < n; i++)   //i<n-(k-1-cnt)
		{
			buf[cnt] = i;
			dfs(i + 1, cnt + 1, n, k);
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	dfs(0, 0, n, k);
	return 0;
}
*/
/**
#include<iostream>
using namespace std;
int buf[10];
void dfs(int cur, int cnt, int n, int k)
{
	if (cnt == k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << buf[i]+1 << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = cur; i < n; i++)
		{
			buf[cnt] = i;
			dfs(i + 1, cnt + 1, n, k);
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	dfs(0, 0, n, k);
	return 0;
}
*/
/******n取m组合问题的非递归算法（与N皇后类似）********************
#include<iostream>
using namespace std;
int x[100];
void dfs(int n, int m)
{
	int k = 1;
	while (k >= 1)
	{
		x[k]++;
		while (x[k] <= n&&x[k] <= x[k - 1])
		{
			x[k]++;
		}
		if (x[k] <= n)
		{
			if (k == m)
			{
				for (int i = 1; i <= m; i++)
				{
					cout << x[i] << ' ';
				}
				cout << endl;
			}
			else
			{
				k++;
			}
		}
		else
		{
			x[k] = 0;
			k--;
		}
	}
	
}
int main()
{
	int n, m;
	cin >> n >> m;
	dfs(n, m);
	return 0;
}
*/
/***并查集******
#include<iostream>
using namespace std;
int pre[100];
int find(int x)
{
	int r = x;
	while (r != pre[r])
	{
		r = pre[r];
	}
	int i = x, j;
	while (i != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
int main()
{
	int nodeNum;
	cin >> nodeNum;
	for (int i = 1; i <= nodeNum; i++)
	{
		pre[i] = i;
	}
	int v0, v1;
	int total = nodeNum - 1;
	while (cin >> v0 >> v1)
	{
		int f0 = find(v0);
		int f1 = find(v1);
		if (f0 != f1)
		{
			pre[f1]=f0;
			total--;
		}
	}
	cout << total << endl;
	return 0;
}
*/
/*****二叉树的宽度和深度
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void create(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	create(&(*ptree)->llink);
	create(&(*ptree)->rlink);
}
void destroy(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroy(&(*ptree)->llink);
	destroy(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void width_depth(BinTreeNode *tree, int &width, int &depth)
{
	if (tree == NULL)
	{
		width = 0;
		depth = 0;
		return;
	}
	queue<BinTreeNode*> qu;
	BinTreeNode *p = tree;
	qu.push(p);
	int last = 1;
	int cur = 0;
	int MAX = 1;
	depth = 0;
	while (!qu.empty())
	{
		while (last-- != 0)
		{
			p = qu.front();
			qu.pop();
			if (p->llink)
			{
				qu.push(p->llink);
				cur++;
			}
			if (p->rlink)
			{
				qu.push(p->rlink);
				cur++;
			}
		}
		if (MAX < cur)
		{
			MAX = cur;
		}
		last = cur;
		cur = 0;
		depth++;
	}
	width = MAX;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << ' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	create(&tree);
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);

	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	
	int depth, width;
	width_depth(tree, width, depth);
	cout << width << ' ' << depth << endl;
	destroy(&tree);
	return 0;
}
*/

/********迷宫问题
#include<iostream>
#include<vector>
using namespace std;
const int direction[4][2] = { -1, 0, 0, 1, 1, 0, 0 - 1 };
struct DataType
{
	int x, y, d;
};
void mazePath(int *maze[], int x0, int y0, int x1, int y1)
{
	int i, j, k;
	int g, h;
	vector<DataType> st;
	DataType element;
	maze[x0][y0] = 2;
	element.x = x0;
	element.y = y0;
	element.d = -1;
	st.push_back(element);
	while (!st.empty())
	{
		element = st.back();
		st.pop_back();
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k <= 3)
		{
			if (i + direction[k][0] < 0 || i + direction[k][0] > x1 || j + direction[k][1] < 0 || j + direction[k][1] > y1)
			{
				k++;
				if (k>3)
				{
					break;
				}
			}
			g = i + direction[k][0];
			h = j + direction[k][1];
			if (maze[g][h] == 0)
			{
				maze[g][h] = 2;
				element.x = i;
				element.y = j;
				element.d = k;
				st.push_back(element);
				i = g;
				j = h;
				k = -1;
			}
			if (g == x1&&h == y1&&maze[g][h] == 2)
			{
				for (vector<DataType>::iterator iter = st.begin(); iter != st.end(); ++iter)
				{
					cout << iter->x << ',' << iter->y << endl;
				}
				cout << g << ',' << h << endl;
				break;
			}
			k++;
		}
	}
}
int main()
{
	int x, y;
	cin >> x >> y;
	int **maze = new int*[x];
	for (int i = 0; i < x; i++)
	{
		maze[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> maze[i][j];
		}
	}
	mazePath(maze, 0, 0, x - 1, y - 1);
	for (int i = 0; i < x; i++)
	{
		delete[]maze[i];
	}
	delete[]maze;
	return 0;
}
*/

/***Bellman_Ford最短路径算法
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 0xfffffff;
const int N = 1001;
const int M = N*(N - 1);
int nodeNum, edgeNum, start;
struct edgeType
{
	int v0, v1, w;
};
edgeType edges[M];
int len[N], pre[N];
bool Bellman_Ford()
{
	for (int i = 1; i <= nodeNum; i++)
	{
		len[i] = (i == start) ? 0 : MAX;
	}
	for (int i = 1; i < nodeNum; i++)
	{
		for (int j = 1; j <= edgeNum; j++)
		{
			if (len[edges[j].v1]>len[edges[j].v0] + edges[j].w)
			{
				len[edges[j].v1]= len[edges[j].v0] + edges[j].w;
				pre[edges[j].v1] = edges[j].v0;
			}
		}
	}
	for (int j = 1; j <= edgeNum; j++)
	{
		if (len[edges[j].v1] > len[edges[j].v0] + edges[j].w)
		{
			return false;     //存在负权值环
		}
	}
	return true;
}
void showPath(int v)
{
	if (len[v] == MAX)
	{
		cout << "no path to " << v << endl;
		return;
	}
	stack<int> st;
	while (v != start)
	{
		st.push(v);
		v = pre[v];
	}
	cout << start << "->";
	while (!st.empty())
	{
		if (st.size() == 1)
		{
			cout << st.top() << ' ';
		}
		else
		{
			cout << st.top() << "->";
		}
		st.pop();
	}
}
int main()
{
	cin >> nodeNum >> edgeNum >> start;
	for (int i = 1; i <= edgeNum; i++)
	{
		cin >> edges[i].v0 >> edges[i].v1 >> edges[i].w;
	}
	if (Bellman_Ford())
	{
		for (int i = 1; i <= nodeNum; i++)
		{
			if (i != start)
			{
				showPath(i);
				if (len[i] != MAX)
				{
					cout << len[i] << endl;
				}
			}
		}
	}
	return 0;
}
*/
/****SPFA最短路径算法
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int MAX = 10000;
const int N = 1001;
const int M = N*(N - 1);
int nodeNum, edgeNum, start;
struct edgeType
{
	int v0, v1, w;
};
edgeType edges[M];
int len[N], pre[N];
int nextEdge[M];
int f[N];
int visited[N];
void SPFA()
{
	queue<int> qu;
	for (int i = 1; i <= nodeNum; i++)
	{
		len[i] = (i == start) ? 0 : MAX;
	}
	visited[start] = 1;
	qu.push(start);
	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();
		for (int i = f[x]; i != 0; i = nextEdge[i])
		{
			if (len[edges[i].v1] > len[edges[i].v0] + edges[i].w)
			{
				len[edges[i].v1] = len[edges[i].v0] + edges[i].w;
				pre[edges[i].v1] = edges[i].v0;
				if (!visited[edges[i].v1])
				{
					qu.push(edges[i].v1);
					visited[edges[i].v1] = 1;
				}
			}
		}
		visited[x] = 0;
	}
}
void showPath(int v)
{
	if (len[v] == MAX)
	{
		cout << "no path to " << v << endl;
		return;
	}
	stack<int> st;
	while (v != start)
	{
		st.push(v);
		v = pre[v];
	}
	cout << start << "->";
	while (!st.empty())
	{
		if (st.size() == 1)
		{
			cout << st.top() << ' ';
		}
		else
		{
			cout << st.top() << "->";
		}
		st.pop();
	}
}
int main()
{
	cin >> nodeNum >> edgeNum >> start;
	for (int i = 1; i <= edgeNum; i++)
	{
		cin >> edges[i].v0 >> edges[i].v1 >> edges[i].w;
		nextEdge[i] = f[edges[i].v0];
		f[edges[i].v0] = i;
	}
	SPFA();
	for (int i = 1; i <= nodeNum; i++)
	{
		if (i != start)
		{
			showPath(i);
			if (len[i] != MAX)
			{
				cout << len[i] << endl;
			}
		}
	}
	return 0;
}
*/
/****玛丽卡*****
#include <iostream>
#include <queue>
using namespace std;
#define N 200000
#define INF 10000000
using namespace std;
int n, m, start;
int u[N], v[N], d[N], f[N], fu[N]; //u[i]=边i的起点，v[i]=边i的终点，d[i]=第i条边对应的权值,f[i]=结点i为起点的有向边的编号,fu数组保存最短路径
bool flag = 1, del[N], visit[N]; //flag=1表示正在跑第一次SPFA,以后的SPFA不用记录最短路径；del[i]=第i条边被删除了,visit数组保存结点是否访问过
int hnext[N]; //next[i]=第i个结点对应的边,
int dist[N]; //dist[i]=到达i点的最短路距离
void SPFA()
{
	int i, j;
	queue<int>q;
	for (i = 1; i <= n; i++)
	{
		dist[i] = (i == start) ? 0 : INF;
	}
	visit[start] = 1; //标记起点访问过
	q.push(start);
	while (!q.empty())
	{
		int o = q.front(); //获得队首元素o
		q.pop();
		int nowp; //当前访问到的边
		for (nowp = f[o]; nowp != 0; nowp = hnext[nowp])
		{
			if (del[nowp]) continue; //此边已经删掉了，则跳过
			if (dist[u[nowp]] + d[nowp]<dist[v[nowp]]) //如果到达边nowp终点的最短路比到达nowp起点最短路和边nowp的权值大，则松弛，将当前边nowp入队
			{
				dist[v[nowp]] = dist[u[nowp]] + d[nowp];
				if (flag) fu[v[nowp]] = nowp; //如果是在跑第一遍SPFA，则记录下当前的点是由哪条边扩展而来
				if (!visit[v[nowp]]) //当前边的起点没有访问过
				{
					q.push(v[nowp]); //将当前边的起点入队
					visit[v[nowp]] = 1; //标记当前边的起点访问过
				}
			}
		}
		visit[o] = 0; //复原
	}
}
int main()
{
	int mint;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> d[i];
		hnext[i] = f[u[i]];
		f[u[i]] = i;
		v[i + m] = u[i]; //无向图,记录完有向边后再记录反向的边
		u[i + m] = v[i];
		d[i + m] = d[i];
		hnext[i + m] = f[u[i + m]];
		f[u[i + m]] = i + m;
	}
	start = n; //初始时SPFA起点为n
	SPFA();
	flag = 0; //第一次spfa结束，标记
	mint = dist[1];
	for (int nowp = fu[1]; nowp != 0; nowp = fu[u[nowp]]) //寻找最短路上的边，枚举删除一条边，使最终最短路尽可能地大
	{
		del[nowp] = 1; //标记此边被删
		if (nowp<m) del[m - nowp] = 1; //反向边也要处理
		else del[nowp - m] = 1;
		SPFA();
		del[nowp] = 0; //复原
		if (nowp<m) del[m - nowp] = 0;
		else del[nowp - m] = 0;
		if (mint<dist[1] && dist[1] != INF) //当从起点到终点有路可走，且删除边nowp后的最短路比当前最大最短路大，更新
			mint = dist[1];
	}
	cout << mint << endl;
	return 0;
}
*/
/**玛丽卡
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int MAX = 0x7fffffff;
const int N = 1001;
const int M = N*(N-1);
int nodeNum, edgeNum, start;
struct edgeNode
{
	int v0, v1, w;
};
edgeNode edges[M];
int len[N];
int nextEdge[M];
int f[N];
int visited[N];
int del[M];
int SPFA()
{
	queue<int> qu;
	for (int i = 1; i <= nodeNum; i++)
	{
		len[i] = (i == start) ? 0 : MAX;
	}
	visited[start] = 1;
	qu.push(start);
	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();
		for (int i = f[x]; i != 0; i = nextEdge[i])
		{
			if (del[i])
			{
				continue;
			}
			if (len[edges[i].v1] > len[edges[i].v0] + edges[i].w)
			{
				len[edges[i].v1] = len[edges[i].v0] + edges[i].w;
				if (!visited[edges[i].v1])
				{
					qu.push(edges[i].v1);
					visited[edges[i].v1] = 1;
				}
			}
		}
		visited[x] = 0;
	}
	return len[nodeNum];
}
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	cin >> nodeNum >> edgeNum;
	for (int i = 1; i <= edgeNum; i++)
	{
		cin >> edges[i].v0 >> edges[i].v1 >> edges[i].w;
		nextEdge[i] = f[edges[i].v0];
		f[edges[i].v0] = i;
		edges[i + edgeNum].v0 = edges[i].v1;
		edges[i + edgeNum].v1 = edges[i].v0;
		edges[i + edgeNum].w = edges[i].w;
		nextEdge[i + edgeNum] = f[edges[i + edgeNum].v0];
		f[edges[i + edgeNum].v0] = i + edgeNum;

	}
	start = 1;
	int MaxMin = 0;
	for (int i = 1; i <= edgeNum; i++)
	{
		del[i] = 1;
		del[i + edgeNum] = 1;
		int tmp = SPFA();
		if (tmp != MAX)
		{
			MaxMin = max(MaxMin, tmp );
		}
		del[i] = 0;
		del[i + edgeNum] = 0;
	}
	cout << MaxMin << endl;
	return 0;
}
*/
/****
#include<iostream>
#include<stack>
using namespace std;
//AVL树节点信息
template<class T>
class TreeNode
{
public:
	TreeNode() :lson(NULL), rson(NULL), hgt(0){}
	T data;//值
	int hgt;//以此节点为根的树的高度
	TreeNode* lson;//指向左儿子的地址
	TreeNode* rson;//指向右儿子的地址
};
//AVL树类的属性和方法声明
template<class T>
class AVLTree
{
private:
	TreeNode<T>* root;//根节点
	void insertpri(TreeNode<T>* &node, T x);//插入
	TreeNode<T>* findpri(TreeNode<T>* node, T x);//查找
	void preOrder(TreeNode<T>* node);//前序遍历递归
	void inOrder(TreeNode<T>* node);//中序遍历递归
	void postOrder(TreeNode<T>* node);//后序遍历递归
	void Deletepri(TreeNode<T>* &node, T x);//删除

	int height(TreeNode<T>* node);//求树的高度
	void SingRotateLeft(TreeNode<T>* &k2);//左左情况下的旋转
	void SingRotateRight(TreeNode<T>* &k2);//右右情况下的旋转
	void DoubleRotateLR(TreeNode<T>* &k3);//左右情况下的旋转
	void DoubleRotateRL(TreeNode<T>* &k3);//右左情况下的旋转
	int Max(int cmpa, int cmpb);//求最大值

public:
	AVLTree() :root(NULL){}
	void insert(T x);//插入接口
	TreeNode<T>* find(T x);//查找接口
	void Delete(T x);//删除接口
	void preOrder();//前序遍历递归接口
	void inOrder();//中序遍历递归接口
	void postOrder();//后序遍历递归接口
	void nPreOrder();//前序遍历非递归
	void nInOrder();//中序遍历非递归
	void nPostOrder();//后续遍历非递归
};
//计算以节点为根的树的高度
template<class T>
int AVLTree<T>::height(TreeNode<T>* node)
{
	if (node != NULL)
	{
		return node->hgt;
	}
	return -1;
}
//求最大值
template<class T>
int AVLTree<T>::Max(int cmpa, int cmpb)
{
	return cmpa>cmpb ? cmpa : cmpb;
}
//左左情况下的旋转
template<class T>
void AVLTree<T>::SingRotateLeft(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->lson;
	k2->lson = k1->rson;
	k1->rson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->lson), k2->hgt) + 1;
	k2 = k1;
}
//右右情况下的旋转
template<class T>
void AVLTree<T>::SingRotateRight(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->rson;
	k2->rson = k1->lson;
	k1->lson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->rson), k2->hgt) + 1;
	k2 = k1;
}
//左右情况的旋转
template<class T>
void AVLTree<T>::DoubleRotateLR(TreeNode<T>* &k3)
{
	SingRotateRight(k3->lson);
	SingRotateLeft(k3);
}
//右左情况的旋转
template<class T>
void AVLTree<T>::DoubleRotateRL(TreeNode<T>* &k3)
{
	SingRotateLeft(k3->rson);
	SingRotateRight(k3);
}
//插入
template<class T>
void AVLTree<T>::insertpri(TreeNode<T>* &node, T x)
{
	if (node == NULL)//如果节点为空,就在此节点处加入x信息
	{
		node = new TreeNode<T>();
		node->data = x;
		return;
	}
	if (node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
	{
		insertpri(node->lson, x);
		if (2 == height(node->lson) - height(node->rson))
		{
			if (x<node->lson->data)
				SingRotateLeft(node);
			else
				DoubleRotateLR(node);
		}
	}
	else if (node->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
	{
		insertpri(node->rson, x);
		if (2 == height(node->rson) - height(node->lson))//如果高度之差为2的话就失去了平衡,需要旋转
		{
			if (x>node->rson->data)
				SingRotateRight(node);
			else
				DoubleRotateRL(node);
		}
	}
	node->hgt = Max(height(node->lson), height(node->rson))+1;
}
//插入接口
template<class T>
void AVLTree<T>::insert(T x)
{
	insertpri(root, x);
}
//查找
template<class T>
TreeNode<T>* AVLTree<T>::findpri(TreeNode<T>* node, T x)
{
	if (node == NULL)//如果节点为空说明没找到,返回NULL
	{
		return NULL;
	}
	if (node->data>x)//如果x小于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->lson, x);
	}
	else if (node->data<x)//如果x大于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->rson, x);
	}
	else return node;//如果相等,就找到了此节点
}
//查找接口
template<class T>
TreeNode<T>* AVLTree<T>::find(T x)
{
	return findpri(root, x);
}
//删除
template<class T>
void AVLTree<T>::Deletepri(TreeNode<T>* &node, T x)
{
	if (node == NULL) //没有找到值是x的节点
	{
		return;
	}
	if (x < node->data)     //在左子树中
	{
		Deletepri(node->lson, x);//如果x小于节点的值,就继续在节点的左子树中删除x
		if (2 == height(node->rson) - height(node->lson))
		{
			if (node->rson->lson != NULL && (height(node->rson->lson)>height(node->rson->rson)))
				DoubleRotateRL(node);
			else
				SingRotateRight(node);
		}
	}
	else if (x > node->data) //在右子树中
	{
		Deletepri(node->rson, x);//如果x大于节点的值,就继续在节点的右子树中删除x
		if (2 == height(node->lson) - height(node->rson))
		{
			if (node->lson->rson != NULL && (height(node->lson->rson)>height(node->lson->lson)))
				DoubleRotateLR(node);
			else
				SingRotateLeft(node);
		}
	}
	else//如果相等,此节点就是要删除的节点
	{
		if (node->lson&&node->rson)//此节点有两个儿子
		{
			TreeNode<T>* temp = node->rson;//temp指向节点的右儿子
			while (temp->lson != NULL) temp = temp->lson;//找到右子树中值最小的节点
			//把右子树中最小节点的值赋值给本节点
			node->data = temp->data;
			Deletepri(node->rson, temp->data);//删除右子树中最小值的节点
			if (2 == height(node->lson) - height(node->rson))
			{
				if (node->lson->rson != NULL && (height(node->lson->rson)>height(node->lson->lson)))
					DoubleRotateLR(node);
				else
					SingRotateLeft(node);
			}
		}
		else//此节点有1个或0个儿子
		{
			TreeNode<T>* temp = node;
			if (node->lson == NULL)//有右儿子或者没有儿子
				node = node->rson;
			else if (node->rson == NULL)//有左儿子
				node = node->lson;
			delete(temp);
			temp = NULL;
		}
	}
	if (node == NULL) return;
	node->hgt = Max(height(node->lson), height(node->rson)) + 1;
	return;
}
//删除接口
template<class T>
void AVLTree<T>::Delete(T x)
{
	Deletepri(root, x);
}
//前序遍历递归
template<typename T>
void AVLTree<T>::preOrder(TreeNode<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << ' ';
	preOrder(node->lson);
	preOrder(node->rson);
}
//前序遍历递归接口
template<typename T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
}
//中序遍历递归
template<class T>
void AVLTree<T>::inOrder(TreeNode<T>* node)
{
	if (node == NULL) return;
	inOrder(node->lson);//先遍历左子树
	cout << node->data << " ";//输出根节点
	inOrder(node->rson);//再遍历右子树
}
//中序遍历递归接口
template<class T>
void AVLTree<T>::inOrder()
{
	inOrder(root);
}
//后序遍历递归
template<typename T>
void AVLTree<T>::postOrder(TreeNode<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	postOrder(node->lson);
	postOrder(node->rson);
	cout << node->data << ' ';
}
//后序遍历递归接口
template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
}
//前序遍历非递归
template<typename T>
void AVLTree<T>::nPreOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode<T>*> st;
	TreeNode<T> *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->data << ' ';
			st.push(p->rson);
			st.push(p->lson);
		}
	}
	cout << endl;
}
//中序遍历非递归
template<class T>
void AVLTree<T>::nInOrder()
{
	if (root == NULL)
	{
		return;
	}
	TreeNode<T> *p = root;
	stack<TreeNode<T>*> st;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->lson;
		}
		p = st.top();
		st.pop();
		cout << p->data << ' ';
		p = p->rson;
	}
	cout << endl;
}
//后序遍历非递归
template<typename T>
void AVLTree<T>::nPostOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode<T>*> st;
	TreeNode<T> *p = root;
	TreeNode<T> *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rson;
			p = p->lson;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->data << ' ';
		if (!st.empty() && st.top()->lson == p)
		{
			p = st.top()->rson;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	AVLTree<int> tree;
	int x;
	while (cin >> x)
	{
		tree.insert(x);
	}
	tree.preOrder();
	cout << endl;
	tree.nPreOrder();
	tree.inOrder();
	cout << endl;
	tree.nInOrder();
	tree.postOrder();
	cout << endl;
	tree.nPostOrder();
	cin.clear();
	while (cin >> x)
	{
		tree.Delete(x);
		tree.nPreOrder();
		tree.nInOrder();
		tree.nPostOrder();
	}
	
	return 0;
}
*/
/*******二叉平衡树C++递归实现*
#include<iostream>
#include<stack>
using namespace std;
//AVL树节点信息
template<class T>
class TreeNode
{
public:
	TreeNode() :lson(NULL), rson(NULL), hgt(0){}
	T data;//值
	int hgt;//以此节点为根的树的高度
	TreeNode* lson;//指向左儿子的地址
	TreeNode* rson;//指向右儿子的地址
};
//AVL树类的属性和方法声明
template<class T>
class AVLTree
{
private:
	TreeNode<T>* root;//根节点
	void insertpri(TreeNode<T>** pnode, T x);//插入
	TreeNode<T>* findpri(TreeNode<T>* node, T x);//查找
	void preOrder(TreeNode<T>* node);//前序遍历递归
	void inOrder(TreeNode<T>* node);//中序遍历递归
	void postOrder(TreeNode<T>* node);//后序遍历递归
	void Deletepri(TreeNode<T>** pnode, T x);//删除

	int height(TreeNode<T>* node);//求树的高度
	TreeNode<T>* SingRotateLeft(TreeNode<T>* k2);//左左情况下的旋转
	TreeNode<T>* SingRotateRight(TreeNode<T>* k2);//右右情况下的旋转
	TreeNode<T>* DoubleRotateLR(TreeNode<T>* k3);//左右情况下的旋转
	TreeNode<T>* DoubleRotateRL(TreeNode<T>* k3);//右左情况下的旋转
	int Max(int cmpa, int cmpb);//求最大值

public:
	AVLTree() :root(NULL){}
	void insert(T x);//插入接口
	TreeNode<T>* find(T x);//查找接口
	void Delete(T x);//删除接口
	void preOrder();//前序遍历递归接口
	void inOrder();//中序遍历递归接口
	void postOrder();//后序遍历递归接口
	void nPreOrder();//前序遍历非递归
	void nInOrder();//中序遍历非递归
	void nPostOrder();//后续遍历非递归
};
//计算以节点为根的树的高度
template<class T>
int AVLTree<T>::height(TreeNode<T>* node)
{
	if (node != NULL)
	{
		return node->hgt;
	}
	return -1;
}
//求最大值
template<class T>
int AVLTree<T>::Max(int cmpa, int cmpb)
{
	return cmpa>cmpb ? cmpa : cmpb;
}
//左左情况下的旋转
template<class T>
TreeNode<T>* AVLTree<T>::SingRotateLeft(TreeNode<T>* k2)
{
	TreeNode<T>* k1;
	k1 = k2->lson;
	k2->lson = k1->rson;
	k1->rson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->lson), k2->hgt) + 1;
	return k1;
}
//右右情况下的旋转
template<class T>
TreeNode<T>* AVLTree<T>::SingRotateRight(TreeNode<T>* k2)
{
	TreeNode<T>* k1;
	k1 = k2->rson;
	k2->rson = k1->lson;
	k1->lson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->rson), k2->hgt) + 1;
	return k1;
}
//左右情况的旋转
template<class T>
TreeNode<T>* AVLTree<T>::DoubleRotateLR(TreeNode<T>* k3)
{
	k3->lson=SingRotateRight(k3->lson);
	return SingRotateLeft(k3);
}
//右左情况的旋转
template<class T>
TreeNode<T>* AVLTree<T>::DoubleRotateRL(TreeNode<T>* k3)
{
	k3->rson=SingRotateLeft(k3->rson);
	return SingRotateRight(k3);
}
//插入
template<class T>
void AVLTree<T>::insertpri(TreeNode<T>** pnode, T x)
{
	if (*pnode == NULL)//如果节点为空,就在此节点处加入x信息
	{
		*pnode = new TreeNode<T>();
		(*pnode)->data = x;
		return;
	}
	if ((*pnode)->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
	{
		insertpri(&(*pnode)->lson, x);
		if (2 == height((*pnode)->lson) - height((*pnode)->rson))
		{
			if (x<(*pnode)->lson->data)
				*pnode = SingRotateLeft(*pnode);
			else
				*pnode = DoubleRotateLR(*pnode);
		}
	}
	else if ((*pnode)->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
	{
		insertpri(&(*pnode)->rson, x);
		if (2 == height((*pnode)->rson) - height((*pnode)->lson))//如果高度之差为2的话就失去了平衡,需要旋转
		{
			if (x>(*pnode)->rson->data)
				*pnode=SingRotateRight(*pnode);
			else
				*pnode=DoubleRotateRL(*pnode);
		}
	}
	(*pnode)->hgt = Max(height((*pnode)->lson), height((*pnode)->rson)) + 1;
}
//插入接口
template<class T>
void AVLTree<T>::insert(T x)
{
	insertpri(&root, x);
}
//查找
template<class T>
TreeNode<T>* AVLTree<T>::findpri(TreeNode<T>* node, T x)
{
	if (node == NULL)//如果节点为空说明没找到,返回NULL
	{
		return NULL;
	}
	if (node->data>x)//如果x小于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->lson, x);
	}
	else if (node->data<x)//如果x大于节点的值,就继续在节点的左子树中查找x
	{
		return findpri(node->rson, x);
	}
	else return node;//如果相等,就找到了此节点
}
//查找接口
template<class T>
TreeNode<T>* AVLTree<T>::find(T x)
{
	return findpri(root, x);
}
//删除
template<class T>
void AVLTree<T>::Deletepri(TreeNode<T>** pnode, T x)
{
	if (*pnode == NULL) //没有找到值是x的节点
	{
		return;
	}
	if (x < (*pnode)->data)     //在左子树中
	{
		Deletepri(&(*pnode)->lson, x);//如果x小于节点的值,就继续在节点的左子树中删除x
		if (2 == height((*pnode)->rson) - height((*pnode)->lson))
		{
			if ((*pnode)->rson->lson != NULL && (height((*pnode)->rson->lson)>height((*pnode)->rson->rson)))
				*pnode=DoubleRotateRL(*pnode);
			else
				*pnode=SingRotateRight(*pnode);
		}
	}
	else if (x > (*pnode)->data) //在右子树中
	{
		Deletepri(&(*pnode)->rson, x);//如果x大于节点的值,就继续在节点的右子树中删除x
		if (2 == height((*pnode)->lson) - height((*pnode)->rson))
		{
			if ((*pnode)->lson->rson != NULL && (height((*pnode)->lson->rson)>height((*pnode)->lson->lson)))
				*pnode = DoubleRotateLR(*pnode);
			else
				*pnode=SingRotateLeft(*pnode);
		}
	}
	else//如果相等,此节点就是要删除的节点
	{
		if ((*pnode)->lson && (*pnode)->rson)//此节点有两个儿子
		{
			TreeNode<T>* temp = (*pnode)->rson;//temp指向节点的右儿子
			while (temp->lson != NULL) temp = temp->lson;//找到右子树中值最小的节点
			//把右子树中最小节点的值赋值给本节点
			(*pnode)->data = temp->data;
			Deletepri(&(*pnode)->rson, temp->data);//删除右子树中最小值的节点
			if (2 == height((*pnode)->lson) - height((*pnode)->rson))
			{
				if ((*pnode)->lson->rson != NULL && (height((*pnode)->lson->rson)>height((*pnode)->lson->lson)))
					*pnode=DoubleRotateLR(*pnode);
				else
					*pnode=SingRotateLeft(*pnode);
			}
		}
		else//此节点有1个或0个儿子
		{
			TreeNode<T>* temp = *pnode;
			if ((*pnode)->lson == NULL)//有右儿子或者没有儿子
				*pnode = (*pnode)->rson;
			else if ((*pnode)->rson == NULL)//有左儿子
				*pnode = (*pnode)->lson;
			delete(temp);
			temp = NULL;
		}
	}
	if (*pnode == NULL) return;
	(*pnode)->hgt = Max(height((*pnode)->lson), height((*pnode)->rson)) + 1;
	return;
}
//删除接口
template<class T>
void AVLTree<T>::Delete(T x)
{
	Deletepri(&root, x);
}
//前序遍历递归
template<typename T>
void AVLTree<T>::preOrder(TreeNode<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << ' ';
	preOrder(node->lson);
	preOrder(node->rson);
}
//前序遍历递归接口
template<typename T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
}
//中序遍历递归
template<class T>
void AVLTree<T>::inOrder(TreeNode<T>* node)
{
	if (node == NULL) return;
	inOrder(node->lson);//先遍历左子树
	cout << node->data << " ";//输出根节点
	inOrder(node->rson);//再遍历右子树
}
//中序遍历递归接口
template<class T>
void AVLTree<T>::inOrder()
{
	inOrder(root);
}
//后序遍历递归
template<typename T>
void AVLTree<T>::postOrder(TreeNode<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	postOrder(node->lson);
	postOrder(node->rson);
	cout << node->data << ' ';
}
//后序遍历递归接口
template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
}
//前序遍历非递归
template<typename T>
void AVLTree<T>::nPreOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode<T>*> st;
	TreeNode<T> *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->data << ' ';
			st.push(p->rson);
			st.push(p->lson);
		}
	}
	cout << endl;
}
//中序遍历非递归
template<class T>
void AVLTree<T>::nInOrder()
{
	if (root == NULL)
	{
		return;
	}
	TreeNode<T> *p = root;
	stack<TreeNode<T>*> st;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->lson;
		}
		p = st.top();
		st.pop();
		cout << p->data << ' ';
		p = p->rson;
	}
	cout << endl;
}
//后序遍历非递归
template<typename T>
void AVLTree<T>::nPostOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode<T>*> st;
	TreeNode<T> *p = root;
	TreeNode<T> *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rson;
			p = p->lson;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->data << ' ';
		if (!st.empty() && st.top()->lson == p)
		{
			p = st.top()->rson;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	AVLTree<int> tree;
	int x;
	while (cin >> x)
	{
		tree.insert(x);
	}
	tree.preOrder();
	cout << endl;
	tree.nPreOrder();
	tree.inOrder();
	cout << endl;
	tree.nInOrder();
	tree.postOrder();
	cout << endl;
	tree.nPostOrder();
	cin.clear();
	while (cin >> x)
	{
		tree.Delete(x);
		tree.nPreOrder();
		tree.nInOrder();
		tree.nPostOrder();
	}

	return 0;
}
*/
/***********二叉平衡树c语言递归实现****************
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int key;
	int hight;
	BinTreeNode *llink, *rlink;
};
int max(int x, int y)
{
	return x > y ? x : y;
}
int getHight(BinTreeNode *tree)
{
	if (tree)
	{
		return tree->hight;
	}
	return -1;
}
BinTreeNode *createNode(int key)
{
	BinTreeNode *p = new BinTreeNode;
	if (p)
	{
		p->key = key;
		p->hight = 0;
		p->llink = p->rlink = NULL;
	}
	return p;
}

BinTreeNode *LL(BinTreeNode *a)
{
	BinTreeNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink = a;
	a->hight = max(getHight(a->llink), getHight(a->rlink)) + 1;
	b->hight = max(getHight(b->llink), a->hight);
	return b;
}
BinTreeNode *RR(BinTreeNode *a)
{
	BinTreeNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink = a;
	a->hight = max(getHight(a->llink), getHight(a->rlink)) + 1;
	b->hight = max(a->hight, getHight(b->rlink)) + 1;
	return b;
}
BinTreeNode *LR(BinTreeNode *a)
{
	a->llink = RR(a->llink);
	return LL(a);
}
BinTreeNode *RL(BinTreeNode *a)
{
	a->rlink = LL(a->rlink);
	return RR(a);
}
void insert(BinTreeNode **ptree, int key)
{
	if (*ptree == NULL)
	{
		*ptree = createNode(key);
		return;
	}
	if (key<(*ptree)->key)
	{
		insert(&(*ptree)->llink, key);
		if (2 == getHight((*ptree)->llink) - getHight((*ptree)->rlink))
		{
			if (key<(*ptree)->llink->key)
			{
				*ptree = LL(*ptree);
			}
			else
			{
				*ptree = LR(*ptree);
			}
		}
	}
	else if (key>(*ptree)->key)
	{
		insert(&(*ptree)->rlink, key);
		if (2 == getHight((*ptree)->rlink) - getHight((*ptree)->llink))
		{
			if (key > (*ptree)->rlink->key)
			{
				*ptree = RR(*ptree);
			}
			else
			{
				*ptree = RL(*ptree);
			}
		}
	}
	(*ptree)->hight = max(getHight((*ptree)->llink), getHight((*ptree)->rlink)) + 1;
}
void deleteNode(BinTreeNode **ptree, int key)
{
	if (*ptree == NULL)
	{
		return;
	}
	if (key < (*ptree)->key)   //删除的结点在左边
	{
		deleteNode(&(*ptree)->llink, key);
		if (2 == getHight((*ptree)->rlink) - getHight((*ptree)->llink))
		{
			if ((*ptree)->rlink->llink != NULL&&getHight((*ptree)->rlink->llink)>getHight((*ptree)->rlink->rlink))
			{
				*ptree = RL(*ptree);
			}
			else
			{
				*ptree = RR(*ptree);
			}
		}
	}
	else if (key > (*ptree)->key)             //删除的结点在右边
	{
		deleteNode(&(*ptree)->rlink, key);
		if (2 == getHight((*ptree)->llink) - getHight((*ptree)->rlink))
		{
			if ((*ptree)->llink->rlink != NULL&&getHight((*ptree)->llink->rlink) > getHight((*ptree)->llink->llink))
			{
				*ptree = LR(*ptree);
			}
			else
			{
				*ptree = LL(*ptree);
			}
		}
	}
	else                                 //根结点正是要删除的结点
	{
		if ((*ptree)->llink && (*ptree)->rlink)                 //此结点有两个儿子
		{
			BinTreeNode *r = (*ptree)->rlink;
			while (r->llink != NULL)
			{
				r = r->llink;
			}
			(*ptree)->key = r->key;
			deleteNode(&(*ptree)->rlink, r->key);
			if (2 == getHight((*ptree)->llink) - getHight((*ptree)->rlink))
			{
				if ((*ptree)->llink->rlink != NULL&&getHight((*ptree)->llink->rlink) > getHight((*ptree)->llink->llink))
				{
					*ptree = LR(*ptree);
				}
				else
				{
					*ptree = LL(*ptree);
				}
			}
		}
		else
		{
			BinTreeNode *r = *ptree;
			if ((*ptree)->llink == NULL)
			{
				(*ptree) = (*ptree)->rlink;
			}
			else
			{
				(*ptree) = (*ptree)->llink;
			}
			delete r;
			r = NULL;
		}
	}
	if (*ptree != NULL)
	{
		(*ptree)->hight = max(getHight((*ptree)->llink), getHight((*ptree)->rlink)) + 1;
	}
}
void createTree(BinTreeNode **ptree)
{
	int tmp;
	while (cin >> tmp)
	{
		insert(ptree, tmp);
	}
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->key << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->key << ' ';
	inOrder(tree->rlink);
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->key << ' ';
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	cout << endl;
	inOrder(tree);
	cout << endl;
	postOrder(tree);
	cout << endl;

	cin.clear();
	int i;
	while (cin >> i)
	{
		deleteNode(&tree,i);
		preOrder(tree);
		cout << endl;
		inOrder(tree);
		cout << endl;
		postOrder(tree);
		cout << endl;
	}
	destroyTree(&tree);
	return 0;
}
*/
/************二叉树C++实现***********************
#include<iostream>
#include<string>
#include<stack>
using namespace std;
template<typename T>
class BinTreeNode
{
public:
	BinTreeNode(T x = T()) :llink(NULL), rlink(NULL), key(x){}//构造函数
	~BinTreeNode()                                            //析构函数 
	{
		if (llink)
		{
			delete llink;
		}
		if (rlink)
		{
			delete rlink;
		}
		cout << "~" << key << ' ';
	}
	T key;
	BinTreeNode *llink, *rlink;
private:
	BinTreeNode(const BinTreeNode &obj);
	BinTreeNode &operator=(const BinTreeNode &obj);
};
template<typename T>
class Tree
{
public:
	Tree() :root(NULL)                          //构造函数
	{
		createTree(&root);
	}
	~Tree()                                    //析构函数
	{
		destroyTree(&root);
		cout << endl;
	}
	Tree(const Tree &obj);                      //拷贝构造函数
	Tree &operator=(const Tree &obj);         //赋值运算符重载
	void preOrder();      //前序遍历递归接口
	void nPreOrder();    //前序遍历非递归
	void inOrder();      //中序遍历递归接口
	void nInOrder();     //中序遍历非递归
	void postOrder();    //后序遍历递归接口
	void nPostOrder();   //后序遍历非递归
private:
	BinTreeNode<T> *copyTree(BinTreeNode<T> *tree);
	void preOrder(BinTreeNode<T> *tree);
	void inOrder(BinTreeNode<T> *tree);
	void postOrder(BinTreeNode<T> *tree);
	void createTree(BinTreeNode<T> **ptree);
	void destroyTree(BinTreeNode<T> **ptree);
	BinTreeNode<T> *root;
};
template<typename T>
BinTreeNode<T> *Tree<T>::copyTree(BinTreeNode<T> *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	BinTreeNode<T> *p = new BinTreeNode<T>(tree->key);
	p->llink = copyTree(tree->llink);
	p->rlink = copyTree(tree->rlink);
	return p;
}
template<typename T>
Tree<T>::Tree(const Tree &obj)
{
	root = copyTree(obj.root);
}
template<typename T>
Tree<T> &Tree<T>::operator=(const Tree &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	destroyTree(&root);
	root = copyTree(obj.root);
	return *this;
}
template<typename T>
void Tree<T>::preOrder(BinTreeNode<T> *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->key << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
template<typename T>
void Tree<T>::preOrder()
{
	preOrder(root);
}
template<typename T>
void Tree<T>::nPreOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<BinTreeNode<T>*> st;
	BinTreeNode<T> *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
template<typename T>
void Tree<T>::inOrder(BinTreeNode<T> *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->key << ' ';
	inOrder(tree->rlink);
}
template<typename T>
void Tree<T>::inOrder()
{
	inOrder(root);
}
template<typename T>
void Tree<T>::nInOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<BinTreeNode<T>*> st;
	BinTreeNode<T> *p = root;
	while (p||!st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
template<typename T>
void Tree<T>::postOrder(BinTreeNode<T> *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->key << ' ';
}
template<typename T>
void Tree<T>::postOrder()
{
	postOrder(root);
}
template<typename T>
void Tree<T>::nPostOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<BinTreeNode<T>*> st;
	BinTreeNode<T> *p = root;
	BinTreeNode<T> *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
template<typename T>
void Tree<T>::createTree(BinTreeNode<T> **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	T tmp;
	cin >> tmp;
	if (tmp == T())
	{
		return;
	}
	*ptree = new BinTreeNode<T>(tmp);
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}

template<typename T>
void Tree<T>::destroyTree(BinTreeNode<T> **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete (*ptree);
	*ptree = NULL;
}
int main()
{
	//---堆内建对象测试
	Tree<int> *ptree=new Tree<int>;
	ptree->preOrder();
	cout << endl;
	delete ptree;
    //栈内建对象测试
	Tree<int> tree;
	tree.preOrder();
	cout << endl;
	tree.nPreOrder();

	tree.inOrder();
	cout << endl;
	tree.nInOrder();

	tree.postOrder();
	cout << endl;
	tree.nPostOrder();
	//拷贝构造函数测试
	Tree<int> tree0(tree);
	tree0.nPreOrder();
	tree0.nInOrder();
	tree0.nPostOrder();
	//赋值运算符重载测试
	Tree<int> tree1;
	tree1 = tree;
	tree1.nPreOrder();
	tree1.nInOrder();
	tree1.nPostOrder();
	return 0;
}
*/
/********直接定义拷贝构造函数和赋值运算符重载***
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 10);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	int size;
	T *data;
};
template<typename T>
array<T>::array(int i = 10) : size(i), data(NULL)
{
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(NULL)
{
	if (size)
	{
		delete[]data;
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this != &obj)
	{
		array<T> tmp(obj);
		T *dataTmp = data;
		data = tmp.data;
		tmp.data = dataTmp;

		int sizeTmp = size;
		size = tmp.size;
		tmp.size = sizeTmp;
	}
	return *this;
}
template<typename T>
array<T>::~array()
{
	if (data)
	{
		delete[]data;
	}
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1;
	arr1 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/***************引用计数******************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 10);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	void release();
	int size;
	T *data;
	int *count;
};
template<typename T>
array<T>::array(int i = 10) : size(i), data(NULL), count(new int)
{
	(*count) = 1;
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(obj.data), count(obj.count)
{
	(*count)++;
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	release();
	size = obj.size;
	data = obj.data;
	count = obj.count;
	(*count)++;
	return *this;
}
template<typename T>
array<T>::~array()
{
	release();
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
template<typename T>
void array<T>::release()
{
	(*count)--;
	if (*count == 0)
	{
		if (data)
		{
			delete[]data;
		}
		delete count;
	}
}
int main()
{
	array<string> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	array<string> arr0(arr);
	array<string> arr1, arr2;
	arr1 = arr2 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr0[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/****多态实例（图形面积计算）
#include<iostream>
using namespace std;
class shape
{
public:
	shape(double i, double j) :x(i), y(j){}
	virtual double area() = 0;
protected:
	double x, y;
};
class juxing :public shape
{
public:
	juxing(int i, int j) :shape(i, j){}
	double area()
	{
		return x*y;
	}
private:
};
class sanjiaoxing :public shape
{
public:
	sanjiaoxing(int i, int j) :shape(i, j){}
	double area()
	{
		return x*y / 2;
	}
private:
};
class yuanxing :public shape
{
public:
	yuanxing(int i) :shape(i, i){}
	double area()
	{
		return x*x*3.14159;
	}
private:

};
int main()
{
	juxing jux(1, 2);
	sanjiaoxing sanjiaox(1, 2);
	yuanxing yuanx(2);
	shape *p = &jux;
	cout << p->area() << endl;
	p = &sanjiaox;
	cout << p->area() << endl;
	p = &yuanx;
	cout << p->area() << endl;
	return 0;
}
*/
/*********二叉平衡数c语言非递归实现***
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int key;
	int bf;
	BinTreeNode *llink, *rlink;
};
BinTreeNode *createNode(int key)
{
	BinTreeNode *p = new BinTreeNode;
	if (p)
	{
		p->key = key;
		p->bf = 0;
		p->llink = p->rlink = NULL;
	}
	return p;
}
BinTreeNode *LL(BinTreeNode *a, BinTreeNode *b)
{
	a->llink = b->rlink;
	b->rlink = a;
	a->bf = b->bf = 0;
	return b;
}
BinTreeNode *RR(BinTreeNode *a, BinTreeNode *b)
{
	a->rlink = b->llink;
	b->llink = a;
	a->bf = b->bf = 0;
	return b;
}
BinTreeNode *LR(BinTreeNode *a, BinTreeNode *b)
{
	BinTreeNode *c = b->rlink;
	b->rlink = c->llink;
	a->llink = c->rlink;
	c->llink = b;
	c->rlink = a;
	switch (c->bf)
	{
	case 0:
		a->bf = 0;
		a->bf = 0;
		break;
	case -1:
		a->bf = 1;
		a->bf = 0;
		break;
	case 1:
		a->bf = 0;
		a->bf = -1;
		break;
	}
	c->bf = 0;
	return c;
}
BinTreeNode *RL(BinTreeNode *a, BinTreeNode *b)
{
	BinTreeNode *c = b->llink;
	b->llink = c->rlink;
	a->rlink = c->llink;
	c->rlink = b;
	c->llink = a;
	switch (c->bf)
	{
	case 0:
		a->bf = 0;
		b->bf = 0;
		break;
	case -1:
		a->bf = 0;
		b->bf = 1;
		break;
	case 1:
		a->bf = -1;
		b->bf = 0;
		break;
	}
	c->bf = 0;
	return c;
}
int insert(BinTreeNode **ptree, int key)
{
	BinTreeNode *node_a, *node_b, *parent_a, *p, *q, *r, *node;
	int d;
	if (*ptree == NULL)
	{
		*ptree = createNode(key);
		if (*ptree == NULL)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	node_a = *ptree;
	parent_a = NULL;
	p = *ptree;
	q = NULL;
	while (p != NULL)
	{
		if (p->key == key)
		{
			return 1;
		}
		r = q;
		q = p;
		if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
		if (q->bf != 0)
		{
			parent_a = r;
			node_a = q;
		}
	}
	node = createNode(key);
	if (node == NULL)
	{
		return 0;
	}
	if (key<q->key)
	{
		q->llink = node;
	}
	else
	{
		q->rlink = node;
	}
	if (key < node_a->key)
	{
		node_b = p = node_a->llink;
		d = -1;
	}
	else
	{
		node_b = p = node_a->rlink;
		d = 1;
	}
	while (p != NULL&&p != node)
	{
		if (key < p->key)
		{
			p->bf = -1;
			p = p->llink;
		}
		else
		{
			p->bf = 1;
			p = p->rlink;
		}
	}
	if (node_a->bf == 0)
	{
		node_a->bf = d;
		return 1;
	}
	if (node_a->bf == -d)
	{
		node_a->bf = 0;
		return 1;
	}
	if (d == -1)
	{
		if (node_b->bf == -1)
		{
			node_b = LL(node_a, node_b);
		}
		else
		{
			node_b = LR(node_a, node_b);
		}
	}
	else
	{
		if (node_b->bf == -1)
		{
			node_b = RL(node_a, node_b);
		}
		else
		{
			node_b = RR(node_a, node_b);
		}
	}
	if (parent_a == NULL)
	{
		*ptree = node_b;
	}
	else
	{
		if (parent_a->llink == node_a)
		{
			parent_a->llink = node_b;
		}
		else
		{
			parent_a->rlink = node_b;
		}
	}
	return 1;
}
void createTree(BinTreeNode **ptree)
{
	int tmp;
	while (cin >> tmp)
	{
		insert(ptree, tmp);
	}
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->key << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->key << ' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->key << ' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);

	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	destroyTree(&tree);
	return 0;
}
*/
/*********n皇后*********
#include<iostream>
using namespace std;
int x[100];
int jueDui(int x)
{
	int y = x >> 31;
	return (x^y) - y;
}
bool place(int k)//考察皇后k放置在x[k]列是否发生冲突
{
	int i;
	for (i = 1; i<k; i++)
	if (x[k] == x[i] || abs(k - i) == abs(x[k] - x[i]))
		return false;
	return true;
}

void queue(int n)
{
	int i, k;
	int sum = 0;
	for (i = 1; i <= n; i++)
		x[i] = 0;
	k = 1;
	while (k >= 1)
	{
		x[k] = x[k] + 1;   //在下一列放置第k个皇后
		while (x[k] <= n&&!place(k))
			x[k] = x[k] + 1;//搜索下一列
		if (x[k] <= n&&k == n)//得到一个输出
		{
			for (i = 1; i <= n; i++)
				cout<<x[i]<<' ';
			cout << endl;
			//return;//若return则只求出其中一种解，若不return则可以继续回溯，求出全部的可能的解
		}
		else if (x[k] <= n&&k<n)
			k = k + 1;//放置下一个皇后
		else
		{
			x[k] = 0;//重置x[k],回溯
			k = k - 1;
		}
	}
}

void main()
{
	int n;
	cout<<"输入皇后个数n:"<<endl;
	cin >> n;
	queue(n);
}
*/
/*******N皇后***
#include<iostream>
using namespace std;
int x[100];
int jueDui(int x)
{
	int y = x >> 31;
	return (x^y) - y;
}
bool place(int k)
{
	for (int i = 1; i < k; i++)
	{
		if (x[i] == x[k] || jueDui(i - k) == jueDui(x[i] - x[k]))
		{
			return false;
		}
	}
	return true;
}
int queue(int n)
{
	int k = 1;
	int sum = 0;
	while (k >= 1)
	{
		x[k]++;
		while (x[k] <= n&&!place(k))
		{
			x[k]++;
		}
		if (x[k] <= n&&k == n)
		{
			sum++;
		}
		else if (x[k] <= n&&k < n)
		{
			k++;
		}
		else
		{
			x[k] = 0;
			k--;
		}
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	cout << queue(n) << endl;
	return 0;
}
*/
/*******排列组合 与n皇后类似**
#include<iostream>
using namespace std;
int x[100];
bool place(int k)
{
	for (int i = 1; i < k; i++)
	{
		if (x[i] == x[k])
		{
			return false;
		}
	}
	return true;
}
void queue(int n)
{
	int k = 1;
	int sum = 0;
	int flag = 0;
	while (k >= 1)
	{
		int buf = x[k];
		x[k]++;
		while (x[k] <= n && !place(k))
		{
			x[k]++;
		}
		
		if (x[k] <= n)
		{
			if (k == n)
			{
				for (int i = 1; i <= n; i++)
				{
					cout << x[i] << ' ';
				}
				cout << endl;
			}
			else if (k < n)
			{
				flag |= (1 << (x[k] - 1));
				k++;
			}
		}
		else
		{
			x[k] = 0;
			k--;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	queue(n);
	return 0;
}
*/
/***************并查集***********************************
#include<iostream>
using namespace std;
int find(int *pre, int x)
{
	int r = x;
	while (r != pre[r])
	{
		r = pre[r];
	}
	int i = x, j;
	while (i != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
int main()
{
	int vexNum;
	cin >> vexNum;
	int *pre = new int[vexNum + 1];
	for (int i = 1; i <= vexNum; i++)
	{
		pre[i] = i;
	}
	int need = vexNum - 1;
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		int f1 = find(pre,v0);
		int f2 = find(pre,v1);
		if (f1 != f2)
		{
			pre[f1] = f2;
			need--;
		}
	}
	cout << need << endl;
	return 0;
}
*/
/*****
#include <iostream>  
#include <queue>  
#include<stack>
using namespace std;
static int black = 0;
static int red = 1;
template<typename T>
struct RBNode
{
	RBNode() :left(NULL), right(NULL), parent(NULL), val(T()), color(red){}
	RBNode(const T &v1) :left(NULL), right(NULL), parent(NULL), val(v1), color(red){}
	RBNode  *left;
	RBNode  *right;
	RBNode  *parent;
	int     color;
	T       val;
};

template<typename T>
class RBTree
{
public:
	RBTree() :root(NULL){}
	~RBTree()
	{
		if (root)
		{
			Destroy(&root);
		}
	}
	bool  InsertUnique(const T &v1);
	void  nPreOrder();
	void nInOrder();
	void nPostOrder();
private:
	void    Destroy(RBNode<T> **p);
	void    InsertReBalance(RBNode<T> *node);
	RBNode<T>*  rotate_left(RBNode<T> *node);
	RBNode<T>*  rotate_right(RBNode<T> *node);
	RBNode<T> *root;
};
template<typename T>
bool RBTree<T>::InsertUnique(const T &v1)
{
	RBNode<T> *parent = NULL;
	RBNode<T> *newNode = new RBNode<T>(v1);
	RBNode<T> *p = root;
	while (p)
	{
		if (v1 == p->val)
		{
			return false;
		}
		parent = p;
		if (v1 < p->val)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (parent == NULL)
	{
		root = newNode;
		root->color = black;
		return true;
	}

	if (v1 < parent->val)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}
	newNode->parent = parent;
	InsertReBalance(newNode);
	return true;
}

template<typename T>
void RBTree<T>::InsertReBalance(RBNode<T> *node)
{
	RBNode<T> *parent = node->parent;
	RBNode<T> *grandParent = NULL;
	while (parent && parent->color == red)
	{
		grandParent = parent->parent;
		if (parent == grandParent->left)
		{
			RBNode<T> *uncle = grandParent->right;
			if (uncle && uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandParent->color = red;
				node = grandParent;
				parent = grandParent->parent;
			}
			else
			{
				if (node == parent->right)
				{
					node = rotate_left(parent);
					parent = node->parent;
					grandParent = parent->parent;
				}
				parent->color = black;
				grandParent->color = red;
				rotate_right(grandParent);
			}
		}
		else
		{
			RBNode<T> *uncle = grandParent->left;
			if (uncle && uncle->color == red)
			{
				uncle->color = black;
				parent->color = black;
				grandParent->color = red;
				node = grandParent;
				parent = node->parent;
			}
			else
			{
				if (node == parent->left)
				{
					node = rotate_right(parent);
					parent = node->parent;
					grandParent = parent->parent;
				}
				parent->color = black;
				grandParent->color = red;
				rotate_left(grandParent);
			}
		}
	}
	root->color = black;
}
template<typename T>
RBNode<T> *RBTree<T>::rotate_left(RBNode<T> *x)
{
	RBNode<T> *y = x->right;
	if (y == NULL)
	{
		return x;
	}

	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	if (root == x)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}
	y->left = x;
	x->parent = y;
	return x;
}
template<typename T>
RBNode<T>* RBTree<T>::rotate_right(RBNode<T> *x)
{
	RBNode<T> *y = x->left;
	if (y == NULL)
	{
		return x;
	}
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	if (root == x)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->parent = x->parent;
	}
	y->right = x;
	x->parent = y;
	return x;
}

template<typename T>
void RBTree<T>::Destroy(RBNode<T> **p)
{
	if ((*p)->left)
	{
		Destroy(&(*p)->left);
	}
	if ((*p)->right)
	{
		Destroy(&(*p)->right);
	}
	delete *p;
	*p = NULL;
}
template<typename T>
void RBTree<T>::nPreOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<RBNode<T>*> st;
	RBNode<T> *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->val << ' ';
			st.push(p->right);
			st.push(p->left);
		}
	}
	cout << endl;
}
template<typename T>
void RBTree<T>::nInOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<RBNode<T>*> st;
	RBNode<T> *p = root;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->left;
		}
		p = st.top();
		st.pop();
		cout << p->val << ' ';
		p = p->right;
	}
	cout << endl;
}
template<typename T>
void RBTree<T>::nPostOrder()
{
	if (root == NULL)
	{
		return;
	}
	stack<RBNode<T>*> st;
	RBNode<T> *p = root;
	RBNode<T> *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->right;
			p = p->left;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->val << ' ';
		if (!st.empty() && st.top()->left == p)
		{
			p = st.top()->right;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	RBTree<int> obj;
	obj.InsertUnique(30);
	obj.InsertUnique(40);
	obj.InsertUnique(50);
	obj.InsertUnique(20);
	obj.InsertUnique(35);
	obj.InsertUnique(10);
	obj.InsertUnique(11);
	obj.nPreOrder();
	obj.nInOrder();
	obj.nPostOrder();
	return 0;
}
*/
/***红黑树C++实现*
#include<iostream>
#include<stack>
using namespace std;
const bool black = 0;
const bool red = 1;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink, *rlink, *parent;
};
class RBTree
{
public:
	RBTree();
	~RBTree();
	void insertNode(int key);         //插入元素接口
	void deleteNode(int key);         //删除元素接口
	void nPreOrder();                 //先序遍历非递归
	void nInOrder();                  //中序遍历非递归
	void nPostOrder();                //后序遍历非递归
private:
	void destroy(RBNode **proot);     //销毁树，析构函数用到
	RBNode *createNode(int key);      //生成红黑树结点
	void insertFixup(RBNode *pnode);  //插入元素后调整
	RBNode *searchNode(int key);      //找指定元素的结点，删除元素函数用到
	void transplant(RBNode *v0, RBNode *v1); //删除指定结点,删除元素函数用到
	RBNode *minNode(RBNode *x);             //找到树中最小的元素，删除元素函数用到
	void deleteFixup(RBNode *delNode);      //删除元素后调整
	RBNode *rotate_right(RBNode *a);        //右旋
	RBNode *rotate_left(RBNode *a);         //左旋
	RBTree(const RBTree &obj);
	RBTree &operator=(const RBTree &obj);
	RBNode *root;
	RBNode *m_null;
};
//构造函数
RBTree::RBTree()
{
	m_null = new RBNode;
	m_null->color = black;
	m_null->llink = m_null->rlink = m_null;
	root = m_null;
}
//析构函数
RBTree::~RBTree()
{
	if (root != m_null)
	{
		destroy(&root);
		root = NULL;
	}
	delete m_null;
	m_null = NULL;
}
//插入元素
void RBTree::insertNode(int key)
{
	RBNode *p = root;
	RBNode *q = m_null;
	while (p != m_null)
	{
		q = p;
		if (key == p->key)
		{
			return;
		}
		else if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	RBNode *newNode = createNode(key);
	if (q == m_null)
	{
		root = newNode;
		root->color = black;
		newNode->parent = m_null;
		return;
	}
	if (key < q->key)
	{
		q->llink = newNode;
	}
	else
	{
		q->rlink = newNode;
	}
	newNode->parent = q;
	insertFixup(newNode);              //插入元素后调整
}
//插入元素后调整
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent = pnode->parent;
	RBNode *grandParent = m_null;
	while (parent != m_null&&parent->color == red)      //迭代
	{
		grandParent = parent->parent;
		if (parent == grandParent->llink)
		{
			RBNode *uncle = grandParent->rlink;
			if (uncle->color == red)                                //情况1
			{
				parent->color = black;
				uncle->color = black;
				grandParent->color = red;
				pnode = grandParent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->rlink)                        //情况2，可转换为情况3
				{
					pnode = rotate_left(parent);
					parent = pnode->parent;
					grandParent = parent->parent;
				}
				parent->color = black;                            //情况3
				grandParent->color = red;
				rotate_right(grandParent);
			}
		}
		else                                                      //与上面对称
		{
			RBNode *uncle = grandParent->llink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandParent->color = red;
				pnode = grandParent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->llink)
				{
					pnode = rotate_right(parent);
					parent = pnode->parent;
					grandParent = parent->parent;
				}
				parent->color = black;
				grandParent->color = red;
				rotate_left(grandParent);
			}
		}
	}
	root->color = black;
}
//寻找指定键值元素
RBNode *RBTree::searchNode(int key)
{
	RBNode *p = root;
	while (p != m_null)
	{
		if (key == p->key)
		{
			return p;
		}
		else if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	return m_null;
}
//删除元素后调整各结点关系
void RBTree::transplant(RBNode *v0, RBNode *v1)
{
	if (v0 == root)
	{
		root = v1;
	}
	else if (v0 == v0->parent->llink)
	{
		v0->parent->llink = v1;
	}
	else
	{
		v0->parent->rlink = v1;
	}
	v1->parent = v0->parent;
}
//找到树中最小健值结点
RBNode *RBTree::minNode(RBNode *x)
{
	while (x->llink != m_null)
	{
		x = x->llink;
	}
	return x;
}
//删除指定健值结点
void RBTree::deleteNode(int key)
{
	RBNode *delNode = searchNode(key);            //寻找删除的结点
	if (delNode == m_null)
	{
		return;
	}
	RBNode *realDel = delNode;                  //实际删除的结点赋初值
	RBNode *replace = m_null;                   //代替的结点
	if (delNode->rlink == m_null)               //如果删除的结点最多只有1棵子树
	{
		replace = delNode->llink;
	}
	else if (delNode->llink == m_null)
	{
		replace = delNode->rlink;
	}
	else                                       //如果有两个子树
	{
		realDel = minNode(delNode->rlink);     //找到右子树最小结点，即为实际要删除的结点
		replace = realDel->rlink;
		delNode->key = realDel->key;           //实际删除的结点值赋给删除的结点
	}
	transplant(realDel, replace);
	if (realDel->color == black)
	{
		deleteFixup(replace);             //如果实际删除的结点是黑色，则调整
	}
	delete realDel;
}
//删除结点后调整
void RBTree::deleteFixup(RBNode *delNode)
{
	RBNode *p = delNode;

	while (p != root&&p->color == black)
	{
		RBNode *parent = p->parent;
		if (p == parent->llink)
		{
			RBNode *slibing = parent->rlink;
			if (slibing->color == red)										//情况1，兄弟结点为红色 可转换为情况2，3，4
			{																//兄弟结点涂成黑色，父结点凃成红色，以父结点为支点左旋 
				parent->color = red;
				slibing->color = black;
				rotate_left(parent);
				slibing = parent->rlink;										//调整兄弟结点
			}
			//此时兄弟结点肯定为黑色
			if (slibing->llink->color == black&&slibing->rlink == black)		//情况2，两个侄子结点都为黑色
			{
				slibing->color = red;										//兄弟结点凃红
				p = p->parent;												//父结点为当前节点
			}
			else
			{
				if (slibing->rlink == black)									//情况3，左侄子结点为红色
				{
					slibing->color = red;									//兄弟凃红
					slibing->llink->color = black;							//左侄子凃红
					rotate_right(slibing);									//以兄弟为支点右旋
					slibing = slibing->parent;								//调整兄弟结点转换为情况4
				}
				slibing->color = parent->color;								//情况4 ，右侄子为红
				parent->color = black;										//父结点与兄弟结点交换颜色
				slibing->rlink->color = black;								//右侄子凃黑后结束
				rotate_left(parent);										//以父结点为支点左旋
				p = root;                                                 
			}
		}
		else                                                                 //与上面对称
		{
			RBNode *slibing = parent->llink;
			if (slibing->color == red)
			{
				slibing->color = black;
				parent->color = red;
				rotate_right(parent);
				slibing = parent->llink;
			}
			if (slibing->llink->color == black&&slibing->rlink->color == black)
			{
				slibing->color = red;
				p = parent;
			}
			else
			{
				if (slibing->llink == black)
				{
					slibing->color = red;
					slibing->rlink->color = black;
					rotate_left(slibing);
					slibing = slibing->parent;
				}
				slibing->color = parent->color;
				parent->color = black;
				slibing->llink->color = black;
				rotate_right(parent);
				p = root;
			}
		}
	}
	p->color = black;
}
//右旋
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b = a->llink;
	if (b == m_null)
	{
		return a;
	}
	a->llink = b->rlink;
	b->rlink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->rlink = a;
	a->parent = b;
	return a;
}
//左旋
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b = a->rlink;
	if (b == m_null)
	{
		return a;
	}
	a->rlink = b->llink;
	b->llink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->llink = a;
	a->parent = b;
	return a;
}
//销毁树，析构函数调用
void RBTree::destroy(RBNode **proot)
{
	if (*proot == m_null)
	{
		return;
	}
	destroy(&(*proot)->llink);
	destroy(&(*proot)->rlink);
	delete *proot;
	*proot = m_null;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p = new RBNode;
	if (p)
	{
		p->color = red;
		p->key = key;
		p->llink = p->rlink = p->parent = m_null;
	}
	return p;
}
//先序遍历非递归
void RBTree::nPreOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != m_null)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
//中序遍历非递归
void RBTree::nInOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
//后序遍历非递归
void RBTree::nPostOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	RBNode *pp = m_null;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == m_null)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = m_null;
		}
	}
	cout << endl;
}
int main()
{
	RBTree tree;
	int x;
	while (cin >> x)
	{
		tree.insertNode(x);
	}
	tree.nPreOrder();
	tree.nInOrder();
	tree.nPostOrder();
	cin.clear();
	while (cin >> x)
	{
		tree.deleteNode(x);
		tree.nPreOrder();
		tree.nInOrder();
		tree.nPostOrder();
	}
	return 0;
}
*/
/***********************
#include<iostream>
using namespace std;
void test()
{
	cout << "huang" << endl;
}
static void test1(){ cout << "huang" << endl; }
class A
{
public:
	A(int i) :a(i)
	{
		b++;
	}
	static void fun()
	{
		cout << "huang" << endl;
		//cout << a << endl;                   //静态成员函数不含默认的this指针，不能访问非静态成员
		cout << b << endl;
	}
	void fun0()
	{
		cout << "hua" << endl;
		cout << a << endl;
		cout << b << endl;
	}
	static int b;

private:
	int a;
	
};
int A::b = 0;
int main()
{
	A obj(2);
	A obj0(0);
	A::fun();                 //可以调用静态成员函数
	//A::fun0();              
	obj.fun();
	obj.fun0();
	cout << sizeof(A) << endl;   //不包含静态成员变量
	cout << obj.b << endl;
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int *p = (int*)(&a + 1);
	cout << *(a + 1) << ' ' << *(p - 1) << endl;
	return 0;
}
*/
/***********************
#include <stdio.h>  
#include <stdlib.h>  

#define LEN 13  

struct hash_node {
	int count;
	struct hash_node *next;
};

static int hash(int num)
{
	return num % LEN;
}

static void collision(struct hash_node *vec[], int elem, struct hash_node *new)
{
	if (vec[elem] == NULL)
		vec[elem] = new;
	else
	{
		new->next = vec[elem];
		vec[elem] = new;
	}
}

static void ord_num_print(int i)
{
	if (i == 1)
		printf("the 1st element: ");
	else if (i == 2)
		printf("the 2nd element: ");
	else if (i == 3)
		printf("the 3rd element: ");
	else
		printf("the %dth element: ", i);
}

static void print_hash(struct hash_node *vec[])
{
	int i;
	struct hash_node *tmp;

	for (i = 0; i < LEN; i++)
	if (vec[i] == NULL)
	{
		ord_num_print(i + 1);
		printf("NULL\n");
	}
	else
	{
		ord_num_print(i + 1);
		tmp = vec[i];
		do {
			printf("%d ", tmp->count);
		} while ((tmp = tmp->next) && tmp != NULL);
		printf("\n");
	}
}

static void create_hash(struct hash_node *vec[], int num)
{
	FILE *fp;
	int i, tmp, arr[num];
	struct hash_node *p;

	fp = fopen("./hash", "r");

	for (i = 0; i < num; i++)
		fscanf(fp, "%d", &arr[i]);

	fclose(fp);

	for (i = 0; i < num; i++) {
		p = malloc(sizeof(struct hash_node));
		p->count = arr[i];
		p->next = NULL;

		tmp = hash(arr[i]);
		collision(vec, tmp, p);
	}
}
void insert_hash_node(struct hash_node *vec[], int data)
{
	int tmp;
	struct hash_node *p = malloc(sizeof(struct hash_node));
	p->count = data;
	p->next = NULL;

	tmp = hash(data);
	collision(vec, tmp, p);
}
void delete_hash_node(struct hash_node *vec[], int data)
{
	int elem;
	struct hash_node *p, *tmp;

	elem = hash(data);
	if (vec[elem] == NULL) {
		fprintf(stderr, "vec[%d] is NULL\n", elem);
		exit(-2);
	}
	else
	{
		tmp = vec[elem];
		while (tmp->count != data) {
			if (tmp->next == NULL) {
				fprintf(stderr, "not found %d\n", data);
				exit(-3);
			}
			p = tmp;
			tmp = tmp->next;
		}
		p->next = tmp->next;
		free(tmp);
	}
}
int main(int argc, char *argv[])
{
	int i, num;
	struct hash_node *vec[LEN];


	if (argc < 2) {
		fprintf(stderr, "Usage: %s num\n", argv[0]);
		exit(-1);
	}

	for (i = 0; i < LEN; i++)
		vec[i] = NULL;

	num = atoi(argv[1]);

	printf("\tthe first times\n");
	create_hash(vec, num);
	print_hash(vec);

	printf("\n\tthe second times\n");
	insert_hash_node(vec, 29);
	print_hash(vec);

	printf("\n\tthe third times\n");
	delete_hash_node(vec, 1);
	print_hash(vec);

	return 0;
}
*/
/****散列表******
#include<iostream>
#include<string>
using namespace std;
const int LEN = 13;
struct Node
{
	int key;
	Node *next;
};
int Hash(int num)
{
	return num % LEN;
}
void createHash(Node *vec[],int num)
{
	for (int i = 0; i < num; i++)
	{
		vec[i] = NULL;
	}
	int x;
	while (cin >> x)
	{
		int y = Hash(x);
		Node *p = new Node;
		p->key = x;
		p->next = vec[y];
		vec[y] = p;
	}
}
void destroyHash(Node *vec[], int num)
{
	for (int i = 0; i < num; i++)
	{
		Node *p = vec[i];
		Node *q = NULL;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
		vec[i] = NULL;
	}
}
Node *search(Node *vec[], int key)
{
	Node *p = vec[Hash(key)];
	while (p)
	{
		if (p->key == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void insertHash(Node *vec[], int key)
{
	if (search(vec, key) != NULL)
	{
		return;
	}
	int tmp = Hash(key);
	Node *p = new Node;
	p->key = key;
	p->next = vec[tmp];
	vec[tmp] = p;
}
void deleteHash(Node *vec[], int key)
{
	Node *p = search(vec, key);
	if (p == NULL)
	{
		return;
	}
	if (p->next == NULL)
	{
		p = vec[Hash(key)];
		if (p->key == key)
		{
			delete p;
			p = NULL;
			vec[Hash(key)] = NULL;
			return;
		}
		while (p->next->key != key)
		{
			p = p->next;
		}
		Node *q = p->next;
		p->next = NULL;
		delete q;
	}
	else
	{
		p->key = p->next->key;
		Node *q = p->next;
		p->next = q->next;
		delete q;
		q = NULL;
	}
}
void printHash(Node *vec[], int len)
{
	cout << "start:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "第" << i << "行：";
		Node *p = vec[i];
		if (p == NULL)
		{
			cout << "no element!" << endl;
		}
		else
		{
			while (p)
			{
				cout << p->key << ' ';
				p = p->next;
			}
			cout << endl;

		}
	}
	cout << "end!" << endl;
}
int main()
{
	Node *vec[LEN];
	createHash(vec,LEN);
	printHash(vec, LEN);
	int x;
	string str;
	cin.clear();
	while (cin >> str >> x)
	{
		if (str == "in")
		{
			insertHash(vec, x);
		}
		else if (str == "out")
		{
			deleteHash(vec, x);
		}
		printHash(vec, LEN);
	}
	destroyHash(vec, LEN);
}
*/
/*****哈希表********
#include<iostream>
#include<string>
using namespace std;
const int LEN = 13;
struct Node
{
	int key;
	Node *next;
};
int Hash(int x)
{
	return x % 13;
}
Node *searchNode(Node *vec[], int key)
{
	Node *p = vec[Hash(key)];
	while (p != NULL)
	{
		if (p->key == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void insertNode(Node *vec[], int key)
{
	if (searchNode(vec, key) != NULL)
	{
		return;
	}
	int tmp = Hash(key);
	Node *p = new Node;
	p->key = key;
	p->next = vec[tmp];
	vec[tmp] = p;
}
void deleteNode(Node *vec[], int key)
{
	int tmp = Hash(key);
	Node *p = vec[tmp];
	if (p == NULL)
	{
		return;
	}
	if (p->key == key)
	{
		vec[tmp] = p->next;
		delete p;
		p = NULL;
	}
	else
	{
		Node *q = p->next;
		while (q&&q->key != key)
		{
			p = q;
			q = q->next;
		}
		if (q)
		{
			p->next = q->next;
			delete q;
			q = NULL;
		}
	}
}
void createHash(Node *vec[], int num)
{
	for (int i = 0; i < num; i++)
	{
		vec[i] = NULL;
	}
	int x;
	while (cin >> x)
	{
		insertNode(vec, x);
	}
}
void destroyHash(Node *vec[], int num)
{
	for (int i = 0; i < num; i++)
	{
		Node *p = vec[i];
		Node *q = NULL;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
		vec[i] = NULL;
	}
}
void printHash(Node *vec[], int num)
{
	cout << "start---------------------" << endl;
	for (int i = 0; i < num; i++)
	{
		Node *p = vec[i];
		cout << i<<' ';
		if (p == NULL)
		{
			cout << "no elements in this line" << endl;
		}
		else
		{
			while (p->next)
			{
				cout << p->key << "->";
				p = p->next;
			}
			cout << p->key << endl;
		}
	}
}
int main()
{
	Node *myHash[LEN];
	createHash(myHash, LEN);
	printHash(myHash, LEN);
	string str;
	int x;
	cin.clear();
	while (cin >> str >> x)
	{
		if (str == "in")
		{
			insertNode(myHash, x);
		}
		else if (str == "out")
		{
			deleteNode(myHash, x);
		}
		printHash(myHash, LEN);
	}
	destroyHash(myHash, LEN);
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
int rectCover(int number) 
{
	if (number == 1)
	{
		return 1;
	}
	if (number == 2)
	{
		return 2;
	}
	int a1 = 1;
	int a2 = 2;
	for (int i = 3; i <= number; i++)
	{
		int temp = a2;
		a2 += a1;
		a1 = temp;
	}
	return a2;
}
int Fibonacci(int n) {
	if (n <= 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}
	int a1 = 1;
	int a2 = 1;
	for (int i = 3; i <= n; i++)
	{
		int temp = a2;
		a2 += a1;
		a1 = temp;
	}
	return a2;

}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << rectCover(n) << endl;
		cout << Fibonacci(n) << endl;
	}
	return 0;
}
*/
/******
#include<iostream>
using namespace std;
int func(unsigned int i)
{
	unsigned int temp = i;
	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
	temp = (temp & 0x33333333) + ((temp & 0xccccccccc) >> 2);
	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0 >> 4));
	temp = (temp & 0xff00ff) + ((temp & 0xff00fff00) >> 8);
	temp = (temp & 0xffff) + ((temp & 0xffff0000) >> 16);
	return temp;
}
int main()
{
	cout << func(0x11530828) << endl;
	return 0;
}
*/
/****空格替换为%20****
#include<iostream>
using namespace std;
void replaceSpace(char *str, int length)
{
	char *p = str;
	int num = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			num++;
		}
		p++;
	}
	char *q = p + 2 * num;
	while (p != q)
	{
		while (*p != ' ')
		{
			*(q--) = *(p--);
		}
		p--;
		*(q--) = '0';
		*(q--) = '2';
		*(q--) = '%';
	}
}
int main()
{
	char str[100];
	gets_s(str);
	replaceSpace(str,0);
	cout << str << endl;
	return 0;
}
*/
/********************************
#include<iostream>
using namespace std;
int  NumberOf1(int n) 
{
	int num = 0;
	while (n)
	{
		num++;
		n = n&(n - 1);
	}
	return num;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumberOf1(n) << endl;
	}
	return 0;
}
*/
/****************************
#include<iostream>
#include<vector>
using namespace std;
bool Find(vector<vector<int> > array, int target) 
{
	for (vector<vector<int> >::iterator iter = array.begin(); iter != array.end(); ++iter)
	{
		for (vector<int>::iterator it = iter->begin(); it != iter->end(); ++it)
		{
			if (*it == target)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	return 0;
}
*/
/*****
#include<iostream>
#include<vector>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void findPath(BinTreeNode *tree, int expectedNum, vector<int> &path, int &current)
{
	if (tree == NULL)
	{
		return;
	}
	current += tree->info;
	path.push_back(tree->info);
	if (tree->llink == NULL&&tree->rlink == NULL&&current == expectedNum)
	{
		for (vector<int>::iterator iter = path.begin(); iter != path.end(); ++iter)
		{
			cout << *iter << ' ';
		}
		cout << endl;
	}
	findPath(tree->llink, expectedNum, path, current);
	findPath(tree->rlink, expectedNum, path, current);
	current -= tree->info;
	path.pop_back();
}
void findPath(BinTreeNode *tree, int expectedNum)
{
	if (tree == NULL)
	{
		return;
	}
	vector<int> path;
	int current = 0;
	findPath(tree, expectedNum, path, current);
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	findPath(tree, 22);
	destroyTree(&tree);
	return 0;
}
*/
/*****反转链表******
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode *p = pHead;
		ListNode *q = pHead->next;
		pHead->next = NULL;
		ListNode *t = NULL;
		while (q != NULL)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		return p;
	}
};
int main()
{
	return 0;
}
*/
/***********
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (pListHead == NULL)
	{
		return NULL;
	}
	ListNode *p = pListHead;
	ListNode *q = p;
	for (int i = 0; i < k - 1; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			return NULL;
		}
	}
	while (p->next != NULL)
	{
		q = q->next;
		p = p->next;
	}
	return q;
}
int main()
{
	return  0;
}
*/
/******旋转数组最小值************
#include<iostream>
#include<vector>
using namespace std;
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
	{
		return 0;
	}
	int start = 0;
	int end = rotateArray.size() - 1;
	int mid = start;
	while (rotateArray[start] >= rotateArray[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if (rotateArray[start] == rotateArray[end] && rotateArray[start] == rotateArray[mid])
		{
			int min = rotateArray[start];
			for (int i = start; i <= end; i++)
			{
				if (min > rotateArray[i])
				{
					min = rotateArray[i];
				}
			}
			return min;
		}
		if (rotateArray[mid] >= rotateArray[start])
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	return rotateArray[mid];
}
int main()
{
	vector<int> ivec;
	int x;
	while (cin >> x)
	{
		ivec.push_back(x);
	}
	cout << minNumberInRotateArray(ivec) << endl;
	return 0;
}
*/
/******二叉树镜像************
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
void Mirror(TreeNode *pRoot) 
{
	if ( NULL==pRoot)
	{
		return;
	}
	TreeNode *mybuf = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = mybuf;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}
int main()
{

}
*/
/**********顺时针打印二维数组**********************
#include<iostream>
#include<vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) 
{
	vector<int> ivec;
	int n = matrix.size();
	if (n <= 0)
	{
		return ivec;
	}
	int m = matrix[0].size();
	if (m <= 0)
	{
		return ivec;
	}
	int start = 0;
	while (n > start * 2 && m > start * 2)
	{
		int endX = m - 1 - start;
		int endY = n - 1 - start;
		for (int j = start; j <= endX; j++)
		{
			ivec.push_back(matrix[start][j]);
		}
		for (int i = start + 1; i <= endY; i++)
		{
			ivec.push_back(matrix[i][endX]);
		}
		if (endY > start)
		{
			for (int j = endX - 1; j >= start; j--)
			{
				ivec.push_back(matrix[endY][j]);
			}
		}
		if (endX > start)
		{
			for (int i = endY - 1; i > start; i--)
			{
				ivec.push_back(matrix[i][start]);
			}
		}
		start++;
	}
	return ivec;
}
int main()
{
	vector<vector<int> > ivec;
	vector<int> buf;
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++)
	{
		buf.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			buf.push_back(x);
		}
		ivec.push_back(buf);
	}
	vector<int> res = printMatrix(ivec);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
	return 0;
}
*/
/***************************
#include<iostream>
using namespace std;

double Power(double base, int exponent) 
{
	if (base<0.0000001&&base>-0.0000001&&exponent <= 0)
	{
		return 1.0;
	}
	if (exponent == 0)
	{
		return 1.0;
	}
	int flag = 0;
	if (exponent < 0)
	{
		exponent = -exponent;
		flag = 1;
	}
	double sum = 1;
	for (int i = 0; i < exponent; i++)
	{
		sum *= base;
	}
	if (flag)
	{
		sum = 1.0 / sum;
	}
	return sum;
}
int main()
{
	double base;
	int exponent;
	while (cin >> base >> exponent)
	{
		cout << Power(base, exponent) << endl;
	}
	return 0; 
}
*/
/*************************
#include<iostream>
#include<stack>
using namespace std;
const bool black = false;
const bool red = true;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink, *rlink, *parent;
};
class RBTree
{
public:
	RBTree();
	~RBTree();
	void insertNode(int key);
	void deleteNode(int key);
	void nPreOrder();
	void nInOrder();
	void nPostOrder();
private:
	void insertFixup(RBNode *pnode);
	void deleteFixup(RBNode *pnode);
	RBNode *rotate_left(RBNode *a);
	RBNode *rotate_right(RBNode *a);
	RBNode *createNode(int key);
	void destroy(RBNode *pnode);
	RBNode *root;
	RBNode *m_null;
};
RBTree::RBTree()
{
	m_null = new RBNode;
	if (m_null)
	{
		m_null->color = black;
		m_null->llink = m_null->rlink = m_null->parent = m_null;
	}
	root = m_null;
}
RBTree::~RBTree()
{
	destroy(root);
	root = NULL;
	m_null = NULL;
}
void RBTree::insertNode(int key)
{
	RBNode *p = root;
	RBNode *parent = m_null;
	while (p != m_null)
	{
		if (p->key == key)
		{
			return;
		}
		parent = p;
		if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	RBNode *newnode = createNode(key);
	if (parent == m_null)
	{
		root = newnode;
		newnode->color = black;
		newnode->parent = m_null;
	}
	else
	{
		if (key < parent->key)
		{
			parent->llink = newnode;
		}
		else
		{
			parent->rlink = newnode;
		}
		newnode->parent = parent;
		insertFixup(newnode);
	}
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent = pnode->parent;
	RBNode *grandparent = m_null;
	while (parent != m_null&&parent->color == red)
	{
		grandparent = parent->parent;
		if (parent == grandparent->llink)
		{
			RBNode *uncle = grandparent->rlink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandparent->color = red;
				pnode = grandparent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->rlink)
				{
					pnode = rotate_left(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandparent->color = red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle = grandparent->llink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandparent->color = red;
				pnode = grandparent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->llink)
				{
					pnode = rotate_right(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandparent->color = red;
				rotate_left(grandparent);
			}
		}
	}
	root->color = black;
}
void RBTree::deleteNode(int key)
{
	RBNode *delNode = root;
	while (delNode != m_null)
	{
		if (key == delNode->key)
		{
			break;
		}
		else if (key < delNode->key)
		{
			delNode = delNode->llink;
		}
		else
		{
			delNode = delNode->rlink;
		}
	}
	if (delNode == m_null)
	{
		return;
	}
	RBNode *realDel = delNode;
	RBNode *replace = m_null;
	if (delNode->llink == m_null)
	{
		replace = delNode->rlink;
	}
	else if (delNode->rlink == m_null)
	{
		replace = delNode->llink;
	}
	else
	{
		realDel = delNode->rlink;
		while (realDel->llink != m_null)
		{
			realDel = realDel->llink;
		}
		replace = realDel->rlink;
		delNode->key = realDel->key;
	}
	if (root == realDel)
	{
		root = replace;
		replace->parent = m_null;
	}
	else
	{
		if (realDel->parent->llink == realDel)
		{
			realDel->parent->llink = replace;
		}
		else
		{
			realDel->parent->rlink = replace;
		}
		replace->parent = realDel->parent;
	}
	if (realDel->color == black)
	{
		deleteFixup(replace);
	}
	delete realDel;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p = pnode;
	RBNode *parent = m_null;
	RBNode *sibling = m_null;
	while (p != root&&p->color == black)
	{
		parent = p->parent;
		if (p == parent->llink)
		{
			sibling = parent->rlink;
			if (sibling->color == red)
			{
				sibling->color = black;
				parent->color = red;
				rotate_left(parent);
				sibling = parent->rlink;
			}
			if (sibling->llink->color == black&&sibling->rlink->color == black)
			{
				sibling->color = red;
				p = parent;
			}
			else
			{
				if (sibling->rlink == black)
				{
					sibling->color = red;
					sibling->llink->color = black;
					rotate_right(sibling);
					sibling = sibling->parent;
				}
				sibling->color = parent->color;
				parent->color = black;
				sibling->rlink->color = black;
				rotate_left(parent);
				p = root;
			}
		}
		else
		{
			sibling = parent->llink;
			if (sibling->color = red)
			{
				sibling->color = black;
				parent->color = red;
				rotate_right(parent);
				sibling = parent->llink;
			}
			if (sibling->llink->color == black&&sibling->rlink->color == black)
			{
				sibling->color = red;
				p = parent;
			}
			else
			{
				if (sibling->llink->color == black)
				{
					sibling->color = red;
					sibling->rlink->color = black;
					rotate_left(sibling);
					sibling = sibling->parent;
				}
				sibling->color = parent->color;
				parent->color = black;
				sibling->llink->color = black;
				rotate_right(parent);
				p = root;
			}
		}
	}
	p->color = black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->llink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->rlink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p = new RBNode;
	if (p)
	{
		p->key = key;
		p->color = red;
		p->llink = p->rlink = p->parent = m_null;
	}
	return p;
}
void RBTree::destroy(RBNode *pnode)
{
	if (pnode == m_null)
	{
		return;
	}
	destroy(pnode->llink);
	destroy(pnode->rlink);
	delete pnode;
}
void RBTree::nPreOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != m_null)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void RBTree::nInOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void RBTree::nPostOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	RBNode *pp = m_null;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == m_null)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = m_null;
		}
	}
	cout << endl;
}
int main()
{
	RBTree tree;
	int x;
	while (cin >> x)
	{
		tree.insertNode(x);
	}
	tree.nPreOrder();
	tree.nInOrder();
	tree.nPostOrder();
	cin.clear();
	while (cin >> x)
	{
		tree.deleteNode(x);
		tree.nPreOrder();
		tree.nInOrder();
		tree.nPostOrder();
	}
	return 0;
}
*/
/*******
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int pos = str.rfind(' ');
	cout << str.size() - pos - 1 << endl;
}
*/
/*****
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string strNum[] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };//, , 、、、、、角、分、零、整 }
string strT[] = { "元", "万","亿","拾", "佰", "仟" };
void intTostr(int a, string &str)
{
	str.clear();
	int qian = a / 1000;
	int bai = a / 100 % 10;
	int shi = a / 10 % 10;
	int ge = a % 10;
	if (qian != 0)
	{
		str += strNum[qian];
		str += "仟";
	}
	if ()
}
int main()
{
	double d;
	cin >> d;
	long l = d * 100;
	long yuan = l / 100;
	long yunnD = l % 100;
	vector<int> iYuan;
	while (yuan)
	{
		iYuan.push_back(yuan % 10000);
		yuan /= 10000;
	}
	vector<string> strvec;
	for (int i = 0; i < iYuan.size(); i++)
	{
		string buf;
		intTostr(iYuan[i], buf);
		buf += strT[i];
		strvec.push_back(buf);
	}
}
*/
/*****************
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> ivec;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ivec.push_back(x);
	}
	sort(ivec.begin(), ivec.end());
	for (int i = 0; i < k; i++)
	{
		if (i < k - 1)
			cout << ivec[i] << ' ';
		else
			cout << ivec[i] << endl;
	}
	return 0;
}
*/
/*************
#include<iostream>
#include<string>
using namespace std;
string add(string &str0, string &str1)
{
	string str;
	string buf;
	if (str0.size() >= str1.size())
	{
		str = str0;
		buf = str1;
	}
	else
	{
		str = str1;
		buf = str0;
	}
	string::reverse_iterator itstr = str.rbegin();
	string::reverse_iterator itbuf = buf.rbegin();
	while (itbuf != buf.rend() - 1)
	{
		*itstr += (*itbuf - '0');
		if (*itstr > '9')
		{
			(*itstr) -= 10;
			(*(itstr + 1)) += 1;
		}
		++itstr;
		++itbuf;
	}
	*itstr += (*itbuf - '0');
	while (itstr != str.rend() - 1)
	{
		if (*itstr > '9')
		{
			(*itstr) -= 10;
			(*(itstr + 1)) += 1;
		}
		++itstr;
	}
	if (*itstr > '9')
	{
		(*itstr) -= 10;
		str.insert(str.begin(), '1');
	}
	return str;
}
int main()
{
	string str0, str1;
	cin >> str0 >> str1;
	string str = add(str0, str1);
	cout << str;
}
*/
/***
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int fun(string str)
{
	int a[26] = {0};
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter >= 'a'&&*iter <= 'z')
		{
			a[*iter - 'a']++;
		}
		else
		{
			a[*iter - 'A']++;
		}
	}
	sort(a, a + 26, cmp);
	int n = 26;
	int sum = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] <= 0)
		{
			break;
		}
		sum += (a[i] * n--);
	}
	return sum;
}
int main()
{
	vector<string> strvec;
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		strvec.push_back(str);
	}
	for (vector<string>::iterator iter = strvec.begin(); iter != strvec.end(); ++iter)
	{
		cout << fun(*iter) << endl;
	}
	return 0;
}
*/
/*****
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int count = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter >= 'A'&&*iter <= 'Z')
		{
			count++;
		}
	}
	cout << count << endl;
}
*/
/***小数高精度转换为二进制**********
#include<iostream>
#include<string>
using namespace std;
int cheng2(string &str)
{
	int flag = 0;
	for (string::reverse_iterator iter = str.rbegin(); *iter != '.'; iter++)
	{
		int buf = (*iter - '0') * 2 + flag;
		*iter = (buf % 10) + '0';
		flag = buf / 10;
	}
	return flag;
}
int main()
{
	string str;
	while (cin >> str)
	{
		string result("0.");
		for (int i = 0; i < 62; i++)
		{
			int buf = cheng2(str);
			result.push_back(buf + '0');
		}
		cout << result << endl;
	}
	return 0;
}
*/
/**
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息:" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vexEnd[i][j] = -1;
			}
			else
			{
				dist.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vexEnd[i][j] = dist.vexEnd[i][k];
				}
			}
		}
	}
}
void showPaht(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		cout << "no path from " << v0 << " to " << v1 << endl;
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << "->";
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;

}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPaht(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;
	destroyGraph(G);
	return 0;
}
*/
/****拓扑排序********
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct edgeNode
{
	int vexEnd;
	int weight;
	edgeNode *nextNode;
};
struct vexNode
{
	string vertex;
	edgeNode *firstNode;
};
struct GraphList
{
	int vexNum;
	int edgeNum;
	vexNode *vexs;
};
int locate(const GraphList &G, string str)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		if (G.vexs[i].vertex == str)
		{
			return i;
		}
	}
	return -1;
}
void createGraph(GraphList &G)
{
	if (G.vexs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.vexs = new vexNode[G.vexNum];
	cout << "请输入各顶点的名字：" << endl;
	for (int i = 0; i < G.vexNum; i++)
	{
		cin >> G.vexs[i].vertex;
		G.vexs[i].firstNode = NULL;
	}
	cout << "请输入各边的具体信息：" << endl;
	string v0, v1;
	int w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		int x = locate(G, v0);
		int y = locate(G, v1);
		if (x == -1 || y == -1)
		{
			cout << "输入有误，请重新输入" << endl;
			i--;
			continue;
		}
		edgeNode *p = new edgeNode;
		p->vexEnd = y;
		p->weight = w;
		p->nextNode = G.vexs[x].firstNode;
		G.vexs[x].firstNode = p;
	}
}
void destroyGraph(GraphList &G)
{
	if (G.vexs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		edgeNode *q = NULL;
		while (p)
		{
			q = p->nextNode;
			delete p;
			p = q;
		}
		G.vexs[i].firstNode = NULL;
	}
	delete[]G.vexs;
	G.vexs = NULL;
}
void findIndegree(const GraphList &G, int *indegree)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		edgeNode *p = G.vexs[i].firstNode;
		while (p)
		{
			indegree[p->vexEnd]++;
			p = p->nextNode;
		}
	}
}
void AOV(const GraphList &G, int *result)
{
	int index = 0;
	int *indegree = new int[G.vexNum];
	findIndegree(G, indegree);
	
	stack<int> st;
	for (int i = 0; i < G.vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			st.push(i);
		}
	}
	while (!st.empty())
	{
		int j = st.top();
		st.pop();
		result[index++] = j;
		edgeNode *p = G.vexs[j].firstNode;
		while (p)
		{
			indegree[p->vexEnd]--;
			if (indegree[p->vexEnd] == 0)
			{
				st.push(p->vexEnd);
			}
			p = p->nextNode;
		}
	}
	delete[]indegree;
}
int main()
{
	GraphList G;
	G.vexs = NULL;
	createGraph(G);
	int *result = new int[G.vexNum];
	AOV(G, result);
	for (int i = 0; i < G.vexNum; i++)
	{
		cout << G.vexs[result[i]].vertex << ' ';
	}
	cout << endl;
	delete[]result;
	destroyGraph(G);
	return 0;
}
*/
/********
#include<iostream>
using namespace std;
struct BinTreeNode
{
	int key;
	int hei;
	BinTreeNode *llink, *rlink;
};
BinTreeNode *createNode(int key)
{
	BinTreeNode *p = new BinTreeNode;
	if (p)
	{
		p->key = key;
		p->hei = 0;
		p->llink = p->rlink = NULL;
	}
	return p;
}
int height(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return -1;
	}
	return tree->hei;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
BinTreeNode *LL(BinTreeNode *a)
{
	BinTreeNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink = a;
	a->hei = max(height(a->llink), height(a->rlink)) + 1;
	b->hei = max(height(b->llink), a->hei) + 1;
	return b;
}
BinTreeNode *RR(BinTreeNode *a)
{
	BinTreeNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink = a;
	a->hei = max(height(a->llink), height(a->rlink)) + 1;
	b->hei = max(a->hei, height(b->rlink));
	return b;
}
BinTreeNode *LR(BinTreeNode *a)
{
	a->llink = RR(a->llink);
	return LL(a);
}
BinTreeNode *RL(BinTreeNode *a)
{
	a->rlink = LL(a->rlink);
	return RR(a);
}
void insert(BinTreeNode **ptree, int key)
{
	if (ptree == NULL)
	{
		return;
	}
	if (*ptree == NULL)
	{
		*ptree = createNode(key);
		return;
	}
	if (key < (*ptree)->key)
	{
		insert(&(*ptree)->llink, key);
		if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
		{
			if (key < (*ptree)->llink->key)
			{
				*ptree = LL(*ptree);
			}
			else
			{ 
				*ptree = LR(*ptree);
			}
		}
	}
	else if (key>(*ptree)->key)
	{
		insert(&(*ptree)->rlink, key);
		if (2 == height((*ptree)->rlink) - height((*ptree)->llink))
		{
			if (key > (*ptree)->rlink->key)
			{
				*ptree = RR(*ptree);
			}
			else
			{
				*ptree = RL(*ptree);
			}
		}
	}
	(*ptree)->hei = max(height((*ptree)->llink), height((*ptree)->rlink)) + 1;
}
void createTree(BinTreeNode **ptree)
{
	int x;
	while (cin >> x)
	{
		insert(ptree, x);
	}
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || (*ptree) == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void deleteNode(BinTreeNode **ptree, int key)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	if (key < (*ptree)->key)
	{
		deleteNode(&(*ptree)->llink, key);
		if (2 == height((*ptree)->rlink) - height((*ptree)->llink))
		{
			if (height((*ptree)->rlink->rlink)>height((*ptree)->rlink->llink))
			{
				*ptree = RR(*ptree);
			}
			else
			{
				*ptree = RL(*ptree);
			}
		}
	}
	else if (key>(*ptree)->key)
	{
		deleteNode(&(*ptree)->rlink, key);
		if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
		{
			if (height((*ptree)->llink->llink) > height((*ptree)->llink->rlink))
			{
				*ptree = LL(*ptree);
			}
			else
			{
				*ptree = LR(*ptree);
			}
		}
	}
	else
	{
		if ((*ptree)->llink != NULL && (*ptree)->rlink != NULL)
		{
			BinTreeNode *r = (*ptree)->rlink;
			while (r->llink)
			{
				r = r->llink;
			}
			(*ptree)->key = r->key;
			deleteNode(&(*ptree)->rlink, r->key);
			if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
			{
				if (height((*ptree)->llink->llink) > height((*ptree)->llink->rlink))
				{
					*ptree = LL(*ptree);
				}
				else
				{
					*ptree = LR(*ptree);
				}
			}
		}
		else
		{
			BinTreeNode *r = *ptree;
			if ((*ptree)->llink == NULL)
			{
				*ptree = (*ptree)->rlink;
			}
			else 
			{
				*ptree = (*ptree)->llink;
			}
			delete r;
			r = NULL;
		}
		
	}
	if (*ptree != NULL)
	{
		(*ptree)->hei = max(height((*ptree)->llink), height((*ptree)->rlink)) + 1;
	}
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->key << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->key << ' ';
	inOrder(tree->rlink);
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	cout << endl;
	inOrder(tree);
	cout << endl;
	int x;
	cin.clear();
	while (cin >> x)
	{
		deleteNode(&tree, x);
		preOrder(tree);
		cout << endl;
		inOrder(tree);
		cout << endl;
	}
	destroyTree(&tree);
	return 0;
}
*/
/*******************************************
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int key;
	int hei;
	BinTreeNode *llink, *rlink;
};
BinTreeNode *createNode(int key)
{
	BinTreeNode *p = new BinTreeNode;
	if (p)
	{
		p->key = key;
		p->hei = 0;
		p->llink = p->rlink = NULL;
	}
	return p;
}
int height(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return -1;
	}
	return tree->hei;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
BinTreeNode *LL(BinTreeNode *a)
{
	BinTreeNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink = a;
	a->hei = max(height(a->llink), height(a->rlink))+1;
	b->hei = max(height(b->llink), a->hei) + 1;
	return b;
}
BinTreeNode *RR(BinTreeNode *a)
{
	BinTreeNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink = a;
	a->hei = max(height(a->llink), height(a->rlink)) + 1;
	b->hei = max(a->hei, height(b->rlink)) + 1;
	return b;
}
BinTreeNode *LR(BinTreeNode *a)
{
	a->llink = RR(a->llink);
	return LL(a);
}
BinTreeNode *RL(BinTreeNode *a)
{
	a->rlink = LL(a->rlink);
	return RR(a);
}
void insertNode(BinTreeNode **ptree, int key)
{
	if (ptree == NULL)
	{
		return;
	}
	if (*ptree == NULL)
	{
		*ptree = createNode(key);
		return;
	}
	if (key < (*ptree)->key)
	{
		insertNode(&(*ptree)->llink,key);
		if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
		{
			if (key<(*ptree)->llink->key)
			{
				*ptree = LL(*ptree);
			}
			else
			{
				*ptree = LR(*ptree);
			}
		}
	}
	else if (key>(*ptree)->key)
	{
		insertNode(&(*ptree)->rlink, key);
		if (2 == height((*ptree)->rlink) - height((*ptree)->llink))
		{
			if (key > (*ptree)->rlink->key)
			{
				*ptree = RR(*ptree);
			}
			else
			{
				*ptree = RL(*ptree);
			}
		}
	}
	(*ptree)->hei = max(height((*ptree)->llink), height((*ptree)->rlink)) + 1;
}
void deleteNode(BinTreeNode **ptree, int key)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	if (key < (*ptree)->key)
	{
		deleteNode(&(*ptree)->llink, key);
		if (2 == height((*ptree)->rlink) - height((*ptree)->llink))
		{
			if (height((*ptree)->rlink->rlink)>height((*ptree)->rlink->llink))
			{
				*ptree = RR(*ptree);
			}
			else
			{
				*ptree = RL(*ptree);
			}
		}

	}
	else if (key>(*ptree)->key)
	{
		deleteNode(&(*ptree)->rlink, key);
		if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
		{
			if (height((*ptree)->llink->llink) > height((*ptree)->llink->rlink))
			{
				*ptree = LL(*ptree);
			}
			else
			{
				*ptree = LR(*ptree);
			}
		}
	}
	else
	{
		if ((*ptree)->llink != NULL && (*ptree)->rlink != NULL)
		{
			BinTreeNode *r = (*ptree)->rlink;
			while (r->llink)
			{
				r = r->llink;
			}
			(*ptree)->key = r->key;
			deleteNode(&(*ptree)->rlink, r->key);
			if (2 == height((*ptree)->llink) - height((*ptree)->rlink))
			{
				if (height((*ptree)->llink->llink) > height((*ptree)->llink->rlink))
				{
					*ptree = LL(*ptree);
				}
				else
				{
					*ptree = LR(*ptree);
				}
			}
		}
		else
		{
			BinTreeNode *r = *ptree;
			if ((*ptree)->llink == NULL)
			{
				*ptree = (*ptree)->rlink;
			}
			else
			{
				*ptree = (*ptree)->llink;
			}
			delete r;
			r = NULL;
		}
	}
	if (*ptree)
	{
		(*ptree)->hei = max(height((*ptree)->llink), height((*ptree)->rlink)) + 1;
	}
}
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int x;
	while (cin >> x)
	{
		insertNode(ptree, x);
	}
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	inOrder(tree);
	postOrder(tree);
	int x;
	cin.clear();
	while (cin >> x)
	{
		deleteNode(&tree, x);
		preOrder(tree);
		inOrder(tree);
		postOrder(tree);
	}
	destroyTree(&tree);
	return 0;
}
*/
/**********红黑树C++实现*********************************
#include<iostream>
#include<stack>
using namespace std;
const bool black = true;
const bool red = false;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink, *rlink, *parent;
};
class RBTree
{
public:
	RBTree();
	~RBTree();
	void insertNode(int key);
	void deleteNode(int key);
	void preOrder();
	void inOrder();
	void postOrder();
private:
	void insertFixup(RBNode *pnode);
	void deleteFixup(RBNode *pnode);
	RBNode *rotate_left(RBNode *a);
	RBNode *rotate_right(RBNode *a);
	RBNode *createNode(int key);
	void destroy(RBNode *pnode);
	RBNode *root;
	RBNode *m_null;
};
RBTree::RBTree()
{
	m_null = new RBNode;
	if (m_null)
	{
		m_null->color = black;
		m_null->rlink = m_null->llink = m_null->parent = m_null;
	}
	root = m_null;
}
RBTree::~RBTree()
{
	if (root)
	{
		destroy(root);
		root = NULL;
	}
	delete m_null;
	m_null = NULL;
}
void RBTree::insertNode(int key)
{
	RBNode *p = root;
	RBNode *parent = m_null;
	while (p!=m_null)
	{
		parent = p;
		if (p->key == key)
		{
			return;
		}
		else if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	RBNode *newNode = createNode(key);
	if (parent == m_null)
	{
		root = newNode;
		root->color = black;
		root->parent = m_null;
	}
	else
	{
		if (key < parent->key)
		{
			parent->llink = newNode;
		}
		else
		{
			parent->rlink = newNode;
		}
		newNode->parent = parent;
		insertFixup(newNode);
	}
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent = pnode->parent;
	RBNode *grandParent = m_null;
	while (parent != m_null&&parent->color == red)
	{
		grandParent = parent->parent;
		if (parent == grandParent->llink)
		{
			RBNode *uncle = grandParent->rlink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandParent->color = red;
				pnode = grandParent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->rlink)
				{
					pnode = rotate_left(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandParent->color = red;
				rotate_right(grandParent);
			}
		}
		else
		{
			RBNode *uncle = grandParent->llink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandParent->color = red;
				pnode = grandParent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->llink)
				{
					pnode = rotate_right(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandParent->color = red;
				rotate_left(grandParent);
			}
		}
	}
	root->color = black;
}
void RBTree::deleteNode(int key)
{
	RBNode *delNode = root;
	while (delNode != m_null)
	{
		if (key == delNode->key)
		{
			break;
		}
		else if (key < delNode->key)
		{
			delNode = delNode->llink;
		}
		else
		{
			delNode = delNode->rlink;
		}
	}
	if (delNode == m_null)
	{
		return;
	}
	RBNode *realDel = delNode;
	RBNode *replace = m_null;
	if (delNode->llink == m_null)
	{
		replace = delNode->rlink;
	}
	else if (delNode->rlink == m_null)
	{
		replace = delNode->llink;
	}
	else
	{
		realDel = delNode->rlink;
		while (realDel->llink != m_null)
		{
			realDel = realDel->llink;
		}
		replace = realDel->rlink;
		delNode->key = realDel->key;
	}
	if (realDel == root)
	{
		root = replace;
		replace->parent = m_null;
	}
	else
	{
		if (realDel == realDel->parent->llink)
		{
			realDel->parent->llink = replace;
		}
		else
		{
			realDel->parent->rlink = replace;
		}
		replace->parent = realDel->parent;
	}
	if (realDel->color == black)
	{
		deleteFixup(replace);
	}
	delete realDel;
	realDel = m_null;
}

void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p = pnode;
	RBNode *parent = m_null;
	RBNode *slibing = m_null;
	while (p != root&&p->color == black)
	{
		parent = p->parent;
		if (p == parent->llink)
		{
			slibing = parent->rlink;
			if (slibing->color == red)
			{
				slibing->color = black;
				parent->color = red;
				rotate_left(parent);
				slibing = parent->rlink;
			}
			if (slibing->llink->color == black&&slibing->rlink->color == black)
			{
				slibing->color = red;
				p = parent;
			}
			else
			{
				if (slibing->rlink->color == black)
				{
					slibing->color = red;
					slibing->llink->color = black;
					rotate_right(slibing);
					slibing = slibing->parent;
				}
				slibing->color = parent->color;
				parent->color = black;
				slibing->rlink->color = black;
				rotate_left(parent);
				p = root;
			}
		}
		else
		{
			slibing = parent->llink;
			if (slibing->color == red)
			{
				slibing->color = black;
				parent->color = red;
				rotate_right(parent);
				slibing = parent->llink;
			}
			if (slibing->llink->color == black&&slibing->rlink->color == black)
			{
				slibing->color = red;
				p = parent;
			}
			else
			{
				if (slibing->llink->color == black)
				{
					slibing->color = red;
					slibing->rlink->color = black;
					rotate_left(slibing);
					slibing = slibing->parent;
				}
				slibing->color = parent->color;
				parent->color = black;
				slibing->llink->color = black;
				rotate_right(parent);
				p = root;
			}
		}
	}
	p->color = black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->llink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->rlink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p = new RBNode;
	if (p)
	{
		p->key = key;
		p->color = red;
		p->llink = p->rlink = p->parent = m_null;
	}
	return p;
}
void RBTree::destroy(RBNode *pnode)
{
	if (pnode == m_null)
	{
		return;
	}
	destroy(pnode->llink);
	destroy(pnode->rlink);
	delete pnode;
	pnode = m_null;
}
void RBTree::preOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p != m_null)
		{
			cout << p->key << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void RBTree::inOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void RBTree::postOrder()
{
	if (root == m_null)
	{
		return;
	}
	stack<RBNode*> st;
	RBNode *p = root;
	RBNode *pp = m_null;
	while (p != m_null || !st.empty())
	{
		while (p != m_null)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == m_null)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->key << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = m_null;
		}
	}
	cout << endl;
}
int main()
{
	RBTree tree;
	int x;
	while (cin >> x)
	{
		tree.insertNode(x);
	}
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	cin.clear();
	while (cin >> x)
	{
		tree.deleteNode(x);
		tree.preOrder();
		tree.inOrder();
		tree.postOrder();
	}
	return 0;
}
*/
/*****各种排序
#include<iostream>
using namespace std;
void insertSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void shell(int *a, int n, int k)
{
	for (int i = k; i < n; i++)   //以前这里一直都是错的
	{
		int j = i - k;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + k] = a[j];
			j -= k;
		}
		a[j + k] = x;
	}
}
void shellSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int k = n / 2;
	while (k)
	{
		shell(a, n, k);
		k /= 2;
	}
}
void selectSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}
}
void heap(int *a, int n, int i)
{
	int child;
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[i] < a[child])
		{
			a[i] ^= a[child];
			a[child] ^= a[i];
			a[i] ^= a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heap(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[0] ^= a[i];
		a[i] ^= a[0];
		a[0] ^= a[i];
		heap(a, i, 0);
	}
}
void QiPaoSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}
void QSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int i = 0;
	int j = n - 1;
	int k = a[0];
	while (i < j)
	{
		for (; i < j; j--)
		{
			if (a[j] < k)
			{
				a[i++] = a[j];
				break;
			}
		}
		for (; i < j; i++)
		{
			if (a[i]>k)
			{
				a[j--] = a[i];
				break;
			}
		}
	}
	a[i] = k;
	QSort(a, i);
	QSort(a + i + 1, n - i - 1);
}
int main()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//insertSort(a, 9);
	shellSort(a, 9);
	//selectSort(a, 9);
	//heapSort(a, 9);
	//QiPaoSort(a, 9);
	//QSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/*************************
#include<iostream>
using namespace std;
struct A{
	void foo(){ cout << "foo" << endl; }
	virtual void bar(){ cout << "bar" << endl; }
	A(){ bar(); }
};
struct B :A{
	void foo(){ cout << "b_foo" << endl; }
	void bar(){ cout << "b_bar" << endl; }
};
int main()
{
	A *p = new B;
	p->foo();
	p->bar();
	return 0;
}
*/
/******
// ---------------------------------------------------   
//  注1: 一般要求一个解,此程序是得到所有解   
//  注2: 由于32位unsigned int限制,最多32个物品                           
// ---------------------------------------------------   

#include <iostream>   
using   namespace  std;

// 物品总数   
const   int  N_ITEM = 5;

// 背包能装的重量   
const   int  BAG = 15;

// 初始化每个物品的重量   
int  item[N_ITEM] = { 2, 3, 5, 7, 8 };

// 标记数组   
int  flag[N_ITEM] = { 0, 0, 0, 0, 0 };

// 结果计数器   
int  resultCount = 0;

// 打印结果   
void  Print();

int  main()
{
	// 打印已知条件   
	cout << "BAG Weight:" << BAG << endl;
	cout << "Item Number:" << N_ITEM << endl;

	for (int i = 0; i != N_ITEM; i++)
	{
		cout << "Item." << i + 1 << " W=" << item[i] << "\t";
	}

	cout << endl;

	unsigned int  count = 0;
	unsigned int  all_count = 1;

	for (int i = 0; i != N_ITEM; i++)
	{
		all_count *= 2;//all_count记录可能解的个数   
	}

	while (1)
	{
		// 模拟递归...列举所有flag数组可能   
		// 其实就这个for循环是关键   
		for (int i = 0; i != N_ITEM; i++)
		{
			if (0 == flag[i])
			{
				flag[i] = 1;
				//continue;
			}
			else
			{
				flag[i] = 0;
				break;
			}
		}

		// 本次重量,初始化0   
		int  temp = 0;

		// 按标记计算所有选中物品重量和   
		for (int i = 0; i != N_ITEM; i++)
		{
			if (1 == flag[i])
			{
				temp += item[i];
			}
		}

		// 满足背包重量就打印   
		if (temp == BAG)
		{
			resultCount++;
			Print();
		}

		// 如果遍历了所有情况就break掉while(1)循环   
		count++;
		if (count == all_count)
		{
			break;
		}
	}

	return  0;
}

void  Print()
{
	cout << "Result " << resultCount << endl;

	for (int i = 0; i != N_ITEM; i++)
	{
		if (1 == flag[i])
		{
			cout <<item[i]<<' ';
		}
	}

	cout << endl;
}
*/
/********背包问题，打印能把背包装满的所有可能
#include<iostream>
using namespace std;
int main()
{
	int sum;
	cin >> sum;
	int n;
	cin >> n;
	int *a = new int[n];
	int *flag = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		flag[i] = 0;
	}
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		num *= 2;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0)
			{
				flag[j] = 1;
			}
			else
			{
				flag[j] = 0;
				break;
			}
		}
		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 1)
			{
				temp += a[j];
			}
		}
		if (temp == sum)
		{
			for (int j = 0; j < n; j++)
			{
				if (flag[j] == 1)
				{
					cout << a[j] << ' ';
				}
			}
			cout << endl;
		}
	}
}
*/
/*分冶法求格雷码*
#include<iostream>
using namespace std;
int a[1024][10];
void gradcode(int n)
{
	int i, j, num = 1;
	if (n == 1)
	{
		a[0][0] = 0;
		a[1][0] = 1;
	}
	else
	{
		gradcode(n - 1);
		for (i = 0; i<n; i++)
			num = num * 2;
		for (i = 0; i<num / 2; i++)
		for (j = 0; j<n - 1; j++)
			a[num - 1 - i][j] = a[i][j];
		for (i = 0; i<num / 2; i++)
			a[i][j] = 0;
		for (i = num / 2; i<num; i++)
			a[i][j] = 1;
	}
}
int main()
{
	int n, i, j, num = 1;
	cout<<"请输入一个大于0小于10的整数:";
	cin >> n;

	for (i = 0; i<n; i++)
		num = num * 2;
	gradcode(n);
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<n; j++)
			cout<<a[i][j];
		cout << endl;
	}

	return 0;
}
*/
/******分冶法求n位格雷码**********
#include<iostream>
using namespace std;
int a[1024][10];
void gradcode(int n)
{
	if (n == 1)
	{
		a[0][0] = 0;
		a[1][0] = 1;
	}
	else
	{
		gradcode(n - 1);
		int num = 1;
		for (int i = 0; i < n; i++)
		{
			num *= 2;
		}
		for (int i = 0; i < num / 2; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				a[num - i - 1][j] = a[i][j];
			}
		}
		for (int i = 0; i < num / 2; i++)
		{
			a[i][n - 1] = 0;
		}
		for (int i = num / 2; i < num; i++)
		{
			a[i][n - 1] = 1;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	gradcode(n);
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		num *= 2;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][n - j - 1];
		}
		cout << endl;
	}
	return 0;
}
*/
/*****公式法求格雷码*******************
#include<iostream>
using namespace std;
void print(int x, int n)
{
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = x & 1;
		x >>= 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[n - i - 1];
	}
	cout << endl;
	delete[]a;
}
void gradcode(int n)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		num *= 2;
	}
	for (int i = 0; i < num; i++)
	{
		print((i >> 1) ^ i,n);
	}
}
int main()
{
	int n;
	cin >> n;
	gradcode(n);
}
*/
/***************************
#include<iostream>
using namespace std;
class X
{
public:
	X()
	{
		cout << "X" << endl;
	}
};
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
private:
};
class B:public A
{
public:
	B()
	{
		cout << "B" << endl;
	}
private:
	X x;
};
int main()
{
	B obj;
	return 0;
}
*/
/******最大公约数
#include<iostream>
using namespace std;
int gys(int x, int y)
{
	return (y == 0) ? x : (gys(y, x%y));
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout << gys(x, y) << endl;
	}
	return 0;
}
*/
/***不使用+。-，*，/求两个数的和******
#include<iostream>
using namespace std;
int add(int x, int y)
{
	return (y == 0) ? x : (add(x^y, (x&y) << 1));
}
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout<<add(x, y)<<endl;
	}
	return 0;
}
*/
/**************************
#include<iostream>
using namespace std;
void reverse(char *begin, char *end)
{
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
void *pszStringRotate(char *pszString, int k)
{
	char *p = pszString;
	int n = 0;
	while (*(pszString + n++) != '\0');
	n--;
	k%=n;
	if (k == 0)
	{
		return p;
	}
	reverse(p, p + k - 1);
	reverse(p + k, p + n - 1);
	reverse(p, p + n - 1);
	return p;
}
int main()
{
	char c[] = "ABCDEFG";
	pszStringRotate(c, 3);
	cout << c << endl;
	return 0;
}
*/
/*******************
#include<iostream>
using namespace std;
class A
{
public:
	A(int i = 0) :a3(i++), a1(i++), a2(i++)//按照内存中的顺序依次初始化
	{

	}
	void print()
	{
		cout << a1 << endl;
		cout << a2 << endl;
		cout << a3 << endl;
	}
private:
	int a1;
	int a2;
	int a3;
};
int main()
{
	A obj;
	obj.print();
	return 0;
}
*/
/*****************
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i=0);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	int size;
	T *data;
};
template<typename T>
array<T>::array(int i = 0) : size(i), data(NULL)
{
	if (size)
	{
		data = new T[size];
	}

}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(NULL)
{
	if (size)
	{
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	delete[]data;
	size = obj.size;
	if (size)
	{
		data = new T[size];
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = obj.data[i];
			}
		}
	}
	return *this;
}



template<typename T>
array<T>::~array()
{
	if (data)
	{
		delete[]data;
		data = NULL;
	}
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
int main()
{
	array<string> str(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}
	array<string> str0(str);
	array<string> str1;
	str1 = str;
	for (int i = 0; i < 5; i++)
	{
		cout << str[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << str0[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << str1[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/****************
#include<iostream>
using namespace std;
struct A
{
	long a1;
	short a2;
	int a3;
	int *a4;
};
int main()
{
	cout << sizeof(A) << endl;
	return 0;
}
*/
/*******
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array
{
public:
	array(int i = 0);
	array(const array &obj);
	array &operator=(const array &obj);
	~array();
	T &operator[](int i);
private:
	void release();
	int size;
	T *data;
	int *count;
};
template<typename T>
array<T>::array(int i = 0) : size(i), data(NULL), count(new int)
{
	*count = 1;
	if (size)
	{
		data = new T[size];
	}
}
template<typename T>
array<T>::array(const array &obj) : size(obj.size), data(obj.data), count(obj.count)
{
	(*count)++;
}
template<typename T>
array<T> &array<T>::operator=(const array &obj)
{
	if (this == &obj)
	{
		return *this;
	}
	release();
	size = obj.size;
	data = obj.data;
	count = obj.count;
	(*count)++;
	return *this;
}
template<typename T>
array<T>::~array()
{
	release();
}
template<typename T>
T &array<T>::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return data[i];
	}
}
template<typename T>
void array<T>::release()
{
	(*count)--;
	if (*count == 0)
	{
		if (data)
		{
			delete[]data;
			data = NULL;
		}
		delete count;
		count = NULL;
	}
}
int main()
{
	array<string> str(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}
	array<string> str0(str);
	array<string> str1;
	str1 = str;
	for (int i = 0; i < 5; i++)
	{
		cout << str[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << str0[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << str1[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/************
#include<iostream>
using namespace std;
class A
{
public:
	void fun()
	{
		delete this;
	}
};
int main()
{
	A *p = new A;
	p->fun();
	return 0;
}
*/
/***********
#include<iostream>
using namespace std;
bool Find(int *Matrix, int rows, int clumns, int num)
{
	if (Matrix == NULL || rows <= 0 || clumns <= 0)
	{
		return false;
	}
	int row = 0;
	int clumn = clumns - 1;
	while (row < rows&&clumn >= 0)
	{
		if (Matrix[row*clumns + clumn]==num)
		{
			return true;
		}
		else if (Matrix[row*clumns + clumn]>num)
		{
			clumn--;
		}
		else
		{
			row++;
		}
	}
	return false;
}
int main()
{
	int matrix[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	cout << Find(matrix, 4, 4, 7) << endl;
	return 0;
}
*/
/****************
#include<iostream>
using namespace std;
bool Find(int (*Matrix)[4], int rows, int clumns, int num)
{
	if (Matrix == NULL || rows <= 0 || clumns <= 0)
	{
		return false;
	}
	int row = 0;
	int clumn = clumns - 1;
	while (row < rows&&clumn >= 0)
	{
		if (Matrix[row][clumn] == num)
		{
			return true;
		}
		else if (Matrix[row][clumn]>num)
		{
			clumn--;
		}
		else
		{
			row++;
		}
	}
	return false;
}
int main()
{
	int matrix[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	cout << Find(matrix, 4, 4, 7) << endl;
	return 0;
}
*/
/********顺时针打印二维数组**************
#include<iostream>
using namespace std;
void fun(int *a[], int rows, int clumns)
{
	if (a == NULL || rows <= 0 || clumns <= 0)
	{
		return;
	}
	int start = 0;
	while (start * 2 < rows&&start * 2 < clumns)
	{
		int endX = clumns - start - 1;
		int endY = rows - start - 1;
		for (int j = start; j <= endX; j++)
		{
			cout << a[start][j] << ' ';
		}
		for (int i = start + 1; i <= endY; i++)
		{
			cout << a[i][endX] << ' ';
		}
		if (start < endY)
		{
			for (int j = endX - 1; j >= start; j--)
			{
				cout << a[endY][j] << ' ';
			}
		}
		if (start < endX)
		{
			for (int i = endY - 1; i>start; i--)
			{
				cout << a[i][start] << ' ';
			}
		}
		start++;
	}
	cout << endl;
}
int main()
{
	int rows, clumns;
	cin >> rows >> clumns;
	int **a = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[clumns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < clumns; j++)
		{
			cin >> a[i][j];
		}
	}
	fun(a, rows, clumns);
	return 0;
}
*/
/********************
#include<iostream>
#include<string>
using namespace std;
void ReplaceBlank(char *c)
{
	if (c == NULL)
	{
		return;
	}
	char *p = c;
	int n = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			n++;
		}
		p++;
	}
	char *q = p + 2 * n;
	while (p != q)
	{
		while (*p != ' ')
		{
			*q-- = *p--;
		}
		p--;
		*q-- = '0';
		*q-- = '2';
		*q-- = '%';
	}
}
int main()
{
	char c[100];
	gets_s(c);
	ReplaceBlank(c);
	cout << c << endl;
}
*/
/********************
#include<iostream>
using namespace std;
void fun(int *a, int *b, int len)
{
	if (a == NULL || b == NULL || len < 1)
	{
		return;
	}
	int *p = a;
	while (*(p+1)!= 0)
	{
		p++;
	}
	int *q = p + len;
	int i = len-1;
	while (i >= 0)
	{
		if (*p > b[i])
		{
			*q-- = *p--;
		}
		else
		{
			*q-- = b[i--];
		}
	}
}
int main()
{
	int a[100] = { 1, 5, 6, 8, 9 };
	int b[] = { 2, 3, 7 };
	fun(a, b, 3);
	int i = 0;
	while (a[i] != 0)
	{
		cout << a[i++] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/*********************************
#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
	int key;
	ListNode *next;
};
void createList(ListNode **pList)
{
	if (pList == NULL || *pList != NULL)
	{
		return;
	}
	int x;
	ListNode *p = *pList;
	while (cin >> x)
	{
		ListNode *newNode = new ListNode;
		newNode->key = x;
		newNode->next = NULL;
		if (p == NULL)
		{
			*pList = newNode;
			p = *pList;
		}
		else
		{
			p->next = newNode;
			p = p->next;
		}
	}
}
void destroyList(ListNode **pList)
{
	if (pList == NULL || *pList == NULL)
	{
		return;
	}
	ListNode *p = *pList;
	ListNode *q = NULL;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	*pList = NULL;
}
void removeNode(ListNode **pList, int key)
{
	if (pList == NULL || *pList == NULL)
	{
		return;
	}
	ListNode *p = *pList;
	ListNode *pre = NULL;
	while (p)
	{
		if (p->key == key)
		{
			break;
		}
		pre = p;
		p = p->next;
	}
	if (p == NULL)
	{
		return;
	}
	if (pre == NULL)
	{
		*pList = p->next;
	}
	else
	{
		pre->next = p->next;
	}
	delete p;
}
ListNode *findNode(ListNode *list, int key)
{
	ListNode *p = list;
	while (p)
	{
		if (p->key == key)
		{
			break;
		}
		p = p->next;
	}
	return p;
}
//链表的倒数第k个结点
ListNode *findNodeK(ListNode *list, int k)
{
	if (list == NULL || k < 1)
	{
		return NULL;
	}
	ListNode *p = list;
	for (int i = 0; i < k - 1; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			return NULL;
		}
	}
	ListNode *q = list;
	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}
//
void deleteNode(ListNode **pList, ListNode *del)
{
	if (pList == NULL || *pList == NULL||del==NULL)
	{
		return;
	}
	ListNode *p = *pList;
	if (del == *pList)
	{
		*pList = (*pList)->next;
	}
	else if (del->next==NULL)
	{
		while (p->next != del&&p!=NULL)
		{
			p = p->next;
		}
		p->next = NULL;
	}
	else
	{
		del->key = del->next->key;
		p = del->next;
		del->next = del->next->next;
		del = p;
		p = NULL;
	}
	delete del;
	del = NULL;
}
void print(ListNode *List)
{
	while (List != NULL)
	{
		cout << List->key << ' ';
		List = List->next;
	}
	cout << endl;
}
void printTail(ListNode *list)
{
	if (list == NULL)
	{
		return;
	}
	printTail(list->next);
	cout << list->key << ' ';
}
void printTailN(ListNode *List)
{
	if (List == NULL)
	{
		return;
	}
	stack<int> st;
	while (List)
	{
		st.push(List->key);
		List = List->next;
	}
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;

}
ListNode *reverse(ListNode *list)
{
	if (list == NULL)
	{
		return NULL;
	}
	ListNode *p = list;
	ListNode *q = p->next;
	ListNode *r = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	list->next = NULL;
	return p;
}
int main()
{
	ListNode *list = NULL;
	createList(&list);
	print(list);
	printTail(list);
	cout << endl;
	printTailN(list);
	list = reverse(list);
	print(list);
	int x;
	cin.clear();
	while (cin >> x)
	{
		ListNode *p = findNodeK(list, x);
		deleteNode(&list, p);
		print(list);
	}
	destroyList(&list);
	return 0;
}
*/

/**********
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int x;
	while (cin >> x)
	{
		ivec.push_back(x);
	}
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
*/
/*****************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 1000000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和边数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vexEnd[i][j] = -1;
			}
			else
			{
				dist.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vexEnd[i][j] = dist.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		cout << "no path from " << v0 << " to " << v1 << endl;
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << "->";
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	destroyGraph(G);
	return 0;
}
*/
/******************
#include<iostream>
#include<vector>
using namespace std;

int getPos(vector<int> A, int n, int val) 
{
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (A[mid] == val)
		{
			while (mid >= 1 && A[mid - 1] == A[mid])
			{
				mid--;
			}
			return mid;
		}
		else if (A[mid] > val)
		{
			end = mid-1;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return -1;
}
int main()
{
	//[9, 13, 21, 31], 4, 9
	vector<int> A;
	A.push_back(9);
	A.push_back(13); 
	A.push_back(21); 
	A.push_back(31);
	cout << getPos(A, 4, 9) << endl;
	return 0;
}
*/
/******
#include<iostream>
#include<string>
using namespace std;
char findFirstRepeat(string A, int n) 
{
	bool a[256] = { false };
	for (int i = 0; i < n; i++)
	{
		if (a[A[i]] = true)
		{
			return A[i];
		}
		a[A[i]] = true;
	}
	return 0;
}
int main()
{
}
*/
/*********************************
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
int fun(string str)
{
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter >= 'A'&&*iter <= 'Z')
		{
			*iter += 32;
		}
	}
	int size = str.size();
	int it = 0;
	int sum = 0;
	while ((it = str.find("coder",it))!=string::npos)
	{
		it++;
		sum++;
	}
	return sum;
}
bool cmp(pair<string, int> x, pair<string, int> y)
{
	return x.second > y.second;
}
vector<string> findCoder(vector<string> A, int n) 
{
	vector<pair<string, int> > pairVec;
	for (vector<string>::iterator iter = A.begin(); iter != A.end(); ++iter)
	{
		int num = fun(*iter);
		if (num > 0)
		{
			pairVec.push_back(make_pair(*iter, num));
		}
	}
	sort(pairVec.begin(), pairVec.end(), cmp);
	vector<string> result;
	for (vector<pair<string, int> >::iterator iter = pairVec.begin(); iter != pairVec.end(); ++iter)
	{
		result.push_back(iter->first);
	}
	return result;
}
int main()
{
	return 0;
}
*/
/***************
#include<iostream>
using namespace std;
int maxCover(int *a, int n, int L)
{
	int MAX = 1;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = i; j < n; j++)
		{
			if (a[j] - a[i]>L)
			{
				break;
			}
			count++;
		}
		if (MAX < count)
		{
			MAX = count;
			start = i;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << a[i + start] << ' ';
	}
	cout << endl;
	return MAX;
}

int maxCover1(int a[], int n, int L)
{
	int count = 2, maxCount = 1, start;
	int i = 0, j = 1;
	while (i < n && j < n){
		while ((j < n) && (a[j] - a[i] <= L))
		{
			j++;
			count++;
		}
		// 退回到满足条件的j
		j--;
		count--;
		if (maxCount < count)
		{
			start = i;
			maxCount = count;
		}
		i++;
		j++;
	}
	printf("covered point: ");
	for (i = start; i < start + maxCount; i++)
	{
		cout<<a[i]<<' ';
	}
	cout << endl;
	return maxCount;
}
int main()
{
	int a[] = { 1, 3, 7, 8, 10, 11, 12, 13, 15, 16, 17, 18, 21 };
	cout<<maxCover(a, 13, 8)<<endl; 
	int b[] = { 1, 2, 3, 4, 5, 100, 1000 };
	cout << maxCover(b, 7, 8) << endl; 
	cout << maxCover1(a, 13, 8) << endl;
	cout << maxCover1(b, 7, 8) << endl;
	return 0;
}
*/
/*****************
#include<iostream>
using namespace std;
void merge(int *r, int *r1, int low, int m, int high)
{
	int i, j, k;
	i = low;
	j = m + 1;
	k = low;
	while (i <= m&&j <= high)
	{
		if (r[i] < r[j])
		{
			r1[k++] = r[i++];
		}
		else
		{
			r1[k++] = r[j++];
		}
	}
	while (i <= m)
	{
		r1[k++] = r[i++];
	}
	while (j <= high)
	{
		r1[k++] = r[j++];
	}
}
void mergePass(int *r, int *r1, int n, int length)
{
	int j, i = 0;
	while (i + 2 * length - 1 < n)
	{
		merge(r, r1, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n - 1)
	{
		merge(r, r1, i, i + length - 1, n - 1);
	}
	else
	{
		for (j = i; j < n; j++)
		{
			r1[j] = r[j];
		}
	}
}
void mergeSort(int *a, int n)
{
	int *b = new int[n];
	int length = 1;
	while (length < n)
	{
		mergePass(a, b, n, length);
		length *= 2;
	
		mergePass(b, a, n, length);
		length *= 2;
	}
	delete[]b;
}
int main()
{
	int a[10] = { 3, 1, 5, 7, 2, 4, 9, 6, 10, 8 };

	mergeSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
*/
/************
#include<iostream>
using namespace std;
void merge(int *a, int *b, int low, int m, int high)
{
	int i, j, k;
	i = low;
	j = m + 1;
	k = low;
	while (i <= m&&j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
}
void mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	while (i + 2 * length - 1 < n)
	{
		merge(a, b, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		merge(a, b, i, i + length - 1, n - 1);
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			b[j] = a[j];
		}
	}
}
void mergeSort(int *a, int n)
{
	int *b = new int[n];
	int length = 1;
	while (length < n)
	{
		mergePass(a, b, n, length);
		length *= 2;
		mergePass(b, a, n, length);
		length *= 2;
	}

	delete[]b;
}
int main()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	mergeSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/

/******各种排序算法********
#include<iostream>
using namespace std;
//插入排序
void insertSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//希尔排序
void shell(int *a, int n, int k)
{
	for (int i = k; i < n; i+=k)
	{
		int j = i - k;
		int x = a[i];
		while (j >= 0 && a[j]>x)
		{
			a[j + k] = a[j];
			j -= k;
		}
		a[j + k] = x;
	}
}
void shellSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int k = n / 2;
	while (k)
	{
		shell(a, n, k);
		k /= 2;
	}
}
//选择排序
void selectSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[x])
			{
				x = j;
			}
		}
		if (x != i)
		{
			a[x] = a[x] + a[i];
			a[i] = a[x] - a[i];
			a[x] = a[x] - a[i];
		}
	}
}
//堆排序
void heap(int *a, int n, int i)
{
	int child;
	for (; 2 * i + 1 < n; i = child)
	{
		child = 2 * i + 1;
		if (child < n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[i] < a[child])
		{
			a[i] ^= a[child];
			a[child] ^= a[i];
			a[i] ^= a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heap(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[i] ^= a[0];
		a[0] ^= a[i];
		a[i] ^= a[0];
		heap(a, i, 0);
	}
}
//起泡排序
void QiPaoSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}
//快速排血
void QSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int i = 0;
	int j = n - 1;
	int x = a[0];
	while (i < j)
	{
		for (; i < j; j--)
		{
			if (a[j] < x)
			{
				a[i++] = a[j];
				break;
			}
		}
		for (; i < j; i++)
		{
			if (a[i]>x)
			{
				a[j--] = a[i];
				break;
			}
		}
	}
	a[i] = x;
	QSort(a, i);
	QSort(a + i + 1, n - i - 1);
}
//归并排序
void merge(int *a, int *b, int low, int m, int high)
{
	int i, j, k;
	i = low;
	j = m + 1;
	k = low;
	while (i <= m&&j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
}
void mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	while (i + 2 * length - 1 < n)
	{
		merge(a, b, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		merge(a, b, i, i + length - 1, n - 1);
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			b[j] = a[j];
		}
	}
}
void mergeSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int *b = new int[n];
	int length = 1;
	while (length < n)
	{
		mergePass(a, b, n, length);
		length *= 2;
		mergePass(b, a, n, length);
		length *= 2;
	}
	delete[]b;
}

int main()
{
	int a[] = { 3, 8, 5, 2, 1, 11, 15, 19, 14, 12, 13, 20, 18, 17, 4, 6, 7, 16, 9, 10 };
	//insertSort(a, 20);
	//shellSort(a, 20);
	//selectSort(a, 20);
	//heapSort(a, 20);
	//QiPaoSort(a, 20);
	//QSort(a, 20);
	mergeSort(a, 20);
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/********全排列*************
#include<iostream>
using namespace std;
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void reverse(int *a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	while (begin < end)
	{
		a[begin] ^= a[end];
		a[end] ^= a[begin];
		a[begin] ^= a[end];
		begin++;
		end--;
	}
}
void fun(int *a, int n)
{
	while (true)
	{
		print(a, n);
		int i;
		for (i = n - 2; i >= 0; i--)
		{
			if (a[i] < a[i+1])
			{
				break;
			}
			else if (i == 0)
			{
				return;
			}
		}
		int j;
		for (j = n - 1; j>i; j--)
		{
			if (a[j] > a[i])
			{
				break;
			}
		}
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
		reverse(a, i + 1, n - 1);
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	fun(a, 5);
	return 0;
}
*/
/******************
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		if (isspace(s1[i]))
			cout << s2;
		else
			cout << s1[i];
	}
	cout << endl;
}
*/
/***********************
#include<iostream>
using namespace std;
void merge(int *a, int *b, int low, int m, int high)
{
	int i = low;
	int j = m + 1;
	int k = low;
	while (i <= m&&j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
}
void mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	while (i + 2 * length - 1 < n)
	{
		merge(a, b, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		merge(a, b, i, i + length - 1, n - 1);
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			b[j] = a[j];
		}
	}
}
void mergeSort(int *a, int n)
{
	int *b = new int[n];
	int length = 1;
	while (length < n)
	{
		mergePass(a, b, n, length);
		length *= 2;
		mergePass(b, a, n, length);
		length *= 2;
	}
	delete[]b;
}
int main()
{
	int a[] = { 2, 6, 10, 16, 8, 7, 5, 3, 17, 11, 12, 15, 19, 20, 1, 4, 9, 13, 18, 14 };
	mergeSort(a, 20);
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/*************
#include<iostream>
#include<vector>
#include<complex>
using namespace std;
int main()
{
	vector<int> ivec;
	complex<double> x(1, 2);
	cout << x << endl;
	return 0;
}
*/
/************************
public class Solution {
	public TreeNode pre = null;
	public TreeNode Convert(TreeNode pRootOfTree) {
		if (pRootOfTree == null) return null;
		
		TreeNode left = Convert(pRootOfTree.left);
		
		pRootOfTree.left = pre;
		if (pre != null)
		{
			pre.right = pRootOfTree;
		}
		pre = pRootOfTree;

		TreeNode right = Convert(pRootOfTree.right);
		
		return left != null ? left : pRootOfTree;
	}
}
*/
/*********************
#include<iostream>
using namespace std;
int min(int x, int y, int z)
{
	int m = x < y ? x : y;
	return m < z ? m : z;
}
int getUglyNumber(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int *a = new int[index];
	a[0] = 1;
	int next = 1;
	int pos2 = 0;
	int pos3 = 0;
	int pos5 = 0;
	while (next < index)
	{
		a[next] = min(a[pos2] * 2, a[pos3] * 3, a[pos5] * 5);
		while (a[pos2] * 2 <= a[next])
		{
			pos2++;
		}
		while (a[pos3] * 3 <= a[next])
		{
			pos3++;
		}
		while (a[pos5] * 5 <= a[next])
		{
			pos5++;
		}
		next++;
	}
	int result = a[index - 1];
	delete[]a;
	return result;
}
bool isUgly(int x)
{
	while (x % 2 == 0)
	{
		x /= 2;
	}
	while (x % 3 == 0)
	{
		x /= 3;
	}
	while (x % 5 == 0)
	{
		x /= 5;
	}
	return (x == 1) ? true : false;

}
int getUglyNumber0(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int cnt = 0;
	int x = 0;
	while (cnt < index)
	{
		x++;
		if (isUgly(x))
		{
			cnt++;
		}
	}
	return x;
}
int main()
{
	int index;
	while (cin >> index)
	{
		cout << getUglyNumber(index) << endl;
		cout << getUglyNumber0(index) << endl;
	}
	return 0;
}
*/
/******逆序对数***用到了归并排序的思想******
#include<iostream>
using namespace std;
int merge(int *a, int *b, int low, int m, int high)
{
	int i = low;
	int j = m + 1;
	int k = low;
	int sum = 0;
	while (i <= m&&j <= high)
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
			sum+=(m-i+1);
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
	return sum;
}
int mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	int sum = 0;
	while (i + 2 * length - 1 < n)
	{
		int buf=merge(a, b, i, i + length - 1, i + 2 * length - 1);
		sum += buf;
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		int buf=merge(a, b, i, i + length - 1, n - 1);
		sum += buf;
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			b[j] = a[j];
		}
	}
	return sum;
}
int mergeSort(int *a, int n)
{
	int *b = new int[n];
	int length = 1;
	int sum=0;
	while (length < n)
	{
		int buf=mergePass(a, b, n, length);
		length *= 2;
		buf+=mergePass(b, a, n, length);
		length *= 2;
		sum += buf;
	}
	delete[]b;
	return sum;
}
int fun(int *a, int n)
{
	if (a == NULL || n <= 0)
	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				sum++;
			}
		}
	}
	return sum;
}
int main()
{
	int a[] = {5,3,9,10,2,11,1,4,15,16,6,7,8,12,13,20,17,19,14,18};
	cout << fun(a, 20) << endl;
	cout << mergeSort(a, 20) << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/*****************************
#include<iostream>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
void createList(ListNode **plist0, ListNode **plist1, int *a, int na, int *b, int nb, int *c, int nc)
{
	if (plist0 == NULL || plist1 == NULL)
	{
		return;
	}
	*plist0 = new ListNode;
	(*plist0)->info = a[0];
	(*plist0)->next = NULL;
	ListNode *p = *plist0;
	for (int i = 1; i < na; i++)
	{
		ListNode *newNode = new ListNode;
		newNode->info = a[i];
		newNode->next = NULL;
		p->next = newNode;
		p = newNode;
	}
	ListNode *buf = NULL;
	for (int i = 0; i < nc; i++)
	{
		
		ListNode *newNode = new ListNode;
		newNode->info = c[i];
		newNode->next = NULL;
		if (i == 0)
		{
			buf = newNode;
		}
		p->next = newNode;
		p = newNode;
	}
	*plist1 = new ListNode;
	(*plist1)->info = b[0];
	(*plist1)->next = (nb==1)? buf:NULL;
	p = *plist1;
	for (int i = 1; i < nb; i++)
	{
		ListNode *newNode = new ListNode;
		newNode->info = b[i];
		newNode->next = (i == nb - 1) ? buf : NULL;
		p->next = newNode;
		p = newNode;
	}
}
void destroyList(ListNode **plist0, ListNode **plist1, ListNode *pNode)
{
	if (plist0 == NULL || *plist0 == NULL || plist1 == NULL || *plist1 == NULL)
	{
		return;
	}
	ListNode *p = *plist0;
	ListNode *q = NULL;
	while (p != pNode)
	{
		q = p->next;
		cout << p->info << ' ';
		delete p;
		p = q;
	}
	*plist0 = NULL;
	p = *plist1;
	while (p)
	{
		q = p->next;
		cout << p->info << ' ';
		delete p;
		p = q;
	}
	*plist1 = NULL;
}
void print(ListNode *list)
{
	while (list)
	{
		cout << list->info << ' ';
		list = list->next;
	}
	cout << endl;
}
int getLen(ListNode *list)
{
	int len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return len;
}
ListNode *findfirstCommon(ListNode *list0, ListNode *list1)
{
	if (list0 == NULL || list1 == NULL)
	{
		return NULL;
	}
	int len0 = getLen(list0);
	int len1 = getLen(list1);
	ListNode *longList = NULL;
	ListNode *shortList = NULL;
	int lenDis = 0;
	if (len0 > len1)
	{
		longList = list0;
		shortList = list1;
		lenDis = len0 - len1;
	}
	else
	{
		longList = list1;
		shortList = list0;
		lenDis = len1 - len0;
	}
	for (int i = 0; i < lenDis; i++)
	{
		longList = longList->next;
	}
	while (longList&&shortList&&longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}
int main()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5 };
	int c[] = { 6, 7 };
	ListNode *list0 = NULL;
	ListNode *list1 = NULL;
	createList(&list0, &list1, a, 3, b, 2, c, 2);
	print(list0);
	print(list1);
	ListNode *pNode = findfirstCommon(list0, list1);
	cout << pNode->info << endl;
	destroyList(&list0, &list1, pNode);
	return 0;
}
*/
/********
#include<iostream>
using namespace std;
int getFirstK(int *a, int n, int begin, int end,int k)
{
	if (begin > end)
	{
		return -1;
	}
	int mid = (end + begin) / 2;
	if (a[mid] == k)
	{
		if (mid == begin || a[mid - 1] != k)
		{
			return mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	else if (a[mid] > k)
	{
		end = mid - 1;
	}
	else
	{
		begin = mid + 1;
	}
	return getFirstK(a, n, begin, end, k);
}
int getLastK(int *a, int n, int begin, int end, int k)
{
	if (begin > end)
	{
		return -1;
	}
	int mid = (end + begin) / 2;
	if (a[mid] == k)
	{
		if (mid == end || a[mid + 1] != k)
		{
			return mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	else if (a[mid] > k)
	{
		end = mid - 1;
	}
	else
	{
		begin = mid + 1;
	}
	return getLastK(a, n, begin, end, k);
}
int getNumofK(int *a, int n,int k)
{
	if (a == NULL || n <= 0)
	{
		return -1;
	}
	int first = getFirstK(a, n, 0, n - 1,k);
	int last = getLastK(a, n, 0, n - 1, k);
	if (first == -1 || last == -1)
	{
		return 0;
	}
	return last - first + 1;

}
int main()
{
	int a[] = { 1, 2, 4, 5, 6, 7};
	cout << getNumofK(a,sizeof(a)/sizeof(int),3) << endl;
	return 0;
}
*/
/******二叉树的深度和宽度****
#include<iostream>
#include<queue>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void depth_width(BinTreeNode *tree, int &depth, int &width)
{
	depth = width = 0;
	if (tree == NULL)
	{
		return;
	}
	queue<BinTreeNode*> qu;
	BinTreeNode *p = tree;
	qu.push(p);
	int last = 1;
	int max = 0;
	int buf = 0;
	while (!qu.empty())
	{
		buf = 0;
		while (last-- != 0)
		{
			p = qu.front();
			qu.pop();
			if (p->llink)
			{
				qu.push(p->llink);
				buf++;
			}
			if (p->rlink)
			{
				qu.push(p->rlink);
				buf++;
			}
		}
		
		if (buf > max)
		{
			max = buf;
		}
		last = buf;
		depth++;
	}
	width = max;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	int depth=0, width=0;
	depth_width(tree, depth, width);
	cout << depth << ' ' << width << endl;
	destroyTree(&tree);
	return 0;
}
*/
/**********和为S的两个数字（数组是排序的）**********
#include<iostream>
using namespace std;
void fun(int *a, int n, int sum, int *x, int *y)
{
	if (a == NULL || n <= 0)
	{
		return;
	}
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		if (a[begin] + a[end] == sum)
		{
			*x = a[begin];
			*y = a[end];
			break;
		}
		else if (a[begin] + a[end] < sum)
		{
			begin++;
		}
		else
		{
			end--;
		}
	}

}
int main()
{
	int a[] = {1,2,4,7,11,15};
	int x=0, y=0;
	fun(a, 6, 15, &x, &y);
	cout << x << ' ' << y << endl;
	return 0;
}
*/
/****和为s的两个数字（不是排序的）
#include<iostream>
using namespace std;
void fun(int *a, int n, int sum, int *x, int *y)
{
	if (a == NULL || n <= 0)
	{
		return;
	}
	int *b = new int[sum + 1];
	for (int i = 0; i <= sum; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (b[sum - a[i]])
		{
			*x = a[i];
			*y = sum - a[i];
			break;
		}
		if (a[i] <= sum)
		{
			b[a[i]] = 1;
		}
		
	}
	delete[]b;
}
int main()
{
	int a[] = { 7,15, 4, 2, 11, 1 };
	int x = 0, y = 0;
	fun(a, 6, 15, &x, &y);
	cout << x << ' ' << y << endl;
	return 0;
}
*/
/*******************************
#include<iostream>
using namespace std;
void print(int begin, int end)
{
	if (begin > end)
	{
		return;
	}
	for (int i = begin; i <= end; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
}
void fun(int sum)
{
	if (sum < 3)
	{
		return;
	}
	int begin = 1;
	int end = begin+1;
	while (begin <= sum / 2)
	{
		int buf = begin;
		while ((buf += end) <= sum)
		{
			if (buf == sum)
			{
				print(begin, end);
			}
			end++;
		}
		begin++;
		end = begin + 1;
	}
}
int main()
{
	int sum;
	while (cin >> sum)
	{
		fun(sum);
	}
	return 0;
}
*/
/*******
#include<iostream>
using namespace std;
void Reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
	{
		return;
	}
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
bool isAlph(char c)
{
	return (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z');
}
void fun(char *str)
{
	if (str == NULL)
	{
		return;
	}
	char *tail = str;
	while (*tail != '\0')
	{
		tail++;
	}
	Reverse(str, tail - 1);
	char *begin = str;
	while (*begin != '\0')
	{
		while (!isAlph(*begin))
		{
			begin++;
		}
		char *end = begin;
		while (isAlph(*end))
		{
			end++;
		}
		Reverse(begin, end - 1);
		begin = end;
	}
}
int main()
{
	char str[100];
	gets_s(str);
	fun(str);
	cout << str << endl;
	return 0;
}
*/
/*****************
#include<iostream>
using namespace std;
class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}
	static void reset()
	{
		N = 0;
		Sum = 0;
	}
	static int getSum()
	{
		return Sum;
	}

private:
	static int N;
	static int Sum;
};
int Temp::N = 0;
int Temp::Sum = 0;
int fun(int n)
{
	Temp::reset();
	Temp *p = new Temp[n];
	delete[]p;
	return Temp::getSum();
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << fun(n) << endl;
	}
	return 0;
}
*/
/*************
#include<iostream>
using namespace std;
class sealed
{
public:
	static sealed *getinstance(int i)
	{
		return new sealed(i);
	}
	static void deleteinstance(sealed *pInstance)
	{
		delete pInstance;
	}
	int &getA()
	{
		return a;
	}
	void print()
	{
		cout << a << endl;
	}
private:
	int a;
	sealed(int i = 0) :a(i){}
	~sealed(){}
};
int main()
{
	sealed *p = sealed::getinstance(1);
	p->getA() = 2;
	p->print();
	sealed::deleteinstance(p);
	return 0;
}
*/
/**************
#include<iostream>
#include<vector>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
bool printPath(BinTreeNode *root, int data)
{
	if (root == NULL)
		return false;

	if (root->info == data || printPath(root->llink,data) || printPath(root->rlink,data))
	{
		cout << root->info<<' ';   //路径上的结点标识打印出来
		return true;
	}

	return false;
}
void printPath0(BinTreeNode *root, int data)
{
	if (root == NULL)
	{
		return;
	}
	vector<BinTreeNode*> vec;
	BinTreeNode *p = root;
	BinTreeNode *pp=NULL;
	while (p || !vec.empty())
	{
		while (p)
		{
			vec.push_back(p);
			pp = p->rlink;
			p = p->llink;
			if (p==NULL)
			{
				p = pp;
			}
		}
		p = vec.back();
		if (p->info == data)
		{
			for (vector<BinTreeNode*>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
			{
				cout << (*iter)->info << ' ';
			}
			cout << endl;
			break;
		}
		vec.pop_back();
		if (!vec.empty() && vec.back()->llink == p)
		{
			p = vec.back()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	int x;
	cin.clear();
	while (cin >> x)
	{
		printPath0(tree, x);
	}
	destroyTree(&tree);
	return 0;
}
*/
/****
#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct TreeNode
{
	int info;
	vector<TreeNode*> m_vChildren;

};
bool GetNodePath(TreeNode *pRoot, TreeNode *pNode, list<TreeNode*> &path)
{
	if (pRoot == pNode)
	{
		return true;
	}
	path.push_back(pRoot);
	bool found = false;
	vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
	while (!found&&iter != pRoot->m_vChildren.end())
	{
		found = GetNodePath(*iter, pNode, path);
		++iter;
	}
	if (!found)
	{
		path.pop_back();
	}
	return found;
}
TreeNode *GetLastCommonNode(const list<TreeNode*> &path1, const list<TreeNode*> &path2)
{
	list<TreeNode*>::const_iterator iter1 = path1.begin();
	list<TreeNode*>::const_iterator iter2 = path2.begin();
	TreeNode *pLast = NULL;
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
		{
			pLast = *iter1;
		}
		iter1++;
		iter2++;
	}
	return pLast;
}
TreeNode *GetLastCommonParent(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2)
{
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
	{
		return NULL;
	}
	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);
	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);
	return GetLastCommonNode(path1, path2);
}
int main()
{
	return 0;
}
*/
/********dijkstra算法****************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 10000000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int len;
	int vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和变数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete []G.arcs[i];
	}
	delete []G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GraphMatrix &G, path *dist)
{
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vexEnd = -1;
		}
		else
		{
			dist[i].vexEnd = 0;
		}
	}
	flag[0] = 1;
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && minw>dist[j].len)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		flag[min] = 1;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len>G.arcs[min][j] + dist[min].len)
			{
				dist[j].len = G.arcs[min][j] + dist[min].len;
				dist[j].vexEnd = min;
			}
		}
	}
}
void showPath(const path *dist, int v)
{
	if (dist[v].len == MAX)
	{
		cout << "no path to v" << endl;
		return;
	}
	stack<int> st;
	while (v)
	{
		st.push(v);
		v = dist[v].vexEnd;
	}
	cout << v << "->";
	while (!st.empty())
	{
		if (st.size() == 1)
		{
			cout << st.top() << endl;
		}
		else
		{
			cout << st.top() << "->";
		}
		st.pop();
	}
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path *dist = new path[G.vexNum];
	dijkstra(G, dist);
	for (int i = 1; i < G.vexNum; i++)
	{
		cout << dist[i].len << '\t';
		showPath(dist, i);
	}
	delete[]dist;
	destroyGraph(G);
	return 0;
}
*/
/********Floyd算法*********
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 10000000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和变数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vexEnd[i][j] = -1;
			}
			else
			{
				dist.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vexEnd[i][j] = dist.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		cout << "no path from " << v0 << " to " << v1 << endl;
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << "->";
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}
	Floyd(G, dist);
	int v0, v1;
	cin.clear();
	while (cin >> v0 >> v1)
	{
		if (v0 < 0 || v0 >= G.vexNum || v1 < 0 || v1 >= G.vexNum)
		{
			cout << "输入有误" << endl;
			continue;
		}
		if (dist.len[v0][v1] != MAX)
		{
			cout << dist.len[v0][v1] << '\t';
		}
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	destroyGraph(G);
	return 0;
}
*/
/********prim最小生成树*************
#include<iostream>
#include<stack>
using namespace std;
const int MAX = 10000000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	cout << "请输入顶点数和变数：" << endl;
	cin >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入各边的具体信息" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		cin >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
		G.arcs[v1][v0] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void prim(const GraphMatrix &G)
{
	int *start = new int[G.vexNum];
	int *lowCost = new int[G.vexNum];

	for (int i = 0; i < G.vexNum; i++)
	{
		start[i] = 0;
		lowCost[i] = G.arcs[0][i];
	}
	int minw;
	int min;
	for (int i = 1; i < G.vexNum; i++)
	{
		minw = MAX;
		min = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (lowCost[j] != 0 && lowCost[j] < minw)
			{
				minw = lowCost[j];
				min = j;
			}
		}
		cout << start[min] << "->" << min << ' ' << minw << endl;
		lowCost[min] = 0;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (lowCost[j] != 0 && lowCost[j]>G.arcs[min][j])
			{
				lowCost[j] = G.arcs[min][j];
				start[j] = min;
			}
		}
	}
	delete[]lowCost;
	delete[]start;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	prim(G);
	destroyGraph(G);
	return 0;
}
*/
/****************
#include<iostream>
using namespace std;
class A
{
public:
	static int s;
	A() :a(s++){}
	void print()
	{
		cout << a << endl;
	}
protected:
	int a;
};
int A::s = 0;
class B:public A
{
public:
	B() :b(s++){}
	void print()
	{
		cout << a << endl;
		cout << b << endl;
		obj.print();
	}
private:
	A obj;
	int b;
	
};
int main()
{
	B obj;
	obj.print();
	return 0;
}
*/
/***********************
#include<iostream>
using namespace std;
class sealed
{
public:
	static sealed *getInstance(int i)
	{
		return new sealed(i);
	}
	static void deleteInstance(sealed *p)
	{
		delete p;
	}
	void print()
	{
		cout << a << endl;
	}
	int &getA()
	{
		return a;
	}
private:
	int a;
	sealed(int i) : a(i){}
	~sealed(){}
};
int main()
{
	sealed *pobj = sealed::getInstance(2);
	pobj->print();
	sealed::deleteInstance(pobj);
	return 0;
}
*/
/******************
#include<iostream>
using namespace std;
struct ListNode
{
	int info;
	ListNode *next;
};
void createList(ListNode **pList)
{
	if (pList == NULL || *pList != NULL)
	{
		return;
	}
	int x;
	cin >> x;
	*pList = new ListNode;
	(*pList)->info = x;
	(*pList)->next = NULL;
	ListNode *p = *pList;
	while (cin >> x)
	{
		ListNode *newNode = new ListNode;
		newNode->info = x;
		newNode->next = NULL;
		p->next = newNode;
		p = newNode;
	}
}
void destroyList(ListNode **pList)
{
	if (pList == NULL || *pList == NULL)
	{
		return;
	}
	ListNode *p = *pList;
	ListNode *q = NULL;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	*pList = NULL;
}
ListNode *reverseList(ListNode *list,ListNode **pLast)
{
	if (list == NULL)
	{
		return NULL;
	}
	ListNode *next = list->next;
	list->next = *pLast;
	*pLast = list;
	return next == NULL ? list : reverseList(next, pLast);
}
void print(ListNode *list)
{
	while (list)
	{
		cout << list->info << ' ';
		list = list->next;
	}
	cout << endl;
}
int main()
{
	ListNode *list = NULL;
	createList(&list);
	ListNode *last = NULL;
	list = reverseList(list, &last);
	print(list);
	destroyList(&list);
	return 0;
}
*/
/*****************
#include<iostream>
using namespace std;
int main()
{
	static int i;
	cout << i << endl;
	return 0;
}
*/
/**
#include<iostream>
using namespace std;
struct A
{
	char t : 4;
	char k : 4;
	unsigned short i : 8;
	unsigned long m;
};
int main()
{

	cout << sizeof(unsigned long) << endl;
	cout << sizeof(A) << endl;
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
class A
{
public:
	virtual void fun()
	{
		cout << "fun in A" << endl;
	}
};
class B :public A
{
public:
	void fun()
	{
		cout << "fun in B" << endl;
	}
};
void test(A &obj) //传引用或指针才能实现多态
{
	obj.fun();
}
int main()
{
	B obj;
	test(obj);
	return 0;
}
*/
/******
#include<iostream>
using namespace std;
bool isLittleEnd()
{
	unsigned short i = 0x1122;
	unsigned char *pc = (unsigned char*)&i;
	return *pc == 0x22;
}
int main()
{
	cout << sizeof(unsigned short) << endl;
	cout << isLittleEnd() << endl;
	return 0;
}
*/
/***************
#include<iostream>
using namespace std;
void fun(int i)
{
	
	cout << i % 10;
	i /= 10;
	if (i == 0)
	{
		return;
	}
	fun(i);
}
int main()
{
	int x;
	while (cin >> x)
	{
		fun(x);
		cout << endl;
	}
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
class A
{
public:
	void fun()
	{
		cout << "fun" << endl;
	}
	void fun() const
	{
		cout << "fun const" << endl;
	}
	static void test()
	{
		cout << a << endl;
	}
private:
	static int a;
};
int main()
{
	const A obj;
	obj.fun();
	return 0;
}
*/
/***********
#include<iostream>
using namespace std;
class A
{
public:
	A(int i) :a(i){}
	void fun1()
	{
		cout << "huang huahua" << endl;
	}
	void fun2()
	{
		cout << a << endl;
	}
private:
	int a;
};
int main()
{
	A *p = NULL;
	p->fun1();   //正常运行
	p->fun2();   //程序奔溃，this=NULL;
	return 0;
}
*/
/********
#include<iostream>
using namespace std;
struct type
{
	int x;
	int y;
	int z;
};
int main()
{
	type *p = NULL;
	int i = (int)&p->z;
	cout << i << endl;
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
class A
{
public:
	virtual void fun(int i = 10)
	{
		cout << "A" <<i<< endl;
	}

};
class B :public A
{
public:
	void fun(int i = 20)
	{
		cout << "B" <<i<< endl;
	}
};
int main()
{
	B obj;
	A *obj0 = &obj;
	obj0->fun();
	return 0;
}
*/
/**
#include<iostream>
#include<set>
using namespace std;
void fun(int *a, int n, multiset<int> &ints, int k)
{
	if (a == NULL || n < 1 || k < 1)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (ints.size() < k)
		{
			ints.insert(a[i]);
		}
		else
		{
			if (a[i]>*ints.begin())
			{
				ints.erase(ints.begin());
				ints.insert(a[i]);
			}
		}
	}
}
int main()
{
	int a[] = { 5, 7, 9, 2, 11, 2, 8, 4, 5, 6, 22 };
	multiset<int> iset;

	fun(a, 11, iset, 3);
	for (multiset<int>::iterator iter = iset.begin(); iter != iset.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
}
*/
/***********
#include <iostream>
using namespace std;
template<typename T>
class Heap
{
public:
	//默认构造函数
	Heap() :m_array(0), m_size(0), m_lenght(0) {}
	//分配length长度的数组
	Heap(int length);
	//析构函数
	~Heap()
	{
		delete[] m_array;
	}
	//插入一个数据项
	bool insert(T item);
	//判断是否为空
	bool empty();
	//获得最大的数据，但不删除
	T fetchMax();
	//删除最大的数据也就是数组的第一个数据项
	void deleteMax();
	//显示堆的内容 
	void display();
	//把一个类型T的数组转化成一个堆
	void array_heapSort(T* array, int size);
	//对堆进行堆排序
	//precondition:堆已经存在
	void heapSort();

private:
	//下调，把[star,end]区间的二叉树进行堆化
	void locate_down(int start, int end);
	//上调，把[star,end]区间的二叉树进行堆化
	void locate_up(int start, int end);

private:
	T* m_array;      //指向一个数组的指针
	int m_size;       //已经存放了数据的个数
	int m_lenght;    //分配的空间的长度

};
template<typename T>
Heap<T>::Heap(int length)
{
	m_array = new T[length + 1];
	m_size = 0;
	m_lenght = length;
}
template<typename T>
T Heap<T>::fetchMax()
{
	return m_array[1];
}

template<typename T>
bool Heap<T>::empty()
{
	return m_size == 0;
}
template<typename T>
void Heap<T>::locate_down(int start, int end)
{
	int c = start * 2;
	int temp;
	while (c <= end)
	{
		if (c<end && m_array[c]<m_array[c + 1])
			c = c + 1;
		if (m_array[start]<m_array[c])
		{
			temp = m_array[start];
			m_array[start] = m_array[c];
			m_array[c] = temp;
		}
		start = c;
		c = 2 * c;
	}
}
template<typename T>
void Heap<T>::deleteMax()
{
	m_array[1] = m_array[m_size];   //尾覆盖首
	--m_size;                                        //长度减一
	locate_down(1, m_size);                 //下调，保证堆结构
}
template<typename T>
void Heap<T>::locate_up(int start, int end)
{
	int loc = end;
	int parent = end / 2;
	int temp;
	while (parent >= start && m_array[loc] >m_array[parent])
	{
		temp = m_array[loc];
		m_array[loc] = m_array[parent];
		m_array[parent] = temp;
		loc = parent;
		parent = loc / 2;
	}
}
template<typename T>
bool Heap<T>::insert(T item)
{
	if (m_size>m_lenght)      //判断是否已满
	{
		std::cerr << "the heap has FULL/n";
		this->~Heap();
		return 0;
	}
	++m_size;                      //从m_array[ 1 ]开始放数据,所以先进行++m_size
	m_array[m_size] = item;

	locate_up(1, m_size);                 //上调保证堆结构
	return 1;

}
template<typename T>
void Heap<T>::display()
{
	int i = 1;
	while (i <= m_size)
	{
		std::cout << m_array[i] << "  ";
		++i;
	}
	std::cout << std::endl;
}
template<typename T>
void Heap<T>::array_heapSort(T* array, int size)   //array[  ]从array[ 0 ]开始存放数据
{
	int i;
	m_lenght = size;
	m_array = new T[m_lenght + 1];
	for (i = 1; i <= size; ++i)
		this->insert(array[i - 1]);
	this->heapSort();
	//write to the original array
	for (i = 1; i <= m_size; ++i)
		array[i - 1] = m_array[i];
}
template<typename T>
void Heap<T>::heapSort()
{
	int i, temp;
	for (i = m_size; i >= 2; --i)
	{
		temp = m_array[1];
		m_array[1] = m_array[i];
		m_array[i] = temp;

		locate_down(1, i - 1);    //locate_down() 会把1~i-1里面的数据排成堆

	}
}
int main()
{
	int i;
	Heap<int> one(6);
	for (i = 0; i<6; ++i)
		one.insert(i + 1);
	cout << "构建的堆为:\n";
	one.display();
	cout << "进行堆排序以后为：\n";
	one.heapSort();
	one.display();
	cout << "下面是对一个数组进行堆排序：\n";
	int a[] = { 7, 9, 8, 6, 10, 11 };
	cout << "待排序的数组为:\n";
	for (i = 0; i<6; ++i)
		cout << a[i] << " ";
	cout << endl;
	cout << "进行堆排序以后为:\n";
	Heap<int> two;
	two.array_heapSort(a, 6);
	for (i = 0; i<6; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
*/
/*****
#include<iostream>
using namespace std;
struct bs
{
	int a : 8; 
	int b : 2; 
	int c : 6;
};

int main()
{
	cout << sizeof(bs) << endl;
	return 0;
}
*/
/***********
#include<iostream>
using namespace std;
char *my_strcpy(char *dst, const char *src)
{
	if (dst == NULL || src == NULL)
	{
		return NULL;
	}
	char *ret = dst;
	while ((*dst++ = *src++) != '\0');
	return ret;
}
int main()
{
	char str[10] = "abc";
	my_strcpy(str + 1, str);
	cout << str << endl;
	return 0;
}
*/
/************打印二叉树每个叶子节点的路径**************************
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void fun(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	vector<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push_back(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.back();
		st.pop_back();
		if (p->llink == NULL&&p->rlink == NULL)
		{
			for (vector<BinTreeNode*>::iterator iter = st.begin(); iter != st.end(); ++iter)
			{
				cout << (*iter)->info << ' ';
			}
			cout << p->info << endl;
		}
		if (!st.empty() && st.back()->llink == p)
		{
			p = st.back()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	fun(tree);
	destroyTree(&tree);
	return 0;
}
*/
/*******字符串哈希******
#include<iostream>
using namespace std;
int ELFhash(char *key)
{
	unsigned long h = 0;
	unsigned long x = 0;

	while (*key)
	{
		h = (h << 4) + (*key++);  //h左移4位，当前字符ASCII存入h的低四位
		if ((x = h & 0xF0000000L) != 0)
		{ //如果最高位不为0，则说明字符多余7个，如果不处理，再加第九个字符时，第一个字符会被移出
			//因此要有如下处理
			h ^= (x >> 24);
			//清空28~31位
			h &= ~x;
		}
	}
	return h % 100;
}
int main()
{
	return 0;
}
*/
/*************
#include<iostream>
using namespace std;
int ELFhash(char *str)
{
	unsigned long h = 0;
	unsigned long x = 0;
	while (*str)
	{
		h = (h << 4) + (*str++);
		if ((x = h & 0xF0000000L) != 0)
		{
			h ^= (x >> 24);
			h &= (~x);
		}
	}
	return h % 1000;
}
int main()
{
	return 0;
}
*/
/*************************
#include<iostream>
using namespace std;
int merge(int *a, int *b, int low, int m, int high)
{
	int i = low;
	int j = m + 1;
	int k = low;
	int result = 0;
	while (i <= m&&j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
			result += (m - i + 1);
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
	return result;
}
int mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	int result = 0;
	while (i + 2 * length - 1 < n)
	{
		result += merge(a, b, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		result += merge(a, b, i, i + length - 1, n - 1);
	}
	for (int j = i; j < n; j++)
	{
		b[j] = a[j];
	}
	return result;
}
int mergeSort(int *a, int n)
{
	int *b = new int[n];
	int length = 1;
	int result = 0;
	while (length < n)
	{
		result+=mergePass(a, b, n, length);
		length *= 2;
		result+=mergePass(b, a, n, length);
		length *= 2;
	}
	delete[]b;
	return result;
}
int fun(int *a, int n)
{
	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				result++;
			}
		}
	}
	return result;
}
int main()
{
	int a[] = { 5, 3, 8, 10, 16, 2, 4, 9, 19, 13, 15, 1, 6, 11, 7, 12, 14, 20, 17, 18 };
	cout << fun(a, 20) << endl;
	cout << mergeSort(a, 20) << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/********
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	inOrder(tree);
	postOrder(tree);
	destroyTree(&tree);
	return 0;
}
*/
/****
#include<iostream>
using namespace std;
void merge(int *a, int *b, int low, int m, int high)
{
	int i = low;
	int j = m + 1;
	int k = low;
	while (i <= m&&j <= high)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
}
void mergePass(int *a, int *b, int n, int length)
{
	int i = 0;
	while (i + 2 * length - 1 < n)
	{
		merge(a, b, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n)
	{
		merge(a, b, i, i + length - 1, n - 1);
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			b[j] = a[j];
		}
	}
}
void mergeSort(int *a, int n)
{
	if (a == NULL || n <= 1)
	{
		return;
	}
	int *b = new int[n];
	int length = 1;
	while (length < n)
	{
		mergePass(a, b, n, length);
		length *= 2;
		mergePass(b, a, n, length);
		length *= 2;
	}
	delete[]b;
}
int main()
{
	int a[] = {6,5,10,17,2,7,9,11,1,4,3,19,20,12,13,16,14,15,8,18};
	mergeSort(a, 20);
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
*/
/********
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int temp;
	cin >> temp;
	if (temp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = temp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << ' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << ' ';
	inOrder(tree->rlink);
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << ' ';
}
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		p = p->rlink;
	}
	cout << endl;
}
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << ' ';
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);

	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);
	destroyTree(&tree);
	return 0;
}
*/
/****
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GroupMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int len;
	int vexEnd;
};
void createGroup(GroupMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	ifstream input("huang1.txt");
	cout << "请输入顶点数和边数：" << endl;
	input >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入个边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		input >> v0>>v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGroup(GroupMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void dijkstra(const GroupMatrix &G, path *dist)
{
	int *flag = new int[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		flag[i] = 0;
	}
	flag[0] = 1;
	for (int i = 0; i < G.vexNum; i++)
	{
		dist[i].len = G.arcs[0][i];
		if (dist[i].len == MAX)
		{
			dist[i].vexEnd = -1;
		}
		else
		{
			dist[i].vexEnd = 0;
		}
	}
	int min, minw;
	for (int i = 1; i < G.vexNum; i++)
	{
		min = 0;
		minw = MAX;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && minw > dist[j].len)
			{
				minw = dist[j].len;
				min = j;
			}
		}
		flag[min] = 1;
		for (int j = 1; j < G.vexNum; j++)
		{
			if (flag[j] == 0 && dist[j].len>dist[min].len + G.arcs[min][j])
			{
				dist[j].len = dist[min].len + G.arcs[min][j];
				dist[j].vexEnd = min;
			}
		}
	}
}
void showPath(const path *dist, int v)
{
	if (dist[v].len == MAX)
	{
		cout << "no path to " << v << endl;
	}
	stack<int> st;
	while (v != 0)
	{
		st.push(v);
		v = dist[v].vexEnd;
	}
	cout << 0 << "->";
	while (!st.empty())
	{
		if (st.size() == 1)
		{
			cout << st.top() << endl;
		}
		else
		{
			cout << st.top() << "->";
		}
		st.pop();
	}
}
int main()
{
	GroupMatrix G;
	G.arcs = NULL;
	createGroup(G);
	path *dist = new path[G.vexNum];
	dijkstra(G, dist);
	for (int i = 1; i < G.vexNum; i++)
	{
		showPath(dist, i);
	}
	delete[]dist;
	destroyGroup(G);
	return 0;
}
*/
/*****
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
const int MAX = 100000;
struct GraphMatrix
{
	int vexNum;
	int edgeNum;
	int **arcs;
};
struct path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if (G.arcs != NULL)
	{
		return;
	}
	ifstream input("huang1.txt");
	cout << "请输入顶点数和边数：" << endl;
	input >> G.vexNum >> G.edgeNum;
	G.arcs = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		G.arcs[i] = new int[G.vexNum];
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			if (i == j)
			{
				G.arcs[i][j] = 0;
			}
			else
			{
				G.arcs[i][j] = MAX;
			}
		}
	}
	cout << "请输入个边的具体信息（v0,v1,w）：" << endl;
	int v0, v1, w;
	for (int i = 0; i < G.edgeNum; i++)
	{
		input >> v0 >> v1 >> w;
		G.arcs[v0][v1] = w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if (G.arcs == NULL)
	{
		return;
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
	G.arcs = NULL;
}
void Floyd(const GraphMatrix &G, path &dist)
{
	for (int i = 0; i < G.vexNum; i++)
	{
		for (int j = 0; j < G.vexNum; j++)
		{
			dist.len[i][j] = G.arcs[i][j];
			if (dist.len[i][j] == MAX)
			{
				dist.vexEnd[i][j] = -1;
			}
			else
			{
				dist.vexEnd[i][j] = j;
			}
		}
	}
	for (int k = 0; k < G.vexNum; k++)
	{
		for (int i = 0; i < G.vexNum; i++)
		{
			for (int j = 0; j < G.vexNum; j++)
			{
				if (dist.len[i][j]>dist.len[i][k] + dist.len[k][j])
				{
					dist.len[i][j] = dist.len[i][k] + dist.len[k][j];
					dist.vexEnd[i][j] = dist.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(const path &dist, int v0, int v1)
{
	if (dist.len[v0][v1] == MAX)
	{
		cout << "no path from " << v0 << " to " << v1 << endl;
		return;
	}
	while (v0 != v1)
	{
		cout << v0 << "->";
		v0 = dist.vexEnd[v0][v1];
	}
	cout << v0 << endl;
}
int main()
{
	GraphMatrix G;
	G.arcs = NULL;
	createGraph(G);
	path dist;
	dist.len = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.len[i] = new int[G.vexNum];
	}
	dist.vexEnd = new int*[G.vexNum];
	for (int i = 0; i < G.vexNum; i++)
	{
		dist.vexEnd[i] = new int[G.vexNum];
	}

	Floyd(G, dist);
	int v0, v1;
	while (cin >> v0 >> v1)
	{
		showPath(dist, v0, v1);
	}
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.vexEnd[i];
	}
	delete[]dist.vexEnd;
	for (int i = 0; i < G.vexNum; i++)
	{
		delete[]dist.len[i];
	}
	delete[]dist.len;
	destroyGraph(G);
	return 0;
}
*/
/****
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << ' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	nPreOrder(tree);
	destroyTree(&tree);
	return 0;
}
*/
/**
#include<iostream>
#include<cmath>
using namespace std;
double x[3];
double a, b, c, d, u, v;
int i, t;
double f(double x)
{
	double temp;
	temp = ((a*x + b)*x + c)*x + d;
	return temp;
}
int main()
{
	while (cin >> a >> b >> c >> d)
	{
		t = 0;
		for (i = -100; i <= 100; i++)
		{
			u = double(i);
			v = u + 0.99999;
			if (fabs(f(u))<0.00001 || f(u)*f(v) <= 0)
			{
				
				if (fabs(f(u))<0.00001)
					x[t++] = u;
				else
				{
					while ((u + 0.001<v) && fabs(f((u + v) / 2)) >= 0.00001)

					{
						if (f(u)*f((u + v) / 2)<0)
							v = (u + v) / 2;
						else
							u = (u + v) / 2;
					}
					x[t] = (u + v) / 2;
				}
			}
		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
	}

	return 0;
}
*/
/*****
#include<iostream>
#include<cmath>
using namespace std;
double a, b, c, d;
double u, v;
double x[3];
double f(double x)
{
	return x*(x*(a*x + b) + c) + d;
}
int main()
{
	while (cin >> a >> b >> c >> d)
	{
		int t = 0;
		for (int i = -100; i <= 100; i++)
		{
			u = double(i);
			v = u + 0.9999;
			if (fabs(f(u)) <= 0.00001 || f(u)*f(v) < 0)
			{
				if (fabs(f(u)) < 0.00001)
				{
					x[t++] = u;
				}
				else
				{
					while (u + 0.001<v&&fabs(f((u + v) / 2))>=0.00001)
					{
						if (f(u)*f((u + v) / 2) < 0)
						{
							v = (u + v) / 2;
						}
						else
						{
							u = (u + v) / 2;
						}
					}
					x[t] = (u + v) / 2;
				}
			}
		}
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
	}
	
	return 0;
}
*/
/*
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink, *rlink;
};
void createTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree != NULL)
	{
		return;
	}
	int tmp;
	cin >> tmp;
	if (tmp == 0)
	{
		return;
	}
	*ptree = new BinTreeNode;
	(*ptree)->info = tmp;
	(*ptree)->llink = (*ptree)->rlink = NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if (ptree == NULL || *ptree == NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree = NULL;
}
void preOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout << tree->info << " ";
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout << tree->info << " ";
	inOrder(tree->rlink);
}
void postOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout << tree->info << " ";
}
void nPreOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	st.push(p);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		if (p)
		{
			cout << p->info << " ";
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout << endl;
}
void nInOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->llink;
		}
		p = st.top();
		st.pop();
		cout << p->info << " ";
		p = p->rlink;
	}
	cout << endl;
}
void nPostOrder(BinTreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p = tree;
	BinTreeNode *pp = NULL;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			pp = p->rlink;
			p = p->llink;
			if (p == NULL)
			{
				p = pp;
			}
		}
		p = st.top();
		st.pop();
		cout << p->info << " ";
		if (!st.empty() && st.top()->llink == p)
		{
			p = st.top()->rlink;
		}
		else
		{
			p = NULL;
		}
	}
	cout << endl;
}
int main()
{
	BinTreeNode *tree = NULL;
	createTree(&tree);
	preOrder(tree);
	cout << endl;
	nPreOrder(tree);
	
	inOrder(tree);
	cout << endl;
	nInOrder(tree);

	postOrder(tree);
	cout << endl;
	nPostOrder(tree);

	destroyTree(&tree);
}
*/
