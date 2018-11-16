#include<iostream>
using namespace std;
void *strcpy(void *dest,void *src,int n)
{
	if(dest==NULL||src==NULL||n<1)
		return NULL;
	char *pdest=(char*)dest;
	char *psrc=(char*)src;
	if(pdest>psrc&&pdest<psrc+n)
	{
		for(int i=n-1;i>=0;i--)
			pdest[i]=psrc[i];
	}
	else
	{
		for(int i=0;i<n;i++)
			pdest[i]=psrc[i];
	}
	return pdest;
}
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T&);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};
template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	t=-1;
}
template<typename T>
stack<T>::~stack()
{
	if(data!=NULL)
		delete[]data;
}
template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}
template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}
template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		strcpy(buf,data,M*sizeof(T));
		T *tmp=buf;
		buf=data;
		data=tmp;
		M*=2;
		delete[]buf;
	}
	data[++t]=obj;
}
template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}
template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}
/*
int result=0;
int &getIndex(void)
{
	return result;
}
int main()
{
	int count=0;
	const int &refCount=count;
	//refCount++;
	count++;
	cout<<count<<endl;
	getIndex()=5;
	cout<<result<<endl;
	return 0;
}
*/



/*
class Tdate{
	public:
		void set(int m,int d,int y)
		{
			month=m;
			day=d;
			year=y;
		}
		int isLeapYear()
		{
			return((year%4==0&&year%100!=0)||year%400==0);
		}
		void print()
		{
			cout<<year<<'-'<<month<<'-'<<day<<endl;
		}
	private:
		int month;
		int day;
		int year;
};
struct {
	int a;
	int b;
} test;
int main()
{
	Tdate a;
	a.set(2,4,1998);
	a.print();
	cout<<a.isLeapYear()<<endl;
	cout<<test.a<<' '<<test.b<<endl;
	return 0;
}
*/



/*
class Location
{
	public:
		Location(int xx,int yy);
		~Location();
		int GetX();
		int GetY();
	private:
		int X,Y;
};
Location::Location(int xx,int yy)
{
	X=xx;
	Y=yy;
	cout<<"Constructor called"<<endl;
}
Location::~Location()
{
	cout<<"Destructor called"<<endl;
}
int Location::GetX()
{
	return X;
}
int Location::GetY()
{
	return Y;
}
int main()
{
	Location A(10,20);
	cout<<A.GetX()<<","<<A.GetY()<<endl;
	return 0;
}
*/



/*
class X
{
	public:
		X(){}
		X(int i=0){x=i;}
	private:
		int x;
};
int main()
{
	X one(10);
	//X two;                    //二义性
	return 0;
}
*/



/*
class Tdate
{
	public:
		Tdate();
		Tdate(int d);
		Tdate(int d,int m);
		Tdate(int d,int m,int y);
	protected:
		int month;
		int day;
		int year;
};
Tdate::Tdate()
{
	month=10;
	day=1;
	year=2000;
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
Tdate::Tdate(int d)
{
	month=10;
	day=d;
	year=2000;
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
Tdate::Tdate(int d,int m)
{
	month=m;
	day=d;
	year=2000;
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
Tdate::Tdate(int d,int m,int y)
{
	month=m;
	day=d;
	year=y;
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
int main()
{
	Tdate aday;
	Tdate bday(5);
	Tdate cday(2,12);
	Tdate dday(1,2,1998);
	return 0;
}
*/



/*
class A
{
	public:
		A(int i)
		{
			a=i;
		}
		A(const A &obj)
		{
			a=obj.a+2;
		}
		int getA()
		{
			return a;
		}
		int setA(int i)
		{
			a=i;
		}
		
	private:
	int a;
};
int main()
{
	A obj(1);
	cout<<obj.getA()<<endl;
	obj.setA(5);
	cout<<obj.getA()<<endl;
	A obj1(obj);
	cout<<obj1.getA()<<endl;
	A obj2=obj;
	cout<<obj2.getA()<<endl;
	return 0;
}
*/



/*
class A
{
	public:
		A(char *c)
		{
			a=c;
			a[0]='g';  
//指向常量的指针赋值给指向非常量的指针，警告，当修改数据时，编译通过但运行出错
		}
		void print()
		{	
			cout<<a<<endl;
		}
	private:
		char *a;
};
int main()
{
	A obj("huang");
	obj.print();
	return 0;
}
*/


/*
int main()
{
	const char *p="huang";
	return 0;
}
*/

/*
int main()
{
	int i=0;
	int j=1;
	int &ref=i;
	ref=j;
}
*/





/*
class A
{
	public:
		A(int &i):ten(10),ref(i)
		{
			//ref=i;
		}
		void print()
		{
			cout<<"ten="<<ten<<endl;
			cout<<"ref="<<ref<<endl;
		}
	protected:
		const int ten;
		int &ref;
};

int main()
{
	int i=0;
	A obj(i);
	obj.print();
	i=5;
	obj.print();
	return 0;
}
*/

/*
class A
{
	public:
		A(double &i):a(i){}
	private:
		double &a;
};
int main()
{
	double i=0;
	A obj(i);
	cout<<sizeof(obj)<<endl;
	return 0;
}
*/

/*
class A
{
	public:
		A()
		{
			cout<<"A()"<<endl;
		}
		virtual ~A()
		{
			cout<<"~A()"<<endl;
		}
	private:
		int a;
};
class B:public A
{
	public:
		B()
		{
			cout<<"B()"<<endl;
		}
		~B()
		{
			cout<<"~B()"<<endl;
		}
	private:	
		int b;
};
int main()
{
	A *p=new B;
	delete p;
	return 0;
}
*/



/*
class A
{
	public:
		static int s;
	private:
		int a;
};
int A::s=1;
int main()
{
	A obj;
	cout<<sizeof(obj)<<endl;
	return 0;
}
*/


/*
class X
{
	public:
		static void func(int i,X *ptr);
	private:
		int member;
};
void X::func(int i,X *ptr)
{
	ptr->member=i;
	cout<<ptr->member<<endl;
}

int main()
{
	X obj;
	X::func(1,&obj);
	obj.func(1,&obj);
	return 0;
}
*/




/*
class Location
{
	public:
		int set(int x,int y);
		~Location()
		{
			cout<<"Destructor called:"<<X<<","<<Y<<endl;
		}
	private:
		int X,Y;
};
int Location::set(int x,int y)
{
	X=x;
	Y=y;
	cout<<"Constructor :"<<X<<","<<Y<<endl;
	return 0;
}
int main()
{
	Location *ptr;
	ptr=new Location[2];
	ptr[0].set(5,10);
	ptr[1].set(15,20);
	cout<<"Deleting..."<<endl;
	delete []ptr;
}
*/




/*
class Location
{
	public:
		Location(int xx=0,int yy=0)
		{
			X=xx;
			Y=yy;
		}
		Location(const Location &p);
		int GetX()
		{
			return X;
		}
		int GetY()
		{
			return Y;
		}
	private:
		int X;
		int Y;
};
Location::Location(const Location &p)
{
	X=p.X;
	Y=p.Y;
	cout<<"Copy_constructor called."<<endl;
}

int main()
{
	Location A(1,2);
	Location B(A);
	Location C=A;
	cout<<"B:"<<B.GetX()<<","<<B.GetY()<<endl;
	cout<<"C:"<<C.GetX()<<","<<C.GetY()<<endl;
}
*/



/*
class Location
{
	public:
		Location(int xx=0,int yy=0)
		{
			X=xx;
			Y=yy;
			cout<<"Constructor"<<endl;
		}
		Location(const Location &p);
		~Location()
		{
			cout<<"Destructor"<<endl;
		}
		int GetX()
		{
			return X;
		}
		int GetY()
		{
			return Y;
		}
	private:
		int X;
		int Y;
};
Location::Location(const Location &p)
{
	X=p.X;
	Y=p.Y;
	cout<<"Copy_constructor"<<endl;
}
void f(Location p)
{
	cout<<"Funtion:"<<p.GetX()<<','<<p.GetY()<<endl;
}

int main()
{
	Location A(1,2);
	f(A);
	return 0;
}
*/



/*
class Location
{
	public:
		Location(int xx=0,int yy=0)
		{
			X=xx;
			Y=yy;
			cout<<"constructor"<<endl;
		}
		Location(const Location &p);
		~Location()
		{
			cout<<"destructor"<<endl;
		}
		int GetX()
		{
			return X;
		}
		int GetY()
		{
			return Y;
		}
	private:
		int X;
		int Y;
};
Location::Location(const Location &p)
{
	X=p.X;
	Y=p.Y;
	cout<<"copy_constructor"<<endl;
}
Location g()
{
	Location A(1,2);
	return A;
}
int main()
{
	Location B;
	cout<<B.GetX()<<","<<B.GetY()<<endl;
	B=g();
cout<<B.GetX()<<","<<B.GetY()<<endl;
	return 0;
}
*/



/*
#include<string.h>
class Person
{
	public:
		Person(const char *pn)
		{
			pname=new char[strlen(pn)+1];
			if(pname)
				strcpy(pname,pn);
		}
		Person(const Person &p);
		~Person()
		{
			delete pname;
		}
	private:
		char *pname;
};
Person::Person(const Person &p)
{
	pname=new char[strlen(p.pname)+1];
	if(pname)
		strcpy(pname,p.pname);
}
int main()
{
	Person p1("Randy");
	Person p2=p1;
	return 0;
}
*/





/*
class A
{
	public:
		A(int i=0,int j=0)
		{
			a=i;
			b=j;
		}
		void print()
		{
			cout<<a<<','<<b<<endl;
		}
	private:
		int a;
		int b;
};

int main()
{
	int i;
	A obj[4]={A(1,2),A(2,3),A(3,4),A(4,5)};
	for(i=0;i<4;i++)
	{
		obj[i].print();
	}
	A *p=obj;
	p->print();
	p++;
	p->print();
	p++;
	p->print();
	p++;
	p->print();
	return 0;
}
*/




/*
int add(int x,int y)
{
	return x+y;
}
int mux(int x,int y)
{
	return x*y;
}
typedef int (*Fun)(int x,int y);
int result(Fun fun,int x,int y)
{
	return fun(x,y);
}
int main()
{
	int x=2,y=3;
	cout<<result(add,x,y)<<endl;
	cout<<result(mux,x,y)<<endl;

	Fun p=&add;
	cout<<(*p)(2,3)<<endl;
	p=&mux;
	cout<<(*p)(2,3)<<endl;

	return 0;
}
*/



/*
class A
{
		friend void fun(A *,int,int);
	public:
		void print()
		{
			cout<<x<<','<<y<<endl;
		}
		void fun_member(int,int);
	private:
		int x,y;
};
void A::fun_member(int i,int j)
{
	x=i;
	y=j;
}
void fun(A *pa,int i,int j)
{
	pa->x=i;
	pa->y=j;
}
int main()
{
	A obj;
	fun(&obj,4,5);
	obj.print();
	obj.fun_member(5,6);
	obj.print();
	return 0;
}
*/




/*
#include<math.h>
class Point
{
		friend double distance(Point*,Point*);
	public:
		Point(double i=0.0,double j=0.0):x(i),y(j){}
	private:
		double x,y;
};
double distance(Point *p1,Point *p2)
{
	double dx=p1->x-p2->x;
	double dy=p1->y-p2->y;
	return sqrt(dx*dx+dy*dy);
}
int main()
{
	Point obj1,obj2(3.0,4.0);
	cout<<distance(&obj1,&obj2)<<endl;
	return 0;
}
*/



/*
class A
{
	friend class B;
	public:
	private:
		int x,y;
};

class B
{
	public:
		void set(int i=0,int j=0)
		{
			a.x=i;
			a.y=j;
		}
		void print()
		{
			cout<<a.x<<','<<a.y<<endl;
		}
	private:
		A a;
};

int main()
{
	B obj;
	obj.set(3,4);
	obj.print();
	return 0;
}
*/


/****
class A
{
	public:
		int a,b;
		void f()
		{
			cout<<"A"<<endl;
		}
};
class B:public A
{
	public:
		int b,c;
		void f()
		{
			cout<<"B"<<endl;
		}
};
int main()
{	
	B obj;
	cout<<sizeof(obj)<<endl;
	A *p=&obj;
	p->f();
	return 0;
}
*/



/*
class A
{
	public:
		static int x;
		int a;
		static void f()
		{
			cout<<"f()"<<endl;
		}
	private:
};
int A::x=0;
class B:public A
{
};
int main()
{
	A obj;
	obj.x=1;
	obj.f();
	B obj0;
	obj0.f();
	return 0;
}
*/



/*
class counter
{
	public:
		counter(int i=0):value(i){}
		void operator++();
		void operator++(int i=0);
		void operator--();
		unsigned int operator()();
	private:
		unsigned int value;
};
void counter::operator++()
{
	if(value<65536)
		value++;
}
void counter::operator++(int i)
{
	if(value<65536)
		value++;
}
void counter::operator--()
{
	if(value>0)
		value--;
}
unsigned int counter::operator()()
{
	return value;
}
int main()
{
	counter obj;
	++obj;
	cout<<obj()<<endl;
	++obj;
	cout<<obj()<<endl;
	--obj;
	cout<<obj()<<endl;
	obj++;
	cout<<obj()<<endl;
	return 0;
}
*/



/*
class complex
{
		friend complex operator+(const complex &c1,const complex &c2);
		friend complex operator-(const complex &c1,const complex &c2);
		friend complex operator-(const complex &c);
	public:
		complex(double r=0,double i=0);
		void print() const;
	private:
		double real,imag;
};
complex::complex(double r,double i)
{
	real=r;
	imag=i;
}
void complex::print() const
{
	cout<<'('<<real<<","<<imag<<')'<<endl;
}
complex operator+(const complex &c1,const complex &c2)
{
	complex result;
	result.real=c1.real+c2.real;
	result.imag=c1.imag+c2.imag;
	return result;
}
complex operator-(const complex &c1,const complex &c2)
{
	complex result;
	result.real=c1.real-c2.real;
	result.imag=c1.imag-c2.imag;
	return result;
}
complex operator-(const complex &c)
{
	return complex(-c.real,-c.imag);
}
int main()
{
	complex c1(2.5,3.7);
	complex c2(3.4,5.6);
	complex c;
	c=c1+c2;
	c.print();
	c=c1-c2;
	c.print();
	c=-c1;
	c.print();
	return 0;
}
*/



/*
class A
{
	public:
		A(int i=0):a(i){}
		A(const A &obj)
		{
			a=obj.a;
			cout<<"copy_constructor"<<endl;
		}
	private:
		int a;
};
int main()
{
	A obj;
	A obj1=obj;
	return 0;
}
*/


/*
class tree_d
{
	public:
		tree_d(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
		tree_d operator++();
		void print() const;
	private:
		int x,y,z;
};
tree_d tree_d::operator++()
{
	x++;
	y++;
	z++;
	return *this;
}
void tree_d::print() const
{
	cout<<'('<<x<<','<<y<<','<<z<<')'<<endl;
}
int main()
{
	tree_d obj(1,2,3);
	tree_d obj1;
	obj1=++obj;
	obj1.print();
	return 0;
}
*/




/*
#include<string.h>
class String
{
	public:
		String(int sz=0)
		{
			p=new char[size=sz];
		}
		String(const char *pc)
		{
			p=new char[size=sizeof(pc)+1];
			strcpy(p,pc);
		}
		~String(){delete p;}
		String &operator=(const String &a);
		void print() const;
	private:
		char *p;
		int size;
};
String &String::operator=(const String &a)
{
	if(this==&a)
	{
		return *this;
	}
	delete p;
	p=new char[size=a.size];
	strcpy(p,a.p);
	return *this;
}
void String::print() const
{
	cout<<p<<endl;
}
int main()
{
	String str("huang");
	String str1("hua");
	String str2;
	(str2=str)=str1;
	str.print();
	str2.print();
	str1.print();
	cout<<"============"<<endl;
	int a=1;
	int b=2;
	int c;
	(c=a)=b;
	cout<<a<<' '<<b<<' '<<c<<endl;
	return 0;
}
*/



/*
class A
{
	public:
		A(int i=0,int j=0):x(i),y(j){}
		double operator()(int i,int j);
	private:
		int x,y;
};
double A::operator()(int i,int j)
{
	return i*j+4;
}
int main()
{
	A obj;
	cout<<obj(2,3)<<endl;
	return 0;
}
*/




/*
class vector
{
	public:
		vector(int size);
		~vector();
		int &operator[](int i);
	private:
		int *v;
};
vector::vector(int size)
{
	v=new int[size];
}
vector::~vector()
{
	delete v;
}
int &vector::operator[](int i)
{
	return v[i];
}
int main()
{
	int i;
	vector a(5);
	for(i=0;i<5;i++)
	{
		a[i]=i;
	}
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
*/


