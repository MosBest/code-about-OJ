//����
/*
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Show Hint 

 
*/
 
//˼·���Ӻ���ǰ����������ʣ��4���������ǶԷ� ��ȡ����ô�������ǳ�ȡ1������2������3��
//�����һ���ܹ�ȫ����ȡ������ͬ������ǰ4�����Է��ȳ�ȡ����ôǰ4�������һ���ҳ�ȡ�꣬Ȼ�����ֵ�ʣ�µ�4�����������ȳ�ȡ
//����Ҫ�����ǵ�һ���ȳ�ȡ����ô��4ǰ�����1������2������3�������ǿ���ʹ�öԷ���4�����濪ʼ �� 

//�����Ĵ��� 
/*
Line 5: control reaches end of non-void function [-Werror=return-type] 
Ҫ�����з�����䣬��������ĳ�������û�С����������if���������return��
���� if�����û�У������˴��� ����ˣ���Ҫ������if��������return��䡣 
*/ 

//����һ
bool canWinNim(int n) {
    int a=n%4;
    if(a==1||a==2||a==3)
        return true;
    return false;
}

//������ 
bool canWinNim(int n) {

    return n%4;
        
}
