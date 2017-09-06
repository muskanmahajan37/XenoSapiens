//
//  Item.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "Item.hpp"


/**
 * A simple constructor.
 */
Item::Item(std::string name) noexcept : name_(name)
{
  connections = std::map<std::string, std::shared_ptr<Room>>();
  useList = std::vector<std::shared_ptr<Interactable>>();
  
  description = "Default description of a Room\n";
}




