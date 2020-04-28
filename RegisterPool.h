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
        std::string regId;
        bool isValid;
        RegisterPool* pool;
    public:
        std::string getRegId();
        Register& operator=(Register && a);
        Register(std::string, RegisterPool*);
        Register(Register&) = delete;
        Register(Register&&);
        Register();
        ~Register();
    };

    RegisterPool();
    Register get();
    void push(std::string);
    int getAvailableCount();
    std::vector<std::string> getUsedRegs();

private:
    std::vector<std::string> availableRegs;
    std::vector<std::string> unavailableRegs;
};


#endif //CPSL_COMPILER_REGISTERPOOL_H
