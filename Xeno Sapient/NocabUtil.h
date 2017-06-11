//
//  NocabUtil.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/11/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef NocabUtil_h
#define NocabUtil_h

#include <string.h>


/**
 * A case insensitive string comparison operation. True is returned iff a
 * and b are the same string after casting both to lowerase. s
 */
static bool nocabStrCmp(std::string a, std::string b) {
  auto length = a.length();
  if (length != b.length()) {
    return false;
  }
  for (unsigned int i = 0; i < length; ++i) {
    if (tolower(a[i]) != tolower(b[i])) {
      return false;
    }
  }
  return true;
}

/**
 * Changes every character to a lowercase. 
 */
static void nocabToLower(std::string a) {
  int i = 0;
  char c;
  while (a[i])
  {
    c = a[i];
    putchar (tolower(c));
    i++;
  }
}


#endif /* NocabUtil_h */
