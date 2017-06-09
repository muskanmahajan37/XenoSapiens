//
//  Controller.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "Controller.h"


using namespace xs_game;


Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view) : model_(model), view_(view)
{
  
}


/**
 * Change the current room to be the next room in the specified direction.
 * If there is no room at the specified direction then return false and don't
 * change the current room.
 */
bool Controller::changeRoom(std::string dir)
{
  if (model_->changeRoom(dir)) {
    // Room changed
    std::cout << "Changed room \n";
    return true;
  } else {
    // Room didn't change
    std::cout << "Didn't change room: " + dir + "\n";
    return false;
  }
}

/**
 * Get the descriptior of the specified thing "at" in the current room.
 * If this room doesn't contain object refered to with at, then a default
 * message is returned.
 */
std::string Controller::look(std::string at)
{
  view_->display(model_->look(at));
  return "Garbage string remove me controller.cpp";
}

bool Controller::init()
{
  model_->init();
  return true;
}

void Controller::play()
{
  while(true) {
    std::vector<std::string> tokens = view_->getTokens();
    
    if (tokens.at(0) == "")
    {
      // If it's just an empty line, change nothing and start over.
      break;
    }
    
    
    command command = parseToken(tokens.at(0));
    
    switch (command) {
      case GO:
        std::cout << "case GO:\n";
        model_->changeRoom(tokens.at(1));
        break;
        
      case LOOK:
        std::cout << "case LOOK:\n";
        model_->look(tokens.at(1));
        break;
        
      case NA:
      default:
        std::cout << "case NA:\n";
        // Mallformed command
        break;
    }
      }
}




Controller::command Controller::parseToken(std::string input)
{
  
  if (input.compare("go") == 0) {
    return GO;
  } else if (input.compare("look") == 0) {
    return LOOK;
  }
  
  // Else we don't understand so return the default unknown command enum
  return NA;
}




