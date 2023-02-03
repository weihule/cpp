#include <iostream>
#include <string>

using namespace std;

class Building {
	friend class GoodGay;
public:
	Building(string sitting_root, string bed_room) {
		this->sitting_root = sitting_root;
		this->bed_room = bed_room;
	}
	string sitting_root;
private:
	string bed_room;

};

class Building2
{
private:
	string bed_room;
public:
	string sitting_room;
	// ���캯��
	Building2(string sitting_root, string bed_room)
	{
		this->sitting_room = sitting_root;
		this->bed_room = bed_room;
	}

};

class GoodGay2
{
public:
	GoodGay2()
	{
		building = new Building2("living_room", "bed_room");
	}

	Building2* building;

};

class GoodGay {
public:
	GoodGay() {
		// ����һ��Building����
		building = new Building("livingroom", "bedroom");
	}
	// �ú�������Building�еĹ�����˽������
	void visit() {
		cout << "GoodGay are visiting " << building->sitting_root << endl;
		cout << "GoodGay are visiting " << building->sitting_root << endl;
	}
	Building* building;
};


// �������캯��
class Line
{
public:
	Line(int length)
	{
		cout << "���ÿ������캯��" << endl;
		ptr = new int;		// Ϊָ������ڴ�
		*ptr = length;
	}

	int get_length(void)
	{
		return *ptr;
	};

	~Line()			// ��������
	{
		cout << "--������������" << endl;
	}

	void display(Line obj)
	{
		cout << "line : " << obj.get_length() << endl;
	}

private:
	int* ptr;

};

void test02()
{
	Line l1(10);
	l1.display(l1);
}


void test01() {
	GoodGay g1;
	g1.visit();
}

class Person
{
public:
	int m_a;
	int m_b;
};

Person operator+ (Person& p1, Person& p2)
{
	Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;

	return temp;
}


void test03()
{
	Person p1;
	p1.m_a = 11;
	p1.m_b = 20;

	Person p2;
	p2.m_a = 10;
	p2.m_b = 20;

	Person p3 = p1 + p2;
	cout << "p3.m_a = " << p3.m_a << endl;
	cout << "p3.m_b = " << p3.m_b << endl;
}


class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��..." << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ..." << endl;
	}

	void left()
	{
		cout << "Java��Python��C++..." << endl;
	}

};

class Java : public BasePage
{
public:
	void content()
	{
		cout << "Java ѧ����Ƶ" << endl;
	}
};

class Python : public BasePage
{
public:
	void content()
	{
		cout << "Python ѧ����Ƶ" << endl;
	}
};

void test04()
{
	cout << "Java:" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "Python:" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
}

class Base
{
public:
	Base()
	{
		m_a = 111;
	}

	~Base()
	{
		cout << "Base ��������" << endl;
	}

	void func()
	{
		cout << "Base func" << endl;
	}

	int m_a;
};

class Son :public Base
{
public:
	Son()
	{
		m_a = 200;
	}

	~Son()
	{
		cout << "Son ��������" << endl;
	}

	void func()
	{
		cout << "Son func" << endl;
	}
	int m_a;
};

void test05()
{
	/*Base b;*/
	Son s;
	s.func();
	s.Base::func();
}

class Animal
{
public:
	// �麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

void do_speak(Animal &animal)
{
	animal.speak();
}

void test06()
{
	Cat cat1;
	do_speak(cat1);
}


class Calculator
{
public:
	float m_num1;
	float m_num2;

	Calculator(float num1, float num2)
	{
		m_num1 = num1;
		m_num2 = num2;
	}

	float get_result(char oper)
	{
		switch (oper)
		{
		case '+':
			return m_num1 + m_num2;
			break;
		case '-':
			return m_num1 + m_num2;
			break;
		case '*':
			return m_num1 * m_num2;
			break;
		case '/':
			return m_num1 / m_num2;
			break;
		default:
			break;
		}
	}
};


class AbstractCalculator
{
public:

	//AbstractCalculator(float num1, float num2)
	//{
	//	m_num1 = num1;
	//	m_num2 = num2;
	//}
	virtual float get_result()
	{
		return 0;
	}

