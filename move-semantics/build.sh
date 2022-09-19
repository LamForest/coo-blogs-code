# g++ -std=c++11 return.cpp -o return
g++ -std=c++11 return0.cpp -o return
if [ $? -ne 0 ]
then
    echo "Compile with error"
    exit 2
else
    echo "Compile succeeded without error"
fi
./return