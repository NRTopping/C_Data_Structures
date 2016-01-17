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

TEST(NDSlist, listGetInsertHead_empty) { 
  const int data = 1;
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_insert_head(list, (nds_element_t) data);
  TEST_ASSERT_EQUAL_INT(1, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data, (int)nds_list_get_head(list));
}

TEST(NDSlist, listGetInsertHead_nonEmpty) { 
  const int data_1 = 1, 
            data_2 = 2; 
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_insert_head(list, (nds_element_t) data_1);
  TEST_ASSERT_EQUAL_INT(1, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data_1, (int)nds_list_get_head(list));
  nds_list_insert_head(list, (nds_element_t) data_2);
  TEST_ASSERT_EQUAL_INT(2, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data_2, (int)nds_list_get_head(list));
  TEST_ASSERT_EQUAL_INT(data_1, (int)nds_list_get_tail(list));
}

TEST(NDSlist, listGetInsertTail_empty) { 
  const int data = 1;
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_insert_tail(list, (nds_element_t) data);
  TEST_ASSERT_EQUAL_INT(1, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data, (int)nds_list_get_tail(list));
}

TEST(NDSlist, listGetInsertTail_nonEmpty) { 
  const int data_1 = 1, 
            data_2 = 2; 
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_insert_tail(list, (nds_element_t) data_1);
  TEST_ASSERT_EQUAL_INT(1, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data_1, (int)nds_list_get_tail(list));
  nds_list_insert_tail(list, (nds_element_t) data_2);
  TEST_ASSERT_EQUAL_INT(2, nds_list_size(list));
  TEST_ASSERT_EQUAL_INT(data_2, (int)nds_list_get_tail(list));
  TEST_ASSERT_EQUAL_INT(data_1, (int)nds_list_get_head(list));
}

TEST(NDSlist, listFlush_empty) { 
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_flush(list);
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
}

TEST(NDSlist, listFlush_nonEmpty) { 
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  nds_list_insert_head(list, (nds_element_t) 1);
  nds_list_insert_head(list, (nds_element_t) 2);
  nds_list_insert_head(list, (nds_element_t) 3);
  TEST_ASSERT_EQUAL_INT(3, nds_list_size(list));

  nds_list_flush(list);
  TEST_ASSERT_EQUAL_INT(0, nds_list_size(list));
  TEST_ASSERT_NULL(nds_list_get_head(list));
  TEST_ASSERT_NULL(nds_list_get_tail(list));
}

TEST_GROUP_RUNNER(NDSlist) { 
  RUN_TEST_CASE(NDSlist, listAllocate);
  RUN_TEST_CASE(NDSlist, listGetInsertHead_empty);
  RUN_TEST_CASE(NDSlist, listGetInsertHead_nonEmpty);
  RUN_TEST_CASE(NDSlist, listGetInsertTail_empty);
  RUN_TEST_CASE(NDSlist, listGetInsertTail_nonEmpty);
  RUN_TEST_CASE(NDSlist, listFlush_empty);
  /*RUN_TEST_CASE(NDSlist, listFlush_nonEmpty);*/
}

static void RunAllTests() { 
  RUN_TEST_GROUP(NDSlist);
}

int main(int argc, const char *argv[]) { 
  return UnityMain(argc, argv, RunAllTests);
}
