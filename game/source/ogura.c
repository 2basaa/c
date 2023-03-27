/*小倉百人一首*/
/*
stdiio.h　標準入出力を処理する関数
string.h  str,mem,wrsなどの関数で使用
stdlib.h  数値変換、疑似乱数列生成、記憶域管理など
time.h 時間を使用するときのライブラリ
windows.h 文字入力などで使用
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void READtxt(int*);
void explode(char*, char*, int);

char kami[100][64];//6400����
char simo[100][64];
char yomi[100][64];
int readCard;//詠みカード
int quesitionCard[10];//10このランダムな問題

void main() {
	char c[128];
	int N, i, j;
	
	printf("\n���q�S�l���\n");
	printf("\n0����͂���ƏI��\n");
	//�X�g���[���̃f�[�^�������ς��ɂȂ�ƁA�X�g���[���̃f�[�^��f���o��
	fflush(stdout);
	//srand��rand()�V�[�h���ݒ� 
	srand(time(NULL));
	
	//ファイル読み込めでなかったらENDへ
	READtxt(&N);
	if (N==0) goto END;
	
	while(1) {
		//10こランダムに選ぶ
		for(i=0; i< 10; i++) {
			//%で余りをだす。
			//1から100までの値をだす。
			quesitionCard[i]=rand()%100+1;
		} 
		//questionCardの中の0から9まで
		readCard=quesitionCard[rand()%10];

		printf("\n");fflush(stdout);
		for(i=0; i<10; i++) {
			//jは０から100までの番号
			//下の句を10個表示
			j = quesitionCard[i] - 1;
			printf("\n%3d: %s", j+1, &simo[j][0]);
		}
		//fflush(stdout)で一気に出力ではなく、徐々に出力
		printf("\n"); fflush(stdout);
		//解答の上の句を表示
		printf("\n %s\n", &kami[readCard-1][0]); fflush(stdout);

		while(1) {
			printf("\n:�̔ԍ�"); fflush(stdout);
			//gets(c)で128バイトまでの文字を読み込む
			gets(c);
			//文字列１と文字列2を比較
			/*strcmo(str1, str2) str1とstr2を比較
				str1=str2なら0
				str1!=str2なら0以外の値
				ファイルが読み込めなかったら、break
			*/
			if (strcmp(c, "0") == 0) break;
			//atoi(c)で文字列から数値へ変換
			//正解処理
			if (atoi(c)==readCard)
			{
				//Beep()でビープ音を鳴らす
				//Beep(Hz, time[ms])
				Beep(660, 100); Beep(523,200);
				break;
			}
			//お手付き処理
			Beep(440, 100); Sleep(50); Beep(440, 300);
			printf("����t���ł�\n\n"); fflush(stdout);
			continue;
		}

		printf("\n----------------------------\n");
		fflush(stdout);

		if( strcmp(c, "0") == 0) break;
	}

END: ;
} 

void READtxt(
/*�e�L�X�g�t�@�C����ǂݍ���*/
int *N )//�s�� 
{
	FILE *fp=NULL;//�t�@�C���̃|�C���^�͂Ȃ�
	//char�^�́A1�o�C�g�����̕�����
	//buf��1������512�����i�[�����z�� 
	char buf[512], *cp;
	int i;
	
	*N = 0;
	
	//memset�֐��̓������Ɏw��o�C�g�����̒l���Z�b�g
	/*void *buf�́A�������̃|�C���^
	  int ch�́A�Z�b�g����l
	  size_t n�́A�Z�b�g����T�C�Y 
	memset(void *buf, int ch, size_t n)
	��L�ŁA�w�肳�ꂽ�A�h���X�̏ꏊ��6400�o�C�g����\0���������� 
	&�̓A�h���X���Z�q���A�A�h���X�ԍ����o�� 
	\0�́A�I�[������(������̂����܂�����������) 
	*/

	//c言語では、['']では囲まれた文字は文字リテラル
	//[""]では囲まれた文字列は文字列が格納されたアドレス
	memset(&kami[0][0], '\0', 6400);
	memset(&simo[0][0], '\0', 6400);
	memset(&yomi[0][0], '\0', 6400);	 
	
	fp = fopen("C:/workspace/c/game/textFolder/ogura100.txt", "r");
	if (fp == NULL) goto END;
	
	//�S�l���̒T�� 
	for (i=0; i<100; i++) {
		/* 
		char *s�͕����z��̃|�C���^
		iint n�͈�s�̍ő啶����
		FILE fp�̓t�@�C���|�C���^ 
		fgets(char *s,int n, FILE fp);
		fgets�Ńt�@�C�����當�������s�擾*/ 
		cp = fgets(buf, 500, fp);
		if (cp==NULL) break;
		//"\t"�Ń^�u�����������ƂɂȂ� 
		explode("\t", buf, i);
		(*N)++;
	}
END: if(fp!=NULL) fclose(fp);
}

void explode(
/*�e�L�X�g�f�[�^���獀�ڂ����o��*/
char *kugiri, //��؂蕶��
char *buf, //�e�L�X�g1�s
int i)
{
	char *cp0, *cp; //������A�h���X
	int len; 
	len = strlen(buf);//������̒���
	if (len==0) goto END;
	if (buf[len-1]=='\n') buf[len-1]='\0';
	
	//��̋�̏���
	cp0 = buf;
	//strstr(cp0, kugiri)
	//strstr�ŕ�����cp0�̒���kugiri��T��
	cp = strstr(cp0, kugiri);
	if (cp == NULL) goto END;
	len=cp - cp0;//�ŏ��̕�������\t�܂ł̕�����
	memcpy(&kami[i][0], cp0, len);
	
	//���̋�̏���
	cp0 = cp + 1;
	cp = strstr(cp0, kugiri);
	if (cp==NULL) goto END;
	len= cp - cp0;//���̋�̒���
	memcpy(&simo[i][0], cp0, len);
	
	//�r�ݐl
	cp0 = cp + 1;
	strcpy(&yomi[i][0], cp0);
	
END: ;
}
