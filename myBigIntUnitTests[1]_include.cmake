if(EXISTS "/home/joe/dev/myBigInt/myBigIntUnitTests[1]_tests.cmake")
  include("/home/joe/dev/myBigInt/myBigIntUnitTests[1]_tests.cmake")
else()
  add_test(myBigIntUnitTests_NOT_BUILT myBigIntUnitTests_NOT_BUILT)
endif()
