#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncpy) {
    char result[10];
	char bisque[8];
	EXPECT_EQ(String::strncpy(result, "ferrari", 100), result);
	EXPECT_STREQ(result, "ferrari");
	EXPECT_EQ(String::strlen(result), 7);
	EXPECT_EQ(String::strncpy(result, "ferrari", 4), result);
	EXPECT_STREQ(result, "ferr");
    EXPECT_EQ(String::strlen(result), 4);
	EXPECT_EQ(String::strncpy(bisque, "lobster", 200), bisque);
	EXPECT_STREQ(bisque, "lobster");
	EXPECT_EQ(String::strlen(bisque), 7);
}

TEST(StringFunction, strcat) {
    char result[40];
	String::strcpy(result, "atomic");
    EXPECT_EQ(String::strcat(result, "mushroom"), result);
	EXPECT_STREQ(result, "atomicmushroom");
	EXPECT_EQ(String::strlen(result), 14);
}

TEST(StringFunction, strncat) {
    char result1[30];
	char result2[20];
	char result3[10];
	char result4[60];
	strcpy(result1, "pedro");
	strcpy(result2, "ramirez");
	strcpy(result3, "m");
	strcpy(result4, "aybach");
	EXPECT_EQ(String::strlen(result1), 5);
    EXPECT_EQ(String::strncat(result1, result2, 4), result1);
	EXPECT_STREQ(result1, "pedrorami");
	EXPECT_EQ(String::strlen(result1), 9);
	EXPECT_EQ(String::strncat(result3, result4, 6), result3);
	EXPECT_STREQ(result3, "maybach");
}

TEST(StringFunction, strcmp) {
    char result1[20];
	char result2[20];
	char result3[30];
	char result4[4];
	char result5[10];
	String::strcpy(result1, "nathansoriginal");
	String::strcpy(result2, "hotdogs");
	String::strcpy(result3, "tiktok");
	String::strcpy(result4, "A");
	String::strcpy(result5, "B");
	EXPECT_EQ(String::strlen(result1), 15);
	EXPECT_EQ(String::strcmp(result4, result5), -1);
	EXPECT_EQ(String::strcmp(result3, "tiktok"), 0);
	EXPECT_EQ(String::strcmp(result5, result4), 1);
}

TEST(StringFunction, strncmp) {
    char result1[20];
	char result2[20];
	char result3[20];
	char result4[20];
	char result5[23];
	String::strcpy(result1, "hello");
	String::strcpy(result2, result1);
	String::strcpy(result3, "frankenstein");
	String::strcpy(result4, "tacobell");
	String::strcpy(result5, "tacobell");
	EXPECT_EQ(String::strlen(result1), 5);
	EXPECT_EQ(String::strncmp(result4, result5, 3), 0);
	EXPECT_EQ(String::strncmp(result4, result5, 10), 0);
	EXPECT_EQ(String::strncmp(result2, result1, 1), 0);
	EXPECT_EQ(String::strncmp(result4, result2, 3), 12);
}

TEST(StringFunction, reverse_cpy) {
    char result1[20];
	char result2[20];
	char result3[40];
	String::strcpy(result1, "fickle");
	String::strcpy(result2, "strawberries");
	String::reverse_cpy(result3, result2);
	EXPECT_STREQ(result3, "seirrebwarts");
	String::reverse_cpy(result1, result3);
	EXPECT_STREQ(result1, "strawberries");
	String::reverse_cpy(result3, "jim");
	EXPECT_STREQ(result3, "mij");
}

TEST(StringFunction, strchr) {
    char result1[20];
	char result2[20];
	char result3[20];

	String::strcpy(result1, "foxtrot");
	String::strcpy(result2, "tacos");
	String::strcpy(result3, "fingers");
	EXPECT_STREQ(String::strchr(result1, 'o'), "oxtrot");
	EXPECT_STREQ(String::strchr(result2, 's'), "s");
}

TEST(StringFunction, strstr) {
    char result1[20];
	char result2[20];
	char result3[20];
	char result4[20];
	char result5[20];
	String::strcpy(result1, "candiedfruits");
	String::strcpy(result2, "and");
	String::strcpy(result3, "it");
	String::strcpy(result4, "randy");
	String::strcpy(result5, "an");
	EXPECT_STREQ(String::strstr(result1, result2), "andiedfruits");
	EXPECT_STREQ(String::strstr(result4, result5), "andy");
	EXPECT_STREQ(String::strstr(result1, result3), "its");
}