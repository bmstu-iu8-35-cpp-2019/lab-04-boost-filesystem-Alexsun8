// Copyright 2018 Your Name <your_email>

#include <header.hpp>

int main() {
  // int main(int argc, char *argv[]){
  //    if(argc < 2 )throw std::logic_error("Не введён путь к файлу");

  //    const boost::filesystem::path p(argv[1]);  // avoid repeated path
  //    construction below
  boost::filesystem::path p = "../misc";
  std::vector<finance> files = bypass(p);
  std::cout << std::endl << "Задание 1 закончено" << std::endl;
  lasts(files);

  return 0;
}
