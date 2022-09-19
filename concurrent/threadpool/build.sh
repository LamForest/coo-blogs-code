g++ -std=c++11 test.cpp -o test
if [ $? -ne 0 ]
then
    echo "Compile with error"
    exit 2
else
    echo "Compile succeeded without error"
fi
./test