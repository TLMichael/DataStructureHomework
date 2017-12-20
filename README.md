# <p align = "center">DataStructure Homework </p>
### <p align = "center">数据结构上机实验题目-2017 v2  NUAA </p>

## <p align = "center">D第一阶段（线性部分）</p>
### 《数据结构》第1上机题 （线性表练习）
- 1．编程实现书P19  ADT List 基本操作12个：
（1）用顺序存储结构实现； （2）用链式存储结构实现；
- 2．编程，建立元素值为整型的顺序表，并实现就地逆置（习题集P18  2.21 ）。
- 3．编程，建立元素值为整型的单链表，并实现就地逆置（习题集P18  2.22 ）。
- 4．约瑟夫问题。输入n，s，m，设有n个人做作圆桌周围，从第s个人开始报数，报到m的人出列，然后再从下一个人开始报数，数到m的人又出列，如此重复，直到所有的人都出列为止。要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。(选做题)

### 《数据结构》第2上机题 （线性表练习）
- 1．建立元素值为整型的顺序表，编程，用插入排序算法实现顺序表排序。
- 2．建立元素值为整型的单链表，编程，用插入排序算法实现单链表排序。	
- 3．用顺序结构编程实现下列功能：假设以两个元素值为整型依值递增有序排列的线性表A和B 分别表示两个集合，现要求在A的空间上构成一个新线性表C，其元素为A和B元素的并集，且表C中的元素也是依值递增有序排列。
- 4．用单链表结构编程实现下列功能：假设以两个元素值为整型依值递增有序排列的线性表A和B 分别表示两个集合，现要求在A的空间上构成一个新线性表C，其元素为A和B元素的并集，且表C中的元素也是依值递增有序排列。
- 5．CSP题目
问题描述：首先输入正整数n，接着输入n个正整数，如果其中存在一个数，比该数大的个数等于比该数小的个数，则输出该数，如果不存在则输出-1。
问题分析：这个问题可以用排序来实现。
    ``` 
    样例输入：
    6
    9 7 2 5 7 8
    样例输出
    7
    样例输入：
    5
    9 5 2 5 7
    样例输出
    1 
    ```
