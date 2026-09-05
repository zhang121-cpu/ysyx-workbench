#include "klibtest.h"

void test_string();
void test_stdio();

static const char *test_names[256] = {
  ['s'] = "string/memory test",
  ['f'] = "formatted output (stdio) test"
};

int main(const char *args) {
  switch (args[0]) {
    case 's':
      test_string();
      break;
    case 'f': 
      test_stdio();  
      break;
    default:
      printf("Usage: make run mainargs=*\n");
      for (int ch = 0; ch < 256; ch++) {
        if (test_names[ch]) {
          printf("  %c: %s\n", ch, test_names[ch]);
        }
      }
  }
  return 0;
}



