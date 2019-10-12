// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstddef>
#include <string>
#include <boost/filesystem.hpp>
//#include <filesystem>
#include <experimental/filesystem>
class finance {
private:
    std::string _broker = "";
    unsigned int _account = 0;
    unsigned int _date = 0;
public:
    finance() = default;

    explicit finance(boost::filesystem::path &p);

    explicit finance(boost::filesystem::path &&p);

    finance(const finance &fin);

    ~finance() = default;

    finance &operator=(const finance &fin);

    finance &operator=(finance &&fin)  noexcept ;
    bool operator==(finance &fin);

    static finance newer(std::vector<finance> &vector);

    std::string broker();

    unsigned int account();

    unsigned int date();
};

#endif // INCLUDE_HEADER_HPP_
