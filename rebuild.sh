# 如果没有build文件夹, 新建一个
if [ ! -d "build" ]; then
    mkdir build
fi

echo "============================================================="
cppcheck --enable=style,unusedFunction --force ./code
echo "============================================================="


cd build && cmake .. && make -j6

../stc8prog/./stc8prog  -p /dev/ttyUSB0 -e -f demo.hex

cd ..
