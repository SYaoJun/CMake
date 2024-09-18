#include <gtest/gtest.h>
#include <gmock/gmock.h>

class B {
public:
    virtual ~B() = default;
    virtual void stop() = 0;
};

class A {
public:
    A(B* b) : b_(b) {}
    virtual ~A() = default;

    virtual void  stop() {
        if (b_) {
            b_->stop();
        }
    }

private:
    B* b_;
};


class MockB : public B {
public:
    MOCK_METHOD(void, stop, (), (override));
};

class MockA : public A {
public:
    MockA(B* b) : A(b) {}
    MOCK_METHOD(void, stop, (), (override));
};


using ::testing::_;
using ::testing::Return;
using ::testing::Invoke;

class ATest : public ::testing::Test {
protected:
    MockB mockB;
    A a{&mockB};
};

TEST_F(ATest, StopCallsBStop) {
    // 设置期望：当调用 a.stop() 时，期望调用 mockB.stop()
    EXPECT_CALL(mockB, stop()).Times(1);

    // 调用 A 的 stop 方法，应该调用 B 的 stop 方法
    a.stop();
}