/*
class A
{
	public:
		A(int i=0,int j=1):x(i),y(j){}
		operator double()
		{
			return (double)x/(double)y;
		}
	private:
		int x,y;
};
void display(double d)
{
	cout<<d<<endl;
}
int main()
{
	A obj(1,3);
	display(obj);
}
*/


/*
bool Find(int *matrix,int rows,int columns,int num)
{
	bool result=false;
	if(matrix!=NULL&&rows>0&&columns>0)
	{
		int row=0;
		int column=columns-1;
		while(row<rows&&column>=0)
		{
			if(matrix[row*columns+column]==num)
			{
				result=true;
				break;
			}
			else if(matrix[row*columns+column]>num)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return result;
}

int main()
{
	int a[16]={1,2,8,9,2,4,9,12,4,7,10,13,5,8,11,14};
	cout<<Find(a,4,4,7)<<endl;
	return 0;
}
*/


/*
void replaceBlank(char str[],int len)
{
	int i=0;
	int num_blank=0;
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			num_blank++;
		}
		if(str[i]=='\0')
		{
			break;
		}
	}
	char *p=&str[i];
	char *q=p+2*num_blank;
	for(i=0;i<num_blank;i++)
	{
		while(*p!=' ')
		{
			*q--=*p--;
		}
		*q--='0';
		*q--='2';
		*q--='%';
		p--;
	}
}
int main()
{
	char str[20]="we are here!";
	replaceBlank(str,20);
	cout<<str<<endl;
	return 0;
}
*/


/*****
void fun(int a[],int lena,int b[],int lenb)
{
	int i=lena-1;
	int j=lenb-1;
	int k=i+lenb;
	while(i>=0&&j>=0)
	{
		if(a[i]>=b[j])
		{
			a[k--]=a[i--];
		}
		else
		{	
			a[k--]=b[j--];
		}		
	}
	while(j>=0)
	{
		a[k--]=b[j--];
	}
}
int main()
{
	int i;
	int b[20]={1,3,5,7,9,11,13};
	int a[20]={2,4,6,8,10};
	fun(a,5,b,7);
	for(i=0;i<12;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
*/


/*
#include<stack>
struct Node
{
	int info;
	Node *next;
};

void addToTail(Node **plink,int value)
{
	if(plink==NULL)
	{
		return;
	}
	Node *pNode=new Node;
	pNode->info=value;
	pNode->next=NULL;
	if(*plink==NULL)
	{
		*plink=pNode;
	}
	else
	{
		Node *q=*plink;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=pNode;
	}
}
void deleteLink(Node **plink)
{
	if(plink==NULL||*plink==NULL)
	{
		return;
	}
	Node *p=*plink;
	while(*plink)
	{
		p=(*plink)->next;
		delete *plink;
		*plink=p;
	}
}
void reverseLink(Node **plink)
{
	if(*plink==NULL||plink==NULL)
	{
		return;
	}
	Node *p=*plink;
	Node *q=p->next;
	Node *r=NULL;
	while(q)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	(*plink)->next=NULL;
	*plink=p;
}
void deleteNode(Node **plink,int key)
{
	if(plink==NULL||*plink==NULL)
	{
		return;
	}
	Node *p=*plink;
	Node *pd=NULL;
	if((*plink)->info==key)
	{
		pd=*plink;
		*plink=(*plink)->next;
	}
	else
	{
		while(p->next!=NULL&&p->next->info!=key)
		{
			p=p->next;
		}
		if(p->next!=NULL)
		{
			pd=p->next;
			p->next=pd->next;
		}
	}
	delete pd;
	pd=NULL;
}
void printLink(Node *link)
{
	while(link!=NULL)
	{
		cout<<link->info<<' ';
		link=link->next;
	}
	cout<<endl;
}
void printLink_fromTail(Node *link)
{
	if(link==NULL)
	{
		return;
	}
	printLink_fromTail(link->next);
	cout<<link->info<<' ';
}
void printLink_fromTail1(Node *link)
{
	if(link==NULL)
	{
		return;
	}
	stack<int> st;
	while(link)
	{
		st.push(link->info);
		link=link->next;
	}
	while(!st.empty())
	{
		cout<<st.top()<<' ';
		st.pop();
	}
	cout<<endl;
}
int main()
{
	int i;
	Node *link=NULL;
	for(i=0;i<10;i++)
	{
		addToTail(&link,i+1);
	}
	printLink(link);
	printLink_fromTail(link);
	cout<<endl;
	printLink_fromTail1(link);
	cout<<"========================="<<endl;
	reverseLink(&link);
	printLink(link);

	int key;
	while(cin>>key)
	{
		deleteNode(&link,key);
		printLink(link);
	}
	deleteLink(&link);
	return 0;
}
*/


/*
#include<stack>
#include<queue>
struct BinTreeNode
{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
	{
		return;
	}
	int tmp;
	cin>>tmp;
	if(tmp==0)
	{
		return;
	}
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
BinTreeNode *ConstructCore(int *startPre,int *endPre,int *startIn,int *endIn)
{
	int rootValue=*startPre;
	BinTreeNode *root=new BinTreeNode;
	root->info=rootValue;
	root->llink=root->rlink=NULL;
	
	int leftlen=0;
	while(startIn[leftlen]!=rootValue)
	{
		leftlen++;
	}
	if(leftlen>0)
	{
		root->llink=ConstructCore(startPre+1,startPre+leftlen,startIn,startIn+leftlen-1);
	}
	if(startIn[leftlen]!=*endIn)
	{
		root->rlink=ConstructCore(startPre+leftlen+1,endPre,startIn+leftlen+1,endIn);
	}
	return root;
}
BinTreeNode *Construct(int *preOrder,int *inOrder,int len)
{
	if(preOrder==NULL||inOrder==NULL||len<=0)
	{
		return NULL;
	}
	return ConstructCore(preOrder,preOrder+len-1,inOrder,inOrder+len-1);
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=NULL)
		{
			cout<<p->info<<' ';
			st.push(p->rlink);
			st.push(p->llink); 
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	postOrder(tree->llink);	
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)	
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
void frontOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	queue<BinTreeNode*> qu;
	BinTreeNode *p=tree;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		cout<<p->info<<' ';
		if(p->llink)
		{
			qu.push(p->llink);
		}
		if(p->rlink)
		{
			qu.push(p->rlink);
		}
	}
	cout<<endl;
}
int main()
{
	int in[8]={4,7,2,1,5,3,8,6};
	int pre[8]={1,2,4,7,3,5,6,8};
	BinTreeNode *tree=NULL;
	//createTree(&tree);
	tree=Construct(pre,in,8);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);
	
	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	frontOrder(tree);
	destroyTree(&tree);
	return 0;
}
*/


/*
#include<string.h>
//===================================C++实现栈=======================================
template<typename T>
class Stack
{
	public:
		Stack(int i);
		~Stack();
		bool isFull();
		bool isEmpty();
		void push(const T &key);
		T top();
		void pop();
	private:
		T *a;
		int M;
		int t;
};

template<typename T>
Stack<T>::Stack(int i=100):M(i)
{
	a=new T[i];
	t=-1;
}

template<typename T>
Stack<T>::~Stack()
{
	delete []a;
}

template<typename T>
bool Stack<T>::isFull()
{
	return t==M-1;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return t==-1;
}

template<typename T>
void Stack<T>::push(const T &key)
{
	if(isFull())
	{
		return;
	}
	a[++t]=key;
}

template<typename T>
T Stack<T>::top()
{
	if(isEmpty())
	{
		return T();
	}
	return a[t];
}

template<typename T>
void Stack<T>::pop()
{
	if(isEmpty())
	{
		return;
	}
	t--;
}

//=========================================C++实现队列========================================
template<typename T>
class Queue
{
	public:
		Queue(int s);
		~Queue();
		bool isEmpty();
		bool isFull();
		void push(const T &obj);
		T front();
		void pop();
	private:
		T *data;
		int M;
		int f,r;
};

template<typename T>
Queue<T>::Queue(int s=100):M(s)
{
	data=new T[s];
	f=r=0;
}

template<typename T>
Queue<T>::~Queue()
{
	delete []data;
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return f==r;
}

template<typename T>
bool Queue<T>::isFull()
{
	return (r+1)%M==f;
}

template<typename T>
void Queue<T>::push(const T &obj)
{
	if(isFull())
	{
		return;
	}
	data[r]=obj;
	r=(r+1)%M;
}

template<typename T>
T Queue<T>::front()
{
	if(isEmpty())
	{
		return T();
	}
	return data[f];
}

template<typename T>
void Queue<T>::pop()
{
	if(isEmpty())
	{
		return;
	}
	f=(f+1)%M;
}

//======================================二叉树=============================
struct Node
{
	int info;
	Node *llink,*rlink;
};
Node *ConstructCore(int *startPre,int *endPre,int *startIn,int *endIn)
{
	int rootValue=*startPre;
	Node *root=new Node;
	root->info=rootValue;
	root->llink=root->rlink=NULL;
	int leftlen=0;
	while(startIn[leftlen]!=rootValue)
	{
		leftlen++;
	}
	if(leftlen)
	{
		root->llink=ConstructCore(startPre+1,startPre+leftlen,startIn,startIn+leftlen-1);
	}
	if(startIn[leftlen]!=*endIn)
	{
		root->rlink=ConstructCore(startPre+leftlen+1,endPre,startIn+leftlen+1,endIn);
	}
	return root;
}
Node *Construct(int *pre,int *in,int len)
{
	if(pre==NULL||in==NULL||len<=0)
	{
		return NULL;
	}
	return ConstructCore(pre,pre+len-1,in,in+len-1);
}
//---------------------创建二叉树----------------------------
void createTree(Node **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
	{
		return;
	}
	int tmp;
	cin>>tmp;
	if(tmp==0)
	{
		return;
	}
	*ptree=new Node;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
//--------------销毁二叉树------------------------
void destroyTree(Node **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
//------------------先序遍历递归算法------------------------------
void preOrder(Node *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
//------------------------先序遍历非递归算法--------------------------
void nPreOrder(Node *tree)
{
	if(tree==NULL)
	{
		return;
	}
	Stack<Node*> st;
	Node *p=tree;
	st.push(p);
	while(!st.isEmpty())
	{
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(p->rlink)
		{
			st.push(p->rlink);
		}
		if(p->llink)
		{
			st.push(p->llink);
		}

//		if(p!=NULL)
//		{
//			cout<<p->info<<' ';
//			st.push(p->rlink);
//			st.push(p->llink);
//		}

	}
	cout<<endl;
}
//-------------------------中序遍历递归算法---------------------------
void inOrder(Node *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
//-----------------------中序遍历非递归算法--------------------------- 
void nInOrder(Node *tree)
{
	if(tree==NULL)
	{
		return;
	}
	Stack<Node*> st;
	Node *p=tree;
	while(p!=NULL||!st.isEmpty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
//---------------------后序遍历递归算法-------------------------
void postOrder(Node *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
//-------------------后序遍历非递归算法------------------------- 
void nPostOrder(Node *tree)
{
	if(tree==NULL)
	{
		return;
	}
	Stack<Node*> st;
	Node *p=tree;
	Node *pp=NULL;
	while(p!=NULL||!st.isEmpty())
	{
		while(p!=NULL)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.isEmpty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
//---------------广度优先遍历----------------
void frontOrder(Node *tree)
{
	if(tree==NULL)
	{
		return;
	}
	Queue<Node*> st;
	Node *p=tree;
	st.push(p);
	while(!st.isEmpty())
	{
		p=st.front();
		st.pop();
		if(p)
		{
			cout<<p->info<<' ';
			st.push(p->llink);
			st.push(p->rlink); 
		}

//		cout<<p->info<<' ';
//		if(p->llink)
//		{
//			st.push(p->llink);
//		}
//		if(p->rlink)
//		{
//			st.push(p->rlink);
//		}

	}
	cout<<endl;
}
//======================二叉排序树转换为排序的双向链表的非递归算法=============================
void convert_to_link(Node **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	Stack<Node*> st;
	Node *p=*ptree;
	Node *pLast=NULL;
	while(p!=NULL||!st.isEmpty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}

		

		p=st.top();
		st.pop();
		
		p->llink=pLast;
		if(pLast!=NULL)
		{
			pLast->rlink=p;
		}

		pLast=p;
		
		p=p->rlink;
	}
	while((*ptree)->llink!=NULL)
		*ptree=(*ptree)->llink;
}
//======================二叉排序树转换为排序的双向链表的递归算法=============================
void ConvertNode(Node *pNode,Node **pLast)
{
	if(pNode==NULL)
		return;
	Node *pCurrent=pNode;
	if(pCurrent->llink!=NULL)
		ConvertNode(pCurrent->llink,pLast);

	pCurrent->llink=*pLast;
	if(*pLast!=NULL)
		(*pLast)->rlink=pCurrent;
	*pLast=pCurrent;
	
	if(pCurrent->rlink!=NULL)
		ConvertNode(pCurrent->rlink,pLast);
}
void convert_to_linkR(Node **ptree)
{
	Node *pLast=NULL;
	ConvertNode(*ptree,&pLast);

	while(*ptree!=NULL&&(*ptree)->llink!=NULL)
		*ptree=(*ptree)->llink;
}


class String
{
	public:
		String(const char *s=NULL)
		{
			if(s==NULL)
			{
				data=new char[1];
				data[0]='\0';
			}
			else
			{
				data=new char[strlen(s)+1];
				strcpy(data,s);
			}
		}
		String(const String &str)
		{
			data=new char[strlen(str.data)+1];
			strcpy(data,str.data);
		}
		~String()
		{
			delete []data;
		}
		String &operator=(const String &obj)
		{
			if(this==&obj)
			{
				return *this;
			}
			delete []data;
			data=NULL;

			data=new char[strlen(obj.data)+1];
			strcpy(data,obj.data);

			return *this;
		}
		friend ostream &operator<<(ostream &os,String obj)
		{
			cout<<obj.data;
			return os;
		}
		friend istream &operator>>(istream &is,String &obj)
		{
			is>>obj.data;
			return is;
		}
	private:
		char *data;
};


int main()
{
	Stack<int> st;
	int i;
	for(i=0;i<10;i++)
	{
		st.push(i+1);
	}
	while(!st.isEmpty())
	{
		cout<<st.top()<<' ';
		st.pop();
	}
	cout<<endl;
	cout<<"==============================="<<endl;

	Stack<String> stStr;
	String str;
	for(i=0;i<5;i++)
	{
		cin>>str;
		stStr.push(str);
	}
	while(!stStr.isEmpty())
	{
		cout<<stStr.top()<<' ';
		stStr.pop();
	}	
	cout<<endl;
	cout<<"================================="<<endl;


	Node *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	frontOrder(tree);
	destroyTree(&tree);
	cout<<"===================================="<<endl;
	int pre[7]={1,2,4,5,3,6,7};
	int in[7]={4,2,5,1,6,3,7};
	tree=Construct(pre,in,7);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	frontOrder(tree);
	cout<<"======================================"<<endl;
	convert_to_linkR(&tree);
	Node *p=NULL;
	while(tree)
	{
		cout<<tree->info<<' ';
		p=tree->rlink;
		delete tree;
		tree=p;
	}
	cout<<endl;
	cout<<"====================================="<<endl;
	tree=Construct(pre,in,7);	
	convert_to_link(&tree);
	p=NULL;
	while(tree)
	{
		cout<<tree->info<<' ';
		p=tree->rlink;
		delete tree;
		tree=p;
	}
	cout<<endl;
	//destroyTree(&tree);
	return 0;
}
*/



/*
class Three_d
{
	public:
		Three_d(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
		friend ostream& operator<<(ostream &os,Three_d obj);
		friend istream& operator>>(istream &is,Three_d &obj);
	private:
		int x,y,z;
};
ostream& operator<<(ostream &os,Three_d obj)
{
	os<<'('<<obj.x<<','<<obj.y<<','<<obj.z<<')';
	return os;
}
istream& operator>>(istream &is,Three_d &obj)
{
	is>>obj.x;
	is>>obj.y;
	is>>obj.z;
	return is;
}
int main()
{
	Three_d obj(1,2,3);
	cout<<obj<<endl;
	cin>>obj;
	cout<<obj<<endl;
	return 0;
}
*/



