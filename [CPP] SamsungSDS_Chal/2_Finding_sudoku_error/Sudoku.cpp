//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<int> targetx;
//int targety;
//vector<int> compensation;
//vector<int> result;
//
//void check_rowOverlap(int* start);
//void check_colOverlap(int* high);
//int n; // for compensation
//
//int testarr[9][9];
//
//int main()
//{
//	int* ptr;
//	int T;
//	int K[30];
//
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> K[i];
//		for (int j = 0; j < 9; j++) {
//			for (int k = 0; k < 9; k++) {
//				cin >> testarr[j][k];
//			}
//		}
//
//		for (targety = 0; targety < 9; targety++) 
//		{
//			check_rowOverlap(&testarr[targety][0]);
//
//			if (targetx.empty() != true) 
//			{
//				for (n = 0; n < compensation.size()+1; n++) {
//					check_colOverlap(&testarr[0][*(targetx.begin() + n) - 1]);
//				}
//				targetx.clear();
//				compensation.clear();
//			}
//		}
//	}
//
//	ptr = &result.at(0);
//	for (int i = 0; i < T; i++) {
//		printf("#%d ", i+1);
//		for (int j = 0; j < K[i]; j++) {
//			printf("%d %d %d ", *ptr, *(ptr + 1), *(ptr + 2));
//			ptr += 3;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//
//void check_rowOverlap(int* start) {
//
//	int address[9] = { 0,0,0,0,0,0,0,0,0 };
//
//	for (int k = 1; k < 10; k++) {
//		if (address[(*start) - 1] == 0) {
//			address[(*start) - 1] = k;
//		}
//		else {
//			targetx.push_back(address[*start - 1]);
//			targetx.push_back(k);
//		}
//		start++;
//	}
//
//	if (targetx.empty() != true) { // 중복 사이즈 재조정
//		sort(targetx.begin(), targetx.end());
//
//		for (int i = 0; i < targetx.size() - 1; i++) {
//			if (*(targetx.begin() + i) == *(targetx.begin() + i + 1))
//				targetx.erase(targetx.begin() + i);
//		}
//	}
//
//	for (int k = 0; k < 9; k++) {
//		if (address[k] == 0) { // 0인 곳 체크해서 보상 수 넣음
//			compensation.push_back(k + 1);
//		}
//	}
//}
//
//void check_colOverlap(int* high) {
//	int i, j;
//	int address[9] = { 0,0,0,0,0,0,0,0,0 };
//	for (i = 0; i < compensation.size(); i++) {
//		for (j = 0; j < 9; j++) {
//			if (*high == *(compensation.begin() + i)) {
//				break;
//			}
//			high += 8;
//		}
//		if (j == 9) {
//			result.push_back(targety + 1);
//			result.push_back(*(targetx.begin() + n));
//			result.push_back(*(compensation.begin() + i));
//			testarr[targety][*(targetx.begin() + n)] = *(compensation.begin() + i);
//		}
//	}
//}