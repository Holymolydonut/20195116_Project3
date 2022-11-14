#include<iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x, float y, float z, const char* chars) :x{ x }, y{ y }, z{ z }, _chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	friend ostream& operator<<(ostream& os, Vector& v) {
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}

	friend istream& operator>>(istream& is, Vector& v) {
		is >> v.x >> v.y >> v.z;
		return is;
	}

	const float& operator[](int index) const {
		if (index < 1)
			return x;
		if (index = 1)
			return y;
		return z;
	}

	Vector& operator=(const Vector& v) {
		x = v.x;
		y = v.y;
		z = v.z;

		delete[]_chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);

		return *this;
	}

	Vector(Vector& v)
		:Vector(v.x, v.y, v.z, v._chars) {
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;
	}

	~ Vector() {
		delete[]_chars;
	}

};

int main() {
	/*Vector v0{1,2,3};
	cout << v0 << endl;

	Vector v1;
	cin >> v1;
	cout << v1<<endl;*/

	/*Vector v0{1,2,3};
	cout << v0[-1] << endl;
	cout << v0[1] << endl;
	cout << v0[2] << endl;
	cout << v0[3] << endl;

	v0[0] = 100;
	cout << v0[0] << endl;*/

	Vector v0{ 1,2,3,"abc"};
	Vector v1 = v0;
	Vector v2;
	v2 = v0;

	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;

}