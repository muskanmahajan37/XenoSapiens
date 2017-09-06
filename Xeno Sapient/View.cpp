//
//  View.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/8/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include <string>
#include <iostream>
#include <sstream>

#include "View.h"


using namespace xs_game;

void View::display(std::string message)
{
  std::cout << message << std::endl;
}

void View::display(std::shared_ptr<std::string> message)
{
  std::cout << message << std::endl;
}

/**
 * Retrieve the next full input from the user.
 */
std::string View::getInput()
{
  std::string pinput;
  std::getline(std::cin, pinput, '\n');
  
  std::cout << "view.cpp getInput pinput: \"" + pinput + "\"\n";
  
  return pinput;
}




std::vector<std::string> View::getTokens()
{
  std::istringstream iss(this->getInput());
  
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};
  
  return tokens;
}






