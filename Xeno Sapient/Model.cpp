//
//  Model.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//


#include <iostream>
#include <memory>

#include "NocabUtil.h"

#include "Model.h"

#include "Room.h"

using namespace xs_game;

void Model::setUpRooms()
{
  currentRoom = std::unique_ptr<Room>(new Room());
}


std::string Model::look(std::string at) {
  
  return currentRoom->look(at);
}


/**
 * Sets up all the rooms: Creates, links and populates all rooms.
 */
void Model::initRooms() {
  std::cout << "in initRooms in Model.cpp \n";
  
  // To test we will be building 5 rooms
  std::shared_ptr<Room> commonRoom(new Room());
  std::shared_ptr<Room> hallwayRoom(new Room());
  std::shared_ptr<Room> medRoom(new Room());
  std::shared_ptr<Room> canteniaRoom(new Room());
  std::shared_ptr<Room> lockerRoom(new Room());
  
  commonRoom->setDescription("Common Room Description\n");
  hallwayRoom->setDescription("Hall Description\n");
  medRoom->setDescription("Med Description\n");
  canteniaRoom->setDescription("Cantenia des\n");
  lockerRoom->setDescription("Locker des\n");
  
  // hallway is south of commonRoom
  dirSet(hallwayRoom, "south", commonRoom);
  
//  commonRoom->addConnectionOneWay("south", hallwayRoom);
//  hallwayRoom->addConnectionOneWay("north", commonRoom);
//  commonRoom->addConnectionOneWay("s", hallwayRoom);
//  hallwayRoom->addConnectionOneWay("n", commonRoom);
  
  
  hallwayRoom->addConnectionOneWay("med", medRoom);
  medRoom->addConnectionOneWay("out", hallwayRoom);
  
  hallwayRoom->addConnectionOneWay("cantenia", canteniaRoom);
  canteniaRoom->addConnectionOneWay("out", canteniaRoom);
  
  hallwayRoom->addConnectionOneWay("cantenia", lockerRoom);
  lockerRoom->addConnectionOneWay("out", hallwayRoom);
  
  
  currentRoom = commonRoom;
  
}

/**
 * Set up the player model: Create a new player with empty stats/inv.
 */
void initPlayer() {
  
  std::cout << "TODO: initPlayer Model.cpp\n";
  
}

void Model::init() {
  
  // Set up all rooms
  initRooms();
  
  // Set up player
  initPlayer();
  
}


bool Model::changeRoom(std::string dir)
{
  // Check to make sure the next room is a valid direction
  
  if (currentRoom->checkConnection(dir) == 0) {
    // there is no conncetion
    std::cout << "Model.cpp changeRoom no connection found in direction: \"" + dir + "\"\n";
    return false;
  }
  
  std::cout << "Model.cpp changeRoom connection found!\n";
  
  currentRoom = currentRoom->checkConnection(dir);
  return true;
}


// Room a is dir of b
// room b is (opposit of dir) of a
void Model::dirSet(std::shared_ptr<Room> a, std::string dir, std::shared_ptr<Room> b) {
  
  if (nocabStrCmp(dir, "north") || nocabStrCmp(dir, "n")) {
    b->addConnectionOneWay("north", a);
    b->addConnectionOneWay("n", a);
    a->addConnectionOneWay("south", b);
    a->addConnectionOneWay("s", b);
  }
  if (nocabStrCmp(dir, "south") || nocabStrCmp(dir, "s")) {
    b->addConnectionOneWay("south", a);
    b->addConnectionOneWay("s", a);
    a->addConnectionOneWay("north", b);
    a->addConnectionOneWay("n", b);
    
  }
  if (nocabStrCmp(dir, "east") || nocabStrCmp(dir, "e")) {
    b->addConnectionOneWay("east", a);
    b->addConnectionOneWay("e", a);
    a->addConnectionOneWay("west", b);
    a->addConnectionOneWay("w", b);
    
  }
  if (nocabStrCmp(dir, "west") || nocabStrCmp(dir, "w")) {
    b->addConnectionOneWay("west", a);
    b->addConnectionOneWay("w", a);
    a->addConnectionOneWay("east", b);
    a->addConnectionOneWay("e", b);
    
  }
  
  
}



