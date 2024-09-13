#include <string>
#include "gmock/gmock.h"
 
namespace gmock_ {
 
class Foo {
    
public:
    int value = 0;
	// Must be virtual as we'll inherit from Foo.
	virtual ~Foo() {}
 
	virtual bool SetName(const std::string& name) = 0;
	virtual std::string GetName() const = 0;
    virtual std::string GenerateString(int x) = 0;
    virtual int GetValue() = 0;
};
 
class MockFoo : public Foo {
public: 
    //! 1. first argument is return type
    //! 2. second argument is the name of the method
    //! 3. third argument is the arguments
    //! 4. fourth argument is the confined type
	MOCK_METHOD(bool, SetName, (const std::string&), (override)); // the last argument is the convention for a mock method.
	MOCK_METHOD(std::string, GetName, (), (const, override));
    MOCK_METHOD(std::string, GenerateString, (int x), (override));
    MOCK_METHOD(int, GetValue, (), (override));
};
 

 
} // namespace gmock_
 
TEST(gmock, name) {
	using namespace gmock_;
	using ::testing::AtLeast;
	using ::testing::Return;
    using ::testing::Invoke;
	MockFoo foo;
	EXPECT_CALL(foo, GenerateString(1))
		.Times(AtLeast(2))
		.WillOnce([](int x) {
          
                return "world1";
        }).WillOnce(Invoke([&foo]() {
            foo.value++;
            return "world2";
        }));

	EXPECT_EQ("world1", foo.GenerateString(1));
    EXPECT_EQ("world2", foo.GenerateString(1));

    EXPECT_CALL(foo, GetValue()).Times(AtLeast(1)).WillOnce(Return(1));
    EXPECT_EQ(1, foo.GetValue());
}


