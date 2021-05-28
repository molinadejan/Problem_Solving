#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
  // 사람이 100살까지 산다고 하고
  // N년간 하루에 M개비 씩 담배를 피웠을때
  // 남은 수명
  // 담개 1개비 당 20분 수명 단축
  
  int N, M;
  scanf("%d%d", &N, &M);


  int lifeTimeToMinute = 100 * 365 * 24 * 60;
  int reducedTimeToMinute = N * 365 * M * 20;

  lifeTimeToMinute -= reducedTimeToMinute;

  printf("줄어든 시간 : %02d일 %02d시 %02d분\n", 
      reducedTimeToMinute / (60 * 24), (reducedTimeToMinute / 60) % 24, reducedTimeToMinute % 60);

  printf("기대수명 : %02d살 %02d일 %02d시간 %02d분\n", 
      lifeTimeToMinute / (365 * 24 * 60), (lifeTimeToMinute / (24 * 60)) % 365, (lifeTimeToMinute / 60) % 24, lifeTimeToMinute % 60);

  return 0;
}
