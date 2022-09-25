# g++ -std=c++11 return.cpp -o return
clang++ -std=c++20 -stdlib=libc++ -fcoroutines-ts $1.cpp -o $1
if [ $? -ne 0 ]
then
    echo "Compile with error"
    exit 2
else
    echo "Compile succeeded without error"
fi
./$1