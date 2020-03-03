#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Level.h"   
#include "Player.h"
#include "Food.h"

// *** LEVEL ***

//test initialization of level
BOOST_AUTO_TEST_CASE(testLevel1){

    //initialize game
    Level level;
    //check if level width is set to 32
    BOOST_CHECK(level.width == 32);
    //check if level height is set to 18
    BOOST_CHECK(level.height == 18);
}

//test initialization of level
BOOST_AUTO_TEST_CASE(testLevel2){

    //initialize game
    Level level;
    //check if tile width is set to 40
    BOOST_CHECK(level.tile_width == 40);
    //check if tile height is set to 40
    BOOST_CHECK(level.tile_height == 40);
}

// test changing level width
BOOST_AUTO_TEST_CASE(testLevel3){

    //initialize game
    Level level;
    //check if changing width throws error since it is const
    BOOST_CHECK_THROW(level.width = 48);
    //check if changing height throws error since it is const
    BOOST_CHECK_THROW(level.heigh = 48);
}

// test opening correct level file name
BOOST_AUTO_TEST_CASE(testLevel4){
    string filename = "map_1.level";

    //initialize game
    Level level;
    //check if initalizing level with correct file does not throw an error
    BOOST_CHECK_NO_THROW(level(filename));
    
}

// test opening incorrect level file name
BOOST_AUTO_TEST_CASE(testLevel5){
    string filename = "map_bad.level";

    //initialize game
    Level level;
    //check if initalizing level with incorrect file does throw an error
    BOOST_CHECK_THROW(level(filename));
    
}




// *** PLAYER ***

//checks updating player position correctly
BOOST_AUTO_TEST_CASE(testPlayer1) {

    //initialize player
    Player p;

    //set mousePosition to be in the range of the map
    Vector2f mousePosition(10, 10); 
    
    //checks to see if using correct coordinates does not throw an error
    BOOST_CHECK_NO_THROW(p.update(mousePosition));
}

//checks updating player position incorrectly
BOOST_AUTO_TEST_CASE(testPlayer2) {

    //initialize player
    Player p;

    //set mousePosition to not be in the range of the map
    Vector2f mousePosition(-2, 4); 
    
    //checks to see if using incorrect coordinates throws an error
    BOOST_CHECK_THROW(p.update(mousePosition));
}




// *** FOOD ***

// checks if itializing food to correct type
BOOST_AUTO_TEST_CASE(testFood1) {
    int foodNum = 2;
    Food f;

    //initialize food with food type 2
    //checks to see if using correct food type does not throw an error
    BOOST_CHECK_NO_THROW(f(foodNum));
}

// checks if itializing food to incorrect type
BOOST_AUTO_TEST_CASE(testFood2) {
// setting foodNum to 6 because there are only 1-5 food types
    int foodNum = 6;
    Food f;

    //initialize food with food type 6
    //checks to see if using incorrect food type does throw an error
    BOOST_CHECK_THROW(f(foodNum));
}

// checks if intializing whichfood variable correctly
BOOST_AUTO_TEST_CASE(testFood3) {
    int foodNum = 2;
    Food f(2);

    //initialize food with food type 2
    //checks to see if initilizing food correctly 
    BOOST_CHECK(f.whichfood == 2)
}

// checks if intializing whichfood variable incorrectly throws an error
BOOST_AUTO_TEST_CASE(testFood4) {
    // setting foodNum to 6 because there are only 1-5 food types
    int foodNum = 6;
    Food f(6);

    //initialize food with food type 6
    //checks to see if initilizing food correctly 
    BOOST_CHECK(f.whichfood != 6)
}

// checks if intializing pointsPerFood variable correctly
BOOST_AUTO_TEST_CASE(testFood5) {
    int foodNum = 2;
    Food f(2);

    //initialize food with food type 2
    //checks to see if initilizing pointsPerFood correctly 
    BOOST_CHECK(f.pointsPerFood == 200)
}

// checks if intializing pointsPerFood variable incorrectly throws error
BOOST_AUTO_TEST_CASE(testFood6) {
// setting foodNum to 6 because there are only 1-5 food types
    int foodNum = 6;
    Food f(6);

    //initialize food with food type 6
    //checks to see if initilizing pointsPerFood correctly with bad input
    BOOST_CHECK(f.pointsPerFood != 600)
}

