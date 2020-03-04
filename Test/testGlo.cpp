#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Engine.cpp"
#include "Records.cpp"

// *** ENGINE ***

//checks game rendering
BOOST_AUTO_TEST_CASE(testEngine1){

    //initialize engine
    Engine engine;
    // initalize window
    RenderWindow window;
    //initialize game statistics
    GameStatistics gameStatistics;
    
    //check for error
    BOOST_CHECK_NO_THROW(engine.render(window, gameStatistics));
}

//checks getting powerbar state 
BOOST_AUTO_TEST_CASE(testEngine2){

    //initialize engine
    Engine engine;
    // initalize window
    RenderWindow window;
    //initialize game statistics
    GameStatistics gameStatistics;
    
    //check for error
    BOOST_CHECK_NO_THROW(engine.getPowerState(window, gameStatistics));
}

checks getting date and time
BOOST_AUTO_TEST_CASE(testEngine3){

    //initialize engine
    Engine engine;
    
    //check for error
    BOOST_CHECK_NO_THROW(engine.getDate());
}

checks updating record file
BOOST_AUTO_TEST_CASE(testEngine4){

    //initialize engine
    Engine engine;
    const string path;
    newLine;
    size_t werse;
    //check for error
    BOOST_CHECK_NO_THROW(engine.update_records_file(path, newLine, werse));
}

// *** RECORDS ***

BOOST_AUTO_TEST_CASE(testRecords1){

    //initialize engine
    Records records;
    //check if date is set to base date
    BOOST_CHECK(records.date == "01.01.2015");
}

BOOST_AUTO_TEST_CASE(testRecords2){

    //initialize records
    Records records;
    
    //check for error
    BOOST_CHECK_NO_THROW(records.loading());
}
