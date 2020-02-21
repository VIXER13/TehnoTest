#ifndef UTILS_HPP
#define UTILS_HPP

#include "data_base.hpp"

void print_common_commands();

data_base::action parse_command(const std::string &input);

void choice_command(data_base &db, const data_base::action command);

#endif
