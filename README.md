# DataSturctue-Basic-and-Algorithm
2020年有新冠肺炎发生，时间集中管理方便自学，刚好想提升一下自己code能力，所以集中突击了一下数据结构和算法。<br>
做了这些年机械，从事软件开发的可能性不大，但是有这个时间还是提升一下自己的计算视角。加上现在学习资源容易获取，弥补基础知识不是什么大问题，并且计算机这个学科非常容易适合自学，一台电脑，一书，一段视频，一段讲解，就可以自己实现实施，形成学习正反馈。有了 基础的夯实，想进阶也就是工程的磨练<br>

自学过程中，课程依据的浙大的Mooc《数据结构和算法》，对于讲到的数据结构我都手撸了一下实现，在PTA做课后练习时，如果是数据结构自身的实现用C来写原型，如果是数据结构应用实例，选择C++实现，整体做下来对我最大的提升在code实现效率提升。解析问题分解问题能力好像进步了不少，解析问题，一般会用到增，查，改逻辑组成一个算法过程，如果你发现这个过程哪一个是效率的关键，就可以抽象出用对应数据结构解决。<br>

虽然就个体而言是一种提升，对专业来说还是入门，但是总结出来，也是当前的结束，下一个开始。

# DataStructure

- linear structure->
[list](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/commit/68d4d006350dd1f2c2dedac496bd91b5b6e42e8f)<br>
<>数组实现，数组有位置索引，查找效率高O(1)，插入和删除效率低O(n)<br>
<>链表实现， 链表没有位置索引查找效率低O(n)，插入和删除效率高O(1)，但是删除前要先找到所以效率还是O(1)
- merge two sorted list->[merger list](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/f2_megerlist.c)
- reverse list->
[reverse list](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/reverseLinkedList.c)
- find reverse Kth list->[findRevKthList](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/findListRevKth.c)<br>
<>这几个练习都是采用双指针策略实现<br>

- linear structure<array list>
  [array list](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/arraylist.h)
  
- Stack->[stack](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/stack.h)<br>
  <>堆栈实际应用中有着广泛的应用，浏览器历史的后退，浏览器，文件路径浏览，还有一些编程过程减轻思考压力，标记符对应，深搜非递归模拟系统栈<br>
  栈，查找，删除，插入均为O(1)，作为有序操作过程，只能对一端操作<br>
  valid parentthese->
  [valid parentthese](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/validParentheses.cpp)<br>
  
- Queue->[queue]
  <>队列作为一种先进先出数据结构，在工程中有着广泛使用，就像生活中的排队一样，打印进机任务管理，商家提供计时收费服务，都可以依赖队列模拟<br>
  队列在查找，删除，插入均为O(1)，作为有序操作过程，可以对两端进行操作，构造队列基于线性结构均可实现<br>
  queue->
  [Queue](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/queue.c)<br>
#### 前面几种都是线性结构，无论是连续物理空间还是非连续物理空间，从原型抽象角度，使用时都是线性。实际使用中还有很多是线性结构不足以描述的联系，比如计算机文件系统，提供计件收费的系统，时时把时间消耗最短的任务优先完成，生活中人与人相互联系系统。这些都是非线性，这里就引入了树，堆，图结构

- BSTree->[Tree](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/tree.c)<br>
  <>二叉搜索树作为一种数据结构，每一个节点左子树都小于节点，右子树都大于节点，而每一个节点也都是二叉搜索树，所以这种树查询时每次都可以过滤掉一半数据，这样就带啦了极大查找效率lg(n)，插入和删除都是类似链表操作O(1)
  Tree level review->[tree level review](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p7_treeLevelReview.c)<br>
  Tree bsttreemorphism[树的同构][bsttreemorphism](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p9_bsttreemorphism.c)<br>
  <>二叉树查询效率高，需要保持两边平衡，如果单边树就退化为链表，因此在工程中有了平衡二叉树和B+树对基础二叉树做补充<br>
- AVLTree->[AVLTree](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/AVLTree/avltree.c)<br>

- Heap->[Heap](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/tree/master/Heap)<br>
  <>堆作为一种完全二叉树，有着特定的使用范畴。如果队列、栈作为顺序操作满足静态序列要求，堆就是动态序列要求。比如操作系统的任务调度，让计算机始终满负载运行，始终提取可计算任务放在堆顶；进行序列调整是进行堆排
- HuffmanCode->[HuffmanCode](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p14_HuffmanCode.c)<br>

-<Graph>->
  <>现实中关系网最普遍的代表抽象模型是图，她可以描述生活中联系网络，树可以看做图的退化
- 连通集->[connect set](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p15_listconnectgraph.cpp)<br>
- 六度空间->[six degree](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/sixdegree.cpp)<br>

# Algorithm
  算法从整体策略来说分为，分而治之，归并，贪心和动态规划。一般一个问题的直接处理方式暴力求解贪心，如果暴力效率低，可以寻求减少问题规模，这就是分而治之和归并。如果发现分拆过程子问题和原问题是同一类，采用递归求解，而递归树有重复求解，采用动划减少求解规模。
  在规划算法的时候，增、删、改过程的瓶颈点，会促使采用合适的数据结构应对
 - qsort->[qsort](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p24_qsort.c)<br>
 - megersort->[mergerSort](https://github.com/zjb1001/DataSturctue-Basic-and-Algorithm-/blob/master/p25_megersort.c)<br>
 
