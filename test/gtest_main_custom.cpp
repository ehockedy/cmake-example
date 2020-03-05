#include <gtest/gtest.h>
#include <iostream>

class MinimalistPrinter : public ::testing::EmptyTestEventListener {
  virtual void OnTestProgramStart(const ::testing::UnitTest& unit_test) {
    printf("Starting the Giblet World testing procedure\n");
  }

  virtual void OnTestSuiteStart(const ::testing::TestSuite& test_suite) {
    std::cout << std::endl << "Running " << test_suite.name() << " tests" << std::endl;
  }
  
  // Called before a test starts.
  //virtual void OnTestStart(const ::testing::TestInfo& test_info) {
  //  printf("*** Test %s.%s starting.\n",
  //         test_info.test_suite_name(), test_info.name());
 // }

  // Called after a failed assertion or a SUCCESS().
  //virtual void OnTestPartResult(const ::testing::TestPartResult& test_part_result) {
  //  if (test_part_result.failed()) {
  //    std::cout << 
  //  }
    //printf("  %s in %s:%d\n  %s\n",
    //       test_part_result.failed() ? "*** Failure" : "Success",
    //       test_part_result.file_name(),
    //       test_part_result.line_number(),
    //       test_part_result.summary());
  //}

  // Called after a test ends.
  virtual void OnTestEnd(const ::testing::TestInfo& test_info) {
    if (test_info.result()->Failed()) {
      std::cout << "  \033[1;31mTest " << test_info.name() << " FAILED\033[0m" << std::endl;
    } else {
      std::cout << "  \033[1;32mTest " << test_info.name() << " PASSED\033[0m" << std::endl;
    } 
  }
  
  virtual void OnTestSuiteEnd(const ::testing::TestSuite& test_suite) {
    std::string status;
    test_suite.Passed() ? status = "\033[1;32mPASSED\033[0m" : status = "\033[1;31mFAILED\033[0m";
    std::cout << test_suite.name() << " " << status << std::endl;
    if (!test_suite.Passed()) {
      std::cout << "  " << test_suite.failed_test_count() << " of "
        << test_suite.total_test_count() << " failed." << std::endl;
    }
    
  }
};

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  // Gets hold of the event listener list.
  ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();
  // Adds a listener to the end.  googletest takes the ownership.
  delete listeners.Release(listeners.default_result_printer());

  listeners.Append(new MinimalistPrinter);
  return RUN_ALL_TESTS();
}
