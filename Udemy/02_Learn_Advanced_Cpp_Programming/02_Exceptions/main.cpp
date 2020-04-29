#include <iostream>
#include <exception>



class BrpfError : std::exception {
public:
    explicit BrpfError(const std::string& message) : message{message} {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message{""};
};

void mightGoWrong() {
    bool error1 = false;
    bool error2 = true;
    if (error1)
        throw "Something went wrong.";
    if (error2)
        throw BrpfError("Something went wrong again.");

}

void useMightGoWrong() {
    auto memory = new char[9999999999999999];
    delete [] memory;
}

int main() {
    try {
        useMightGoWrong();
    } catch (int e) {
        std::cout << "Error code: " << e << std::endl;
    } catch (const char* errorMsg) {
        std::cout << errorMsg;
    } catch (std::string& errorMsg) {
        std::cout << errorMsg;
    } catch (BrpfError& e) {
        std::cout << e.what();
    } catch (std::bad_alloc& e) {
        std::cout << e.what();
    }

    return 0;
}
