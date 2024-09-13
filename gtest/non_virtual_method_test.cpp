#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

using ::testing::_;
using ::testing::Invoke;

// 实际类
class MyClass {
public:
    void NonVirtualMethod() {
        std::cout << "NonVirtualMethod called" << std::endl;
    }
};

// 接口定义
class MyClassInterface {
public:
    virtual ~MyClassInterface() = default;
    virtual void NonVirtualMethod() = 0;
};

// 代理类
class MyClassProxy : public MyClassInterface {
public:
    explicit MyClassProxy(MyClass* my_class) : my_class_(my_class) {}
    void NonVirtualMethod() override {
        my_class_->NonVirtualMethod();
    }

private:
    MyClass* my_class_;
};

// Mock 类
class MockMyClass : public MyClassInterface {
public:
    MOCK_METHOD(void, NonVirtualMethod, (), (override));
};

// 测试实际类
TEST(MyClassTest, ActualNonVirtualMethodTest) {
    MyClass my_class;
    MyClassProxy proxy(&my_class);
    proxy.NonVirtualMethod();
}

// 测试 Mock 类
TEST(MyClassTest, NonVirtualMethodTest) {
    MockMyClass mock_my_class;
    EXPECT_CALL(mock_my_class, NonVirtualMethod()).Times(1);

    MyClassInterface* interface = &mock_my_class;
    interface->NonVirtualMethod();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
