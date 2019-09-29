/** 分块查找又称为索引顺序查找。
分块查找又称为索引顺序查找。
1.首先将列表分成若干个块（子表）(列表相邻的元素组成一个块,比如列表data分为以下三个块data[0~a], data[a+1~b], data[b+1~n])。
    一般情况下，块的长度均匀，最后一块可以不满。
    每块中元素不必有序，即块内无序，但块与块之间有序（即下一个块中最小的元素必大于上一个块中所有的元素）。

2.然后构造一个索引表。其中每个索引项对应一个块，且每个索引项记录每块的起始位置，和每块中关键字(或最小关键字)。
    索引表按关键字有序排列。（这里关键字就是列表中每个元素的值）


分块查找的基本过程如下：

（1）首先，将待查关键字 K 与索引表中的关键字进行比较，以确定待查记录所在的块。
        具体的可用顺序查找法或折半查找法进行。

（2）进一步用顺序查找法，在相应块内查找关键字为 K的元素。
*/
