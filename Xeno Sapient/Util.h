//
//  Util.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 7/2/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Util_h
#define Util_h

#include <string.h>
#include <iostream>     // std::cout
#include <sstream>
#include <fstream>


static std::stringstream nocabStrBuilder(const char* path)
{
  
  std::stringstream ss;
  
  ss << 100;
  
  int a;
  std::cin >> a;
  ss << ' ' << a;
  ss << '\n';
  
  
  std::cout << ss.str();
  
  return ss;
  
}







static bool textFork(const char* dest)
{
  
  
  return false;
}



















/*
 * Out and Back Fork in a dialogue tree. Used to inject a little personalized flavor text
 * to compliment the players choices.
 * This fork can be it's own self contained fork
 */
static void OBFork(const char* destination)
{
  
}


/*
 * Total Path Change for a dialogue tree. Used when we're at the end of a file
 * and need to move into a new file to continue the dialogue. Usually there
 * is no returning to the origional file.
 */
static void TPCFork(const char* destination)
{
  
}

#endif /* Util_h */
