build:
	cmake --build .build

format:
	clang-format -i Chapter02/*.cpp Chapter02/*.h
