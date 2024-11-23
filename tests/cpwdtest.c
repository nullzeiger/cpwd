#include "tests.h"

int main(void)
{
	ASSERT_TEST("create new password", new_password_test());
	ASSERT_TEST("all password", all_password_test());
	ASSERT_TEST("search password", search_password_test());
	ASSERT_TEST("delete password", delete_password_test());

	if (remove_password_test_file() == 0) {
		puts("File for test removed");
	}
	else {
		puts("Error removed test file");
	}

	return 0;
}
