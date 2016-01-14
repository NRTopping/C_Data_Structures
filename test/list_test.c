#include <NDS/list.h>
#include <unity_fixture.h>
#include <unity.h>

static nds_list_t list = NULL;

TEST_GROUP(NDSlist);

TEST_SETUP(NDSlist) { 
  // Create list, no special allocation/deallocation
  list = nds_list_alloc(NULL, NULL); 
}

TEST_TEAR_DOWN(NDSlist) { 
  if (list != NULL) nds_list_free(list);
}

TEST(NDSlist, listAllocate) { 
  TEST_ASSERT_NOT_NULL(list);
}

TEST_GROUP_RUNNER(NDSlist) { 
  RUN_TEST_CASE(NDSlist, listAllocate);
}

static void RunAllTests() { 
  RUN_TEST_GROUP(NDSlist);
}

int main(int argc, const char *argv[]) { 
  return UnityMain(argc, argv, RunAllTests);
}
