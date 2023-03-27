//クリップボード・テキスト設定
#include <stdio.h>
#include <windows.h>


int main(void) {
    //HGLOBAL thandl = NULL;
    HGLOBAL thandl=NULL;
    char str[1024];
    int len, ir; //テキスト文字列

    printf("\nPlease input letters\n");
    gets(str); //文字列取得

    len = strlen(str); //文字数
    if (len == 0) goto L9;

	thandl=GlobalAlloc(GMEM_FIXED,len+1);
    //thandl = GlobalAlloc(GMEM_FIXED, len+1);//文字列ハンドル割当
    if (thandl == NULL) goto L9;

    //strcpy(thandl, str);//文字列

    ir = OpenClipboard(NULL);
    if ( ir == 0) goto L9;//クリップボードを開く

    EmptyClipboard();//クリップボードクリア

    SetClipboardData(CF_TEXT, thandl);//クリップボードデータ設定
    CloseClipboard(); //クリップボードを閉じる
L9: ;
}
