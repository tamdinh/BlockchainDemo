#include <Block.h>
#include "gtest/gtest.h"

class BlockTest : public ::testing::Test {
public :
    Block* block;
protected:
    virtual void TearDown() {
        delete block;
    }

    virtual void SetUp() {
       block = new Block(0,"Block 0");
    }
};

TEST_F(BlockTest, TestBlockContructor) {
    Block *b = block;
    EXPECT_EQ(0,b->GetHeight());
}
TEST_F(BlockTest, TestBlockContructor2) {
    Block *b = block;
    const char* expectVal = "hello";
    const char* actualVal = b->GetHash().c_str();
    EXPECT_STREQ(expectVal,actualVal);
}