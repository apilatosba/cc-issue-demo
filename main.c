#include <stdio.h>

#define CC_NO_SHORT_NAMES
#include "cc.h"

typedef struct Player Player;
struct Player {
   int id;
   char* name;
};

#define CC_CMPR Player, { return val_1.id < val_2.id ? -1 : val_1.id > val_2.id; }
#define CC_HASH Player, { return val.id * 2654435761ull; }
#include "cc.h"

int main() {
   cc_map(char*, Player) customValueMap;
   cc_init(&customValueMap);

   cc_insert(&customValueMap, "Player", (Player){.id = 10, .name = "Player 10"}); // this line doesnt compile
   // cc_insert(&customValueMap, "Player", ((Player){.id = 10, .name = "Player 10"})); // this line compiles

   cc_for_each(&customValueMap, key, value) {
      printf("%s: %i\n", *key, value->id);
   }

   return 0;
}
