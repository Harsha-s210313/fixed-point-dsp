#include <stdio.h>
#include <fp_math.h>
#include <test_fp_math.h>

#define TEST(condition, name) \
    if(condition) { printf("%s: PASS\n", name); } \
    else { printf("%s: FAIL\n", name); }

void test_fp_mul(){
    TEST(fp_mul(Q15(0.7), Q15(0.9)) == 20644, "mul normal");
    TEST(fp_mul(Q15_MAX, Q15(0.9)) == 29490, "mul positive overflow");
    TEST(fp_mul(Q15(-1.0), Q15(0.9)) == -29491, "mul negative");
    TEST(fp_mul(Q15(-1.0), Q15(-1.0)) == 32767, "mul edge case");
}

void test_fp_add(){
	TEST(fp_add(Q15(0.7),Q15(0.2)) == 29492, "add normal " );
	TEST(fp_add(Q15_MAX,Q15(0.9)) == 32767, "add normal overflow" );
	TEST(fp_add(Q15(-1.0),Q15(0.9)) == -3277, "add negative" );
	TEST(fp_add(Q15(-1.0),Q15(-1.0)) == -32768, "add edge case" );
}

void test_fp_sub(){
	TEST(fp_sub(Q15(0.7),Q15(0.2)) == 16384, "sub normal " );
	TEST(fp_sub(Q15_MIN,Q15(0.1)) == -32768, "sub normal overflow" );
	TEST(fp_sub(Q15(-0.5),Q15(0.0)) == -16384, "sub negative" );
	TEST(fp_sub(Q15(-1.0),Q15(-1.0)) == 0, "sub edge case" );
}

void test_fp_div(){
	TEST(fp_div(Q15(0.7),Q15(0.2)) == 32767, "div normal");
	TEST(fp_div(Q15_MAX,0) == 32767, "div normal overflow");
	TEST(fp_div(Q15(0.7),Q15(-0.2)) == -32768, "div negative");
	TEST(fp_div(Q15(-0.7),Q15(-0.2)) == 32767, "div edge case");
}

void run_all_tests(){
	test_fp_add();
	test_fp_sub();
	test_fp_mul();
	test_fp_div();
}
