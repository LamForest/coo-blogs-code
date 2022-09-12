g++ -std=c++11 pc.cpp -o pc
if [ $? -ne 0 ]
then
    echo "Compile with error"
    exit 2
else
    echo "Compile succeeded without error"
fi
./pc > 1.log

total=`cat 1.log | wc -l` 
useless=`cat 1.log | grep -E "\-1" | wc -l`
ratio=`echo "scale=8;$useless / $total" | bc`
printf "useless ratio = %.8f\n" $ratio
rm 1.log