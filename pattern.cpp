#include<iostream>
using namespace std;

int main(){

    int n, max_line = 0;
    cin >> n;
    //���ҧ data[n][70]
    char data[n][70];

    //���ҧ��ҷ����������������
    for(int i=0; i<n; i++){
        for(int j=0; j<70; j++){
            data[i][j] = 'o';
        }
    }

    //���ҧ��¼��
    for(int i=0; i<n; i++){
        int p, q, r;
        cin >> p >> q >> r;

        for(int x=q-1; x<r+q-1; x++) if(x < 70) data[p-1][x] = 'x';

        if(max_line < p) max_line = p;
    }

    //�������¼��
    for(int i=0; i<max_line; i++){
        for(int j=0; j<70; j++){
            cout << data[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
4
1 1 10
2 3 9
3 5 25
2 20 2

*/

