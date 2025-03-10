if [ ! -d "build" ]; then
    mkdir build
fi

pushd build

clang -g -o bracket_c ../main.c

popd
