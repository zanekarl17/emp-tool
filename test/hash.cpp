#include "hash.h"
#include "utils.h"
#include <iostream>
using namespace std;

int main() {
	Hash hash;

	char * data = new char[1024*1024];
	hash.put(data, 1024*1024);
	char dig[Hash::DIGEST_SIZE];
	hash.digest(dig);
	
	for (long long length = 2; length <= 2048; length*=4) {
		long long times = 1024*1024*32/length;
		block * data = new block[length];
		auto start = clock_start();
		for (int i = 0; i < times; ++i) {
			hash.put(data, length);
			hash.digest(dig);
		}
		double interval = time_from(start);
		delete data;
		cout << "Hash speed with block size "<<length<<" :\t"<<(length*times*128)/(interval+0.0)*1e3<<" Gbps\n";
	}
	return 0;
}
