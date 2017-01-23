//
// Created by fedor on 23/01/17.
//

#include <gtest/gtest.h>
#include "box.h"

using namespace std;

TEST(box, string_constructor_ok)
{
    map<string, capd::interval> edges;
    edges.insert(make_pair("a", capd::interval("0","1")));
    edges.insert(make_pair("b", capd::interval("-0.1","0.1")));
    edges.insert(make_pair("c_index", capd::interval("0","0")));
    EXPECT_EQ(box(edges), box("a : [0,1];b:[ -0.1, 0.1];c_index:[0,  0];"));
}

TEST(box, string_constructor_no_trailing_semicolon)
{
    EXPECT_THROW(box("a : [0,1];b:[ -0.1, 0.1];c_index:[0,  0]"), invalid_argument);
}

TEST(contains, one_box_contains_another)
{
    box b("a:[0,1];b:[0,1];c:[0,1];");
    EXPECT_TRUE(b.contains(box("a:[0,0.5];b:[0.5,0.5];c:[0.5,1];")));
}

TEST(contains, boxes_intersect)
{
    box b("a:[0,1];b:[0,1];c:[0,1];");
    EXPECT_FALSE(b.contains(box("a:[0.1,1.1];b:[0,1];c:[0,1];")));
}

TEST(contains, boxes_are_equal)
{
    box b("a:[0,1];b:[0,1];c:[0,1];");
    EXPECT_TRUE(b.contains(box("a:[0.0,1.0];b:[0,1];c:[0,1];")));
}