	float m_num1;
	float m_num2;
};

class AddCalculator: public AbstractCalculator
{
	float get_result()
	{
		return m_num1 + m_num2;
	}
};
 
class SubCalculator : public AbstractCalculator
{
	float get_result()
	{
		return m_num1 - m_num2;
	}
};

class MulCalculator : public AbstractCalculator
{
	float get_result()
	{
		return m_num1 * m_num2;
	}
};

void test08()
{
	AbstractCalculator* abs = new MulCalculator;
	abs->m_num1 = 10;
	abs->m_num2 = 20;

	cout << "res = " << abs->get_result() << endl; 
	delete abs;
}

void test07()
{
	Calculator cal1(10, 20);
	float res = cal1.get_result('*');
	cout << "res = " << res << endl;
}


class Drinking
{
public:
	virtual void boil() = 0;

	virtual void brew() = 0;

	virtual void pour() = 0;

	virtual void put_something() = 0;

	void make_drink()
	{
		boil();
		brew();
		pour();
		put_something();
	}
};

class Coffee : public Drinking
{
	void boil()
	{
		cout << "coffee" << endl;
	}

	virtual void brew()
	{
		cout << "brew" << endl;
	}

	virtual void pour()
	{
		cout << "pour" << endl;
	}

	virtual void put_something()
	{
		cout << "put sugar" << endl;
	}
};


class Tea : public Drinking
{
	void boil()
	{
		cout << "tea" << endl;
	}

	virtual void brew()
	{
		cout << "brew" << endl;
	}

	virtual void pour()
	{
		cout << "pour" << endl;
	}

	virtual void put_something()
	{
		cout << "put gouqi" << endl;
	}
};


void do_work(Drinking* dr)
{
	dr->make_drink();

	delete dr;
}


void test09()
{
	do_work(new Tea);
}


class Animal2
{
public:
	Animal2()
	{
		cout << "Animal2 ���캯������" << endl;
	}
	virtual void speak() = 0;

	virtual ~Animal2()
	{
		cout << "Animal2 ������������" << endl;
	}
};

class Cat2 :public Animal2
{
public:
	string* m_name;
	Cat2(string name)
	{
		cout << "Cat2 ���캯������" << endl;
		m_name = new string(name);
	}

	void speak()
	{
		cout << *m_name << " cat speak" << endl;
	}

	~Cat2()
	{
		if (m_name != NULL)
		{
			cout << "Cat2 ������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
};

void test10()
{
	Animal2* ani = new Cat2("Tom");
	ani->speak();

	delete ani;
}

class Cpu
{
public:
	virtual void caculate() = 0;
};


class CPU
{
public:
	virtual void calculate() = 0;
};

class GPU
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* c, GPU* g, Memory* me)
	{
		m_c = c;
		m_g = g;
		m_me = me;
	}

	// �����ĺ���
	void work()
	{
		m_c->calculate();
		m_g->display();
		m_me->storage();
	}

	~Computer()
	{
		if (m_c != NULL)
		{
			delete m_c;
			m_c = NULL;
		}
		if (m_g != NULL)
		{
			delete m_g;
			m_g = NULL;
		}
		if (m_me != NULL)
		{
			delete m_me;
			m_me = NULL;
		}
	}

private:
	CPU* m_c;
	GPU* m_g;
	Memory* m_me;
};

// ����ĳ���
class InterCPU : public CPU
{
	virtual void calculate()
	{
		cout << "Inter ��CPU��ʼ������ !" << endl;
	}
};

class InterGPU : public GPU
{
	virtual void display()
	{
		cout << "Inter ��GPU��ʼ��ʾ�� !" << endl;
	}
};

class InterMemory : public Memory
{
	virtual void storage()
	{
		cout << "Inter ���ڴ濪ʼ�洢�� !" << endl;
	}
};

void test11()
{
	// ������һ̨�������
	CPU* inter_cpu = new InterCPU;
	GPU* inter_gpu = new InterGPU;
	Memory* inter_memory = new InterMemory;

	// ������һ̨����
	Computer* c1 = new Computer(inter_cpu, inter_gpu, inter_memory);
	c1->work();

	delete c1;
}

int main() {
	test11();
	system("pause");
	return 0;
}