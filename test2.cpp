#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w") {
	string text = "vov I really want to vrite my oVn Vows";

	CHECK(find(text, "vows") == string("Vows"));
}