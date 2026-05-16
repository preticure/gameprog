DIRS = Chapter01/ Chapter02/

BUILD_DIR = .build

FACES := "⊂( ᴖ ̫ᴖ )⊃" "…三(卍 ˘ω˘))卍" "(∩^o^)⊃━☆ﾟ.*･｡" "(๑╹ᆺ╹)" "(▰╹◡╹▰)" "[ ˘꒳˘ ]" "⊂( ᴖ ̫ᴖ)⊃" "⸝⸝◜~◝⸝⸝" "ʕ´•ᴥ•\`ʔ" "( ｰ̀֊ｰ́ )੭" "´◕ ◡ ◕｀"

BUILD_MSGS := "Building..." "BUILD START " "build!" "び〜るどっ" "いえーい" "しーめいくﾊｲﾌﾝﾊｲﾌﾝびるど〜" "ビルドするにょれ" "やるわよ"
FORMAT_MSGS := "Formatting..." "FORMAT TIME " "Let'\''s format!" "ふぉーまっと すたーと〜" "ふぉーまっと〜" "ふぉーまっとするにょれ" "いくぞ〜"
NOFILES_MSGS := "、、、って、なんも変更してないやんか" "いや0ジャーン" "差分ないので〜"

build:
	@bash -c \
	'faces=($(FACES)); \
	msgs=($(BUILD_MSGS)); \
	echo -e "$${msgs[$$((RANDOM % $${#msgs[@]}))]} $${faces[$$((RANDOM % $${#faces[@]}))]}\n"'
	@cmake --build ${BUILD_DIR}

format:
	@bash -c \
	'faces=($(FACES)); \
	msgs=($(FORMAT_MSGS)); \
	echo -e "$${msgs[$$((RANDOM % $${#msgs[@]}))]} $${faces[$$((RANDOM % $${#faces[@]}))]}\n"'
	@files=$$({ git diff --name-only HEAD -- $(DIRS); \
	   git ls-files --others --exclude-standard -- $(DIRS); } \
	    | grep -E '\.(cpp|hpp|c|h)$$' \
	    | sort -u); \
	if [ -z "$$files" ]; then \
		bash -c \
		'empty_msgs=($(NOFILES_MSGS)); \
	    echo -e "\n\n\n$${empty_msgs[$$((RANDOM % $${#empty_msgs[@]}))]}"'; \
	else \
	    echo "$$files" | tee /dev/stderr | xargs clang-format -i; \
	fi

format-all:
	@bash -c \
	'faces=($(FACES)); \
	msgs=($(FORMAT_MSGS)); \
	echo -e "$${msgs[$$((RANDOM % $${#msgs[@]}))]} $${faces[$$((RANDOM % $${#faces[@]}))]}\n"'
	@find ${DIRS} \
	    \( -name "*.cpp" -o -name "*.hpp" -o -name "*.c" -o -name "*.h" \) \
	    -print \
	    | tee /dev/stderr \
	    | xargs clang-format -i
