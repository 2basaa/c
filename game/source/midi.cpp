/* MIDI音源                 */
/* アニーローリー           */
/* リンク時にwinmm.libを追加*/
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

/*音階
60　ド
62　レ
64　ミ
65　ファ
67　ソ
69　ラ
71　シ
72　ド
*/

//音階のデータ(-1は最後の印)
int musicScale[128] = {
    64, 62, //ミレ
    60, 60, 72, 71, //ドドドシ
    71, 69, 69,//シララ
    67, 64, 64, 62, 60,//ソミミレド 
    62, 64, 62,//レミレ
    71, 69, 69, //シララ
    67, 64, 62, 60,//ソミレド
    60, 0, 67,//ド・ソ
    72, 72, 74, 74,//ドドレレ
    76, 67, //ミソ
    72, 72, 74, 74,//ドドレレ
    76, 76, 74, //ミミレ
    72, 71, 69, 72, 69,// ドシラドラ
    67, 64, 64, 62,//ソミミレ
    60, 72, 64, 62, 60, // ドドミレド
    60, //ド
    -1
};

//音の長さのデータ[ms]
int musicLength[128] = {
    375, 125, 
    750, 250, 750, 250,
    500, 1000, 500,
    750, 250, 500, 250, 250, 
    1500, 375, 125, 
    750, 250, 750, 250, 
    1000, 500, 500,
    750, 250, 750, 250,
    1500, 375, 125, 
    750, 250, 500, 250, 250,
    500, 1000, 375, 125, 
    250, 500, 250, 750, 250,
    1500,
};

int main(void) {
    HMIDIOUT hmo; //MIDIデバイスのハンドル
    int timbre = 11; //音色(1~128)Music Box
    int number;
    printf("\nアニーローリー\n");
    //MIDI出力デバイスを開く
    midiOutOpen(&hmo, MIDI_MAPPER, 0, 0, CALLBACK_NULL);
    //音色を設定
    midiOutShortMsg(hmo, 0x000000C0 |timbre<<8);

    for (number=0; musicScale[number] != -1; number++) {
        //音を出す
        //MID出力デバイスにメッセージ送信
        midiOutShortMsg(hmo, 0x7F0090 | (musicScale[number]<<8));
        Sleep(musicLength[number]);//待機
        //音を消す
        //MID出力デバイスにメッセージ送信
        midiOutShortMsg(hmo, 0x80 | (musicScale[number]<<8));
    }
    midiOutClose(hmo); //MIDI出力デバイスを閉じる
    return 0;
}
