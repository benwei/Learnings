#include "glib.h"
int
test_b (int number)
{
  g_debug ("Hello world from libb: %d", number);
  return 0;
}

