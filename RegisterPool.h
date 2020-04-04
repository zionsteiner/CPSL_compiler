//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_REGISTERPOOL_H
#define CPSL_COMPILER_REGISTERPOOL_H


#include <string>
#include <vector>

class RegisterPool {
public:
    class Register{
    private:
        const std::string reg;
        bool isValid;
        RegisterPool* pool;
    public:
        Register(std::string, RegisterPool*);
        Register(Register&) = delete;
        Register(Register&&);
        ~Register();
    };

    RegisterPool();
    Register get();
    void push(Register*);

private:
    std::vector<std::string> availableRegs;
};


#endif //CPSL_COMPILER_REGISTERPOOL_H
