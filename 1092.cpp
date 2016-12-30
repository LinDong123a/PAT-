#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string store, XiaoHong;
	cin >> store >> XiaoHong;
	map<char, int> Store, _XiaoHong;
	for (int i = 0; i < store.size(); ++i)
		++Store[store[i]];
	for (int j = 0; j < XiaoHong.size(); ++j)
		++_XiaoHong[XiaoHong[j]];

	int less_than = 0;
	bool is_enough = true;
	for (auto beg = _XiaoHong.begin(); beg != _XiaoHong.end(); ++beg) {
		if (beg->second > Store[beg->first]) {
			is_enough = false;
			less_than += beg->second - Store[beg->first];
		}
	}

	if (is_enough)
		cout << "Yes " << store.size() - XiaoHong.size();
	else
		cout << "No " << less_than;

	system("pause");
	return 0;
}