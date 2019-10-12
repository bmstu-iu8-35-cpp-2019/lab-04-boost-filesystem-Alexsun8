// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <header.hpp>
#include <boost/filesystem/path.hpp>
#include "../sources/source.cpp"

TEST(dd, dd) {
    std::vector<finance> test;
    boost::filesystem::path p = "../misc";
    test = bypass(p);
    lasts(test);
   // EXPECT_EQ(test.size(), 0)

}