#include "data_base.hpp"
#include <vector>
#include <tuple>
#include <algorithm>
#include <sstream>
#include <stdexcept>

data_base::data_base(const std::string &input) {
    std::string token;
    std::istringstream stream(input);
    for (size_t i = 0; std::getline(stream, token, '\t'); ++i) {
        data[i] = token;
    }
}

size_t data_base::size() const noexcept {
    return data.size();
}

std::string& data_base::get_field(const size_t index) {
    return data.at(index);
}

void data_base::add_field(const size_t index, const std::string &input) {
    if (data.count(index)) {
        throw data_base_exception("Add existing index");
    }
    data[index] = input;
}

void data_base::delete_field(const size_t index) {
    if (!data.count(index)) {
        throw data_base_exception("Index not found");
    }

    data.erase(index);
}

std::ostream& operator<<(std::ostream &os, const data_base &db) {
    std::vector<size_t> numbering(db.size());
    for (auto[it, i] = std::make_tuple(db.data.cbegin(), size_t(0)); it != db.data.cend(); ++i, ++it) {
        numbering[i] = it->first;
    }

    std::sort(numbering.begin(), numbering.end());
    for(const auto& i : numbering) {
        os << i << " " << db.data.at(i) << std::endl;
    }

    return os;
}
