#include "VM.h"
#include "VM.cpp"
using namespace std;

void test(string filename)
{
    VM *vm = new VM();
    try
    {
        vm->run(filename);
    }
    catch (exception& e)
    {
        cout << e.what();
    }
    delete vm;
}

int main()
{
    string argv[] = {"prog1.txt", "prog2.txt", "prog3.txt", "prog4.txt", "prog5.txt", "prog6.txt", "prog7.txt", "prog8.txt", "prog9.txt", "prog10.txt"};
    for (int i = 0; i < 10; i++)
    {
        test(argv[i]);
        cout << endl;
    }
    return 0;
}
