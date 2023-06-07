奶酪会被全部吃完，只是求：只给第一只老鼠吃k块的情况下（剩下的都给第二只吃），最大值是多少！

要注意的是，同一块，给了第一只老鼠吃，就不能给第二只老鼠吃了。

#### 做法：贪心+排序
1. 先让第二只吃完所有的奶酪
2. 让第二只吐出k块奶酪给第一只 （关键在于吐出哪儿k块能使得总和最大）
   a.  吐出第i块奶酪时，得分的变化为res - reward2[i] + reward1[i]
      1. 整理一下就是 res + (reward1[i] - reward2[i])
   b.  那么我让(reward2[i] - reward1[i])这个值最大的k块奶酪给第一只老鼠吃即可。


#### accumulate()介绍

```
#include <numeric> // 需要的头文件

accumulate(起始迭代器, 结束迭代器, 初始值, 自定义操作函数); // 第四个参数非必须
```

```
// 计算数组中所有元素的乘积
int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(arr.begin(), arr.end(), 1, multiplies<int>()); // 初值1 * (1 * 2 * 3 * 4 *... * 10)
    cout << sum << endl;	// 输出3628800
    return 0;
}

// 计算数组中每个元素乘以3之后的和
int fun(int acc, int num) {
    return acc + num * 3;     // 计算数组中每个元素乘以3
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(arr.begin(), arr.end(), 0, fun);
    cout << sum << endl;	// 输出 165
    return 0;
}

// 拼接字符串
int main() {
    vector<string> words{"this ", "is ", "a ", "sentence!"};
    string init, res;
    res = accumulate(words.begin(), words.end(), init);    // 连接字符串
    cout << res << endl;    // this is a sentence!
    return 0;
}
```