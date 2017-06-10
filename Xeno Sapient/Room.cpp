//
//  Room.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/8/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>


#include "Room.h"

using namespace xs_game;


/**
 * A simple constructor.
 */
Room::Room() noexcept
{
  //connections = std::map<std::string, std::shared_ptr<Room>>();
  useList = std::vector<std::shared_ptr<Interactable>>();
  
  description = "Default description of a Room\n";
}


/**
 * A constructor that adds the room specified with connection to this
 * new rooms list of connection and the provided rooms list of connections.
 */
//Room::Room(std::string const dir, std::shared_ptr<Room> const connection) noexcept
//{
//  connections = std::map<std::string, std::shared_ptr<Room>>();
//  connections.insert(std::pair<std::string, std::shared_ptr<Room>>(dir, connection));
//  
//  useList = std::vector<std::shared_ptr<Interactable>>();
//  description = "Default description of a Room\n";
//}

/**
 * A destructor
 */
Room::~Room() noexcept
{
  //TODO:
}

/**
 * Get the descriptior of the specified thing "at" in this room.
 * If this room doesn't contain object refered to with at, then a default
 * message is returned.
 */
std::string Room::look(std::string at) const
{
  //TODO: Every room has its own description?
  return description;
  //return "fixme! Room.cpp look function\n";
}

/**
 * Adds the specified neighbor to this list of connections, adds this
 * Room to "neighbor" list of connections.
 */
void Room::addConnection(std::string dir, std::shared_ptr<Room> neighbor)
{
  connections.insert(std::pair<std::string, std::shared_ptr<Room>>(dir, neighbor));
  neighbor->addConnectionOneWay(dir, std::make_shared<Room>(*this));
}

/**
 * Add the specified neighbor to this list of connections, but
 * does NOT add this Room to the neighbor list of connections.
 */
void Room::addConnectionOneWay(std::string dir, std::shared_ptr<Room> neighbor)
{
  connections.insert(std::pair<std::string, std::shared_ptr<Room>>(dir, neighbor));
}

/**
 * Removes the specified neighbor from this list of connections,
 * and also removes this Room from the neighbor's list of connections.
 *
 * If the target room is not part of this list of connections, then nothing
 * will happen and will return false.
 */
bool Room::removeConnection(std::shared_ptr<Room> neighborToRemove)
{
  for (auto iter = connections.begin(); iter != connections.end(); ++iter)
  {
    if (iter->second == neighborToRemove) {
      // If the current itterator is the target, remove the target
      connections.erase(iter);
      
      return neighborToRemove->removeConnectionOneWay(std::make_shared<Room>(*this));
    }
  }
  
  
  return false;
}

/**
 * Removes the specified neighbor from this list of connections,
 * but does NOT remove this Room from the neighbor's list of connections.
 *
 * If the target room is not in this list of connections, then nothing
 * will happen and will return false.
 */
bool Room::removeConnectionOneWay(std::shared_ptr<Room> neighborToRemove)
{
  for (auto iter = connections.begin(); iter != connections.end(); ++iter)
  {
    if (iter->second == neighborToRemove)
    {
      connections.erase(iter);
      return true;
    }
  }
  
  return false;
}


void Room::setDescription(std::string newDescritpion)
{
  description = newDescritpion;
}


std::shared_ptr<Room> Room::checkConnection(std::string dir)
{
  std::shared_ptr<Room> result;
  try {
    
    result = connections[dir];
    return result;
    
  } catch(const std::out_of_range& oor) {
    // We couldn't find the specified connection.
    return 0;
  }
}





