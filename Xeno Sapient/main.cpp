//
//  main.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


#include "Room.h"
#include "Interactable.h"
#include "Player.h"
#include "Item.h"

#include "Controller.h"
#include "Model.h"
#include "View.h"


using namespace xs_game;


int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  
  
  
  std::shared_ptr<Model> model = std::shared_ptr<Model>(new Model());
  std::shared_ptr<View> view = std::shared_ptr<View>(new View());
  std::shared_ptr<Controller> controller = std::unique_ptr<Controller>(new Controller(model, view));
  
  model->setUpRooms();
  
  std::cout << model->look("garbage string");
  
  
  controller->init();
  //controller->play();
  
  
  
  return 0;
}
