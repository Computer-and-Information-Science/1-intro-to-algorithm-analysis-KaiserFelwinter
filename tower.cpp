// Tower of Hanoi puzzle for an arbitrary number of disks, recursive
#include <iostream>
using namespace std;
int call_count = 0;
void tower (int n_disks, char from, char to, char interim);

int main () {
	int n;
	cout << "Number of disks: ";
	cin >> n;
	tower(n, 'A', 'C', 'B');
	cout << "Call count: " << call_count << endl;
}

void tower (int n_disks, char from, char to, char interim) {
	call_count++;
	if (n_disks > 0) {
		tower(n_disks - 1, from, interim, to);
		cout << "Move disk " << n_disks << " from " << from << " to " << to << endl;
		tower(n_disks - 1, interim, to, from);
	}
}
