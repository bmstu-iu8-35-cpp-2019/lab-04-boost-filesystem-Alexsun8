// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include "../include/header.hpp"


TEST(BOOST, BOOST_SOURCE_Test) {
    std::vector<finance> test;
    boost::filesystem::path p = "../misc";
    test = bypass(p);
    std::cout << std::endl << "Задание 1 закончено" << std::endl;
    lasts(test);
    // EXPECT_EQ(test.size(), 0)
}
