#include <gtest/gtest.h>
#include <utility>
#include <memory>

#include <outlaw.h>
#include <werewolf.h>
#include <bear.h>
#include <factory.h>

using coords = std::pair<int, int>;

class BaseEntities : public ::testing::TestWithParam< std::pair< std::pair< coords, coords >, int > > {};

TEST_P(BaseEntities, CheckCloseTrue) {
	// arrange
    std::pair< std::pair< coords, coords >, int > data = GetParam();
	// act
	bool isClose = true;
    coords c1 = data.first.first;
    coords c2 = data.first.second;
    Factory factory;
    auto o = factory.factory(OutlawType, c1.first, c1.second);
    auto e = factory.factory(BearType, c2.first, c2.second);

	// assert
	ASSERT_EQ(isClose, true);
}

INSTANTIATE_TEST_SUITE_P(
	BaseEntities_Close,
	BaseEntities,
	::testing::Values(
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {1, 1} }, 2 }),
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {0, 1} }, 1 }),
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {1, 0} }, 1 })
));



class BaseEntities1 : public ::testing::TestWithParam< std::pair< std::pair< coords, coords >, int > > {};

TEST_P(BaseEntities1, CheckCloseFalse) {
	// arrange
    std::pair< std::pair< coords, coords >, int > data = GetParam();
    coords c1 = data.first.first;
	// act
	bool isClose = false;
    coords c2 = data.first.second;
    Factory factory;
    auto o = factory.factory(OutlawType, c1.first, c1.second);
    auto e = factory.factory(BearType, c2.first, c2.second);


	// assert
	ASSERT_EQ(isClose, false);
}

INSTANTIATE_TEST_SUITE_P(
	BaseEntities_NotClose,
	BaseEntities1,
	::testing::Values(
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {10, 10} }, 12 }),
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {0, 10} }, 7 }),
        std::pair< std::pair< coords, coords >, int >({ { {0, 0}, {10, 0} }, 9 })
));

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}