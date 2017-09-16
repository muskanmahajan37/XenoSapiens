//
//  Model.hpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <memory>

#include "Room.h"
#include "Player.h"

namespace xs_game {
  
  /**
   * The main datastructure that represent the current state of the game
   * are stored here. This object is minipulated by the View.
   */
  class Model {
    
  public:
    
    /**
     * Change the current room to be the next room in the specified direction.
     * If there is no room at the specified direction then return false and don't
     * change the current room.
     */
    bool changeRoom(std::string dir);
    
    /**
     * Get the descriptior of the specified thing "at" in the current room.
     * If this room doesn't contain object refered to with at, then a default
     * message is returned describing the room.
     */
    std::string look(std::string at);
    
    // TODO: remove this
    std::shared_ptr<std::string> lookBig(std::string at);
    
    /**
     * A getter method to get the filepath to the description of the current room.
     */
    //TODO: Add the 'at' functionality, allowing us to look at items in the room
    std::string getDescriptionFilePath(std::string at);
    
    /**
     * A method that returns the name of every item/interactable in the room. Using this
     * function allows the user to eventually 'look' at the items/interactables for a more
     * detailed descriptoin.
     */
    std::string getInteractInRoom();
    
    /**
     * A method that returns the direction, and name of target room, of 
     * every connected Room to the current room.
     */
    std::string getPathsFromRoom();
    
    /**
     * The initial set up for the rooms of the game. Creates all required Rooms
     * and 
     */
    void setUpRooms();
    
    /**
     * Sets up all the rooms: Creates, links and populates all rooms. 
     * Set up the player model: Create a new player with empty stats/inv. 
     */
    void init();
    
  protected:
    
    
  private:
    
    void initRooms();
    
    /**
     * Connects the two rooms in such a way that room a, is direction of b.
     * for example the dirset(a, west, b) means that a is west of b
     *                                               b is east of a
     */
    void dirSet(std::shared_ptr<Room> a, std::string dir, std::shared_ptr<Room> b);
    
    
    std::shared_ptr<xs_game::Room> currentRoom;
    xs_game::Player player;
    
    
  };
  
}




#endif /* Model_hpp */
