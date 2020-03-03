#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Game.h"   

//test initialization of Game
BOOST_AUTO_TEST_CASE(testGame1){

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
}

BOOST_AUTO_TEST_CASE(testPA2) {

    //initialize point animation
    PointAnimation pa;
    //check if lifetime is 5 seconds
    BOOST_CHECK(pa.lifetime == 5);
}

BOOST_AUTO_TEST_CASE(testPA3) {

    //initialize point animation
    PointAnimation pa;
    //check if lifetime is 5 seconds
    BOOST_CHECK(pa.lifetime == 5);
}

BOOST_AUTO_TEST_CASE(testPA4) {

    //initialize point animation
    PointAnimation pa;
    //check if lifetime is 5 seconds
    BOOST_CHECK(pa.lifetime == 5);
}

BOOST_AUTO_TEST_CASE(testPA5) {

    //initialize point animation
    PointAnimation pa;
    //check if lifetime is 5 seconds
    BOOST_CHECK(pa.lifetime == 5);

}
