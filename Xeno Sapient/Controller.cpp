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
#include "ConvoNode.h"


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
void Controller::look(std::string at)
{
  view_->display(model_->look(at));
  //view_->display(model_->lookBig(at));
}

void Controller::look()
{
  // NOTE: This will only get the current Room's descriptor
  
  // Get the file to be read out
  std::string path = model_->getDescriptionFilePath("room");
  // This will display to _view
  nocabParseFile(path);
  
  // Get the list of items in the room and display
  std::string items = model_->getInteractInRoom();
  view_->display(items);
  
  // Get the list of possible movement and display
  std::string paths = model_->getPathsFromRoom();
  view_->display(paths);
  
  
  //view_->display(model_->lookBig(at));
}


void Controller::use(std::string useName) {
  //model_->use(useName);

  //First make sure the item exists, if it does then 'use' it
  // if it doesn't then alert the player that the obj isn't in the room

  if (model_->checkInteractables(useName)) {
    // The item exists
    model_->useInteractable(useName);
  } else {
    // The item doesn't exist
    view_->display("The item:\"" + useName + "\" doesn't exist or can't be used.");
  }
  
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
        
        
        if (tokens.size() == 1) {             // If you only have "LOOK" then look at the room
          //std::cout << "  size == 1\n";
          this->look();       // look w/o args => look at room
        }
        else if (tokens.size() == 2) {      // Look at the specified object
          this->look(tokens.at(1));
        }
        else {
          // Can't really look at 2 things at once...
        }
        break;
      case USE:
        
        // Make sure it's not a mallformed command
        if (tokens.size() == 2) {
          // Just use the item
          this->use(tokens.at(1));
          
        } else if (tokens.size() == 3) {
          // Use an item on the interactable
          view_->display("ERROR: using w/ 3 obj is not supported yet... Controller.cpp play()");
        
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




/////////////////////////////////////////////////////////////
// Dealing with dialogue trees.






std::vector<std::string> Controller::parceDecision(std::ifstream &inFile)
{
  
  std::vector<std::string> result;
  result.push_back("TODO: Controller.cpp parce Decision()");
  return result;
  
  
//  std::string x;
//  std::vector<std::string> links;
//  std::vector<std::pair<std::string, bool> > boolChanges;
//
//  // We come in, it starts off on the line of the open '=' tag
//  // Move to the next line
//  // Is that the close tag?
//  //  yes => return
//  //  no  => print line
//  // Move to the next line
//  // Is that the close tag?
//  //  yes => return
//  //  no => print line
//
//  /* NOTE: the only way to exit this loop is in the first if check.
//   *        the only way to exit this loop is if the file we're reading
//   *        actually has a closing '=' tag.
//   */
//  while(true) {
//
//    // Vars used to help keep the two vectors in parellel
//    bool nextFilePush = false;
//    bool boolChangePush = false;
//
//
//    // TODO: error handeling for mallformed tags here:
//    // get the line from the view next time...
//    getline(inFile, x);
//    bool diterminedText = false;
//
//    if (x.at(0) == '=') {
//      // We've found the close tag.
//      return links;
//    } else {
//      // We need to remove the destination from it then display it
//      std::string link;
//      int firstTag  = -1;
//      int secondTag = -1;
//      for (int i = 0; i < x.size(); i++) {
//
//        switch(x.at(i)) {
//          case '{':
//          case '[':
//          case '(':
//          {
//            firstTag = i;
//            if (!diterminedText) {
//              x = x.substr(0, firstTag);
//              diterminedText = true;
//            }
//            break;
//          }
//          /////////
//          case '}':       // {} are for setting the next file to read
//          {
//            secondTag = i;
//
//            link = x.substr(firstTag + 1, secondTag - firstTag - 1);
//            links.push_back(link);
//            nextFilePush = true;
//            break;
//          }
//          /////////
//          case ']':       // [] are for checking to see if option is avaliable
//          {
//            secondTag = i;
//            std::string requiredBool = x.substr(firstTag + 1, secondTag - firstTag - 1);
//            if(model_->checkBool(requiredBool) && diterminedText) {
//              view_->display(x);
//            } else if (!diterminedText) {
//              view_->display("ERR in parceDecision controller.cpp: Tried to print unditermined text");
//            }
//            break;
//          }
//          /////////
//          case ')':       // () are for modifying model bools if the option is chosen
//          {
//            secondTag = i;
//            std::string changeBool = x.substr(firstTag + 1, secondTag - firstTag - 1);
//            std::pair<std::string, bool> changePairTemp = this->parceChangeBool(changeBool);
//            boolChanges.push_back(changePairTemp);
//            boolChangePush = true;
//            break;
//          }
//          // default do nothing
//          default:
//          {
//
//          }
//
//        } // end switch;
//
//        if (!boolChangePush) {
//          links.push_back("\0");
//        }
//
//
//        /*
//        if (x.at(i) == '{') {
//          firstTag = i;
//          continue;
//        }
//        if (x.at(i) == '}') {
//          secondTag = i;
//        }
//
//        if (secondTag != 0) {
//
//        }
//         */
//
//      }// end for loop
//
//    } // end if
//  } // end while
}




/*
 * Takes in a vector of valid file links, and prompts the user to pick one.
 * Does NOT display coresponding chioces, only gets input and runs the specified 
 * dialogue file.
 */
void Controller::loadDecisionLinks(std::vector<std::string>) {
  std::string input = view_->getInput();}



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
    view_->display("attempted to open:\"" + path + "\"");
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
        view_->display("Attempted to display a decision file, these are out of date and unsupported");
        
//        // character choice found
//        std::vector<std::string> links = parceDecision(inFile);
//
//        bool validInput = false;
//        int inputint = 0;
//        // Logic for getting a valid input
//        while (!validInput) {
//
//          // Get which link we want to follow
//          std::string input = view_->getInput();
//
//          try {
//            inputint = std::stoi(input);
//          } catch(std::invalid_argument e) {
//
//            view_->display("I didn't understand the choice of: \""+input+"\"");
//          }
//
//          if (inputint > links.size() || inputint < 0) {
//            view_->display("I didn't understand the choice of: \"" + input + "\"");
//          } else {
//            // input is valid
//            validInput = true;
//          }
//
//
//        }
//
//
//        nocabParseFile(links[inputint - 1]);
//
//        break;
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


void Controller::runCutsceene(std::string rootFileName) {
  // Make sure the file exists
  // Convert it into a ConvoNode
  // While the next file name is NOT a null
  //  read the CN
  //  Get the player input on selection
  //  convert the player input index to the 'real' index
  //  reset the current CN
  //  redo the while loop
  
  ConvoNode currentCN (rootFileName);
  
  auto currentVars = *(model_->getCurrentVars());
  view_->display(currentCN.read(currentVars));
  
  bool validInput = false;
  int playerInputIndex = 0;
  while (!validInput) {
    std::string playerInput = view_->getInput();
    try {
      playerInputIndex = std::stoi(playerInput);
      validInput = true;
    } catch (const std::invalid_argument& err) {
      // invalid input
      view_->display("Couldn't understand your input please re-enter");
    }
  }
  
  // Convert playerInputIndex to the 'real' index
  int realIndex = convertToRealIndex(playerInputIndex, currentCN);
  
  currentCN = currentCN.followGraph(realIndex);
  
}


int Controller::convertToRealIndex(int playerInput, ConvoNode& cn) {
  for (int i = playerInput; i < cn.vectorLength(); i++) {
    // While we have NOT found a valid real index
    if (cn.check(*(model_->getCurrentVars()), i)) {
      // If we have a valid option, end the loop
      return i;
    }
  }
  
  return -1;
}





