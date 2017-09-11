#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

double getRandomNumber(const double min, const double max);
bool isInsideCircle(const double x, const double y);
bool isInsideHeart(const double x, const double y);


void main() {

	srand((unsigned int)time(NULL));
	//매번 다른 난수 형성을 위해 시드 심어줌
	int num_pts_square = 10000;//사각형 안에 찍히는 점의 수를 변수로 선언후 초기화
	int num_pts_circle = 0;//원 안에 찍히는 점의 수를 변수 선언후 초기화

	std::cout << "1번 문제" << std::endl;

	for (int i = 0; i < num_pts_square;i++){//i=0부터 num_pts_square 까지 반복문 실행
		double x = getRandomNumber(0.0, 1.0);
		//x값을 0.0부터 1.0사이의 난수를 발생시켜서 넣는다
		double y = getRandomNumber(0.0, 1.0);
		//y값을 0.0부터 1.0사이의 난수를 발생시켜서 넣는다
		if (isInsideCircle(x, y) == true) {//만약 원 안에 점이 찍혔다면
			num_pts_circle++;
			//num_pts_circle을 1 증가 시켜준다
		}
	}

	double circle_area = 1.0*num_pts_circle / num_pts_square;
	//원의 넓이는 사각형의 넓이 * 원안에 찍힌 점들의 갯수 / 사각형안에 찍힌 점들의 갯수(전체 내가 찍은 점갯수임) 이다.

	std::cout << "circle area from monte : " << circle_area << std::endl;
	//출력

	std::cout<<"circle_area from pi    : "<<0.5*0.5*3.14<<std::endl;
	//실제 파이로 계산한 값과 비교하기위해 파이로 계산한 값도 출력해보았다.


	std::cout << "\n2번,3번 문제" << std::endl;
	//2번,3번
	FILE *of = fopen("draw_heart.txt", "w");
	//하트를 그려주기위해 파일 오픈


	//int num_pts_square = 10000;//사각형 안에 찍히는 점의 수를 변수로 선언후 초기화
	int num_pts_heart = 0;//하트 안에 찍히는 점의 수를 변수 선언후 초기화


	for (int i = 0; i < num_pts_square; i++) {//i=0부터 num_pts_square 까지 반복문 실행
		double x = getRandomNumber(-1.5, 1.5);
		double y = getRandomNumber(-1.5, 1.5);
		//하트가 그려지는 범위가 x,y 모두 -1.5~1.5 내 이므로 범위를 -1.5~1.5 로 난수를 발생시켜서 넣는다
		if (isInsideHeart(x, y) == true) {//만약 하트 안에 있는 점이라면
			fprintf(of, "%f,%f\n", x, y);//파일 출력을 하고
			num_pts_heart++;//하트안에 찍힌 점의 수를 1증가시켜준다
		}

	}
	fclose(of);//반복문을 나오면 파일을 닫고
	double square_area = pow(3, 2);
	//사각형의 크기를 계산한다 (여기선 한변이 -1.5~1.5  이므로 3이고 크기는 3^2 이다.
	double heart_area = square_area * num_pts_heart / num_pts_square;
	//하트 의 크기는 사각형의 크기 * 하트에 찍힌 점의수/사각형에찍힌 점의수

	std::cout << "heart area : " << heart_area << std::endl;//출력한다





}

double getRandomNumber(const double min, const double max) {

	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;

}

bool isInsideCircle(const double x, const double y) {
	const double x_c = 0.5;//원의 중심 x좌표
	const double y_c = 0.5;//원의 중심 y좌표
	const double r = 0.5;//반지름의 크기
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;//원의 방정식

	if (f > 0.0)return false;//매개변수를 넣었을떄 0 보다 크면 false를 반환한다
	else return true;//아닐떄는 true (즉 있음)

}

bool isInsideHeart(const double x, const double y) {
	//제곱의 계산이 불편하여 math.h 의 pow 함수를 사용하였다.
	const double f = pow(pow(x, 2) + pow(y, 2) - 1.0, 3) - pow(x, 2)*pow(y, 3);

	if (f > 0.0)return false;
	else return true;

}
