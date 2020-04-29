#pragma once

#include "BankAccount.h"

struct Command {
    bool succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};

struct BankAccountCommand : Command {
    BankAccount& account;
    enum Action {deposit, withdraw } action;
    int amount;

    BankAccountCommand(BankAccount &account, Action action, int amount)
            : account(account), action(action), amount(amount) {}

    void call() override {
        switch (action) {
            case deposit:
                account.deposit(amount);
                succeeded = true;
                break;
            case withdraw:
                succeeded = account.withdraw(amount);
                break;
        }
    }

    void undo() override {
        if (!succeeded) return;

        switch (action) {
            case deposit:
                account.withdraw(amount);
                break;
            case withdraw:
                account.deposit(amount);
                break;
        }

    }
};

using init_list = std::initializer_list<BankAccountCommand>;

struct CompositeBankAccountCommand
        : std::vector<BankAccountCommand>, Command {
    CompositeBankAccountCommand(const init_list& items) : vector(items) {}
};