/*
#include<string.h>
template<typename T>
class Array
{
	public:
		Array(int s);
		virtual ~Array();
		const T &Entry(int index);
		void Enter(int index,const T &value);
		T &operator[](int index);
	private:
		T *element;
		int size;
};

template<typename T>
Array<T>::Array(int s)
{
	element=new T[s];
	size=s;
}

template<typename T>
Array<T>::~Array()
{
	delete []element;
}

template<typename T>
const T& Array<T>::Entry(int index)
{
	if(index>=0&&index<size)
		return element[index];
}

template<typename T>
void Array<T>::Enter(int index,const T &value)
{
	if(index>=0&&index<size)
		element[index]=value;
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if(index>=0&&index<size)
		return element[index];
}


class String
{
	public:
		String(const char *s=NULL)
		{
			if(s==NULL)
			{
				data=new char[1];
				data[0]='\0';
			}
			else
			{
				data=new char[strlen(s)+1];
				strcpy(data,s);
			}
		}
		~String()
		{
			delete []data;
		}
		String &operator=(const String &obj)
		{
			if(this==&obj)
			{
				return *this;
			}
			delete []data;
			data=NULL;

			data=new char[strlen(obj.data)+1];
			strcpy(data,obj.data);

			return *this;
		}
		friend ostream &operator<<(ostream &os,String obj)
		{
			cout<<obj.data;
			return os;
		}
		friend istream &operator>>(istream &is,String &obj)
		{
			is>>obj.data;
			return is;
		}
	private:
		char *data;
};
int main()
{
	Array<String> iarr(10);
	int i;
	String obj;
	for(i=0;i<10;i++)
	{
		cin>>obj;
		iarr[i]=obj;
	}
	for(i=0;i<10;i++)
	{
		cout<<iarr[i]<<' ';
	}
	cout<<endl;
	return 0;
}
*/




/*
#include<stack>
#include<queue>

//=========================两个栈实现队列============================
template<typename T>
class Queue
{
	public:
		bool empty();
		void push(const T &obj);
		T pop();
	private:
		stack<T> st1;
		stack<T> st2;
};

template<typename T>
bool Queue<T>::empty()
{
	return st1.empty()&&st2.empty();
}

template<typename T>
void Queue<T>::push(const T &obj)
{
	st1.push(obj);
}

template<typename T>
T Queue<T>::pop()
{
	T result=T();
	if(!st2.empty())
	{
		result=st2.top();
		st2.pop();
	}
	else if(!st1.empty())
	{
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		result=st2.top();
		st2.pop();
	}
	return result;
}


//=========================两个队列实现栈============================
template<typename T>
class Stack
{
	public:
		bool empty();
		void push(const T &obj);
		T pop();
	private:
		queue<T> qu1;
		queue<T> qu2;
};

template<typename T>
bool Stack<T>::empty()
{
	return qu1.empty()&&qu2.empty();
}

template<typename T>
void Stack<T>::push(const T &obj)
{
	if(qu1.empty())
	{
		qu2.push(obj);
	}
	else
	{
		qu1.push(obj);
	}
}

template<typename T>
T Stack<T>::pop()
{
	T result=T();
	if(empty())
	{
		return T();
	}
	if(qu1.empty())
	{
		while(qu2.size()!=1)
		{
			qu1.push(qu2.front());
			qu2.pop();
		}
		result=qu2.front();
		qu2.pop();
	}
	else
	{
		while(qu1.size()!=1)
		{
			qu2.push(qu1.front());
			qu1.pop();
		}
		result=qu1.front();
		qu1.pop();
	}
	return result;
}
int main()
{
	Queue<int> qu;
	int i=0;
	for(i=0;i<10;i++)
	{
		qu.push(i+1);
	}
	for(i=0;i<5;i++)
	{
		cout<<qu.pop()<<' ';
	}
	cout<<endl;
	for(i=10;i<20;i++)
	{
		qu.push(i+1);
	}
	while(!qu.empty())
	{
		cout<<qu.pop()<<' ';
	}
	cout<<endl;
	cout<<"================================="<<endl;
	Stack<int> st;
	for(i=0;i<10;i++)
	{
		st.push(i+1);
	}
	for(i=0;i<5;i++)
	{
		cout<<st.pop()<<' ';
	}
	cout<<endl;
	for(i=10;i<20;i++)
	{
		st.push(i+1);
	}
	while(!st.empty())
	{
		cout<<st.pop()<<' ';
	}
	cout<<endl;
	return 0;
}
*/



/***
template<typename T>
class Array
{
	public:
		Array(int s);
		virtual ~Array();
		virtual const T& Entry(int index) const;
		virtual void Enter(int index,const T &value);
	private:
		int size;
		T *element;
};

template<typename T>
Array<T>::Array(int s)
{
	size=s;
	element=new T[size];
}

template<typename T>
Array<T>::~Array()
{
	delete []element;
}

template<typename T>
const T& Array<T>::Entry(int index) const
{
	return element[index];
}

template<typename T>
void Array<T>::Enter(int  index,const T &value)
{
	element[index]=value;
}


template<typename T>
class BoundArray:public Array<T>
{
	public:
		BoundArray(int s,int m=0);
		virtual const T& Entry(int index) const;
		virtual void Enter(int index,const T &value);
	private:
		int min;
};

template<typename T>
BoundArray<T>::BoundArray(int s,int m):Array<T>(s),min(m)
{
}

template<typename T>
const T& BoundArray<T>::Entry(int index) const
{
	return Array<T>::Entry(index-min);
}

template<typename T>
void BoundArray<T>::Enter(int index,const T &value)
{
	Array<T>::Enter(index-min,value);
}
int main()
{
	int i=0;
	BoundArray<int> arr(5,1);
	for(i=1;i<=5;i++)
	{
		arr.Enter(i,i);
	}
	for(i=1;i<=5;i++)
	{
		cout<<arr.Entry(i)<<' ';
	}
	cout<<endl;
	return 0;
}
*/



/*
class Expt
{
	public:
		Expt(){};
		~Expt(){};
};

class Demo
{
	public:
		Demo()
		{
			n=0;
			cout<<"create obj 1,n="<<n<<endl;
		}
		Demo(int m)
		{
			n=m;
			cout<<"create obj 2,n="<<n<<endl;
		}
		~Demo()
		{
			cout<<"delete obj,n="<<n<<endl;
		}
	private:
		int n;
};

int main()
{
	Demo d0(1);
	try{
		Demo d1;
		Demo d2(10);
		throw Expt();
		Demo d3;
	}
	catch(Expt e){}
	cout<<"pass"<<endl;
	return 0;
}
*/



/*
#include<stack>
struct BinTreeNode
{
	int info;
	BinTreeNode *llink,*rlink;
};

BinTreeNode *ConstructCore(int *startPre,int *endPre,int *startIn,int *endIn)
{
	int rootValue=*startPre;
	BinTreeNode *root=new BinTreeNode;
	root->info=rootValue;
	root->llink=root->rlink=NULL;
	
	int leftLen=0;
	while(startIn[leftLen]!=rootValue)
	{
		leftLen++;
	}
	
	if(leftLen>0)
	{
		root->llink=ConstructCore(startPre+1,startPre+leftLen,startIn,startIn+leftLen-1);
	}
	if(startIn[leftLen]!=*endIn)
	{
		root->rlink=ConstructCore(startPre+leftLen+1,endPre,startIn+leftLen+1,endIn);
	}
	return root;
}
BinTreeNode *Construct(int *pre,int *in,int len)
{
	if(pre==NULL||in==NULL||len<=0)
		return NULL;
	return ConstructCore(pre,pre+len-1,in,in+len-1);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink); 
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void convert(BinTreeNode *tree,BinTreeNode **pLast)
{
	if(tree==NULL)
		return;
	BinTreeNode *current=tree;
	
	convert(tree->llink,pLast);

	if(*pLast!=NULL)
		(*pLast)->rlink=current;
	current->llink=*pLast;
	*pLast=current;

	convert(tree->rlink,pLast);
}
void convert2link(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	BinTreeNode *lastNode=NULL;
	convert(*ptree,&lastNode);
	while((*ptree)->llink!=NULL)
		*ptree=(*ptree)->llink;

}
void convert2linkN(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=*ptree;
	BinTreeNode *pLast=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		if(pLast!=NULL)
		{
			pLast->rlink=p;
		}
		p->llink=pLast;
		pLast=p;

		p=p->rlink;
	}
	while((*ptree)->llink!=NULL)
		*ptree=(*ptree)->llink;
}
int main()
{
	int pre[7]={1,2,4,5,3,6,7};
	int in[7]={4,2,5,1,6,3,7};
	BinTreeNode *tree=Construct(pre,in,7);
	preOrder(tree);
	cout<<endl;
	inOrder(tree);
	cout<<endl;
	postOrder(tree);
	cout<<endl;
	
	convert2linkN(&tree);
	BinTreeNode *p=NULL;
	while(tree!=NULL)
	{
		cout<<tree->info<<' ';
		p=tree->rlink;
		delete tree;
		tree=p; 
	}
	cout<<endl;
	//destroyTree(&tree);
	return 0;
}
*/



/******************************************************************************
int list(int *a,int n)
{
	int i=0;
	int j=0;
	int *d=new int[n];
	int max=1;
	for(i=0;i<n;i++)
	{
		d[i]=1;
		for(j=0;j<i;j++)
		{	
			if(a[j]<a[i]&&d[j]+1>d[i])
			{
				d[i]=d[j]+1;
			}
		}
		if(d[i]>max)
			max=d[i];
	}
	delete []d;
	return max;
}
int main()
{
	int a[6] = { 1, 2, 3, 1, 1, 2 };
	cout<<list(a,6)<<endl;
	return 0;
}
*/


/**********************************
int gys(int a,int b)
{
	return b==0? a:gys(b,a%b);
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<gys(a,b)<<endl;
	}
	return 0;
}
*/


/*
int getMax_sum(int *a,int n)
{
	int maxSum=0;
	int curSum=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		curSum+=a[i];
		if(curSum<0)
			curSum=0;
		if(curSum>maxSum)
		{
			maxSum=curSum;
		}
	}
	return maxSum;
}
int main()
{
	int a[7]={2,5,-4,2,-1,5,-4};
	cout<<getMax_sum(a,7)<<endl;
	return 0;
}
*/

/*
int max(int a,int b)
{
	return a>b? a:b;
}
int min(int a,int b)
{
	return a<b? a:b;
}
int getMax_product(int *a,int n)
{
	int maxProduct=1;
	int minProduct=1;
	int result=1;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			maxProduct=1;
			minProduct=1;
		}
		else if(a[i]<0)
		{
			int tmp=maxProduct;
			maxProduct=max(minProduct*a[i],1);
			minProduct=tmp*a[i];
		}
		else
		{
			maxProduct*=a[i];
			minProduct=min(minProduct*a[i],1);
		}
		result=max(result,maxProduct);
	}
	return result;
}
int main()
{
	int a[7] = { 1, 2, -2, 4, 5, 2, -1 };
	cout << getMax_product(a, 7) << endl;
	return 0;
}
*/

/***************************************
int add(int a,int b)
{
	return b==0? a:add(a^b,(a&b)<<1);
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<add(a,b)<<endl;
	}
	return 0;
}
*/

/*
long long numof1(long long n)
{
	int num=0;
	while(n)
	{
		num++;
		n&=(n-1);
	}
	return num;
}
int main()
{
	long long n;
	while(cin>>n)
	{
		cout<<numof1(n)<<endl;
	}
	return 0;
}
*/
/****************************
#include<math.h>
bool isPrime(long long n)
{
	long long i=sqrt(n);
	int j=0;
	for(j=2;j<=i;j++)
	{
		if(n%j==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long long n;
	while(cin>>n)
	{
		cout<<isPrime(n)<<endl;
	}
	return 0;
}
*/
/*****************************************
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

/*****************************
class A
{
public:
	void f(int i)
	{
		cout << "f in A" << endl;
	}
};
class B:public A
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
/************************************
#include<iostream>
using namespace std;
class A1
{
public:
	A1()
	{
		cout<<"A1"<<endl;
	}
	virtual ~A1()
	{
		cout << "~A1" << endl;
	}
private:
};
class A2
{
public:
	A2()
	{
		cout<<"A2"<<endl;
	}
	virtual ~A2()
	{
		cout << "~A2" << endl;
	}
private:
};
class B :public A1, public A2
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}
	virtual ~B()
	{
		cout << "~B" << endl;
	}
private:

};
int main()
{
	A1 *pA1 = new B;
	delete pA1;
	return 0;
}
*/

/*******************************888
#include<vector>
#include<stdexcept>
int main()
{
vector<int> ivec;
ivec.push_back(1);
	try
	{
		
		cout << ivec.at(1) << endl;
		return 0;
	}
	catch(out_of_range&exc)
	{
		cout << "out of range" << endl;
	}
}
*/

/**********************************
void swap(int &a,int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		swap(a,b);
		cout<<a<<','<<b<<endl;
	}
	return 0;
}
*/

/*
#include<string>
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

/*
struct BinTreeNode 
{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
		return;
	int tmp;
	cin>>tmp;
	if(tmp==0)
		return;
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree==NULL;
}
void mirrorTree(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	mirrorTree(tree->llink);
	mirrorTree(tree->rlink);
	BinTreeNode *p=tree->llink;
	tree->llink=tree->rlink;
	tree->rlink=p;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	mirrorTree(tree);
	preOrder(tree);
	cout<<endl;
	destroyTree(&tree);
	return 0;
}
*/

/*
int fun(int x)
{
	int y=x>>31;
	return (x^y)-y;
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
*/


/*
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=k;i<n;i+=k)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)
	{
		shell(a,n,k);
		k/=2;
	}
}

void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
			{
				x=j;
			}
		}
		if(x!=i)
		{
			a[x]^=a[i];
			a[i]^=a[x];
			a[x]^=a[i];
		}
	}
}
void heap(int *a,int n,int i)
{
	int child;
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child<n-1&&a[child]<a[child+1])
			child++;
		if(a[child]>a[i])
		{
			a[i]^=a[child];
			a[child]^=a[i];
			a[i]^=a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a,int n)
{
	int i;
	if(a==NULL||n<=1)
	{
		return;
	}
	for(i=n/2-1;i>=0;i--)
	{
		heap(a,n,i);
	}
	for(i=n-1;i>0;i--)
	{
		a[0]^=a[i];
		a[i]^=a[0];
		a[0]^=a[i];
		heap(a,i,0);
	}
}
void QiPaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i=0;
	int j=n-1;
	int x=a[0];
	while(i<j)
	{	
		for(;i<j;j--)
		{
			if(a[j]<x)
			{
				a[i++]=a[j];
				break;
			}
		}
		for(;i<j;i++)
		{
			if(a[i]>x)
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}

}
void mergePass(int *a,int *b,int n,int len)
{
	int i=0;
	while(i+2*len-1<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
	{
		merge(a,b,i,i+len-1,n-1);
	}
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int len=1;
	int *b=new int[n];
	while(len<n)
	{
		mergePass(a,b,n,len);
		len*=2;
		mergePass(b,a,n,len);
		len*=2;
	}
	delete []b;
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



/*
#include<stack>
#include<queue>
struct BinSearchNode
{
	int info;
	BinSearchNode *llink,*rlink;
};

int searchNode(BinSearchNode *tree,int key,BinSearchNode **pPosition)
{
	if(pPosition==NULL)
		return -1;
	BinSearchNode *p=tree;
	BinSearchNode *q=NULL;
	while(p)
	{
		q=p;
		if(p->info==key)
		{
			*pPosition=NULL;
			return 1;
		}
		else if(p->info>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	*pPosition=q;
	return 0;
}
int insertNode(BinSearchNode **ptree,int key)
{
	if(ptree==NULL)
	{
		return -1;
	}
	BinSearchNode *position=NULL;
	if(searchNode(*ptree,key,&position)==1)
	{
		return 0;
	}
	BinSearchNode *p=new BinSearchNode;
	p->info=key;
	p->llink=p->rlink=NULL;
	if(position==NULL)
	{
		*ptree=p;
	}
	else if(position->info>key)
	{
		position->llink=p;
	}
	else 
	{
		position->rlink=p;
	}
	return 1;
}
void deleteNode(BinSearchNode **ptree,int key)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	BinSearchNode *p=*ptree;
	BinSearchNode *parent=NULL;
	while(p)
	{
		if(p->info==key)
			break;
		parent=p;
		if(p->info>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	if(p==NULL)
	{
		return;
	}
	if(p->llink==NULL)
	{
		if(parent==NULL)
		{
			*ptree=p->rlink;
		}
		else if(parent->llink==p)
		{
			parent->llink=p->rlink;
		}
		else
		{
			parent->rlink=p->rlink;
		}
	}
	else
	{
		BinSearchNode *r=p->llink;
		while(r->rlink)
			r=r->rlink;
		r->rlink=p->rlink;
		if(parent==NULL)
		{
			*ptree=p->llink;
		}
		else if(parent->llink==p)
		{
			parent->llink=p->llink;
		}
		else
		{
			parent->rlink=p->llink;
		}
	}
	delete p;
}
void createTree(BinSearchNode **ptree)
{
	if(ptree==NULL)
	{
		return;
	}
	int key;
	while(cin>>key)
	{
		insertNode(ptree,key);
	}
}
void destroyTree(BinSearchNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=NULL)
		{
			cout<<p->info<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
void nInOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinSearchNode *tree)
{
	if(tree==NULL)	
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	BinSearchNode *pp=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
void frontOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	queue<BinSearchNode*> qu;
	BinSearchNode *p=tree;
	qu.push(tree);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		if(p)
		{
			cout<<p->info<<' ';
			qu.push(p->llink);
			qu.push(p->rlink);
		}
	}
	cout<<endl;
}
int main()
{
	BinSearchNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	frontOrder(tree);
	int key;
	cin.clear();
	while(cin>>key)
	{
		deleteNode(&tree,key);	
		preOrder(tree);
		cout<<endl;
		nPreOrder(tree);

		inOrder(tree);
		cout<<endl;
		nInOrder(tree);

		postOrder(tree);
		cout<<endl;
		nPostOrder(tree);

		frontOrder(tree);
	}
	destroyTree(&tree);
	return 0;
}
*/

