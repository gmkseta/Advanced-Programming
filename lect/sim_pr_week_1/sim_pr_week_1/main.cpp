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
	//�Ź� �ٸ� ���� ������ ���� �õ� �ɾ���
	int num_pts_square = 10000;//�簢�� �ȿ� ������ ���� ���� ������ ������ �ʱ�ȭ
	int num_pts_circle = 0;//�� �ȿ� ������ ���� ���� ���� ������ �ʱ�ȭ

	std::cout << "1�� ����" << std::endl;

	for (int i = 0; i < num_pts_square;i++){//i=0���� num_pts_square ���� �ݺ��� ����
		double x = getRandomNumber(0.0, 1.0);
		//x���� 0.0���� 1.0������ ������ �߻����Ѽ� �ִ´�
		double y = getRandomNumber(0.0, 1.0);
		//y���� 0.0���� 1.0������ ������ �߻����Ѽ� �ִ´�
		if (isInsideCircle(x, y) == true) {//���� �� �ȿ� ���� �����ٸ�
			num_pts_circle++;
			//num_pts_circle�� 1 ���� �����ش�
		}
	}

	double circle_area = 1.0*num_pts_circle / num_pts_square;
	//���� ���̴� �簢���� ���� * ���ȿ� ���� ������ ���� / �簢���ȿ� ���� ������ ����(��ü ���� ���� ��������) �̴�.

	std::cout << "circle area from monte : " << circle_area << std::endl;
	//���

	std::cout<<"circle_area from pi    : "<<0.5*0.5*3.14<<std::endl;
	//���� ���̷� ����� ���� ���ϱ����� ���̷� ����� ���� ����غ��Ҵ�.


	std::cout << "\n2��,3�� ����" << std::endl;
	//2��,3��
	FILE *of = fopen("draw_heart.txt", "w");
	//��Ʈ�� �׷��ֱ����� ���� ����


	//int num_pts_square = 10000;//�簢�� �ȿ� ������ ���� ���� ������ ������ �ʱ�ȭ
	int num_pts_heart = 0;//��Ʈ �ȿ� ������ ���� ���� ���� ������ �ʱ�ȭ


	for (int i = 0; i < num_pts_square; i++) {//i=0���� num_pts_square ���� �ݺ��� ����
		double x = getRandomNumber(-1.5, 1.5);
		double y = getRandomNumber(-1.5, 1.5);
		//��Ʈ�� �׷����� ������ x,y ��� -1.5~1.5 �� �̹Ƿ� ������ -1.5~1.5 �� ������ �߻����Ѽ� �ִ´�
		if (isInsideHeart(x, y) == true) {//���� ��Ʈ �ȿ� �ִ� ���̶��
			fprintf(of, "%f,%f\n", x, y);//���� ����� �ϰ�
			num_pts_heart++;//��Ʈ�ȿ� ���� ���� ���� 1���������ش�
		}

	}
	fclose(of);//�ݺ����� ������ ������ �ݰ�
	double square_area = pow(3, 2);
	//�簢���� ũ�⸦ ����Ѵ� (���⼱ �Ѻ��� -1.5~1.5  �̹Ƿ� 3�̰� ũ��� 3^2 �̴�.
	double heart_area = square_area * num_pts_heart / num_pts_square;
	//��Ʈ �� ũ��� �簢���� ũ�� * ��Ʈ�� ���� ���Ǽ�/�簢�������� ���Ǽ�

	std::cout << "heart area : " << heart_area << std::endl;//����Ѵ�





}

double getRandomNumber(const double min, const double max) {

	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;

}

bool isInsideCircle(const double x, const double y) {
	const double x_c = 0.5;//���� �߽� x��ǥ
	const double y_c = 0.5;//���� �߽� y��ǥ
	const double r = 0.5;//�������� ũ��
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;//���� ������

	if (f > 0.0)return false;//�Ű������� �־����� 0 ���� ũ�� false�� ��ȯ�Ѵ�
	else return true;//�ƴҋ��� true (�� ����)

}

bool isInsideHeart(const double x, const double y) {
	//������ ����� �����Ͽ� math.h �� pow �Լ��� ����Ͽ���.
	const double f = pow(pow(x, 2) + pow(y, 2) - 1.0, 3) - pow(x, 2)*pow(y, 3);

	if (f > 0.0)return false;
	else return true;

}
