g++ -std=c++11 pc.cpp -o pc
if [ $? -ne 0 ]
then
    echo "Compile succeeded, but with warnings"
    exit 2
else
    echo "Compile succeeded without warnings"
fi
./pc