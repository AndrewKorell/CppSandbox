//polymorphosis example
#include <iostream>

// Start with a base class
// this is an abstract class because nyName is pure-virtual

class BaseClass {
    protected:
        int valueOne, valueTwo;
    public:
        virtual ~BaseClass() {}; //declare the destructor
        void set_values (int a, int b)
        {
            valueOne = a;
            valueTwo = b;
        }
        virtual int theSum() { return valueOne + valueTwo; }
        virtual void myName() = 0; // pure virtual
        virtual void myOtherName() { std::cout << "baseClass Other" << std::endl; } // non-pure virtual
};

//Then create a child class
//
class ChildClassOne : public BaseClass {
    public:
        void set_values (int a, int b)
        {
            valueOne = a;
            valueTwo = b;

        }
        int theSum() override { return valueOne + valueTwo + 3; }
        void myName() override { std::cout << "baseClassOne" << std::endl; }
        void myOtherName() override { std::cout << "baseClassOneOther" <<std::endl; }
};

//Then a second child class
class ChildClassTwo : public BaseClass {
    public:
        int theSum() override { return  valueOne + valueTwo + 3 + 4; }
        void myName() override { std::cout << "baseClassTwo" << std::endl; }
        void myOtherName() override { BaseClass::myOtherName(); } //a little bit of weirdness for the heck of it.

};

int main() {

    //allocate an array of pointers
    BaseClass** pSomeArray = new BaseClass*[5];


    //Fill the values with variations of classes
    pSomeArray[0] = new ChildClassOne();
    pSomeArray[1] = new ChildClassOne();
    pSomeArray[2] = new ChildClassTwo();
    pSomeArray[3] = new ChildClassOne();
    pSomeArray[4] = new ChildClassTwo();
    pSomeArray[5] = new ChildClassOne();

    pSomeArray[0]->set_values(1,2);
    pSomeArray[1]->set_values(1,2);
    pSomeArray[2]->set_values(1,2);
    pSomeArray[3]->set_values(1,2);
    pSomeArray[4]->set_values(1,2);
    pSomeArray[5]->set_values(1,2);

    for (int i = 0; i < 5; i++) {
        pSomeArray[i]->myName();
        pSomeArray[i]->myOtherName();
        std::cout << pSomeArray[i]->theSum() << std::endl;
    }

    delete[] pSomeArray; //clean up


    return 0;
}
