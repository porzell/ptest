# PTest
## What is PTest?
Glad you asked!  PTest is short for PicoTest.

### PicoTest is a header-only, super-lightweight unit testing library.

PTest allows you to quickly add unit tests to your project without the need for
compiling and linking a separate testing library (like gtest).

PicoTest is absolutely tiny at ~340 LoC, but still can get the job done.

## So, how do I use this thing?
Easy!  First off you've got to make a test case.  That'll look like this:
```C++
P_TEST(MyTestName) {
    ...
}
```

Inside your P_TEST body, you'll want to add some assertions to test.  Basically,
any expression that would work in an if statement will work inside an assertion.

Here's how simple an example test file can be!

```C++
#define USE_PTEST_MAIN
#include "../include/ptest.hpp"
#include <string>

P_TEST(MyFirstTest) {
	std::string testString;

	testString += "hello";
	testString += ' ';
	testString += "world!";

	P_ASSERT(testString == "hello world!");
	P_EXPECT(testString == "goodbye world!");
	
	P_ASSERT(2 + 2 != 4);
}
```

And here's what you'll see in your console:

```
Found test MyFirstTest...

[Running all tests]

[Running] MyFirstTest:

============================================
Expectation Failure in testproject.cpp (Line 14)
     Condition not met:
        (testString == "goodbye world!")


============================================
Assertion Failure in testproject.cpp (Line 16)
     Condition not met:
        (2 + 2 != 4)

 Test 'MyFirstTest' finished. (0.497651 ms)
   2 assertions failed.
   3 assertions run.
============================================

==================================================================
[Test Summary]:                 (Total Time: 0.497651 ms)
        Tests Passed:   0
        Tests Failed:   1
        Total Tests:    1
==================================================================
```

Nice, huh?

## Other Features

### Test Fixtures

PTest also lets you provide your own main function to run through tests and also
supports the use of test fixture classes like this:

```C++
#define USE_PTEST_MAIN
#include "../include/ptest.hpp"

class MyTestFixtureClass : public PTest::PTestFixture {
    protected:
        int myVar = 3;
    public:
        virtual void Create() {
            // Stuff here gets called before test case.
        }
        virtual void Destroy() {
            // Stuff here gets called after test case.
        }
};

P_TEST_F(MyTestFixtureClass, UnitTest1) {
    P_ASSERT(myVar == 3);
}

P_TEST_F(MyTestFixtureClass, UnitTest2) {
    P_ASSERT(myVar == 3);
    myVar = 4;
}

int main() {
    return PTest::PTestRegistry::Get().RunAllTests();
}
```


PTest will automatically gather all ```P_TEST()``` and ```P_TEST_F()``` tests to
run, so you don't need to worry about it.

If you would like to run just one test you can also use:
```C++
return PTest::PTestRegistry::Get().RunTest("MyFirstTest");
```

## Planned Features
Currently, the planned list of PTest features to be supported includes:
* Descriptive assertions:
 This will allow you to add a custom text output to display on an assertion failure.
* Gherkin-like test syntax:
 Oh yeah, that's right!  PTest will soon be supporting a Gherkin-like block syntax to allow you to bring Test-driven development to your project in one tiny header.
* Test tags/filters:
 For when you're really rather choosy about your tests...
* Exception catch assertions:
 This will be pretty easy to add in and likely will be coming very soon.

## License
PicoTest is licensed under the MIT License, so it's easy to integrate into any project, big or small.

```
MIT License

Copyright (c) 2018 Peter Orzell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Compatibility
PTest is currently set up to work on Windows (MSVC++) and Linux (G++/Clang).

## Have fun!
Let me know if you end up using this!  I'll be working on it regularly.