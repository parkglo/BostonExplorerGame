#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Game.h"   


//test initialization of Game
BOOST_AUTO_TEST_CASE(testGame1) {

    //initialize game
    Game game;
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);
    //check that the window is not in fullscreen
    BOOST_CHECK(game.fullScrean == FALSE);
}

//check menu function
BOOST_AUTO_TEST_CASE(testGame2) {

    //initialize game
    Game game;

    //run menu
    game.menu();
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);
}

//check game over function
BOOST_AUTO_TEST_CASE(testGame3) {

    //initialize game
    Game game;
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);
}

//check about function
BOOST_AUTO_TEST_CASE(testGame4) {

    //initialize game
    Game game;
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);
}

//check rungame
BOOST_AUTO_TEST_CASE(testGame5) {

    //initialize game
    Game game;
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);

}

//check initialization
BOOST_AUTO_TEST_CASE(testPA1) {

    //initialize point animation
    PointAnimation pa;
    //check if lifetime is 5 seconds
    BOOST_CHECK(pa.lifetime == 5);
    BOOST_CHECK(pa.data.size() == 0);
}

//test add
BOOST_AUTO_TEST_CASE(testPA2) {

    //initialize point animation
    PointAnimation pa;
    Vector2f vec(1.5, 2.5);
    string str = "150";
    pa.add(str, vec);
    //check if lifetime values have been added
    BOOST_CHECK(pa.data.back()->label.std::string::compare(str) == 0);
    BOOST_CHECK(pa.data.back()->pos == vec);
}

//test update
BOOST_AUTO_TEST_CASE(testPA3) {

    //initialize point animation
    PointAnimation pa;
    Vector2f vec(1.5, 2.5);
    string str = "150";
    pa.add(str, vec);
    pa.update();

    //check if point exists after update
    BOOST_CHECK(pa.data.size() == 1);
}

//check for error with update
BOOST_AUTO_TEST_CASE(testPA4) {

    //initialize point animation
    PointAnimation pa;
    //check for error
    BOOST_CHECK_NO_THROW(pa.update());
}

//test draw window
BOOST_AUTO_TEST_CASE(testPA5) {

    //initialize point animation
    PointAnimation pa;
    //initialize window
    RenderWindow window;

    //check for error
    BOOST_CHECK_NO_THROW(pa.drawPoint(window));
}
