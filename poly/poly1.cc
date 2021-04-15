//polymorphosis example
#include <iostream>

// Start with a base class
class BaseClass {
	protected:
		int valueOne, valueTwo;
	public:
		void set_values (int a, int b)
		{
			valueOne = a;
			valueTwo = b;
		}
		
		virtual int theSum() { return valueOne + valueTwo; }
};

//Then create a child class
class ChildClassOne : public BaseClass { 

public:
		void set_values (int a, int b)
		{
			valueOne = a;
			valueTwo = b;
			
		}
		int theSum() { return valueOne + valueTwo + 3; }
};

//Then a second child class
class ChildClassTwo : public BaseClass {
	protected:
		int valueThree, valueFour;
	public:
		int theSum() { return  valueOne + valueTwo + 3 + 4; }
	
};

int main() {

	BaseClass class1;
	ChildClassOne class2;
	ChildClassTwo class3;

	BaseClass *pBase1 = &class1;
	BaseClass *pBase2 = &class2;
	BaseClass *pBase3 = &class3;

	pBase1->set_values(1,2);
	pBase2->set_values(1,2);
	pBase3->set_values(1,2);

	std::cout << pBase1->theSum() << "\n";
	std::cout << pBase2->theSum() << "\n";
	std::cout << pBase3->theSum() << "\n";
	return 0;
}
	
