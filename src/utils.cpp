#include "utils.hpp"
#include <string.h>

data_base::action parse_command(const std::string &input) {
    static constexpr char edt_cmd[] = "edt";
    static constexpr char add_cmd[] = "add";
    static constexpr char del_cmd[] = "del";
    static constexpr char wrt_cmd[] = "wrt";
    static constexpr char cls_cmd[] = "cls";

    if (!strcmp(input.data(), edt_cmd)) {
        return data_base::action::EDT;
    }

    if (!strcmp(input.data(), add_cmd)) {
        return data_base::action::ADD;
    }

    if (!strcmp(input.data(), del_cmd)) {
        return data_base::action::DEL;
    }

    if (!strcmp(input.data(), wrt_cmd)) {
        return data_base::action::WRT;
    }

    if (!strcmp(input.data(), cls_cmd)) {
        return data_base::action::CLS;
    }

    throw std::invalid_argument("Wrong command!");
}

void print_common_commands() {
    std::cout << "common commands:"        << std::endl
              << "* edt — edit field"      << std::endl
              << "* add — add field"       << std::endl
              << "* del — delete field"    << std::endl
              << "* wrt — write data"      << std::endl
              << "* cls — close data base" << std::endl;
}

static size_t ask_index() {
    std::cout << "Input index: ";
    std::string input;
    std::cin >> input;
    return std::stoul(input);
}

void choice_command(data_base &db, const data_base::action command) {
    switch (command) {
    case data_base::action::EDT : {
            size_t index = ask_index();
            std::cout << "Input new string: ";
            std::cin >> db.get_field(index);
    }
    break;

    case data_base::action::ADD : {
        size_t index = ask_index();
        std::cout << "Input new string: ";
        std::string input;
        std::cin >> input;
        db.add_field(index, input);
    }
    break;

    case data_base::action::DEL : {
        db.delete_field(ask_index());
    }
    break;

    case data_base::action::WRT : {
        std::cout << db << std::endl;
    }
    break;

    default:
    break;
    }
}
