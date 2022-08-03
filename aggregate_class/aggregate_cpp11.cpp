#include <string>

struct Config
{
    bool enable;
    std::string name;
};

class NotAggregate1
{ //不是聚合类，has private data member;
    bool enable;
    std::string name;
};

class IsAggregate1
{ //聚合类，只有默认构造函数
public:
    IsAggregate1() = default;
    bool enable;
    std::string name;
};

class IsAggregate2
{ //聚合类，可以有非聚合类数据成员
public:
    bool enable;
    std::string name;
    NotAggregate1 na;
};

struct IsAggregate3
{ //聚合类
    bool enable;
    std::string name;

private: //可以有私有函数，私有静态数据成员，只要不是non-static data member即可。
    std::string getName()
    {
        return name;
    }
};

int main()
{
    Config config{true, ""};
    IsAggregate3 a3{true, ""};
    return 0;
}