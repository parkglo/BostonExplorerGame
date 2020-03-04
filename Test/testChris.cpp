#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Engine.h"
#include "Point.h"
#include "Game.h"


BOOST_AUTO_TEST_CASE(testStaty) {
  
  //Initialize Staty
  Staty staty;
  //Check if struct GameStatistics works
  GameStatistics stats
  //Check if points is equal to 0
  BOOST_CHECK(stats.points == 0);
  //Check if lives start at 3
  BOOST_CHECK(stats.lives == 3);
  //Check if nrLevel is 1
  BOOST_CHECK(stats.nrLevel == 1);
  //Check if maxLevel is 15
  BOOST_CHECK(stats.maxLevel == 15);
  //Check if toNewLive is equal to 50000
  BOOST_CHECK(stats.toNewLive == 50000);
  //Check if howmanylevels returns error if changed since it is constant
  BOOST_CHECK_THROW(stats.howmanylevels = 32);
}

BOOST_AUTO_TEST_CASE(testPoint) {
  
  //Create Point
  Point point;
  //Check for error
  BOOST_CHECK_NO_THROW(point.Point());
  
  //Check if values work
  BOOST_CHECK(point.label("100");
  
  BOOST_Check(point.label = n_label);
  }

BOOST_AUTO_TEST_CASE(testPoint2) {
  //Create Point
  Point point;
  //Check for errors
  BOOST_CHECK(pos(Vector2f(700,400));
}

BOOST_AUTO_TEST_CASE(testEngine) {
  //Initialize Engine
  Engine engine;
  
  //Check for error since it should be constant
  BOOST_CHECK_THROW(engine.howmanyFood = 9);
}

BOOST_AUTO_TEST_CASE(testEngine) {
  //Intialize Engine
  Engine engine;
  
  //Check for errors
  BOOST_CHECK_NO_THROW(engine.check_collision());
}

BOOST_AUTO_TEST_CASE(testEngine) {
  //Intialize Engine
  Engine engine;
  GameStatistics stats;
  
  //Check for errors
  BOOST_CHECK_NO_THROW(engine.check_collision_withFOOD(stats));
}

BOOST_AUTO_TEST_CASE(testEngine) {
  //Intialize Engine
  Engine engine;
  GameStatistics stats;
  
  //Check for errors
  BOOST_CHECK_NO_THROW(engine.update_GUI(stats));
}


BOOST_AUTO_TEST_CASE(testEngine) {
  //Intialize Engine
  Engine engine;
  RenderWindow win;
  GameStatistics stats;
  
  //Check for errors
  BOOST_CHECK_NO_THROW(engine.update_GUI(win, stats));
}