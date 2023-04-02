#include<stdlib.h>
#include<conio.h>
//map地图 score分数 game为0时游戏结束 c输入缓存 i循环变量 j是否有空地 k移动是否有效
int map[16] = { 0 }, score = 0, game = 1, c, i, j, k;
const char* wall[4] = { "\n----- ----- ----- -----\n","|","|" ,"|" };//wall墙
/*move()移动 o为要移动的格子 v为移动值 
①判断位置是否上下越界，是否为空地，是则直接返回
②判断左右是否越界，看新旧位置是否在同一行，不在就是越界
③判断新位置是否和本身的值相同，相同就合并，新位置值*2，本身清0，以及增加分数。为防止一个数反复合并，所以后面合并后为负数，后面再取反
④判断新位置是否为空地，是空地还要继续移动，递归调用自己。只有产生移动k才为0，否则没有移动还会继续生成*/
void move(int i, int v) {
	if (i + v < 0 || 15 < i + v || !map[i])
		return;
	if ((v == 1 || v == -1) && i / 4 - (i + v) / 4)
		return;
	if (map[i + v] == map[i])
		map[i + v] *= -2, score += map[i], map[i] = k = 0;
	if (!map[i + v])
		map[i + v] = map[i], map[i] = k = 0, move(i + v, v);
}
//按照一定顺序进行移动 begin迭代 end结束值 i迭代方向 v移动值
void order(int end, int i, int v) {
	for (int begin = end == 16 ? 0 : 15; begin - end; begin += i)move(begin, v);
}
int main() {
	system("mode con:cols=25 lines=9");//设置窗口大小 高为9宽为25
	/*申请随机种子 game为0游戏结束
	①②判断输入，根据输入来移动
	③负数取反，同时判断是否有空地，跟前面取负数相对应。生成一个新数字，先取一个随机值
	④如果没有空地或者没有产生移动，直接跳出不生成。如果是空地则生成新数字，80%是2，20%是4
	⑤判断竖向横向是否能合并，最后四个格子跳过判断 最后一个格子不参与判断 所以是循环次数是15 只要有一处能合并就跳出*/
	for (srand((unsigned)malloc(1)), c = j = 0; game; j = k = 1, c = _getch()) {
		if (c == 'a' || c == 'w')
			order(16, 1, c == 'a' ? -1 : -4);
		else if (c == 'd' || c == 's')
			order(-1, -1, c == 'd' ? 1 : 4);
		for (i = 0; i < 16; i++)
			map[i] < 0 && (map[i] = -map[i]), map[i] || (j = 0);//如果有空地j=0
		do if (i = rand() % 16, j || k)
			break;
		while (map[i] || (map[i] = rand() % 5 ? 2 : 4, 0));
		for (i = 0, system("cls"); j && (i < 15 || (game = 0)); i++)
			if (i < 12 && map[i] == map[i + 4] || i + 1 & 3 && map[i] == map[i + 1])
				break;
		if (game || _cprintf("game over!"))
			_cprintf("score:%d", score);
		for (i = 0; i < 16; i++)
			_cprintf("%s%5d", wall[i & 3], map[i]);
	}
	return 0;
}