/*
#include<stack>
#include<queue>
struct BinSearchNode
{
	int info;
	BinSearchNode *llink,*rlink;
};

int searchNode(BinSearchNode *tree,int key,BinSearchNode **pPosition)
{
	if(pPosition==NULL)
	{
		return -1;
	}
	BinSearchNode *p=tree;
	BinSearchNode *parent=NULL;
	while(p)
	{
		parent=p;
		if(p->info==key)
		{
			*pPosition=p;
			return 1;
		}
		else if(p->info>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	*pPosition=parent;
	return 0;
}
int insertNode(BinSearchNode **ptree,int key)
{
	if(ptree==NULL)
		return-1;
	BinSearchNode *position=NULL;
	int flag=searchNode(*ptree,key,&position);
	if(flag==1)
	{
		return 0;
	}
	else if(flag==-1)
	{
		return -1;
	}
	BinSearchNode *p=new BinSearchNode;
	p->info=key;
	p->llink=p->rlink=NULL;
	if(position==NULL)
	{
		*ptree=p;
	}
	else if(position->info>key)
	{
		position->llink=p;
	}
	else
	{
		position->rlink=p;
	}
	return 1;
}
void createTree(BinSearchNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
		return;
	int key;
	while(cin>>key)
	{
		insertNode(ptree,key);
	}
}
void destroyTree(BinSearchNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void deleteNode(BinSearchNode **ptree,int key)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	BinSearchNode *p=*ptree;
	BinSearchNode *parent=NULL;
	while(p)
	{
		if(p->info==key)
		{
			break;
		}
		parent=p;
		if(p->info>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	if(p==NULL)
	{
		return;
	}
	if(p->llink==NULL)
	{
		if(parent==NULL)
		{
			*ptree=p->rlink;
		}
		else if(parent->llink==p)
		{
			parent->llink=p->rlink;
		}
		else if(parent->rlink==p)
		{
			parent->rlink=p->rlink;
		}
	}
	else
	{
		BinSearchNode *r=p->llink;
		while(r->rlink)
		{
			r=r->rlink;
		}
		r->rlink=p->rlink;
		if(parent==NULL)
		{
			*ptree=p->llink;
		}
		else if(parent->llink==p)
		{
			parent->llink=p->llink;
		}
		else if(parent->rlink==p)
		{
			parent->rlink=p->llink;
		}
	}
	delete p;
}
void preOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			cout<<p->info<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);	
}
void nInOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinSearchNode*> st;
	BinSearchNode *p=tree;
	BinSearchNode *pp=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}	
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else 
		{
			p=NULL;
		}
	}
	cout<<endl;
}
void frontOrder(BinSearchNode *tree)
{
	if(tree==NULL)
		return;
	queue<BinSearchNode*> qu;
	BinSearchNode *p=tree;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		if(p)
		{
			cout<<p->info<<' ';
			qu.push(p->llink);
			qu.push(p->rlink);
		}
	}
	cout<<endl;
}
int main()
{
	BinSearchNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);
	
	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	frontOrder(tree);
	cin.clear();
	int key;
	while(cin>>key)
	{
		deleteNode(&tree,key);
		preOrder(tree);
		cout<<endl;
		nPreOrder(tree);

		inOrder(tree);
		cout<<endl;
		nInOrder(tree);
	
		postOrder(tree);
		cout<<endl;
		nPostOrder(tree);

		frontOrder(tree);
	}
	destroyTree(&tree);
	return 0;
}
*/


/*
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=k;i<n;i+=k)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)	
	{
		shell(a,n,k);
		k/=2;
	}
}
void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
			{
				x=j;
			}
		}
		if(x!=i)
		{
			a[x]^=a[i];
			a[i]^=a[x];
			a[x]^=a[i];
		}
	}
}
void heap(int *a,int n,int i)
{
	int child;
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child<n-1&&a[child]<a[child+1])
		{
			child++;
		}
		if(a[i]<a[child])
		{
			a[i]^=a[child];
			a[child]^=a[i];
			a[i]^=a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=n/2-1;i>=0;i--)
	{
		heap(a,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		a[0]^=a[i];
		a[i]^=a[0];
		a[0]^=a[i];
		heap(a,i,0);
	}
}
void QiPaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i=0;
	int j=n-1;
	int x=a[0];
	while(i<j)
	{
		for(;i<j;j--)
		{
			if(a[j]<x)
			{
				a[i++]=a[j];
				break;
			}
		}
		for(;i<j;i++)
		{
			if(a[i]>x)
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
}
void mergePass(int *a,int *b,int n,int len)
{
	int i=0;
	while(i+2*len+1<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
	{
		merge(a,b,i,i+len-1,n-1);
	}
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)	
		return;
	int len=1;
	int *b=new int[n];
	while(len<n)
	{
		mergePass(a,b,n,len);
		len*=2;
		mergePass(b,a,n,len);
		len*=2;
	}
	delete []b;
}
int main()
{
	int a[20]={5,9,11,2,19,3,8,20,4,6,17,1,16,15,14,12,13,7,10,18};
	//insertSort(a,20);
	//shellSort(a,20);
	//selectSort(a,20);
	//heapSort(a,20);
	//QiPaoSort(a,20);
	//QSort(a,20);
	mergeSort(a,20);
	for(int i=0;i<20;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
*/


/**
#include<vector>
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=100):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		return;
	}
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
	{
		return T();
	}
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
	{
		return;
	}
	t--;
}

template<typename T>
class queue
{
	public:
		queue(int i);
		~queue();
		bool empty();
		bool full();
		void push(const T &obj);
		T front();
		void pop();
	private:
		T *data;
		int M;
		int f,r;
};

template<typename T>
queue<T>::queue(int i=10):M(i)
{
	data=new T[M];
	f=r=0;
}

template<typename T>
queue<T>::~queue()
{
	delete []data;
}

template<typename T>
bool queue<T>::empty()
{
	return f==r;
}

template<typename T>
bool queue<T>::full()
{
	return (r+1)%M==f;
}

template<typename T>
void queue<T>::push(const T &obj)
{
	if(full())
	{
		return;
	}
	data[r]=obj;
	r=(r+1)%M;
}

template<typename T>
T queue<T>::front()
{
	if(empty())
	{
		return T();
	}
	return data[f];
}

template<typename T>
void queue<T>::pop()
{
	if(empty())
	{
		return;
	}
	f=(f+1)%M;
}
struct BinTreeNode
{
	int info;
	BinTreeNode *llink,*rlink;
}; 
BinTreeNode *ConstructCore(int *preStart,int *preEnd,int *inStart,int *inEnd)
{
	int rootValue=*preStart;
	BinTreeNode *root=new BinTreeNode;
	root->info=rootValue;
	root->llink=root->rlink=NULL;
	int leftlen=0;
	while(inStart[leftlen]!=rootValue)
		leftlen++;

	if(leftlen>0)
		root->llink=ConstructCore(preStart+1,preStart+leftlen,inStart,inStart+leftlen-1);

	if(rootValue!=*inEnd)
		root->rlink=ConstructCore(preStart+leftlen+1,preEnd,inStart+leftlen+1,inEnd);

	return root;
}
BinTreeNode *Construct(int *pre,int *in,int len)
{
	if(pre==NULL||in==NULL||len<=0)
		return NULL;
	return ConstructCore(pre,pre+len-1,in,in+len-1);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			cout<<p->info<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
void frontOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	queue<BinTreeNode*> qu;
	BinTreeNode *p=tree;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		if(p)
		{
			cout<<p->info<<' ';
			qu.push(p->llink);
			qu.push(p->rlink);
		}
	}
	cout<<endl;
}
void convertCore(BinTreeNode *tree,BinTreeNode **pLast)
{
	if(tree==NULL)
		return;
	BinTreeNode *current=tree;
	convertCore(current->llink,pLast);

	if(*pLast!=NULL)
		(*pLast)->rlink=current;
	current->llink=*pLast;
	*pLast=current;
	
	convertCore(current->rlink,pLast);
	
}
void convert(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	BinTreeNode *Last=NULL;
	convertCore(*ptree,&Last);
	while((*ptree)->llink)
		*ptree=(*ptree)->llink;
}
void nConvert(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=*ptree;
	BinTreeNode *last=NULL;
	while(p!=NULL||!st.empty())
	{
		while(p!=NULL)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();

		if(last!=NULL)
			last->rlink=p;
		p->llink=last;
		last=p;

		p=p->rlink;
	}
	while((*ptree)->llink)
		*ptree=(*ptree)->llink;
}
void printPath_leafNode(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	vector<BinTreeNode*> vec;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p!=NULL||!vec.empty())
	{
		while(p!=NULL)
		{
			vec.push_back(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=vec.back();
		vec.pop_back();
		if(p->llink==NULL&&p->rlink==NULL)
		{
			for(vector<BinTreeNode*>::iterator iter=vec.begin();iter!=vec.end();++iter)
			{
				cout<<(*iter)->info<<' ';
			}
			cout<<p->info<<endl;
		}
		if(!vec.empty()&&vec.back()->llink==p)
		{
			p=vec.back()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
}
void width_depth(BinTreeNode *tree,int &width,int &depth)
{
	if(tree==NULL)
		return;
	queue<BinTreeNode*> qu;
	BinTreeNode *p=tree;
	qu.push(p);
	int last=1;
	int buf=1;
	width=1;
	depth=0;
	while(!qu.empty())
	{
		buf=0;
		while(last--)
		{
			p=qu.front();
			qu.pop();
			if(p->llink)
			{
				qu.push(p->llink);
				buf++;
			}
			if(p->rlink)
			{
				qu.push(p->rlink);
				buf++;
			}
		}
		if(buf>width)
		{
			width=buf;
		}
		last=buf;
		depth++;
	}
	
}
int main()
{
	int pre[9]={1,9,2,7,3,5,4,6,8};
	int in[9] ={1,2,3,4,5,6,7,8,9};
	BinTreeNode *tree=Construct(pre,in,9);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);
	
	frontOrder(tree);

	cout<<"================"<<endl;
	printPath_leafNode(tree);
	cout<<"================"<<endl;
	int width,depth;
	width_depth(tree,width,depth);
	cout<<"width:"<<width<<"  "<<"depth:"<<depth<<endl;
	nConvert(&tree);
	while(tree)
	{
		cout<<tree->info<<' ';
		BinTreeNode *p=tree;
		tree=tree->rlink;
		delete p;
	}
	cout<<endl;
	//destroyTree(&tree);
	return 0;
}
*/

/*
#include<iostream>
using namespace std;
struct bs
{
	short a : 8; 
	short b : 2; 
	short c : 6;
};

int main()
{
	cout << sizeof(bs) << endl;
	return 0;
}
*/


/*
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

/*
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
	int i = (int)&p->y;
	cout << i << endl;
	return 0;
}
*/

/*
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



/*
class A
{
public:
	A()
	{
	}
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


/*
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


/*
struct A
{
	char t : 4;
	char k : 4;
	int i ;
	int m: 8;
};
int main()
{

	cout << sizeof(unsigned long) << endl;
	cout << sizeof(A) << endl;
	return 0;
}
*/

/*
#include<iostream>
using namespace std;
int main()
{
	static int i;
	cout << i << endl;
	return 0;
}
*/


/****和为s的两个数字（不是排序的）*****
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
*/



/*
void fun(int *a,int n,int sum,int *x,int *y)
{
	if(a==NULL||n<=1)
		return;
	int *b=new int[sum+1];
	for(int i=0;i<=sum;i++)
	{
		b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(b[sum-a[i]]==1)
		{
			*x=sum-a[i];
			*y=a[i];
			break;
		}
		if(a[i]<sum)
			b[a[i]]=1;
	}
	delete []b;
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



/**********红黑树C++实现*********************************
#include<vector>
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=100):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
		return;
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}
const bool red=true;
const bool black=false;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
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
		void fun();
	private:
		void insertFixup(RBNode *pnode);
		void deleteFixup(RBNode *pnode);
		RBNode *left_rotate(RBNode *a);
		RBNode *right_rotate(RBNode *a);
		RBNode *createNode(int key);
		void destroy(RBNode *pnode);
		RBNode *root;
		RBNode *m_null;
		
};
RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
}
RBTree::~RBTree()
{
	destroy(root);
	root=NULL;
	delete m_null;
	m_null=NULL;
}
void RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *parent=m_null;
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
		{
			return;
		}
		else if(p->key>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	RBNode *newnode=createNode(key);
	if(parent==m_null)
	{
		root=newnode;
		root->color=black;
	}
	else
	{
		if(parent->key>key)
		{
			parent->llink=newnode;			
		}
		else
		{
			parent->rlink=newnode;
		}
		newnode->parent=parent;
		insertFixup(newnode);
	}
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(parent==grandparent->llink)
		{
			RBNode *uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				parent->color=black;
				uncle->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(pnode==parent->rlink)
				{
					pnode=left_rotate(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				right_rotate(grandparent);
			}
		}
		else
		{
			RBNode *uncle=grandparent->llink;
			if(uncle->color==red)
			{
				parent->color=black;
				uncle->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(pnode==parent->llink)
				{
					pnode=right_rotate(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				left_rotate(grandparent);
			}
		}
	}
	root->color=black;
}
void RBTree::deleteNode(int key)
{
	RBNode *delNode=root;
	while(delNode!=m_null)
	{
		if(delNode->key==key)
		{
			break;
		}
		else if(delNode->key>key)
		{
			delNode=delNode->llink;
		}
		else
		{
			delNode=delNode->rlink;
		}
	}
	if(delNode==m_null)
	{
		return;
	}
	RBNode *realDel=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realDel=delNode->rlink;
		while(realDel->llink!=m_null)
			realDel=realDel->llink;
		replace=realDel->rlink;
		delNode->key=realDel->key;
	}
	if(realDel==root)
	{
		root=replace;
		replace->parent=m_null;
	}
	else
	{
		if(realDel->parent->llink==realDel)
			realDel->parent->llink=replace;
		else
			realDel->parent->rlink=replace;
		replace->parent=realDel->parent;
	}
	if(realDel->color==black)
		deleteFixup(replace);
	delete realDel;
	realDel=NULL;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==black)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				parent->color=red;
				slibing->color=black;
				left_rotate(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->color=red;
					slibing->llink->color=black;
					right_rotate(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				slibing->rlink->color=black;
				parent->color=black;
				left_rotate(parent);
				p=root;
			}
		}
		else
		{
			slibing=parent->llink;
			if(slibing->color==red)
			{
				parent->color=red;
				slibing->color=black;
				right_rotate(parent);
				slibing=parent->llink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color==black)
				{
					slibing->color=red;
					slibing->rlink->color=black;
					left_rotate(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				slibing->llink->color=black;
				parent->color=black;
				right_rotate(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::left_rotate(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(a==root)
	{
		root=b;
		b->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
		{
			a->parent->llink=b;
		}
		else
		{
			a->parent->rlink=b;
		}
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::right_rotate(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(a==root)
	{
		root=b;
		b->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
		{
			a->parent->llink=b;
		}
		else
		{
			a->parent->rlink=b;
		}
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode *pnode)
{
	if(pnode==m_null)
		return;
	destroy(pnode->llink);
	destroy(pnode->rlink);
	delete pnode;
	pnode=m_null;
}
void RBTree::preOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void RBTree::postOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=m_null;
		}
	}
	cout<<endl;
}
void RBTree::fun()
{
	vector<RBNode*> vec;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!vec.empty())
	{
		while(p!=m_null)
		{
			vec.push_back(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
			{
				p=pp;
			}
		}
		p=vec.back();
		vec.pop_back();
		
		if(p->llink==m_null&&p->rlink==m_null)
		{
			int num=0;
			for(vector<RBNode*>::iterator iter=vec.begin();iter!=vec.end();++iter)
			{
				cout<<(*iter)->key<<' ';
				if((*iter)->color==black)
					num++;
			}
			if(p->color==black)
				num++;
			cout<<p->key<<":"<<num<<endl;
		}

		if(!vec.empty()&&vec.back()->llink==p)
		{
			p=vec.back()->rlink;
		}
		else
		{
			p=m_null;
		}
	}
}
int main()
{
	RBTree tree;
	int key;
	while(cin>>key)
	{
		tree.insertNode(key);
	}
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	cout<<"=============================="<<endl;
	tree.fun();
	return 0;
}
*/



