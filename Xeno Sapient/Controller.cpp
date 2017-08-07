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
#include "NocabUtil.h"


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
    //std::cout << "Changed room \n";
    return true;
  } else {
    // Room didn't change
    //std::cout << "Didn't change room: " + dir + "\n";
    return false;
  }
}

/**
 * Get the descriptior of the specified thing "at" in the current room.
 * If this room doesn't contain object refered to with at, then a default
 * message is returned.
 */
// TODO: make this a void funciton.
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
    
    if (tokens.size() == 0 || tokens.at(0) == "")
    {
      // If it's just an empty line, change nothing and start over.
      break;
    }
    
    
    command command = parseToken(tokens.at(0));
    
    switch (command) {
      case GO:
        //std::cout << "case GO:\n";
        
        if (tokens.size() < 2) {
          view_->display("You didn't tell me where to go. \n");
          break;
        }
        
        if (model_->changeRoom(tokens.at(1))) {
          view_->display("You move into the next room.\n");
        } else {
          view_->display("Mallformed command, cannot go there for various reasons.\n");
        }
        break;
      case LOOK:
        //std::cout << "case LOOK:\n";
        
        if (tokens.size() == 1) {
          //std::cout << "  size == 1\n";
          view_->display(model_->look("garbage"));
        } else if (tokens.size() == 2) {
          view_->display(model_->look(tokens.at(1)));
        } else {
          // Can't really look at 2 things at once...
        }
        break;
        
      case NA:
      default:
        view_->display("Mallformed command\n");
        // Mallformed command
        break;
    }
  }
}




Controller::command Controller::parseToken(std::string input)
{
  
  //std::cout << "controller.cpp parseToken input: \"" + input + "\"\n";
  
  if (nocabStrCmp(input, "go")) { //input.compare("go") == 0) {
    return GO;
  } else if (nocabStrCmp(input, "look")) { //input.compare("look") == 0) {
    return LOOK;
  } else if (nocabStrCmp(input, "use")) {
    return USE;
  } else if (nocabStrCmp(input, "talk")) {
    return TALK;
  }
  
  // Else we don't understand so return the default unknown command enum
  return NA;
}


void Controller::viewFile(std::ifstream inFile)
{
  std::string x;
  if (!inFile.is_open()) {
    view_->display("Error! Could not open file. In viewFile Controller.cpp");
    return;
  }
  
  while (getline(inFile, x)) {
    view_->display(x);
    view_->display("\n");
  }
  
  inFile.close();
}


//
//
//bool Controller::nocabStrCmp(std::string a, std::string b) {
//
//
//}





/////////////////////////////////////////////////////////////
// Dealing with dialogue trees.



// First I need to make a function that can print all the files

// Print all the possible choices
// Store the link destinations into an array
//    Player selects one of them (lets say choice 2)
// Fork over to destination stored in array index 1 (cause it's 0 indexed)

std::vector<std::string> Controller::parceDecision(std::ifstream &inFile)
{
  std::string x;
  std::vector<std::string> links;
  
  // We come in, it starts off on the line of the open '=' tag
  // Move to the next line
  // Is that the close tag?
  //  yes => return
  //  no  => print line
  // Move to the next line
  // Is that the close tag?
  //  yes => return
  //  no => print line
  
  /* NOTE: the only way to exit this loop is in the first if check.
   *        the only way to exit this loop is if the file we're reading
   *        actually has a closing '=' tag.
   */
  while(true) {
    
    
    // TODO: error handeling for mallformed tags here:
    getline(inFile, x);
    if (x.at(0) == '=') {
      // We've found the close tag.
      return links;
    } else {
      // We need to remove the destination from it then display it
      std::string link;
      int firstTag  = 0;
      int secondTag = 0;
      for (int i = 0; i < x.size(); i++) {
        
        if (x.at(i) == '=' && firstTag == 0) {
          firstTag = i;
          continue;
        }
        if (x.at(i) == '=' && firstTag != 0) {
          secondTag = i;
        }
      }
      
      link = x.substr(firstTag + 1, secondTag - firstTag - 1);
      x = x.substr(0, firstTag);
      
      
      // Put the link in the next valid position
      links.push_back(link);
      view_->display(x);
      //view_->display("   link: \"" + link + "\"");
      //view_->display("");
    } // end if
  } // end while
}




/*
 * Takes in a vector of valid file links, and prompts the user to pick one.
 * Does NOT display coresponding chioces, only gets input and runs the specified 
 * dialogue file.
 */
void Controller::loadDecisionLinks(std::vector<std::string>) {
  std::string input = view_->getInput();
  
}



/*
 * Parces the specified file according to a few conventions.
 * Each convention symbol apears at the start of the line, and each folowing line
 * is to be effected by they folowing codex. The 'open' and 'close'
 * encoded symbol is the same, much like comments in code. IE
 *
 *  This is description
 *  =
 *  this is a player choice
 *  =
 *  This is description
 *
 * '=' implies that the folowing items are player selectable choices
 */
void Controller::nocabParseFile(std::string path)
{
  // I need to read a file line by line untill I find the specified character
  
  
  std::string x;
  ///Users/arthurbacon/Desktop/GitProjects/XenoSapiens/Xeno Sapient/
  std::ifstream inFile(path);
  //inFile.open("test");
  
  if (!inFile.is_open()) {
    view_->display("!!didn't open a new file!! Err in Controller nocabParseFile");
    return;
  }
  
  // Check every line in the file for the first character
  while (getline(inFile, x))
  {
    
    if (x.length() == 0) {
      view_->display("");
      continue;
    }
    
    switch (x.at(0))
    {
      case '=':
      {
        // character choice found
        std::vector<std::string> links = parceDecision(inFile);
        
        bool validInput = false;
        // Logic for getting a valid input
        while (!validInput) {
          
          // Get which link we want to follow
          std::string input = view_->getInput();
          
          // Make sure that's a valid choice
          int inputint;
          try {
            inputint = std::stoi(input);
          } catch(std::invalid_argument e) {
            
            view_->display("I didn't understand the choice of: \""+input+"\"");
          }
          
          if (inputint > links.size() || inputint < 0) {
            view_->display("I didn't understand the choice of: \"" + input + "\"");
          }
          
          nocabParseFile(links[inputint - 1]);
          
          
        }
        
        
        break;
      } // end case '='
        
      default:
        // No code char, print description
        view_->display(x);
        //view_->display("");
        break;
    }
    
  }
  
  view_->display("EOF");
  
  inFile.close();
  
}





