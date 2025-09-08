// First N Fibonacci Numbers, recursive, efficient
#include <iostream>
using namespace std;
int call_count = 0;
const unsigned int N = 10;

unsigned int fib (unsigned int n);

int main () {
	cout << "Generating the first " << N << " Fibonacci numbers." << endl;
	for (unsigned int i = 0; i < N; i++) {
		cout << " " << fib(i);
		cout.flush();
		
	}
	cout << endl;
	cout << "Call count: " << call_count << endl;
	return 0;
}

unsigned int fib (unsigned int n) {
	call_count++;
	static unsigned int results[N] = { 0 };
	if (!results[n])
		results[n] = n <= 1 ? 1 : fib(n - 1) + fib(n - 2);
	return results[n];
}
