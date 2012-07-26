#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
static int verbose = 0;

class MockObject {
	public:
		void log(const string &msg) {
			if(verbose)
			cout << __PRETTY_FUNCTION__ << "_" << msg << endl;
		}

		MockObject() {
			log("a");
		}
		~MockObject() {
			log("a");
		}
		int Dummy(const string user, const string desc) {
			log(user + desc);
			return 0;
		}
};

// The fixture for testing class MockObject.
class MockObjectTest : public ::testing::Test {
	protected:
		// You can remove any or all of the following functions if its body
		// is empty.

		MockObjectTest() {
			// You can do set-up work for each test here.
		}

		virtual ~MockObjectTest() {
			// You can do clean-up work that doesn't throw exceptions here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:

		virtual void SetUp() {
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		virtual void TearDown() {
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

		// Objects declared here can be used by all tests in the test case for MockObject.
};

// Tests that the MockObject::Bar() method does Abc.
TEST_F(MockObjectTest, MethodDummy) {
	const string input_filepath = "this/package/testdata/myinputfile.dat";
	const string output_filepath = "this/package/testdata/myoutputfile.dat";
	MockObject f;
	EXPECT_EQ(0, f.Dummy("I", " am dummy"));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	// parse '-v' for verbose
	for (int i = 0; i < argc ; i++) {
		const char *arg = argv[i];
		if (*arg == '-' && arg[1] == 'v')
			verbose = 1;

	}
	return RUN_ALL_TESTS();
}