/*
#include<vector>
#include<string.h>
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=100):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
		return;
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}

template<typename T>
class queue
{
	public:
		queue(int i);
		~queue();
		bool empty();
		bool full();
		void push(const T &obj);
		T front();
		void pop();
	private:
		T *data;
		int M;
		int f,r;
};

template<typename T>
queue<T>::queue(int i=20):M(i)
{
	data=new T[M];
	f=r=0;
}

template<typename T>
queue<T>::~queue()
{
	delete []data;
}

template<typename T>
bool queue<T>::empty()
{
	return f==r;
}

template<typename T>
bool queue<T>::full()
{
	return (r+1)%M==f;
}

template<typename T>
void queue<T>::push(const T &obj)
{
	if(full())
	{
		//cout<<"queue is full"<<endl;
		//return;
		T *buf=new T[2*M];
		if(f==0)
		{
			memcpy((char*)buf,(char*)data,(M-1)*sizeof(T));
		}
		else
		{
			memcpy((char*)buf,(char*)&data[f],(M-f)*sizeof(T));
			memcpy((char*)(buf+M-f),(char*)data,(f-1)*sizeof(T));
		}
		f=0;
		r=M-1;
		M*=2;
		T *temp=buf;
		buf=data;
		data=temp;
		delete []buf;
	}
	data[r]=obj;
	r=(r+1)%M;
}

template<typename T>
T queue<T>::front()
{
	if(empty())
		return T();
	return data[f];
}

template<typename T>
void queue<T>::pop()
{
	if(empty())
		return;
	f=(f+1)%M;
}
const bool red=true;
const bool black=false;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
};
class RBTree
{
	public:
		RBTree();
		~RBTree();
		int insertNode(int key);
		void deleteNode(int key);
		void preOrder();
		void inOrder();
		void postOrder();
		int fun();
		void width_depth(int &width,int &depth);
	private:
		void insertFixup(RBNode *pnode);
		void deleteFixup(RBNode *pnode);
		RBNode *rotate_left(RBNode *a);
		RBNode *rotate_right(RBNode *a);
		RBNode *createNode(int key);
		void destroy(RBNode **ppnode);
		RBNode *root;
		RBNode *m_null;
};
RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
}
RBTree::~RBTree()
{
	if(root!=m_null)
		destroy(&root);
	root=NULL;
	delete m_null;
	m_null=NULL;
}
int RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *parent=m_null;
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
			return -1;
		else if(p->key>key)
			p=p->llink;
		else
			p=p->rlink;
	}
	RBNode *newnode=createNode(key);
	if(parent==m_null)
	{
		root=newnode;
		root->color=black;
		root->parent=m_null;
	}
	else 
	{	
		if(parent->key>key)
			parent->llink=newnode;
		else
			parent->rlink=newnode;
		newnode->parent=parent;
		insertFixup(newnode);
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(grandparent->llink==parent)
		{
			RBNode *uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->rlink==pnode)
				{
					pnode=rotate_left(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle=grandparent->llink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->llink==pnode)
				{
					pnode=rotate_right(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_left(grandparent);
			}
		}
	}
	root->color=black;
}

void RBTree::deleteNode(int key)
{
	RBNode *delNode=root;
	while(delNode!=m_null)
	{
		if(delNode->key==key)
			break;
		else if(delNode->key>key)
			delNode=delNode->llink;
		else
			delNode=delNode->rlink;
	}
	if(delNode==m_null)
		return;
	RBNode *realDel=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realDel=delNode->rlink;
		while(realDel->llink!=m_null)
			realDel=realDel->llink;
		replace=realDel->rlink;
		delNode->key=realDel->key;
	}
	if(realDel==root)
	{
		root=replace;
		replace->parent=m_null;
	}
	else
	{
		if(realDel->parent->llink==realDel)
			realDel->parent->llink=replace;
		else
			realDel->parent->rlink=replace;
		replace->parent=realDel->parent;
	}
	if(realDel->color==black)
		deleteFixup(replace);
	delete realDel;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==black)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_left(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->color=red;
					slibing->llink->color=black;
					rotate_right(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				slibing->rlink->color=black;
				parent->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else
		{
			slibing=parent->llink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=parent->llink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color==black)
				{
					slibing->color=red;
					slibing->rlink->color=black;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				slibing->llink->color=black;
				parent->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}

RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(a==root)
	{
		root=b;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(a==root)
	{
		root=b;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode **ppnode)
{
	if(ppnode==NULL||*ppnode==m_null)
		return;
	destroy(&(*ppnode)->llink);
	destroy(&(*ppnode)->rlink);
	delete *ppnode;
	*ppnode=m_null;
}
void RBTree::preOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void RBTree::postOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		if(!st.empty()&&st.top()->llink==p)
			p=st.top()->rlink;
		else
			p=m_null;
	}
	cout<<endl;
}
int RBTree::fun()
{
	vector<RBNode*> vec;
	RBNode *p=root;
	RBNode *pp=m_null;
	int black_num=0;
	int buf=0;
	while(p!=m_null||!vec.empty())
	{
		while(p!=m_null)
		{
			vec.push_back(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=vec.back();
		vec.pop_back();
		if(p->llink==m_null&&p->rlink==m_null)
		{
			cout<<vec.size()+1<<' ';
			black_num=0;
			for(vector<RBNode*>::iterator iter=vec.begin();iter!=vec.end();++iter)
			{
				if((*iter)->color==black)
					black_num++;
			}
			if(p->color==black)
				black_num++;
			if(buf==0)
				buf=black_num;
			else if(black_num!=buf)
				return 0;
		}
		if(!vec.empty()&&vec.back()->llink==p)
			p=vec.back()->rlink;
		else
			p=m_null;
	}
	cout<<endl;
	return buf;
}

void RBTree::width_depth(int &width,int &depth)
{
	if(root==m_null)
		return;
	queue<RBNode*> qu;
	RBNode *p=root;
	qu.push(p);
	int last=1;
	int buf;
	width=1;
	depth=0;
	while(!qu.empty())
	{
		buf=0;
		while(last--)
		{
			p=qu.front();
			qu.pop();
			if(p->llink!=m_null)
			{
				qu.push(p->llink);
				buf++;
			}
			if(p->rlink!=m_null)
			{
				qu.push(p->rlink);
				buf++;
			}
		}
		last=buf;
		if(buf>width)
		{
			width=buf;
		}
		depth++;
	}
}
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
int main()
{
	RBTree tree;
	//int key;
	//while(cin>>key)
	//{
		//tree.insertNode(key);
	//}
	//for(int i=1;i<=1000;i++)
		//tree.insertNode(i);
	int num=0;
	while(num<10000)
	{
		if(tree.insertNode(random(10000))==0)
			num++;
	}
	//tree.preOrder();
	tree.inOrder();
	//tree.postOrder();
	cout<<"========================================="<<endl;
	int width,depth;
	tree.width_depth(width,depth);
	cout<<"width:"<<width<<"  depth:"<<depth<<endl;
	cout<<"========================================="<<endl;
	if(tree.fun()==0)
		cout<<"wrong"<<endl;
	else
		cout<<tree.fun()<<" black"<<endl;
	int key;
	while(cin>>key)
	{
		tree.deleteNode(key);
		//tree.preOrder();
		tree.inOrder();
		//tree.postOrder();
		if(tree.fun()==0)
			cout<<"wrong"<<endl;
		else
			cout<<tree.fun()<<" black"<<endl;
	}
	
	return 0;
}
*/


/*
#include<string.h>
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));
		
		T *tmp=buf;
		buf=data;
		data=tmp;
		M*=2;
		delete []buf;
	}
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
	{
		return T();
	}
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
	{
		return;
	}
	t--;
}
const bool red=true;
const bool black=false;
struct RBNode 
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
};
class RBTree
{
	public:
		RBTree();
		~RBTree();
		int insertNode(int key);
		void deleteNode(int key);
		void preOrder();
		void inOrder();
		void postOrder();
	private:
		void insertFixup(RBNode *pnode);
		void deleteFixup(RBNode *pnode);
		RBNode *rotate_left(RBNode *a);
		RBNode *rotate_right(RBNode *b);
		RBNode *createNode(int key);
		void destroy(RBNode **ppnode);
		RBNode *root;
		RBNode *m_null;
};
RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
}
RBTree::~RBTree()
{
	if(root!=m_null)
		destroy(&root);
	root=NULL;
	delete m_null;
	m_null=NULL;
}
int RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *parent=m_null;
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
		{
			return -1;
		}
		else if(p->key>key)
		{
			p=p->llink;
		}
		else
		{
			p=p->rlink;
		}
	}
	RBNode *newnode=createNode(key);
	if(parent==m_null)
	{
		root=newnode;
		root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(parent->key>key)
		{
			parent->llink=newnode;
		}
		else
		{
			parent->rlink=newnode;
		}
		newnode->parent=parent;
		insertFixup(newnode);
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(grandparent->llink==parent)
		{
			RBNode *uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(pnode==parent->rlink)
				{
					pnode=rotate_left(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle=grandparent->llink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(pnode==parent->llink)
				{
					pnode=rotate_right(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_left(grandparent);
			}
		}
	}
	root->color=black;
}
	

void RBTree::deleteNode(int key)
{
	RBNode *delNode=root;
	while(delNode!=m_null)
	{
		if(delNode->key==key)
		{
			break;
		}
		else if(delNode->key>key)
		{
			delNode=delNode->llink;
		}
		else
		{
			delNode=delNode->rlink;
		}
	}
	if(delNode==m_null)
	{
		return;
	}
	RBNode *realDel=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realDel=delNode->rlink;
		while(realDel->llink!=m_null)
			realDel=realDel->llink;
		replace=realDel->rlink;
		delNode->key=realDel->key;
	}
	if(realDel==root)
	{
		root=replace;
		replace->parent=m_null;
	}
	else
	{
		if(realDel->parent->llink==realDel)
			realDel->parent->llink=replace;
		else
			realDel->parent->rlink=replace;
		replace->parent=realDel->parent;
	}
	if(realDel->color==black)
	{
		deleteFixup(replace);
	}
	delete realDel;
	
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==red)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_left(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->llink->color=black;
					slibing->color=red;
					rotate_right(slibing);
					slibing=slibing->parent;
				}	
				slibing->color=parent->color;
				slibing->rlink->color=black;
				parent->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color==black)
				{
					slibing->rlink->color=black;
					slibing->color=red;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				slibing->llink->color=black;
				parent->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(a==root)
	{
		root=b;
		b->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(a==root)
	{
		root=b;
		b->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode **ppnode)
{
	if(ppnode==NULL||*ppnode==m_null)
		return;
	destroy(&(*ppnode)->llink);
	destroy(&(*ppnode)->rlink);
	delete *ppnode;
	*ppnode=m_null;
}
void RBTree::preOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void RBTree::postOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=m_null;
		}
	}
	cout<<endl;
}
#include<stdio.h>
#include<stdlib.h>
#define random(i) (rand()%i)
int main()
{
	
	RBTree tree;
	int num=0;
	while(num<1000)
	{
		if(tree.insertNode(random(1000))==0)
			num++;
	}
	tree.preOrder();
	cout<<"======================"<<endl;
	tree.inOrder();
	cout<<"======================"<<endl;
	tree.postOrder();
	int key;
	while(cin>>key)
	{
		tree.deleteNode(key);
		tree.preOrder();
		cout<<"======================"<<endl;
		tree.inOrder();
		cout<<"======================"<<endl;
		tree.postOrder();
	}
	return 0;
}
*/

/*
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=k;i<n;i+=k)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)
	{
		shell(a,n,k);
		k/=2;
	}
}
void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
			{
				x=j;
			}
		}
		if(x!=i)
		{
			a[x]^=a[i];
			a[i]^=a[x];
			a[x]^=a[i];
		}
	}
}
void heap(int *a,int n,int i)
{
	int child;	
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child<n-1&&a[child]<a[child+1])
		{
			child++;
		}
		if(a[i]<a[child])
		{
			a[i]^=a[child];
			a[child]^=a[i];
			a[i]^=a[child];
		}
		else
			break;
	}
}
void heapSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=n/2-1;i>=0;i--)
	{
		heap(a,n,i);
	}
	for(int i=n-1;i>0;i--)
	{	
		a[i]^=a[0];
		a[0]^=a[i];
		a[i]^=a[0];
		heap(a,i,0);
	}
}
void QiPaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i=0;
	int j=n-1;
	int x=a[0];
	while(i<j)
	{
		for(;i<j;j--)
		{
			if(a[j]<x)
			{
				a[i++]=a[j];
				break;
			}
		}
		for(;i<j;i++)
		{
			if(a[i]>x)
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
}
void mergePass(int *a,int *b,int n,int len)
{
	int i=0;
	while(i+2*len-1<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
	{
		merge(a,b,i,i+len-1,n-1);
	}
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int len=1;
	int *b=new int[n];
	while(len<n)
	{
		mergePass(a,b,n,len);
		len*=2;
		mergePass(b,a,n,len);
		len*=2;
	}
	delete []b;
}
#include<stdio.h>
#include<stdlib.h>
#define random(i) (rand()%i)
#define NUM 100000
int main()
{
	int buf[NUM]={0};
	int a[NUM]={0};
	int num=0;
	while(num<NUM)
	{
		int i=random(NUM);
		if(buf[i]==0)
		{
			a[num++]=i;
			buf[i]=1;
		}
	}
	for(int i=0;i<NUM;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	cout<<"=========================="<<endl;
	//insertSort(a,NUM);
	//shellSort(a,NUM);
	//selectSort(a,NUM);
	//heapSort(a,NUM);
	//QiPaoSort(a,NUM);
	//QSort(a,NUM);
	mergeSort(a,NUM);
	for(int i=0;i<NUM;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
*/
/*
int list(int *a,int n)
{
	int *dp=new int[n];
	int M=1;
	for(int i=0;i<n;i++)
		dp[i]=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>M)
		{
			M=dp[i];
		}
	}
	delete []dp;
	return M;
}
int main()
{
	int a[10]={1,20,3,3,7,6,7,8,9,10};
	cout<<list(a,10)<<endl;
	return 0;
}
*/
/*
int x[100];
int juedui(int x)
{
	int y=x>>31;
	return (x^y)-y;	
}
bool place(int k)
{
	int buf=0;
	for(int i=1;i<k;i++)
	{
		if(x[i]==x[k])
			return false;
		if(x[i]<x[k])
		{
			if(x[i]<buf)
				return false;
			else
				buf=x[i];
		}
	}
	return true;
}
int queue(int n)
{
	int k=1;
	int sum=0;
	int flag=0;
	while(k>=1)
	{
		x[k]++;
		while(x[k]<=n&&!place(k))
		{
			x[k]++;
		}
		if(x[k]<=n)
		{
			if(k==n)
			{
				for(int i=1;i<=n;i++)
					cout<<x[i]<<' ';
				cout<<endl;
			}
			else if(k<n)
			{
				k++;
			}
		}
		else
		{
			x[k]=0;
			k--;
		}
	}
	return sum;
}
int main()
{
	int test;
	while(cin>>test)
	{
		queue(test);
	}
	return 0;
}
*/



/*
void memcpy(void *dest,void *src,int n)
{
	char *pdest=(char*)dest;
	char *psrc=(char*)src;
	if(pdest>psrc&&pdest<psrc+n)
	{
		for(int i=n-1;i>=0;i--)
			pdest[i]=psrc[i];
	}
	else
	{
		for(int i=0;i<n;i++)
			pdest[i]=psrc[i];
	}
}
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	t=-1;
}
template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));
		T *tmp=buf;
		buf=data;
		data=tmp;
		M*=2;
		delete[]buf;
	}
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}
const bool red=false;
const bool black=true;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
}; 
class RBTree
{
	public:
		RBTree();
		~RBTree();
		int insertNode(int key);
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
		void destroy(RBNode **ppnode);
		RBNode *root;
		RBNode *m_null;
		
};
RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
}
RBTree::~RBTree()
{
	destroy(&root);
	root=NULL;
	delete m_null;
	m_null=NULL;
}
int RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *parent=m_null;
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
			return -1;
		else if(p->key>key)
			p=p->llink;
		else
			p=p->rlink;
	}
	RBNode *newnode=createNode(key);
	if(parent==m_null)
	{
		root=newnode;
		root->color=black;
	}
	else
	{
		if(parent->key>key)
			parent->llink=newnode;
		else
			parent->rlink=newnode;
		newnode->parent=parent;
		insertFixup(newnode);
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(grandparent->llink==parent)
		{
			RBNode *uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(pnode==parent->rlink)
				{
					pnode=rotate_left(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle=grandparent->llink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->llink==pnode)
				{
					pnode=rotate_right(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_left(grandparent);
			}
		}
	}
	root->color=black;
}
void RBTree::deleteNode(int key)
{
	RBNode *delNode=root;
	while(delNode!=m_null)
	{
		if(delNode->key==key)
			break;
		else if(delNode->key>key)
			delNode=delNode->llink;
		else
			delNode=delNode->rlink;
	}
	if(delNode==m_null)
		return;
	RBNode *realDel=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realDel=delNode->rlink;
		while(realDel->llink!=m_null)
			realDel=realDel->llink;
		replace=realDel->rlink;
		delNode->key=realDel->key;
	}
	if(realDel==root)
	{
		root=replace;
		root->parent=m_null;
	}
	else
	{
		if(realDel->parent->llink==realDel)
			realDel->parent->llink=replace;
		else
			realDel->parent->rlink=replace;
		replace->parent=realDel->parent;
	}
	if(realDel->color==black)
	{
		deleteFixup(replace);
	}
	delete realDel;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==red)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=p->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_left(parent);
				slibing=p->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->llink->color=black;
					slibing->color=red;
					rotate_right(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->rlink->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else
		{
			slibing=p->llink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=p->llink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color==black)
				{
					slibing->rlink->color=black;
					slibing->color=red;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->llink->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(a==root)
	{
		root=b;
		root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(a==root)
	{
		root=b;
		root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode **ppnode)
{
	if(ppnode==NULL||*ppnode==m_null)
		return;
	destroy(&(*ppnode)->llink);
	destroy(&(*ppnode)->rlink);
	delete *ppnode;
	*ppnode=m_null;
}
void RBTree::preOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}

void RBTree::postOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';	
		if(!st.empty()&&st.top()->llink==p)
			p=st.top()->rlink;
		else
			p=m_null;
	}
	cout<<endl;
}
#include<stdio.h>
#include<stdlib.h>
#define random(i) (rand()%i)
int main()
{
	RBTree tree;
	int num=0;
	while(num<1000)
	{
		if(tree.insertNode(random(1000))==0)
			num++;
	}
	tree.preOrder();
	cout<<"====================================="<<endl;
	tree.inOrder();
	cout<<"====================================="<<endl;
	tree.postOrder();
	cout<<"====================================="<<endl;
	return 0;
}
*/



