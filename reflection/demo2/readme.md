顺序问题：  
https://www.cnblogs.com/zhanggaofeng/p/9255668.html

动态库依赖动态库的问题:  
https://blog.csdn.net/kl1125290220/article/details/103081969

--no-copy-dt-needed-entries 
从binutils 2.22版本以后，如果你在程序中使用了你依赖的动态库所依赖的动态库中的函数时，你就必须显式的指定你依赖的动态库所依赖的动态库。

