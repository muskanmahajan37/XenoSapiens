//
//  Interactable.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "Interactable.h"

#include <iostream>
#include <map>

using namespace xs_game;

/**
 * A simple constructor.
 */
Interactable::Interactable(std::string const& name) noexcept : name_(name)
{
  descriptoin_ = name + " Does NOT have a description. Interactable.";
  useFunction = [](std::shared_ptr<std::map<std::string, bool> >){ std::cout << "USED AN INTERACTABLE\n"; return true;};
}

/**
 * A simple constructor.
 */
/**
 * Below is a breif description of this... garbage looking type
 *
 * std::function<                       - The type is a lambda function, first and formost
 *               bool                   - The lambda returns a bool type
 *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
 *                                std::map<                - of type Map...
 *                                         std::string,    - which pairs strings...
 *                                         bool            - to bool values
 *                                        >
 *                               >
 *               )
 *              >
 */
Interactable::Interactable(std::string const& name, std::string const& description) noexcept : name_(name), descriptoin_(description)
{
  useFunction = [](std::shared_ptr<std::map<std::string, bool> >){ std::cout << "USED AN INTERACTABLE\n"; return true;};
}

/**
 * A destructor
 */
Interactable::~Interactable() noexcept
{
  //TODO:
}

std::string Interactable::getName() const {
  return name_;
}

bool Interactable::setDescription(std::string description) {
  descriptoin_ = description;
  return true;
}

std::string Interactable::getDescription() const {
  return descriptoin_;
}




/**
 * Below is a breif description of this... garbage looking type
 *
 * std::function<                       - The type is a lambda function, first and formost
 *               bool                   - The lambda returns a bool type
 *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
 *                                std::map<                - of type Map...
 *                                         std::string,    - which pairs strings...
 *                                         bool            - to bool values
 *                                        >
 *                               >
 *               )
 *              >
 */
bool Interactable::setLambda(std::function<bool(std::shared_ptr<std::map<std::string, bool> >)> newLambda) {
  useFunction = newLambda;
  return true;
}





/**
 * Below is a breif description of this... garbage looking type
 *
 * std::function<                       - The type is a lambda function, first and formost
 *               bool                   - The lambda returns a bool type
 *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
 *                                std::map<                - of type Map...
 *                                         std::string,    - which pairs strings...
 *                                         bool            - to bool values
 *                                        >
 *                               >
 *               )
 *              >
 */
std::function<bool(std::shared_ptr<std::map<std::string, bool> >)> Interactable::getLambda() const {
  return useFunction;
}













