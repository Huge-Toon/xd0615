/*
  多音调播放器

  依次播放多个引脚对应的多种音调

  电路:
  * 3个连接至数字引脚6,7,8的8Ω扬声器
*/


int pos = 0;//意义不明

void setup()
{
  pinMode(8, OUTPUT);//初始化引脚8为输出模式
  pinMode(6, OUTPUT);//初始化引脚6为输出模式
  pinMode(7, OUTPUT);//初始化引脚7为输出模式
}
/*
tone():
语法:
tone(pin, frequency)
tone(pin, frequency, duration)
释义：
以50%的占空比生成特定频率的方波信号。
输出引脚由pin参数确定。
信号频率由frequency参数确定。
持续时间由duration参数确定，若duration参数未被传入，
则对应信号输出直至noTone()函数被调用
后停止。
注意事项：
同一时间内只能在一个引脚上生成一种tone信号。
故在另一引脚上调用tone()函数时，
应先调用noTone（）关闭当前引脚上的tone信号。
*/
void loop()//往复循环
{
  // 关闭引脚8上的tone()函数
  noTone(8);
  // 在引脚6上播放一个200ms长的音符:
  tone(6, 880,200); // 播放音调 69 (A5 = 880 Hz)
  delay(200); // 等待200ms
  // 关闭引脚6上的tone()函数:
  noTone(6);
  // 在引脚7上播放一个500ms时长的音符
  tone(7, 988, 500); // 播放音调 69 (B5 = 988 Hz)
  delay(500); // 等待500ms
  // 关闭引脚7上的tone()函数
  noTone(7);
  // 在引脚7上播放一个300ms时长的音符:
  tone(8, 1047, 300); // 播放音调 72 (C6 = 1047 Hz)
  delay(300); // 等待300ms
}