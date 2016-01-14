#include <NDS/lnode.h>
#include <unity_fixture.h>
#include <unity.h>

static nds_lnode_t node = NULL;
static nds_lnode_t altNode = NULL;                   

TEST_GROUP(NDSlnode);

TEST_SETUP(NDSlnode) { 
  node = nds_lnode_alloc();
  altNode = nds_lnode_alloc();
}

TEST_TEAR_DOWN(NDSlnode) { 
  if(node != NULL) nds_lnode_free(node);
  if(altNode != NULL) nds_lnode_free(altNode);
}

TEST(NDSlnode, allocateNode) { 
  TEST_ASSERT_NOT_NULL(node);
  TEST_ASSERT_NULL(nds_lnode_get_next(node));
  TEST_ASSERT_NULL(nds_lnode_get_prev(node));
  TEST_ASSERT_NULL(nds_lnode_get_data(node));
}

TEST(NDSlnode, freeNodeNullData) { 
  const nds_element_t nullRes = nds_lnode_free(node);
  TEST_ASSERT_NULL(nullRes);
  node = NULL;
}

TEST(NDSlnode, freeNodeData) { 
  nds_lnode_set_data(node, (nds_element_t) 1);
  const nds_element_t res = nds_lnode_free(node);
  node = NULL;
  TEST_ASSERT_EQUAL_INT(1, res);
}

TEST(NDSlnode, getNextNullNode) { 
  const nds_lnode_t next = nds_lnode_get_next(node);
  TEST_ASSERT_NULL(next);
}

TEST(NDSlnode, getSetNextNode) { 
  nds_lnode_set_next(node, altNode);
  TEST_ASSERT_EQUAL_PTR(altNode, nds_lnode_get_next(node));
}

TEST(NDSlnode, getPrevNullNode) { 
  const nds_lnode_t prev = nds_lnode_get_prev(node);
  TEST_ASSERT_NULL(prev);
}

TEST(NDSlnode, getSetPrevNode) { 
  nds_lnode_set_prev(node, altNode);
  TEST_ASSERT_EQUAL_PTR(altNode, nds_lnode_get_prev(node));
}

TEST(NDSlnode, linkNodes) { 
  nds_lnode_link(node, altNode);

  TEST_ASSERT_NULL(nds_lnode_get_prev(node));
  TEST_ASSERT_EQUAL_PTR(altNode, nds_lnode_get_next(node));

  TEST_ASSERT_EQUAL_PTR(node, nds_lnode_get_prev(altNode));
  TEST_ASSERT_NULL(nds_lnode_get_next(altNode));
}

TEST(NDSlnode, unlinkNodes) { 
  nds_lnode_link(node, altNode);
  nds_lnode_unlink(node, altNode);

  TEST_ASSERT_NULL(nds_lnode_get_prev(node));
  TEST_ASSERT_NULL(nds_lnode_get_next(node));

  TEST_ASSERT_NULL(nds_lnode_get_prev(altNode));
  TEST_ASSERT_NULL(nds_lnode_get_next(altNode));
}

TEST(NDSlnode, writeNode) { 
  // TODO 
}

TEST(NDSlnode, readNode) { 
  // TODO 
}

TEST_GROUP_RUNNER(NDSlnode) {
  RUN_TEST_CASE(NDSlnode, allocateNode);
  RUN_TEST_CASE(NDSlnode, freeNodeNullData);
  RUN_TEST_CASE(NDSlnode, freeNodeData);
  RUN_TEST_CASE(NDSlnode, getNextNullNode);
  RUN_TEST_CASE(NDSlnode, getSetNextNode);
  RUN_TEST_CASE(NDSlnode, getPrevNullNode);
  RUN_TEST_CASE(NDSlnode, getSetPrevNode);
  RUN_TEST_CASE(NDSlnode, linkNodes);
  RUN_TEST_CASE(NDSlnode, unlinkNodes);
  RUN_TEST_CASE(NDSlnode, writeNode);
  RUN_TEST_CASE(NDSlnode, readNode);
}

static void RunAllTests() { 
  RUN_TEST_GROUP(NDSlnode);
}

int main(int argc, const char *argv[]) { 
  return UnityMain(argc, argv, RunAllTests);
}

