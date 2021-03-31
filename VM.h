#ifndef VM_H
#define VM_H

#include "main.h"

using namespace std;

// Instructions
enum class Instructions
{
    Add = 0, Minus, Mul, Div,                   // Arithmetic instructions
    CmpEQ, CmpNE, CmpLT, CmpLE, CmpGT, CmpGE,   // Comparison instructions
    Not, And, Or,                               // Logical instructions
    Move, Load, Store,                          // Load and store instructions
    Jump, JumpIf, Call, Return, Halt,           // Sequence control instructions
    Input, Output,                              // Input and Output instructions
    NONE
};

// VarType
enum class VarType
{
    Integer = 0, Float, Boolean, NONE
};

// Data contain var or add
enum class DataType
{
    Add = 0, Var, NONE
};

// Variables
class Variable
{
private:
    VarType VarTypeFunction;
    int IntegerVar;
    float FloatVar;
    bool BooleanVar;
public:
    Variable()
    {
        this->BooleanVar = false;
        this->FloatVar = 0;
        this->IntegerVar = 0;
        this->VarTypeFunction = VarType::NONE;
    };
    ~Variable()
    {
    };
    void setVariable(int var)
    {
        this->IntegerVar = var;
        this->VarTypeFunction = VarType::Integer;
    };
    void setVariable(float var)
    {
        this->FloatVar = var;
        this->VarTypeFunction = VarType::Float;
    };
    void setVariable(bool var)
    {
        this->BooleanVar = var;
        this->VarTypeFunction = VarType::Boolean;
    };
    int getInVar()
    {
        return this->IntegerVar;
    };
    float getFlVar()
    {
        return this->FloatVar;
    };
    bool getBlVar()
    {
        return this->BooleanVar;
    };
    VarType getVarTypeFunction()
    {
        return this->VarTypeFunction;
    };
};

// Data
class Data
{
private:
    int Add;
    Variable Var;
    DataType DataTypeFunction;
public:
    Data()
    {
        this->Add = 0;
        this->DataTypeFunction = DataType::NONE;
    };
    ~Data()
    {
    };
    void setData(int addr)
    {
        this->Add = addr;
        this->DataTypeFunction = DataType::Add;
    };
    void setData(Variable var)
    {
        this->Var = var;
        this->DataTypeFunction = DataType::Var;
    };
    int getAddrData()
    {
        return this->Add;
    };
    Variable getVarData()
    {
        return this->Var;
    };
    DataType getDataTypeFunction()
    {
        return this->DataTypeFunction;
    };
};

