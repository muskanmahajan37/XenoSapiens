//
//  Controller.hpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

#include "Model.h"
#include "View.h"

//#include "Room.h"


namespace xs_game {
  
  /**
   * To control the game. Takes in commands from a View object,
   * interprets them and executes changes in the model.
   */
  class Controller {
    
  public:
    
    
    /**
     * A default constructor;
     */
    Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view);
    
    /**
     * Change the current room to be the next room in the specified direction.
     * If there is no room at the specified direction then return false and don't
     * change the current room.
     */
    bool changeRoom(std::string dir);
    
    /**
     * Get the descriptior of the specified thing "at" in the current room.
     * If this room doesn't contain object refered to with at, then a default
     * message is returned.
     */
    std::string look(std::string at);
    
    bool init();
    
    void play();
    
    /**
     * Takes in a file stream from the Model object and pushes it to the
     * the View to display.
     */
    void viewFile(std::ifstream infile);
    
  protected:
    
    
  private:
    
    enum command {GO, LOOK, USE, TALK, NA};
    
    command parseToken(std::string input);
    
    
    std::shared_ptr<Model> model_;
    std::shared_ptr<View> view_;
    
    
    
    
  };
  
}





#endif /* Controller_hpp */
