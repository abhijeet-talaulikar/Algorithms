#include<iostream>
#include<string>
using namespace std;

int PC1_C[4][7] = {
{57, 49, 41, 33, 25, 17, 9},
{1, 58, 50, 42, 34, 26, 18},
{10, 2, 59, 51, 43, 35, 27},
{19, 11, 3, 60, 52, 44, 36} };

int PC1_D[4][7] = {
{63, 55, 47, 39, 31, 23, 15},
{7, 62, 54, 46, 38, 30, 22},
{14, 6, 61, 53, 45, 37, 29},
{21, 13, 5, 28, 20, 12, 4} };

int PC2[8][6] = {
{14, 17, 11, 24, 1, 5},
{3, 28, 15, 6, 21, 10},
{23, 19, 12, 4, 26, 8},
{16, 7, 27, 20, 13, 2},
{41, 52, 31, 37, 47, 55},
{30, 40, 51, 45, 33, 48},
{44, 49, 39, 56, 34, 53},
{46, 42, 50, 36, 29, 32} };

int IP[8][8] = {
{58, 50, 42, 34, 26, 18, 10, 2},
{60, 52, 44, 36, 28, 20, 12, 4},
{62, 54, 46, 38, 30, 22, 14, 6},
{64, 56, 48, 40, 32, 24, 16, 8},
{57, 49, 41, 33, 25, 17, 9, 1},
{59, 51, 43, 35, 27, 19, 11, 3},
{61, 53, 45, 37, 29, 21, 13, 5},
{63, 55, 47, 39, 31, 23, 15, 7}};

int IPi[8][8] = {
{40, 8, 48, 16, 56, 24, 64, 32},
{39, 7, 47, 15, 55, 23, 63, 31},
{38, 6, 46, 14, 54, 22, 62, 30},
{37, 5, 45, 13, 53, 21, 61, 29},
{36, 4, 44, 12, 52, 20, 60, 28},
{35, 3, 43, 11, 51, 19, 59, 27},
{34, 2, 42, 10, 50, 18, 58, 26},
{33, 1, 41, 9, 49, 17, 57, 25}
};

int E[8][6] = {
{32, 1, 2, 3, 4, 5},
{4, 5, 6, 7, 8, 9},
{8, 9, 10, 11, 12, 13},
{12, 13, 14, 15, 16, 17},
{16, 17, 18, 19, 20, 21},
{20, 21, 22, 23, 24, 25},
{24, 25, 26, 27, 28, 29},
{28, 29, 30, 31, 32, 1}
};

int P[8][4] = {
{16, 7, 20, 21},
{29, 12, 28, 17},
{1, 15, 23, 26},
{5, 18, 31, 10},
{2, 8, 24, 14},
{32, 27, 3, 9},
{19, 13, 30, 6},
{22, 11, 4, 25}
};

