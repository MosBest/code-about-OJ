//问题
/*
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Show Hint 

 
*/
 
//思路：从后向前看，如果最后剩下4个，且再是对方 抽取，那么无论他是抽取1，还是2，还是3，
//最后我一定能够全部抽取过来。同理，再往前4个，对方先抽取，那么前4个的最后一定我抽取完，然后又轮到剩下的4个，又是他先抽取
//可是要求我是第一个先抽取，那么在4前面加上1个或者2个或者3个，都是可以使得对方在4个里面开始 。 

//遇到的错误 
/*
Line 5: control reaches end of non-void function [-Werror=return-type] 
要求函数有返回语句，但是你在某种情况下没有。这里，我是在if语句里面有return，
但是 if语句外没有，导致了错误 。因此，不要忘记在if语句外加上return语句。 
*/ 

//方案一
bool canWinNim(int n) {
    int a=n%4;
    if(a==1||a==2||a==3)
        return true;
    return false;
}

//方案二 
bool canWinNim(int n) {

    return n%4;
        
}