/*
//------内存拷贝---------------------------------
void memcpy(void *dest,void *src,int len)
{
	char *pdest=(char*)dest;
	char *psrc=(char*)src;
	if(psrc>pdest&&psrc<pdest+len)
	{
		for(int i=len-1;i>=0;i--)
		{
			pdest[i]=psrc[i];
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			pdest[i]=psrc[i];
		}
	}
}
//----------栈的c++实现---------------------------------------
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));
		T *tmp=buf;
		buf=data;
		data=tmp;
		M*=2;
		delete []buf;
	}
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
	{
		return T();
	}
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
	{
		return;
	}
	t--;
}
//-------------循环队列的C++实现----------------------------------
template<typename T>
class queue
{
	public:
		queue(int i);
		~queue();
		bool empty();
		bool full();
		void push(const T &obj);
		T front();
		void pop();
	private:
		T *data;
		int M;
		int f;
		int r;
};

template<typename T>
queue<T>::queue(int i=10):M(i)
{
	data=new T[M];
	f=0;
	r=0;
}

template<typename T>
queue<T>::~queue()
{
	delete []data;
}

template<typename T>
bool queue<T>::empty()
{
	return r==f;
}

template<typename T>
bool queue<T>::full()
{
	return (r+1)%M==f;
}

template<typename T>
void queue<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		if(f==0)
		{
			memcpy(buf,&data[f],(M-1)*sizeof(T));
		}
		else
		{
			int len=M-f;
			memcpy((char*)buf,(char*)&data[f],len*sizeof(T));
			memcpy((char*)&buf[len],(char*)data,(r)*sizeof(T));

		}
		T *tmp=buf;
		buf=data;
		data=tmp;
		f=0;
		r=M-1;
		M*=2;
		delete []buf;
	}
	data[r]=obj;
	r=(r+1)%M;
}
template<typename T>
T queue<T>::front()
{
	if(empty())
	{
		return T();
	}
	return data[f];
}

template<typename T>
void queue<T>::pop()
{
	if(empty())
	{
		return;
	}
	f=(f+1)%M;
}
//------红黑树-------------------------------------
const bool red=false;
const bool black=true;
struct RBNode                                      //红黑树结点
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
};
class RBTree                                       //定义红黑树类
{
	public:
		RBTree();
		~RBTree();
		int insertNode(int key);                   //插入结点
		void deleteNode(int key);                  //删除结点
		void preOrder();                           //前序遍历
		void inOrder();                            //中序遍历
		void postOrder();                          //后序遍历
		void frontOrder();                         //广度优先遍历
		void convert2link();                       //递归转换成排序链表
		void nConvert2link();                      //非递归转换成排序链表
		void printLink();                          //打印链表
		void refresh();                            //
		void construct();                          //根据前序遍历和中序遍历重建二叉树
		void width_depth(int &width,int &depth);   //二叉树的宽度和深度
	private:
		RBNode *constructCore(int *preStart,int *preEnd,int *inStart,int *inEnd);
		void convertCore(RBNode *pnode,RBNode **plast);
		void insertFixup(RBNode *pnode);
		void deleteFixup(RBNode *pnode);
		RBNode *rotate_left(RBNode *a);
		RBNode *rotate_right(RBNode *a);
		RBNode *createNode(int key);
		void destroy(RBNode **ppnode);
		void destroyLink();
		RBNode *root;
		RBNode *m_null;
		int pre[1000];
		int in[1000];
		int len;
		bool isLink;
};

RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
	isLink=false;
}
RBTree::~RBTree()
{
	if(isLink)
	{
		destroyLink();
	}
	else
	{
		destroy(&root);
	}
	root=NULL;
	delete m_null;
	m_null=NULL;
}
int RBTree::insertNode(int key)
{
	if(isLink)
		return -1;
	RBNode *p=root;
	RBNode *parent=m_null;
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
			return -1;
		else if(p->key>key)
			p=p->llink;
		else
			p=p->rlink;
	}
	RBNode *newNode=createNode(key);
	if(parent==m_null)
	{
		root=newNode;
		root->color=black;
	}
	else
	{
		if(parent->key>key)
			parent->llink=newNode;
		else
			parent->rlink=newNode;
		newNode->parent=parent;
		insertFixup(newNode);
			
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(grandparent->llink==parent)
		{
			RBNode *uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->rlink==pnode)
				{
					pnode=rotate_left(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle=grandparent->llink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->llink==pnode)
				{
					pnode=rotate_right(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_left(grandparent);
			}
		}
	}
	root->color=black;
}
void RBTree::deleteNode(int key)
{
	if(isLink)
		return;
	RBNode *delNode=root;
	while(delNode!=NULL)
	{
		if(delNode->key==key)
			break;
		else if(delNode->key>key)
			delNode=delNode->llink;
		else
			delNode=delNode->rlink;
	}
	if(delNode==m_null)
		return;
	RBNode *realNode=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realNode=delNode->rlink;
		while(realNode->llink!=m_null)
			realNode=realNode->llink;
		replace=realNode->rlink;
		delNode->key=realNode->key;
	}
	if(realNode->color==black)
		deleteFixup(replace);
	delete realNode;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==red)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_left(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->llink->color=black;
					slibing->color=red;
					rotate_right(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->rlink->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else
		{
			slibing=parent->llink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=parent->llink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color==black)
				{
					slibing->rlink->color=black;
					slibing->color=red;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->llink->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(a==root)
	{
		root=b;
		root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(a==root)
	{
		root=b;
		root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode **ppnode)
{
	if(ppnode==NULL||*ppnode==m_null)
	{
		return;
	}
	destroy(&(*ppnode)->llink);
	destroy(&(*ppnode)->rlink);
	delete *ppnode;
	*ppnode=m_null;
}
void RBTree::destroyLink()
{
	RBNode *p=m_null;
	while(root!=m_null)
	{
		p=root->rlink;
		delete root;
		root=p;
	}
}
void RBTree::preOrder()
{
	if(root==m_null||isLink)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout.fill('0');
			cout.width(3);
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null||isLink)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}	
		p=st.top();
		st.pop();
		cout.fill('0');
		cout.width(3);
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void RBTree::postOrder()
{
	if(root==m_null||isLink)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout.fill('0');
		cout.width(3);
		cout<<p->key<<' ';
		if(!st.empty()&&st.top()->llink==p)
			p=st.top()->rlink;
		else
			p=m_null;
	}
	cout<<endl;

}
void RBTree::frontOrder()
{
	if(root==m_null)
		return;
	queue<RBNode*> qu;
	RBNode *p=root;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		if(p!=m_null)
		{
			cout.fill('0');
			cout.width(3);
			cout<<p->key<<' ';
			qu.push(p->llink);
			qu.push(p->rlink);
		}
	}
	cout<<endl;
}
void RBTree::convert2link()
{
	if(root==NULL||root==m_null)
		return;
	RBNode *last=m_null;
	convertCore(root,&last);
	while(root->llink!=m_null)
		root=root->llink;
	isLink=true;
}
void RBTree::convertCore(RBNode *pnode,RBNode **plast)
{
	if(pnode==m_null)
		return;
	
	convertCore(pnode->llink,plast);

	if(*plast!=m_null)
		(*plast)->rlink=pnode;
	pnode->llink=*plast;
	*plast=pnode;

	convertCore(pnode->rlink,plast);
}	
void RBTree::nConvert2link()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *last=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		
		if(last!=m_null)
			last->rlink=p;
		p->llink=last;
		last=p;
		
		p=p->rlink;
	}
	while(root->llink!=m_null)
		root=root->llink;
	isLink=true;
}
void RBTree::printLink()
{
	
	while(root!=m_null)
	{
		cout.fill('0');
		cout.width(3);
		cout<<root->key<<' ';
		root=root->rlink;
	}
	cout<<endl;
}
void RBTree::refresh()
{
	if(root==m_null||root==NULL)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	int i=0;
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			pre[i++]=p->key;
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	p=root;
	i=0;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		in[i++]=p->key;
		p=p->rlink;
	}
	len=i;
}
void RBTree::construct()
{
	if(len<=0)
		return;
	destroyLink();
	root=constructCore(pre,pre+len-1,in,in+len-1);
	isLink=false;
}
RBNode *RBTree::constructCore(int *preStart,int *preEnd,int *inStart,int *inEnd)
{
	int rootValue=*preStart;
	RBNode *root0=createNode(rootValue);

	int leftLen=0;
	while(inStart[leftLen]!=rootValue)
	{
		leftLen++;
	}
	if(leftLen>0)
	{
		root0->llink=constructCore(preStart+1,preStart+leftLen,inStart,inStart+leftLen-1);
	}
	if(rootValue!=*inEnd)
	{
		root0->rlink=constructCore(preStart+leftLen+1,preEnd,inStart+leftLen+1,inEnd);
	}
	return root0;
}

void RBTree::width_depth(int &width,int &depth)
{
	if(root==m_null)
		return;
	queue<RBNode*> qu;
	RBNode *p=root;
	qu.push(p);
	int last=1;
	depth=0;
	width=0;
	while(!qu.empty())
	{
		int buf=0;
		while(last--)
		{
			p=qu.front();
			qu.pop();
			if(p->llink!=m_null)
			{
				qu.push(p->llink);
				buf++;
			}
			if(p->rlink!=m_null)
			{
				qu.push(p->rlink);
				buf++;
			}
		}
		if(buf>width)
		{
			width=buf;
		}
		last=buf;
		depth++;
	}
}
#include<stdio.h>
#include<stdlib.h>
#define NUM 100
#define random(i) (rand()%i)

int main()
{
	RBTree tree;
	int num=0;
	while(num<NUM)
	{
		if(tree.insertNode(random(NUM))==0)
			num++;
	}	
	int width=0;
	int depth=0;
	tree.width_depth(width,depth);
	cout<<"width:"<<width<<"  depth:"<<depth<<endl;
	cout<<"=================preOrder=================="<<endl;
	tree.preOrder();
	cout<<"=================inOrder==================="<<endl;
	tree.inOrder();
	cout<<"=================frontOrder================"<<endl;
	tree.frontOrder();
	cout<<"=================convert to link==========="<<endl;
	tree.refresh();
	tree.nConvert2link();
	tree.printLink();
	cout<<"==========construct from pre and in========="<<endl;
	tree.construct();
	tree.preOrder();
	cout<<"===================================="<<endl;
	tree.inOrder();
	cout<<"===================================="<<endl;
	return 0;
}
*/




/************************************************
int x[100];
bool place(int k)
{
	int buf=0;
	for(int i=1;i<k;i++)
	{
		if(x[i]==x[k])
			return false;
		if(x[i]>x[k])
		{
			for(int j=i+1;j<k;j++)
			{
				if(x[j]<x[k])
					return false;
			}
		}
	}
	return true;
}
void train(int n)
{
	int k=1;
	int num=0;
	while(k>=1)
	{
		x[k]++;
		while(x[k]<=n&&!place(k))
			x[k]++;
		if(x[k]<=n)
		{
			if(k==n)
			{
				for(int i=1;i<=n;i++)
					cout<<x[i]<<' ';
				cout<<endl;
				num++;
			}
			else
				k++;
		}
		else
		{
			x[k]=0;
			k--;
		}
	}
	cout<<num<<endl;
}
int main()
{
	int n;
	while(cin>>n)
		train(n);
	return 0;
}
*/

/********
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=k;i<n;i+=k)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)
	{
		shell(a,n,k);
		k/=2;
	}
}
void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
				x=j;
		}
		if(x!=i)
		{
			a[x]^=a[i];
			a[i]^=a[x];
			a[x]^=a[i];
		}
	}
}
void heap(int *a,int n,int i)
{
	int child;
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child<n-1&&a[child]<a[child+1])
			child++;
		if(a[i]<a[child])
		{
			a[i]^=a[child];
			a[child]^=a[i];
			a[i]^=a[child];
		}
		else
			break;
	}
}
void heapSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=n/2-1;i>=0;i--)
	{
		heap(a,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		a[i]^=a[0];
		a[0]^=a[i];
		a[i]^=a[0];
		heap(a,i,0);
	}
}
void QipaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
		if(i%1000==0)
		cout<<i<<endl;
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i=0;
	int j=n-1;
	int x=a[0];
	while(i<j)
	{
		for(;i<j;j--)
		{
			if(a[j]<x)
			{
				a[i++]=a[j];
				break;
			}
		}
		for(;i<j;i++)
		{
			if(a[i]>x)
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=m)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
}
void mergePass(int *a,int *b,int n,int len)
{
	int i=0;
	while(i+2*len-1<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
	{
		merge(a,b,i,i+len-1,n-1);
	}
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int len=1;
	int *b=new int[n];
	while(len<n)
	{
		mergePass(a,b,n,len);
		len*=2;
		mergePass(b,a,n,len);
		len*=2;
	}
	delete []b;
}
#include<stdio.h>
#include<stdlib.h>
#define NUM 1000000
#define random(i) (rand()%i)
int a[NUM];
int flag[NUM];
int main()
{
	int num=0;
	while(num<NUM)
	{
		int i=random(NUM);
		if(flag[i]==0)
		{
			flag[i]=1;
			a[num++]=i;
		}
	}
	//insertSort(a,NUM);
	//shellSort(a,NUM);
	//selectSort(a,NUM);
	//heapSort(a,NUM);
	QipaoSort(a,NUM);
	//QSort(a,NUM);
	//mergeSort(a,NUM);
	for(int i=0;i<NUM;i++)
	{
		cout.fill('0');
		cout.width(3);
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
*/

/*
int numof1(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n&=n-1;
	}
	return count;
}
bool fun(int n)
{
	return (n&(n-1))==0;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<numof1(n)<<"  "<<fun(n)<<endl;
	}
	return 0;
}
*/

/****
bool equal(double x,double y)
{
	if(x-y>-0.000001&&x-y<0.000001)
		return true;
	else
		return false;
}
int abs(int x)
{
	int y=x>>31;
	return (x^y)-y;
}
double powerUnsigned(double base,unsigned int exponent)
{
	if(exponent==0)
		return 1.0;
	else if(exponent==1)
		return base;
	double result=powerUnsigned(base,exponent>>1);
	result*=result;
	if(exponent&1==1)
		result*=base;
	return result;
}
double power(double base,int exponent)
{
	if(equal(base,0.0))
	{
		if(exponent<0)
		{
			cout<<"error"<<endl;
		}
		return 0.0;
	}
	unsigned int absExponent=abs(exponent);
	double result=powerUnsigned(base,absExponent);
	if(exponent<0)
		result=1.0/result;
	return result;
}
int main()
{
	double base;
	int exponent;
	while(cin>>base>>exponent)
	{
		cout<<power(base,exponent)<<endl;
	}
	return 0;
}
*/


