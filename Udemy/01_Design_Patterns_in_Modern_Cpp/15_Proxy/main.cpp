#include <iostream>
#include <vector>
#include "BankAccount.h"
#include "Command.h"

using namespace std;

int main() {
    BankAccount account;

    vector<BankAccountCommand> commands {
        BankAccountCommand{account, BankAccountCommand::deposit, 100},
        BankAccountCommand{account, BankAccountCommand::withdraw, 200}
    };

    std::cout << account << endl;

    for (auto& cmd : commands)
        cmd.call();

    for (auto it = commands.rbegin(); it != commands.rend(); ++it) {
        it->undo();
    }

    // Assignment


    return 0;
}
