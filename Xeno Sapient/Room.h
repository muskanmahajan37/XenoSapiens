//
//  Room.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Room_h
#define Room_h

#include <map>
#include <vector>
#include <string>
#include "Interactable.h"
#include "Item.h"

namespace xs_game {
  
  
  /**
   * To represent a generic room in the xeno sapient game.
   * All rooms have connecting rooms.
   *                "use" objects.
   *                "look" objects.
   *                "talk" objects.
   */
  class Room {
    
  public:
    
    /**
     * A simple constructor.
     */
    Room(std::string name) noexcept;
    
    /**
     * A constructor that adds the room specified with connection to this
     * new rooms list of connection and the provided rooms list of connections.
     */
    //Room(std::string dir, std::shared_ptr<Room> connection) noexcept;
    
    /**
     * A destructor
     */
    ~Room() noexcept;
    
    /**
     * A getter method for the name of this room.
     */
    std::string getName() const;
    
    /**
     * Get the descriptior of the specified thing "at" in this room.
     * If this room doesn't contain object refered to with at, then a default
     * message is returned.
     */
    // To look at an item in the room, use checkInteractabl(std::string name) instead
    //std::string look(std::string at);
    
    /**
     * Get the descriptor of the current room.
     */
    std::string look() const;
    
    /**
     * Adds the specified neighbor to this list of connections, adds this 
     * Room to "neighbor" list of connections.
     */
    void addConnection(std::string dir, std::shared_ptr<Room> neighbor);
    
    /**
     * Add the specified neighbor to this list of connections, but 
     * does NOT add this Room to the neighbor list of connections.
     */
    void addConnectionOneWay(std::string dir, std::shared_ptr<Room> neighbor);
    
    /**
     * Removes the specified neighbor from this list of connections,
     * and also removes this Room from the neighbor's list of connections.
     *
     * If the target room is not part of this list of connections, then nothing
     * will happen and will return false.
     */
    bool removeConnection(std::shared_ptr<Room> neighborToRemove);
    
    
    /**
     * Removes the specified neighbor from this list of connections,
     * but does NOT remove this Room from the neighbor's list of connections.
     *
     * If the target room is not in this list of connections, then nothing
     * will happen and will return false.
     */
    bool removeConnectionOneWay(std::shared_ptr<Room> neighborToRemove);
    
    /**
     * A simple setter method for the description of this room.
     */
    void setDescription(std::string newDescription);
    
    /**
     * A setter method that sets the path of the description of this room.
     */
    void setDescriptionFile(std::string newDescriptionPath);
    
    /**
     * A getter method to get the filepath to the description of this room.
     */
    //TODO: Add the 'at' functionality, allowing us to look at Interactables in the room
    std::string getDescriptionFilePath(std::string at);
  
    /**
     * Adds an Interactables to this room.
     */
    bool addInteract(std::shared_ptr<Interactable> interact);
    
    /**
     * Returns the names of all the Interactables in the room.
     */
    std::string stringifyInteract();
    
    /**
     * Returns the directions, and names of rooms, connected to this one.
     */
    std::string stringifyConnections();
    
    
    /**
     * Checks to see if there is an Interactable with the specified name/key value
     * @return the Interactable specified by the name (if it exists)
     * Else, return NULL
     */
    std::shared_ptr<Interactable> checkInteractable(std::string name);
    
    /**
     * Checks to see if there is a room with the specified direction/ key value
     * @return the room at the end of the target connection (if the connection exists)
     * Else, return NULL
     */
    std::shared_ptr<Room> checkConnection(std::string dir);
  protected:
    
    
  private:
    
    std::string name_; /** The name of this room */
    
    std::string description;      /** The uber basic description, TODO: Remove this */
    std::string descriptionPath_; /** The path to the description fo this room */
    
    std::map<std::string, std::shared_ptr<Room> > connections_; /** All the connections out of this room; */
    //std::vector<std::shared_ptr<xs_game::Interactable> >  interactables_;     /** All the usable Interactables in this room. */
    std::map<std::string, std::shared_ptr<Interactable> > interactables_;
  };
  
}







#endif /* Room_h */
