#include<stdlib.h>
#include<conio.h>
//map��ͼ score���� gameΪ0ʱ��Ϸ���� c���뻺�� iѭ������ j�Ƿ��пյ� k�ƶ��Ƿ���Ч
int map[16] = { 0 }, score = 0, game = 1, c, i, j, k;
const char* wall[4] = { "\n----- ----- ----- -----\n","|","|" ,"|" };//wallǽ
/*move()�ƶ� oΪҪ�ƶ��ĸ��� vΪ�ƶ�ֵ 
���ж�λ���Ƿ�����Խ�磬�Ƿ�Ϊ�յأ�����ֱ�ӷ���
���ж������Ƿ�Խ�磬���¾�λ���Ƿ���ͬһ�У����ھ���Խ��
���ж���λ���Ƿ�ͱ����ֵ��ͬ����ͬ�ͺϲ�����λ��ֵ*2��������0���Լ����ӷ�����Ϊ��ֹһ���������ϲ������Ժ���ϲ���Ϊ������������ȡ��
���ж���λ���Ƿ�Ϊ�յأ��ǿյػ�Ҫ�����ƶ����ݹ�����Լ���ֻ�в����ƶ�k��Ϊ0������û���ƶ������������*/
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
//����һ��˳������ƶ� begin���� end����ֵ i�������� v�ƶ�ֵ
void order(int end, int i, int v) {
	for (int begin = end == 16 ? 0 : 15; begin - end; begin += i)move(begin, v);
}
int main() {
	system("mode con:cols=25 lines=9");//���ô��ڴ�С ��Ϊ9��Ϊ25
	/*����������� gameΪ0��Ϸ����
	�٢��ж����룬�����������ƶ�
	�۸���ȡ����ͬʱ�ж��Ƿ��пյأ���ǰ��ȡ�������Ӧ������һ�������֣���ȡһ�����ֵ
	�����û�пյػ���û�в����ƶ���ֱ�����������ɡ�����ǿյ������������֣�80%��2��20%��4
	���ж���������Ƿ��ܺϲ�������ĸ����������ж� ���һ�����Ӳ������ж� ������ѭ��������15 ֻҪ��һ���ܺϲ�������*/
	for (srand((unsigned)malloc(1)), c = j = 0; game; j = k = 1, c = _getch()) {
		if (c == 'a' || c == 'w')
			order(16, 1, c == 'a' ? -1 : -4);
		else if (c == 'd' || c == 's')
			order(-1, -1, c == 'd' ? 1 : 4);
		for (i = 0; i < 16; i++)
			map[i] < 0 && (map[i] = -map[i]), map[i] || (j = 0);//����пյ�j=0
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

