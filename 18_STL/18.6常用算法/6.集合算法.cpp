/**
set_intersection // 求两个容器的交集
set_union // 求两个容器的并集
set_difference  // 求两个容器的差集

set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 

求交集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器中取小值
set_intersection返回值既是交集中最后一个元素的位置

求并集的两个集合必须的有序序列
目标容器开辟空间需要两个容器相加
set_union返回值既是并集中最后一个元素的位置

求差集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器取较大值
set_difference返回值既是差集中最后一个元素的位置
 */
