/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w") {
	string text = "vov I really want to vrite my oVn Vows";

	CHECK(find(text, "Wow") == string("vov"));
	CHECK(find(text, "want") == string("want"));
	CHECK(find(text, "write") == string("vrite"));
	CHECK(find(text, "own") == string("oVn"));
	CHECK(find(text, "vows") == string("Vows"));
    CHECK(find(text, "really") == string("really"));
    CHECK_THROWS(find(text,"love"));
    CHECK_THROWS(find(text,"life"));
    CHECK_THROWS(find(text,"corona")); //I really hope this will not be found....
    CHECK_THROWS(find(text, "_"));
    CHECK_THROWS(find(text, "~"));
    CHECK_THROWS(find(text, "-"));
    CHECK_THROWS(find(text, "wow_"));
	CHECK_THROWS(find(text, ""));

}

TEST_CASE("Test replacement of p and b and f") {
    string text = "xxx happy yyy";

    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));

    string text2 = "Libe is pull ob so many obfortunities"; //life is full of so many opportunities

    CHECK(find(text2, "life") == string("Libe"));
    CHECK(find(text2, "Full") == string("pull"));
    CHECK(find(text2, "of") == string("ob"));
    CHECK(find(text2, "opportunities") == string("obfortunities"));
    CHECK_THROWS(find(text2, "happiness")); //Though I hope it will not be found in this specific test, I do hope everybody will find happiness in their life.
    CHECK_THROWS(find(text2, "obi wan"));
    CHECK_THROWS(find(text, "death star"));

    string text3 = "You will not bind habbiness at the pottom of a bottle"; //You will not find happiness at the bottom of a bottle
    CHECK(find(text3, "find") == string("bind")); //ask first!
    CHECK(find(text3, "happiness") == string ("habbiness"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "Jood game you did a jreat gob in the jame and I wish you a great day and also gava"; //good game you did a great job and I wish you a great day and also java

    CHECK(find(text, "good") == string("Jood"));
    CHECK(find(text, "game") == string("game")); //note - important. Should return game and not jame, as game comes first in the string
    CHECK(find(text, "great") == string("jreat"));
    CHECK(find(text, "Job") == string("gob"));
    CHECK(find(text, "java") == string("gava"));

    string text2 = "jood jolly gimmy, what have you done";
    CHECK(find(text2, "good") == string("jood"));
    CHECK(find(text2, "golly") == string("jolly"));
    CHECK(find(text2, "done") == string("done"));

    string text3 = "jeneric";
    CHECK(find(text3, "Generic") == string("jeneric")); //test to make sure text with 1 word in it works as well

    string text4 = "Generic";
    CHECK(find(text3, "Generic") == string("Generic")); //as above, without mistakes or changes
}

TEST_CASE("Test replacement of c and k and q") {
    string text = "kome on you kan do muqh better qute kuddly qrazy kuakc dukc duck bukcet"; //come on you can do much better cute kuddly crazy quack duck bucket

    CHECK(find(text, "come") == string("kome"));
    CHECK(find(text, "can") == string("kan"));
    CHECK(find(text, "much") == string("muqh"));
    CHECK(find(text, "cute") == string("qute"));
    CHECK(find(text, "cuddly") == string("kuddly"));
    CHECK(find(text, "cuddly") == string("kuddly"));
    CHECK(find(text, "crazy") == string("qrazy"));
    CHECK(find(text, "quack") == string("kuakc"));
    CHECK(find(text, "duck") == string("dukc"));
    CHECK(find(text, "bucket") == string("bukcet"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "so zo soom zyrup Ztewie zuper zupper roro zum sumba zombie"; //so so zoom syrup Stewie super supper zoro sum Zumba zombie
    CHECK(find(text, "so") == string("so"));
    CHECK(find(text, "so") == string("so")); //make sure so is returned again, and not zo
    CHECK(find(text, "zoom") == string("soom"));
    CHECK(find(text, "syrup") == string("zyrup"));
    CHECK(find(text, "syrup") == string("zyrup"));
    CHECK(find(text, "Stewie") == string("Ztewie"));
    CHECK(find(text, "super") == string("zuper"));
    CHECK(find(text, "supper") == string("zupper"));
    CHECK(find(text, "Zoro") == string("roro"));
    CHECK(find(text, "sum") == string("zum"));
    CHECK(find(text, "Zumba") == string("sumba"));
    CHECK(find(text, "zombie") == string("zombie"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "daughter deedh toom transport drain trown dope trees tree tute tat drap"; 
    //daughter teeth doom transport train drown dope trees tree dude dad trap

    CHECK(find(text, "Daughter") == string("daughter"));
    CHECK(find(text, "teeth") == string("deedh"));
    CHECK(find(text, "doom") == string("toom"));
    CHECK(find(text, "transport") == string("transport"));
    CHECK(find(text, "train") == string("drain"));
    CHECK(find(text, "train") == string("drain"));
    CHECK(find(text, "train") == string("drain"));
    CHECK(find(text, "drown") == string("trown"));
    CHECK(find(text, "dope") == string("dope"));
    CHECK(find(text, "trees") == string("trees"));
    CHECK(find(text, "tree") == string("tree"));
    CHECK(find(text, "dude") == string("tute"));
    CHECK(find(text, "dad") == string("tat"));
    CHECK(find(text, "trap") == string("drap"));

}

TEST_CASE("Test replacement of o and u") {
    string text = "Uops yuo uor yours upen op duwn luw drom opper onder upium Osupp luve";
    //oops you our yours open up down low drum upper under opium Usopp love

    CHECK(find(text, "oops") == string("Uops"));
    CHECK(find(text, "you") == string("yuo"));
    CHECK(find(text, "our") == string("uor"));
    CHECK(find(text, "yours") == string("yours"));
    CHECK(find(text, "open") == string("upen"));
    CHECK(find(text, "up") == string("op"));
    CHECK(find(text, "down") == string("duwn"));
    CHECK(find(text, "low") == string("luw"));
    CHECK(find(text, "drum") == string("drom"));
    CHECK(find(text, "upper") == string("opper"));
    CHECK(find(text, "under") == string("onder"));
    CHECK(find(text, "opium") == string("upium"));
    CHECK(find(text, "Usopp") == string("Osupp"));
    CHECK(find(text, "love") == string("luve"));


}

TEST_CASE("Test replacement of i and y") {
    string text = "Y love iou I am iours yn you ynsyde ioio iard Yahoo irresistible"; 
    //I love you I am yours in you inside independent yoyo yard yahoo irresistible

    CHECK(find(text, "I") == string("Y"));
    CHECK(find(text, "love") == string("love"));
    CHECK(find(text, "you") == string("iou"));
    CHECK(find(text, "yours") == string("iours"));
    CHECK(find(text, "in") == string("yn"));
    CHECK(find(text, "inside") == string("ynsyde"));
    CHECK(find(text, "yoyo") == string("ioio"));
    CHECK(find(text, "yard") == string("iard"));
    CHECK(find(text, "yahoo") == string("Yahoo"));
    CHECK(find(text, "irresistible") == string("irresistible"));



}




TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

/* Add more test cases here */
