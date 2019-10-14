// Copyright 2018 Your Name <your_email>

#include <header.hpp>

bool filename_is_okey(boost::filesystem::path &p) {
  std::string filename, f1;
  filename = p.filename().string();
  if (filename.size() != 29) return false;
  for (size_t i = 0; i < 8; i++) f1 += filename[i];
  if (f1 != "balance_") return false;
  f1.clear();
  for (size_t i = 8; i < 16; i++) {
    if (filename[i] < '0' || filename[i] > '9') return false;
  }
  if (filename[16] != '_') return false;
  for (size_t i = 17; i < 21; i++) {
    if (filename[i] < '0' || filename[i] > '9') return false;
  }
  //месяц
  if (filename[21] > '1' || (filename[21] == '1' && filename[22] > '2'))
    return false;
  //число
  if (filename[23] > '3' || (filename[23] == '3' && filename[24] > '1'))
    return false;

  return !(p.extension() != ".txt");
}

// std::vector<std::unordered_map< std::string, boost::filesystem::path>>
// bypass(boost::filesystem::path &p) {
std::vector<finance> bypass(boost::filesystem::path &p) {
  if (!exists(p)) throw std::logic_error("path doesn't exist");

  //    std::vector<std::unordered_map<std::string, boost::filesystem::path>>
  //    files, temp; std::unordered_map<std::string, boost::filesystem::path>
  //    map; std::vector<std::string>
  std::vector<finance> files, temp;
  boost::filesystem::path temp_path;

  for (const boost::filesystem::directory_entry &x :
       boost::filesystem::directory_iterator{p}) {
    if (is_regular_file(x)) {
      temp_path = x.path();
      //            std::cout<<"Проверка is ok"<<std::endl;
      if (filename_is_okey(temp_path)) {
        std::cout << temp_path.parent_path().filename() << "   "
                  << temp_path.filename() << std::endl;
        files.emplace_back(temp_path);
      }
    } else {
      if (is_symlink(x)) {
        temp_path = read_symlink(x);
        temp = bypass(temp_path);
        //                for (const auto &i : temp)
        //                    files.push_back(i);
        for (const auto &i : temp) files.push_back(i);
      } else {
        if (is_directory(x)) {
          //                    std::cout<<std::endl<<"Вошёл в
          //                    папку"<<std::endl;
          temp_path = x.path();
          temp = bypass(temp_path);
          //                    for (const auto &i : temp)
          //                        files.push_back(i);
          for (const auto &i : temp) files.push_back(i);
        }
      }
    }
  }

  //    std::cout<<std::endl<<"Список выписан"<<std::endl;
  return files;
}

void lasts(std::vector<finance> vec) {
  if (vec.empty()) return;
  finance newest = vec[0];

  vec.erase(vec.begin());
  size_t files = 1;
  //    std::cout<<std::endl<<"размер вектора "<<vec.size()<<std::endl<<"newest:
  //    "<<newest.date()<<std::endl;
  //  std::cout<<std::endl<<"start last";
  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] == newest && vec[i].broker() == newest.broker()) {
      //            newest = std::move(vec[i]);
      if (vec[i].date() > newest.date()) newest = vec[i];
      vec.erase(vec.begin() + i);

      files++;
      i--;

      //            std::cout<<std::endl<<"размер вектора
      //            "<<vec.size()<<std::endl<<"newest:
      //            "<<newest.date()<<std::endl;
    }
  }
  std::cout << std::endl
            << "broker:  " << newest.broker()
            << "  account: " << newest.account() << "  files:  " << files
            << "  last date:  " << newest.date();
  lasts(vec);
}
