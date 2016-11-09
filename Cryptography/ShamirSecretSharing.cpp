#include<iostream>
#include<cmath>
using namespace std;

int *multiply(int A[], int B[], int m, int n) {
	int *prod = new int[m+n-1];
	for(int i = 0; i<m+n-1; i++) prod[i] = 0;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) prod[i+j] += A[i]*B[j];
   	}
	return prod;
}

int main() {
	int s, n, k, temp;
	cout<<"Enter secret: ";
	cin>>s;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"Enter k: ";
	cin>>k;
	int a[k], D[n][2], points[k][2];
	float l[k][k], f[k];
	a[0] = s;
	cout<<"Enter k-1 random values: "<<endl;
	for(int i = 1;i < k;i++) cin>>a[i];
	for(int i = 0;i < n;i++) {
		D[i][0] = i + 1;
		D[i][1] = 0;
		for(int j = 0;j < k;j++) D[i][1] += a[j] * pow(i + 1, j);
	}
	cout<<"\nFollowing points were constructed: "<<endl;
	for(int i = 0;i < n;i++) cout<<"D["<<i<<"] = "<<D[i][0]<<", "<<D[i][1]<<endl;
	cout<<"\nChoose "<<k<<" points for reconstruction: "<<endl;
	for(int i = 0;i < k;i++) {
		cin>>temp;
		if(temp >= 1 && temp <= n) {
			points[i][0] = D[temp - 1][0];
			points[i][1] = D[temp - 1][1];
		}
	}
	cout<<"\nPoints chosen were: "<<endl;
	for(int i = 0;i < k;i++) cout<<"(x"<<i<<", y"<<i<<") = ("<<points[i][0]<<", "<<points[i][1]<<")"<<endl;

	//compute lagrange's polynomials
	for(int i = 0;i < k;i++) {
		int *init, id, length = 2;
		for(int j = 0;j < k;j++) {
			if(j != i) {
				init[0] = -1 * points[j][0];
				init[1] = 1;
				id = j;
				break;
			}
		}
		//polynomial multiplication
		for(int j = 0;j < k;j++) {
			if(j != i && j != id) {
				int new_ar[2] = {-1 * points[j][0], 1};
				init = multiply(init, new_ar, length, 2);
				length++;
			}
		}
		//end
		for(int j = 0;j < k;j++) l[i][j] = init[j];
		temp = 1;
		for(int j = 0;j < k;j++) if(j != i) temp *= points[i][0] - points[j][0];
		for(int j = 0;j < k;j++) l[i][j] /= temp;
	}

	cout<<"\nLagrange's polynomial coefficients are: "<<endl;
	for(int i = 0;i < k;i++) {
		for(int j = 0;j < k;j++) {
			cout<<l[i][j];
			if(j != 0) cout<<"x^"<<j;
			if(j != k-1) cout<<" + ";
		}
		cout<<endl;
	}

	//compute f(x)
	for(int i = 0;i < k;i++) {
		f[i] = 0;
		for(int j = 0;j < k;j++) f[i] += points[j][1] * l[j][i];
	}
	cout<<"\nf(x) = ";
	for(int i = 0;i < k;i++) {
		cout<<f[i];
		if(i != 0) cout<<"x^"<<i;
		if(i != k-1) cout<<" + ";
	}
	cout<<"\n\nReconstructed secret = "<<f[0]<<endl;
}