// Stack
class Stack
{
private:
    int* StackAdd;
    int Top;
public:
    Stack()
    {
        StackAdd = new int[3];
        this->Top = -1;
    }
    ~Stack()
    {
        // delete StackAdd;
    }
    bool IsFull()
    {
        if(Top >= 3 - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(int addr)
    {
        this->StackAdd[++Top] = addr;
    }

    int Pop()
    {
        return StackAdd[Top--];
    }
};

// CodeMemory
class CodeMemory
{
private:
    string* Memory;
    int curr;
public:
    CodeMemory()
    {
        this->Memory = new string[65536];
        this->curr = 0;
    }
    ~CodeMemory()
    {
        // delete Memory;
    }
    void setCodeMemory(string instruction)
    {
        Memory[this->curr] = instruction;
        this->curr++;
    }
    string getCodeMemory(int address)
    {
        return Memory[address];
    }
    int getCurr() {
        return this->curr;
    }
};

// StaticMemory
class StaticMemory
{
private:
    Variable* Memory;
    int curr;
public:
    StaticMemory()
    {
        Memory = new Variable[65536];
        this->curr = 0;
    }
    ~StaticMemory()
    {
        // delete Memory;
    }
    void setSMemory(Variable var, int address)
    {
        Memory[address] = var;
        this->curr = address;
    }
    Variable getSMemory(int address)
    {
        return Memory[address];
    }
};

// VM
class VM
{
private:
    int IP; // IP Register
    Data R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15; // General Registers
    Data Register[15] = {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15};
    bool running;               // running flag
    Stack stackMemory;          // store return addresses
    CodeMemory codeMemory;      // store instructions to be executed
    StaticMemory staticMemory;  // store variables
public:
    VM()
    {
        this->IP = 0;
        this->running = true;
    }

    ~VM()
    {
    }

    // Add functions for executing an instructions
    Instructions readInstruction(string input)
    {
        if (input == "Add")
        {
            return Instructions::Add;
        }
        else if (input == "Minus")
        {
            return Instructions::Minus;
        }
        else if (input == "Mul")
        {
            return Instructions::Mul;
        }
        else if (input == "Div")
        {
            return Instructions::Div;
        }
        else if (input == "CmpEQ")
        {
            return Instructions::CmpEQ;
        }
        else if (input == "CmpNE")
        {
            return Instructions::CmpNE;
        }
        else if (input == "CmpLT")
        {
            return Instructions::CmpLT;
        }
        else if (input == "CmpLE")
        {
            return Instructions::CmpLE;
        }
        else if (input == "CmpGT")
        {
            return Instructions::CmpGT;
        }
        else if (input == "CmpGE")
        {
            return Instructions::CmpGE;
        }
        else if (input == "Not")
        {
            return Instructions::Not;
        }
        else if (input == "And")
        {
            return Instructions::And;
        }
        else if (input == "Or")
        {
            return Instructions::Or;
        }
        else if (input == "Move")
        {
            return Instructions::Move;
        }
        else if (input == "Load")
        {
            return Instructions::Load;
        }
        else if (input == "Store")
        {
            return Instructions::Store;
        }
        else if (input == "Jump")
        {
            return Instructions::Jump;
        }
        else if (input == "JumpIf")
        {
            return Instructions::JumpIf;
        }
        else if (input == "Call")
        {
            return Instructions::Call;
        }
        else if (input == "Return")
        {
            return Instructions::Return;
        }
        else if (input == "Halt")
        {
            return Instructions::Halt;
        }
        else if (input == "Input")
        {
            return Instructions::Input;
        }
        else if (input == "Output")
        {
            return Instructions::Output;
        }
        else
        {
            return Instructions::NONE;
        }
    };

    int readRegister(string input)
    {
        if (input == "R1")
        {
            return 1;
        }
        else if (input == "R2")
        {
            return 2;
        }
        else if (input == "R3")
        {
            return 3;
        }
        else if (input == "R4")
        {
            return 4;
        }
        else if (input == "R5")
        {
            return 5;
        }
        else if (input == "R6")
        {
            return 6;
        }
        else if (input == "R7")
        {
            return 7;
        }
        else if (input == "R8")
        {
            return 8;
        }
        else if (input == "R9")
        {
            return 9;
        }
        else if (input == "R10")
        {
            return 10;
        }
        else if (input == "R11")
        {
            return 11;
        }
        else if (input == "R12")
        {
            return 12;
        }
        else if (input == "R13")
        {
            return 13;
        }
        else if (input == "R14")
        {
            return 14;
        }
        else if (input == "R15")
        {
            return 15;
        }
        else return 0;
    };

    int readAddress(string input)
    {
        string temp = input;
        temp.pop_back();
        int output;
        output = stoi(temp);
        return output;
    };

    inline int readInteger(string input)
    {
        int output = stoi(input);
        return output;
    };

    float readFloat(string input)
    {
        float output = stof(input);
        return output;
    };

    bool readBoolean(string input)
    {
        if (input == "true")
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    int typeDetect(string input)
    {
        smatch m;
        regex r("R[1-9][0-5]*");
        regex b("(true|flase)");
        regex a("[0-9]+A$");
        regex in("^[0-9]*$");
        regex fl("[0-9]+[.][0-9]+");
        if (regex_match(input, m, r))
        {
            return 0; // This is Register
        }
        else if (regex_match(input, m, b))
        {
            return 1; // This is a boolean
        }
        else if (regex_match(input, m, a))
        {
            return 2; // This is Address
        }
        else if (regex_match(input, m, in))
        {
            return 3; // This is integer
        }
        else if (regex_match(input, m, fl))
        {
            return 4; // This is float
        }
        else
        {
            return -1;    // unknown type
        }
    };

    bool checkValidOperand(string runningcode)
    {
// Arithmetic instructions
        if (regex_match (runningcode, regex("^(Add|Minus|Mul|Div)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //Register and Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Add|Minus|Mul|Div)( )R([1-9][0-5]?)(,)( )([0-9]+)$"))) //Register and interger
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Add|Minus|Mul|Div)( )R([1-9][0-5]?)(,)( )([0-9]+)[.]([0-9]+)$"))) //Register and float
        {
            return true;
        }

//Comparison instructions
        else if (regex_match (runningcode, regex("^(CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //Register and Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE)( )R([1-9][0-5]?)(,)( )([0-9]+)$"))) //Register and interger
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE)( )R([1-9][0-5]?)(,)( )([0-9]+)[.]([0-9]+)$"))) //Register and float
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE)( )R([1-9][0-5]?)(,)( )(true|false)$"))) //Register and boolean
        {
            return true;
        }

//Logical instructions
        else if (regex_match (runningcode, regex("^(Not)( )R([1-9][0-5]?)$"))) //Not with Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(And|Or)( )R([1-9][0-5]?)(,)( )(true|false)$"))) //And, Or with Register and boolean
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(And|Or)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //And, Or with Register and Register
        {
            return true;
        }

//Move instructions
        else if (regex_match (runningcode, regex("^(Move)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //Move with Register and Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Move)( )R([1-9][0-5]?)(,)( )([0-9]+)$"))) //Move with Register and interger
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Move)( )R([1-9][0-5]?)(,)( )([0-9]+)[.]([0-9]+)$"))) //Move with Register and float
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Move)( )R([1-9][0-5]?)(,)( )([0-9]+)A$"))) //Move with Register and Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Move)( )R([1-9][0-5]?)(,)( )(true|false)$"))) //Move with Register and boolean
        {
            return true;
        }

