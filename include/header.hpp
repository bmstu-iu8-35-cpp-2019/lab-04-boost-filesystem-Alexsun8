// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <boost/filesystem.hpp>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

class finance {
 private:
  std::string _broker = "";
  unsigned int _account = 0;
  unsigned int _date = 0;

 public:
  finance() = default;

  explicit finance(const boost::filesystem::path &p);

  explicit finance(boost::filesystem::path &&p);

  finance(const finance &fin);

  ~finance() = default;

  finance &operator=(const finance &fin);

  finance &operator=(finance &&fin) noexcept;

  bool operator==(finance &fin);

  static finance newer(std::vector<finance> &vector);

  std::string broker();

  unsigned int account();

  unsigned int date();
};

bool filename_is_okey(boost::filesystem::path &p);

std::vector<finance> bypass(boost::filesystem::path &p);

void lasts(std::vector<finance> vec);

#endif  // INCLUDE_HEADER_HPP_
