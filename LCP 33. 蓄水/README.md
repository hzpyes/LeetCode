首先显然应该把所有 升级水桶 的操作放在 蓄水 之前，这样每次蓄水时的增益是最大的。

那么假设已经升级完毕，若当前已知最终需要「蓄水」次数为 k，则对于第 i 个水缸配备的水桶在「蓄水」操作前的容量 m_{i} 至少应该达到m_{i} = vat[i] / k(向上取整)。

此时对于第 i 个水桶需要的「升级水桶」操作次数为max(0, m_{i} - bucket[i]).

那么我们枚举「蓄水」操作次数的 k 即可。k操作次数一定不会大于全部水缸的最低蓄水量。并且当 k 大于等于当前已经得到的最少操作总次数时，可以提前结束枚举。

#### 向上取整技巧
 m/n的向上取整 = m + n - 1 / n的向下取整

#### *max_element函数找最大元素
```
	int n[]={1,4,22,3,8,5};
	int len=sizeof(n)/sizeof(int);
	cout<<*max_element(n,n+len)<<endl;
	cout<<*min_element(n,n+len)<<endl;
```
```
	int n[]={1,4,2,3,5,0};
	vector<int>v(n,n+sizeof(n)/sizeof(int)); // sizeof(n)/sizeof(int)是求数组n的长度
	cout<<*min_element(v.begin(),v.end())<<endl; // 最小元素
	cout<<*max_element(v.begin(),v.end())<<endl; // 最大元素
```