//Load instructions
        else if (regex_match (runningcode, regex("^(Load)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //Load with Register and Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Load)( )R([1-9][0-5]?)(,)( )([0-9]+)A$"))) //Load with Register and Address
        {
            return true;
        }

//Store instructions
        else if (regex_match (runningcode, regex("^(Store)( )R([1-9][0-5]?)(,)( )(R[1-9][0-5]?)$"))) //Store with Register and Register
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Store)( )R([1-9][0-5]?)(,)( )([0-9]+)$"))) //Store with Register and interger
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Store)( )R([1-9][0-5]?)(,)( )([0-9]+)[.]([0-9]+)$"))) //Store with Register and float
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Store)( )R([1-9][0-5]?)(,)( )([0-9]+)A$"))) //Store with Register and Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Store)( )R([1-9][0-5]?)(,)( )(true|false)$"))) //Store with Register and boolean
        {
            return true;
        }

//Jump instructions
        else if (regex_match (runningcode, regex("^(Jump)( )([0-9]+)A$"))) //Jump with Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Jump)( )R([1-9][0-5]?)$"))) //Jump with Register
        {
            return true;
        }

//JumpIf instructions
        else if (regex_match (runningcode, regex("^(JumpIf)( )R([1-9][0-5]?)(,)( )([0-9]+)A$"))) //JumpIf with Register and Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(JumpIf)( )R([1-9][0-5]?)(,)( )R([1-9][0-5]?)$"))) //JumpIf with Register and Register
        {
            return true;
        }

//Call instructions
        else if (regex_match (runningcode, regex("^(Call)( )([0-9]+)A$"))) //Call with Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Call)( )R([1-9][0-5]?)$"))) //Call with Register
        {
            return true;
        }

//Return instructions
        else if (regex_match (runningcode, regex("^Return$"))) //Return
        {
            return true;
        }

//Halt instructions
        else if (regex_match (runningcode, regex("^Halt$"))) //Halt
        {
            return true;
        }

//Input instructions
        else if (regex_match (runningcode, regex("^(Input)( )R([1-9][0-5]?)$"))) //Input with Register
        {
            return true;
        }

