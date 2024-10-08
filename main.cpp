
#include "DxLib.h"
#include <string>
#include "GameScene.h"

// ウィンドウのタイトルに表示する文字列
std::wstring TITLE = L"TITLE";

// ウィンドウ横幅
const int WIN_WIDTH = 640;

// ウィンドウ縦幅
const int WIN_HEIGHT = 880;

//// ウィンドウ横幅
//const int WIN_WIDTH = 1280;
//
//// ウィンドウ縦幅
//const int WIN_HEIGHT = 720;

//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	// 使用する文字コードを utf8 に設定
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText("4025_P花の警備　");

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)

	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0xFF);			

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言

	std::unique_ptr<GameScene> gameScene;
	gameScene = std::make_unique<GameScene>();
	gameScene->SetWindowSize(Vec2(WIN_WIDTH, WIN_HEIGHT));
	gameScene->Initialize();

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (1)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}


		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//



		// 更新処理

		gameScene->Update();

		// 描画処理


		gameScene->Draw();
		gameScene->DrawUI();

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();	

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	gameScene->AllClear();
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
