#include <iostream>
#include <vector>
using namespace std;
int N;
int Msize;

void bricks(vector<int>& v, vector<bool>& isVisited) 
{
	if (v.size() == Msize) {
		for (int& k : v) {
			cout << k << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!isVisited[i]) {		//�湮���� ���� ��쿡��
			isVisited[i] = true;	//i�� �湮 üũ�ϰ�
			v.push_back(i);			//v���ҿ��ٰ� i�� Ǫ����
			bricks(v, isVisited);	//bricks ��� ȣ��
			v.pop_back();			//�ٽ� v���ҿ��� i�� ������
			isVisited[i] = false;	//i �湮 ����
		}
	}
}

int main(void)
{
	cin >> N >> Msize;
	vector<int> v;
	vector<bool> isVisited(N + 1);
	for (int i = 0; i <= N; i++) {
		isVisited[i] = false;
	}
	bricks(v, isVisited);
	
	return 0;
}