//Output instructions
        else if (regex_match (runningcode, regex("^(Output)( )([0-9]+)A$"))) //Output with Integer
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Output)( )([0-9]+)[.]([0-9]+)$"))) //Output with float
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Output)( )(true|false)$"))) //Output with boolean
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Output)( )([0-9]+)A$"))) //Output with Address
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(Output)( )(R[1-9][0-5]?)$"))) //Output with register
        {
            return true;
        }
        else return false;
    };

    bool checkValidInstruction(string runningcode)
    {
// Arithmetic instructions
        if (regex_match (runningcode, regex("^(Add|Minus|Mul|Div)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$")))
        {
            return true;
        }

//Comparison instructions
        else if (regex_match (runningcode, regex("^(CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$")))
        {
            return true;
        }

//Logical instructions
        else if (regex_match (runningcode, regex("^(Not)( )([a-zA-Z0-9]+)$"))) //Not
        {
            return true;
        }
        else if (regex_match (runningcode, regex("^(And|Or)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //And, Or
        {
            return true;
        }

//Move instructions
        else if (regex_match (runningcode, regex("^(Move)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //Move
        {
            return true;
        }

//Load instructions
        else if (regex_match (runningcode, regex("^(Load)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //Load
        {
            return true;
        }

//Store instructions
        else if (regex_match (runningcode, regex("^(Store)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //Store
        {
            return true;
        }

//Jump instructions
        else if (regex_match (runningcode, regex("^(Jump)( )([a-zA-Z0-9]+)$"))) //Jump
        {
            return true;
        }

//JumpIf instructions
        else if (regex_match (runningcode, regex("^(JumpIf)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //JumpIf
        {
            return true;
        }

//Call instructions
        else if (regex_match (runningcode, regex("^(Call)( )([a-zA-Z0-9]+)$"))) //Call
        {
            return true;
        }

//Return instructions
        else if (regex_match (runningcode, regex("^Return$"))) //Return
        {
            return true;
        }

//Halt instructions
        else if (regex_match (runningcode, regex("^Halt$"))) //Halt
        {
            return true;
        }

//Input instructions
        else if (regex_match (runningcode, regex("^(Input)( )([a-zA-Z0-9]+)$"))) //Input
        {
            return true;
        }
//Output instructions
        else if (regex_match (runningcode, regex("^(Output)( )([a-zA-Z0-9]+)(,)( )([a-zA-Z0-9]+)$"))) //Output
        {
            return true;
        }
        else return false;
    };

    void readTXT(string testcase)
    {
        string line = "";
        ifstream myfile(testcase);
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                getline(myfile, line);
                this->codeMemory.setCodeMemory(line);
                if (checkValidInstruction(codeMemory.getCodeMemory(IP)) == false)
                {
                    throw InvalidInstruction(IP);
                }
                else if(checkValidOperand(codeMemory.getCodeMemory(IP)) == false)
                {
                    throw InvalidOperand(IP);
                }
            }
            myfile.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    };

    void run(string testcase)
    {
        readTXT(testcase);
        while (running)
        {
            string* instruction = new string[3];
            instruction = decode(codeMemory.getCodeMemory(IP));
            fetch();
            execute(instruction);
        }
    };


    int fetch() // Return address of running code
    {
        return ++this->IP;
    };

    bool CheckInput(string input)
    {
        smatch m;
        regex b("(true|flase)");
        regex in("^[0-9]*$");
        regex fl("^[0-9]+[.][0-9]+$");
        if (regex_match(input, m, b) || regex_match(input, m, in) || regex_match(input, m, fl))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    string* decode(string instruction) // Decode running code
    {
        string* arr = new string[3];
        regex e1("^([A-Za-z]+)( )([A-Za-z0-9]+)(,)( )([A-Za-z0-9.]+)$");
        regex e2("^([A-Za-z]+)( )([A-Za-z0-9.]+)$");
        regex e7("^([A-Za-z]+)$");
        regex e3("^([A-Z][a-zA-Z]+)");
        regex e4("(R[0-9]+)");
        regex e5("([A-Z0-9.a-z]+)$");
        regex e6("A$");

        smatch match;
        if (regex_search(instruction, match, e1))
        {
            if (regex_search(instruction, match, e3))
            {
                arr[0] =  match.str(1);
            }
            if (regex_search(instruction, match, e4))
            {
                arr[1] =  match.str(1);
            }
            if (regex_search(instruction, match, e5))
            {
                arr[2] =  match.str(1);
            }
        }
        else if (regex_search(instruction, match, e2))
        {
            if (regex_search(instruction, match, e3))
            {
                arr[0] =  match.str(1);
            }
            if (regex_search(instruction, match, e5))
            {
                arr[1] =  match.str(1);
            }
        }
        else if (regex_search(instruction, match, e7))
        {
            arr[0] =  match.str(1);
        }

        return arr;
    };

    inline void execute(string opcode[]);        // Excute running code
};
#endif
