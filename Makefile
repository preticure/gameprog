DIRS = Chapter01/ Chapter02/

BUILD_DIR = .build

build:
	cmake --build ${BUILD_DIR}


format:
	@echo "Formatting...⊂( ᴖ ̫ᴖ )⊃"
	@find ${DIRS} \
	    \( -name "*.cpp" -o -name "*.hpp" -o -name "*.c" -o -name "*.h" \) \
	    -print \
	    | tee /dev/stderr \
	    | xargs clang-format -i
