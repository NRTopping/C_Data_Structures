#include <NDS/lnode.h>
/*#include "../include/NDS/lnode.h"*/
#include <unity_fixture.h>
#include <unity.h>
/*#include "Unity/extras/fixture/src/unity_fixture.h"*/
/*#include "Unity/src/unity.h"*/


static nds_lnode_t node = NULL;

TEST_GROUP(NDSlnode);

TEST_SETUP(NDSlnode) { 
  node = nds_lnode_alloc();
}

TEST_TEAR_DOWN(NDSlnode) { 
  if (node != NULL) nds_lnode_free(node);
}

TEST(NDSlnode, alloc) { 
  TEST_ASSERT_NOT_NULL(node);
}

TEST_GROUP_RUNNER(NDSlnode) { 
  RUN_TEST_CASE(NDSlnode, alloc);
}

static void RunAllTests() { 
  RUN_TEST_GROUP(NDSlnode);
}

int main(int argc, const char *argv[]) { 
  return UnityMain(argc, argv, RunAllTests);
}