int S[9][4][16] = {
{
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
},

{
{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
},

{
{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
},

{
{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
},

{
{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
},

{
{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
},

{
{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
},

{
{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
},

{
{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
}
};

int dec(int num) {
	int decimal_val = 0, base = 1, rem;
	while (num > 0) {
		rem = num % 10;
		decimal_val = decimal_val + rem * base;
		num = num / 10 ;
		base = base * 2;
	}
	return decimal_val;
}

int bin(int n) {
	int binaryNumber = 0;
	int remainder, i = 1;
	while (n!=0) {
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}

class Bitset {
	public:
	int b[100], length;
	Bitset() {}
	Bitset(string bitset) {
		this->length = bitset.length();
		for(int i = 0;i < bitset.length();i++) b[i] = (bitset[i] == '0') ? 0 : 1;
	}
	Bitset(int length) {
		this->length = length;
	}
	void leftRotatebyOne() {
		int i, temp = this->b[0];
		for (i = 0; i < this->length - 1;i++) this->b[i] = this->b[i + 1];
		this->b[i] = temp;
	}
	Bitset LShift(int d) {
		for(int i = 0; i < d;i++) this->leftRotatebyOne();
		return *this;
	}
	void rightRotatebyOne() {
		int temp = this->b[this->length - 1];
		for (int i = this->length - 1; i > 0;i--) this->b[i] = this->b[i - 1];
		this->b[0] = temp;
	}
	Bitset RShift(int d) {
		for(int i = 0; i < d;i++) this->rightRotatebyOne();
		return *this;
	}
	string get() {
		string temp = "";
		for(int i = 0;i < this->length;i++) if(this->b[i]) temp += '1'; else temp += '0';
		return temp;
	}
	int pos(int n) {
		return this->b[n];
	}
	void set(int n, char x) {
		this->b[n] = x;
	}
	void equate(Bitset bn) {
		this->length = bn.length;
		for(int i = 0;i < this->length;i++) this->b[i] = bn.pos(i);
	}
};

class DES {
	public:
	Bitset K[17];

	DES(string K) {
		Bitset MyKey(K);
		KeySchedule(MyKey);
	}

	int KeySchedule(Bitset Key) {
		int v[17];
		Bitset C[17], D[17], CD(56);
		for(int i = 0;i < 17;i++) {
			C[i].length = 28;
			D[i].length = 28;
		}
		for(int i = 1;i <= 16;i++) K[i].length = 48;
		for(int i = 1;i <= 16;i++) {
			if(i == 1 || i == 2 || i == 9 || i == 16) v[i] = 1;
			else v[i] = 2;
		}
		for(int i = 0, k = -1;i < 4;i++) for(int j = 0;j < 7;j++) C[0].set(++k, Key.pos(PC1_C[i][j]-1));
		for(int i = 0, k = -1;i < 4;i++) for(int j = 0;j < 7;j++) D[0].set(++k, Key.pos(PC1_D[i][j]-1));
		for(int i = 1;i <= 16;i++) {
			C[i].equate(C[i-1].LShift(v[i]));
			D[i].equate(D[i-1].LShift(v[i]));
			for(int j = 0;j < 28;j++) CD.set(j, C[i].pos(j));
			for(int j = 28, k = -1;j < 56;j++) CD.set(j, D[i].pos(++k));
			for(int p = 0, k = -1;p < 8;p++) for(int q = 0;q < 6;q++) K[i].set(++k, CD.pos(PC2[p][q]-1));
		}
	}

	Bitset f(Bitset R, Bitset K) {
		Bitset T(48), T1(48), B[9], T2(32), T3(32);
		for(int j = 1;j <= 8;j++) B[j].length = 6;
		for(int p = 0, k = -1;p < 8;p++) for(int q = 0;q < 6;q++) T.set(++k, R.pos(E[p][q]-1));
		for(int j = 0;j < 48;j++) T1.set(j, T.b[j] ^ K.b[j]);
		for(int p = 1, k = -1;p <= 8;p++) for(int q = 0;q < 6;q++) B[p].set(q, T1.pos(++k));
		for(int p = 1, k = -1;p <= 8;p++) {
			int r = 2 * B[p].pos(0) + B[p].pos(5);
			int c = dec(B[p].pos(1)*1000 + B[p].pos(2)*100 + B[p].pos(3)*10 + B[p].pos(4));
			int Sval = bin(S[p][r][c]);
			T2.set(++k, (int) Sval / 1000);
			T2.set(++k, (int) (Sval % 1000) / 100);
			T2.set(++k, (int) (Sval % 100) / 10);
			T2.set(++k, (int) Sval % 10);
		}
		for(int p = 0, k = -1;p < 8;p++) for(int q = 0;q < 4;q++) T3.set(++k, T2.pos(P[p][q]));
		return T3;
	}

	Bitset Encrypt(string m) {
		Bitset M(m);
		Bitset L[17], R[17];
		for(int i = 0;i < 17;i++) {
			L[i].length = 32;
			R[i].length = 32;
		}
		for(int i = 0, k = -1;i < 4;i++) for(int j = 0;j < 8;j++) L[0].set(++k, M.pos(IP[i][j]-1));
		for(int i = 4, k = -1;i < 8;i++) for(int j = 0;j < 8;j++) R[0].set(++k, M.pos(IP[i][j]-1));
		for(int i = 1;i <= 16;i++) {
			L[i].equate(R[i-1]);
			Bitset T3 = f(R[i-1], K[i]);
			for(int j = 0;j < 32;j++) R[i].set(j, L[i-1].pos(j) ^ T3.pos(j));
		}
		Bitset bs(64), C(64);
		for(int i = 0;i < 32;i++) bs.set(i, R[16].pos(i));
		for(int i = 32;i < 64;i++) bs.set(i, L[16].pos(i-32));
		for(int p = 0, k = -1;p < 8;p++) for(int q = 0;q < 8;q++) C.set(++k, bs.pos(IPi[p][q]-1));
		return C;
	}
	Bitset Decrypt(string c) {
		Bitset M(c);
		Bitset L[17], R[17];
		for(int i = 0;i < 17;i++) {
			L[i].length = 32;
			R[i].length = 32;
		}
		for(int i = 0, k = -1;i < 4;i++) for(int j = 0;j < 8;j++) L[0].set(++k, M.pos(IP[i][j]-1));
		for(int i = 4, k = -1;i < 8;i++) for(int j = 0;j < 8;j++) R[0].set(++k, M.pos(IP[i][j]-1));
		for(int i = 1;i <= 16;i++) {
			L[i].equate(R[i-1]);
			Bitset T3 = f(R[i-1], K[17-i]);
			for(int j = 0;j < 32;j++) R[i].set(j, L[i-1].pos(j) ^ T3.pos(j));
		}
		Bitset bs(64), C(64);
		for(int i = 0;i < 32;i++) bs.set(i, R[16].pos(i));
		for(int i = 32;i < 64;i++) bs.set(i, L[16].pos(i-32));
		for(int p = 0, k = -1;p < 8;p++) for(int q = 0;q < 8;q++) C.set(++k, bs.pos(IPi[p][q]-1));
		return C;
	}
};

int main() {
	string k = "0100111110010010000010111101111100001110000110101011100110110011"; //sample 64-bit key (after adding 8 parity bits)
	string m = "0000100101001010001010100101001011001000001110000111100100110010"; //sample 64-bit message
	DES D(k);
	Bitset c = D.Encrypt(m);
	Bitset p = D.Decrypt(c.get());
	cout<<"Message: \t\t"<<m<<endl;
	cout<<"Ciphertext: \t\t"<<c.get()<<endl;
	cout<<"Decrypted plaintext: \t"<<p.get()<<endl;
}
