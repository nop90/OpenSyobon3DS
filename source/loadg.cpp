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
    mgrap[0] = LoadGraph("/syobon/res/player.PNG");
	sf2d_texture_set_params(mgrap[0], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//ブロック
    mgrap[1] = LoadGraph("/syobon/res/brock.PNG");
	sf2d_texture_set_params(mgrap[1], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//アイテム
    mgrap[2] = LoadGraph("/syobon/res/item.PNG");
	sf2d_texture_set_params(mgrap[2], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//敵
    mgrap[3] = LoadGraph("/syobon/res/teki.PNG");
	sf2d_texture_set_params(mgrap[3], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//背景
    mgrap[4] = LoadGraph("/syobon/res/haikei.PNG");
	sf2d_texture_set_params(mgrap[4], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//ブロック2
    mgrap[5] = LoadGraph("/syobon/res/brock2.PNG");
	sf2d_texture_set_params(mgrap[5], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//おまけ
    mgrap[6] = LoadGraph("/syobon/res/omake.PNG");
	sf2d_texture_set_params(mgrap[6], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//おまけ2
   mgrap[7] = LoadGraph("/syobon/res/omake2.PNG");
	sf2d_texture_set_params(mgrap[7], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
//タイトル
    mgrap[30] = LoadGraph("/syobon/res/syobon3.PNG");
	sf2d_texture_set_params(mgrap[30], GPU_TEXTURE_MAG_FILTER(GPU_LINEAR) | GPU_TEXTURE_MIN_FILTER(GPU_LINEAR)); 
// level icons
   mgrap[8] = LoadGraph("/syobon/res/levels.PNG");
//Background
   mgrap[9] = LoadGraph("/syobon/res/background.PNG");

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


   for (t = 0; t < 6; t++) {
	otom[t] = 0;
    }
   for (t = 0; t < 19; t++) {
	oto[t] = 0;
    }



    otom[1] = createSFX("/syobon/BGM/field.raw",SOUND_FORMAT_16BIT); 
    otom[2] = createSFX("/syobon/BGM/dungeon.raw",SOUND_FORMAT_16BIT); 
    otom[3] = createSFX("/syobon/BGM/star4.raw",SOUND_FORMAT_16BIT); 
    otom[4] = createSFX("/syobon/BGM/castle.raw",SOUND_FORMAT_16BIT);
    otom[5] = createSFX("/syobon/BGM/puyo.raw",SOUND_FORMAT_16BIT); 

// //otom[6]=LoadMusicMem( "/syobon/BGM/last.raw",SOUND_FORMAT_16BIT);

    oto[1] = createSFX("/syobon/SE/jump.raw",SOUND_FORMAT_16BIT);
// //oto[2] = LoadSoundMem("/syobon/SE/brockcoin.raw",SOUND_FORMAT_16BIT);
    oto[3] = createSFX("/syobon/SE/brockbreak.raw",SOUND_FORMAT_16BIT);
    oto[4] = createSFX("/syobon/SE/coin.raw",SOUND_FORMAT_16BIT);
    oto[5] = createSFX("/syobon/SE/humi.raw",SOUND_FORMAT_16BIT);
    oto[6] = createSFX("/syobon/SE/koura.raw",SOUND_FORMAT_16BIT);
    oto[7] = createSFX("/syobon/SE/dokan.raw",SOUND_FORMAT_16BIT);
    oto[8] = createSFX("/syobon/SE/brockkinoko.raw",SOUND_FORMAT_16BIT);
    oto[9] = createSFX("/syobon/SE/powerup.raw",SOUND_FORMAT_16BIT);
    oto[10] = createSFX("/syobon/SE/kirra.raw",SOUND_FORMAT_16BIT);
    oto[11] = createSFX("/syobon/SE/goal.raw",SOUND_FORMAT_16BIT);
    oto[12] = createSFX("/syobon/SE/death.raw",SOUND_FORMAT_16BIT);
    oto[13] = createSFX("/syobon/SE/Pswitch.raw",SOUND_FORMAT_16BIT);
    oto[14] = createSFX("/syobon/SE/jumpBlock.raw",SOUND_FORMAT_16BIT);
    oto[15] = createSFX("/syobon/SE/hintBlock.raw",SOUND_FORMAT_16BIT);
    oto[16] = createSFX("/syobon/SE/4clear.raw",SOUND_FORMAT_16BIT);
    oto[17] = createSFX("/syobon/SE/allclear.raw",SOUND_FORMAT_16BIT);
    oto[18] = createSFX("/syobon/SE/tekifire.raw",SOUND_FORMAT_16BIT);




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