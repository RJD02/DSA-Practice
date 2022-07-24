//https://www.codewars.com/kata/517abf86da9663f1d2000003/train/cpp

#include <string>
#include <iostream>
using namespace std;

std::string to_camel_case(std::string text) {
  // TODO: Your code goes here!
  string ret;
  for(int i = 0; i < text.size(); i++) {
    if(text[i] == '-' or text[i] == '_') {
      i++;
      ret += toupper(text[i]);
    } else {
      ret += text[i];
    }
  }
  return ret;
}