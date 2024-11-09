@echo off
if not exist build (
	mkdir build
)

pushd build

clang -g -fuse-ld=lld -o bracket_c.exe ../main.c -lUser32

popd
