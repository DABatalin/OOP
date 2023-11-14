#include <gtest/gtest.h>
#include <iostream>

#include "array.h"
#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"


TEST(hexagon, default_constructor)
{
	Hexagon hex;
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(hex.get_area(), 0);
	ASSERT_EQ(hex.get_middle_point(), para);
	ASSERT_EQ(hex.get_points().size(), 6);
}

TEST(hexagon, area1)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;
	v[5].first = 3; v[5].second = 2;

	Hexagon hex(v);
	ASSERT_EQ(hex.get_area(), 4);
	ASSERT_EQ(hex.get_points(), v);
}

TEST(hexagon, area2)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;
	v[4].first = 0; v[4].second = 0;
	v[5].first = 0; v[5].second = 0;

	Hexagon hex(v);
	ASSERT_EQ(hex.get_area(), 0);
	ASSERT_EQ(hex.get_points(), v);
}

TEST(hexagon, middle_point1)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;
	v[5].first = 3; v[5].second = 2;

	Hexagon hex(v);
	std::pair<double, double> para;
	para.first = 2;
	para.second = 2.5;
	ASSERT_EQ(hex.get_middle_point(), para);
	ASSERT_EQ(hex.get_points(), v);
}

TEST(hexagon, middle_point2)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;
	v[4].first = 0; v[4].second = 0;
	v[5].first = 0; v[5].second = 0;

	Hexagon hex(v);
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(hex.get_middle_point(), para);
	ASSERT_EQ(hex.get_points(), v);
}

TEST(hexagon, side_amount)
{
	std::vector<std::pair<double, double>> v(7);

	EXPECT_THROW(Hexagon hex(v), std::invalid_argument);
}

TEST(hexagon, eq_operator)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;
	v[5].first = 3; v[5].second = 2;

	std::vector<std::pair<double, double>> v1(6);
	v1[0].first = 3; v1[0].second = 2;
	v1[1].first = 2; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 5;
	v1[4].first = 4; v1[4].second = 4;
	v1[5].first = 4; v1[5].second = 3;

	Hexagon hex1(v);
	Hexagon hex2(v);
	Hexagon hex3(v1);

	ASSERT_EQ(hex1, hex2);
	ASSERT_FALSE(hex1 == hex3);
}

TEST(hexagon, copy_operator)
{
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;
	v[5].first = 3; v[5].second = 2;

	std::vector<std::pair<double, double>> v1(6);
	v1[0].first = 3; v1[0].second = 2;
	v1[1].first = 2; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 5;
	v1[4].first = 4; v1[4].second = 4;
	v1[5].first = 4; v1[5].second = 3;

	Hexagon hex1;
	Hexagon hex2(v);
	Hexagon hex3(v1);

    hex1 = hex2;
    ASSERT_EQ(hex1, hex2);
    Hexagon hex4;
    hex4 = hex1;
    hex2 = hex3;
    ASSERT_EQ(hex1, hex4);
}

TEST(hexagon, double_cast) {
	std::vector<std::pair<double, double>> v(6);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;
	v[5].first = 3; v[5].second = 2;
    Hexagon hex1(v);
    double a = (double)hex1;
    EXPECT_EQ(a, 4);
}

TEST(pentagon, default_constructor)
{
	Pentagon pent;
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(pent.get_area(), 0);
	ASSERT_EQ(pent.get_middle_point(), para);
	ASSERT_EQ(pent.get_points().size(), 5);
}

TEST(pentagon, area1)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;

	Pentagon pent(v);
	ASSERT_EQ(pent.get_area(), 3.5);
	ASSERT_EQ(pent.get_points(), v);
}

TEST(pentagon, area2)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;
	v[4].first = 0; v[4].second = 0;

	Pentagon pent(v);
	ASSERT_EQ(pent.get_area(), 0);
	ASSERT_EQ(pent.get_points(), v);
}


TEST(pentagon, middle_point2)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;
	v[4].first = 0; v[4].second = 0;

	Pentagon pent(v);
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(pent.get_middle_point(), para);
	ASSERT_EQ(pent.get_points(), v);
}

TEST(pentagon, side_amount)
{
	std::vector<std::pair<double, double>> v(7);

	EXPECT_THROW(Pentagon pent(v), std::invalid_argument);
}

TEST(pentagon, eq_operator)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;

	std::vector<std::pair<double, double>> v1(5);
	v1[0].first = 3; v1[0].second = 2;
	v1[1].first = 2; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 5;
	v1[4].first = 4; v1[4].second = 4;

	Pentagon pent1(v);
	Pentagon pent2(v);
	Pentagon pent3(v1);

	ASSERT_EQ(pent1, pent2);
	ASSERT_FALSE(pent1 == pent3);
}

