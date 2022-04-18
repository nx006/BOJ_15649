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
		if (!isVisited[i]) {		//방문하지 않은 경우에만
			isVisited[i] = true;	//i를 방문 체크하고
			v.push_back(i);			//v원소에다가 i를 푸쉬함
			bricks(v, isVisited);	//bricks 재귀 호출
			v.pop_back();			//다시 v원소에서 i를 제거함
			isVisited[i] = false;	//i 방문 해제
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