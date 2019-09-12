# include <stdlib.h>
# include <stdio.h>

char* string_from_library(char* value) {
  char* out = (char*)malloc(256 * sizeof(char));
  sprintf(out, "String: '%s'", value);
  return out;
}

int number_from_library(int value) {
  return value + 1;
}

int boolean_from_library(int value) {
  if (value == 0) {
    return 1;
  } else {
    return 0;
  }
}
