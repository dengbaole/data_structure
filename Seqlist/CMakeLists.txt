cmake_minimum_required(VERSION 3.0)

project(my_cmake_exe)

include_directories(${CMAKE_SOURCE_DIR}/INC)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb") #这个照着复制就行
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(./SRC DIR_SRCS)
# # 指定生成目标
add_executable(my_cmake_exe ${DIR_SRCS})
# add_executable(${PROJECT_NAME}   SRC/main.c SRC/delay.c)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_compile_options(-g)   #添加语句


