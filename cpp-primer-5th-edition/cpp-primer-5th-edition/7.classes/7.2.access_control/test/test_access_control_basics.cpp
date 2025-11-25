#include <gtest/gtest.h>
#include <string>

// Class for testing access control
class AccessTest {
private:
    std::string privateData;
    int privateValue;
    
protected:
    std::string protectedData;
    int protectedValue;
    
public:
    std::string publicData;
    int publicValue;
    
    // Constructor
    AccessTest(const std::string& priv, int privVal, const std::string& prot, int protVal, const std::string& pub, int pubVal)
        : privateData(priv), privateValue(privVal), protectedData(prot), protectedValue(protVal), publicData(pub), publicValue(pubVal) {}
    
    // Getters for private members
    std::string getPrivateData() const { return privateData; }
    int getPrivateValue() const { return privateValue; }
    
    // Getters for protected members
    std::string getProtectedData() const { return protectedData; }
    int getProtectedValue() const { return protectedValue; }
};

// Test public access
TEST(AccessControlTest, PublicAccess) {
    AccessTest obj("private", 1, "protected", 2, "public", 3);
    
    // Can directly access public members
    EXPECT_EQ("public", obj.publicData);
    EXPECT_EQ(3, obj.publicValue);
    
    obj.publicData = "modified";
    obj.publicValue = 42;
    EXPECT_EQ("modified", obj.publicData);
    EXPECT_EQ(42, obj.publicValue);
}

// Test private access through getters
TEST(AccessControlTest, PrivateAccess) {
    AccessTest obj("private", 1, "protected", 2, "public", 3);
    
    // Cannot directly access private members - must use getters
    EXPECT_EQ("private", obj.getPrivateData());
    EXPECT_EQ(1, obj.getPrivateValue());
}

// Test protected access through getters
TEST(AccessControlTest, ProtectedAccess) {
    AccessTest obj("private", 1, "protected", 2, "public", 3);
    
    // Cannot directly access protected members - must use getters
    EXPECT_EQ("protected", obj.getProtectedData());
    EXPECT_EQ(2, obj.getProtectedValue());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}