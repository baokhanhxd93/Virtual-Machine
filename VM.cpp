#include "VM.h"

void VM::execute(string instruct[]) // Assume that dest is always a register, otherwise add new conditions
{
    Instructions Opperator = readInstruction(instruct[0]);
    switch (Opperator)
    {
    case Instructions::Add: // Add dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest + src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest + src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains an interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            float temp = dest + src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            int temp = dest + src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else   // src contains a boolean value
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    float temp = dest + src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    int temp = dest + src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest + src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest + src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::Minus: // Minus dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest - src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest - src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains an interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            float temp = dest - src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            int temp = dest - src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else   // src contains a boolean value
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    float temp = dest - src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    int temp = dest - src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest - src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest - src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }

    case Instructions::Mul: // Mul dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest * src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            float temp = dest * src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains an interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            float temp = dest * src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            int temp = dest * src;
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else   // src contains a boolean value
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    float temp = dest * src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    int temp = dest * src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest * src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    float temp = dest * src;
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains a boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }

    case Instructions::Div: // Div dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getVarData().getInVar() == 0 || this->Register[srcIndex].getVarData().getInVar() == 0.0 )
                    {
                        throw DivideByZero(IP - 1);
                    }
                    else
                    {
                        if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                        {
                            if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                            {
                                float dest = this->Register[destIndex].getVarData().getFlVar();
                                float src = this->Register[srcIndex].getVarData().getFlVar();
                                float temp = dest / src;
                                Variable tempVar;
                                tempVar.setVariable(temp);
                                this->Register[destIndex].setData(tempVar);
                            }
                            else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                            {
                                int dest = this->Register[destIndex].getVarData().getInVar();
                                float src = this->Register[srcIndex].getVarData().getFlVar();
                                float temp = dest / src;
                                Variable tempVar;
                                tempVar.setVariable(temp);
                                this->Register[destIndex].setData(tempVar);
                            }
                            else   // dest contains a boolean value
                            {
                                throw TypeMismatch(IP - 1);
                            }
                        }
                        else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains an interger value
                        {
                            if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                            {
                                float dest = this->Register[destIndex].getVarData().getFlVar();
                                int src = this->Register[srcIndex].getVarData().getInVar();
                                float temp = dest / src;
                                Variable tempVar;
                                tempVar.setVariable(temp);
                                this->Register[destIndex].setData(tempVar);
                            }
                            else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                            {
                                int dest = this->Register[destIndex].getVarData().getInVar();
                                int src = this->Register[srcIndex].getVarData().getInVar();
                                float temp = dest / src;
                                Variable tempVar;
                                tempVar.setVariable(temp);
                                this->Register[destIndex].setData(tempVar);
                            }
                            else   // dest contains a boolean value
                            {
                                throw TypeMismatch(IP - 1);
                            }
                        }
                        else   // src contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->readInteger(instruct[2]) == 0)
                {
                    throw DivideByZero(IP - 1);
                }
                else
                {
                    if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                    {
                        float dest = this->Register[destIndex].getVarData().getFlVar();
                        int src = readInteger(instruct[2]);
                        float temp = dest / src;
                        Variable tempVar;
                        tempVar.setVariable(temp);
                        this->Register[destIndex].setData(tempVar);
                    }
                    else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                    {
                        int dest = this->Register[destIndex].getVarData().getInVar();
                        int src = readInteger(instruct[2]);
                        float temp = dest / src;
                        Variable tempVar;
                        tempVar.setVariable(temp);
                        this->Register[destIndex].setData(tempVar);
                    }
                    else   // dest contains a boolean value
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->readFloat(instruct[2]) == 0.0)
                {
                    throw DivideByZero(IP - 1);
                }
                else
                {
                    if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                    {
                        float dest = this->Register[destIndex].getVarData().getFlVar();
                        float src = readFloat(instruct[2]);
                        float temp = dest / src;
                        Variable tempVar;
                        tempVar.setVariable(temp);
                        this->Register[destIndex].setData(tempVar);
                    }
                    else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                    {
                        int dest = this->Register[destIndex].getVarData().getInVar();
                        float src = readFloat(instruct[2]);
                        float temp = dest / src;
                        Variable tempVar;
                        tempVar.setVariable(temp);
                        this->Register[destIndex].setData(tempVar);
                    }
                    else   // dest contains a boolean value
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
            }
        }
        break;
    }

    case Instructions::CmpEQ: // CmpEQ dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest == src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest == src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest == src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest == src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest == src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest == src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest == src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest == src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest == src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest == src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::CmpNE: // CmpNE dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest != src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest != src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest != src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest != src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest != src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest != src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest != src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest != src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest != src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest != src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::CmpLT: // CmpLT dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest < src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest < src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest < src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest < src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest < src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest < src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest < src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest < src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest < src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest < src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::CmpLE: // CmpLE dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest <= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest <= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest <= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest <= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest <= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest <= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest <= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest <= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest <= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest <= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::CmpGT: // CmpGT dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest > src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest > src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest > src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest > src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest > src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest > src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest > src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest > src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest > src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest > src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::CmpGE: // CmpGE dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add)   // dest contains an address
        {
            throw TypeMismatch(IP - 1);
        }
        else   // dest contains a contains value (float, int or bool)
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                {
                    throw TypeMismatch(IP - 1);
                }
                else   // src contains a contains value (float, int or bool)
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                        {
                            bool dest = this->Register[destIndex].getVarData().getBlVar();
                            bool src = this->Register[srcIndex].getVarData().getBlVar();
                            bool temp = (dest >= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   //dest contains float or int
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest >= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            float src = this->Register[srcIndex].getVarData().getFlVar();
                            bool temp = (dest >= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                    else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                    {
                        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains a float value
                        {
                            float dest = this->Register[destIndex].getVarData().getFlVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest >= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else if (this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains a int value
                        {
                            int dest = this->Register[destIndex].getVarData().getInVar();
                            int src = this->Register[srcIndex].getVarData().getInVar();
                            bool temp = (dest >= src);
                            Variable tempVar;
                            tempVar.setVariable(temp);
                            this->Register[destIndex].setData(tempVar);
                        }
                        else   // dest contains a boolean value
                        {
                            throw TypeMismatch(IP - 1);
                        }
                    }
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a constant boolean value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = readBoolean(instruct[2]);
                    bool temp = (dest >= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains float or interger
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 2)   // src is an address
            {
                throw TypeMismatch(IP - 1);
            }
            else if (typeDetect(instruct[2]) == 3)   // src is a constant interger value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest >= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    int src = readInteger(instruct[2]);
                    bool temp = (dest >= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 4)   // src is a constant float value
            {
                if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // dest contains an interger value
                {
                    int dest = this->Register[destIndex].getVarData().getInVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest >= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Float)   // dest contains an float value
                {
                    float dest = this->Register[destIndex].getVarData().getFlVar();
                    float src = readFloat(instruct[2]);
                    bool temp = (dest >= src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else   // dest contains an boolean value
                {
                    throw TypeMismatch(IP - 1);
                }
            }
        }
        break;
    }
    case Instructions::Not: // Not dest
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
        {
            bool dest = this->Register[destIndex].getVarData().getBlVar();
            bool temp = !dest;
            Variable tempVar;
            tempVar.setVariable(temp);
            this->Register[destIndex].setData(tempVar);
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }
    case Instructions::And: // And dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   //source contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = this->Register[srcIndex].getVarData().getBlVar();
                    bool temp = (dest & src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a const bool value
            {
                bool dest = this->Register[destIndex].getVarData().getBlVar();
                bool src = readBoolean(instruct[2]);
                bool temp = (dest & src);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->Register[destIndex].setData(tempVar);
            }
            else
            {
                throw TypeMismatch(IP - 1);
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }

    case Instructions::Or: // Or dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
        {
            if (typeDetect(instruct[2]) == 0)   // src is a register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var && this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   //source contains a boolean value
                {
                    bool dest = this->Register[destIndex].getVarData().getBlVar();
                    bool src = this->Register[srcIndex].getVarData().getBlVar();
                    bool temp = (dest | src);
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else
                {
                    throw TypeMismatch(IP -1);
                }
            }
            else if (typeDetect(instruct[2]) == 1)   // src is a const bool value
            {
                bool dest = this->Register[destIndex].getVarData().getBlVar();
                bool src = readBoolean(instruct[2]);
                bool temp = (dest | src);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->Register[destIndex].setData(tempVar);
            }
            else
            {
                throw TypeMismatch(IP - 1);
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }

    case Instructions::Move: // Move dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (typeDetect(instruct[2]) == 0)   // src is a register
        {
            int srcIndex = readRegister(instruct[2]) - 1;
            if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
            {
                int addr = this->Register[srcIndex].getAddrData();
                this->Register[destIndex].setData(addr);
            }
            else if (this->Register[srcIndex].getDataTypeFunction() == DataType::Var)   // src contains a value
            {
                if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                {
                    bool temp = this->Register[srcIndex].getVarData().getBlVar();
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)   // src contains a interger value
                {
                    int temp = this->Register[srcIndex].getVarData().getInVar();
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
                else if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)   // src contains a float value
                {
                    float temp = this->Register[srcIndex].getVarData().getFlVar();
                    Variable tempVar;
                    tempVar.setVariable(temp);
                    this->Register[destIndex].setData(tempVar);
                }
            }
        }
        else if (typeDetect(instruct[2]) == 1)   // src is a boolean constant value
        {
            bool temp = readBoolean(instruct[2]);
            Variable tempVar;
            tempVar.setVariable(temp);
            this->Register[destIndex].setData(tempVar);
        }
        else if (typeDetect(instruct[2]) == 2)   // src is a constant address
        {
            int addr = readAddress(instruct[2]);
            this->Register[destIndex].setData(addr);
        }
        else if (typeDetect(instruct[2]) == 3)   // src is a interger constant value
        {
            int temp = readInteger(instruct[2]);
            Variable tempVar;
            tempVar.setVariable(temp);
            this->Register[destIndex].setData(tempVar);
        }
        else if (typeDetect(instruct[2]) == 4)   // src is a float constant value
        {
            float temp = readFloat(instruct[2]);
            Variable tempVar;
            tempVar.setVariable(temp);
            this->Register[destIndex].setData(tempVar);
        }
        break;
    }

    case Instructions::Load: // Load dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (typeDetect(instruct[2]) == 2)   // src is an constant address
        {
            int addr = readAddress(instruct[2]); // get address of variable stored in static memory
            Variable var = this->staticMemory.getSMemory(addr);
            this->Register[destIndex].setData(var);
        }
        else if(typeDetect(instruct[2]) == 0)   // src is a register
        {
            int srcIndex = readRegister(instruct[2]) - 1;
            if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
            {
                int addr = this->Register[srcIndex].getAddrData();
                Variable var = this->staticMemory.getSMemory(addr);
                this->Register[destIndex].setData(var);
            }
            else   // src does not contain an address
            {
                throw TypeMismatch(IP - 1);
            }
        }
        else   // src is not a constant address
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }

    case Instructions::Store: // Store dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Add) // Address
        {
            int storeAddr = this->Register[destIndex].getAddrData();
            if (typeDetect(instruct[2]) == 0) // Register
            {
                int srcIndex = readRegister(instruct[2]) - 1;
                if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add) // Adress
                {
                    throw TypeMismatch(IP - 1);
                }
                else // Not ad
                {
                    Variable tempVar = this->Register[srcIndex].getVarData();
                    this->staticMemory.setSMemory(tempVar, storeAddr);
                }
            }
            else if (typeDetect(instruct[2]) == 1)
            {
                bool temp = readBoolean(instruct[2]);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->staticMemory.setSMemory(tempVar, storeAddr);
            }
            else if (typeDetect(instruct[2]) == 2)
            {
                throw TypeMismatch(IP);
            }
            else if (typeDetect(instruct[2]) == 3)
            {
                int temp = readInteger(instruct[2]);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->staticMemory.setSMemory(tempVar, storeAddr);
            }
            else if (typeDetect(instruct[2]) == 4)
            {
                float temp = readFloat(instruct[2]);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->staticMemory.setSMemory(tempVar, storeAddr);
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }

    case Instructions::Jump: // Jump src
    {
        if (typeDetect(instruct[1]) == 0)   // src is a register
        {
            int srcIndex = readRegister(instruct[1]) - 1;
            if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
            {
                if (this->Register[srcIndex].getAddrData() < 0 || this->Register[srcIndex].getAddrData() > codeMemory.getCurr())
                {
                    throw InvalidDestination(IP - 1);
                }
                else
                {
                    int tempAdd = this->Register[srcIndex].getAddrData();
                    this->IP = tempAdd;
                }
            }
            else
            {
                throw TypeMismatch(IP - 1);
            }
        }
        else if (typeDetect(instruct[1]) == 2)   // src is an address
        {
            if (readAddress(instruct[1]) < 0 || readAddress(instruct[1]) > codeMemory.getCurr())
            {
                throw InvalidDestination(IP - 1);
            }
            else
            {
                int tempAdd = readAddress(instruct[1]);
                this->IP = tempAdd;
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }
    case Instructions::JumpIf: // JumpIf dest, src
    {
        int destIndex = readRegister(instruct[1]) - 1;
        int srcIndex = readRegister(instruct[2]) - 1;
        if (this->Register[destIndex].getDataTypeFunction() == DataType::Var && this->Register[destIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // dest contains a boolean value
        {
            if (Register[destIndex].getVarData().getBlVar() == true)
            {
                if (typeDetect(instruct[2]) == 0)   // src is a register
                {
                    if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
                    {
                        if (this->Register[srcIndex].getAddrData() < 0 || this->Register[srcIndex].getAddrData() > codeMemory.getCurr())
                        {
                            throw InvalidDestination(IP - 1);
                        }
                        else
                        {
                            int tempAdd = this->Register[srcIndex].getAddrData();
                            this->IP = tempAdd;
                        }
                    }
                    else
                    {
                        throw TypeMismatch(IP - 1);
                    }
                }
                else if (typeDetect(instruct[2]) == 2)   // src is an address
                {
                    if (readAddress(instruct[2]) < 0 || readAddress(instruct[2]) > codeMemory.getCurr())
                    {
                        throw InvalidDestination(IP - 1);
                    }
                    else
                    {
                        int tempAdd = readAddress(instruct[2]);
                        this->IP = tempAdd;
                    }
                }
                else
                {
                    throw TypeMismatch(IP - 1);
                }
            }
            else if (Register[destIndex].getVarData().getBlVar() == false)
            {
                if (typeDetect(instruct[2]) != 2 || (typeDetect(instruct[2]) != 0 && Register[srcIndex].getDataTypeFunction() == DataType::Add))
                {
                    throw TypeMismatch(IP - 1);
                    break;
                }
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }
    case Instructions::Call: // Call src
    {
        if (typeDetect(instruct[1]) == 0)   // src is a register
        {
            int srcIndex = readRegister(instruct[1]) - 1;
            if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
            {
                if (this->Register[srcIndex].getAddrData() < 0 || this->Register[srcIndex].getAddrData() > codeMemory.getCurr())
                {
                    throw InvalidDestination(IP - 1);
                }
                else
                {
                    if (stackMemory.IsFull() == true)
                    {
                        throw StackFull(IP - 1);
                    }
                    else
                    {
                        this->stackMemory.Push(this->IP); // load IP to stack
                        int tempAdd = this->Register[srcIndex].getAddrData();
                        this->IP = tempAdd;
                    }
                }
            }
            else
            {
                throw TypeMismatch(IP - 1);
            }
        }
        else if (typeDetect(instruct[1]) == 2)   // src is an address
        {
            if (readAddress(instruct[1]) < 0 || readAddress(instruct[1]) > codeMemory.getCurr())
            {
                throw InvalidDestination(IP - 1);
            }
            else
            {
                if (stackMemory.IsFull() == true)
                {
                    throw StackFull(IP - 1);
                }
                else
                {
                    this->stackMemory.Push(this->IP); // load IP to stack
                    int tempAdd = readAddress(instruct[1]);
                    this->IP = tempAdd;
                }
            }
        }
        else
        {
            throw TypeMismatch(IP - 1);
        }
        break;
    }
    case Instructions::Return: // Return
    {
        this->IP = this->stackMemory.Pop();
        break;
    }
    case Instructions::Halt: // Halt
    {
        this->running = false; // set running flag to false
        break;
    }
    case Instructions::Input:
    {
        int destIndex = readRegister(instruct[1]) - 1;
        string dest;
        cin >> dest;
        if (CheckInput(dest) == true)
        {
            if (typeDetect(dest) == 1)
            {
                bool temp = readBoolean(dest);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->Register[destIndex].setData(tempVar);
            }
            else if (typeDetect(dest) == 3)
            {
                int temp = readBoolean(dest);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->Register[destIndex].setData(tempVar);
            }
            else if (typeDetect(dest) == 4)
            {
                float temp = readBoolean(dest);
                Variable tempVar;
                tempVar.setVariable(temp);
                this->Register[destIndex].setData(tempVar);
            }
        }
        else
        {
            throw InvalidInput(IP - 1);
        }
        break;
    }
    case Instructions::Output: // Output src
    {
        if (typeDetect(instruct[1]) == 0)   // src is a register
        {
            int srcIndex = readRegister(instruct[1]) - 1;
            if (this->Register[srcIndex].getDataTypeFunction() == DataType::Add)   // src contains an address
            {
                int temp = this->Register[srcIndex].getAddrData();
                cout << temp << "A";
            }
            else
            {
                if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Boolean)   // src contains a boolean value
                {
                    if (this->Register[srcIndex].getVarData().getBlVar() == true)
                    {
                        cout << true;
                    }
                    else if (this->Register[srcIndex].getVarData().getBlVar() == false)
                    {
                        cout << false;
                    }
                }
                else if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Float)
                {
                    float temp = this->Register[srcIndex].getVarData().getFlVar();
                    cout << temp;
                }
                else if (this->Register[srcIndex].getVarData().getVarTypeFunction() == VarType::Integer)
                {
                    int temp = this->Register[srcIndex].getVarData().getInVar();
                    cout << temp;
                }
            }
        }
        else
        {
            cout << instruct[1];
        }
        break;
    }
    case Instructions::NONE:
    {
        break;
    }
    default:
    {
        break;
    }
    }
}
