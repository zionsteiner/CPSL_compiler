//
// Created by zion on 3/28/20.
//

#include <string>
#include <iostream>
#include "RegisterPool.h"

RegisterPool::RegisterPool() {
    // $t0-$t7, $s0-$s7, $t8-$t9
    for (int i = 8; i <= 25; ++i) {
        std::string regId = "$" + std::to_string(i);
        availableRegs.push_back(regId);
    }
}

RegisterPool::Register RegisterPool::get() {
    std::string regId = availableRegs.back();
    availableRegs.pop_back();
    std::cout << "GET " << regId << "\nSIZE: " << availableRegs.size() << std::endl;

    return Register(regId, this);
}

void RegisterPool::push(std::string regId) {
    availableRegs.push_back(regId);
    std::cout << "PUT " << regId << "\nSIZE: " << availableRegs.size() << std::endl;
}

std::string RegisterPool::Register::getRegId() {return regId;}

RegisterPool::Register::Register(std::string regId, RegisterPool* pool): regId(regId), pool(pool), isValid(true) {}

RegisterPool::Register::Register(Register&& a): regId(a.regId), isValid(true), pool(a.pool) {a.isValid = false;}

RegisterPool::Register::Register(): isValid(false) {
    this->pool = nullptr;
}

RegisterPool::Register::~Register() {
    if (isValid) {
        pool->push(regId);
    }
}

RegisterPool::Register &RegisterPool::Register::operator=(RegisterPool::Register &&a) {
    if (isValid) {
        pool->push(regId);
        regId = "";
    }

    this->regId = a.regId;
    this->pool = a.pool;
    this->isValid = true;

    a.isValid = false;

    return *this;
}

int RegisterPool::getAvailableCount() {
    return availableRegs.size();
}
