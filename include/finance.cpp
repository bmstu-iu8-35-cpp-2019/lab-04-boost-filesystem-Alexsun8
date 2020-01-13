// Copyright 2018 Your Name <your_email>

#include "header.hpp"

finance::finance(const boost::filesystem::path &p) {
  boost::filesystem::path parent = p.parent_path().filename();
  _broker = parent.string();
  std::string num = "", filename = p.filename().string(), date = "";
  for (size_t i = num_start_place; i < num_end_place; i++) num += filename[i];
  _account = atoi(num.c_str());
  //    num = "";

  for (size_t i = num_end_place + 1; i < end_place; i++) date += filename[i];
  _date = atoi(date.c_str());

  //    std::cout<<std::endl<<date<<std::endl;
}

finance::finance(boost::filesystem::path &&p) {
  _broker = p.parent_path().filename().string();
  std::string num = "", filename = p.filename().string();
  for (size_t i = num_start_place; i < num_end_place; i++) num += filename[i];
  _account = atoi(num.c_str());
  num = "";
  for (size_t i = num_end_place + 1; i < end_place; i++) num += filename[i];
  _date = atoi(num.c_str());
  //    std::cout<<std::endl<<num<<std::endl;
}

// finance::finance(finance &fin) = default;
finance::finance(const finance &fin)
    : _broker(fin._broker), _account(fin._account), _date(fin._date) {}

finance &finance::operator=(const finance &fin) = default;

finance &finance::operator=(finance &&fin) noexcept = default;

bool finance::operator==(finance &fin) { return fin._account == _account; }

finance finance::newer(std::vector<finance> &vector) {
  finance newest = vector[0];
  for (size_t i = 1; i < vector.size(); i++) {
    if (newest._date < vector[i]._date) newest = vector[i];
  }
  return newest;
}

std::string finance::broker() { return _broker; }

unsigned int finance::account() { return _account; }

unsigned int finance::date() { return _date; }
