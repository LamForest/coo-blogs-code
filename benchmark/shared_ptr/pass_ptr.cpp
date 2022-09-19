// void rp(Cat *p){
// bm::DoNotOptimize(p);
//     // p->doSth();
// }
// void rp(std::shared_ptr<Cat> p){
//     // p->doSth();
//      bm::DoNotOptimize(p);
// }

// void rp_ref(const std::shared_ptr<Cat>& p){
//     // p->doSth();
//      bm::DoNotOptimize(p);
// }

// void rp(std::unique_ptr<Cat> p){
//     // p->doSth();
//      bm::DoNotOptimize(p);
// }


class Cat
{
    // std::string name;
    // double weight;
    // int age;
    int a[1000];

public:
    void doSth()
    {
        age = 1;
    }
};