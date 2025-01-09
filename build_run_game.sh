rm -r build
mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=/home/roracema/Documents/projects/catch-the-target/vcpkg/scripts/buildsystems/vcpkg.cmake ..
cmake --build .
./CatchTheTarget