#include "test_scanner.h"

char* case1 = (char*)"cases/case1.c";
std::vector<TestScanner::ExpectStruct> case1_expected = {
    {1, 1, '\n'},
    {2, 1, 'i'},
    {2, 2, 'n'},
    {2, 3, 't'},
    {2, 4, ' '},
    {2, 5, 'm'},
    {2, 6, 'a'},
    {2, 7, 'i'},
    {2, 8, 'n'},
    {2, 9, '('},
    {2, 10, ')'},
    {2, 11, ' '},
    {2, 12, '{'},
    {2, 13, '\n'},
    {3, 1, ' '},
    {3, 2, ' '},
    {3, 3, ' '},
    {3, 4, ' '},
    {3, 5, 'i'},
    {3, 6, 'n'},
    {3, 7, 't'},
    {3, 8, ' '},
    {3, 9, 'a'},
    {3, 10, ' '},
    {3, 11, '='},
    {3, 12, ' '},
    {3, 13, '0'},
    {3, 14, ';'},
    {3, 15, '\n'},
    {4, 1, ' '},
    {4, 2, ' '},
    {4, 3, ' '},
    {4, 4, ' '},
    {4, 5, 'c'},
    {4, 6, 'h'},
    {4, 7, 'a'},
    {4, 8, 'r'},
    {4, 9, '*'},
    {4, 10, ' '},
    {4, 11, 'b'},
    {4, 12, ' '},
    {4, 13, '='},
    {4, 14, ' '},
    {4, 15, '"'},
    {4, 16, 's'},
    {4, 17, 's'},
    {4, 18, 's'},
    {4, 19, 's'},
    {4, 20, '"'},
    {4, 21, ';'},
    {4, 22, '\n'},
    {5, 1, ' '},
    {5, 2, ' '},
    {5, 3, ' '},
    {5, 4, ' '},
    {5, 5, 'r'},
    {5, 6, 'e'},
    {5, 7, 't'},
    {5, 8, 'u'},
    {5, 9, 'r'},
    {5, 10, 'n'},
    {5, 11, ' '},
    {5, 12, '-'},
    {5, 13, '1'},
    {5, 14, ';'},
    {5, 15, '\n'},
    {6, 1, '}'},
    {6, 2, '\n'},
    {7, 1, '\n'},
    {8, 1, -1},
};


