#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "utils.hpp"

int main() {
    std::cout << "Input data: ";
    std::string input;
    std::getline(std::cin, input);
    data_base db(input);

    print_common_commands();

    while (true) {
        std::cout << std::endl << "Write command: ";
        std::cin >> input;
        input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

        try {
            data_base::action command = parse_command(input);
            if (command == data_base::action::CLS)
                break;
            choice_command(db, command);
        } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        } catch(...) {
            std::cerr << "Invalid input" << std::endl;
        }
    }

    return 0;
}