TEST(pentagon, copy_operator)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;

	std::vector<std::pair<double, double>> v1(5);
	v1[0].first = 3; v1[0].second = 2;
	v1[1].first = 2; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 5;
	v1[4].first = 4; v1[4].second = 4;

	Pentagon pent1;
	Pentagon pent2(v);
	Pentagon pent3(v1);

    pent1 = pent2;
    ASSERT_EQ(pent1, pent2);
    Pentagon pent4;
    pent4 = pent1;
    pent2 = pent3;
    ASSERT_EQ(pent1, pent4);
}

TEST(pentagon, double_cast) {
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;

    Pentagon pent1(v);
    double a = (double)pent1;
    EXPECT_EQ(a, 3.5);
}


TEST(rhombus, default_constructor)
{
	Rhombus rh;
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(rh.get_area(), 0);
	ASSERT_EQ(rh.get_middle_point(), para);
	ASSERT_EQ(rh.get_points().size(), 4);
}


TEST(rhombus, area1)
{
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;


	Rhombus rh(v);
	ASSERT_EQ(rh.get_area(), 2);
	ASSERT_EQ(rh.get_points(), v);
}

TEST(rhombus, area2)
{
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;

	Rhombus rh(v);
	ASSERT_EQ(rh.get_area(), 0);
	ASSERT_EQ(rh.get_points(), v);
}


TEST(rhombus, middle_point2)
{
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;

	Rhombus rh(v);
	std::pair<double, double> para;
	para.first = 0;
	para.second = 0;
	ASSERT_EQ(rh.get_middle_point(), para);
	ASSERT_EQ(rh.get_points(), v);
}

TEST(rhombus, side_amount)
{
	std::vector<std::pair<double, double>> v(7);

	EXPECT_THROW(Rhombus rh(v), std::invalid_argument);
}

TEST(rhombus, eq_operator)
{
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	std::vector<std::pair<double, double>> v1(4);
	v1[0].first = 2; v1[0].second = 2;
	v1[1].first = 1; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 3;


	Rhombus rh1(v);
	Rhombus rh2(v);
	Rhombus rh3(v1);

	ASSERT_EQ(rh1, rh2);
	ASSERT_FALSE(rh1 == rh3);
}

TEST(rhombus, copy_operator)
{
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	std::vector<std::pair<double, double>> v1(4);
	v1[0].first = 2; v1[0].second = 2;
	v1[1].first = 1; v1[1].second = 3;
	v1[2].first = 2; v1[2].second = 4;
	v1[3].first = 3; v1[3].second = 3;


	Rhombus rh1;
	Rhombus rh2(v);
	Rhombus rh3(v1);

    rh1 = rh2;
    ASSERT_EQ(rh1, rh2);
    Rhombus rh4;
    rh4 = rh1;
    rh2 = rh3;
    ASSERT_EQ(rh1, rh4);
}

TEST(rhombus, double_cast) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;


    Rhombus rh1(v);
    double a = (double)rh1;
    EXPECT_EQ(a, 2);
}

TEST(rhombus, exception_not_a_rhombus) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 3;

    EXPECT_THROW(Rhombus rh1(v), std::invalid_argument);
}

TEST(array, default_constructor) {
	Array arr;

	for(int i = 0; i < 1000; i++) 
		ASSERT_EQ(arr[i], nullptr);
}

TEST(array, replace_figure) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	Array arr;
	Rhombus rh(v);
	arr.replace_figure(0, &rh);

	ASSERT_EQ(arr[0], &rh);
}

TEST(array, average_area) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	std::vector<std::pair<double, double>> v1(4);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 0; v[1].second = 3;
	v[2].first = 2; v[2].second = 5;
	v[3].first = 4; v[3].second = 3;

	Array arr;
	Rhombus rh(v);
	Rhombus rh1(v1);
	arr.replace_figure(0, &rh);
	arr.replace_figure(1, &rh1);

	ASSERT_EQ(arr.average_area(), 4);
}

TEST(array, delete_figure) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	std::vector<std::pair<double, double>> v1(4);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 0; v[1].second = 3;
	v[2].first = 2; v[2].second = 5;
	v[3].first = 4; v[3].second = 3;

	Array arr;
	Rhombus rh(v);
	Rhombus rh1(v1);
	arr.replace_figure(0, &rh);
	arr.replace_figure(1, &rh1);
	arr.delete_figure(1);

	ASSERT_EQ(arr[1], nullptr);
}
/*

2 1
1 2
1 3
2 4
3 3
при этих входных Площадь: 3.5
Центральная точка: 1.8 2.6
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}