char* case2 = (char*)"cases/case2.c";
std::vector<TestScanner::ExpectStruct> case2_expected = {
    {1, 1, 'i'},
    {1, 2, 'n'},
    {1, 3, 't'},
    {1, 4, ' '},
    {1, 5, 'f'},
    {1, 6, 'u'},
    {1, 7, 'n'},
    {1, 8, '('},
    {1, 9, ')'},
    {1, 10, '\n'},
    {2, 1, '{'},
    {2, 2, '\n'},
    {3, 1, '\t'},
    {3, 2, 'i'},
    {3, 3, 'n'},
    {3, 4, 't'},
    {3, 5, ' '},
    {3, 6, 'a'},
    {3, 7, ' '},
    {3, 8, '='},
    {3, 9, ' '},
    {3, 10, '1'},
    {3, 11, ','},
    {3, 12, ' '},
    {3, 13, 'b'},
    {3, 14, ' '},
    {3, 15, '='},
    {3, 16, ' '},
    {3, 17, 'a'},
    {3, 18, ' '},
    {3, 19, '+'},
    {3, 20, ' '},
    {3, 21, '2'},
    {3, 22, ','},
    {3, 23, ' '},
    {3, 24, 'c'},
    {3, 25, ' '},
    {3, 26, '='},
    {3, 27, ' '},
    {3, 28, 'a'},
    {3, 29, ' '},
    {3, 30, '*'},
    {3, 31, ' '},
    {3, 32, 'b'},
    {3, 33, ','},
    {3, 34, ' '},
    {3, 35, 'd'},
    {3, 36, ' '},
    {3, 37, '='},
    {3, 38, ' '},
    {3, 39, 'b'},
    {3, 40, ' '},
    {3, 41, '*'},
    {3, 42, ' '},
    {3, 43, 'c'},
    {3, 44, ','},
    {3, 45, ' '},
    {3, 46, 'e'},
    {3, 47, ' '},
    {3, 48, '='},
    {3, 49, ' '},
    {3, 50, '1'},
    {3, 51, '0'},
    {3, 52, ';'},
    {3, 53, '\n'},
    {4, 1, '\t'},
    {4, 2, 'i'},
    {4, 3, 'n'},
    {4, 4, 't'},
    {4, 5, ' '},
    {4, 6, 'i'},
    {4, 7, ' '},
    {4, 8, '='},
    {4, 9, ' '},
    {4, 10, '1'},
    {4, 11, '0'},
    {4, 12, ';'},
    {4, 13, '\n'},
    {5, 1, '\n'},
    {6, 1, '\t'},
    {6, 2, 'i'},
    {6, 3, 'f'},
    {6, 4, '('},
    {6, 5, 'a'},
    {6, 6, ' '},
    {6, 7, '>'},
    {6, 8, ' '},
    {6, 9, 'b'},
    {6, 10, ')'},
    {6, 11, ' '},
    {6, 12, '{'},
    {6, 13, '\n'},
    {7, 1, '\t'},
    {7, 2, '\t'},
    {7, 3, 'c'},
    {7, 4, ' '},
    {7, 5, '='},
    {7, 6, ' '},
    {7, 7, 'a'},
    {7, 8, ' '},
    {7, 9, '*'},
    {7, 10, ' '},
    {7, 11, 'b'},
    {7, 12, ';'},
    {7, 13, '\n'},
    {8, 1, '\t'},
    {8, 2, '\t'},
    {8, 3, 'd'},
    {8, 4, ' '},
    {8, 5, '='},
    {8, 6, ' '},
    {8, 7, 'b'},
    {8, 8, ' '},
    {8, 9, '/'},
    {8, 10, ' '},
    {8, 11, 'c'},
    {8, 12, ';'},
    {8, 13, '\n'},
    {9, 1, '\t'},
    {9, 2, '\t'},
    {9, 3, 'e'},
    {9, 4, ' '},
    {9, 5, '='},
    {9, 6, ' '},
    {9, 7, 'c'},
    {9, 8, ' '},
    {9, 9, '%'},
    {9, 10, ' '},
    {9, 11, 'd'},
    {9, 12, ';'},
    {9, 13, '\n'},
    {10, 1, '\t'},
    {10, 2, '}'},
    {10, 3, '\n'},
    {11, 1, '\n'},
    {12, 1, '\t'},
    {12, 2, 'd'},
    {12, 3, 'o'},
    {12, 4, ' '},
    {12, 5, '{'},
    {12, 6, '\n'},
    {13, 1, '\t'},
    {13, 2, '\t'},
    {13, 3, 'c'},
    {13, 4, ' '},
    {13, 5, '='},
    {13, 6, ' '},
    {13, 7, 'a'},
    {13, 8, ' '},
    {13, 9, '*'},
    {13, 10, ' '},
    {13, 11, 'b'},
    {13, 12, ';'},
    {13, 13, '\n'},
    {14, 1, '\t'},
    {14, 2, '\t'},
    {14, 3, 'd'},
    {14, 4, ' '},
    {14, 5, '='},
    {14, 6, ' '},
    {14, 7, 'b'},
    {14, 8, ' '},
    {14, 9, '*'},
    {14, 10, ' '},
    {14, 11, 'c'},
    {14, 12, ';'},
    {14, 13, '\n'},
    {15, 1, '\t'},
    {15, 2, '\t'},
    {15, 3, 'e'},
    {15, 4, ' '},
    {15, 5, '='},
    {15, 6, ' '},
    {15, 7, 'c'},
    {15, 8, ' '},
    {15, 9, '*'},
    {15, 10, ' '},
    {15, 11, 'd'},
    {15, 12, ';'},
    {15, 13, '\n'},
    {16, 1, '\t'},
    {16, 2, '}'},
    {16, 3, ' '},
    {16, 4, 'w'},
    {16, 5, 'h'},
    {16, 6, 'i'},
    {16, 7, 'l'},
    {16, 8, 'e'},
    {16, 9, '('},
    {16, 10, 'i'},
    {16, 11, '-'},
    {16, 12, '-'},
    {16, 13, ')'},
    {16, 14, ';'},
    {16, 15, '\n'},
    {17, 1, '\n'},
    {18, 1, '\t'},
    {18, 2, 'r'},
    {18, 3, 'e'},
    {18, 4, 't'},
    {18, 5, 'u'},
    {18, 6, 'r'},
    {18, 7, 'n'},
    {18, 8, ' '},
    {18, 9, 'a'},
    {18, 10, ' '},
    {18, 11, '+'},
    {18, 12, ' '},
    {18, 13, 'e'},
    {18, 14, ';'},
    {18, 15, '\n'},
    {19, 1, '}'},
    {19, 2, '\n'},
    {20, 1, '\n'},
    {21, 1, 'i'},
    {21, 2, 'n'},
    {21, 3, 't'},
    {21, 4, ' '},
    {21, 5, 'm'},
    {21, 6, 'a'},
    {21, 7, 'i'},
    {21, 8, 'n'},
    {21, 9, '('},
    {21, 10, ')'},
    {21, 11, ' '},
    {21, 12, '{'},
    {21, 13, '\n'},
    {22, 1, '\t'},
    {22, 2, 'i'},
    {22, 3, 'n'},
    {22, 4, 't'},
    {22, 5, ' '},
    {22, 6, 'i'},
    {22, 7, ' '},
    {22, 8, '='},
    {22, 9, ' '},
    {22, 10, '5'},
    {22, 11, '0'},
    {22, 12, '0'},
    {22, 13, ','},
    {22, 14, ' '},
    {22, 15, 'j'},
    {22, 16, ';'},
    {22, 17, '\n'},
    {23, 1, '\n'},
    {24, 1, '\t'},
    {24, 2, 'w'},
    {24, 3, 'h'},
    {24, 4, 'i'},
    {24, 5, 'l'},
    {24, 6, 'e'},
    {24, 7, '('},
    {24, 8, 'i'},
    {24, 9, '-'},
    {24, 10, '-'},
    {24, 11, ')'},
    {24, 12, '{'},
    {24, 13, '\n'},
    {25, 1, '\t'},
    {25, 2, '\t'},
    {25, 3, 'j'},
    {25, 4, ' '},
    {25, 5, '='},
    {25, 6, ' '},
    {25, 7, 'f'},
    {25, 8, 'u'},
    {25, 9, 'n'},
    {25, 10, '('},
    {25, 11, ')'},
    {25, 12, ';'},
    {25, 13, '\n'},
    {26, 1, '\t'},
    {26, 2, '}'},
    {26, 3, '\n'},
    {27, 1, '\n'},
    {28, 1, '\t'},
    {28, 2, 'r'},
    {28, 3, 'e'},
    {28, 4, 't'},
    {28, 5, 'u'},
    {28, 6, 'r'},
    {28, 7, 'n'},
    {28, 8, ' '},
    {28, 9, 'i'},
    {28, 10, ' '},
    {28, 11, '='},
    {28, 12, ' '},
    {28, 13, 'j'},
    {28, 14, ';'},
    {28, 15, '\n'},
    {29, 1, '}'},
    {29, 2, '\n'},
    {30, 1, -1},
};

