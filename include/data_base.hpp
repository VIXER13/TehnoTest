#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP

#include <iostream>
#include <unordered_map>
#include <exception>
#include <string>

class data_base_exception : public std::exception {
    std::string message;

 public:
    explicit data_base_exception(const std::string& str) :
        message(str) {}

    const char* what() const noexcept override {
        return message.data();
    }
};

class data_base {
    std::unordered_map<size_t, std::string> data;

 public:
    enum class action : uint8_t { EDT, ADD, DEL, WRT, CLS };

    explicit data_base(const std::string &input);

    size_t size() const noexcept;

    std::string& get_field(const size_t index);

    void add_field(const size_t index, const std::string &input);
    void delete_field(const size_t index);

    friend std::ostream& operator<<(std::ostream &os, const data_base &db);
};

#endif
