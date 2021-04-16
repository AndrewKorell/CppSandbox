#include <iostream>
#include <vector>
#include <algorithm>

//Lambdas - anonymous function
//see CPP reference page on this

void ForEach(const std::vector<int>& values, void(*func)(int)) //function pointer (*func)
                                                               //assign a function to a variable
{
    for(int value : values)
        func(value);
}

void PrintVariable(int a)
{
    std::cout << "Function Pointer says: " << a << std::endl;

}


int main()
{
    //Brief demonstration of function pointers starts
    typedef void(*PrintVariableFunction)(int);

    PrintVariableFunction printVar = PrintVariable;
    auto printVar2 = PrintVariable;

    printVar2(1);
    printVar(2);
    //Breif demonstration of function pointers ends

    std::vector<int> values = { 1, 2, 3, 5 };
    auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
    std::cout << *it << std::endl;

    /* lambda expression becomes fun(value) in function pointer   */
    auto lambda = [](int value) { std::cout << "value: " << value << std::endl; };
    // [] captures, put outside variables inside
    // (int value) parameters passed to the function
    // { ... } the function

    ForEach(values, lambda);

    return 0;
}
