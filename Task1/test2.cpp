#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b and f") {
    string text = "so zo soom zyrup Ztewie zuper zupper soro zum sumba zombie"; //so so zoom syrup Stewie super supper zoro sum Zumba zombie

    CHECK(find(text, "Zoro") == string("soro"));

}