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
    bool test4_constructor1_Circle() {
        Circle<int> test_object = Circle<int>();
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 0 || test_object.getY() != 0 || test_object.getRadius() != 0) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test4_constructor2_Circle() {
        Circle<int> test_object = Circle<int>(4, 5, 3);
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 4 || test_object.getY() != 5 || test_object.getRadius() != 3) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test4_constructor3_Circle() {
        Point<int> center(2, 3);
        Circle<int> test_object = Circle<int>(center, 5);
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 2 || test_object.getY() != 3 || test_object.getRadius() != 5) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test4_constructor4_Circle() {
        Circle<int> test_object1 = Circle<int>(1, 2, 3);
        Circle<int> test_object2 = Circle<int>(test_object1);
        bool expected_result = true, actual_result = true;
        if (test_object2.getX() != 1 || test_object2.getY() != 2 || test_object2.getRadius() != 3) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }


    bool test4_is_intersects_Circle() {
        Circle<int> circle1(0, 0, 5);
        Circle<int> circle2(5, 0, 3);
        Circle<int> circle3(8, 0, 3);
        Circle<int> circle4(15, 0, 2);
        bool expected_result = true, actual_result = true;

        if (circle1.is_intersects(circle2) != in_it || circle1.is_intersects(circle3) != touches || circle1.is_intersects(circle4) != no_touch) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }


    // Тесты для Sphere
    bool test5_constructor1_Sphere() {
        Sphere<int> test_object = Sphere<int>();
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 0 || test_object.getY() != 0 || test_object.getZ() != 0 || test_object.getRadius() != 0) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test5_constructor2_Sphere() {
        Sphere<int> test_object = Sphere<int>(1, 2, 3, 4);
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 1 || test_object.getY() != 2 || test_object.getZ() != 3 || test_object.getRadius() != 4) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test5_constructor3_Sphere() {
        Point3D<int> center(5, 6, 7);
        Sphere<int> test_object = Sphere<int>(center, 8);
        bool expected_result = true, actual_result = true;
        if (test_object.getX() != 5 || test_object.getY() != 6 || test_object.getZ() != 7 || test_object.getRadius() != 8) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test5_constructor4_Sphere() {
        Sphere<int> test_object1 = Sphere<int>(10, 11, 12, 13);
        Sphere<int> test_object2 = Sphere<int>(test_object1);
        bool expected_result = true, actual_result = true;
        if (test_object2.getX() != 10 || test_object2.getY() != 11 || test_object2.getZ() != 12 || test_object2.getRadius() != 13) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
    }

    bool test5_is_intersects_Sphere() {
        Sphere<int> sphere1(0, 0, 0, 5);
        Sphere<int> sphere2(4, 0, 0, 2);  // Пересекаются
        Sphere<int> sphere3(7, 0, 0, 2);  // Касаются
        Sphere<int> sphere4(15, 0, 0, 2); // Не касаются
        bool expected_result = true, actual_result = true;

        if (sphere1.is_intersects(sphere2) != in_it || sphere1.is_intersects(sphere3) != touches || sphere1.is_intersects(sphere4) != no_touch) {
            actual_result = false;
        }
        return result(expected_result, actual_result);
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
    // Тесты для Circle
    printf("test4_constructor1_Circle"); test::print_result(test::test4_constructor1_Circle());
    printf("test4_constructor2_Circle"); test::print_result(test::test4_constructor2_Circle());
    printf("test4_constructor3_Circle"); test::print_result(test::test4_constructor3_Circle());
    printf("test4_constructor4_Circle"); test::print_result(test::test4_constructor4_Circle());
    printf("test4_is_intersects_Circle"); test::print_result(test::test4_is_intersects_Circle());
    printf("\n");

    // Тесты для Sphere
    printf("test5_constructor1_Sphere"); test::print_result(test::test5_constructor1_Sphere());
    printf("test5_constructor2_Sphere"); test::print_result(test::test5_constructor2_Sphere());
    printf("test5_constructor3_Sphere"); test::print_result(test::test5_constructor3_Sphere());
    printf("test5_constructor4_Sphere"); test::print_result(test::test5_constructor4_Sphere());
    printf("test5_is_intersects_Sphere"); test::print_result(test::test5_is_intersects_Sphere());
}