#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Game.h"   

BOOST_AUTO_TEST_CASE(testGame1){

    //initialize game
    Game game;
    //check if first game state is MENU
    BOOST_CHECK(game.state == 0);
}