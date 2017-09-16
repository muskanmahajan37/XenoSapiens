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
#include <fstream>


#include "Room.h"
#include "Interactable.h"
#include "Player.h"
#include "Item.h"

#include "Controller.h"
#include "Model.h"
#include "View.h"

#include "Util.h"

#include <unistd.h>

#include <functional>


using namespace xs_game;


int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  
  
  
  //std::stringstream ss = nocabStrBuilder("abcd");
  
  std::shared_ptr<Model> model = std::shared_ptr<Model>(new Model());
  std::shared_ptr<View> view = std::shared_ptr<View>(new View());
  std::shared_ptr<Controller> controller = std::unique_ptr<Controller>(new Controller(model, view));
  
  //controller->nocabParseFile("text/test.txt");
  
  model->init();
  
  //std::cout << model->look("garbage string");
  
  
//  controller->init();
//  controller->play();
  
//  Room* testRoom = new Room("test room");
//  std::shared_ptr<Item> item1 = std::shared_ptr<Item>(new Item("Item 1"));
//  std::shared_ptr<Item> item2 = std::shared_ptr<Item>(new Item("Item 2"));
//  testRoom->addItem(item1);
//  testRoom->addItem(item2);
//  
//  std::cout << testRoom->stringifyItems();
//  
//  std::cout << model->getPathsFromRoom();
  
  auto testLamb =
  [](double d) -> int {
    if (d < 10) {
      return 0;
    } else {
      return d;
    }
  };
  
  //int result = testLamb(5);
  
  std::cout << std::to_string(testLamb(10)) << std::endl;
  
  
  
  return 0;
}
