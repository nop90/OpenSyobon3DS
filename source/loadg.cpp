#include "os3ds.h"

extern int ma, t, tt;
extern t_graph *grap[161][8];
extern sf2d_texture *mgrap[51];
int x1;
extern SFX_s* otom[6];
extern SFX_s* oto[19];

extern int anx[160], any[160];
extern int ne[41], nf[41];

void loadg(void)
{

    for (t = 0; t < 51; t++) {
	mgrap[t] = 0;
    }
    for (int i = 0; i < 161; i++)
	for (int j = 0; j < 8; j++)
	    grap[i][j] = NULL;



//画像読み込み

// 透過色を変更
//SetTransColor( 9*16+9 , 255 , 255 ) ;

//プレイヤー
    mgrap[0] = LoadGraph("romfs:/res/player.PNG");
//ブロック
    mgrap[1] = LoadGraph("romfs:/res/brock.PNG");
//アイテム
    mgrap[2] = LoadGraph("romfs:/res/item.PNG");
//敵
    mgrap[3] = LoadGraph("romfs:/res/teki.PNG");
//背景
    mgrap[4] = LoadGraph("romfs:/res/haikei.PNG");
//ブロック2
    mgrap[5] = LoadGraph("romfs:/res/brock2.PNG");
//おまけ
    mgrap[6] = LoadGraph("romfs:/res/omake.PNG");
//おまけ2
   mgrap[7] = LoadGraph("romfs:/res/omake2.PNG");
//タイトル
    mgrap[30] = LoadGraph("romfs:/res/syobon3.PNG");

// level icons
   mgrap[8] = LoadGraph("romfs:/res/Levels.png");
//Background
   mgrap[9] = LoadGraph("romfs:/res/Background.png");

//プレイヤー読み込み
    grap[40][0] = DerivationGraph(0, 0, 30, 36, mgrap[0]);
    grap[0][0] = DerivationGraph(31 * 4, 0, 30, 36, mgrap[0]);
    grap[1][0] = DerivationGraph(31 * 1, 0, 30, 36, mgrap[0]);
    grap[2][0] = DerivationGraph(31 * 2, 0, 30, 36, mgrap[0]);
    grap[3][0] = DerivationGraph(31 * 3, 0, 30, 36, mgrap[0]);
    grap[41][0] = DerivationGraph(50, 0, 51, 73, mgrap[6]);

    x1 = 1;
//ブロック読み込み
    for (t = 0; t <= 6; t++) {
	grap[t][x1] = DerivationGraph(33 * t, 0, 30, 30, mgrap[x1]);
	grap[t + 30][x1] = DerivationGraph(33 * t, 33, 30, 30, mgrap[x1]);
	grap[t + 60][x1] = DerivationGraph(33 * t, 66, 30, 30, mgrap[x1]);
	grap[t + 90][x1] = DerivationGraph(33 * t, 99, 30, 30, mgrap[x1]);
    }
    grap[8][x1] = DerivationGraph(33 * 7, 0, 30, 30, mgrap[x1]);
    grap[16][x1] = DerivationGraph(33 * 6, 0, 24, 27, mgrap[2]);
    grap[10][x1] = DerivationGraph(33 * 9, 0, 30, 30, mgrap[x1]);
    grap[40][x1] = DerivationGraph(33 * 9, 33, 30, 30, mgrap[x1]);
    grap[70][x1] = DerivationGraph(33 * 9, 66, 30, 30, mgrap[x1]);
    grap[100][x1] = DerivationGraph(33 * 9, 99, 30, 30, mgrap[x1]);

//ブロック読み込み2
    x1 = 5;
    for (t = 0; t <= 6; t++) {
	grap[t][x1] = DerivationGraph(33 * t, 0, 30, 30, mgrap[x1]);
    }
    grap[10][5] = DerivationGraph(33 * 1, 33, 30, 30, mgrap[x1]);
    grap[11][5] = DerivationGraph(33 * 2, 33, 30, 30, mgrap[x1]);
    grap[12][5] = DerivationGraph(33 * 0, 66, 30, 30, mgrap[x1]);
    grap[13][5] = DerivationGraph(33 * 1, 66, 30, 30, mgrap[x1]);
    grap[14][5] = DerivationGraph(33 * 2, 66, 30, 30, mgrap[x1]);


//アイテム読み込み
    x1 = 2;
    for (t = 0; t <= 5; t++) {
		grap[t][x1] = DerivationGraph(33 * t, 0, 30, 30, mgrap[x1]);
    }

//敵キャラ読み込み
    x1 = 3;
    grap[0][x1] = DerivationGraph(33 * 0, 0, 30, 30, mgrap[x1]);
    grap[1][x1] = DerivationGraph(33 * 1, 0, 30, 43, mgrap[x1]);
    grap[2][x1] = DerivationGraph(33 * 2, 0, 30, 30, mgrap[x1]);
    grap[3][x1] = DerivationGraph(33 * 3, 0, 30, 44, mgrap[x1]);
    grap[4][x1] = DerivationGraph(33 * 4, 0, 33, 35, mgrap[x1]);

    grap[5][x1] = DerivationGraph(0, 0, 37, 55, mgrap[7]);
    grap[6][x1] = DerivationGraph(38 * 2, 0, 36, 50, mgrap[7]);
    grap[150][x1] = DerivationGraph(38 * 2 + 37 * 2, 0, 36, 50, mgrap[7]);
    grap[7][x1] = DerivationGraph(33 * 6 + 1, 0, 32, 32, mgrap[x1]);
    grap[8][x1] = DerivationGraph(38 * 2 + 37 * 3, 0, 37, 47, mgrap[7]);
    grap[151][x1] = DerivationGraph(38 * 3 + 37 * 3, 0, 37, 47, mgrap[7]);
    grap[9][x1] = DerivationGraph(33 * 7 + 1, 0, 26, 30, mgrap[x1]);
    grap[10][x1] = DerivationGraph(214, 0, 46, 16, mgrap[6]);


//モララー
    grap[30][x1] = DerivationGraph(0, 56, 30, 36, mgrap[7]);
    grap[155][x1] = DerivationGraph(31 * 3, 56, 30, 36, mgrap[7]);
    grap[31][x1] = DerivationGraph(50, 74, 49, 79, mgrap[6]);


    grap[80][x1] = DerivationGraph(151, 31, 70, 40, mgrap[4]);
    grap[81][x1] = DerivationGraph(151, 72, 70, 40, mgrap[4]);
    grap[130][x1] = DerivationGraph(151 + 71, 72, 70, 40, mgrap[4]);
    grap[82][x1] = DerivationGraph(33 * 1, 0, 30, 30, mgrap[5]);
    grap[83][x1] = DerivationGraph(0, 0, 49, 48, mgrap[6]);
    grap[84][x1] = DerivationGraph(33 * 5 + 1, 0, 30, 30, mgrap[x1]);
    grap[86][x1] = DerivationGraph(102, 66, 49, 59, mgrap[6]);
    grap[152][x1] = DerivationGraph(152, 66, 49, 59, mgrap[6]);

    grap[90][x1] = DerivationGraph(102, 0, 64, 63, mgrap[6]);

    grap[100][x1] = DerivationGraph(33 * 1, 0, 30, 30, mgrap[2]);
    grap[101][x1] = DerivationGraph(33 * 7, 0, 30, 30, mgrap[2]);
    grap[102][x1] = DerivationGraph(33 * 3, 0, 30, 30, mgrap[2]);

//grap[104][x1] = DerivationGraph( 33*2, 0, 30, 30, mgrap[5]) ;
    grap[105][x1] = DerivationGraph(33 * 5, 0, 30, 30, mgrap[2]);
    grap[110][x1] = DerivationGraph(33 * 4, 0, 30, 30, mgrap[2]);

//test ko

//背景読み込み
    x1 = 4;
    grap[0][x1] = DerivationGraph(0, 0, 150, 90, mgrap[x1]);
    grap[1][x1] = DerivationGraph(151, 0, 65, 29, mgrap[x1]);
    grap[2][x1] = DerivationGraph(151, 31, 70, 40, mgrap[x1]);
    grap[3][x1] = DerivationGraph(0, 91, 100, 90, mgrap[x1]);
    grap[4][x1] = DerivationGraph(151, 113, 51, 29, mgrap[x1]);
    grap[5][x1] = DerivationGraph(222, 0, 28, 60, mgrap[x1]);
    grap[6][x1] = DerivationGraph(151, 143, 90, 40, mgrap[x1]);
    grap[30][x1] = DerivationGraph(293, 0, 149, 90, mgrap[x1]);
    grap[31][x1] = DerivationGraph(293, 92, 64, 29, mgrap[x1]);

//中間フラグ
    grap[20][x1] = DerivationGraph(40, 182, 40, 60, mgrap[x1]);

// 3DS logo
    grap[40][x1] = DerivationGraph(150, 200, 145, 45, mgrap[x1]);

//グラ
    x1 = 5;
    grap[0][x1] = DerivationGraph(167, 0, 45, 45, mgrap[6]);

//敵サイズ収得
//int GrHandle=0;
    x1 = 3;
    for (t = 0; t <= 140; t++) {
	if (grap[t][x1]) {
	    anx[t] = grap[t][x1]->width;
	    any[t] = grap[t][x1]->height;
//GetGraphSize(grap[t][x1] ,&anx[t] ,&any[t]);
	    anx[t] *= 100;
	    any[t] *= 100;
	} else {
	    anx[t] = 0;
	    any[t] = 0;
	}
    }
    anx[79] = 120 * 100;
    any[79] = 15 * 100;
    anx[85] = 25 * 100;
    any[85] = 30 * 10 * 100;

//背景サイズ収得
    x1 = 4;
    for (t = 0; t < 40; t++) {
	if (grap[t][x1]) {
	    ne[t] = grap[t][x1]->width;
	    nf[t] = grap[t][x1]->height;
//GetGraphSize(grap[t][x1] ,&ne[t] ,&nf[t]);
//ne[t]*=100;nf[t]*=100;
	} else {
	    ne[t] = 0;
	    nf[t] = 0;
	}
    }

// Level selection icons
	for (t=0;t<=10;t++)
		grap[20+t][5] = DerivationGraph(48*t, 0, 48, 48, mgrap[8]);
 
/*
anx[0]=30;any[0]=30;
anx[1]=30;any[1]=43;
anx[2]=30;any[2]=30;
anx[3]=30;any[3]=44;
*/


/*

//ogg読み込み
//try{
//oto[2] = LoadSoundMem( "SE/1.mp3" ) ;
    otom[1] = LoadMusicMem("romfs:/BGM/field.ogg"); //50
    otom[2] = LoadMusicMem("romfs:/BGM/dungeon.ogg"); //40
    otom[3] = LoadMusicMem("romfs:/BGM/star4.ogg"); //50
    otom[4] = LoadMusicMem("romfs:/BGM/castle.ogg"); //50
    otom[5] = LoadMusicMem("romfs:/BGM/puyo.ogg"); //50
//otom[6]=LoadMusicMem( "romfs:/BGM/last.ogg");
//ChangeVolumeSoundMem(50, otom[6]);

    oto[1] = LoadSoundMem("romfs:/SE/jump.ogg");
//oto[2] = LoadSoundMem("romfs:/SE/brockcoin.ogg");
    oto[3] = LoadSoundMem("romfs:/SE/brockbreak.ogg");
    oto[4] = LoadSoundMem("romfs:/SE/coin.ogg");
    oto[5] = LoadSoundMem("romfs:/SE/humi.ogg");
    oto[6] = LoadSoundMem("romfs:/SE/koura.ogg");
    oto[7] = LoadSoundMem("romfs:/SE/dokan.ogg");
    oto[8] = LoadSoundMem("romfs:/SE/brockkinoko.ogg");
    oto[9] = LoadSoundMem("romfs:/SE/powerup.ogg");
    oto[10] = LoadSoundMem("romfs:/SE/kirra.ogg");
    oto[11] = LoadSoundMem("romfs:/SE/goal.ogg");
    oto[12] = LoadSoundMem("romfs:/SE/death.ogg");
    oto[13] = LoadSoundMem("romfs:/SE/Pswitch.ogg");
    oto[14] = LoadSoundMem("romfs:/SE/jumpBlock.ogg");
    oto[15] = LoadSoundMem("romfs:/SE/hintBlock.ogg");
    oto[16] = LoadSoundMem("romfs:/SE/4-clear.ogg");
    oto[17] = LoadSoundMem("romfs:/SE/allclear.ogg");
    oto[18] = LoadSoundMem("romfs:/SE/tekifire.ogg");

*/

   for (t = 0; t < 6; t++) {
	otom[t] = 0;
    }
   for (t = 0; t < 19; t++) {
	oto[t] = 0;
    }



    otom[1] = createSFX("romfs:/BGM/field.raw",SOUND_FORMAT_16BIT); 
    otom[2] = createSFX("romfs:/BGM/dungeon.raw",SOUND_FORMAT_16BIT); 
    otom[3] = createSFX("romfs:/BGM/star4.raw",SOUND_FORMAT_16BIT); 
    otom[4] = createSFX("romfs:/BGM/castle.raw",SOUND_FORMAT_16BIT);
    otom[5] = createSFX("romfs:/BGM/puyo.raw",SOUND_FORMAT_16BIT); 

// //otom[6]=LoadMusicMem( "romfs:/BGM/last.raw",SOUND_FORMAT_16BIT);

    oto[1] = createSFX("romfs:/SE/jump.raw",SOUND_FORMAT_16BIT);
// //oto[2] = LoadSoundMem("romfs:/SE/brockcoin.raw",SOUND_FORMAT_16BIT);
    oto[3] = createSFX("romfs:/SE/brockbreak.raw",SOUND_FORMAT_16BIT);
    oto[4] = createSFX("romfs:/SE/coin.raw",SOUND_FORMAT_16BIT);
    oto[5] = createSFX("romfs:/SE/humi.raw",SOUND_FORMAT_16BIT);
    oto[6] = createSFX("romfs:/SE/koura.raw",SOUND_FORMAT_16BIT);
    oto[7] = createSFX("romfs:/SE/dokan.raw",SOUND_FORMAT_16BIT);
    oto[8] = createSFX("romfs:/SE/brockkinoko.raw",SOUND_FORMAT_16BIT);
    oto[9] = createSFX("romfs:/SE/powerup.raw",SOUND_FORMAT_16BIT);
    oto[10] = createSFX("romfs:/SE/kirra.raw",SOUND_FORMAT_16BIT);
    oto[11] = createSFX("romfs:/SE/goal.raw",SOUND_FORMAT_16BIT);
    oto[12] = createSFX("romfs:/SE/death.raw",SOUND_FORMAT_16BIT);
    oto[13] = createSFX("romfs:/SE/Pswitch.raw",SOUND_FORMAT_16BIT);
    oto[14] = createSFX("romfs:/SE/jumpBlock.raw",SOUND_FORMAT_16BIT);
    oto[15] = createSFX("romfs:/SE/hintBlock.raw",SOUND_FORMAT_16BIT);
    oto[16] = createSFX("romfs:/SE/4clear.raw",SOUND_FORMAT_16BIT);
    oto[17] = createSFX("romfs:/SE/allclear.raw",SOUND_FORMAT_16BIT);
    oto[18] = createSFX("romfs:/SE/tekifire.raw",SOUND_FORMAT_16BIT);




//ループ設定-20000-20秒
//SetLoopPosSoundMem( 1,oto[104]) ;
//SetLoopSamplePosSoundMem(44100,oto[104]);
//SetLoopSamplePosSoundMem(22050,oto[104]);

}
/*
extern bool sound;
void parseArgs(int argc, char* argv[])
{
    if(argc <= 1) return;
    for(int i = 0; i < argc; i++)
    {
        if(!strcasecmp(argv[i], "-nosound")) sound = false;
    }
}
*/