### 《数据结构》 第3次上机题（线性表复习，栈与队列练习）
- 1．编程实现书P45   ADT Stack 基本操作9个，用顺序存储结构实现；
- 2．编程实现书P59   ADT Queue 基本操作9个，用链式存储结构实现；
- 3．设某传感器，每秒不间断采集数据（整数0-1000），要求任何时刻只保留最后N个数据（初始值为0），并输出当前最大值，设N=10，试利用循环队列编写算法。
- 4．CSP题目
    - 问题描述
    - 　　在某图形操作系统中,有 N 个窗口,每个窗口都是一个两边与坐标轴分别平行的矩形区域。窗口的边界上的点也属于该窗口。窗口之间有层次的区别,在多于一个窗口重叠的区域里,只会显示位于顶层的窗口里的内容。
    - 　　当你点击屏幕上一个点的时候,你就选择了处于被点击位置的最顶层窗口,并且这个窗口就会被移到所有窗口的最顶层,而剩余的窗口的层次顺序不变。如果你点击的位置不属于任何窗口,则系统会忽略你这次点击。
    - 　　现在我们希望你写一个程序模拟点击窗口的过程。
    - 输入格式
    - 输入的第一行有两个正整数,即 N 和 M。(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
    - 　　接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 每行包含四个非负整数 x1, y1, x2, y2,表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。保证 x1 < x2, y1 < y2。
    - 　　接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
    - 　　题目中涉及到的所有点和矩形的顶点的 x, y 坐标分别不超过 2559 和　　1439。
    - 问题分析：这个问题可以用链式线性表来实现。
    - 输出格式
    - 　　输出包括 M 行,每一行表示一次鼠标点击的结果。如果该次鼠标点击选择了一个窗口,则输出这个窗口的编号(窗口按照输入中的顺序从 1 编号到 N);如果没有,则输出"IGNORED"(不含双引号)。
    ```
    样例输入
    3 4
    0 0 4 4
    1 1 5 5
    2 2 6 6
    1 1
    0 0
    4 4
    0 5
    样例输出
    2
    1
    1
    IGNORED
    样例说明
    　　第一次点击的位置同时属于第 1 和第 2 个窗口,但是由于第 2 个窗口在上面,它被选择并且被置于顶层。
    　　第二次点击的位置只属于第 1 个窗口,因此该次点击选择了此窗口并将其置于顶层。现在的三个窗口的层次关系与初始状态恰好相反了。
    　　第三次点击的位置同时属于三个窗口的范围,但是由于现在第 1 个窗口处于顶层,它被选择。
    　　最后点击的 (0, 5) 不属于任何窗口。
      ```

### 《数据结构》 第4次上机题（线性结构练习）
- 1．输入稀疏矩阵，建立稀疏矩阵三元组顺序结构，实现转置（1、2）；
- 2. CSP题目
    - 问题描述：请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
    - 　　假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有的座位编号，第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100号。
    - 　　购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
    - 　　假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。
输入格式
    - 　　输入的第一行包含一个整数n，表示购票指令的数量。
    - 　　第二行包含n个整数，每个整数p在1到5之间，表示要购入的票数，相邻的两个数之间使用一个空格分隔。
    - 输出格式
    - 输出n行，每行对应一条指令的处理结果。
    - 　　对于购票指令p，输出p张车票的编号，按从小到大排序。
    - 问题分析：这个问题可以用顺序结构或链式结构实现。
    - 样例输入
    - 4
    - 2 5 4 2
    - 样例输出
    - 1 2
    - 6 7 8 9 10
    - 11 12 13 14
    - 3 4
- 3. 利用栈操作实现八皇后问题求解 (选做题) 。


## <p align = "center">第二阶段（树与图部分）</p>	
### 《数据结构》 第5次上机题目  (二叉树练习 )
- 1. 编程实现书P121  ADT BinaryTree 基本操作20个，用二叉链表结构实现；
- 2. 二叉树的先序、中序、后序遍历非递归方法，层次遍历。
- 3. 编程实现，对二叉树中每个元素值为x的结点，删除以它为根的子树，并释放相应空间。
- 4．编程实现，判断给定二叉树是否是完全二叉树。

### 《数据结构》 第6次上机题目  ( 二叉树、树、图 练习 )
- 1．编程实现书P156  ADT Graph 基本操作13个，用邻接矩阵存储结构实现；
- 2. 输入N个权值（1-100正整数），建立哈夫曼树。
- 3. 编程实现，建立一棵以孩子-兄弟链表表示的树。
- 4. 编程实现，对一棵以孩子-兄弟链表表示的树，分别输出每一层的结点。

### 《数据结构》 第7次上机题目  ( 图 练习 )
- 1. 图的深度优先和广度优先遍历；
- 2．CSP题目
    - 问题描述：小刘承包了很多片麦田，为了灌溉这些麦田，小刘在第一个麦田挖了一口很深的水井，所有的麦田都从这口井来引水灌溉。 为了灌溉，小刘需要建立一些水渠，以连接水井和麦田，小刘也可以利用部分麦田作为“中转站”，利用水渠连接不同的麦田，这样只要一片麦田能被灌溉，则与其连接的麦田也能被灌溉。现在小刘知道哪些麦田之间可以建设水渠和建设每个水渠所需要的费用（注意不是所有麦田之间都可以建立水渠）。请问灌溉所有麦田最少需要多少费用来修建水渠。  
输入格式：输入的第一行包含两个正整数n, m，分别表示麦田的片数和小刘可以建立的水渠的数量。麦田使用1, 2, 3, ……依次标号。    接下来m行，每行包含三个整数ai, bi, ci，表示第ai片麦田与第bi片麦田之间可以建立一条水渠，所需要的费用为ci。
    - 输出格式：输出一个整数，表示灌溉所有麦田所需要的最小费用，及水渠连接说明。 
    - 问题分析：这个问题可以用最小生成树算法实现。
    - 输入样例:
    <pre><code> 2222 
    ddd
    ddd</code></pre>
    - 4 4
    - 1 2 1 
    - 2 3 4
    - 2 4 2
    - 3 4 3  
    - 输出样例:
    - 6  
    - 建立以下3条水渠：麦田1与麦田2、麦田2与麦田4、麦田4与麦田3。  
-3．编写拓扑排序算法；
-4. 关键路径练习(选做题)；
第二阶段总结

## <p align = "center">第三阶段（查找与排序部分）</p>
##《数据结构》 第8次上机题目  ( 查找 排序 练习 )
-1. 哈希表设计 ( 习题集 P166  6.2,用二次探测再散列处理冲突 )；
-2．实现交换、选择、归并等简单排序算法；
-3．实现快速排序算法；
-4．实现堆排序算法；
-5. 设二叉排序树T，元素值为整数，输入整数X，若存在输出该结点，若不存在，输出最接近X值的两个结点（有可能一个）。 (选做题)
-6．实现基数排序算法 (选做题)。	
第三阶段总结