void TestScanner::Entry() {
    std::vector<TestScanner> tests = {
        {case1, case1_expected},
        {case2, case2_expected},
    };

    for (const TestScanner& test : tests) {
        auto result = test.run();
        
        size_t result_cnt = result.size();
        size_t expected_cnt = test._expected.size();
        if (result_cnt != expected_cnt) {
            PDEBUG(FATAL "testcase '%s' expect %zu chars, but got %zu!\n", test._name, expected_cnt, result_cnt);
            Error::errorNum++;
            continue;
        }

        size_t cnt = std::min(result_cnt, expected_cnt);
        for (size_t i = 0; i < cnt; ++i) {
            const TestScanner::ExpectStruct& r = result[i];
            const TestScanner::ExpectStruct& e = test._expected[i];

            if (r.row != e.row ||
                r.col != e.col ||
                r.ch  != e.ch) {
                PDEBUG(FATAL "testcase '%s' at %zuth char: \n", test._name, i);
                PDEBUG(INFO "  expect:  %s\n", Scanner::showChar(e.ch, e.row, e.col).c_str());
                PDEBUG(INFO "  but got: %s\n", Scanner::showChar(r.ch, r.row, r.col).c_str());
                Error::errorNum++;
            }
        }
    }
    int error = Error::errorNum;
    int warn  = Error::warnNum;
    std::cout<<"Finish Compile: Error="<<error<<", Warn="<<warn<<"."<<std::endl;
}