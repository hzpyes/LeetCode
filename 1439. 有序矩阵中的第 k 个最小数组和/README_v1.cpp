本题的k最大才取到200，那么暴力法应该可以通过。

思路就是维护一个长为k的数组(模拟堆)，存放最小的k个结果。

    通过对前两个数组合并，双层循环两个数组中各取一个值每进行相加，结果存放到一个数组中并排序，返回前面长度为k的子数组即为当前两个数组的最小k种情况。