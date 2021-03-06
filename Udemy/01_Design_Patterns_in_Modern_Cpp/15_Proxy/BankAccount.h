#pragma once

#include <iostream>

struct BankAccount {
    int balance{0};
    int overdraft_limit{-500};

    void deposit(int amount) {
        balance += amount;
        std::cout << "deposited " << amount
             << ", balance is now " << balance << std::endl;

    }

    bool withdraw(int amount) {
        if (balance - amount >= overdraft_limit) {
            balance -= amount;
            std::cout << "withdrew " << amount
                 << ", balance is now " << balance << std::endl;
            return true;
        } else {
            return false;
        }
    }

    friend std::ostream &
    operator<<(std::ostream &os, const BankAccount &account) {
        os << "balance: " << account.balance;
        return os;
    }
};