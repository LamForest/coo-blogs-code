## restrict的作用
https://zhuanlan.zhihu.com/p/349726808

实测发现 restrict是否有优化和具体的编译器及环境有关

本机Mac OS 下  clang++（版本：clang-1316.0.21.2.5）开O3优化，通过反汇编发现并没有借助restrict优化

不过在[godbolt](https://godbolt.org/z/ea3oov3qP)上测试，x86-64、armv7、armv8下都是优化的