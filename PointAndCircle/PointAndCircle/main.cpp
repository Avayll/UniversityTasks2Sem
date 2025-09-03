#include <stdio.h>

#include "Point.h"
#include "CircleAndSphere.h"

namespace test {
	bool result(bool expected_result, bool actual_result) {
		if (expected_result == actual_result) {
			return true;
		}
		else if (expected_result != actual_result){
			return false;
		}
	}
	void print_result(bool result) {
		if (result) {
			printf(" is completed the test\n");
		}
		else {
			printf(" is failed the test\n");
		}
	}

	bool test1_constructor1_Point() {
		Point<int> test_object = Point<int>();
		bool expected_resut = true, actual_result = true;
		if (test_object.getX() != 0 || test_object.getY() != 0) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test1_constructor2_Point() {
		Point<int> test_object = Point<int>(4, 5);
		bool expected_resut = true, actual_result = true;
		if (test_object.getX() != 4 || test_object.getY() != 5) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test1_constructor3_Point() {
		Point<float> test_object = Point<float>(4.5, 2.7);
		bool expected_resut = true, actual_result = true;
		if (test_object.getX() != 4.5 || test_object.getY() != 2.7) { // почему то на У идёт различие на 0.0000000005, но в целом правильно
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test1_constructor4_Point() {
		Point<int> test_object1 = Point<int>(4, 5);
		Point<int> test_object2 = Point<int>(test_object1);
		bool expected_resut = true, actual_result = true;
		if (test_object2.getX() != 4 || test_object2.getY() != 5) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test2_get_distance_Point() {
		Point<int> test_object1 = Point<int>();
		Point<int> test_object2 = Point<int>(1, 0);
		bool expected_resut = true, actual_result = true;
		if (test_object1.get_distance(test_object2) != 1) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test3_constructor1_Point3D() {
		Point3D<int> test_object = Point3D<int>();
		bool expected_resut = true, actual_result = true;
		if (test_object.getX() != 0 || test_object.getY() != 0 || test_object.getZ() != 0) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test3_constructor2_Point3D() {
		Point3D<int> test_object = Point3D<int>(1, 2, 3);
		bool expected_resut = true, actual_result = true;
		if (test_object.getX() != 1 || test_object.getY() != 2 || test_object.getZ() != 3) {
			//std::cout << (test_object.getX());
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
	bool test3_constructor3_Point3D() {
		Point3D<int> test_object1 = Point3D<int>(3, 4, 5);
		Point3D<int> test_object2 = Point3D<int>(test_object1);
		bool expected_resut = true, actual_result = true;
		if (test_object2.getX() != 3 || test_object2.getY() != 4 || test_object2.getZ() != 5) {
			actual_result = false;
		}
		return result(expected_resut, actual_result);
	}
}

int main() {
	printf("test1_constructor1_Point"); test::print_result(test::test1_constructor1_Point());
	printf("test1_constructor2_Point"); test::print_result(test::test1_constructor2_Point());
	printf("test1_constructor3_Point"); test::print_result(test::test1_constructor3_Point());
	printf("test1_constructor4_Point"); test::print_result(test::test1_constructor4_Point());
	printf("test2_get_distance_Point"); test::print_result(test::test2_get_distance_Point());
	printf("\n");
	printf("test3_constructor1_Point3D"); test::print_result(test::test3_constructor1_Point3D());
	printf("test3_constructor2_Point3D"); test::print_result(test::test3_constructor2_Point3D());
	printf("test3_constructor3_Point3D"); test::print_result(test::test3_constructor3_Point3D());
}