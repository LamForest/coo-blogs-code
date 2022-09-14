g++ -std=c++11 pool.cpp -o pool
if [ $? -ne 0 ]
then
    echo "Compile with error"
    exit 2
else
    echo "Compile succeeded without error"
fi
./pool