/*
#include<string.h>
bool inc(char *num)
{
	int len=strlen(num);
	for(int i=len-1;i>=0;i--)
	{
		if(num[i]=='9')
		{
			if(i==0)
			{
				return false;
			}
			num[i]='0';
		}
		else
		{
			num[i]++;
			break;
		}
	}
	return true;
}
void printNum(char *num)
{
	cout<<num<<endl;
}
void print(int n)
{
	char *number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';
	while(inc(number))
	{
		printNum(number);
	}
	delete []number;
}
int main()
{
	int n;
	while(cin>>n)
		print(n);
	return 0;
}
*/
/*********************8
void fun(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
			a[j++]=a[i];
	}
	while(j<n)
	{
		a[j]=0;
		j++;
	}
}
int main()
{
	int a[10]={1,0,2,0,3,0,4,0,5,0};
	fun(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
*/

/*
void fun(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	
	int i=0;
	int j=n-1;
	while(i<j)
	{
		while(i<j&&(a[i]&1)==1)
		{
			i++;
		}
		while(i<j&&(a[j]&1)==0)
		{
			j--;
		}
		if(i<j)
		{
			a[i]^=a[j];
			a[j]^=a[i];
			a[i]^=a[j];
		}
	}
}
int find(int *a,int n,int key)       //二分查找
{
	if(a==NULL||n<=0)
		return -1;
	int begin=0;
	int end=n-1;
	int mid=0;
	while(begin<=end)
	{
		mid=(begin+end)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]<key)
		{
			begin=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	return -1;
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int key;
	while(cin>>key)
		cout<<find(a,10,key)<<endl;
	fun(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
*/
/*****
struct Node
{
	int key;
	Node *next;
};
Node *createLink(int *a,int n)
{
	if(a==NULL||n<=0)
		return NULL;
	Node *link=NULL;
	Node *p=NULL;
	for(int i=0;i<n;i++)
	{
		Node *newNode=new Node;
		newNode->key=a[i];
		newNode->next=NULL;
		if(p==NULL)
		{
			link=newNode;
		}
		else
		{
			p->next=newNode;
		}
		p=newNode;
	}
	return link;
}
void destroyLink(Node **plink)
{
	if(plink==NULL||*plink==NULL)
		return;
	Node *p=NULL;
	while(*plink!=NULL)
	{
		p=(*plink)->next;
		delete *plink;
		*plink=p;
	}
}
Node *mergeCore(Node *a,Node *b)
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	Node *newlink=NULL;
	if(a->key<b->key)
	{
		newlink=a;
		newlink->next=mergeCore(a->next,b);
	}
	else
	{
		newlink=b;
		newlink->next=mergeCore(a,b->next);
	}
	return newlink;
}
Node *merge(Node **pa,Node **pb)
{
	if(pa==NULL||pb==NULL)
		return NULL;
	Node *link=mergeCore(*pa,*pb);
	*pa=NULL;
	*pb=NULL;
	return link;
}
void print(Node *link)
{
	while(link)
	{
		cout<<link->key<<' ';
		link=link->next;
	}
	cout<<endl;
}
int main()
{
	int a[5]={1,3,5,7,9};
	int b[5]={2,4,6,8,10};
	Node *alink=createLink(a,5);
	Node *blink=createLink(b,5);
	print(alink);
	print(blink);
	Node *clink=merge(&alink,&blink);
	print(clink);
	destroyLink(&clink);
	return 0;
}
*/


/**************************
void *memcpy(void *dest,void *scr,int len)
{
	char *pdest=(char*)dest;
	char *pscr=(char*)scr;
	if(pscr>pdest&&pdest+len>pscr)
	{
		for(int i=len-1;i>=0;i--)
		{
			pdest[i]=pscr[i];
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			pdest[i]=pscr[i];
		}
	}
	return pdest;
}

template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=100):M(i)
{
	data=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete[]data;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));
		
		T *tmp=buf;
		buf=data;
		data=tmp;

		M*=2;
		delete[]buf;
	}
	data[++t]=obj;
}

template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}

struct BinTreeNode
{
	int key;
	BinTreeNode *llink,*rlink;
};
BinTreeNode *constructCore(int *preStart,int *preEnd,int *inStart,int *inEnd)
{
	int rootValue=*preStart;
	BinTreeNode *root=new BinTreeNode;
	root->key=rootValue;
	root->llink=root->rlink=NULL;

	int leftLen=0;
	while(inStart[leftLen]!=rootValue)
		leftLen++;
	if(leftLen>0)
	{
		root->llink=constructCore(preStart+1,preStart+leftLen,inStart,inStart+leftLen-1);
	}
	if(*inEnd!=rootValue)
	{
		root->rlink=constructCore(preStart+leftLen+1,preEnd,inStart+leftLen+1,inEnd);
	}
	return root;
}

BinTreeNode *construct(int *pre,int *in,int len)
{
	if(pre==NULL||in==NULL||len<0)
	{
		return NULL;
	}
	return constructCore(pre,pre+len-1,in,in+len-1);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void mirror(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	BinTreeNode *buf=tree->llink;
	tree->llink=tree->rlink;
	tree->rlink=buf;

	mirror(tree->llink);
	mirror(tree->rlink);
}
bool doesTree1haveTree2(BinTreeNode *root1,BinTreeNode *root2)
{
	if(root2==NULL)
		return true;
	if(root1==NULL)
		return false;
	if(root1->key!=root2->key)
		return false;
	return doesTree1haveTree2(root1->llink,root2->llink)&&doesTree1haveTree2(root1->rlink,root2->rlink);
}
bool tree2_sonof_tree1(BinTreeNode *tree1,BinTreeNode *tree2)
{
	if(tree1==NULL||tree2==NULL)
		return false;
	bool result=false;
	if(tree1->key==tree2->key)
		result=doesTree1haveTree2(tree1->llink,tree2->llink)&&doesTree1haveTree2(tree1->rlink,tree2->rlink);
	if(!result)
		result=tree2_sonof_tree1(tree1->llink,tree2);
	if(!result)
		result=tree2_sonof_tree1(tree1->rlink,tree2);
	return result;
}
bool rtree2_sonof_tree1(BinTreeNode *tree1,BinTreeNode *tree2)
{
	if(tree1==NULL||tree2==NULL)
		return false;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree1;
	st.push(tree1);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			if((p->key==tree2->key)&&doesTree1haveTree2(p->llink,tree2->llink)&&doesTree1haveTree2(p->rlink,tree2->rlink))
				return true;
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	return false;
}	
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
#include<vector>
void findPath(BinTreeNode *tree,int sum)
{
	if(tree==NULL)
		return;
	vector<BinTreeNode*> vec;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	int currentSum=0;
	while(p||!vec.empty())
	{
		while(p)
		{
			vec.push_back(p);
			currentSum+=p->key;
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
				p=pp;
		}
		p=vec.back();
		vec.pop_back();
		if(p->llink==NULL&&p->rlink==NULL&&currentSum==sum)
		{
			for(vector<BinTreeNode*>::iterator iter=vec.begin();iter!=vec.end();++iter)
				cout<<(*iter)->key<<' ';
			cout<<p->key<<endl;
		}
		currentSum-=p->key;
		
		if(!vec.empty()&&vec.back()->llink==p)
			p=vec.back()->rlink;
		else
			p=NULL;
	}
}
int main()
{
	int tree1pre[10]={1,2,4,8,5,2,3,6,7,9};
	int tree1in[10]={8,4,2,2,5,1,6,3,7,9};
	int tree2pre[4]={3,6,7,9};
	int tree2in[4]={6,3,7,9};
	BinTreeNode *tree1=construct(tree1pre,tree1in,10);
	BinTreeNode *tree2=construct(tree2pre,tree2in,4);
	findPath(tree1,10);
	cout<<"==================================="<<endl;
	mirror(tree1);
	mirror(tree2);
	preOrder(tree1);
	preOrder(tree2);
	cout<<rtree2_sonof_tree1(tree1,tree2)<<"   "<<tree2_sonof_tree1(tree1,tree2)<<endl;
	destroyTree(&tree1);
	destroyTree(&tree2);
}
*/




/*
void printMatrixCircle(int **matrix,int colums,int rows,int start)
{
	int endX=colums-1-start;
	int endY=rows-1-start;
	for(int i=start;i<=endX;i++)
	{
		cout<<matrix[start][i]<<' '; 
	}
	if(endY>start)
	{
		for(int j=start+1;j<=endY;j++)
			cout<<matrix[j][endX]<<' ';
	}
	if(endY>start&&endX>start)
	{
		for(int i=endX-1;i>=start;i--)
			cout<<matrix[endY][i]<<' ';
	}
	if(endY>start+1&&endX>start)
	{
		for(int j=endY-1;j>start;j--)
			cout<<matrix[j][start]<<' ';
	}
	cout<<endl;
}
void printMatrixClockwisely(int **matrix,int colums,int rows)
{
	if(matrix==NULL||colums<=0||rows<=0)
		return;
	int start=0;
	while(colums>2*start&&rows>2*start)
	{
		printMatrixCircle(matrix,colums,rows,start);
		start++;
	}
}
int main()
{
	int x,y;
	cin>>x>>y;
	int **matrix=new int*[y];
	for(int i=0;i<y;i++)
		matrix[i]=new int[x];
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			cin>>matrix[i][j];
		}
	}
	printMatrixClockwisely(matrix,x,y);
	return 0;
}
*/

/*
class A
{
	public:
		A(int i):a(i){}
		void fun() const
		{
			cout<<"fun"<<endl;
		}
	private:
		int a;
};
int main()
{
	const A obj(1);
	obj.fun();
}
*/


/************************************************8
#include<string.h>
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
		T min();
	private:
		T *data;
		T *min_buf;
		int M;
		int t;
};

template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	min_buf=new T[M];
	t=-1;
}

template<typename T>
stack<T>::~stack()
{
	delete[]data;
	data=NULL;
	delete[]min_buf;
	min_buf=NULL;
}

template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}

template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}

template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));

		T *tmp=buf;
		buf=data;
		data=tmp;

		memcpy(buf,min_buf,M*sizeof(T));

		tmp=buf;
		buf=min_buf;
		min_buf=tmp;

		M*=2;
		delete []buf;
	}
	int min_num=min();
	if(empty()||obj<min_num)
	{
		min_buf[++t]=obj;
	}
	else
	{
		min_buf[++t]=min_num;
	}
	data[t]=obj;
}

template<typename T>
T stack<T>::min()
{
	if(empty())
		return T();
	return min_buf[t];
}

template<typename T>
T stack<T>::top()
{
	if(empty())
		return T();
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
		return;
	t--;
}
int main()
{
	stack<int> st;
	int x;
	while(cin>>x)
		st.push(x);
	cin.clear();
	while(cin>>x)
	{
		cout<<"min number is:"<<st.min()<<endl;
st.pop();
	}
	return 0;
}
*/



/*
bool verify(int *a,int len)
{
	if(a==NULL||len<=0)
		return false;
	int root=a[len-1];
	int i=0;
	for(i=0;i<len-1;i++)
	{
		if(a[i]>root)
			break;
	}
	int j=i;
	while(j<len-1)
	{
		if(a[j]<root)
			return false;
		j++;
	}
	bool left=true;
	if(i>0)
		left=verify(a,i);
	bool right=true;
	if(i<len-1)
		right=verify(a+i,len-i-1);
	return left&&right;
}
int main()
{
	int a[7]={1,3,2,5,7,4,6};
	cout<<verify(a,7)<<endl;
	return 0;
}
*/
/*
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int get_maxSum(int *a,int n)
{
	if(a==NULL||n<=0)
		return -1;
	int maxSum=0x80000000;
	int curSum=0;
	for(int i=0;i<n;i++)
	{
		curSum+=a[i];	
		if(curSum<0)
			curSum=0;
		maxSum=max(maxSum,curSum);
	}
	return maxSum;
}
int get_maxProduct(int *a,int n)
{
	if(a==NULL||n<=0)
		return -1;
	int minProduct=1;
	int maxProduct=1;
	int result=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			int tmp=minProduct;
			minProduct=maxProduct*a[i];
			maxProduct=max(tmp*a[i],1);
		}
		else if(a[i]==0)
		{
			minProduct=1;
			maxProduct=1;
		}
		else
		{

			maxProduct*=a[i];
			minProduct=min(minProduct*a[i],1);
		}
		result=max(result,maxProduct);
	}
	return result;
}
int main()
{
	int a[8]={1,-2,3,10,-4,7,2,-5};
	cout<<get_maxSum(a,8)<<endl;
	cout<<get_maxProduct(a,8)<<endl;
	return 0;
}
*/

/*
int numof1(int n)
{
	int x=0;
	while(n)
	{
		n&=(n-1);
		x++;
	}
	return x;
}

int main()
{
	int n;
	while(cin>>n)
		cout<<numof1(n)<<endl;
	return 0;
}
*/


/*
void *memcpy(void *dest,void *src,int len)
{
	char *pdest=(char*)dest;
	char *psrc=(char*)src;
	if(pdest>psrc&&pdest<psrc+len)
	{
		for(int i=len-1;i>=0;i--)
		{
			pdest[i]=psrc[i];
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			pdest[i]=psrc[i];
		}
	}
	return pdest;
}
template<typename T>
class stack
{
	public:
		stack(int i);
		~stack();
		bool empty();
		bool full();
		void push(const T &obj);
		T top();
		void pop();
	private:
		T *data;
		int M;
		int t;
};
template<typename T>
stack<T>::stack(int i=10):M(i)
{
	data=new T[M];
	t=-1;
}
template<typename T>
stack<T>::~stack()
{
	delete []data;
}
template<typename T>
bool stack<T>::empty()
{
	return t==-1;
}
template<typename T>
bool stack<T>::full()
{
	return t==M-1;
}
template<typename T>
void stack<T>::push(const T &obj)
{
	if(full())
	{
		T *buf=new T[2*M];
		memcpy(buf,data,M*sizeof(T));
		T *tmp=buf;
		buf=data;
		data=tmp;
		M*=2;
		delete []buf;
	}
	data[++t]=obj;
	
}
template<typename T>
T stack<T>::top()
{
	if(empty())
	{
		return T();
	}
	return data[t];
}

template<typename T>
void stack<T>::pop()
{
	if(empty())
	{
		return;
	}
	t--;
}
const bool red=true;
const bool black=false;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
};
class RBTree
{
	public:
		RBTree();
		~RBTree();
		int insertNode(int key);
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
		void destroy(RBNode **ppnode);
		RBNode *root;
		RBNode *m_null;
};
RBTree::RBTree()
{
	m_null=new RBNode;
	if(m_null)
	{
		m_null->color=black;
		m_null->llink=m_null->rlink=m_null->parent=m_null;
	}
	root=m_null;
}
RBTree::~RBTree()
{
	destroy(&root);
	root=NULL;
	delete m_null;
	m_null=NULL;
}
int RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *parent=m_null;
	
	while(p!=m_null)
	{
		parent=p;
		if(p->key==key)
			return -1;
		else if(p->key>key)
			p=p->llink;
		else
			p=p->rlink;
	}
	RBNode *newNode=createNode(key);
	if(parent==m_null)
	{
		root=newNode;
		root->color=black;
	}
	else
	{
		if(parent->key>key)
			parent->llink=newNode;
		else
			parent->rlink=newNode;
		newNode->parent=parent;
		insertFixup(newNode);
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandparent=m_null;
	RBNode *uncle=m_null;
	while(parent!=m_null&&parent->color==red)
	{
		grandparent=parent->parent;
		if(grandparent->llink==parent)
		{
			uncle=grandparent->rlink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->rlink==pnode)
				{
					pnode=rotate_left(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_right(grandparent);
			}
		}
		else
		{
			uncle=grandparent->llink;
			if(uncle->color==red)
			{
				uncle->color=black;
				parent->color=black;
				grandparent->color=red;
				pnode=grandparent;
				parent=pnode->parent;
			}
			else
			{
				if(parent->llink==pnode)
				{
					pnode=rotate_right(parent);
					parent=pnode->parent;
				}
				parent->color=black;
				grandparent->color=red;
				rotate_left(grandparent);
			}
		}
	}
	root->color=black;
}
void RBTree::deleteNode(int key)
{
	RBNode *delNode=root;
	while(delNode!=m_null)
	{
		if(delNode->key==key)
			break;
		else if(delNode->key>key)
			delNode=delNode->llink;
		else
			delNode=delNode->rlink;
	}
	if(delNode==m_null)
		return;
	RBNode *realNode=delNode;
	RBNode *replace=m_null;
	if(delNode->llink==m_null)
		replace=delNode->rlink;
	else if(delNode->rlink==m_null)
		replace=delNode->llink;
	else
	{
		realNode=realNode->rlink;
		while(realNode->llink!=m_null)
			realNode=realNode->llink;
		replace=realNode->rlink;
		delNode->key=realNode->key;
	}
	if(realNode->color==black)
		deleteFixup(replace);
	delete realNode;
	realNode=NULL;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p=pnode;
	RBNode *parent=m_null;
	RBNode *slibing=m_null;
	while(p!=root&&p->color==red)
	{
		parent=p->parent;
		if(parent->llink==p)
		{
			slibing=parent->rlink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_left(parent);
				slibing=parent->rlink;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->rlink->color==black)
				{
					slibing->llink->color=black;
					slibing->color=red;
					rotate_right(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->rlink->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else
		{
			slibing=parent->llink;
			if(slibing->color==red)
			{
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=parent->llink;
			}
			if(slibing->llink->color==black&&slibing->rlink==black)
			{
				slibing->color=red;
				p=parent;
			}
			else
			{
				if(slibing->llink->color=black)
				{
					slibing->rlink->color=black;
					slibing->color=red;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->llink->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(root==a)
	{
		root=b;
		//root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(root==a)
	{
		root=b;
		//root->color=black;
		root->parent=m_null;
	}
	else
	{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p)
	{
		p->key=key;
		p->color=red;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}
void RBTree::destroy(RBNode **ppnode)
{
	if(ppnode==NULL||*ppnode==m_null)
		return;
	destroy(&(*ppnode)->llink);
	destroy(&(*ppnode)->rlink);
	delete *ppnode;
	*ppnode=m_null;
}
void RBTree::preOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=m_null)
		{
			cout<<p->key<<' ';
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void RBTree::inOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void RBTree::postOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty())
	{
		while(p!=m_null)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();	
		st.pop();
		cout<<p->key<<' ';
		if(!st.empty()&&st.top()->llink==p)
			p=st.top()->rlink;
		else
			p=m_null;
	}
	cout<<endl;
}
#include<stdlib.h>
#define N 1000
#define random(i) (rand()%i)
int main()
{
	RBTree tree;
	int num=0;
	while(num<N)
	{
		if(tree.insertNode(random(N))==0)
			num++;
	}
	cout<<"========================"<<endl;
	tree.preOrder();
	cout<<"========================"<<endl;
	tree.inOrder();
	cout<<"========================"<<endl;
	tree.postOrder();
	cout<<"========================"<<endl;
	return 0;
}
*/

/*
int fun(int *a,int n)
{
	int max=1;
	int *dp=new int[n];
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>max)
			max=dp[i];
	}
	delete []dp;
	return max;
}
int jueduizhi(int x)
{
	int y=x>>31;
	return (x^y)-y;
}
int main()
{
	int a[7]={1,2,3,4,8,6,7};
	cout<<fun(a,7)<<endl;
	int x;
	while(cin>>x)
		cout<<jueduizhi(x)<<endl;
	return 0;
}
*/

/*
const int M=10000000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct Path
{
	int len;
	int vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if(G.arcs!=NULL)
		return;
	cout<<"please enter the number of vex and the number of the arc:"<<endl;
	cin>>G.vexNum>>G.arcNum;
	G.arcs=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		G.arcs[i]=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			if(i==j)
				G.arcs[i][j]=0;
			else
				G.arcs[i][j]=M;
		}
	}
	cout<<"please enter each arc(v0 v1 w):"<<endl;
	int v0,v1,w;
	for(int i=0;i<G.arcNum;i++)
	{
		cin>>v0>>v1>>w;
		G.arcs[v0][v1]=w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if(G.arcs==NULL)
		return;
	for(int i=0;i<G.vexNum;i++)
		delete []G.arcs[i];
	delete[]G.arcs;
	G.arcs=NULL;
}
void dijkstra(GraphMatrix &G,Path *dist)
{
	if(G.arcs==NULL||dist==NULL)
		return;
	int *flag=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		flag[i]=0;
	dist[0].len=0;
	dist[0].vexEnd=0;
	flag[0]=1;
	for(int i=1;i<G.vexNum;i++)
	{
		dist[i].len=G.arcs[0][i];
		if(dist[i].len==M)
			dist[i].vexEnd=-1;
		else
			dist[i].vexEnd=0;
	}
	int minw;
	int min;
	for(int i=1;i<G.vexNum;i++)
	{
		minw=M;
		min=0;
		for(int j=1;j<G.vexNum;j++)
		{
			if(flag[j]==0&&dist[j].len<minw)
			{
				minw=dist[j].len;
				min=j;
			}
		}
		if(min==0)
			return;
		flag[min]=1;
		for(int j=1;j<G.vexNum;j++)
		{
			if(flag[j]==0&&dist[j].len>dist[min].len+G.arcs[min][j])
			{
				dist[j].len=dist[min].len+G.arcs[min][j];
				dist[j].vexEnd=min;
			}
		}
	}
	delete[]flag;
}
void showPath(Path *dist,int v)
{
	if(dist[v].len==M)
		return;
	stack<int> st;
	while(v!=0)
	{
		st.push(v);
		v=dist[v].vexEnd;
	}
	cout<<0<<' ';
	while(!st.empty())
	{
		cout<<st.top()<<' ';
		st.pop(); 
	}
	cout<<endl;
}
int main()
{
	GraphMatrix G;
	G.arcs=NULL;
	createGraph(G);
	Path *dist=new Path[G.vexNum];
	dijkstra(G,dist);
	int v;
	while(cin>>v)
	{
		if(v>0&&v<G.vexNum)
			showPath(dist,v);
	}
	delete[]dist;
	destroyGraph(G);
	return 0;
}
*/

/*
const int M=10000000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct Path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if(G.arcs!=NULL)
		return;
	cout<<"please enter the number of vex and the number of arc:"<<endl;
	cin>>G.vexNum>>G.arcNum;
	G.arcs=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		G.arcs[i]=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			if(i==j)
				G.arcs[i][j]=0;
			else
				G.arcs[i][j]=M;
		}
	}
	cout<<"please enter each arc(v0 v1 w):"<<endl;
	int v0,v1,w;
	for(int i=0;i<G.arcNum;i++)
	{
		cin>>v0>>v1>>w;
		G.arcs[v0][v1]=w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if(G.arcs==NULL)
		return;
	for(int i=0;i<G.vexNum;i++)
		delete[]G.arcs[i];
	delete[]G.arcs;
	G.arcs=NULL;
}
void Floyd(GraphMatrix &G,Path &result)
{
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			result.len[i][j]=G.arcs[i][j];
			if(result.len[i][j]==M)
				result.vexEnd[i][j]=-1;
			else
				result.vexEnd[i][j]=j;
		}
	}
	for(int k=0;k<G.vexNum;k++)
	{
		for(int i=0;i<G.vexNum;i++)
		{
			for(int j=0;j<G.vexNum;j++)
			{
				if(result.len[i][j]>result.len[i][k]+result.len[k][j])
				{
					result.len[i][j]=result.len[i][k]+result.len[k][j];
					result.vexEnd[i][j]=result.vexEnd[i][k];
				}
			}
		}
	}
}
void showPath(Path &result,int v0,int v1)
{
	if(result.len[v0][v1]==M)
		return;
	while(v0!=v1)
	{
		cout<<v0<<' ';
		v0=result.vexEnd[v0][v1];
	}
	cout<<v0<<endl;
}
int main()
{
	GraphMatrix G;
	G.arcs=NULL;
	createGraph(G);
	Path result;
	result.len=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		result.len[i]=new int[G.vexNum];
	result.vexEnd=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		result.vexEnd[i]=new int[G.vexNum];

	Floyd(G,result);
	int v0,v1;
	while(cin>>v0>>v1)
		showPath(result,v0,v1);

	for(int i=0;i<G.vexNum;i++)
		delete[]result.vexEnd[i];
	delete[]result.vexEnd;
	for(int i=0;i<G.vexNum;i++)
		delete[]result.len[i];
	delete[]result.len;
	destroyGraph(G);
	return 0;
}
*/


/*
class shape
{
	public:
		shape(double i,double j)
		{
			x=i;
			y=j;
		}
        virtual ~shape()
		{
			cout<<"~shape"<<endl;
		}
		virtual double area()=0; 
	protected:
		double x,y;
};
class A:public shape
{
	public:
		A(double i,double j):shape(i,j)
		{
		}
		~A()
		{
			cout<<"~A"<<endl;
		}
		double area()
		{
			return x*y;
		}		
};
class B:public shape
{
	public:
		B(double i,double j):shape(i,j)
		{
		}
		~B()
		{
			cout<<"~B"<<endl;
		}
		double area()
		{
			return x*y/2;
		}		
};
int main()
{
	shape *p=new A(1,2);
	cout<<p->area()<<endl;
	delete p;
	p=new B(1,2);
	cout<<p->area()<<endl;
	delete p;
	p=NULL;
	return 0;
}
*/


/*
class A
{
	public:
		A(int i)
		{
			a=i;
		}
		virtual ~A()
		{
			cout<<"~A"<<endl;
		}
		virtual void fun()
		{
			cout<<"A::fun()"<<endl;
		}
	private:
		int a;
};
class B:public A
{
	public:
		B(int i,int j):A(i),b(j){}
		~B()
		{
			cout<<"~B"<<endl;
		}
		void fun()
		{
			cout<<"B::fun()"<<endl;
		}
	private:
		int b;
};
int main()
{
	A *p=new B(1,2);
	p->fun();
	delete p;
	return 0;
}
*/

/*
#include<fstream>
const int M=1000000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct Path
{
	int vexEnd;
	int len;
};
void createGraph(GraphMatrix &G)
{
	if(G.arcs!=NULL)
		return;
	ifstream input("1");
	//cout<<"please enter the number of vex and the number of arcs:"<<endl;
	input>>G.vexNum>>G.arcNum;
	G.arcs=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		G.arcs[i]=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			if(i==j)
				G.arcs[i][j]=0;
			else
				G.arcs[i][j]=M;
		}
	}
	//cout<<"please enter each arc(v0 v1 w):"<<endl;
	int v0,v1,w;
	for(int i=0;i<G.arcNum;i++)
	{
		input>>v0>>v1>>w;
		G.arcs[v0][v1]=w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if(G.arcs==NULL)
		return;
	for(int i=0;i<G.vexNum;i++)
		delete[]G.arcs[i];
	delete[]G.arcs;
	G.arcs=NULL;
}
void dijkstra(GraphMatrix &G,Path *dist)
{
	if(G.arcs==NULL)
		return;
	int *flag=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		flag[i]=0;
	for(int i=0;i<G.vexNum;i++)
	{
		dist[i].len=G.arcs[0][i];
		if(dist[i].len==M)
			dist[i].vexEnd=-1;
		else
			dist[i].vexEnd=0;
	}
	flag[0]=1;
	int minw=M;
	int min=0;
	for(int i=1;i<G.vexNum;i++)
	{
		minw=M;
		min=0;
		for(int j=1;j<G.vexNum;j++)
		{
			if(flag[j]==0&&dist[j].len<minw)
			{
				minw=dist[j].len;
				min=j;
			}
		}
		if(min==0)
			return;
		flag[min]=1;
		for(int j=1;j<G.vexNum;j++)
		{
			if(flag[j]==0&&dist[j].len>dist[min].len+G.arcs[min][j])
			{
				dist[j].len=dist[min].len+G.arcs[min][j];
				dist[j].vexEnd=min;
			}
		}
	}
	delete[]flag;
}
void showPath(Path *dist,int v)
{
	if(dist[v].len==M)
		return;
	stack<int> st;
	while(v!=0)
	{
		st.push(v);
		v=dist[v].vexEnd;
	}
	cout<<0<<' ';
	while(!st.empty())
	{
		cout<<st.top()<<' ';
		st.pop();
	}
}
int main()
{
	GraphMatrix G;
	G.arcs=NULL;
	createGraph(G);
	Path *dist=new Path[G.vexNum];
	dijkstra(G,dist);
	int v;
	while(cin>>v)
	{
		showPath(dist,v);
	}
	delete[]dist;
	destroyGraph(G);
	return 0;
}
*/


/*
#include<fstream>
const int M=1000000;
struct GraphMatrix
{
	int vexNum;
	int arcNum;
	int **arcs;
};
struct Path
{
	int **len;
	int **vexEnd;
};
void createGraph(GraphMatrix &G)
{
	if(G.arcs!=NULL)
		return;
	ifstream input("1");
	input>>G.vexNum>>G.arcNum;
	G.arcs=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		G.arcs[i]=new int[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			if(i==j)
				G.arcs[i][j]=0;
			else
				G.arcs[i][j]=M;
		}
	}
	int v0,v1,w;
	for(int i=0;i<G.arcNum;i++)
	{
		input>>v0>>v1>>w;
		G.arcs[v0][v1]=w;
	}
}
void destroyGraph(GraphMatrix &G)
{
	if(G.arcs==NULL)
		return;
	for(int i=0;i<G.vexNum;i++)
		delete[]G.arcs[i];
	delete[]G.arcs;
	G.arcs=NULL;
}
void Floyd(GraphMatrix &G,Path &result)
{
	for(int i=0;i<G.vexNum;i++)
	{
		for(int j=0;j<G.vexNum;j++)
		{
			result.len[i][j]=G.arcs[i][j];
			if(result.len[i][j]==M)
				result.vexEnd[i][j]=-1;
			else
				result.vexEnd[i][j]=j;
		}
	}
	for(int k=0;k<G.vexNum;k++)
	{
		for(int i=0;i<G.vexNum;i++)
		{
			for(int j=0;j<G.vexNum;j++)
			{
				if(result.len[i][j]>result.len[i][k]+result.len[k][j])
				{
					result.len[i][j]=result.len[i][k]+result.len[k][j];
					result.vexEnd[i][j]=result.vexEnd[i][k];
				}
			}	
		}
	}
} 
void showPath(Path &result,int v0,int v1)
{
	if(result.len[v0][v1]==M)
		return;
	while(v0!=v1)
	{
		cout<<v0<<' ';
		v0=result.vexEnd[v0][v1]; 
	}
	cout<<v0<<endl;
}
int main()
{
	GraphMatrix G;
	G.arcs=NULL;
	createGraph(G);
	Path result;
	result.len=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		result.len[i]=new int[G.vexNum];
	result.vexEnd=new int*[G.vexNum];
	for(int i=0;i<G.vexNum;i++)
		result.vexEnd[i]=new int[G.vexNum];
	
	Floyd(G,result);
	int v0,v1;
	while(cin>>v0>>v1)
		showPath(result,v0,v1);

	for(int i=0;i<G.vexNum;i++)
		delete[]result.vexEnd[i];
	delete[]result.vexEnd;
	for(int i=0;i<G.vexNum;i++)
		delete[]result.len[i];
	delete[]result.len;
	destroyGraph(G);
}
*/
/*
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=k;i<n;i++)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)
	{
		shell(a,n,k);
		k/=2;
	}
}
void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
				x=j;
		}
		if(x!=i)
		{
			a[i]^=a[x];
			a[x]^=a[i];
			a[i]^=a[x];
		}
	}
}
void heap(int *a,int n,int i)
{
	int child;
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child+1<n&&a[child]<a[child+1])
			child++;
		if(a[i]<a[child])
		{
			a[i]^=a[child];
			a[child]^=a[i];
			a[i]^=a[child];
		}
		else
		{
			break;
		}
	}
}
void heapSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=n/2-1;i>=0;i--)
	{
		heap(a,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		a[0]^=a[i];
		a[i]^=a[0];
		a[0]^=a[i];
		heap(a,i,0);
	}
}
void QipaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i=0;
	int j=n-1;
	int x=a[0];
	while(i<j)
	{
		for(;i<j;j--)
		{	
			if(a[j]<x)
			{
				a[i++]=a[j];
				break;
			}
		}		
		for(;i<j;i++)
		{
			if(a[i]>x)
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=m)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
}
void mergePass(int *a,int *b,int len,int n)
{
	int i=0;
	while(i+2*len<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
		merge(a,b,i,i+len-1,n-1);
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int len=1;
	int *b=new int[n];
	while(len<n)
	{
		mergePass(a,b,len,n);
		len*=2;
		mergePass(b,a,len,n);
		len*=2;
	}
	delete[]b;
}
#include<stdlib.h>
#define N 1000000
#define random(i) (rand()%i)
int a[N];
int flag[N];
int main()
{
	int num=0;
	while(num<N)
	{
		int buf=random(N);
		if(flag[buf]==0)
		{
			flag[buf]=1;
			a[num++]=buf;
		}
	}
	//insertSort(a,N);
	shellSort(a,N);
	//selectSort(a,N);
	//heapSort(a,N);
	//QipaoSort(a,N);
	//QSort(a,N);
	//mergeSort(a,N);
	for(int i=N-100;i<N;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
*/
int x[100];
bool place(int k)
{
	for(int i=1;i<k;i++)
	{
		if(x[i]==x[k])
			return false;
	}
	return true;
}
void queue(int n)
{
	int k=1;
	int flag=0;
	while(k>=1)
	{
		x[k]++;
		while(x[k]<=n&&!place(k))
			x[k]++;
		if(x[k]<=n)
		{
			if(k==n)
			{
				if(x[1]!=flag)
				{
					for(int i=1;i<=n;i++)
						cout<<x[i]<<' ';
					cout<<endl;
					flag=x[1];				
				}
			}
			else if(k<n)
				k++;
		}
		else
		{
			x[k]=0;
			k--;
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
		queue(n);
	return 0;
}
